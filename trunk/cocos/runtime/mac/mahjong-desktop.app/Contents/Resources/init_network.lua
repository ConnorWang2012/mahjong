--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   init_network.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: init network module.
@ others:
@ history:
1.date:
author:
modification:
--]]

gamer.msg_mgr_    = gamer.MsgManager:getInstance()
gamer.msg_helper_ = require "network.msg_helper.lua"