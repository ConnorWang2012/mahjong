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

local NormalRoomScene = class("NormalRoomScene", require "view.room.scene.room_scene.lua")
local MahjongLayer    = require "view.room.mahjong_layer.lua"

function NormalRoomScene:ctor(view_file)
	print("[NormalRoomScene:ctor]")
    self.super.ctor(self, view_file)
	self:initLayout()
end

function NormalRoomScene:initLayout()
	self:initMahjongLayer()
end

function NormalRoomScene:initMahjongLayer()
	
end

function NormalRoomScene:onEnter()
	-- TODO : dispatch layer enter event to all listeners
    print("[NormalRoomScene:onEnter]")
	local proto = gamer.g_data_mgr_:getMutableData(gamer.DataIDs.DATA_ID_GAME_START_MSG_PROTOCOL)
	local room_owner_id = proto:room_owner_id()
	print("[NormalRoomScene:onEnter] room_owner_id : %d", room_owner_id)
	
end

function NormalRoomScene:onExit()
	-- TODO : dispatch layer exit event to all listeners
    print("[NormalRoomScene:onExit]")
end

return NormalRoomScene