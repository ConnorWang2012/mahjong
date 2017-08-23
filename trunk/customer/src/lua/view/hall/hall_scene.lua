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

local HallScene         = class("HallScene", require "view.base.layer_base")
local HallTopLayout     = require "view.layouts.ui.hall.hall_top_node_layout"
local HallMiddleLayout  = require "view.layouts.ui.hall.hall_middle_node_layout"
local HallBottomLayout  = require "view.layouts.ui.hall.hall_bottom_node_layout"

function HallScene:ctor(view_file)
    self.super.ctor(self, view_file)

    self:initLayout()
end

function HallScene:initLayout()
    self.hall_top_layout = HallTopLayout:create().root    
    self:addChild(self.hall_top_layout)
    self.hall_top_layout:setPosition(display.top_center)

    self.hall_middle_layout = HallMiddleLayout:create().root    
    self:addChild(self.hall_middle_layout)
    self.hall_middle_layout:setPosition(display.center)

    self.hall_bottom_layout = HallBottomLayout:create().root    
    self:addChild(self.hall_bottom_layout)
    self.hall_bottom_layout:setPosition(display.top_bottom)

    local node_middle = self.hall_middle_layout:getChildByName("node_middle")
    local img_normal_room = node_middle:getChildByName("img_middle")
    img_normal_room:setTouchEnabled(true)
    img_normal_room:addClickEventListener(handler(self, self.onImgNormalRoomTouch))

	local node = self.hall_middle_layout:getChildByName("node_right")
    local img = node:getChildByName("img_right")
    img:setTouchEnabled(true)
    img:addClickEventListener(handler(self, self.onImgRightTouch))

	node = self.hall_middle_layout:getChildByName("node_left")
    img = node:getChildByName("img_left")
    img:setTouchEnabled(true)
    img:addClickEventListener(handler(self, self.onImgLeftTouch))

end

function HallScene:onImgRightTouch(sender)
    print("[HallScene:onImgRightTouch]")
	gamer.popup_mgr_.showPopup(gamer.PopupConstants.PopupIDs.POPUP_ID_ROOM_JOIN)
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
	gamer.popup_mgr_.showPopup(gamer.PopupConstants.PopupIDs.POPUP_ID_ROOM_CREATE)
end

function HallScene:dealWithCreateRoomMsgReceived(code, msg)
	print("[HallScene:dealWithCreateRoomMsgReceived]")
	print("[HallScene:dealWithCreateRoomMsgReceived] room_id : ", msg:room_id())
	gamer.popup_mgr_.removePopup(gamer.PopupConstants.PopupIDs.POPUP_ID_ROOM_CREATE)
end

function HallScene:dealWithJoinRoomMsgReceived(code, msg)
    print("[HallScene:dealWithJoinRoomMsgReceived] code : ", code)
	if code == gamer.MsgCodes.SUCCEED then
		gamer.popup_mgr_.removePopup(gamer.PopupConstants.PopupIDs.POPUP_ID_ROOM_JOIN)
		
		local proto_room = gamer.data_mgr_:create_room_msg_protocol()	
		print("[HallScene:dealWithJoinRoomMsgReceived] room_owner_id, room_id : ", proto_room:room_owner_id(), proto_room:room_id())

		local proto = gamer.protocol.RoomMsgProtocol()
		proto:set_room_id(proto_room:room_id())
		proto:set_room_owner_id(proto_room:room_owner_id())

		gamer.msg_mgr_:sendMsg(gamer.MsgTypes.C2S_MSG_TYPE_ROOM, gamer.MsgIDs.MSG_ID_ROOM_START_GAME, proto)
	end
end

function HallScene:dealWithStartGameMsgReceived(code, msg)
	print("[HallScene:dealWithStartGameMsgReceived]")
	gamer.scene_msg_.runScene(gamer.SceneConstants.SceneIDs.NORMAL_ROOM_SCENE)
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