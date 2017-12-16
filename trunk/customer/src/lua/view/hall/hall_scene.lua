--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   hall_scene.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: hall scene.
@ others:
@ history:
1.date:
author:
modification:
--]]

local HallScene         = class("HallScene", require "view.base.layer_base.lua")
local HallTopLayout     = require "view.layouts.ui.hall.hall_top_node_layout.lua"
local HallMiddleLayout  = require "view.layouts.ui.hall.hall_middle_node_layout.lua"
local HallBottomLayout  = require "view.layouts.ui.hall.hall_bottom_node_layout.lua"
local PlayerHeadLayout  = require "view.layouts.ui.hall.hall_player_head_node_layout.lua"
local PlayerHeadCreator = require "view.common.player_head_creator.lua"

function HallScene:ctor(view_file)
    self.super.ctor(self, view_file)

    self:initLayout()
end

function HallScene:initLayout()
    self.hall_top_layout_ = HallTopLayout:create().root    
    self:addChild(self.hall_top_layout_)
    self.hall_top_layout_:setPosition(display.top_center)

	self.player_head_layout_ = PlayerHeadLayout:create().root
	self.hall_top_layout_:getChildByName("node_head"):addChild(self.player_head_layout_)
	local head_node = PlayerHeadCreator.createWithDefaultStencil("woman_4.png")
	self.player_head_layout_:addChild(head_node)
	
	-- head touch event
	local image_head = head_node:getChildByName("image_clipping")
	if image_head then
		image_head:setTouchEnabled(true)
		image_head:addClickEventListener(handler(self, self.onImgPlayerHeadTouch))
	end

    self.hall_middle_layout_ = HallMiddleLayout:create().root    
    self:addChild(self.hall_middle_layout_)
    self.hall_middle_layout_:setPosition(display.center)
	
    self.hall_bottom_layout_ = HallBottomLayout:create().root    
    self:addChild(self.hall_bottom_layout_)
    self.hall_bottom_layout_:setPosition(display.top_bottom)

    local node_middle = self.hall_middle_layout_:getChildByName("node_middle")
    local img_normal_room = node_middle:getChildByName("img_middle")
    img_normal_room:setTouchEnabled(true)
    img_normal_room:addClickEventListener(handler(self, self.onImgNormalRoomTouch))

	local node = self.hall_middle_layout_:getChildByName("node_right")
    local img = node:getChildByName("img_right")
    img:setTouchEnabled(true)
    img:addClickEventListener(handler(self, self.onImgRightTouch))

	node = self.hall_middle_layout_:getChildByName("node_left")
    img = node:getChildByName("img_left")
    img:setTouchEnabled(true)
    img:addClickEventListener(handler(self, self.onImgLeftTouch))
	
	-- store
	local img_shop = self.hall_bottom_layout_:getChildByName("img_shop")
	img_shop:setTouchEnabled(true)
	img_shop:addClickEventListener(handler(self, self.onImgStoreTouch))
end

function HallScene:onImgPlayerHeadTouch(sender)
	print("[HallScene:onImgPlayerHeadTouch]")
	gamer.popup_mgr_.showPopup(gamer.PopupIDs.POPUP_ID_HALL_PLAYER_INFO)
end

function HallScene:onImgStoreTouch(sender)
    print("[HallScene:onImgStoreTouch]")
	gamer.popup_mgr_.showPopup(gamer.PopupIDs.POPUP_ID_STORE)
end

function HallScene:onImgRightTouch(sender)
    print("[HallScene:onImgRightTouch]")
	gamer.popup_mgr_.showPopup(gamer.PopupIDs.POPUP_ID_ROOM_JOIN)
end

function HallScene:onImgLeftTouch(sender)
    print("[HallScene:onImgLeftTouch]")

	local proto_room = gamer.data_mgr_:create_room_msg_protocol()	
	print("[HallScene:onImgLeftTouch] room_owner_id, room_id : ", proto_room:room_owner_id(), proto_room:room_id())

	local proto = gamer.protocol.RoomMsgProtocol()
    proto:set_room_id(proto_room:room_id())
    proto:set_room_owner_id(proto_room:room_owner_id())

    gamer.msg_mgr_:sendMsg(gamer.MsgTypes.C2S_MSG_TYPE_ROOM, gamer.MsgIDs.MSG_ID_ROOM_START_GAME, proto)
end

function HallScene:onImgNormalRoomTouch(sender)
    print("[HallScene:onImgNormalRoomTouch]")
	gamer.popup_mgr_.showPopup(gamer.PopupIDs.POPUP_ID_ROOM_CREATE)
end

function HallScene:dealWithCreateRoomMsgReceived(code, msg)
	print("[HallScene:dealWithCreateRoomMsgReceived]")
	print("[HallScene:dealWithCreateRoomMsgReceived] room_id : ", msg:room_id())
	gamer.popup_mgr_.removePopup(gamer.PopupIDs.POPUP_ID_ROOM_CREATE)
end

function HallScene:dealWithJoinRoomMsgReceived(code, msg)
    print("[HallScene:dealWithJoinRoomMsgReceived] code : ", code)
	if code == gamer.MsgCodes.SUCCEED then
		gamer.popup_mgr_.removePopup(gamer.PopupIDs.POPUP_ID_ROOM_JOIN)
		--[[
		if not self.test_ then
			self.test_ = true
			return
		end
	
		if not self.test2_ then
			self.test2_ = true
			return
		end
		]]
		local proto_room = gamer.data_mgr_:create_room_msg_protocol()	
		print("[HallScene:dealWithJoinRoomMsgReceived] room_owner_id, room_id : ", proto_room:room_owner_id(), proto_room:room_id())

		gamer.msg_helper_.sendStartGameMsg()
		--[[
		local proto = gamer.protocol.RoomMsgProtocol()
		proto:set_room_id(proto_room:room_id())
		proto:set_room_owner_id(proto_room:room_owner_id())

		gamer.msg_mgr_:sendMsg(gamer.MsgTypes.C2S_MSG_TYPE_ROOM, gamer.MsgIDs.MSG_ID_ROOM_START_GAME, proto)
		]]
	end
end

function HallScene:dealWithStartGameMsgReceived(code, msg)
	print("[HallScene:dealWithStartGameMsgReceived]")
	gamer.scene_mgr_.runScene(gamer.SceneIDs.NORMAL_ROOM_SCENE)
end

function HallScene:addMsgListeners()
	gamer.msg_mgr_:addMsgListener(gamer.MsgTypes.S2C_MSG_TYPE_ROOM, handler(self, self.onServerMsgReceived))
end

function HallScene:removeMsgListeners()
	gamer.msg_mgr_:removeMsgListener(gamer.MsgTypes.S2C_MSG_TYPE_ROOM, handler(self, self.onServerMsgReceived))
end

function HallScene:onServerMsgReceived(code, msg_type, msg_id, msg)
    print("[HallScene:onServerMsgReceived] code, msg_type, msg_id : ", code, msg_type, msg_id)
	if code ~= gamer.MsgCodes.SUCCEED then
		print("[HallScene:onServerMsgReceived] error")
	end

	if msg_type == gamer.MsgTypes.S2C_MSG_TYPE_ROOM then
		if msg_id == gamer.MsgIDs.MSG_ID_ROOM_CREATE then
			self:dealWithCreateRoomMsgReceived(code, msg)
		elseif msg_id == gamer.MsgIDs.MSG_ID_ROOM_PLAYER_JOIN then
			self:dealWithJoinRoomMsgReceived(code, msg)
		elseif msg_id == gamer.MsgIDs.MSG_ID_ROOM_START_GAME then
			self:dealWithStartGameMsgReceived(code, msg)
		end
	end
end

function HallScene:onEnter()
	-- TODO : dispatch layer enter event to all listeners
    print("[HallScene:onEnter]")
    self:addMsgListeners()
end

function HallScene:onExit()
	-- TODO : dispatch layer exit event to all listeners
    print("[HallScene:onExit]")
	self:removeMsgListeners()
end

return HallScene