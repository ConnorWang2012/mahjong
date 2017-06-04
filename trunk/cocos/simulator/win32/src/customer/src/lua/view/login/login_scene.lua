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
    --gamer.SceneManager.runScene(gamer.SceneConstants.SceneIDs.HALL_SCENE)
end

function LoginScene:onLoginResponse(code, msg_type, msg_id, msg)
--    print("[LoginScene:onLoginResponse] msg : ", tostring(msg))
    print("[LoginScene:onLoginResponse] code : ", code)
--    print("[LoginScene:onLoginResponse] msg_type : ", msg_type)
--    print("[LoginScene:onLoginResponse] msg_id : ", msg_id)
--    print("[LoginScene:onLoginResponse] account : ", tostring(msg:account()))
    gamer.SceneManager.runScene(gamer.SceneConstants.SceneIDs.HALL_SCENE)
    --self:setVisible(false)

    --local director = cc.Director:getInstance()
    --local hallscene = (require "view.hall.hall_scene.lua"):create()
    --local l = (require "view.layouts.scene.hall.hall_scene_layout.lua"):create()
    --hallscene:addChild(l)
    --self:addChild(hallscene)

--    self.schedulerID = cc.Director:getInstance():getScheduler():scheduleScriptFunc(function()  
--        cc.Director:getInstance():getScheduler():unscheduleScriptEntry(self.schedulerID)
--        gamer.SceneManager.runScene(gamer.SceneConstants.SceneIDs.HALL_SCENE)
--    end, 1, false)
end

function LoginScene:onEnter()
	-- TODO : dispatch layer enter event to all listeners
    print("[LoginScene:onEnter]")
    
end

function LoginScene:onExit()
	-- TODO : dispatch layer exit event to all listeners
end

return LoginScene