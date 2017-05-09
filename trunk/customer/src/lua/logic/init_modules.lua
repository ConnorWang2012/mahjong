--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   init_modules.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: init modules.
@ others:
@ history:
1.date:
author:
modification:
--]]

if not cc.exports.gamer then
	cc.exports.gamer = {}
end

require "data.init_data"
require "logic.init_logic"
require "network.init_network"
require "view.init_view"

gamer.LayerManager = require "logic.manager.layer_manager"
gamer.SceneManager = require "logic.manager.scene_manager"

gamer.initEngine = function()
    if CC_SHOW_FPS then
        cc.Director:getInstance():setDisplayStats(true)
    end
end

gamer.initModules = function()
    
end