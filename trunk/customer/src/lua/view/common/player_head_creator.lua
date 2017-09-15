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

local PlayerHeadCreator = {}

-- @ param img_stencil, img_chipping : local type image
function PlayerHeadCreator.create(img_stencil, img_chipping)
	local node_stencil = cc.Node:create()
	local image_stencil = ccui.ImageView:create()
	image_stencil:loadTexture(img_stencil, ccui.TextureResType.localType)
	node_stencil:addChild(image_stencil)

	local clipping_node = cc.ClippingNode:create(node_stencil)
	local image_clipping = ccui.ImageView:create()
	image_clipping:loadTexture(img_chipping, ccui.TextureResType.localType)
	clipping_node:addChild(image_clipping)
	--clipping_node:setInverted(true)
	clipping_node:setAlphaThreshold(0.5)

	return clipping_node
end

return PlayerHeadCreator