--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   normal_room_scene.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: normal room scene.
@ others:
@ history:
1.date:
author:
modification:
--]]

local NormalRoomScene = class("NormalRoomScene", require "view.room.room_scene")

function NormalRoomScene:ctor(view_file)
    self.super.ctor(self, view_file)

end

function NormalRoomScene:onEnter()
	-- TODO : dispatch layer enter event to all listeners
    print("[NormalRoomScene:onEnter]")
end

function NormalRoomScene:onExit()
	-- TODO : dispatch layer exit event to all listeners
    print("[NormalRoomScene:onExit]")
end

return NormalRoomScene