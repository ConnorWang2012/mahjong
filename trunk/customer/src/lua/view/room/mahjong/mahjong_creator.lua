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

local MahjongCreator = {}
local MJConst	     = require "view.constant.mahjong_constants.lua"

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

MahjongCreator.opposite_discard_zorder_ = 1000
MahjongCreator.right_discard_zorder_    = 1100

function MahjongCreator.create(direction, type, value)
	if nil == direction or nil == type then
		local str = string.format("direction : %s, type : %s", tostring(direction), tostring(type))
		print("[MahjongCreator.create] param error : ", str)
		return nil
	end

	local mj_node = nil
	if direction == MJConst.Directions.SELF then -- self
		mj_node = MahjongCreator.initPlayerSelfCardLayout(value, type)
	elseif direction == MJConst.Directions.LEFT then
		mj_node = MahjongCreator.initLeftPlayerCardLayout(value, type)
	elseif direction == MJConst.Directions.OPPOSITE then
		mj_node = MahjongCreator.initOppositePlayerCardLayout(value, type)
	elseif direction == MJConst.Directions.RIGHT then 
		mj_node = MahjongCreator.initRightPlayerCardLayout(value, type)
	end

	if mj_node and value then
		mj_node:setTag(value)
	end

	return mj_node
end

function MahjongCreator.initPlayerSelfCardLayout(value, type)
	local mj_layout = nil
	if type == MJConst.Types.INVISIBLE then
		local png = MahjongCreator.getCardPng(value)		
		if png then
			mj_layout = MyInvisibleMJLayout:create().root
			local img_fg = mj_layout:getChildByName("img_fg")
			img_fg:loadTexture(png, ccui.TextureResType.plistType)
		end

	elseif type == MJConst.Types.INVISIBLE_AN_GANG_1 then
		mj_layout = MyInvisibleMJLayout1:create().root

	elseif type == MJConst.Types.INVISIBLE_AN_GANG_2 then
		mj_layout = MyInvisibleMJLayout2:create().root

	elseif type == MJConst.Types.VISIBLE then
		local png = MahjongCreator.getCardPng(value)		
		if png then
			mj_layout = MyVisibleMJLayout1:create().root
			local img_fg = mj_layout:getChildByName("img_fg")
			img_fg:loadTexture(png, ccui.TextureResType.plistType)
		end

	elseif type == MJConst.Types.VISIBLE_MING_GANG then
		local png = MahjongCreator.getCardPng(value)
		if png then
			mj_layout = MyVisibleMJLayout3:create().root
			local img_fg = mj_layout:getChildByName("img_left_fg") 
			local img_fg2 = mj_layout:getChildByName("img_top_fg")
			local img_fg3 = mj_layout:getChildByName("img_right_fg")
			img_fg:loadTexture(png, ccui.TextureResType.plistType)
			img_fg2:loadTexture(png, ccui.TextureResType.plistType)
			img_fg3:loadTexture(png, ccui.TextureResType.plistType)
		end

	elseif type == MJConst.Types.VISIBLE_DISCARD then
		local png = MahjongCreator.getCardPng(value)		
		if png then
			mj_layout = MyDiscardMJLayout:create().root
			local img_fg = mj_layout:getChildByName("img_fg")
			img_fg:loadTexture(png, ccui.TextureResType.plistType)
		end

	end

	if nil == mj_layout then
		print("[MahjongCreator.initPlayerSelfCardLayout] nil == mj_layout")
	end

	return mj_layout
end

function MahjongCreator.initLeftPlayerCardLayout(value, type)
	local mj_layout = nil
	if type == MJConst.Types.INVISIBLE then
		mj_layout = LeftInvisibleMJLayout:create().root
	elseif type == MJConst.Types.INVISIBLE_AN_GANG_1 then
		mj_layout = LeftInvisibleMJLayout1:create().root
	elseif type == MJConst.Types.INVISIBLE_AN_GANG_2 then
		mj_layout = LeftInvisibleMJLayout2:create().root
	elseif type == MJConst.Types.VISIBLE then
		local png = MahjongCreator.getCardPng(value)
		if png then
			mj_layout = LeftVisibleMJLayout1:create().root
			local img_fg = mj_layout:getChildByName("img_fg") or mj_layout:getChildByName("img_top_fg")
			img_fg:loadTexture(png, ccui.TextureResType.plistType)
		end
	elseif type == MJConst.Types.VISIBLE_MING_GANG then
		local png = MahjongCreator.getCardPng(value)
		if png then
			mj_layout = LeftVisibleMJLayout3:create().root
			local img_fg1 = mj_layout:getChildByName("img_top_fg1") 
			local img_fg2 = mj_layout:getChildByName("img_top_fg2")
			local img_fg3 = mj_layout:getChildByName("img_top_fg3")
			img_fg1:loadTexture(png, ccui.TextureResType.plistType)
			img_fg2:loadTexture(png, ccui.TextureResType.plistType)
			img_fg3:loadTexture(png, ccui.TextureResType.plistType)
		end

	elseif type == MJConst.Types.VISIBLE_DISCARD then
		local png = MahjongCreator.getCardPng(value)		
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

function MahjongCreator.initOppositePlayerCardLayout(value, type)
	local mj_layout = nil
	local need_show_card_value = false
	if type == MJConst.Types.INVISIBLE then
		mj_layout = OppositeInvisibleMJLayout:create().root
	elseif type == MJConst.Types.INVISIBLE_AN_GANG_1 then
		mj_layout = OppositeInvisibleMJLayout1:create().root
	elseif type == MJConst.Types.INVISIBLE_AN_GANG_2 then
		mj_layout = OppositeInvisibleMJLayout2:create().root
	elseif type == MJConst.Types.VISIBLE then	
		local png = MahjongCreator.getCardPng(value)
		if png then
			mj_layout = OppositeVisibleMJLayout1:create().root
			local img_fg = mj_layout:getChildByName("img_fg") or mj_layout:getChildByName("img_top_fg")
			img_fg:loadTexture(png, ccui.TextureResType.plistType)
		end
	elseif type == MJConst.Types.VISIBLE_MING_GANG then
		local png = MahjongCreator.getCardPng(value)
		if png then
			mj_layout = OppositeVisibleMJLayout3:create().root
			local img_fg1 = mj_layout:getChildByName("img_top_fg1") 
			local img_fg2 = mj_layout:getChildByName("img_top_fg2")
			local img_fg3 = mj_layout:getChildByName("img_top_fg3")
			img_fg1:loadTexture(png, ccui.TextureResType.plistType)
			img_fg2:loadTexture(png, ccui.TextureResType.plistType)
			img_fg3:loadTexture(png, ccui.TextureResType.plistType)
		end

	elseif type == MJConst.Types.VISIBLE_DISCARD then
		local png = MahjongCreator.getCardPng(value)		
		if png then
			mj_layout = OppositeVisibleMJLayout1:create().root
			local img_fg = mj_layout:getChildByName("img_fg")
			img_fg:loadTexture(png, ccui.TextureResType.plistType)

			-- for opposite player discard(visble mahjong), modify it's local z order as lower
			mj_layout:setLocalZOrder(MahjongCreator.opposite_discard_zorder_)
			MahjongCreator.opposite_discard_zorder_ = MahjongCreator.opposite_discard_zorder_ - 1
		end

	end

	if nil == mj_layout then
		print("[MahjongCreator.initOppositePlayerCardLayout] nil == mj_layout")
		return
	end

	return mj_layout
end

function MahjongCreator.initRightPlayerCardLayout(value, type)
	local mj_layout = nil
	if type == MJConst.Types.INVISIBLE then
		mj_layout = RightInvisibleMJLayout:create().root
	elseif type == MJConst.Types.INVISIBLE_AN_GANG_1 then
		mj_layout = RightInvisibleMJLayout1:create().root
	elseif type == MJConst.Types.INVISIBLE_AN_GANG_2 then
		mj_layout = RightInvisibleMJLayout2:create().root
	elseif type == MJConst.Types.VISIBLE then
		local png = MahjongCreator.getCardPng(value)
		if png then
			mj_layout = RightVisibleMJLayout1:create().root
			local img_fg = mj_layout:getChildByName("img_fg") or mj_layout:getChildByName("img_top_fg")
			img_fg:loadTexture(png, ccui.TextureResType.plistType)
		end
	elseif type == MJConst.Types.VISIBLE_MING_GANG then
		local png = MahjongCreator.getCardPng(value)
		if png then
			mj_layout = RightVisibleMJLayout3:create().root
			local img_fg1 = mj_layout:getChildByName("img_top_fg1") 
			local img_fg2 = mj_layout:getChildByName("img_top_fg2")
			local img_fg3 = mj_layout:getChildByName("img_top_fg3")
			img_fg1:loadTexture(png, ccui.TextureResType.plistType)
			img_fg2:loadTexture(png, ccui.TextureResType.plistType)
			img_fg3:loadTexture(png, ccui.TextureResType.plistType)
		end

	elseif type == MJConst.Types.VISIBLE_DISCARD then
		local png = MahjongCreator.getCardPng(value)		
		if png then
			mj_layout = RightDiscardMJLayout:create().root
			local img_fg = mj_layout:getChildByName("img_fg")
			img_fg:loadTexture(png, ccui.TextureResType.plistType)

			-- for right player discard(visble mahjong), modify it's local z order as lower
			mj_layout:setLocalZOrder(MahjongCreator.right_discard_zorder_)
			MahjongCreator.right_discard_zorder_ = MahjongCreator.right_discard_zorder_ - 1
		end

	end

	if nil == mj_layout then
		print("[MahjongCreator.initRightPlayerCardLayout] nil == mj_layout")
		return
	end

	return mj_layout
end

function MahjongCreator.getCardPng(value)
    --[[
	local i, f = math.modf(value / 10)
	if MJConst.CardPngs[i] then
		return MJConst.CardPngs[i][value % 10]
	end
	]]
	if value <= 8 then
		return MJConst.CardPngs[1][value + 1]
	elseif value <= 17 then
		return MJConst.CardPngs[2][value - 8]
	elseif value <= 26 then
		return MJConst.CardPngs[3][value - 17]
	elseif value <= 33 then
		return MJConst.CardPngs[4][value - 26]
	elseif value <= 41 then
		return MJConst.CardPngs[5][value - 33]
	end
	return nil
end

return MahjongCreator