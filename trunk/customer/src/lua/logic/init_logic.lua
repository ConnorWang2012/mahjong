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

gamer.scene_msg_ = require "logic.manager.scene_manager.lua"
gamer.popup_mgr_ = require "logic.manager.popup_manager.lua"
gamer.event_mgr_ = gamer.EventManager:getInstance()
gamer.cmd_mgr_   = gamer.CommandManager:getInstance()
gamer.data_mgr_  = gamer.DataManager:getInstance()
gamer.msg_mgr_   = gamer.MsgManager:getInstance()