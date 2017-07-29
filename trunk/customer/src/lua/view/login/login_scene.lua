--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   login_scene.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: login scene.
@ others:
@ history:
1.date:
author:
modification:
--]]

local LoginScene = class("LoginScene", require "view.base.layer_base")

function LoginScene:ctor(view_file)
    self.super.ctor(self, view_file)
    local btn_login = self.root_view_node_:getChildByName("btn_login")
    btn_login:addClickEventListener(handler(self, self.onBtnLoginTouch))
end

function LoginScene:onBtnLoginTouch(sender)
    print("[LoginScene:onBtnLoginTouch]")
    local connected = gamer.NetworkManager:getInstance():is_connected()
    print("[LoginScene:onBtnLoginTouch] connected : ", tostring(connected))

	math.randomseed(tostring(os.time()):reverse():sub(1, 7))
	local account = math.random(1, 1000)
	print("[LoginScene:onBtnLoginTouch] account : ", account)

    local proto = gamer.protocol.MyLoginMsgProtocol()
    proto:set_account(tostring(account))
    proto:set_password(2030)

    gamer.MsgManager:getInstance():sendMsg(gamer.MsgTypes.C2S_MSG_TYPE_LOGIN, 
        gamer.MsgIDs.MSG_ID_LOGIN_MY, 
        proto)
end

function LoginScene:dealWithMyLoginMsgReceived(code, msg)
	gamer.g_scene_msg_.runScene(gamer.SceneConstants.SceneIDs.HALL_SCENE)
end

function LoginScene:addMsgListeners()
	gamer.g_msg_mgr_:addMsgListener(gamer.MsgTypes.S2C_MSG_TYPE_LOGIN, handler(self, self.onServerMsgReceived))
end

function LoginScene:removeMsgListeners()
	gamer.g_msg_mgr_:removeMsgListener(gamer.MsgTypes.S2C_MSG_TYPE_LOGIN, handler(self, self.onServerMsgReceived))
end

function LoginScene:onServerMsgReceived(code, msg_type, msg_id, msg)
    print("[LoginScene:onServerMsgReceived] code, msg_type, msg_id : ", code, msg_type, msg_id)
	if code ~= gamer.MsgCodes.SUCCEED then
		print("[LoginScene:onServerMsgReceived] error")
	end

	if msg_type == gamer.MsgTypes.S2C_MSG_TYPE_LOGIN then
		if msg_id == gamer.MsgIDs.MSG_ID_LOGIN_MY then
			self:dealWithMyLoginMsgReceived(code, msg)
		end
	end
end

function LoginScene:onEnter()
	-- TODO : dispatch layer enter event to all listeners
    print("[LoginScene:onEnter]")
    self:addMsgListeners()
end

function LoginScene:onExit()
	-- TODO : dispatch layer exit event to all listeners
    print("[LoginScene:onExit]")
	self:removeMsgListeners()
end

return LoginScene