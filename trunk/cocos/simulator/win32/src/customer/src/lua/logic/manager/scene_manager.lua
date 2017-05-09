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

function SceneManager.runScene(scene_id)
    if not scene_id then
        return
    end

    -- check current scene id
    if SceneManager.running_scene and scene_id == SceneManager.running_scene:id() then
        print("[SceneManager.runScene] running scene all ready")
        return
    end

    local scene, scene_cfg = SceneManager.createScene(scene_id)
    if not scene then
        print("[SceneManager.runScene] create scene failed")
        return
    end

    if scene_cfg.view_file then
		scene:addViewNode(scene_cfg.view_file)
	end

    local director = cc.Director:getInstance()
    if director:getRunningScene() then
        director:replaceScene(scene)
    else
        local s = cc.Scene:create()
        s:addChild(scene)
        director:runWithScene(s)
    end

	SceneManager.running_scene = scene
end

function SceneManager.createScene(scene_id)
	local scene_cfg = gamer.SceneConstants.ScenesCfg[scene_id]
    if not scene_cfg or not scene_cfg.scene_file then
        print("[SceneManager.createScene] create scene failed, scene cfg error")
        return
    end

    return require(scene_cfg.scene_file):create(), scene_cfg
end

function SceneManager.getRunningScene()
	return SceneManager.running_scene
end

return SceneManager