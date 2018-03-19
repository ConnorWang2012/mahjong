--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   setting_popup.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2018-03-03
@ description: setting popup.
@ others:
@ history:
1.date:
author:
modification:
--]]

local RoomListPopup = class("RoomListPopup", require "view.base.popup_base")

function RoomListPopup:ctor(view_file)
	print("[RoomListPopup:ctor]")
    self.super.ctor(self, view_file)

	self:initLayout()
	self:closeWhenTouchBackground(true)
end

function RoomListPopup:initLayout()

end

function RoomListPopup:onEnter()
    print("[RoomListPopup:onEnter]")
end

function RoomListPopup:onExit()
    print("[RoomListPopup:onExit]")
end

return RoomListPopup