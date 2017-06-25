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
local MyVisibleMJLayout1   = require "view.layouts.ui.room.mahjong.my_visible_1_mj_node_layout.lua"
local MyVisibleMJLayout2   = require "view.layouts.ui.room.mahjong.my_visible_2_mj_node_layout.lua"

local LeftInvisibleMJLayout  = require "view.layouts.ui.room.mahjong.left_invisible_mj_node_layout.lua"
local LeftInvisibleMJLayout1 = require "view.layouts.ui.room.mahjong.left_invisible_1_mj_node_layout.lua"
local LeftInvisibleMJLayout2 = require "view.layouts.ui.room.mahjong.left_invisible_2_mj_node_layout.lua"
local LeftVisibleMJLayout1   = require "view.layouts.ui.room.mahjong.left_visible_1_mj_node_layout.lua"
local LeftVisibleMJLayout2   = require "view.layouts.ui.room.mahjong.left_visible_2_mj_node_layout.lua"

local OppositeInvisibleMJLayout  = require "view.layouts.ui.room.mahjong.opposite_invisible_mj_node_layout.lua"
local OppositeInvisibleMJLayout1 = require "view.layouts.ui.room.mahjong.opposite_invisible_1_mj_node_layout.lua"
local OppositeInvisibleMJLayout2 = require "view.layouts.ui.room.mahjong.opposite_invisible_2_mj_node_layout.lua"
local OppositeVisibleMJLayout1   = require "view.layouts.ui.room.mahjong.opposite_visible_1_mj_node_layout.lua"
local OppositeVisibleMJLayout2   = require "view.layouts.ui.room.mahjong.opposite_visible_2_mj_node_layout.lua"

local RightInvisibleMJLayout  = require "view.layouts.ui.room.mahjong.right_invisible_mj_node_layout.lua"
local RightInvisibleMJLayout1 = require "view.layouts.ui.room.mahjong.right_invisible_1_mj_node_layout.lua"
local RightInvisibleMJLayout2 = require "view.layouts.ui.room.mahjong.right_invisible_2_mj_node_layout.lua"
local RightVisibleMJLayout1   = require "view.layouts.ui.room.mahjong.right_visible_1_mj_node_layout.lua"
local RightVisibleMJLayout2   = require "view.layouts.ui.room.mahjong.right_visible_2_mj_node_layout.lua"

function MahjongCreator.create(value, direction, type, state)
	if nil == value or nil == direction or nil == type or nil == state then
		local str = string.format("value : %s, direction : %s, type : %s, state : %s",
			tostring(value), tostring(direction), tostring(type), tostring(state))
		print("[MahjongCreator.create] param error : ", str)
		-- TODO : log
		return nil
	end

	local mj_node = nil
	if direction == MJConst.Directions.SELF then -- self
		mj_node = MahjongCreator.initMyCardLayout(value, type)
	elseif direction == MJConst.Directions.LEFT then
		mj_node = MahjongCreator.initLeftPlayerCardLayout(value, type)
	elseif direction == MJConst.Directions.OPPOSITE then
		mj_node = MahjongCreator.initOppositePlayerCardLayout(value, type)
	elseif direction == MJConst.Directions.RIGHT then 
		mj_node = MahjongCreator.initRightPlayerCardLayout(value, type)
	end

	return mj_node
end

function MahjongCreator.initMyCardLayout(value, type)
	local mj_layout = nil
	local need_show_card_value = false
	if type == MJConst.Types.INVISIBLE then
		mj_layout = MyInvisibleMJLayout:create().root
		need_show_card_value = true
	elseif type == MJConst.Types.INVISIBLE_AN_GANG_1 then
		mj_layout = MyInvisibleMJLayout1:create().root
	elseif type == MJConst.Types.INVISIBLE_AN_GANG_2 then
		mj_layout = MyInvisibleMJLayout2:create().root
	elseif type == MJConst.Types.VISIBLE then
		mj_layout = MyVisibleMJLayout1:create().root
		need_show_card_value = true
	elseif type == MJConst.Types.VISIBLE_MING_GANG then
		mj_layout = MyVisibleMJLayout2:create().root
		need_show_card_value = true
	elseif type == MJConst.Types.VISIBLE_DISCARD then
		-- TODO
	end

	if nil == mj_layout then
		print("[MahjongCreator.initMyCardLayout] nil == mj_layout")
		return
	end
	
	if need_show_card_value then
		local png = MahjongCreator.getCardPng(value)
		local img_fg = mj_layout:getChildByName("img_fg") or mj_layout:getChildByName("img_top_fg")
		if png then
			img_fg:loadTexture(png, ccui.TextureResType.plistType)
		end
	end

	return mj_layout
end

function MahjongCreator.initLeftPlayerCardLayout(type)
	local mj_layout = nil
	local need_show_card_value = false
	if type == MJConst.Types.INVISIBLE then
		mj_layout = LeftInvisibleMJLayout:create().root
		need_show_card_value = true
	elseif type == MJConst.Types.INVISIBLE_AN_GANG_1 then
		mj_layout = LeftInvisibleMJLayout1:create().root
	elseif type == MJConst.Types.INVISIBLE_AN_GANG_2 then
		mj_layout = LeftInvisibleMJLayout2:create().root
	elseif type == MJConst.Types.VISIBLE then
		mj_layout = LeftVisibleMJLayout1:create().root
		need_show_card_value = true
	elseif type == MJConst.Types.VISIBLE_MING_GANG then
		mj_layout = LeftVisibleMJLayout2:create().root
		need_show_card_value = true
	elseif type == MJConst.Types.VISIBLE_DISCARD then
		-- TODO
	end

	if nil == mj_layout then
		print("[MahjongCreator.initLeftPlayerCardLayout] nil == mj_layout")
		return
	end
	
	if need_show_card_value then
		local png = MahjongCreator.getCardPng(value)
		local img_fg = mj_layout:getChildByName("img_fg") or mj_layout:getChildByName("img_top_fg")
		if png then
			img_fg:loadTexture(png, ccui.TextureResType.plistType)
		end
	end

	return mj_layout
end

function MahjongCreator.initOppositePlayerCardLayout(type)
	local mj_layout = nil
	local need_show_card_value = false
	if type == MJConst.Types.INVISIBLE then
		mj_layout = OppositeInvisibleMJLayout:create().root
		need_show_card_value = true
	elseif type == MJConst.Types.INVISIBLE_AN_GANG_1 then
		mj_layout = OppositeInvisibleMJLayout1:create().root
	elseif type == MJConst.Types.INVISIBLE_AN_GANG_2 then
		mj_layout = OppositeInvisibleMJLayout2:create().root
	elseif type == MJConst.Types.VISIBLE then
		mj_layout = OppositeVisibleMJLayout1:create().root
		need_show_card_value = true
	elseif type == MJConst.Types.VISIBLE_MING_GANG then
		mj_layout = OppositeVisibleMJLayout2:create().root
		need_show_card_value = true
	elseif type == MJConst.Types.VISIBLE_DISCARD then
		-- TODO
	end

	if nil == mj_layout then
		print("[MahjongCreator.initOppositePlayerCardLayout] nil == mj_layout")
		return
	end
	
	if need_show_card_value then
		local png = MahjongCreator.getCardPng(value)
		local img_fg = mj_layout:getChildByName("img_fg") or mj_layout:getChildByName("img_top_fg")
		if png then
			img_fg:loadTexture(png, ccui.TextureResType.plistType)
		end
	end

	return mj_layout
end

function MahjongCreator.initRightPlayerCardLayout(type)
	local mj_layout = nil
	local need_show_card_value = false
	if type == MJConst.Types.INVISIBLE then
		mj_layout = RightInvisibleMJLayout:create().root
		need_show_card_value = true
	elseif type == MJConst.Types.INVISIBLE_AN_GANG_1 then
		mj_layout = RightInvisibleMJLayout1:create().root
	elseif type == MJConst.Types.INVISIBLE_AN_GANG_2 then
		mj_layout = RightInvisibleMJLayout2:create().root
	elseif type == MJConst.Types.VISIBLE then
		mj_layout = RightVisibleMJLayout1:create().root
		need_show_card_value = true
	elseif type == MJConst.Types.VISIBLE_MING_GANG then
		mj_layout = RightVisibleMJLayout2:create().root
		need_show_card_value = true
	elseif type == MJConst.Types.VISIBLE_DISCARD then
		-- TODO
	end

	if nil == mj_layout then
		print("[MahjongCreator.initRightPlayerCardLayout] nil == mj_layout")
		return
	end
	
	if need_show_card_value then
		local png = MahjongCreator.getCardPng(value)
		local img_fg = mj_layout:getChildByName("img_fg") or mj_layout:getChildByName("img_top_fg")
		if png then
			img_fg:loadTexture(png, ccui.TextureResType.plistType)
		end
	end

	return mj_layout
end

function MahjongCreator.getCardPng(value)
	local i, f = math.modf(value / 10)
	if MJConst.CardPngs[i] then
		return MJConst.CardPngs[i][value % 10]
	end
	return nil
end

return MahjongCreator