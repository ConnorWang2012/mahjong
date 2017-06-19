--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   room_scene.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: basic room scene.
@ others:
@ history:
1.date:
author:
modification:
--]]

local RoomScene = class("RoomScene", require "view.base.layer_base")

function RoomScene:ctor(view_file)
	print("[RoomScene:ctor]")
    RoomScene.super.ctor(self, view_file)
end

function RoomScene:onEnter()
	-- TODO : dispatch layer enter event to all listeners
    print("[RoomScene:onEnter]")
end

function RoomScene:onExit()
	-- TODO : dispatch layer exit event to all listeners
    print("[RoomScene:onExit]")
end

return RoomScene