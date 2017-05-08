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

function LayerBase:ctor()
    self:registerScriptHandler(function(event)
        if event == "enter" then
            self:onEnter()
        elseif event == "exit" then
            self:onExit()
        end
    end)
end

function LayerBase:addViewNode(view_file)
	if self.view_node_ then
        self.view_node_:removeSelf()
        self.view_node_ = nil
    end
    self.view_node_ = cc.CSLoader:createNode(view_file)
    assert(self.view_node_, string.format("ViewBase:createResourceNode() - add view node from file \"%s\" failed", view_file))
    self:addChild(self.view_node_)
end

function LayerBase:onEnter()
	-- TODO : dispatch layer enter event to all listeners
end

function LayerBase:onExit()
	-- TODO : dispatch layer exit event to all listeners
end

return LayerBase
