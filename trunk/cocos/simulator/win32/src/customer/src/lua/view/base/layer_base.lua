--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   layer_base.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: layer base class.
@ others:
@ history:
1.date:
author:
modification:
--]]

local LayerBase = class("LayerBase", cc.Layer)

function LayerBase:ctor(view_file)
	print("[LayerBase:ctor]")
    self:registerScriptHandler(function(event)
        if event == "enter" then
            self:onEnter()
        elseif event == "exit" then
            self:onExit()
        end
    end)

    if view_file then -- TODO : verify lua or csb
        self:addViewNodeFromLua(view_file)
    end
end

function LayerBase:addViewNodeFromLua(view_file)
	if self.root_view_node_ then
        self.root_view_node_:removeSelf()
        self.root_view_node_ = nil
    end
    self.root_view_node_ = require(view_file):create().root
    assert(self.root_view_node_, string.format("[LayerBase:addViewNode] add view node from file \"%s\" failed", view_file))
    self.root_view_node_:setLocalZOrder(0)
    self:addChild(self.root_view_node_)
end

function LayerBase:addViewNodeFromCsb(view_file)
	if self.root_view_node_ then
        self.root_view_node_:removeSelf()
        self.root_view_node_ = nil
    end
    self.root_view_node_ = cc.CSLoader:createNode(view_file)
    assert(self.root_view_node_, string.format("[LayerBase:addViewNode] add view node from file \"%s\" failed", view_file))
    self.root_view_node_:setLocalZOrder(0)
    self:addChild(self.root_view_node_)
end

function LayerBase:id()
    return self.id_ or -1
end

function LayerBase:set_id(id)
    self.id_ = id
end

function LayerBase:onEnter()
    print("[LayerBase:onEnter]")
	-- TODO : dispatch layer enter event to all listeners
end

function LayerBase:onExit()
    print("[LayerBase:onEnter]")
	-- TODO : dispatch layer exit event to all listeners
end

return LayerBase
