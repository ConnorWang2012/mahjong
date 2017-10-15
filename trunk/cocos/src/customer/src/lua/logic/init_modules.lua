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

require "data.init_data.lua"
require "logic.init_logic.lua"
require "network.init_network.lua"
require "view.init_view.lua"

gamer.ResWidth = 1920
gamer.ResHeight = 1080

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