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

    local proto = gamer.protocol.MyLoginMsgProtocol()
    proto:set_account(2017)
    proto:set_password(2018)

    gamer.MsgManager:getInstance():sendMsg(gamer.MsgTypes.C2S_MSG_TYPE_LOGIN, 
        gamer.MsgIDs.MSG_ID_LOGIN_MY, 
        proto, 
        handler(self, self.onLoginResponse))
end

function LoginScene:onLoginResponse(code, msg_type, msg_id, msg)
    print("[LoginScene:onLoginResponse] code : ", code)
    if code == gamer.MsgCodes.SUCCEED then
        gamer.SceneManager.runScene(gamer.SceneConstants.SceneIDs.HALL_SCENE)
    end
end

function LoginScene:onEnter()
	-- TODO : dispatch layer enter event to all listeners
    print("[LoginScene:onEnter]")
    
end

function LoginScene:onExit()
	-- TODO : dispatch layer exit event to all listeners
    print("[LoginScene:onExit]")
end

return LoginScene