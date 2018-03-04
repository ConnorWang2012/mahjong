--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   head_portrait_select_popup.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2018-01-28
@ description: head portrait select popup.
@ others:
@ history:
1.date:
author:
modification:
--]]

local HeadPortraitSelectPopup = class("HeadPortraitSelectPopup", require "view.base.popup_base")
local PlayerConst             = require "logic.constant.player_constants.lua"

function HeadPortraitSelectPopup:ctor(view_file)
	print("[HeadPortraitSelectPopup:ctor]")
    self.super.ctor(self, view_file)

	self:closeWhenTouchBackground(true)

	self:initLayout()
end

function HeadPortraitSelectPopup:initLayout()
	self:initScrollView()

	local panel_data = self.root_node_:getChildByName("panel_data")
	local img_select_from_phone = panel_data:getChildByName("img_select_from_phone")
	img_select_from_phone:setVisible(false)

	local img_ok = panel_data:getChildByName("img_ok")
	local img_cancel = panel_data:getChildByName("img_cancel")
	img_ok:setTouchEnabled(true)
	img_cancel:setTouchEnabled(true)
	img_ok:addClickEventListener(handler(self, self.onImgOKTouch))
	img_cancel:addClickEventListener(handler(self, self.onImgCancelTouch))
end

function HeadPortraitSelectPopup:initScrollView()
	local panel_data = self.root_node_:getChildByName("panel_data")
	local sv_head_portrait = panel_data:getChildByName("sv_head_portrait")
	
	cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/head.plist")

	local num_one_line = 37
	local interval = 8
	local size = { width = 230, height = 230 }
	sv_head_portrait:setInnerContainerSize({ width = (size.width + interval) * num_one_line, 
		height = size.height * 2 + interval })

	for i = 1, num_one_line do
		local img_head = ccui.ImageView:create()
		img_head:setTag(i)
		img_head:loadTexture("head_" .. i .. ".png", ccui.TextureResType.plistType)
		img_head:setPosition(size.width * i - size.width / 2 + interval * (i - 1), size.height / 2)
		sv_head_portrait:addChild(img_head)

		img_head:setTouchEnabled(true)
		img_head:addClickEventListener(handler(self, self.onImgHeadTouch))

		img_head = ccui.ImageView:create()
		img_head:setTag(i + num_one_line)
		img_head:loadTexture("head_" .. (i + num_one_line) .. ".png", ccui.TextureResType.plistType)
		img_head:setPosition(size.width * i - size.width / 2 + interval * (i - 1), size.height * 1.5 + interval)
		sv_head_portrait:addChild(img_head)

		img_head:setTouchEnabled(true)
		img_head:addClickEventListener(handler(self, self.onImgHeadTouch))
	end
end

function HeadPortraitSelectPopup:onImgOKTouch(sender)
    print("[HeadPortraitSelectPopup:onImgOKTouch]")
	gamer.widget_helper_.playDefaultTouchActionForImage(sender)
	gamer.audio_mgr_.playCommonTouchEffectMusic()

	if not self.last_selected_image_ then
		gamer.popup_mgr_.showCenterTipPopup(gamer.strings_["str_select_one_head_portrait"])
		return
	end

	gamer.popup_mgr_.showCenterTipPopup(gamer.strings_["str_modifying"])

	gamer.msg_helper_.sendModifyLocalHeadPortraitMsg(self.last_selected_image_:getTag())
end

function HeadPortraitSelectPopup:onImgCancelTouch(sender)
    print("[HeadPortraitSelectPopup:onImgCancelTouch]")
	gamer.widget_helper_.playDefaultTouchActionForImage(sender)
	gamer.audio_mgr_.playCommonTouchEffectMusic()

	self:removeSelf()
end

function HeadPortraitSelectPopup:onImgHeadTouch(sender)
    print("[HeadPortraitSelectPopup:onImgHeadTouch]")
	gamer.audio_mgr_.playCommonTouchEffectMusic()

	if sender ~= self.last_selected_image_ then
		if self.last_selected_image_ then
			self.last_selected_image_:setLocalZOrder(1)

			local scale_to = cc.ScaleTo:create(0.1, 1)
			self.last_selected_image_:runAction(scale_to)
		end

		sender:setLocalZOrder(1000)

		local scale_by = cc.ScaleBy:create(0.1, 1.2)
		sender:runAction(scale_by)

		self.last_selected_image_ = sender
	end
end

function HeadPortraitSelectPopup:onEnter()
    print("[HeadPortraitSelectPopup:onEnter]")
end

function HeadPortraitSelectPopup:onExit()
    print("[HeadPortraitSelectPopup:onExit]")
end

return HeadPortraitSelectPopup