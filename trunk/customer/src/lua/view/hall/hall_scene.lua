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
end

function HallScene:onImgNormalRoomTouch(sender)
    print("[HallScene:onImgNormalRoomTouch]")
    local proto = gamer.protocol.CreateRoomMsgProtocol()
    proto:set_room_owner_id(10000001)
    proto:set_rounds_num(10)
    proto:set_players_num(1)
    proto:set_room_cards_num(1)

    gamer.MsgManager:getInstance():sendMsg(gamer.MsgTypes.C2S_MSG_TYPE_ROOM, 
        gamer.MsgIDs.MSG_ID_ROOM_CREATE, 
        proto,
        handler(self, self.onCreateRoomMsgReceived))
end

function HallScene:onCreateRoomMsgReceived(code, msg_type, msg_id, msg)
    print("[HallScene:onCreateRoomMsgReceived] code : ", code)
    print("[HallScene:onCreateRoomMsgReceived] room_id : ", msg:room_id())
	print("[HallScene:onCreateRoomMsgReceived] room_owner_id : ", msg:room_owner_id())
    if code == gamer.MsgCodes.SUCCEED then
        local proto = gamer.protocol.GameStartMsgProtocol()
        proto:set_room_id(msg:room_id())
        proto:set_room_owner_id(msg:room_owner_id())

        gamer.MsgManager:getInstance():sendMsg(gamer.MsgTypes.C2S_MSG_TYPE_ROOM, 
            gamer.MsgIDs.MSG_ID_ROOM_START_GAME, 
            proto,
            handler(self, self.onGameStartMsgReceived))
    end
end

function HallScene:onGameStartMsgReceived(code, msg_type, msg_id, msg)
    print("[HallScene:onGameStartMsgReceived] code : ", code)
    if code == gamer.MsgCodes.SUCCEED then
        gamer.SceneManager.runScene(gamer.SceneConstants.SceneIDs.NORMAL_ROOM_SCENE)
    end
end

function HallScene:onEnter()
	-- TODO : dispatch layer enter event to all listeners
    print("[HallScene:onEnter]")
    
end

function HallScene:onExit()
	-- TODO : dispatch layer exit event to all listeners
    print("[HallScene:onExit]")
end

return HallScene