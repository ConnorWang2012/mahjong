--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   login_layer.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: login layer.
@ others:
@ history:
1.date:
author:
modification:
--]]

local LoginLayer = class("LoginLayer", require "view.base.layer_base")

function LoginLayer:ctor()
    -- add background image
    display.newSprite("HelloWorld.png")
        :move(display.center)
        :addTo(self)

    -- add HelloWorld label
--    cc.Label:createWithSystemFont("Hello World", "Arial", 40)
--        :move(display.cx, display.cy + 200)
--        :addTo(self)

end

return LoginLayer