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

function DataManager.getSelfPlayerID()
	if not DataManager.player_self_id_ then
		local proto_login = data_mgr:getMutableData(gamer.DataIDs.DATA_ID_MY_LOGIN_MSG_PROTOCOL)
		DataManager.player_self_id_ = proto_login:player():player_id()
	end
	return DataManager.player_self_id_
end

function DataManager.getMahjongsOfPlayerSelf()
	local proto = data_mgr:getMutableData(gamer.DataIDs.DATA_ID_ROOM_MSG_PROTOCOL)
	local cards_size = proto:player_cards_size()

	if DataManager.player_self_cards_index_ and DataManager.player_self_cards_index_ < cards_size then
		return proto:player_cards(DataManager.player_self_cards_index_)
	end

	local self_player_id = DataManager.getSelfPlayerID()	
	for i = 0, proto:player_cards_size() - 1 do
		if self_player_id == proto:player_cards(i):player_id() then
			DataManager.player_self_cards_index_ = i
			return proto:player_cards(i)
		end
	end

	return nil
end

function DataManager.getMahjongsOfLeftPlayer()
	local proto = data_mgr:getMutableData(gamer.DataIDs.DATA_ID_ROOM_MSG_PROTOCOL)
	local cards_size = proto:player_cards_size()

	if DataManager.left_player_cards_index_ and DataManager.left_player_cards_index_ < cards_size then
		return proto:player_cards(DataManager.left_player_cards_index_)
	end

	local self_player_id = DataManager.getSelfPlayerID()
	for i = 0, cards_size - 1 do
		if self_player_id == proto:player_cards(i):player_id() then
			if 0 == i then
				DataManager.left_player_cards_index_ = cards_size - 1
			else
				DataManager.left_player_cards_index_ = i - 1
			end
			DataManager.left_player_id_ = proto:player_cards(DataManager.left_player_cards_index_):player_id()
			return proto:player_cards(DataManager.left_player_cards_index_)
		end
	end

	return nil
end

function DataManager.getMahjongsOfOppositePlayer()
	local proto = data_mgr:getMutableData(gamer.DataIDs.DATA_ID_ROOM_MSG_PROTOCOL)
	local cards_size = proto:player_cards_size()

	if DataManager.opposite_player_cards_index_ and DataManager.opposite_player_cards_index_ < cards_size then
		return proto:player_cards(DataManager.opposite_player_cards_index_)
	end

	local self_player_id = DataManager.getSelfPlayerID()
	for i = 0, cards_size - 1 do
		if self_player_id == proto:player_cards(i):player_id() then
			local index = nil
			if 4 == cards_size then
				if i < 2 then
					index = i + 2
				else
					index = i - 2
				end
			elseif 2 == cards_size then
				if 0 == i then
					index = 1
				else
					index = 0
				end
			end

			if index then
				DataManager.opposite_player_cards_index_ = index
				DataManager.opposite_player_id_ = proto:player_cards(index):player_id()
				return proto:player_cards(index)
			end

			break
		end
	end

	return nil
end

function DataManager.getMahjongsOfRightPlayer()
	local proto = data_mgr:getMutableData(gamer.DataIDs.DATA_ID_ROOM_MSG_PROTOCOL)
	local cards_size = proto:player_cards_size()

	if DataManager.right_player_cards_index_ and DataManager.right_player_cards_index_ < cards_size then
		return proto:player_cards(DataManager.right_player_cards_index_)
	end

	local self_player_id = DataManager.getSelfPlayerID()
	for i = 0, cards_size - 1 do
		if self_player_id == proto:player_cards(i):player_id() then
			if (cards_size - 1) == i then
				DataManager.right_player_cards_index_ = 0
			else
				DataManager.right_player_cards_index_ = i + 1
			end
			DataManager.right_player_id_ = proto:player_cards(DataManager.right_player_cards_index_):player_id()
			return proto:player_cards(DataManager.right_player_cards_index_)
		end
	end

	return nil
end

function DataManager.getRoomPlayersNum()
	if not DataManager.players_num_ then
		local proto = data_mgr:getMutableData(gamer.DataIDs.DATA_ID_ROOM_MSG_PROTOCOL)
		DataManager.players_num_ = proto:players_num()
	end
	return DataManager.players_num_
end

function DataManager.getRoomID()
	if not DataManager.room_id_ then
		local proto = data_mgr:getMutableData(gamer.DataIDs.DATA_ID_ROOM_MSG_PROTOCOL)
		DataManager.room_id_ = proto:room_id()
	end
	return DataManager.room_id_
end

function DataManager.updateInvisibleHandCardForDiscard(new_card, discard)
	if new_card == discard then
		return
	end

	local mahjongs = DataManager.getMahjongsOfPlayerSelf()
	for i = 0, mahjongs:invisible_hand_cards_size() - 1 do
		if mahjongs:invisible_hand_cards(i) == discard then
			mahjongs:set_invisible_hand_cards(i, new_card)
			break
		end
	end
end

return DataManager