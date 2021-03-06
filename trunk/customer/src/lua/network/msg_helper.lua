﻿--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   msg_helper.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: help to send msg, etc.
@ others:
@ history:
1.date:
author:
modification:
--]]

local M = {}
local CardConst = require "logic.constant.card_constants.lua"
local RoomConst = require "logic.constant.room_constants.lua"

function M.sendCreatePersonalRoomMsg(rounds_num, players_num, room_cards_num, score_gold)
	print("[MsgHelper.sendCreatePersonalRoomMsg]")
	local proto = gamer.protocol.CreateRoomMsgProtocol()
    proto:set_room_owner_id(gamer.data_mgr_:self_player_id())
    proto:set_rounds_num(rounds_num)
    proto:set_players_num(players_num)
    proto:set_room_cards_num(room_cards_num)
	proto:set_score_gold(score_gold)

    gamer.msg_mgr_:sendMsg(gamer.MsgTypes.C2S_MSG_TYPE_ROOM, 
		gamer.MsgIDs.MSG_ID_ROOM_CREATE, proto)
end

function M.sendJoinPersonalRoomMsg(room_id)
	print("[MsgHelper.sendJoinPersonalRoomMsg]")
	local proto = gamer.protocol.RoomOperationMsgProtocol()
	proto:set_room_id(room_id) 
	proto:set_player_id(gamer.data_mgr_:self_player_id())
	proto:set_operation_id(gamer.MsgIDs.MSG_ID_ROOM_PLAYER_JOIN)

	gamer.msg_mgr_:sendMsg(gamer.MsgTypes.C2S_MSG_TYPE_ROOM, 
		gamer.MsgIDs.MSG_ID_ROOM_PLAYER_JOIN, proto)
end

function M.sendGetRoomListMsg()
	print("[MsgHelper.sendGetRoomListMsg]")
	local proto = gamer.protocol.RoomListMsgProtocol()
	proto:set_player_id(gamer.data_mgr_:self_player_id())
	gamer.msg_mgr_:sendMsg(gamer.MsgTypes.C2S_MSG_TYPE_ROOM, 
		gamer.MsgIDs.MSG_ID_ROOM_GET_ROOM_LIST, proto)
end

function M.sendGetPlayerInfoMsg(player_id)
	print("[MsgHelper.sendGetPlayerInfoMsg]")
	if not player_id then
		print("[MsgHelper.sendGetPlayerInfoMsg] player_id nil, return")
		return
	end

	local proto = gamer.protocol.PlayerMsgProtocol()
	proto:set_player_id(player_id)

	gamer.msg_mgr_:sendMsg(gamer.MsgTypes.C2S_MSG_TYPE_PROPERTY, 
		gamer.MsgIDs.MSG_ID_PROPERTY_GET_PLAYER_INFO, proto)
end

function M.sendGetSelfPlayerInfoMsg()
	print("[MsgHelper.sendGetSelfPlayerInfoMsg]")
	M.sendGetPlayerInfoMsg(gamer.data_mgr_:self_player_id())
end

function M.sendPersonalRoomStartGameMsg()
	print("[MsgHelper.sendPersonalRoomStartGameMsg]")
	local proto_room = gamer.data_mgr_:create_room_msg_protocol()
	if not proto_room then
		print("[MsgHelper.sendPersonalRoomStartGameMsg] create_room_msg_protocol nil!")
	end

	if gamer.data_mgr_:self_player_id() == proto_room:room_owner_id() then
		print("[MsgHelper.sendPersonalRoomStartGameMsg] send start game msg")
		local proto = gamer.protocol.RoomMsgProtocol()
		proto:set_room_id(proto_room:room_id())
		proto:set_room_owner_id(proto_room:room_owner_id())
		proto:set_room_type(RoomConst.RoomTypes.PERSONAL_ROOM)

		gamer.msg_mgr_:sendMsg(gamer.MsgTypes.C2S_MSG_TYPE_ROOM, 
			gamer.MsgIDs.MSG_ID_ROOM_START_GAME, proto)
	else
		print("[MsgHelper.sendPersonalRoomStartGameMsg] not room owner")
	end
end

function M.sendPlayCardMsg(operation_id, card)
	print("[MsgHelper.sendPlayCardMsg]")
	local proto = gamer.protocol.PlayCardMsgProtocol()
	proto:set_room_id(gamer.data_mgr_:room_msg_protocol():room_id())
	proto:set_table_id(gamer.data_mgr_:room_msg_protocol():table_list(0):table_id())
	proto:set_player_id(gamer.data_mgr_:self_player_id())
	proto:set_operation_id(operation_id)
	proto:set_cur_round(1) -- TODO : cur round
	if operation_id == CardConst.OperationIDs.OPERATION_CHI then
		local discard = gamer.data_mgr_:play_card_msg_protocol():discard()
		proto:set_discard(discard)
		for k, v in pairs(card) do
			if v ~= discard then
				proto:add_operating_cards(v)
			end
		end
	else
		if card then
			proto:set_discard(card)
		end
	end

	gamer.msg_mgr_:sendMsg(gamer.MsgTypes.C2S_MSG_TYPE_ROOM, 
		gamer.MsgIDs.MSG_ID_ROOM_PLAY_CARD, proto)
end

function M.sendModifyNicknameMsg(nickname)
	if nickname then
		local proto = gamer.protocol.SetPropertyMsgProtocol()
		proto:set_player_id(gamer.data_mgr_:self_player_id())
		proto:add_property_ids(gamer.PropertyIDs.PROP_ID_NICKNAME)
		proto:add_new_properties(nickname)

		gamer.msg_mgr_:sendMsg(gamer.MsgTypes.C2S_MSG_TYPE_PROPERTY, 
			gamer.MsgIDs.MSG_ID_PROPERTY_SET, proto)
	end
end

function M.sendModifySexMsg(sex)
	if sex then
		local proto = gamer.protocol.SetPropertyMsgProtocol()
		proto:set_player_id(gamer.data_mgr_:self_player_id())
		proto:add_property_ids(gamer.PropertyIDs.PROP_ID_SEX)
		proto:add_new_properties(sex)

		gamer.msg_mgr_:sendMsg(gamer.MsgTypes.C2S_MSG_TYPE_PROPERTY, 
			gamer.MsgIDs.MSG_ID_PROPERTY_SET, proto)
	end
end

function M.sendModifyLocalHeadPortraitMsg(head_portrait_id)
	if head_portrait_id then
		local proto = gamer.protocol.SetPropertyMsgProtocol()
		proto:set_player_id(gamer.data_mgr_:self_player_id())
		proto:add_property_ids(gamer.PropertyIDs.PROP_ID_HEAD_PORTRAIT_LOCAL)
		proto:add_new_properties(head_portrait_id)

		gamer.msg_mgr_:sendMsg(gamer.MsgTypes.C2S_MSG_TYPE_PROPERTY, 
			gamer.MsgIDs.MSG_ID_PROPERTY_SET, proto)
	end
end

return M