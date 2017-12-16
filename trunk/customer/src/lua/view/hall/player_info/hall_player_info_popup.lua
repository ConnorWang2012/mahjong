--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   hall_player_info_popup.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-12-17
@ description: hall player info popup.
@ others:
@ history:
1.date:
author:
modification:
--]]

local HallPlayerInfoPopup = class("HallPlayerInfoPopup", require "view.base.popup_base")

function HallPlayerInfoPopup:ctor(view_file)
	print("[HallPlayerInfoPopup:ctor]")
    self.super.ctor(self, view_file)

	self:initLayout()
	self:closeWhenTouchBackground(true)
end

function HallPlayerInfoPopup:initLayout()

end

function HallPlayerInfoPopup:onEnter()
    print("[HallPlayerInfoPopup:onEnter]")
end

function HallPlayerInfoPopup:onExit()
    print("[HallPlayerInfoPopup:onExit]")
end

return HallPlayerInfoPopup