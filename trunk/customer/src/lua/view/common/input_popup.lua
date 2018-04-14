--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   input_popup.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2018-01-13
@ description: common input popup.
@ others:
@ history:
1.date:
author:
modification:
--]]

local InputPopup = class("InputPopup", require "view.base.popup_base")

function InputPopup:ctor(view_file)
	print("[InputPopup:ctor]")
    self.super.ctor(self, view_file)

	self:initView()
	self:closeWhenTouchBackground(true)
end

function InputPopup:initView()
	local img_bg    = self.root_node_:getChildByName("img_bg")
	self.txt_title_ = img_bg:getChildByName("txt_title")
	local img_close = img_bg:getChildByName("img_close")
	local img_yes   = img_bg:getChildByName("img_yes")
	img_close:setTouchEnabled(true)
    img_close:addClickEventListener(handler(self, self.onImgCloseTouch))

	img_yes:setTouchEnabled(true)
    img_yes:addClickEventListener(handler(self, self.onImgOKTouch))

	-- edit box
	local img_input_bg = img_bg:getChildByName("img_input_bg")
	self.edit_box_ = ccui.EditBox:create(img_input_bg:getContentSize(), "assets/common/input_bg.png")
	self.edit_box_:setFontSize(42)
	self.edit_box_:setFontColor(cc.c3b(244, 164, 95))
	self.edit_box_:setPlaceholderFontSize(42)
	self.edit_box_:setPlaceholderFontColor(cc.c3b(244, 164, 95))
	self.edit_box_:setPlaceHolder(gamer.strings_["str_input_tip"])
	self.edit_box_:setAnchorPoint(cc.p(0.5, 0.5))
	self.edit_box_:setPosition(img_input_bg:getPosition())
	self.edit_box_:setInputMode(cc.EDITBOX_INPUT_MODE_SINGLELINE)
	img_bg:addChild(self.edit_box_)
	
	img_input_bg:removeFromParent()

	self.txt_tip_ = img_bg:getChildByName("txt_input_tip")
	self.txt_tip_:ignoreContentAdaptWithSize(false)
	self.txt_tip_:setVisible(false)
end

function InputPopup:setOKTouchCallback(callback)
	self.ok_callback_ = callback
end

function InputPopup:setTitle(txt_title)
	if txt_title then
		self.txt_title_:setString(txt_title)
	end
end

function InputPopup:getTitle()
	return self.txt_title_:getString()
end

function InputPopup:setInputContext(txt_context)
	if txt_context then
		self.edit_box_:setText(txt_context)
	end
end

function InputPopup:getInputContext()
	return self.edit_box_:getText()
end

function InputPopup:setTip(txt_tip)
	if txt_tip then
		self.txt_tip_:setVisible(true)
		self.txt_tip_:setString(txt_tip)
	end
end

function InputPopup:getEditbox()
	return self.edit_box_
end

function InputPopup:onImgOKTouch(sender)
    print("[InputPopup:onImgOKTouch]")
	gamer.widget_helper_.playDefaultTouchActionForImage(sender)

	if self.ok_callback_ then
		self.ok_callback_()
	end
end

function InputPopup:onImgCloseTouch(sender)
    print("[InputPopup:onImgCloseTouch]")
	self:removeSelf()
end

function InputPopup:onEnter()
    print("[InputPopup:onEnter]")
end

function InputPopup:onExit()
    print("[InputPopup:onExit]")
end

return InputPopup