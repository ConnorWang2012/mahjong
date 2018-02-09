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

local M = {}

function M.runScene(scene_id)
    if not scene_id then
        print("[SceneManager.runScene] scene id nil")
        return
    end

    -- check current scene id
    if M.running_scene and scene_id == M.running_scene:id() then
        print("[SceneManager.runScene] running scene all ready")
        return
    end

    local scene, scene_cfg = M.createScene(scene_id)
    if not scene then
        print("[SceneManager.runScene] create scene failed")
        return
    end

	-- set popup root node to nil
	gamer.popup_mgr_.popup_root_ = nil

    local director = cc.Director:getInstance()
    local s = cc.Scene:create()
    s:addChild(scene)
    if director:getRunningScene() then
        director:replaceScene(s)
    else
        director:runWithScene(s)
    end

	M.running_scene = scene
end

function M.createScene(scene_id)
	local scene_cfg = gamer.SceneConstants.ScenesCfg[scene_id]
    if not scene_cfg or not scene_cfg.scene_file then
        print("[SceneManager.createScene] create scene failed, scene cfg error")
        return
    end

    return require(scene_cfg.scene_file):create(scene_cfg.view_file)
end

function M.getRunningScene()
	return cc.Director:getInstance():getRunningScene() or M.running_scene
end

return M