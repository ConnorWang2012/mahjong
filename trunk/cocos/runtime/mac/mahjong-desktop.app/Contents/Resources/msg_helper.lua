--[[
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

local CardConst = require "logic.constant.card_constants.lua"
local MsgHelper = {}

function MsgHelper.sendStartGameMsg()
	print("[MsgHelper.sendStartGameMsg]")
	local proto_room = gamer.data_mgr_:create_room_msg_protocol()
	if not proto_room then
		print("[MsgHelper.sendStartGameMsg] create_room_msg_protocol nil!")
	end

	if gamer.data_mgr_:self_player_id() == proto_room:room_owner_id() then
		print("[MsgHelper.sendStartGameMsg] send start game msg")
		local proto = gamer.protocol.RoomMsgProtocol()
		proto:set_room_id(proto_room:room_id())
		proto:set_room_owner_id(proto_room:room_owner_id())

		gamer.msg_mgr_:sendMsg(gamer.MsgTypes.C2S_MSG_TYPE_ROOM, 
			gamer.MsgIDs.MSG_ID_ROOM_START_GAME, proto)
	else
		print("[MsgHelper.sendStartGameMsg] not room owner")
	end
end

function MsgHelper.sendPlayCardMsg(operation_id, card)
	print("[MsgHelper.sendPlayCardMsg]")
	local proto = gamer.protocol.PlayCardMsgProtocol()
	proto:set_player_id(gamer.data_mgr_:self_player_id())
	proto:set_room_id(gamer.data_mgr_:room_msg_protocol():room_id())
	proto:set_cur_round(1) -- TODO : cur round
	proto:set_operation_id(operation_id)
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

return MsgHelper