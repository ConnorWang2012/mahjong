--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   layer_manager.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: layer manager.
@ others:
@ history:
1.date:
author:
modification:
--]]

local LayerManager = {}

LayerManager.layer_ids = {}

function LayerManager.createLayer(layer_id)
	if not layer_id then
		print("[LayerManager.createLayer] create layer failed, layer id is nil")
		return
	end

	local layer_cfg = gamer.LayerConstants.LayersCfg[layer_id]
	if not layer_cfg or not layer_cfg.layer_file then
		print("[LayerManager.createLayer] create layer failed, layer cfg error")
		return
	end
	
	local layer = require(layer_cfg.layer_file):create(layer_cfg.view_file)
--	if layer_cfg.view_file then
--		layer:addViewNodeFromLua(layer_cfg.view_file)
--	end

	return layer
end

function LayerManager.addLayer(layer_id)
	if not layer_id then
		print("[LayerManager.addLayer] add layer failed, layer id is nil")
		return
	end

	if LayerManager.layer_ids[layer_id] then
		print("[LayerManager.addLayer] add layer failed, layer has added")
		return
	end
	
	local layer = LayerManager.createLayer(layer_id)
	local scene = gamer.SceneManager:getRunningScene()
	if scene then
		scene:addChild(layer) -- TODO : deal with z order
		LayerManager.layer_ids[layer_id] = layer_id
	else
		print("[LayerManager.addLayer] add layer failed, cur scene is nil")
	end
end

function LayerManager.removeLayer(layer_id)
	if LayerManager.layer_ids[layer_id] then
        LayerManager.layer_ids[layer_id]:removeFromParent()
        LayerManager.layer_ids[layer_id] = nil
    end
end

return LayerManager