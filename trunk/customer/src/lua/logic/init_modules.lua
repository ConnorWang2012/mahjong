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
--[[
if not cc.exports.gamer then
	cc.exports.gamer = {}
end
]]
require "data.init_data"
require "logic.init_logic"
require "network.init_network"
require "view.init_view"

gamer.ResWidth = 1920
gamer.ResHeight = 1080

gamer.LayerManager = require "logic.manager.layer_manager"
gamer.SceneManager = require "logic.manager.scene_manager"

gamer.initEngine = function()
    if CC_SHOW_FPS then
        cc.Director:getInstance():setDisplayStats(true)
    end
end

gamer.initDesignResolution = function()
    cc.Director:getInstance():setContentScaleFactor(gamer.ResHeight / CC_DESIGN_RESOLUTION.height) -- FIXED_HEIGHT
    --cc.Director:getInstance():setContentScaleFactor(gamer.ResWidth / CC_DESIGN_RESOLUTION.width) -- FIXED_WIDTH
end

gamer.initModules = function()
    gamer.initDesignResolution()
end