--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   data_manager.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-07-21
@ description: data manager.
@ others:
@ history:
1.date:
author:
modification:
--]]

local DataManager = {}
local data_mgr = gamer.DataManager:getInstance()

function DataManager.getPlayerSelfID()
	if not DataManager.player_self_id_ then
		local proto_login = data_mgr:getMutableData(gamer.DataIDs.DATA_ID_MY_LOGIN_MSG_PROTOCOL)
		DataManager.player_self_id_ = proto_login:player():player_id()
	end
	return DataManager.player_self_id_
end

function DataManager.getMahjongOfPlayerSelf()
	local player_self_id = DataManager.getPlayerSelfID()
	print("[DataManager:getMahjongOfPlayerSelf] : ", player_self_id)
	local proto_room = data_mgr:getMutableData(gamer.DataIDs.DATA_ID_ROOM_MSG_PROTOCOL)	
	for i = 0, proto_room:player_cards_size() - 1 do
		if player_self_id == proto_room:player_cards(i):player_id() then
			return proto_room:player_cards(i)
		end
	end
	return nil
end

return DataManager