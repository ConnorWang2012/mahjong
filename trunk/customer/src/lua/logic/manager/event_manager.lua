--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   popup_manager.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: listen event, dispatch event, support swallow event(only used by lua).
@ others:
@ history:
1.date:
author:
modification:
--]]

local M = {}

M.Priorities =
{
    SENIOR = 1, 
    MIDDLE = 2,
    JUNIOR = 3,
    NORMAL = 4
}

function M.addEventListener(event_id, listener, obj, priority)
	if not event_id or not listener or not priority then
		print("[EventManager:addEventListener] param error !")
		return
	end

	local key   = M.generateListenerKey(listener, obj)
	local event = M.events_[event_id]

	if event and event.listener_keys then -- non first add
		if event.listener_keys[key] then
			print("[EventManager:addEventListener] listerner has added !")
			return
		else
			event.listener_keys[key] = key
			local listener = { key = key, listener = listener, obj = obj, priority = priority }
			if priority == M.Priorities.SENIOR then
				table.insert(event.listeners, 1, listener)
			elseif priority == M.Priorities.NORMAL then
				table.insert(event.listeners, listener)
			else
				table.insert(event.listeners, listener)
            	M.sortListeners(event.listeners)
			end
		end
	else -- first add
		local listener_keys = {}
		listener_keys[key] = key
		local listener = { key = key, listener = listener, obj = obj, priority = priority }
		M.events_[event_id] = { event_id = event_id, listener_keys = listener_keys, listeners = { listener }, stopped = false }
	end
end

function M.removeEventListener(event_id, listener, obj)
	if not event_id or not listener or not priority then
		print("[EventManager:removeEventListener] param error !")
		return
	end

	local event = M.events_[event_id]
	if not event then
		print("[EventManager:removeEventListener] failed, event has not added, event_id : " .. tostring(event_id))
		return
	end

	local key = M.generateListenerKey(listener, obj)
	event.listener_keys[key] = nil
	for k, v in pairs(event.listeners) do
        if v.key == key then
            table.remove(event.listeners, k)
            break
        end
    end
end

function M.dispatch(event_id, ...)
	if not event_id then
		print("[EventManager:dispatch] event id nil")
		return
	end

	local event = M.events_[event_id]
	if not event then
		print("[EventManager:dispatch] event nil")
		return
	end

	for k, v in pairs(event.listeners) do
        if v and v.listener then
            if false == event.stopped then
				if v.obj then
					v.listener(v.obj, event_id, ...)
				else
					v.listener(event_id, ...)
				end
            else
                event.stopped = false
                break
            end
        end
    end
end

function M.stopEvent(event_id)
    if not event_id then
        print("[EventManager:dispatch] event_id nil")
        return
    end

    local event = M.events_[event_id]
    if event and event.event_id == event_id then
        event.stopped = true
    end
end

------------------------------------ private ------------------------------------

function M.init()
	--[[ { event_id      = xxx, 
           listener_keys = { key1, key2, ... },
           listeners     = { { priority = xxx, listener = xxx }, ... }, 
           stopped,
         }
    --]]
	M.events_ = {}
end

function M.sortListeners(listeners)
    if not listeners then
        return
    end

    if table.getn(listeners) > 1 then
        local comp = function(o1, o2)
            if o1.priority < o2.priority then
                return true
            end
            return false
	    end

        table.sort(listeners, comp)
    end
end

function M.generateListenerKey(listener, obj)
    return string.sub(tostring(listener), 12) .. string.sub(tostring(obj), 8)
end

--------------------------------- end private -----------------------------------

return M