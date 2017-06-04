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

local HallScene = class("HallScene", require "view.base.layer_base")

function HallScene:ctor(view_file)
    self.super.ctor(self, view_file)
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