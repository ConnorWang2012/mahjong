--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   mahjong_creator.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-06-23
@ description: create mahjong node.
@ others:
@ history:
1.date:
author:
modification:
--]]

local M = {}
local MahjongConst	     = require "view.constant.mahjong_constants.lua"

local MyInvisibleMJLayout  = require "view.layouts.ui.room.mahjong.my_invisible_mj_node_layout.lua"
local MyInvisibleMJLayout1 = require "view.layouts.ui.room.mahjong.my_invisible_1_mj_node_layout.lua"
local MyInvisibleMJLayout2 = require "view.layouts.ui.room.mahjong.my_invisible_2_mj_node_layout.lua"
local MyInvisibleMJLayout3 = require "view.layouts.ui.room.mahjong.my_invisible_3_mj_node_layout.lua"
local MyVisibleMJLayout1   = require "view.layouts.ui.room.mahjong.my_visible_1_mj_node_layout.lua"
local MyVisibleMJLayout2   = require "view.layouts.ui.room.mahjong.my_visible_2_mj_node_layout.lua"
local MyVisibleMJLayout3   = require "view.layouts.ui.room.mahjong.my_visible_3_mj_node_layout.lua"
local MyDiscardMJLayout    = require "view.layouts.ui.room.mahjong.my_discard_mj_node_layout.lua"

local LeftInvisibleMJLayout  = require "view.layouts.ui.room.mahjong.left_invisible_mj_node_layout.lua"
local LeftInvisibleMJLayout1 = require "view.layouts.ui.room.mahjong.left_invisible_1_mj_node_layout.lua"
local LeftInvisibleMJLayout2 = require "view.layouts.ui.room.mahjong.left_invisible_2_mj_node_layout.lua"
local LeftInvisibleMJLayout3 = require "view.layouts.ui.room.mahjong.left_invisible_3_mj_node_layout.lua"
local LeftVisibleMJLayout1   = require "view.layouts.ui.room.mahjong.left_visible_1_mj_node_layout.lua"
local LeftVisibleMJLayout2   = require "view.layouts.ui.room.mahjong.left_visible_2_mj_node_layout.lua"
local LeftVisibleMJLayout3   = require "view.layouts.ui.room.mahjong.left_visible_3_mj_node_layout.lua"
local LeftDiscardMJLayout    = require "view.layouts.ui.room.mahjong.left_discard_mj_node_layout.lua"

local OppositeInvisibleMJLayout  = require "view.layouts.ui.room.mahjong.opposite_invisible_mj_node_layout.lua"
local OppositeInvisibleMJLayout1 = require "view.layouts.ui.room.mahjong.opposite_invisible_1_mj_node_layout.lua"
local OppositeInvisibleMJLayout2 = require "view.layouts.ui.room.mahjong.opposite_invisible_2_mj_node_layout.lua"
local OppositeInvisibleMJLayout3 = require "view.layouts.ui.room.mahjong.opposite_invisible_3_mj_node_layout.lua"
local OppositeVisibleMJLayout1   = require "view.layouts.ui.room.mahjong.opposite_visible_1_mj_node_layout.lua"
local OppositeVisibleMJLayout2   = require "view.layouts.ui.room.mahjong.opposite_visible_2_mj_node_layout.lua"
local OppositeVisibleMJLayout3   = require "view.layouts.ui.room.mahjong.opposite_visible_3_mj_node_layout.lua"

local RightInvisibleMJLayout  = require "view.layouts.ui.room.mahjong.right_invisible_mj_node_layout.lua"
local RightInvisibleMJLayout1 = require "view.layouts.ui.room.mahjong.right_invisible_1_mj_node_layout.lua"
local RightInvisibleMJLayout2 = require "view.layouts.ui.room.mahjong.right_invisible_2_mj_node_layout.lua"
local RightInvisibleMJLayout3 = require "view.layouts.ui.room.mahjong.right_invisible_3_mj_node_layout.lua"
local RightVisibleMJLayout1   = require "view.layouts.ui.room.mahjong.right_visible_1_mj_node_layout.lua"
local RightVisibleMJLayout2   = require "view.layouts.ui.room.mahjong.right_visible_2_mj_node_layout.lua"
local RightVisibleMJLayout3   = require "view.layouts.ui.room.mahjong.right_visible_3_mj_node_layout.lua"
local RightDiscardMJLayout    = require "view.layouts.ui.room.mahjong.right_discard_mj_node_layout.lua"

M.opposite_discard_zorder_ = 1000
M.right_discard_zorder_    = 1100

function M.create(direction, type, value)
	if nil == direction or nil == type then
		local str = string.format("direction : %s, type : %s", tostring(direction), tostring(type))
		print("[MahjongCreator.create] param error : ", str)
		return nil
	end

	local mj_node = nil
	if direction == MahjongConst.Directions.SELF then -- self
		mj_node = M.initPlayerSelfCardLayout(type, value)
	elseif direction == MahjongConst.Directions.LEFT then
		mj_node = M.initLeftPlayerCardLayout(type, value)
	elseif direction == MahjongConst.Directions.OPPOSITE then
		mj_node = M.initOppositePlayerCardLayout(type, value)
	elseif direction == MahjongConst.Directions.RIGHT then 
		mj_node = M.initRightPlayerCardLayout(type, value)
	end

	if mj_node and value then
		mj_node:setTag(value)
	end

	return mj_node
end

function M.initPlayerSelfCardLayout(type, value)
	local mj_layout = nil
	if type == MahjongConst.Types.INVISIBLE then
		local png = M.getCardPng(value)		
		if png then
			mj_layout = MyInvisibleMJLayout:create().root
			mj_layout:setLocalZOrder(MahjongConst.ZOrders.INVISIBLE_HAND_CARD_PLAYER_SELF)
			local img_fg = mj_layout:getChildByName("img_fg")
			img_fg:loadTexture(png, ccui.TextureResType.plistType)
		end

	elseif type == MahjongConst.Types.INVISIBLE_1 then
		mj_layout = MyInvisibleMJLayout1:create().root

	elseif type == MahjongConst.Types.INVISIBLE_2 then
		mj_layout = MyInvisibleMJLayout2:create().root

	elseif type == MahjongConst.Types.INVISIBLE_3 then
		mj_layout = MyInvisibleMJLayout3:create().root
		mj_layout:setLocalZOrder(MahjongConst.ZOrders.INVISIBLE_AN_GANG_CARD_PLAYER_SELF)

	elseif type == MahjongConst.Types.VISIBLE then
		local png = M.getCardPng(value)		
		if png then
			mj_layout = MyVisibleMJLayout1:create().root
			mj_layout:setLocalZOrder(MahjongConst.ZOrders.VISIBLE_HAND_CARD_PLAYER_SELF)
			local img_fg = mj_layout:getChildByName("img_fg")
			img_fg:loadTexture(png, ccui.TextureResType.plistType)
		end

	elseif type == MahjongConst.Types.VISIBLE_MING_GANG then
		local png = M.getCardPng(value)
		if png then
			mj_layout = MyVisibleMJLayout3:create().root
			mj_layout:setLocalZOrder(MahjongConst.ZOrders.VISIBLE_HAND_CARD_PLAYER_SELF)
			local img_fg = mj_layout:getChildByName("img_left_fg") 
			local img_fg2 = mj_layout:getChildByName("img_top_fg")
			local img_fg3 = mj_layout:getChildByName("img_right_fg")
			img_fg:loadTexture(png, ccui.TextureResType.plistType)
			img_fg2:loadTexture(png, ccui.TextureResType.plistType)
			img_fg3:loadTexture(png, ccui.TextureResType.plistType)
		end

	elseif type == MahjongConst.Types.VISIBLE_DISCARD then
		local png = M.getCardPng(value)		
		if png then
			mj_layout = MyDiscardMJLayout:create().root
			local img_fg = mj_layout:getChildByName("img_fg")
			img_fg:loadTexture(png, ccui.TextureResType.plistType)
		end

	end

	if nil == mj_layout then
		print("[MahjongCreator.initPlayerSelfCardLayout] nil == mj_layout")
		print("[MahjongCreator.initPlayerSelfCardLayout] nil == mj_layout, type : ", type)
		print("[MahjongCreator.initPlayerSelfCardLayout] nil == mj_layout, value : ", value)
	end

	return mj_layout
end

function M.initLeftPlayerCardLayout(type, value)
	local mj_layout = nil
	if type == MahjongConst.Types.INVISIBLE then
		mj_layout = LeftInvisibleMJLayout:create().root
	elseif type == MahjongConst.Types.INVISIBLE_1 then
		mj_layout = LeftInvisibleMJLayout1:create().root
	elseif type == MahjongConst.Types.INVISIBLE_2 then
		mj_layout = LeftInvisibleMJLayout2:create().root
	elseif type == MahjongConst.Types.INVISIBLE_3 then
		mj_layout = LeftInvisibleMJLayout3:create().root
	elseif type == MahjongConst.Types.VISIBLE then
		local png = M.getCardPng(value)
		if png then
			mj_layout = LeftVisibleMJLayout1:create().root
			local img_fg = mj_layout:getChildByName("img_fg") or mj_layout:getChildByName("img_top_fg")
			img_fg:loadTexture(png, ccui.TextureResType.plistType)
		end
	elseif type == MahjongConst.Types.VISIBLE_MING_GANG then
		local png = M.getCardPng(value)
		if png then
			mj_layout = LeftVisibleMJLayout3:create().root
			local img_fg1 = mj_layout:getChildByName("img_top_fg1") 
			local img_fg2 = mj_layout:getChildByName("img_top_fg2")
			local img_fg3 = mj_layout:getChildByName("img_top_fg3")
			img_fg1:loadTexture(png, ccui.TextureResType.plistType)
			img_fg2:loadTexture(png, ccui.TextureResType.plistType)
			img_fg3:loadTexture(png, ccui.TextureResType.plistType)
		end

	elseif type == MahjongConst.Types.VISIBLE_DISCARD then
		local png = M.getCardPng(value)		
		if png then
			mj_layout = LeftDiscardMJLayout:create().root
			local img_fg = mj_layout:getChildByName("img_fg")
			img_fg:loadTexture(png, ccui.TextureResType.plistType)
		end

	end

	if nil == mj_layout then
		print("[MahjongCreator.initLeftPlayerCardLayout] nil == mj_layout")
		return
	end

	return mj_layout
end

function M.initOppositePlayerCardLayout(type, value)
	local mj_layout = nil
	local need_show_card_value = false
	if type == MahjongConst.Types.INVISIBLE then
		mj_layout = OppositeInvisibleMJLayout:create().root
	elseif type == MahjongConst.Types.INVISIBLE_1 then
		mj_layout = OppositeInvisibleMJLayout1:create().root
	elseif type == MahjongConst.Types.INVISIBLE_2 then
		mj_layout = OppositeInvisibleMJLayout2:create().root
	elseif type == MahjongConst.Types.INVISIBLE_3 then
		mj_layout = OppositeInvisibleMJLayout3:create().root
	elseif type == MahjongConst.Types.VISIBLE then	
		local png = M.getCardPng(value)
		if png then
			mj_layout = OppositeVisibleMJLayout1:create().root
			local img_fg = mj_layout:getChildByName("img_fg") or mj_layout:getChildByName("img_top_fg")
			img_fg:loadTexture(png, ccui.TextureResType.plistType)
		end
	elseif type == MahjongConst.Types.VISIBLE_MING_GANG then
		local png = M.getCardPng(value)
		if png then
			mj_layout = OppositeVisibleMJLayout3:create().root
			local img_fg1 = mj_layout:getChildByName("img_top_fg1") 
			local img_fg2 = mj_layout:getChildByName("img_top_fg2")
			local img_fg3 = mj_layout:getChildByName("img_top_fg3")
			img_fg1:loadTexture(png, ccui.TextureResType.plistType)
			img_fg2:loadTexture(png, ccui.TextureResType.plistType)
			img_fg3:loadTexture(png, ccui.TextureResType.plistType)
		end

	elseif type == MahjongConst.Types.VISIBLE_DISCARD then
		local png = M.getCardPng(value)		
		if png then
			mj_layout = OppositeVisibleMJLayout1:create().root
			local img_fg = mj_layout:getChildByName("img_fg")
			img_fg:loadTexture(png, ccui.TextureResType.plistType)

			-- for opposite player discard(visble mahjong), modify it's local z order as lower
			mj_layout:setLocalZOrder(M.opposite_discard_zorder_)
			M.opposite_discard_zorder_ = M.opposite_discard_zorder_ - 1
		end

	end

	if nil == mj_layout then
		print("[MahjongCreator.initOppositePlayerCardLayout] nil == mj_layout")
		return
	end

	return mj_layout
end

function M.initRightPlayerCardLayout(type, value)
	local mj_layout = nil
	if type == MahjongConst.Types.INVISIBLE then
		mj_layout = RightInvisibleMJLayout:create().root
	elseif type == MahjongConst.Types.INVISIBLE_1 then
		mj_layout = RightInvisibleMJLayout1:create().root
	elseif type == MahjongConst.Types.INVISIBLE_2 then
		mj_layout = RightInvisibleMJLayout2:create().root
	elseif type == MahjongConst.Types.INVISIBLE_3 then
		mj_layout = RightInvisibleMJLayout3:create().root
	elseif type == MahjongConst.Types.VISIBLE then
		local png = M.getCardPng(value)
		if png then
			mj_layout = RightVisibleMJLayout1:create().root
			local img_fg = mj_layout:getChildByName("img_fg") or mj_layout:getChildByName("img_top_fg")
			img_fg:loadTexture(png, ccui.TextureResType.plistType)
		end
	elseif type == MahjongConst.Types.VISIBLE_MING_GANG then
		local png = M.getCardPng(value)
		if png then
			mj_layout = RightVisibleMJLayout3:create().root
			local img_fg1 = mj_layout:getChildByName("img_top_fg1") 
			local img_fg2 = mj_layout:getChildByName("img_top_fg2")
			local img_fg3 = mj_layout:getChildByName("img_top_fg3")
			img_fg1:loadTexture(png, ccui.TextureResType.plistType)
			img_fg2:loadTexture(png, ccui.TextureResType.plistType)
			img_fg3:loadTexture(png, ccui.TextureResType.plistType)
		end

	elseif type == MahjongConst.Types.VISIBLE_DISCARD then
		local png = M.getCardPng(value)		
		if png then
			mj_layout = RightDiscardMJLayout:create().root
			local img_fg = mj_layout:getChildByName("img_fg")
			img_fg:loadTexture(png, ccui.TextureResType.plistType)

			-- for right player discard(visble mahjong), modify it's local z order as lower
			mj_layout:setLocalZOrder(M.right_discard_zorder_)
			M.right_discard_zorder_ = M.right_discard_zorder_ - 1
		end

	end

	if nil == mj_layout then
		print("[MahjongCreator.initRightPlayerCardLayout] nil == mj_layout")
		return
	end

	return mj_layout
end

function M.getCardPng(value)
	if value <= 8 then
		return MahjongConst.CardPngs[1][value + 1]
	elseif value <= 17 then
		return MahjongConst.CardPngs[2][value - 8]
	elseif value <= 26 then
		return MahjongConst.CardPngs[3][value - 17]
	elseif value <= 33 then
		return MahjongConst.CardPngs[4][value - 26]
	elseif value <= 41 then
		return MahjongConst.CardPngs[5][value - 33]
	end
	return nil
end

return M