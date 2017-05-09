--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   node_base.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: node base class.
@ others:
@ history:
1.date:
author:
modification:
--]]

local NodeBase = class("NodeBase", cc.Node)

function NodeBase:ctor()
    self:enableNodeEvents()
end

function NodeBase:addViewNode(view_file)
	if self.view_node_ then
        self.view_node_:removeSelf()
        self.view_node_ = nil
    end
    self.view_node_ = cc.CSLoader:createNode(view_file)
    assert(self.view_node_, string.format("[NodeBase:addViewNode] add view node from file \"%s\" failed", view_file))
    self:addChild(self.view_node_)
end

function NodeBase:id()
    return self.id_ or -1
end

function NodeBase:set_id(id)
    self.id_ = id
end

return NodeBase