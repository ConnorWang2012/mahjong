--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   create_room_popup.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-07-27
@ description: create room popup.
@ others:
@ history:
1.date:
author:
modification:
--]]

local CreateRoomPopup = class("CreateRoomPopup", require "view.base.popup_base")

function CreateRoomPopup:ctor(view_file)
	print("[CreateRoomPopup:ctor]")
    self.super.ctor(self, view_file)

	self:initLayout()
end

function CreateRoomPopup:initLayout()
	local img_bg = self.root_view_node_:getChildByName("img_bg")
	local img_create = img_bg:getChildByName("img_create")
	img_create:setTouchEnabled(true)
    img_create:addClickEventListener(handler(self, self.onImgCreateRoomTouch))
end

function CreateRoomPopup:onImgCreateRoomTouch(sender)
    print("[CreateRoomPopup:onImgCreateRoomTouch]")

	local proto = gamer.protocol.CreateRoomMsgProtocol()
    proto:set_room_owner_id(10000001)
    proto:set_rounds_num(10)
    proto:set_players_num(2)
    proto:set_room_cards_num(1)

    gamer.msg_mgr_:sendMsg(gamer.MsgTypes.C2S_MSG_TYPE_ROOM, gamer.MsgIDs.MSG_ID_ROOM_CREATE, proto)
end

function CreateRoomPopup:onEnter()
    print("[CreateRoomPopup:onEnter]")
end

function CreateRoomPopup:onExit()
    print("[CreateRoomPopup:onEnter]")
end

return CreateRoomPopup
