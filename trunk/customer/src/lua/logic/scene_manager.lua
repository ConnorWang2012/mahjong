--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   scene_manager.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: scene manager.
@ others:
@ history:
1.date:
author:
modification:
--]]

local SceneManager = {}
local Director = cc.Director:getInstance()

function SceneManager.runScene(scene_id)
	local scene = cc.Scene:create()
    if Director:getRunningScene() then
        Director:replaceScene(scene)
    else
        Director:runWithScene(scene)
    end
	SceneManager.running_scene = scene
end

function SceneManager.createScene(scene_id)
	
end

function SceneManager.getRunningScene()
	return SceneManager.running_scene
end

gamer.SceneManager = SceneManager
return SceneManager