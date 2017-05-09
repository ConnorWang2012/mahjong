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

local LoginScene = class("LoginScene", require "view.base.node_base")

function LoginScene:ctor()
    display.newSprite("HelloWorld.png"):move(display.center):addTo(self)
end

return LoginScene