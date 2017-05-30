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
    gamer.MsgManager:getInstance():sendMsg(0, 1, handler(self, self.onLoginResponse))
end

function LoginScene:onLoginResponse(data)
    print("[LoginScene:onLoginResponse] data : ", tostring(data))
    --print("[LoginScene:onLoginResponse] account : ", tostring(data:account()))
    --local a = tolua.cast(data, "gamer::protocol::MyLoginMsgProtocol")
    --print("[LoginScene:onLoginResponse] account : ", tostring(a:account()))
    --data:password()
end

function LoginScene:onEnter()
	-- TODO : dispatch layer enter event to all listeners
    print("[LoginScene:onEnter]")
    
end

function LoginScene:onExit()
	-- TODO : dispatch layer exit event to all listeners
end

return LoginScene