--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   player_head_creator.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-06-23
@ description: use clipping node to create player head.
@ others:
@ history:
1.date:
author:
modification:
--]]

local PlayerConst = require "logic.constant.player_constants.lua"
local M = {}
M.has_loaded_head_images_ = false

if not M.has_loaded_head_images_ then
	cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/head.plist")
	M.has_loaded_head_images_ = true
end

function M.createHeadPortrait(portrait_type, portrait_id, buffer)
	print("[PlayerHeadCreator:createHeadPortrait]")
	if portrait_type == PlayerConst.PortraitTypes.LOCAL then
		return M.createLocalHeadPortrait(portrait_id)
	elseif portrait_type == PlayerConst.PortraitTypes.PERSONNAL then
		return M.initPersonalHeadPortrait(buffer)
	else
		print("[PlayerHeadCreator:createHeadPortrait] portrait_type invalid")
	end
	return nil
end

function M.createPlayerSelfHeadPortrait()
	print("[PlayerHeadCreator:createPlayerSelfHeadPortrait]")
	local player_proto = gamer.data_mgr_:my_login_msg_protocol():player()
	return M.createHeadPortrait(player_proto:head_portrait_type(), player_proto:head_portrait_id(), 
		player_proto:head_portrait())
end

function M.createWithDefaultStencil(img_chipping, img_type)
	return M.create("assets/common/head_stencil.png", img_chipping, nil, img_type)
end

function M.create(img_stencil, img_chipping, img_type1, img_type2)
	local res_type1 = img_type1 or ccui.TextureResType.localType
	local res_type2 = img_type2 or ccui.TextureResType.plistType
	local node_stencil = cc.Node:create()
	local image_stencil = ccui.ImageView:create()
	image_stencil:loadTexture(img_stencil, res_type1)
	node_stencil:addChild(image_stencil)

	local clipping_node = cc.ClippingNode:create(node_stencil)
	local image_clipping = ccui.ImageView:create()
	image_clipping:loadTexture(img_chipping, res_type2)
	image_clipping:setName("image_clipping")
	clipping_node:addChild(image_clipping)
	--clipping_node:setInverted(true)
	clipping_node:setName("node_clipping")
	clipping_node:setAlphaThreshold(0.5)

	return clipping_node
end

------------------------------------ private ------------------------------------

function M.createLocalHeadPortrait(portrait_id)
	print("[PlayerHeadCreator:createLocalHeadPortrait]")
	if not portrait_id or portrait_id > PlayerConst.MAX_HEAD_PORTRAIT_NUM then
		print("[PlayerHeadCreator:createLocalHeadPortrait] portrait_id invalid, return")
		return nil
	end

	cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/head.plist")

	return M.createWithDefaultStencil("head_" .. portrait_id .. ".png", ccui.TextureResType.plistType)
end

function M.createPersonalHeadPortrait(buffer)
	print("[PlayerHeadCreator:createPersonalHeadPortrait]")
	if not buffer then
		print("[PlayerHeadCreator:createPersonalHeadPortrait] buffer is nil, return")
		return nil
	end
end

--------------------------------- end private -----------------------------------

return M