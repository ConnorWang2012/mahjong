--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   wx_api_manager.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: wechat api.
@ others:
@ history:
1.date:
author:
modification:
--]]

local WXApiManager = class("WXApiManager")

WXApiManager.WXScenes = 
{
	WX_SCENE_SESSION  = 0, -- liao tian jie mian
	WX_SCENE_TIMELINE = 1, -- peng you quan
	WX_SCENE_FAVORITE = 2  -- shou cang
}

function WXApiManager:ctor()
	local platform = cc.Application:getInstance():getTargetPlatform()
	if (platform == cc.PLATFORM_OS_ANDROID) then
		self.lua_bridge_ = require "cocos.cocos2d.luaj"
    elseif platform == cc.PLATFORM_OS_IPHONE or
    	   platform == cc.PLATFORM_OS_IPAD then
		self.lua_bridge_ = require "cocos.cocos2d.luaoc"
	end
end

function WXApiManager:shareImage(wx_scene, image_name)
	local platform = cc.Application:getInstance():getTargetPlatform()
	if (platform == cc.PLATFORM_OS_ANDROID) then
		-- TODO
    elseif platform == cc.PLATFORM_OS_IPHONE or
    	   platform == cc.PLATFORM_OS_IPAD then
		local class_name = "WXApiManager"
		local method_name = "shareImage"
		local args = { wx_scene = wx_scene, image_name = image_name }
		local ok, err_code = self.lua_bridge_.callStaticMethod(class_name, method_name, args)
		return ok, err_code
	end
end

return WXApiManager
