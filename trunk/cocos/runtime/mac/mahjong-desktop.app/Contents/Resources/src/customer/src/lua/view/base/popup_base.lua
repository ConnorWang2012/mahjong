--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   popup_base.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-07-27
@ description: popup base class.
@ others:
@ history:
1.date:
author:
modification:
--]]

local PopupBase = class("PopupBase", require "view.base.layer_base")

function PopupBase:ctor(view_file)
	print("[PopupBase:ctor]")
    PopupBase.super.ctor(self, view_file)

	-- swallow touch event for background
	self.touch_listener_ = cc.EventListenerTouchOneByOne:create()
    self.touch_listener_:setSwallowTouches(true)
    self.touch_listener_:registerScriptHandler(handler(self, self.onTouchBegin), cc.Handler.EVENT_TOUCH_BEGAN)
    self.touch_listener_:registerScriptHandler(handler(self, self.onTouchEnd), cc.Handler.EVENT_TOUCH_ENDED)

    cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(self.touch_listener_, self)
end

function PopupBase:onEnter()
    print("[PopupBase:onEnter]")
	-- TODO : dispatch popup enter event to all listeners
end

function PopupBase:onExit()
    print("[PopupBase:onExit]")
	-- TODO : dispatch popup exit event to all listeners
	if self.touch_listener_ then
		cc.Director:getInstance():getEventDispatcher():removeEventListener(self.touch_listener_)
		self.touch_listener_ = nil
	end
end

function PopupBase:onTouchBegin(touch, event)
    print("[PopupBase:onTouchBegin]")
	if event:getEventCode() == cc.EventCode.BEGAN then
        return true
    end
end

function PopupBase:onTouchEnd(touch, event)
    print("[PopupBase:onTouchEnd]")
end

return PopupBase
