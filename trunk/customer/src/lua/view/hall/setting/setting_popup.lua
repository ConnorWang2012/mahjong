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

local SettingPopup = class("SettingPopup", require "view.base.popup_base")

function SettingPopup:ctor(view_file)
	print("[SettingPopup:ctor]")
    self.super.ctor(self, view_file)

	self:initView()
	self:closeWhenTouchBackground(true)
end

function SettingPopup:initView()
	local img_bg    = self.root_node_:getChildByName("img_bg")
	local img_close = img_bg:getChildByName("img_close")
	img_close:setTouchEnabled(true)
    img_close:addClickEventListener(handler(self, self.onImgCloseTouch))

	local img_backround_music = img_bg:getChildByName("img_bgm")
	local img_effect_music = img_bg:getChildByName("img_effect_music")
	img_backround_music:setTouchEnabled(true)
	img_effect_music:setTouchEnabled(true)
	img_backround_music:addClickEventListener(handler(self, self.onImgBackroundMusicTouch))
	img_effect_music:addClickEventListener(handler(self, self.onImgEffectMusicTouch))

	local opened = cc.UserDefault:getInstance():getIntegerForKey("hall_bgm_opened", 1)
	if 1 == opened then
		img_backround_music:setTag(1)
	else
		img_backround_music:setTag(0)
		img_backround_music:loadTexture("assets/hall/setting/i_bgm_off.png", ccui.TextureResType.localType)
	end

	opened = cc.UserDefault:getInstance():getIntegerForKey("effect_music_opened", 1)
	if 1 == opened then
		img_effect_music:setTag(1)
	else
		img_effect_music:setTag(0)
		img_effect_music:loadTexture("assets/hall/setting/i_effect_music_off.png", ccui.TextureResType.localType)
	end
end

function SettingPopup:onImgBackroundMusicTouch(sender)
    print("[SettingPopup:onImgBackroundMusicTouch]")
	if 1 == sender:getTag() then -- opened
		gamer.audio_mgr_.stopHallBGM()
		sender:loadTexture("assets/hall/setting/i_bgm_off.png", ccui.TextureResType.localType)
		sender:setTag(0)

		cc.UserDefault:getInstance():setIntegerForKey("hall_bgm_opened", 0)
	else -- closed
		gamer.audio_mgr_.playHallBGM()
		sender:loadTexture("assets/hall/setting/i_bgm_on.png", ccui.TextureResType.localType)
		sender:setTag(1)

		cc.UserDefault:getInstance():setIntegerForKey("hall_bgm_opened", 1)
	end
end

function SettingPopup:onImgEffectMusicTouch(sender)
    print("[SettingPopup:onImgEffectMusicTouch]")
	if 1 == sender:getTag() then -- enabled
		gamer.audio_mgr_.enableEffectMusic()
		sender:loadTexture("assets/hall/setting/i_effect_music_off.png", ccui.TextureResType.localType)
		sender:setTag(0)

		cc.UserDefault:getInstance():setIntegerForKey("effect_music_opened", 0)
	else -- disabled
		gamer.audio_mgr_.disableEffectMusic()
		sender:loadTexture("assets/hall/setting/i_effect_music_on.png", ccui.TextureResType.localType)
		sender:setTag(1)

		cc.UserDefault:getInstance():setIntegerForKey("effect_music_opened", 1)
	end
end

function SettingPopup:onImgCloseTouch(sender)
    print("[SettingPopup:onImgCloseTouch]")
	gamer.audio_mgr_.playCommonTouchEffectMusic()
	self:removeSelf()
end

function SettingPopup:onEnter()
    print("[SettingPopup:onEnter]")
end

function SettingPopup:onExit()
    print("[SettingPopup:onExit]")
end

return SettingPopup