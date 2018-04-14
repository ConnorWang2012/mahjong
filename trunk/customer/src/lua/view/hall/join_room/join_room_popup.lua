--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   join_room_popup.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-07-27
@ description: join room popup.
@ others:
@ history:
1.date:
author:
modification:
--]]

local JoinRoomPopup = class("JoinRoomPopup", require "view.base.popup_base")

function JoinRoomPopup:ctor(view_file)
	print("[JoinRoomPopup:ctor]")
    self.super.ctor(self, view_file)

	self:initView()
	self:closeWhenTouchBackground(true)
end

function JoinRoomPopup:initView()
	local img_bg = self.root_node_:getChildByName("img_bg")

	self.cur_num_txt_ = img_bg:getChildByName("txt_num_1")

	for i = 0, 9 do
		local img = img_bg:getChildByName("img_num_bg" .. i)
		img:setTag(i)
		img:setTouchEnabled(true)
		img:addClickEventListener(handler(self, self.onImgNumTouch))
	end

	local img_clear = img_bg:getChildByName("img_num_bg11")
	local img_remove = img_bg:getChildByName("img_num_bg12")
	img_clear:setTouchEnabled(true)
	img_remove:setTouchEnabled(true)
	img_clear:addClickEventListener(handler(self, self.onImgClearTouch))		
	img_remove:addClickEventListener(handler(self, self.onImgRemoveTouch))
end

function JoinRoomPopup:getRoomID()
	local img_bg = self.root_node_:getChildByName("img_bg")
	local str = "0"
	for i = 1, 6 do
		local txt = img_bg:getChildByName("txt_num_" .. i)
		local s = txt:getString()
		if "_" == s then
			print("[JoinRoomPopup:getRoomID] error")
			return 0
		end
		str = str .. s
	end

	return tonumber(str)
end

function JoinRoomPopup:onImgNumTouch(sender)
    print("[JoinRoomPopup:onImgNumTouch]")
	self.cur_num_txt_:setString(sender:getTag())
	local name = self.cur_num_txt_:getName()
	if "txt_num_6" == name then
		-- send join room msg
		local room_id = self:getRoomID()
		--[[
		local player_id = gamer.data_mgr_:self_player_id()
		local proto = gamer.protocol.RoomOperationMsgProtocol()
		proto:set_room_id(room_id) 
		proto:set_player_id(player_id)
		proto:set_operation_id(gamer.MsgIDs.MSG_ID_ROOM_PLAYER_JOIN)

		print("[JoinRoomPopup:onImgNumTouch] room id, player id, op id : ", room_id, player_id, gamer.MsgIDs.MSG_ID_ROOM_PLAYER_JOIN)

		gamer.msg_mgr_:sendMsg(gamer.MsgTypes.C2S_MSG_TYPE_ROOM, gamer.MsgIDs.MSG_ID_ROOM_PLAYER_JOIN, proto)
		]]
		gamer.msg_helper_.sendJoinPersonalRoomMsg(room_id)
	else
		local i = tonumber(string.sub(name, string.len(name)))
		if (i + 1) <= 6 then
			local img_bg = self.root_node_:getChildByName("img_bg")
			self.cur_num_txt_ = img_bg:getChildByName("txt_num_" .. (i + 1))
		end
	end
end

function JoinRoomPopup:onImgClearTouch(sender)
	print("[JoinRoomPopup:onImgClearTouch]")

	local img_bg = self.root_node_:getChildByName("img_bg")
	for i = 1, 6 do
		local txt = img_bg:getChildByName("txt_num_" .. i)
		txt:setString("_")
	end

	self.cur_num_txt_ = img_bg:getChildByName("txt_num_1")
end

function JoinRoomPopup:onImgRemoveTouch(sender)
	print("[JoinRoomPopup:onImgRemoveTouch]")
	self.cur_num_txt_:setString("_")

	local name = self.cur_num_txt_:getName()
	local i = tonumber(string.sub(name, string.len(name)))
	if i > 1 then
		local img_bg = self.root_node_:getChildByName("img_bg")
		self.cur_num_txt_ = img_bg:getChildByName("txt_num_" .. (i - 1))
	end
end

function JoinRoomPopup:onEnter()
    print("[JoinRoomPopup:onEnter]")
end

function JoinRoomPopup:onExit()
    print("[JoinRoomPopup:onExit]")
end

return JoinRoomPopup
