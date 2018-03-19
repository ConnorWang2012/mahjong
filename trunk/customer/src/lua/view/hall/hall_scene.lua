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
local PlayerConst       = require "logic.constant.player_constants.lua"

function HallScene:ctor(view_file)
    self.super.ctor(self, view_file)

    self:initLayout()
end

function HallScene:initLayout()
	-- 1.init top
    self.hall_top_layout_ = HallTopLayout:create().root    
    self:addChild(self.hall_top_layout_)
    self.hall_top_layout_:setPosition(display.top_center)

	-- head portrail
	self.player_head_layout_ = PlayerHeadLayout:create().root
	self.hall_top_layout_:getChildByName("node_head"):addChild(self.player_head_layout_)
	local head_node = PlayerHeadCreator.createPlayerSelfHeadPortrait()
	self.player_head_layout_:addChild(head_node)

	local image_head = head_node:getChildByName("image_clipping")
	if image_head then
		image_head:setTouchEnabled(true)
		image_head:addClickEventListener(handler(self, self.onImgPlayerHeadTouch))
	end

	-- nick name
	local player_proto   = gamer.data_mgr_:my_login_msg_protocol():player()
	self:initNickname(player_proto:nick_name())

	self:initVipLevel(player_proto:vip_level())

	self:initLevelName(player_proto:level(), player_proto:level_name())
	
	-- setting
	local img_setting = self.hall_top_layout_:getChildByName("img_setting")
	img_setting:setTouchEnabled(true)
    img_setting:addClickEventListener(handler(self, self.onImgSettingTouch))

	-- 2.init mid
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
	
	-- 3.init bottom
	-- store
	local img_shop = self.hall_bottom_layout_:getChildByName("img_shop")
	img_shop:setTouchEnabled(true)
	img_shop:addClickEventListener(handler(self, self.onImgStoreTouch))
end

function HallScene:initHeadPortrait(portrait_type, portrait_id, buffer)
	print("[HallScene:initHeadPortrait]")
	if portrait_type == PlayerConst.PortraitTypes.LOCAL then
		self:initLocalHeadPortrait(portrait_id)
	elseif portrait_type == PlayerConst.PortraitTypes.PERSONNAL then
		self:initPersonalHeadPortrait(buffer)
	else
		print("[HallScene:initHeadPortrait] portrait_type invalid")
	end
end

function HallScene:initNickname(nickname)
	print("[HallScene:initNickname] nickname :", nickname)
	if nickname then
		local txt_nickname = self.player_head_layout_:getChildByName("txt_name")
		txt_nickname:setString(nickname)
	end
end

function HallScene:initVipLevel(vip)
	print("[HallScene:initVipLevel] vip :", vip)
	if vip then
		local txt_vip_level = self.player_head_layout_:getChildByName("txt_vip_level")
		txt_vip_level:setString("VIP : " .. vip)
	end
end

function HallScene:initLevelName(level, levelname)
	print("[HallScene:initLevelName] level :", level)
	print("[HallScene:initLevelName] levelname :", levelname)
	if level and levelname then
		local txt_level_name = self.player_head_layout_:getChildByName("txt_level_name")
		txt_level_name:setString(gamer.strings_["str_level"] .. " : " .. level .. "（" .. levelname .. "）")
	end
end

function HallScene:initSex(sex)
	print("[HallScene:initSex] sex :", sex)
end

function HallScene:initLocalHeadPortrait(portrait_id)
	print("[HallScene:initLocalHeadPortrait] portrait_id :", portrait_id)
	if not portrait_id or tonumber(portrait_id) > PlayerConst.MAX_HEAD_PORTRAIT_NUM then
		print("[HallScene:initLocalHeadPortrait] portrait_id invalid, return")
		return
	end

	local head_node = self.player_head_layout_:getChildByName("node_clipping")
	if head_node then
		local img_head = head_node:getChildByName("image_clipping")
		if img_head then
			img_head:loadTexture("head_" .. portrait_id .. ".png", ccui.TextureResType.plistType)
		end
	end
end

function HallScene:initPersonalHeadPortrait(buffer)
	print("[HallScene:initPersonalHeadPortrait]")
end

function HallScene:setProperty(set_property_msg)
	print("[HallScene:setProperty]")

	if set_property_msg then
		for i = 0, set_property_msg:property_ids_size() - 1 do
			local prop_id = set_property_msg:property_ids(i)
			print("[HallScene:setProperty] property_id :", prop_id)
			if prop_id == gamer.PropertyIDs.PROP_ID_NICKNAME then
				self:initNickname(set_property_msg:new_properties(i))
			elseif prop_id == gamer.PropertyIDs.PROP_ID_SEX then
				self:initSex(set_property_msg:new_properties(i))
			elseif prop_id == gamer.PropertyIDs.PROP_ID_HEAD_PORTRAIT_LOCAL then
				self:initLocalHeadPortrait(set_property_msg:new_properties(i))
			elseif prop_id == gamer.PropertyIDs.PROP_ID_HEAD_PORTRAIT_PERSONAL then
				self:initPersonalHeadPortrait(set_property_msg:new_properties(i))
			end
		end
	end
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

		gamer.msg_helper_.sendPersonalRoomStartGameMsg()
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

function HallScene:dealWithSetPropertyMsgReceived(code, msg)
	print("[HallScene:dealWithSetPropertyMsgReceived] code :", code)
	if tolua.isnull(self) then
		print("[HallScene:dealWithSetPropertyMsgReceived] tolua.isnull(self), return")
		return
	end

	if code == gamer.MsgCodes.SUCCEED then
		self:setProperty(msg)
	end
end

function HallScene:dealWithPropertyChangedMsgReceived(code, msg)
	print("[HallScene:dealWithPropertyChangedMsgReceived] code :", code)
	if tolua.isnull(self) then
		print("[HallScene:dealWithPropertyChangedMsgReceived] tolua.isnull(self), return")
		return
	end

	if code == gamer.MsgCodes.SUCCEED then
		self:setProperty(msg)
	end
end

function HallScene:addMsgListeners()
	print("[HallScene:addEventListeners]")
	gamer.msg_mgr_:addMsgListener(gamer.MsgTypes.S2C_MSG_TYPE_ROOM, handler(self, self.onServerMsgReceived))
	gamer.msg_mgr_:addMsgListener(gamer.MsgTypes.S2C_MSG_TYPE_PROPERTY, handler(self, self.onServerMsgReceived))
end

function HallScene:removeMsgListeners()
	print("[HallScene:removeEventListeners]")
	gamer.msg_mgr_:removeMsgListener(gamer.MsgTypes.S2C_MSG_TYPE_ROOM, handler(self, self.onServerMsgReceived))
	gamer.msg_mgr_:removeMsgListener(gamer.MsgTypes.S2C_MSG_TYPE_PROPERTY, handler(self, self.onServerMsgReceived))
end

function HallScene:onImgPlayerHeadTouch(sender)
	print("[HallScene:onImgPlayerHeadTouch]")
	gamer.widget_helper_.playDefaultTouchActionForImage(sender)
	gamer.audio_mgr_.playCommonTouchEffectMusic()
	gamer.popup_mgr_.showPopup(gamer.PopupIDs.POPUP_ID_HALL_PLAYER_INFO)
end

function HallScene:onImgSettingTouch(sender)
	print("[HallScene:onImgSettingTouch]")
	gamer.widget_helper_.playDefaultTouchActionForImage(sender)
	gamer.audio_mgr_.playCommonTouchEffectMusic()
	gamer.popup_mgr_.showPopup(gamer.PopupIDs.POPUP_ID_SETTING)
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
	--[[
	local proto_room = gamer.data_mgr_:create_room_msg_protocol()	
	print("[HallScene:onImgLeftTouch] room_owner_id, room_id : ", proto_room:room_owner_id(), proto_room:room_id())

	local proto = gamer.protocol.RoomMsgProtocol()
    proto:set_room_id(proto_room:room_id())
    proto:set_room_owner_id(proto_room:room_owner_id())

    gamer.msg_mgr_:sendMsg(gamer.MsgTypes.C2S_MSG_TYPE_ROOM, gamer.MsgIDs.MSG_ID_ROOM_START_GAME, proto)
	]]
	gamer.popup_mgr_.showPopup(gamer.PopupIDs.POPUP_ID_ROOM_LIST)
end

function HallScene:onImgNormalRoomTouch(sender)
    print("[HallScene:onImgNormalRoomTouch]")
	gamer.popup_mgr_.showPopup(gamer.PopupIDs.POPUP_ID_ROOM_CREATE)
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
	elseif msg_type == gamer.MsgTypes.S2C_MSG_TYPE_PROPERTY then
		if msg_id == gamer.MsgIDs.MSG_ID_PROPERTY_SET then
			self:dealWithSetPropertyMsgReceived(code, msg)
		elseif msg_id == gamer.MsgIDs.MSG_ID_PROPERTY_CHANGED then
			self:dealWithPropertyChangedMsgReceived(code, msg)
		end
	end
end

function HallScene:onEnter()
	-- TODO : dispatch layer enter event to all listeners
    print("[HallScene:onEnter]")
    self:addMsgListeners()

	local opened = cc.UserDefault:getInstance():getIntegerForKey("hall_bgm_opened", 1)
	if 1 == opened then
		gamer.audio_mgr_.playHallBGM()
	end
end

function HallScene:onExit()
	-- TODO : dispatch layer exit event to all listeners
    print("[HallScene:onExit]")
	self:removeMsgListeners()
	gamer.audio_mgr_.stopHallBGM()
end

return HallScene