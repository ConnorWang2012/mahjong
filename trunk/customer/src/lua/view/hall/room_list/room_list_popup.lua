--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   setting_popup.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2018-03-03
@ description: setting popup.
@ others:
@ history:
1.date:
author:
modification:
--]]

local RoomListPopup = class("RoomListPopup", require "view.base.popup_base")
local RoomListItem  = require "view.layouts.ui.hall.room_list.room_item_node_layout.lua"

RoomListPopup.RoomTypes =
{
	ROOM_TYPE_1 = 1,
	ROOM_TYPE_2 = 2,
	ROOM_TYPE_3 = 3,
}

function RoomListPopup:ctor(view_file)
	print("[RoomListPopup:ctor]")
    self.super.ctor(self, view_file)

	self:closeWhenTouchBackground(true)

	self:showLoadingView()
end

function RoomListPopup:initView(room_list_msg_proto)
	self.panel_data_   = self.root_node_:getChildByName("panel_data")
	self.lv_room_list_ = self.panel_data_:getChildByName("lv_rooms")
	self.lv_room_list_:setBounceEnabled(true)

	-- init room name
	local img_bg = self.root_node_:getChildByName("img_bg")
	for i = 1, 3 do
		local txt_room_name = img_bg:getChildByName("txt_room_name" .. i)
		txt_room_name:setString(gamer.strings_["str_room_name" .. i])

		txt_room_name:setLocalZOrder(i + 10)
	end

	local img_tab1 = img_bg:getChildByName("img_tab1")
	local img_tab2 = img_bg:getChildByName("img_tab2")
	local img_tab3 = img_bg:getChildByName("img_tab3")
	img_tab1:setTag(RoomListPopup.RoomTypes.ROOM_TYPE_1)
	img_tab2:setTag(RoomListPopup.RoomTypes.ROOM_TYPE_2)
	img_tab3:setTag(RoomListPopup.RoomTypes.ROOM_TYPE_3)
	img_tab1:setTouchEnabled(true)
	img_tab2:setTouchEnabled(true)
	img_tab3:setTouchEnabled(true)
	img_tab1:addClickEventListener(handler(self, self.onRoomTypeSelect))
	img_tab2:addClickEventListener(handler(self, self.onRoomTypeSelect))
	img_tab3:addClickEventListener(handler(self, self.onRoomTypeSelect))

	self:setSelectedStatus(img_tab1)

	-- init room list
	self:initRoomList(room_list_msg_proto, RoomListPopup.RoomTypes.ROOM_TYPE_1)
end

function RoomListPopup:initRoomList(room_list_msg_proto, room_type)
	self.lv_room_list_:removeAllChildren()

	for i = 0, room_list_msg_proto:room_items_size() - 1 do
		if room_type == room_list_msg_proto:room_items(i):room_type() then
			local item = self:createRoomListItem(room_list_msg_proto:room_items(i))
			if item then
				self.lv_room_list_:pushBackCustomItem(item)
			end
		end
	end
end

function RoomListPopup:createRoomListItem(data)
	print("[RoomListPopup:createRoomListItem]")
	if not data then
		print("[RoomListPopup:createRoomListItem] data nil, return")
		return nil
	end

	local item   = RoomListItem:create().root
	local txt_room_name  = item:getChildByName("txt_room_name")
	local txt_base_score = item:getChildByName("txt_base_score")
	local txt_min_score  = item:getChildByName("txt_min_score")
	
	txt_room_name:setString(self:getRoomName(data:sub_room_type()))
	txt_base_score:setString(data:base_score())
	txt_min_score:setString(data:min_score())

	local layout = ccui.Layout:create()
	local width  = 457
	local height = 657
	item:setName("item")
	item:setPosition(cc.p(width / 2, height / 2))
	layout:setContentSize(width, height)
	layout:addChild(item)

	return layout
end

function RoomListPopup:getRoomName(sub_room_type)
	if sub_room_type <= 3 then
		return gamer.strings_["str_sub_room_name" .. sub_room_type]
	end
	return gamer.strings_["str_sub_room_name1"]
end

function RoomListPopup:dealWithGetRoomListMsgReceived(code, msg)
	print("[RoomListPopup:dealWithGetRoomListMsgReceived]")
	if tolua.isnull(self) then
		print("[RoomListPopup:dealWithGetRoomListMsgReceived] tolua.isnull(self), return")
		return
	end

	if code == gamer.MsgCodes.SUCCEED then
		self:initView(msg)
		self:showDataView()
	else
		self:showEmptyView()
	end
end

function RoomListPopup:addMsgListeners()
	print("[RoomListPopup:addMsgListeners]")
	self.listener_ids_ = {}

	local id = gamer.msg_mgr_:addMsgListener(gamer.MsgTypes.S2C_MSG_TYPE_ROOM, handler(self, self.onServerMsgReceived))
	
	print("[RoomListPopup:addMsgListeners] listener id :", id)
	if id then
		table.insert(self.listener_ids_, id)
	end
end

function RoomListPopup:setSelectedStatus(cur_select_page)
	if self.cur_select_page_ then
		self.cur_select_page_:setLocalZOrder(1)
		self.cur_select_page_:setColor(cc.c3b(255, 255, 255))
	end
	cur_select_page:setLocalZOrder(3)
	cur_select_page:setColor(cc.c3b(0, 255, 0))

	self.cur_select_page_ = cur_select_page
end

function RoomListPopup:onRoomTypeSelect(sender)
	print("[RoomListPopup:onRoomTypeSelect]")
	local room_type = sender:getTag()
	if self.cur_select_page_ and self.cur_select_page_:getTag() == room_type then
		print("[RoomListPopup:onRoomTypeSelect] cur page has showed, return")
		return
	end

	local room_list_msg_proto = gamer.data_mgr_:room_list_msg_protocol()
	if room_list_msg_proto then
		self:initRoomList(room_list_msg_proto, room_type)
	else
		print("[RoomListPopup:onRoomTypeSelect] room_list_msg_proto nil")
	end

	self:setSelectedStatus(sender)
end

function RoomListPopup:onServerMsgReceived(code, msg_type, msg_id, msg)
    print("[RoomListPopup:onServerMsgReceived] code, msg_type, msg_id : ", code, msg_type, msg_id)
	if code ~= gamer.MsgCodes.SUCCEED then
		print("[RoomListPopup:onServerMsgReceived] error")
	end

	if msg_type == gamer.MsgTypes.S2C_MSG_TYPE_ROOM then
		if msg_id == gamer.MsgIDs.MSG_ID_ROOM_GET_ROOM_LIST then
			self:dealWithGetRoomListMsgReceived(code, msg)
		end
	end
end

function RoomListPopup:onEnter()
    print("[RoomListPopup:onEnter]")
	self:addMsgListeners()

	gamer.msg_helper_.sendGetRoomListMsg()
end

function RoomListPopup:onExit()
    print("[RoomListPopup:onExit]")
	self:removeMsgListeners()
end

return RoomListPopup