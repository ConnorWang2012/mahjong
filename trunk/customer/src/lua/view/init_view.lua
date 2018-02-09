﻿--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   init_view.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: init view module.
@ others:
@ history:
1.date:
author:
modification:
--]]

gamer.widget_helper_ = require "view.common.widget_helper.lua"

gamer.PopupConstants = require "view.constant.popup_constants.lua"
gamer.SceneConstants = require "view.constant.scene_constants.lua"

gamer.PopupIDs		= gamer.PopupConstants.PopupIDs
gamer.SceneIDs		= gamer.SceneConstants.SceneIDs
gamer.LocalZOrders	= gamer.SceneConstants.LocalZOrders