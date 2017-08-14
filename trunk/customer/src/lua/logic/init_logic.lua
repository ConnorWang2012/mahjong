--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   init_logic.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: init logic module.
@ others:
@ history:
1.date:
author:
modification:
--]]

require "logic.constant.msg_id.lua"
require "logic.constant.msg_type.lua"
require "logic.constant.msg_code.lua"

gamer.g_scene_msg_ = require "logic.manager.scene_manager.lua"
gamer.g_popup_mgr_ = require "logic.manager.popup_manager.lua"
gamer.g_event_mgr_ = gamer.EventManager:getInstance()
gamer.g_cmd_mgr_   = gamer.CommandManager:getInstance()
gamer.g_data_mgr_  = gamer.DataManager:getInstance()
gamer.g_msg_mgr_   = gamer.MsgManager:getInstance()