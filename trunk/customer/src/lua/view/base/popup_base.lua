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

	-- swallow touch event for background
	self.touch_listener_ = cc.EventListenerTouchOneByOne:create()
    self.touch_listener_:setSwallowTouches(true)
    self.touch_listener_:registerScriptHandler(handler(self, self.onTouchBegin), cc.Handler.EVENT_TOUCH_BEGAN)
    self.touch_listener_:registerScriptHandler(handler(self, self.onTouchEnd), cc.Handler.EVENT_TOUCH_ENDED)

    cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(self.touch_listener_, self)
end

function PopupBase:closeWhenTouchBackground(yes)
	if yes then
		self:addColorLayerBg()
		self.popup_base_bg_layer_:setTouchEnabled(true)
	else
		if self.popup_base_bg_layer_ then
			self.popup_base_bg_layer_:setTouchEnabled(false)
		end
	end
end

function PopupBase:setBackGroundColor(color)
	if self.popup_base_bg_layer_ then
		self.popup_base_bg_layer_:setBackGroundColor(color)
	end
end

function PopupBase:setBackGroundColorOpacity(opacity)
	if self.popup_base_bg_layer_ then
		self.popup_base_bg_layer_:setBackGroundColorOpacity(opacity)
	end
end

------------------------------------ private ------------------------------------

function PopupBase:addColorLayerBg()
	if not self.popup_base_bg_layer_ then
		self.popup_base_bg_layer_ = ccui.Layout:create()
		if self.root_node_ then
			self.root_node_:addChild(self.popup_base_bg_layer_)
			local img_bg = self.root_node_:getChildByName("img_bg")
			if img_bg then
				img_bg:setTouchEnabled(true)
			end
		else
			self:addChild(self.popup_base_bg_layer_)
		end
		self.popup_base_bg_layer_:setBackGroundColorType(1)
		self.popup_base_bg_layer_:setBackGroundColorOpacity(120)
		self.popup_base_bg_layer_:setBackGroundColor(cc.c3b(15, 15, 15))
		self.popup_base_bg_layer_:setContentSize(display.width, display.height)
		self.popup_base_bg_layer_:setAnchorPoint(0.5, 0.5)
		self.popup_base_bg_layer_:setPosition(display.center)
		self.popup_base_bg_layer_:setLocalZOrder(-1)			
		self.popup_base_bg_layer_:setTouchEnabled(true)
		self.popup_base_bg_layer_:addClickEventListener(handler(self, self.onPopupBaseBackgroundTouch))
	end
end

function PopupBase:onEnter()
    print("[PopupBase:onEnter]")
	-- TODO : dispatch popup enter event to all listeners
end

function PopupBase:onExit()
    print("[PopupBase:onExit]")
	-- TODO : dispatch popup exit event to all listeners
	if self.touch_listener_ then
		cc.Director:getInstance():getEventDispatcher():removeEventListener(self.touch_listener_)
		self.touch_listener_ = nil
	end
end

function PopupBase:onTouchBegin(touch, event)
    print("[PopupBase:onTouchBegin]")
	if event:getEventCode() == cc.EventCode.BEGAN then
        return true
    end
end

function PopupBase:onTouchEnd(touch, event)
    print("[PopupBase:onTouchEnd]")
end

function PopupBase:onPopupBaseBackgroundTouch(sender)
	print("[PopupBase:onPopupBaseBackgroundTouch]")
	self:removeFromParent(true)
end

--------------------------------- end private -----------------------------------

return PopupBase