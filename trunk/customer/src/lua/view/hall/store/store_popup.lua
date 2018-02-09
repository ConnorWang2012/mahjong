--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   store_popup.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-07-27
@ description: store popup.
@ others:
@ history:
1.date:
author:
modification:
--]]

local StorePopup = class("StorePopup", require "view.base.popup_base")

function StorePopup:ctor(view_file)
	print("[StorePopup:ctor]")
    self.super.ctor(self, view_file)

	self:initLayout()
	self:closeWhenTouchBackground(true)
end

function StorePopup:initLayout()

end

function StorePopup:onEnter()
    print("[StorePopup:onEnter]")
end

function StorePopup:onExit()
    print("[StorePopup:onExit]")
end

return StorePopup