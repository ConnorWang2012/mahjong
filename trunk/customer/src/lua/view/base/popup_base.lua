--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   popup_base.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-07-27
@ description: popup base class.
@ others:
@ history:
1.date:
author:
modification:
--]]

local PopupBase = class("PopupBase", require "view.base.layer_base")

function PopupBase:ctor(view_file)
	print("[PopupBase:ctor]")
    PopupBase.super.ctor(self, view_file)
end

function PopupBase:onEnter()
    print("[PopupBase:onEnter]")
	-- TODO : dispatch popup enter event to all listeners
end

function PopupBase:onExit()
    print("[PopupBase:onExit]")
	-- TODO : dispatch popup exit event to all listeners
end

return PopupBase
