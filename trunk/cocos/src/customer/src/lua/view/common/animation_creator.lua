--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   animation_creator.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: animation creator.
@ others:
@ history:
1.date:
author:
modification:
--]]

local OperationAnim1   = require "view.animations.room.node_operation_anim1.lua"
local OperationAnim2   = require "view.animations.room.node_operation_anim2.lua"
local OperationAnim3   = require "view.animations.room.node_operation_anim3.lua"
local ChiAnimation     = require "view.animations.room.node_chi_anim.lua"
local PengAnimation    = require "view.animations.room.node_peng_anim.lua"
local GangAnimation    = require "view.animations.room.node_gang_anim.lua"
local BuhuaAnimation   = require "view.animations.room.node_buhua_anim.lua"
local TingAnimation    = require "view.animations.room.node_ting_anim.lua"
local HuAnimation      = require "view.animations.room.node_hu_anim.lua"
local ZimoAnimation    = require "view.animations.room.node_zimo_anim.lua"
local MahjongConst     = require "view.constant.mahjong_constants.lua"
local AnimationCreator = {}

function AnimationCreator.create(animation_id)
	local anim_node = nil

	if animation_id == MahjongConst.AnimationIDs.ANIMATION_OPERATION1 then     -- operation1
		anim_node = OperationAnim1:create()
	elseif animation_id == MahjongConst.AnimationIDs.ANIMATION_OPERATION2 then -- operation2
		anim_node = OperationAnim2:create()
	elseif animation_id == MahjongConst.AnimationIDs.ANIMATION_OPERATION3 then -- operation3
		anim_node = OperationAnim3:create()
	elseif animation_id == MahjongConst.AnimationIDs.ANIMATION_CHI then   -- chi
		anim_node = ChiAnimation:create()
	elseif animation_id == MahjongConst.AnimationIDs.ANIMATION_PENG then  -- peng
		anim_node = PengAnimation:create()
	elseif animation_id == MahjongConst.AnimationIDs.ANIMATION_GANG then  -- gang
		anim_node = GangAnimation:create()
	elseif animation_id == MahjongConst.AnimationIDs.ANIMATION_TING then  -- ting
		anim_node = TingAnimation:create()
	elseif animation_id == MahjongConst.AnimationIDs.ANIMATION_BUHUA then -- bu hua
		anim_node = BuhuaAnimation:create()
	elseif animation_id == MahjongConst.AnimationIDs.ANIMATION_HU then    -- hu
		anim_node = HuAnimation:create()
	elseif animation_id == MahjongConst.AnimationIDs.ANIMATION_ZIMO then  -- zimo
		anim_node = ZimoAnimation:create()
	end

	return anim_node
end

return AnimationCreator