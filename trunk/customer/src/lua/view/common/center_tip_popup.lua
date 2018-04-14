--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   center_tip_popup.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2018-01-28
@ description: center tip.
@ others:
@ history:
1.date:
author:
modification:
--]]

local CenterTipPopup = class("CenterTipPopup", require "view.base.popup_base")

function CenterTipPopup:ctor(view_file, txt_tip, show_time)
	print("[CenterTipPopup:ctor]")
    self.super.ctor(self, view_file)

	self:initView(show_time)
	self:setTip(txt_tip)
	self:showAsTop()
end

function CenterTipPopup:initView(show_time)
	self:setAnchorPoint(cc.p(0.5, 0.5))
	self:setPosition(display.center)

	local img_bg  = self.root_node_:getChildByName("img_bg")
	self.txt_tip_ = img_bg:getChildByName("txt_tip")

	self.show_time_ = show_time or 2

	self:setOpacity(0)

	local func = function()
		self:removeSelf()
	end
	local fadein_action = cc.FadeIn:create(self.show_time_ / 2)
	local fadeout_action = cc.FadeOut:create(self.show_time_ / 2)
	local call_action = cc.CallFunc:create(func)
	local sequence_action = cc.Sequence:create(fadein_action, fadeout_action, call_action)
	img_bg:runAction(sequence_action)
end

function CenterTipPopup:setTip(txt_tip)
    print("[CenterTipPopup:setTip]")
	if txt_tip then
		self.txt_tip_:setString(txt_tip)
	end
end

function CenterTipPopup:onEnter()
    print("[CenterTipPopup:onEnter]")
end

function CenterTipPopup:onExit()
    print("[CenterTipPopup:onExit]")
end

return CenterTipPopup