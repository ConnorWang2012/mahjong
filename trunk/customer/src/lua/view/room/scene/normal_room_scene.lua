--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   normal_room_scene.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: normal room scene.
@ others:
@ history:
1.date:
author:
modification:
--]]

local NormalRoomScene   = class("NormalRoomScene", require "view.room.scene.room_scene.lua")
local HeadLayerLayout   = require "view.layouts.ui.room.room_player_head_layer_layout.lua"
local MenuLayerLayout   = require "view.layouts.ui.room.room_menu_layer_layout.lua"
local MahjongCreator    = require "view.common.mahjong_creator.lua"
local AnimationCreator  = require "view.common.animation_creator.lua"
local PlayerHeadCreator = require "view.common.player_head_creator.lua"
local MahjongConst      = require "view.constant.mahjong_constants.lua"
local CardConst         = require "logic.constant.card_constants.lua"
local PlayerConst       = require "logic.constant.player_constants.lua"
local PlayCardHelper    = require "logic.helper.play_card_helper.lua"

function NormalRoomScene:ctor(view_file)
	print("[NormalRoomScene:ctor]")
    self.super.ctor(self, view_file)

	self:initAnimationLayer()	-- layer z order : 3
	self:initMahjongLayer()		-- layer z order : 0
	self:initPlayerHeadLayer()	-- layer z order : 1
	self:initMenuLayer()		-- layer z order : 2
end

function NormalRoomScene:initForGameStart()
	print("[NormalRoomScene:initForGameStart]")
	self.player_self_last_discard_		= nil
	self.left_player_last_discard_		= nil
	self.opposite_player_last_discard_	= nil
	self.right_player_last_discard_		= nil

	self.player_self_flower_offset_x_	= nil

	gamer.popup_mgr_.removePopup(gamer.PopupIDs.POPUP_ID_GAME_END)
end

function NormalRoomScene:initAnimationLayer()
	if not self.animation_layer_ then
		self.animation_layer_ = cc.Layer:create()
		self:addChild(self.animation_layer_)
		self.animation_layer_:setLocalZOrder(gamer.LocalZOrders.ROOM_ANIMATION_LAYER)
	end
end

function NormalRoomScene:initMahjongLayer()
	print("[NormalRoomScene:initMahjongLayer]")
	self:initMahjongs()
	self:initPlayCardTimerAndDirection()
end

function NormalRoomScene:initPlayerHeadLayer()
	print("[NormalRoomScene:initPlayerHeadLayer]")
	if self.player_head_layer_ then
		return
	end

	self.player_head_layer_ = HeadLayerLayout:create().root
	self.player_head_layer_:setLocalZOrder(gamer.LocalZOrders.ROOM_PLAYER_HEAD_LAYER)
	self:addChild(self.player_head_layer_)

	local init_player_self_head = function()
		self.player_self_head_layout_ = self.player_head_layer_:getChildByName("file_node_player_self_head")
		local head_node = PlayerHeadCreator.createPlayerSelfHeadPortrait()
		self.player_self_head_layout_:getChildByName("node_head"):addChild(head_node)
		self.player_self_head_layout_:getChildByName("img_ting"):setVisible(true)
		self.player_self_head_layout_:getChildByName("txt_gold"):setString("8000")

		head_node:getStencil():setScale(0.9)
	end

	local init_left_player_head = function()
		self.left_player_head_layout_ = self.player_head_layer_:getChildByName("file_node_left_player_head")
		local head_node = PlayerHeadCreator.createWithDefaultStencil("head_6.png")
		self.left_player_head_layout_:getChildByName("node_head"):addChild(head_node)
		self.left_player_head_layout_:getChildByName("txt_name"):setString("上浅玲心")
		self.left_player_head_layout_:getChildByName("txt_gold"):setString("3500")

		head_node:getStencil():setScale(0.9)
	end

	local init_opposite_player_head = function()
		self.opposite_player_head_layout_ = self.player_head_layer_:getChildByName("file_node_opposite_player_head")
		local head_node = PlayerHeadCreator.createWithDefaultStencil("head_2.png")
		self.opposite_player_head_layout_:getChildByName("node_head"):addChild(head_node)
		self.opposite_player_head_layout_:getChildByName("txt_name"):setString("大美人鱼儿")
		self.opposite_player_head_layout_:getChildByName("txt_gold"):setString("6000")

		head_node:getStencil():setScale(0.9)
	end

	local init_right_player_head = function()
		self.right_player_head_layout_ = self.player_head_layer_:getChildByName("file_node_right_player_head")
		local head_node = PlayerHeadCreator.createWithDefaultStencil("head_5.png")
		self.right_player_head_layout_:getChildByName("node_head"):addChild(head_node)
		self.right_player_head_layout_:getChildByName("txt_name"):setString("梦回唐朝")
		self.right_player_head_layout_:getChildByName("txt_gold"):setString("9000")

		head_node:getStencil():setScale(0.9)
	end

	local players_num = gamer.data_mgr_:room_msg_protocol():players_num()
	init_player_self_head()
	if 2 == players_num then
		init_opposite_player_head()
		self.player_head_layer_:getChildByName("file_node_left_player_head"):removeFromParent()
		self.player_head_layer_:getChildByName("file_node_right_player_head"):removeFromParent()
	elseif 3 == players_num then
		init_left_player_head()
		init_right_player_head()
		self.player_head_layer_:getChildByName("file_node_opposite_player_head"):removeFromParent()
	elseif 4 == players_num then
		init_left_player_head()
		init_opposite_player_head()
		init_right_player_head()
	end
end

function NormalRoomScene:initMenuLayer()
	if not self.menu_layer_ then
		self.menu_layer_ = MenuLayerLayout:create().root
		self.menu_layer_:setLocalZOrder(gamer.LocalZOrders.ROOM_MENU_LAYER)
		self:addChild(self.menu_layer_)
	end
end

function NormalRoomScene:initMahjongs()
	print("[NormalRoomScene:initMahjongs]")
	if not self.mahjong_layer_ then
		self.mahjong_layer_ = cc.Layer:create()
		self.mahjong_layer_:setLocalZOrder(gamer.LocalZOrders.ROOM_MAHJONG_LAYER)
		self:addChild(self.mahjong_layer_)
	else
		self.mahjong_layer_:removeAllChildren()
	end

	local players_num = gamer.data_mgr_:room_msg_protocol():players_num()
	self:initMahjongsOfPlayerSelf()
	if 2 == players_num then
		self:initMahjongsOfOppositePlayer()
	elseif 3 == players_num then
		self:initMahjongsOfLeftPlayer()
		self:initMahjongsOfRightPlayer()
	elseif 4 == players_num then
		self:initMahjongsOfLeftPlayer()
		self:initMahjongsOfOppositePlayer()
		self:initMahjongsOfRightPlayer()
	end

	self:updateRemainCardsNum(true)
end

function NormalRoomScene:initPlayCardTimerAndDirection()
	print("[NormalRoomScene:initPlayCardTimerAndDirection]")
	-- show timer and direction
	PlayCardHelper.setPlayerDirection(gamer.data_mgr_:self_player_id(), MahjongConst.Directions.SELF)	
	self:showFlagForOperatingPlayer()
end

function NormalRoomScene:initMahjongsOfPlayerSelf()
	print("[NormalRoomScene:initMahjongsOfPlayerSelf]")
	-- visible hand cards(not including flower cards)
	self:initVisibleMahjongsOfPlayerSelf()

	-- visible flower cards
	self:initVisibleFlowerMahjongsOfPlayerSelf()

	-- invisible hand cards	
	self:initInvisibleMahjongsOfPlayerSelf()
end

function NormalRoomScene:initMahjongsOfLeftPlayer()
	self:initMahjongsForLeftPlayer()

	-- direction
	local player_cards = gamer.data_mgr_:cards_msg_protocol_of_left_player()
	PlayCardHelper.setPlayerDirection(player_cards:player_id(), MahjongConst.Directions.LEFT)
end

function NormalRoomScene:initMahjongsOfOppositePlayer()
	print("[NormalRoomScene:initMahjongsOfOppositePlayer]")

	self:initMahjongsForOppositePlayer()

	-- direction
	local player_cards = gamer.data_mgr_:cards_msg_protocol_of_opposite_player()
	PlayCardHelper.setPlayerDirection(player_cards:player_id(), MahjongConst.Directions.OPPOSITE)
end

function NormalRoomScene:initMahjongsOfRightPlayer()
	self:initMahjongsForRightPlayer()

	-- direction
	local player_cards = gamer.data_mgr_:cards_msg_protocol_of_right_player()
	PlayCardHelper.setPlayerDirection(player_cards:player_id(), MahjongConst.Directions.RIGHT)
end

function NormalRoomScene:initVisibleMahjongsOfPlayerSelf()
	print("[NormalRoomScene:initVisibleMahjongsOfPlayerSelf]")
	local player_cards         = gamer.data_mgr_:cards_msg_protocol_of_player_self()
	local ming_gang_cards_size = player_cards:ming_gang_cards_size()
	local an_gang_cards_size   = player_cards:an_gang_cards_size()
	local peng_cards_size      = player_cards:peng_cards_size()
	local chi_cards_size       = player_cards:chi_cards_size()
	local offset_x             = MahjongConst.Sizes.OFFSET_X1
	local offsetx			   = MahjongConst.Sizes.OFFSET_X1 -- for invisible mahjongs
	self.visible_mj_nodes_player_self_ = {}

	-- ming gang
	if ming_gang_cards_size >= 4 then
		offset_x = MahjongConst.Sizes.OFFSET_X2
		for i = 1, ming_gang_cards_size / 4 do
			local mj_node = MahjongCreator.create(MahjongConst.Directions.SELF, 
												  MahjongConst.Types.VISIBLE_MING_GANG, 
												  player_cards:ming_gang_cards(4 * (i - 1)))
			if mj_node then
				mj_node:setPosition(cc.p(offset_x, MahjongConst.Sizes.OFFSET_Y2))
				self.mahjong_layer_:addChild(mj_node)
				offsetx = offset_x + MahjongConst.Sizes.CARD_W3 / 2 + MahjongConst.Sizes.CARD_INTERVAL1
				offset_x = offset_x + MahjongConst.Sizes.CARD_W3
				table.insert(self.visible_mj_nodes_player_self_, mj_node)
			end
		end
	end

	-- an gang
	if an_gang_cards_size >= 4 then
		if ming_gang_cards_size <= 0 then
			offset_x = MahjongConst.Sizes.OFFSET_X2
		end
		for i = 1, an_gang_cards_size / 4 do
			local mj_node = MahjongCreator.create(MahjongConst.Directions.SELF, 
												  MahjongConst.Types.INVISIBLE_3, 
												  player_cards:an_gang_cards(4 * (i - 1)))
			if mj_node then
				mj_node:setPosition(cc.p(offset_x, MahjongConst.Sizes.OFFSET_Y2))
				self.mahjong_layer_:addChild(mj_node)
				offsetx = offset_x + MahjongConst.Sizes.CARD_W3 / 2 + MahjongConst.Sizes.CARD_INTERVAL1
				offset_x = offset_x + MahjongConst.Sizes.CARD_W3
				table.insert(self.visible_mj_nodes_player_self_, mj_node)
			end
		end
	end

	-- peng 
	if peng_cards_size > 0 then
		if ming_gang_cards_size > 0 or an_gang_cards_size > 0 then
			offset_x = offset_x - MahjongConst.Sizes.CARD_W3 / 2 + MahjongConst.Sizes.CARD_W1 / 2
		end

		for i = 1, peng_cards_size do
			local mj_node = MahjongCreator.create(MahjongConst.Directions.SELF, 
												  MahjongConst.Types.VISIBLE, 
												  player_cards:peng_cards(i - 1))
			if mj_node then
				mj_node:setPosition(cc.p(offset_x, MahjongConst.Sizes.OFFSET_Y1))
				self.mahjong_layer_:addChild(mj_node)
				offsetx = offset_x + MahjongConst.Sizes.CARD_W2 / 2 + MahjongConst.Sizes.CARD_INTERVAL1
				offset_x = offset_x + MahjongConst.Sizes.CARD_W1
				table.insert(self.visible_mj_nodes_player_self_, mj_node)
			end
		end
	end

	-- chi
	if chi_cards_size > 0 then
		if 0 == peng_cards_size and (ming_gang_cards_size > 0 or an_gang_cards_size > 0) then
			offset_x = offset_x - MahjongConst.Sizes.CARD_W3 / 2 + MahjongConst.Sizes.CARD_W1 / 2
		end

		for i = 1, chi_cards_size do
			local mj_node = MahjongCreator.create(MahjongConst.Directions.SELF, 
												  MahjongConst.Types.VISIBLE, 
												  player_cards:chi_cards(i - 1))
			if mj_node then
				mj_node:setPosition(cc.p(offset_x, MahjongConst.Sizes.OFFSET_Y1))
				self.mahjong_layer_:addChild(mj_node)
				offsetx = offset_x + MahjongConst.Sizes.CARD_W2 / 2 + MahjongConst.Sizes.CARD_INTERVAL1
				offset_x = offset_x + MahjongConst.Sizes.CARD_W1
				table.insert(self.visible_mj_nodes_player_self_, mj_node)
			end
		end
	end

	self.player_self_invisible_mj_offset_x_ = offsetx
end

function NormalRoomScene:initVisibleFlowerMahjongsOfPlayerSelf()
	print("[NormalRoomScene:initVisibleFlowerMahjongsOfPlayerSelf]")
	-- flower and season
	local player_cards      = gamer.data_mgr_:cards_msg_protocol_of_player_self()
	local flower_cards_size = player_cards:flower_cards_size()
	local season_cards_size = player_cards:season_cards_size()
	local flower_offset_x = MahjongConst.Sizes.OFFSET_X5
	local flower_offset_y = MahjongConst.Sizes.OFFSET_Y5

	--print("[NormalRoomScene:initVisibleFlowerMahjongsOfPlayerSelf] flower_cards_size :", flower_cards_size)
	--print("[NormalRoomScene:initVisibleFlowerMahjongsOfPlayerSelf] season_cards_size :", season_cards_size)

	for i = 0, flower_cards_size - 1 do
		print("[NormalRoomScene:initVisibleFlowerMahjongsOfPlayerSelf] flower_card :", player_cards:flower_cards(i))
		local mj_node = MahjongCreator.create(MahjongConst.Directions.SELF, 
												MahjongConst.Types.VISIBLE, 
												player_cards:flower_cards(i))
		if mj_node then
			mj_node:setPosition(cc.p(flower_offset_x, flower_offset_y))
			self.mahjong_layer_:addChild(mj_node)
			flower_offset_x = flower_offset_x + MahjongConst.Sizes.CARD_W1
			self.player_self_flower_offset_x_ = flower_offset_x
		end
	end

	for i = 0, season_cards_size - 1 do
		--print("[NormalRoomScene:initVisibleFlowerMahjongsOfPlayerSelf] season_card :", player_cards:season_cards(i))
		local mj_node = MahjongCreator.create(MahjongConst.Directions.SELF, 
												MahjongConst.Types.VISIBLE, 
												player_cards:season_cards(i))
		if mj_node then
			mj_node:setPosition(cc.p(flower_offset_x, flower_offset_y))
			self.mahjong_layer_:addChild(mj_node)
			flower_offset_x = flower_offset_x + MahjongConst.Sizes.CARD_W1
			self.player_self_flower_offset_x_ = flower_offset_x
		end
	end
end

function NormalRoomScene:initInvisibleMahjongsOfPlayerSelf()
	print("[NormalRoomScene:initInvisibleMahjongsOfPlayerSelf]")
	self.invisible_mj_nodes_player_self_ = {}
	local myInsert = table.insert
	local player_cards = gamer.data_mgr_:cards_msg_protocol_of_player_self()

	--print("[NormalRoomScene:initInvisibleMahjongsOfPlayerSelf] cards size :", player_cards:invisible_hand_cards_size())
	for i = 0, player_cards:invisible_hand_cards_size() - 1 do
		--print("[NormalRoomScene:initInvisibleMahjongsOfPlayerSelf] card :", player_cards:invisible_hand_cards(i))
		local mj_node = MahjongCreator.create(MahjongConst.Directions.SELF, 
											  MahjongConst.Types.INVISIBLE, 
											  player_cards:invisible_hand_cards(i))
		if mj_node then
			mj_node:setPosition(cc.p(self.player_self_invisible_mj_offset_x_ + MahjongConst.Sizes.CARD_W2 * i, 
			                         MahjongConst.Sizes.OFFSET_Y3))
			self.mahjong_layer_:addChild(mj_node)

			local img_bg = mj_node:getChildByName("img_bg")
			img_bg:setTouchEnabled(true)
			img_bg:addClickEventListener(handler(self, self.onMahjongNodeTouch))

			myInsert(self.invisible_mj_nodes_player_self_, mj_node)
		end
	end
end

function NormalRoomScene:initMahjongsForLeftPlayer()
	-- 1.visible mahjong nodes
	local player_cards         = gamer.data_mgr_:cards_msg_protocol_of_left_player()
	local ming_gang_cards_size = player_cards:ming_gang_cards_size()
	local an_gang_cards_size   = player_cards:an_gang_cards_size()
	local peng_cards_size      = player_cards:peng_cards_size()
	local chi_cards_size       = player_cards:chi_cards_size()
	local flower_cards_size    = player_cards:flower_cards_size()
	local season_cards_size    = player_cards:season_cards_size()
	local offset_x             = MahjongConst.Sizes.LEFT_CARD_OFFSET_X0
	local offset_y             = MahjongConst.Sizes.CARD_OFFSET_Y0
	self.visible_mj_nodes_left_player_ = {}

	-- ming gang
	if ming_gang_cards_size >= 4 then
		for i = 1, ming_gang_cards_size / 4 do
			local mj_node = MahjongCreator.create(MahjongConst.Directions.LEFT, 
												  MahjongConst.Types.VISIBLE_MING_GANG, 
												  player_cards:ming_gang_cards(4 * (i - 1)))
			if mj_node then
				mj_node:setPosition(cc.p(offset_x, offset_y))
				self.mahjong_layer_:addChild(mj_node)
				offset_x = offset_x - MahjongConst.Sizes.CARD_OFFSET_X3
				offset_y = offset_y - MahjongConst.Sizes.CARD_OFFSET_Y3
				table.insert(self.visible_mj_nodes_left_player_, mj_node)
			end
		end
	end

	-- an gang
	if an_gang_cards_size >= 4 then
		for i = 1, an_gang_cards_size / 4 do
			local mj_node = MahjongCreator.create(MahjongConst.Directions.LEFT, 
												  MahjongConst.Types.INVISIBLE_3, 
												  player_cards:an_gang_cards(4 * (i - 1)))
			if mj_node then
				mj_node:setPosition(cc.p(offset_x, offset_y))
				self.mahjong_layer_:addChild(mj_node)
				offset_x = offset_x - MahjongConst.Sizes.CARD_OFFSET_X3
				offset_y = offset_y - MahjongConst.Sizes.CARD_OFFSET_Y3
				table.insert(self.visible_mj_nodes_left_player_, mj_node)
			end
		end
	end

	-- peng
	if peng_cards_size > 0 then
		if ming_gang_cards_size > 0 or an_gang_cards_size > 0 then
			offset_x = offset_x + MahjongConst.Sizes.CARD_OFFSET_X3 / 3
			offset_y = offset_y + MahjongConst.Sizes.CARD_OFFSET_Y3 / 3
		end

		for i = 0, peng_cards_size - 1 do
			local mj_node = MahjongCreator.create(MahjongConst.Directions.LEFT, 
												  MahjongConst.Types.VISIBLE, 
												  player_cards:peng_cards(i))
			if mj_node then
				mj_node:setPosition(cc.p(offset_x, offset_y))
				self.mahjong_layer_:addChild(mj_node)
				offset_x = offset_x - MahjongConst.Sizes.CARD_OFFSET_X1
				offset_y = offset_y - MahjongConst.Sizes.CARD_OFFSET_Y1
				table.insert(self.visible_mj_nodes_left_player_, mj_node)
			end
		end
	end

	-- chi 
	if chi_cards_size > 0 then
		if 0 == peng_cards_size and (ming_gang_cards_size > 0 or an_gang_cards_size > 0) then
			offset_x = offset_x + MahjongConst.Sizes.CARD_OFFSET_X3 / 3
			offset_y = offset_y + MahjongConst.Sizes.CARD_OFFSET_Y3 / 3
		end

		for i = 0, chi_cards_size - 1 do
			local mj_node = MahjongCreator.create(MahjongConst.Directions.LEFT, 
												  MahjongConst.Types.VISIBLE, 
												  player_cards:chi_cards(i))
			if mj_node then
				mj_node:setPosition(cc.p(offset_x, offset_y))
				self.mahjong_layer_:addChild(mj_node)
				offset_x = offset_x - MahjongConst.Sizes.CARD_OFFSET_X1
				offset_y = offset_y - MahjongConst.Sizes.CARD_OFFSET_Y1
				table.insert(self.visible_mj_nodes_left_player_, mj_node)
			end
		end
	end

	-- flower and season
	if flower_cards_size > 0 or season_cards_size > 0 then
		if 0 == chi_cards_size and 
		   0 == peng_cards_size and 
		   (ming_gang_cards_size > 0 or an_gang_cards_size > 0) then
			offset_x = offset_x + MahjongConst.Sizes.CARD_OFFSET_X3 / 3
			offset_y = offset_y + MahjongConst.Sizes.CARD_OFFSET_Y3 / 3
		end

		for i = 0, flower_cards_size - 1 do
			local mj_node = MahjongCreator.create(MahjongConst.Directions.LEFT, 
												  MahjongConst.Types.VISIBLE, 
												  player_cards:flower_cards(i))
			if mj_node then
				mj_node:setPosition(cc.p(offset_x, offset_y))
				self.mahjong_layer_:addChild(mj_node)
				offset_x = offset_x - MahjongConst.Sizes.CARD_OFFSET_X1
				offset_y = offset_y - MahjongConst.Sizes.CARD_OFFSET_Y1
				table.insert(self.visible_mj_nodes_left_player_, mj_node)
			end
		end

		for i = 0, season_cards_size - 1 do
			local mj_node = MahjongCreator.create(MahjongConst.Directions.LEFT, 
												  MahjongConst.Types.VISIBLE, 
												  player_cards:season_cards(i))
			if mj_node then
				mj_node:setPosition(cc.p(offset_x, offset_y))
				self.mahjong_layer_:addChild(mj_node)
				offset_x = offset_x - MahjongConst.Sizes.CARD_OFFSET_X1
				offset_y = offset_y - MahjongConst.Sizes.CARD_OFFSET_Y1
				table.insert(self.visible_mj_nodes_left_player_, mj_node)
			end
		end
	end

	self.left_player_invisible_mj_offset_x_ = offset_x
	self.left_player_invisible_mj_offset_y_ = offset_y

	--2.invisible mahjong nodes
	self.invisible_mj_nodes_left_player_ = {}
	local myInsert = table.insert
	-- make sure total card num is correct
	local invisible_card_nodes_num = player_cards:invisible_hand_cards_num()
	local visible_card_nodes_num = 3 * (ming_gang_cards_size / 4 + an_gang_cards_size / 4) + 
	                                    peng_cards_size + chi_cards_size
	local card_nodes_num = invisible_card_nodes_num + visible_card_nodes_num
	if card_nodes_num ~= CardConst.ONE_PLAYER_CARD_NUM and 
	   card_nodes_num ~= CardConst.ONE_PLAYER_CARD_NUM2 then
		invisible_card_nodes_num = CardConst.ONE_PLAYER_CARD_NUM - visible_card_nodes_num
	end
	-- add nodes
	for i = 0, invisible_card_nodes_num - 1 do
		local mj_node = MahjongCreator.create(MahjongConst.Directions.LEFT, 
											  MahjongConst.Types.INVISIBLE)
		if mj_node then
			mj_node:setPosition(cc.p(offset_x - MahjongConst.Sizes.CARD_OFFSET_X1 * i, 
			                         offset_y - MahjongConst.Sizes.CARD_OFFSET_Y1 * i))
			self.mahjong_layer_:addChild(mj_node)
			myInsert(self.invisible_mj_nodes_left_player_, mj_node)
		end
	end
end

function NormalRoomScene:initMahjongsForOppositePlayer()
	print("[NormalRoomScene:initMahjongsForOppositePlayer]")
	-- 1.visible mahjong nodes
	local player_cards         = gamer.data_mgr_:cards_msg_protocol_of_opposite_player()
	local ming_gang_cards_size = player_cards:ming_gang_cards_size()
	local an_gang_cards_size   = player_cards:an_gang_cards_size()
	local peng_cards_size      = player_cards:peng_cards_size()
	local chi_cards_size       = player_cards:chi_cards_size()
	local flower_cards_size    = player_cards:flower_cards_size()
	local season_cards_size    = player_cards:season_cards_size()
	local offset_x             = MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X0
	local offsetx			   = MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X0 -- for invisible mahjong
	self.visible_mj_nodes_opposite_player_ = {}

	-- ming gang
	if ming_gang_cards_size >= 4 then
		offset_x = MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X0
		for i = 1, ming_gang_cards_size / 4 do
			local mj_node = MahjongCreator.create(MahjongConst.Directions.OPPOSITE, 
												  MahjongConst.Types.VISIBLE_MING_GANG, 
												  player_cards:ming_gang_cards(4 * (i - 1)))
			if mj_node then
				mj_node:setPosition(cc.p(offset_x, MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_Y0))
				self.mahjong_layer_:addChild(mj_node)
				offsetx = offset_x - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X3 / 2 - 
				          MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1 / 2 - MahjongConst.Sizes.CARD_INTERVAL2
				offset_x = offset_x - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X3
				table.insert(self.visible_mj_nodes_opposite_player_, mj_node)
			end
		end
	end

	-- an gang
	if an_gang_cards_size >= 4 then
		for i = 1, an_gang_cards_size / 4 do
			local mj_node = MahjongCreator.create(MahjongConst.Directions.OPPOSITE, 
												  MahjongConst.Types.INVISIBLE_3, 
												  player_cards:an_gang_cards(4 * (i - 1)))
			if mj_node then
				mj_node:setPosition(cc.p(offset_x, MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_Y0))
				self.mahjong_layer_:addChild(mj_node)
				offsetx = offset_x - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X3 / 2 - 
				          MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1 / 2 - MahjongConst.Sizes.CARD_INTERVAL2
				offset_x = offset_x - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X3
				table.insert(self.visible_mj_nodes_opposite_player_, mj_node)
			end
		end
	end

	-- peng 
	if peng_cards_size > 0 then
		if ming_gang_cards_size > 0 or an_gang_cards_size > 0 then
			offset_x = offset_x + MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X3 / 3
		end

		for i = 1, peng_cards_size do
			local mj_node = MahjongCreator.create(MahjongConst.Directions.OPPOSITE, 
												  MahjongConst.Types.VISIBLE, 
												  player_cards:peng_cards(i - 1))
			if mj_node then
				mj_node:setPosition(cc.p(offset_x, MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_Y0))
				self.mahjong_layer_:addChild(mj_node)
				offsetx = offset_x - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1 - MahjongConst.Sizes.CARD_INTERVAL2
				offset_x = offset_x - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1
				table.insert(self.visible_mj_nodes_opposite_player_, mj_node)
			end
		end
	end

	-- chi
	if chi_cards_size > 0 then
		if 0 == peng_cards_size and (ming_gang_cards_size > 0 or an_gang_cards_size > 0) then
			offset_x = offset_x + MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X3 / 3
		end
		for i = 1, chi_cards_size do
			local mj_node = MahjongCreator.create(MahjongConst.Directions.OPPOSITE, 
												  MahjongConst.Types.VISIBLE, 
												  player_cards:chi_cards(i - 1))
			if mj_node then
				mj_node:setPosition(cc.p(offset_x, MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_Y0))
				self.mahjong_layer_:addChild(mj_node)
				offsetx = offset_x - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1 - MahjongConst.Sizes.CARD_INTERVAL2
				offset_x = offset_x - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1
				table.insert(self.visible_mj_nodes_opposite_player_, mj_node)
			end
		end
	end

	-- flower and season
	if flower_cards_size > 0 or season_cards_size > 0 then
		if 0 == chi_cards_size and 
		   0 == peng_cards_size and 
		   (ming_gang_cards_size > 0 or an_gang_cards_size > 0) then
			offset_x = offset_x + MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X3 / 3
		end

		for i = 0, flower_cards_size - 1 do
			local mj_node = MahjongCreator.create(MahjongConst.Directions.OPPOSITE, 
												  MahjongConst.Types.VISIBLE, 
												  player_cards:flower_cards(i))
			if mj_node then
				mj_node:setPosition(cc.p(offset_x, MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_Y0))
				self.mahjong_layer_:addChild(mj_node)
				offsetx = offset_x - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1 - MahjongConst.Sizes.CARD_INTERVAL2
				offset_x = offset_x - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1
				table.insert(self.visible_mj_nodes_opposite_player_, mj_node)
			end
		end

		for i = 0, season_cards_size - 1 do
			local mj_node = MahjongCreator.create(MahjongConst.Directions.OPPOSITE, 
												  MahjongConst.Types.VISIBLE, 
												  player_cards:season_cards(i))
			if mj_node then
				mj_node:setPosition(cc.p(offset_x, MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_Y0))
				self.mahjong_layer_:addChild(mj_node)
				offsetx = offset_x - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1 - MahjongConst.Sizes.CARD_INTERVAL2
				offset_x = offset_x - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1
				table.insert(self.visible_mj_nodes_opposite_player_, mj_node)
			end
		end
	end

	self.opposite_player_invisible_mj_offset_x_ = offsetx

	-- 2.invisible mahjong nodes
	local myInsert = table.insert
	self.invisible_mj_nodes_opposite_player_ = {}
	-- make sure total card num is correct
	local invisible_card_nodes_num = player_cards:invisible_hand_cards_num()
	local visible_card_nodes_num = 3 * (ming_gang_cards_size / 4 + an_gang_cards_size / 4) + 
	                                    peng_cards_size + chi_cards_size
	local card_nodes_num = invisible_card_nodes_num + visible_card_nodes_num
	if card_nodes_num ~= CardConst.ONE_PLAYER_CARD_NUM and 
	   card_nodes_num ~= CardConst.ONE_PLAYER_CARD_NUM2 then
		invisible_card_nodes_num = CardConst.ONE_PLAYER_CARD_NUM - visible_card_nodes_num
	end
	-- add nodes
	for i = 0, invisible_card_nodes_num - 1 do
		local mj_node = MahjongCreator.create(MahjongConst.Directions.OPPOSITE, 
											  MahjongConst.Types.INVISIBLE)
		if mj_node then
			mj_node:setPosition(cc.p(self.opposite_player_invisible_mj_offset_x_ - 
			                         MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X2 * i, 
			                         MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_Y0))
			self.mahjong_layer_:addChild(mj_node)
			myInsert(self.invisible_mj_nodes_opposite_player_, mj_node)
		end
	end
end

function NormalRoomScene:initMahjongsForRightPlayer()
	--1.visible mahjong nodes
	local player_cards         = gamer.data_mgr_:cards_msg_protocol_of_right_player()
	local ming_gang_cards_size = player_cards:ming_gang_cards_size()
	local an_gang_cards_size   = player_cards:an_gang_cards_size()
	local peng_cards_size      = player_cards:peng_cards_size()
	local chi_cards_size       = player_cards:chi_cards_size()
	local flower_cards_size    = player_cards:flower_cards_size()
	local season_cards_size    = player_cards:season_cards_size()
	local offset_x             = MahjongConst.Sizes.RIGHT_CARD_OFFSET_X0
	local offset_y             = MahjongConst.Sizes.CARD_OFFSET_Y0
	self.visible_mj_nodes_right_player_ = {}

	-- ming gang
	if ming_gang_cards_size >= 4 then
		for i = 1, ming_gang_cards_size / 4 do
			local mj_node = MahjongCreator.create(MahjongConst.Directions.RIGHT, 
												  MahjongConst.Types.VISIBLE_MING_GANG, 
												  player_cards:ming_gang_cards(4 * (i - 1)))
			if mj_node then
				mj_node:setPosition(cc.p(offset_x, offset_y))
				self.mahjong_layer_:addChild(mj_node)
				offset_x = offset_x + MahjongConst.Sizes.CARD_OFFSET_X3
				offset_y = offset_y - MahjongConst.Sizes.CARD_OFFSET_Y3
				table.insert(self.visible_mj_nodes_right_player_, mj_node)
			end
		end
	end

	-- an gang
	if an_gang_cards_size >= 4 then
		for i = 1, an_gang_cards_size / 4 do
			local mj_node = MahjongCreator.create(MahjongConst.Directions.RIGHT, 
												  MahjongConst.Types.INVISIBLE_3, 
												  player_cards:an_gang_cards(4 * (i - 1)))
			if mj_node then
				mj_node:setPosition(cc.p(offset_x, offset_y))
				self.mahjong_layer_:addChild(mj_node)
				offset_x = offset_x + MahjongConst.Sizes.CARD_OFFSET_X3
				offset_y = offset_y - MahjongConst.Sizes.CARD_OFFSET_Y3
				table.insert(self.visible_mj_nodes_right_player_, mj_node)
			end
		end
	end

	-- peng
	if peng_cards_size > 0 then
		if ming_gang_cards_size > 0 or an_gang_cards_size > 0 then
			offset_x = offset_x - MahjongConst.Sizes.CARD_OFFSET_X3 / 3
			offset_y = offset_y + MahjongConst.Sizes.CARD_OFFSET_Y3 / 3
		end

		for i = 0, peng_cards_size - 1 do
			local mj_node = MahjongCreator.create(MahjongConst.Directions.RIGHT, 
												  MahjongConst.Types.VISIBLE, 
												  player_cards:peng_cards(i))
			if mj_node then
				mj_node:setPosition(cc.p(offset_x, offset_y))
				self.mahjong_layer_:addChild(mj_node)
				offset_x = offset_x + MahjongConst.Sizes.CARD_OFFSET_X1
				offset_y = offset_y - MahjongConst.Sizes.CARD_OFFSET_Y1
				table.insert(self.visible_mj_nodes_right_player_, mj_node)
			end
		end
	end

	-- chi 
	if chi_cards_size > 0 then
		if 0 == peng_cards_size and (ming_gang_cards_size > 0 or an_gang_cards_size > 0) then
			offset_x = offset_x - MahjongConst.Sizes.CARD_OFFSET_X3 / 3
			offset_y = offset_y + MahjongConst.Sizes.CARD_OFFSET_Y3 / 3
		end

		for i = 0, chi_cards_size - 1 do
			local mj_node = MahjongCreator.create(MahjongConst.Directions.RIGHT, 
												  MahjongConst.Types.VISIBLE, 
												  player_cards:chi_cards(i))
			if mj_node then
				mj_node:setPosition(cc.p(offset_x, offset_y))
				self.mahjong_layer_:addChild(mj_node)
				offset_x = offset_x + MahjongConst.Sizes.CARD_OFFSET_X1
				offset_y = offset_y - MahjongConst.Sizes.CARD_OFFSET_Y1
				table.insert(self.visible_mj_nodes_right_player_, mj_node)
			end
		end
	end

	-- flower and season
	if flower_cards_size > 0 or season_cards_size > 0 then
		if 0 == chi_cards_size and 
		   0 == peng_cards_size and 
		   (ming_gang_cards_size > 0 or an_gang_cards_size > 0) then
			offset_x = offset_x - MahjongConst.Sizes.CARD_OFFSET_X3 / 3
			offset_y = offset_y + MahjongConst.Sizes.CARD_OFFSET_Y3 / 3
		end

		for i = 0, flower_cards_size - 1 do
			local mj_node = MahjongCreator.create(MahjongConst.Directions.RIGHT, 
												  MahjongConst.Types.VISIBLE, 
												  player_cards:flower_cards(i))
			if mj_node then
				mj_node:setPosition(cc.p(offset_x, offset_y))
				self.mahjong_layer_:addChild(mj_node)
				offset_x = offset_x + MahjongConst.Sizes.CARD_OFFSET_X1
				offset_y = offset_y - MahjongConst.Sizes.CARD_OFFSET_Y1
				table.insert(self.visible_mj_nodes_right_player_, mj_node)
			end
		end

		for i = 0, season_cards_size - 1 do
			local mj_node = MahjongCreator.create(MahjongConst.Directions.RIGHT, 
												  MahjongConst.Types.VISIBLE, 
												  player_cards:season_cards(i))
			if mj_node then
				mj_node:setPosition(cc.p(offset_x, offset_y))
				self.mahjong_layer_:addChild(mj_node)
				offset_x = offset_x + MahjongConst.Sizes.CARD_OFFSET_X1
				offset_y = offset_y - MahjongConst.Sizes.CARD_OFFSET_Y1
				table.insert(self.visible_mj_nodes_right_player_, mj_node)
			end
		end
	end

	self.right_player_invisible_mj_offset_x_ = offset_x
	self.right_player_invisible_mj_offset_y_ = offset_y

	--2.invisible mahjong nodes
	self.invisible_mj_nodes_right_player_ = {}
	local myInsert = table.insert
	-- make sure total card num is correct
	local invisible_card_nodes_num = player_cards:invisible_hand_cards_num()
	local visible_card_nodes_num = 3 * (ming_gang_cards_size / 4 + an_gang_cards_size / 4) + 
	                                    peng_cards_size + chi_cards_size
	local card_nodes_num = invisible_card_nodes_num + visible_card_nodes_num
	if card_nodes_num ~= CardConst.ONE_PLAYER_CARD_NUM and 
	   card_nodes_num ~= CardConst.ONE_PLAYER_CARD_NUM2 then
		invisible_card_nodes_num = CardConst.ONE_PLAYER_CARD_NUM - visible_card_nodes_num
	end
	-- add nodes
	for i = 0, invisible_card_nodes_num - 1 do
		local mj_node = MahjongCreator.create(MahjongConst.Directions.RIGHT, 
											  MahjongConst.Types.INVISIBLE)
		if mj_node then
			mj_node:setPosition(cc.p(offset_x + MahjongConst.Sizes.CARD_OFFSET_X1 * i, 
			                         offset_y - MahjongConst.Sizes.CARD_OFFSET_Y1 * i))
			self.mahjong_layer_:addChild(mj_node)
			myInsert(self.invisible_mj_nodes_right_player_, mj_node)
		end
	end
end

function NormalRoomScene:initMahjongsAfterOperationForPlayerSelf()
	self:removeAllMahjongNodes(self.visible_mj_nodes_player_self_)
	self:removeAllMahjongNodes(self.invisible_mj_nodes_player_self_)

	self:initVisibleMahjongsOfPlayerSelf()
	self:initInvisibleMahjongsOfPlayerSelf()

	self:removeLastDiscardNodeForPlayerSelf()
end

function NormalRoomScene:initMahjongsAfterOperationForLeftPlayer()
	self:removeAllMahjongNodes(self.visible_mj_nodes_left_player_)
	self:removeAllMahjongNodes(self.invisible_mj_nodes_left_player_)

	self:initMahjongsOfLeftPlayer()

	self:removeLastDiscardNodeForLeftPlayer()
end

function NormalRoomScene:initMahjongsAfterOperationForOppositePlayer()
	self:removeAllMahjongNodes(self.visible_mj_nodes_opposite_player_)
	self:removeAllMahjongNodes(self.invisible_mj_nodes_opposite_player_)

	self:initMahjongsOfOppositePlayer()

	self:removeLastDiscardNodeForOppositePlayer()
end

function NormalRoomScene:initMahjongsAfterOperationForRightPlayer()
	self:removeAllMahjongNodes(self.visible_mj_nodes_right_player_)
	self:removeAllMahjongNodes(self.invisible_mj_nodes_right_player_)

	self:initMahjongsOfRightPlayer()

	self:removeLastDiscardNodeForRightPlayer()
end

-- TODO : use event listener
function NormalRoomScene:updateRemainCardsNum(first_update)
	print("[NormalRoomScene:updateRemainCardsNum]")
	if not self.txt_remain_cards_ then
		local tmp = self.root_node_:getChildByName("img_remain_cards")
		self.txt_remain_cards_ = tmp:getChildByName("txt_remain_cards")
	end

	if first_update then
		local num = gamer.data_mgr_:room_msg_protocol():table_list(0):remain_cards_num()
		if num >= 0 then
			self.txt_remain_cards_:setString(tostring(num))
		end
	else
		local num = tonumber(self.txt_remain_cards_:getString()) - 1
		if num >= 0 then
			self.txt_remain_cards_:setString(tostring(num))
		end
	end
end

function NormalRoomScene:getNextDiscardPosOfPlayerSelf()
	local x, y = MahjongConst.Sizes.DISCARD_X1, MahjongConst.Sizes.DISCARD_Y1
	if self.player_self_last_discard_ then
		local pos_x, pos_y = self.player_self_last_discard_:getPosition() 
		if pos_y == MahjongConst.Sizes.DISCARD_Y1 then 
			if pos_x < MahjongConst.Sizes.DISCARD_X11 then
				x = pos_x + MahjongConst.Sizes.DISCARD_OFFSET_X
			else
				x, y = MahjongConst.Sizes.DISCARD_X2, MahjongConst.Sizes.DISCARD_Y2
			end
		elseif pos_y == MahjongConst.Sizes.DISCARD_Y2 then 
			if pos_x < MahjongConst.Sizes.DISCARD_X22 then
				x, y = pos_x + MahjongConst.Sizes.DISCARD_OFFSET_X, pos_y
			else
				x, y = MahjongConst.Sizes.DISCARD_X3, MahjongConst.Sizes.DISCARD_Y3
			end
		elseif pos_y == MahjongConst.Sizes.DISCARD_Y3 then 
			if pos_x < MahjongConst.Sizes.DISCARD_X33 then
				x, y = pos_x + MahjongConst.Sizes.DISCARD_OFFSET_X, pos_y
			else
				print("[NormalRoomScene:getNextDiscardPosOfPlayerSelf] pos overflow")
				x, y = pos_x, pos_y
				-- TODO : get a available pos
			end
		end
	end
	return x, y
end

function NormalRoomScene:getNextDiscardPosOfLeftPlayer()
	local x, y = MahjongConst.Sizes.LEFT_DISCARD_X1, MahjongConst.Sizes.LEFT_DISCARD_Y1
	if self.left_player_last_discard_ then
		local pos_x, pos_y = self.left_player_last_discard_:getPosition() 
		if pos_y == MahjongConst.Sizes.LEFT_DISCARD_Y11 then
			x, y = MahjongConst.Sizes.LEFT_DISCARD_X2, MahjongConst.Sizes.LEFT_DISCARD_Y2
		elseif pos_y == MahjongConst.Sizes.LEFT_DISCARD_Y22 then
			x, y = MahjongConst.Sizes.LEFT_DISCARD_X3, MahjongConst.Sizes.LEFT_DISCARD_Y3
		elseif pos_y == MahjongConst.Sizes.LEFT_DISCARD_Y33 then
			x, y = MahjongConst.Sizes.LEFT_DISCARD_X4, MahjongConst.Sizes.LEFT_DISCARD_Y4
		elseif pos_y == MahjongConst.Sizes.LEFT_DISCARD_Y44 then
			print("[NormalRoomScene:getNextDiscardPosOfLeftPlayer] pos overflow")
			x, y = pos_x, pos_y
			-- TODO : get a available pos
		else
			x = pos_x - MahjongConst.Sizes.LEFT_DISCARD_OFFSET_X
			y = pos_y - MahjongConst.Sizes.LEFT_DISCARD_OFFSET_Y
		end
	end
	return x, y
end

function NormalRoomScene:getNextDiscardPosOfOppositePlayer()
	local x, y = MahjongConst.Sizes.OPPOSITE_DISCARD_X1, MahjongConst.Sizes.OPPOSITE_DISCARD_Y1
	if self.opposite_player_last_discard_ then
		local pos_x, pos_y = self.opposite_player_last_discard_:getPosition() 
		if pos_y == MahjongConst.Sizes.OPPOSITE_DISCARD_Y1 then 
			if pos_x > MahjongConst.Sizes.OPPOSITE_DISCARD_X11 then
				x = pos_x - MahjongConst.Sizes.OPPOSITE_DISCARD_OFFSET_X
			else
				x, y = MahjongConst.Sizes.OPPOSITE_DISCARD_X2, MahjongConst.Sizes.OPPOSITE_DISCARD_Y2
			end
		elseif pos_y == MahjongConst.Sizes.OPPOSITE_DISCARD_Y2 then 
			if pos_x > MahjongConst.Sizes.OPPOSITE_DISCARD_X22 then
				x, y = pos_x - MahjongConst.Sizes.OPPOSITE_DISCARD_OFFSET_X, pos_y
			else
				x, y = MahjongConst.Sizes.OPPOSITE_DISCARD_X3, MahjongConst.Sizes.OPPOSITE_DISCARD_Y3
			end
		elseif pos_y == MahjongConst.Sizes.OPPOSITE_DISCARD_Y3 then
			if pos_x > MahjongConst.Sizes.OPPOSITE_DISCARD_X33 then
				x, y = pos_x - MahjongConst.Sizes.OPPOSITE_DISCARD_OFFSET_X, pos_y
			else
				print("[NormalRoomScene:getNextDiscardPosOfOppositePlayer] pos overflow")
				x, y = pos_x, pos_y
				-- TODO : get a available pos
			end
		end
	end
	return x, y
end

function NormalRoomScene:getNextDiscardPosOfRightPlayer()
	local x, y = MahjongConst.Sizes.RIGHT_DISCARD_X1, MahjongConst.Sizes.RIGHT_DISCARD_Y1
	if self.right_player_last_discard_ then
		local pos_x, pos_y = self.right_player_last_discard_:getPosition() 
		if pos_y == MahjongConst.Sizes.RIGHT_DISCARD_Y11 then
			x, y = MahjongConst.Sizes.RIGHT_DISCARD_X2, MahjongConst.Sizes.RIGHT_DISCARD_Y2
		elseif pos_y == MahjongConst.Sizes.RIGHT_DISCARD_Y22 then
			x, y = MahjongConst.Sizes.RIGHT_DISCARD_X3, MahjongConst.Sizes.RIGHT_DISCARD_Y3
		elseif pos_y == MahjongConst.Sizes.RIGHT_DISCARD_Y33 then
			x, y = MahjongConst.Sizes.RIGHT_DISCARD_X4, MahjongConst.Sizes.RIGHT_DISCARD_Y4
		elseif pos_y == MahjongConst.Sizes.RIGHT_DISCARD_Y44 then
			print("[NormalRoomScene:getNextDiscardPosOfRightPlayer] pos overflow")
			x, y = pos_x, pos_y
			-- TODO : get a available pos
		else
			x = pos_x - MahjongConst.Sizes.RIGHT_DISCARD_OFFSET_X
			y = pos_y + MahjongConst.Sizes.RIGHT_DISCARD_OFFSET_Y
		end
	end
	return x, y
end

function NormalRoomScene:startPlayCardTimer()
	self:stopPlayCardTimer()

	if not self.node_play_card_timer_ then
		self.node_play_card_timer_ = self.root_node_:getChildByName("node_play_card_timer")
	end
	
	self.play_card_time_count_ = CardConst.OPERATION_TIMEOUT_MAX
	self:setTimeOfPlayCardTimer(self.play_card_time_count_)

	self.play_card_timer_ = cc.Director:getInstance():getScheduler():scheduleScriptFunc(handler(self, self.playCardTimer), 1, false)
end

function NormalRoomScene:stopPlayCardTimer()
	if self.play_card_timer_ then
		cc.Director:getInstance():getScheduler():unscheduleScriptEntry(self.play_card_timer_)
		self.play_card_timer_ = nil
	end
end

function NormalRoomScene:playCardTimer()
	if self.play_card_time_count_ >= 0 then
		self:setTimeOfPlayCardTimer(self.play_card_time_count_)

		self.play_card_time_count_ = self.play_card_time_count_ - 1

		self:dealWithOperationTimeout1()
	else
		self:stopPlayCardTimer()
		self:dealWithOperationTimeout2()
	end
end

function NormalRoomScene:setTimeOfPlayCardTimer(time)
	self.node_play_card_timer_:removeAllChildren()
	local text = ccui.TextAtlas:create(tostring(time), "assets/common/numbers_blue.png", 42, 58, "0")
	self.node_play_card_timer_:addChild(text)
end

-- current operating player is other player(i can't discard but do other operation)
function NormalRoomScene:dealWithOperationTimeout1()
	if PlayCardHelper.hasSpecialOperation() then
		if CardConst.OPERATION_TIMEOUT_MAX - self.play_card_time_count_ > CardConst.OPERATION_TIMEOUT_MAX2 then
			print("[NormalRoomScene:dealWithOperationTimeout1] operation timeout1")
			self:doPlayerSelfOperationGiveup()
		end
	end
end

-- current operating player is player self(i can discard and do other operation)
function NormalRoomScene:dealWithOperationTimeout2()
	print("[NormalRoomScene:dealWithOperationTimeout2] operation timeout2")
	-- do operation of discard or buhua or zi mo or give up
	local proto = gamer.data_mgr_:play_card_msg_protocol()
	local next_player_id = proto:next_operate_player_id()
	print("[NormalRoomScene:dealWithOperationTimeout2] new card : ", proto:new_card())
	print("[NormalRoomScene:dealWithOperationTimeout2] next_player_id : ", next_player_id)
	if next_player_id == gamer.data_mgr_:self_player_id() then -- turn to player self to play card
		local operation_id = proto:my_available_operation_id()
		print("[NormalRoomScene:dealWithOperationTimeout2] operation_id : ", operation_id)
		if proto:new_card() == CardConst.CardValues.INVALID_CARD_VALUE then -- it seems player self dont have new card
			-- for first game start, play_card_msg_protocol is invalid, should check invisible_hand_cards_size
			local size = gamer.data_mgr_:cards_msg_protocol_of_player_self():invisible_hand_cards_size()
			if size == CardConst.ONE_PLAYER_CARD_NUM2 then -- it means player self have new card
				local card = gamer.data_mgr_:cards_msg_protocol_of_player_self():invisible_hand_cards(size - 1)
				self:doPlayerSelfOperationDiscard(card)
			elseif operation_id == CardConst.OperationIDs.OPERATION_NONE then
				local card = gamer.data_mgr_:cards_msg_protocol_of_player_self():invisible_hand_cards(size - 1)
				self:doPlayerSelfOperationDiscard(card)
			elseif operation_id == CardConst.OperationIDs.OPERATION_CHI then
				self:doPlayerSelfOperationGiveup()
			elseif operation_id == CardConst.OperationIDs.OPERATION_PENG then
				self:doPlayerSelfOperationGiveup()
			elseif operation_id == CardConst.OperationIDs.OPERATION_PENG_GANG then
				self:doPlayerSelfOperationGiveup()
			elseif operation_id == CardConst.OperationIDs.OPERATION_HU then
				self:doPlayerSelfOperationHu()
			end
		else -- player self have new card
			if operation_id == CardConst.OperationIDs.OPERATION_NONE then
				self:doPlayerSelfOperationDiscard(proto:new_card())
			elseif operation_id == CardConst.OperationIDs.OPERATION_MING_GANG then
				self:doPlayerSelfOperationGiveup()
				self:doPlayerSelfOperationDiscard(proto:new_card())
			elseif operation_id == CardConst.OperationIDs.OPERATION_AN_GANG then
				self:doPlayerSelfOperationGiveup()
				self:doPlayerSelfOperationDiscard(proto:new_card())
			elseif operation_id == CardConst.OperationIDs.OPERATION_BU_HUA then
				self:doPlayerSelfOperationBuhua()
			elseif operation_id == CardConst.OperationIDs.OPERATION_ZI_MO then
				self:doPlayerSelfOperationZimo()
			end
		end
	else -- turn to player self to play card
		-- TODO : 
		print("[NormalRoomScene:dealWithOperationTimeout2] next_player_id != self_player_id")
	end
end

function NormalRoomScene:removeMahjongNode(mahjong_nodes_table, mahjong_value)
	for k, v in pairs(mahjong_nodes_table) do
		if v:getTag() == mahjong_value then
			v:removeFromParent()
			table.remove(mahjong_nodes_table, k)
			break
		end
	end
end

function NormalRoomScene:removeLastMahjongNode(mahjong_nodes_table)
	local n = #mahjong_nodes_table
	if n > 0 then
		mahjong_nodes_table[n]:removeFromParent()
		table.remove(mahjong_nodes_table, n)
	end
end

function NormalRoomScene:removeMahjongNodes(mahjong_nodes_table, mahjong_value, num)
	local func = function(nodes_table, value)
		for k, v in pairs(nodes_table) do
			if v:getTag() == value then
				v:removeFromParent()
				table.remove(nodes_table, k)
				break
			end
		end
	end
	for i = 1, num do
		func(mahjong_nodes_table, mahjong_value)
	end
end

function NormalRoomScene:removeAllMahjongNodes(mahjong_nodes_table)
	local n = #mahjong_nodes_table
	for i = 1, n do
		local last = n - i + 1
		mahjong_nodes_table[last]:removeFromParent()
		table.remove(mahjong_nodes_table, last)
	end
	mahjong_nodes_table = {}
end

function NormalRoomScene:removeLastDiscardNodeForPlayerSelf()
	local players_num = gamer.data_mgr_:room_msg_protocol():players_num()
	if players_num > 2 then
		if self.left_player_last_discard_ then
			self.left_player_last_discard_:removeFromParent()
			self.left_player_last_discard_ = self.left_player_second_to_last_discard_
		end
	else
		if self.opposite_player_last_discard_ then
			self.opposite_player_last_discard_:removeFromParent()
			self.opposite_player_last_discard_ = self.opposite_player_second_to_last_discard_
		end
	end
end

function NormalRoomScene:removeLastDiscardNodeForLeftPlayer()
	local players_num = gamer.data_mgr_:room_msg_protocol():players_num()
	if 3 == players_num then
		if self.right_player_last_discard_ then
			self.right_player_last_discard_:removeFromParent()
			self.right_player_last_discard_ = self.right_player_second_to_last_discard_
		end
	elseif 4 == players_num then
		if self.opposite_player_last_discard_ then
			self.opposite_player_last_discard_:removeFromParent()
			self.opposite_player_last_discard_ = self.opposite_player_second_to_last_discard_
		end
	end
end

function NormalRoomScene:removeLastDiscardNodeForOppositePlayer()
	local players_num = gamer.data_mgr_:room_msg_protocol():players_num()
	if 2 == players_num then
		if self.player_self_last_discard_ then
			self.player_self_last_discard_:removeFromParent()
			self.player_self_last_discard_ = self.player_self_second_to_last_discard_
		end
	elseif 4 == players_num then
		if self.right_player_last_discard_ then
			self.right_player_last_discard_:removeFromParent()
			self.right_player_last_discard_ = self.right_player_second_to_last_discard_
		end
	end
end

function NormalRoomScene:removeLastDiscardNodeForRightPlayer()
	if self.player_self_last_discard_ then
		self.player_self_last_discard_:removeFromParent()
		self.player_self_last_discard_ = self.player_self_second_to_last_discard_
	end
end

function NormalRoomScene:modifyMahjongsOfPlayerSelfAfterDiscard(mahjong_value)
	-- remove discard from invisible cards
	gamer.data_mgr_:updateCardForDiscardOfPlayerSelf(mahjong_value)

	-- add discard node
	self:showDiscardOfPlayerSelf(mahjong_value)

	if self.last_selected_mj_ then
		self.last_selected_mj_:setPositionY(MahjongConst.Sizes.OFFSET_Y3)
		self.last_selected_mj_ = nil
	end

	-- remove invisible card node
	local new_card = gamer.data_mgr_:play_card_msg_protocol():new_card()
	if new_card == CardConst.CardValues.INVALID_CARD_VALUE then
		self:removeMahjongNode(self.invisible_mj_nodes_player_self_, mahjong_value)
		self:resetPositionOfInvisibleMahjongsForPlayerSelf()
	elseif new_card == mahjong_value then
		self:removeLastMahjongNode(self.invisible_mj_nodes_player_self_)
	else
		self:removeAllMahjongNodes(self.invisible_mj_nodes_player_self_)
		self:initInvisibleMahjongsOfPlayerSelf()
	end
end

function NormalRoomScene:modifyMahjongsOfPlayerSelfAfterChi(cards)
	gamer.data_mgr_:updateCardForChi(gamer.data_mgr_:self_player_id(), cards[1], cards[2], cards[3])
	
	self:initMahjongsAfterOperationForPlayerSelf()
end

function NormalRoomScene:modifyMahjongsOfPlayerSelfAfterPeng()
	local discard = gamer.data_mgr_:play_card_msg_protocol():discard()
	gamer.data_mgr_:updateCardForPeng(gamer.data_mgr_:self_player_id(), discard)

	self:initMahjongsAfterOperationForPlayerSelf()
end

function NormalRoomScene:modifyMahjongsOfPlayerSelfAfterPengGang()
	local discard = gamer.data_mgr_:play_card_msg_protocol():discard()
	gamer.data_mgr_:updateCardForPengAndGang(gamer.data_mgr_:self_player_id(), discard)

	self:initMahjongsAfterOperationForPlayerSelf()
end

function NormalRoomScene:modifyMahjongsOfPlayerSelfAfterBuhua()
	local flower_offset_x = self.player_self_flower_offset_x_ or MahjongConst.Sizes.OFFSET_X5
	local flower_offset_y = MahjongConst.Sizes.OFFSET_Y5

	local player_cards = gamer.data_mgr_:cards_msg_protocol_of_player_self()
	for i = player_cards:invisible_hand_cards_size() - 1, 0, -1 do
		if PlayCardHelper.isFlowerOrSeasonCard(player_cards:invisible_hand_cards(i)) then
			local mj_node = MahjongCreator.create(MahjongConst.Directions.SELF, 
											      MahjongConst.Types.VISIBLE, 
											      player_cards:invisible_hand_cards(i))
			if mj_node then
				mj_node:setPosition(cc.p(flower_offset_x, flower_offset_y))
				self.mahjong_layer_:addChild(mj_node)
				flower_offset_x = flower_offset_x + MahjongConst.Sizes.CARD_W1
				self.player_self_flower_offset_x_ = flower_offset_x
			end
		elseif i <= player_cards:invisible_hand_cards_size() - 2 then
			break
		end
	end

	gamer.data_mgr_:updateCardForBuhua(gamer.data_mgr_:self_player_id())
	
	self:removeAllMahjongNodes(self.invisible_mj_nodes_player_self_)
	self:initInvisibleMahjongsOfPlayerSelf()
end

function NormalRoomScene:modifyMahjongsOfPlayerSelfAfterMingGang()
	local discard = gamer.data_mgr_:play_card_msg_protocol():discard()
	gamer.data_mgr_:updateCardForMingGang(gamer.data_mgr_:self_player_id(), discard)

	self:initMahjongsAfterOperationForPlayerSelf()
end

function NormalRoomScene:modifyMahjongsOfPlayerSelfAfterAnGang()
	local discard = gamer.data_mgr_:play_card_msg_protocol():discard()
	gamer.data_mgr_:updateCardForAnGang(gamer.data_mgr_:self_player_id(), discard)

	self:initMahjongsAfterOperationForPlayerSelf()
end

function NormalRoomScene:modifyMahjongsOfOtherPlayerAfterDiscard(play_card_msg)
	print("[NormalRoomScene:modifyMahjongsOfOtherPlayerAfterDiscard]")
	local direction = PlayCardHelper.getPlayerDirection(play_card_msg:player_id())

	if direction == MahjongConst.Directions.LEFT then
		self:showDiscardOfLeftPlayer(play_card_msg:discard())
		local n = #self.invisible_mj_nodes_left_player_
		if 2 == (n % 3) then -- make sure num of invisible card nodes is correct after remove one
			self:removeLastMahjongNode(self.invisible_mj_nodes_left_player_)
		end
	elseif direction == MahjongConst.Directions.OPPOSITE then
		self:showDiscardOfOppositePlayer(play_card_msg:discard())
		local n = #self.invisible_mj_nodes_opposite_player_
		if 2 == (n % 3) then -- make sure num of invisible card nodes is correct after remove one
			self:removeLastMahjongNode(self.invisible_mj_nodes_opposite_player_)
		end
	elseif direction == MahjongConst.Directions.RIGHT then
		self:showDiscardOfRightPlayer(play_card_msg:discard())
		local n = #self.invisible_mj_nodes_right_player_
		if 2 == (n % 3) then -- make sure num of invisible card nodes is correct after remove one
			self:removeLastMahjongNode(self.invisible_mj_nodes_right_player_)
		end
	end
end

function NormalRoomScene:modifyMahjongsOfOtherPlayerAfterOperation()
	print("[NormalRoomScene:modifyMahjongsOfOtherPlayerAfterOperation]")
	local player_id = gamer.data_mgr_:play_card_msg_protocol():player_id()
	local direction = PlayCardHelper.getPlayerDirection(player_id)

	if direction == MahjongConst.Directions.LEFT then
		self:initMahjongsAfterOperationForLeftPlayer()
	elseif direction == MahjongConst.Directions.OPPOSITE then
		self:initMahjongsAfterOperationForOppositePlayer()
	elseif direction == MahjongConst.Directions.RIGHT then
		self:initMahjongsAfterOperationForRightPlayer()
	end
end

function NormalRoomScene:resetPositionOfInvisibleMahjongsForPlayerSelf()
	for k, v in pairs(self.invisible_mj_nodes_player_self_) do
		v:setPosition(cc.p(self.player_self_invisible_mj_offset_x_ + MahjongConst.Sizes.CARD_W2 * (k - 1), 
			               MahjongConst.Sizes.OFFSET_Y3))
	end
end

function NormalRoomScene:resetPositionOfInvisibleMahjongsForOppositePlayer()
	for k, v in pairs(self.invisible_mj_nodes_opposite_player_) do
		v:setPosition(cc.p(self.opposite_player_invisible_mj_offset_x_ - 
						   MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1 * (k - 1), 
			               MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_Y0))
	end
end

function NormalRoomScene:showFlagForOperatingPlayer()
	self:startPlayCardTimer()
	self:showNextPlayCardDirection()
end

function NormalRoomScene:showNextPlayCardDirection()
	if self.img_player_direction_ then
		self.img_player_direction_:setVisible(false)
	end
	
	local img_name = PlayCardHelper.getImageNameOfDirectionForOperatingPlayer()
	self.img_player_direction_ = self.root_node_:getChildByName(img_name)

	if self.img_player_direction_ then
		self.img_player_direction_:setVisible(true)
	end
end

function NormalRoomScene:showNextPlayCardDirectionAfterPlayerSelf()
	if self.img_player_direction_ then
		self.img_player_direction_:setVisible(false)
	end
	
	local img_name = PlayCardHelper.getImageNameOfDirectionAfterPlayerSelf()
	self.img_player_direction_ = self.root_node_:getChildByName(img_name)

	if self.img_player_direction_ then
		self.img_player_direction_:setVisible(true)
	end
end

function NormalRoomScene:showInvisibleMahjongsForGameEnd(play_card_msg)
	print("[NormalRoomScene:showInvisibleMahjongsForGameEnd]")
	local direction = MahjongConst.Directions.SELF
	if play_card_msg then
		direction = PlayCardHelper.getPlayerDirection(play_card_msg:player_id())
	end

	if direction == MahjongConst.Directions.SELF then
		self:showInvisibleMahjongsOfPlayerSelf()
	elseif direction == MahjongConst.Directions.LEFT then
		self:showInvisibleMahjongsOfLeftPlayer(play_card_msg)
	elseif direction == MahjongConst.Directions.OPPOSITE then
		self:showInvisibleMahjongsOfOppositePlayer(play_card_msg)
	elseif direction == MahjongConst.Directions.RIGHT then
		self:showInvisibleMahjongsOfRightPlayer(play_card_msg)
	end
end

function NormalRoomScene:showInvisibleMahjongsOfPlayerSelf()
	for k, v in pairs(self.invisible_mj_nodes_player_self_) do
		local mj_value = v:getTag()
		v:removeFromParent()

		local mj_node = MahjongCreator.create(MahjongConst.Directions.SELF, 
											  MahjongConst.Types.VISIBLE, 
											  mj_value)
		if mj_node then
			mj_node:setPosition(cc.p(self.player_self_invisible_mj_offset_x_ + MahjongConst.Sizes.CARD_W1 * (k - 1),
			                         MahjongConst.Sizes.OFFSET_Y1))
			self.mahjong_layer_:addChild(mj_node)
		end
	end

	self.invisible_mj_nodes_player_self_ = {}
end

function NormalRoomScene:showInvisibleMahjongsOfLeftPlayer(play_card_msg)
	local invisible_hand_cards_size = play_card_msg:invisible_hand_cards_size()
	if 0 == invisible_hand_cards_size then
		return
	end

	self:removeAllMahjongNodes(self.invisible_mj_nodes_left_player_)

	local offset_x = self.left_player_invisible_mj_offset_x_ - MahjongConst.Sizes.CARD_OFFSET_X1 / 2
	local offset_y = self.left_player_invisible_mj_offset_y_ - MahjongConst.Sizes.CARD_OFFSET_Y1 / 2
	for i = 0, invisible_hand_cards_size - 1 do
		local mj_node = MahjongCreator.create(MahjongConst.Directions.LEFT, 
											  MahjongConst.Types.VISIBLE, 
											  play_card_msg:invisible_hand_cards(i))
		if mj_node then
			mj_node:setPosition(cc.p(offset_x - MahjongConst.Sizes.CARD_OFFSET_X1 * i,
			                         offset_y - MahjongConst.Sizes.CARD_OFFSET_Y1 * i))
			self.mahjong_layer_:addChild(mj_node)
		end
	end
end

function NormalRoomScene:showInvisibleMahjongsOfOppositePlayer(play_card_msg)
	local invisible_hand_cards_size = play_card_msg:invisible_hand_cards_size()
	if 0 == invisible_hand_cards_size then
		return
	end

	self:removeAllMahjongNodes(self.invisible_mj_nodes_opposite_player_)

	for i = 0,  invisible_hand_cards_size - 1 do
		local mj_node = MahjongCreator.create(MahjongConst.Directions.OPPOSITE, 
											  MahjongConst.Types.VISIBLE, 
											  play_card_msg:invisible_hand_cards(i))
		if mj_node then
			mj_node:setPosition(cc.p(self.opposite_player_invisible_mj_offset_x_ - 
			                         MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1 * i, 
			                         MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_Y0))
			self.mahjong_layer_:addChild(mj_node)
		end
	end
end

function NormalRoomScene:showInvisibleMahjongsOfRightPlayer(play_card_msg)
	local invisible_hand_cards_size = play_card_msg:invisible_hand_cards_size()
	if 0 == invisible_hand_cards_size then
		return
	end

	self:removeAllMahjongNodes(self.invisible_mj_nodes_right_player_)

	local offset_x = self.right_player_invisible_mj_offset_x_ + MahjongConst.Sizes.CARD_OFFSET_X1 / 2
	local offset_y = self.right_player_invisible_mj_offset_y_ - MahjongConst.Sizes.CARD_OFFSET_Y1 / 2
	for i = 0,  invisible_hand_cards_size - 1 do
		local mj_node = MahjongCreator.create(MahjongConst.Directions.RIGHT, 
											  MahjongConst.Types.VISIBLE, 
											  play_card_msg:invisible_hand_cards(i))
		if mj_node then
			mj_node:setPosition(cc.p(offset_x + MahjongConst.Sizes.CARD_OFFSET_X1 * i,
			                         offset_y - MahjongConst.Sizes.CARD_OFFSET_Y1 * i))
			self.mahjong_layer_:addChild(mj_node)
		end
	end
end

function NormalRoomScene:showAvailableOperationsForPlayerSelf(play_card_msg)
	print("[NormalRoomScene:showAvailableOperationsForPlayerSelf]")
	local operation_id = play_card_msg:my_available_operation_id()
	local discard = play_card_msg:discard()
	print("[NormalRoomScene:showAvailableOperationsForPlayerSelf] operation_id : ", operation_id)
	print("[NormalRoomScene:showAvailableOperationsForPlayerSelf] discard : ", discard)
	if operation_id == CardConst.OperationIDs.OPERATION_NONE then		     -- none
		-- player self have a new card and i can't operate but discard
		print("[NormalRoomScene:showAvailableOperationsForPlayerSelf] new_card : ", play_card_msg:new_card())
		if play_card_msg:new_card() ~= CardConst.CardValues.INVALID_CARD_VALUE then
			self:dealWithNewCardOfPlayerSelf(play_card_msg:new_card())
		elseif play_card_msg:next_operate_player_id() ~= PlayerConst.INVALID_PLAYER_ID and
		       play_card_msg:has_next_operate_player_new_card() then -- means next player has got a new card
			self:dealWithNewCardOfOtherPlayer(play_card_msg)
		end
	elseif operation_id == CardConst.OperationIDs.OPERATION_CHI then         -- chi
		self:showOperationChiOnly(play_card_msg, display.bottom + 300)
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG then        -- peng
		self:showOperationPeng(play_card_msg, display.bottom + 300)
	elseif operation_id == CardConst.OperationIDs.OPERATION_CHI_OR_PENG then -- chi or peng
		self:showOperationChi(play_card_msg)
	elseif operation_id == CardConst.OperationIDs.OPERATION_CHI_OR_PENG_OR_GANG then -- chi or peng or gang
		self:showOperationChi(play_card_msg)
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG_GANG then   -- peng or gang
		self:showOperationPengGang(play_card_msg)
	elseif operation_id == CardConst.OperationIDs.OPERATION_MING_GANG then   -- ming gang
		self:showOperationMingGang(play_card_msg)
		if play_card_msg:new_card() ~= CardConst.CardValues.INVALID_CARD_VALUE then
			self:dealWithNewCardOfPlayerSelf(play_card_msg:new_card())
		end
	elseif operation_id == CardConst.OperationIDs.OPERATION_AN_GANG then     -- an gang
		self:showOperationAnGang(play_card_msg)
		if play_card_msg:new_card() ~= CardConst.CardValues.INVALID_CARD_VALUE then
			self:dealWithNewCardOfPlayerSelf(play_card_msg:new_card())
		end
	elseif operation_id == CardConst.OperationIDs.OPERATION_BU_HUA then      -- bu hua
		self:showOperationBuhua(play_card_msg)
		if play_card_msg:new_card() ~= CardConst.CardValues.INVALID_CARD_VALUE then
			self:dealWithNewCardOfPlayerSelf(play_card_msg:new_card())
		end
	elseif operation_id == CardConst.OperationIDs.OPERATION_TING then        -- ting
		self:showOperationTing(play_card_msg)
		if play_card_msg:new_card() ~= CardConst.CardValues.INVALID_CARD_VALUE then
			self:dealWithNewCardOfPlayerSelf(play_card_msg:new_card())
		end
	elseif operation_id == CardConst.OperationIDs.OPERATION_HU then          -- hu
		self:showOperationHu(play_card_msg)
	elseif operation_id == CardConst.OperationIDs.OPERATION_ZI_MO then       -- zi mo
		self:showOperationZimo(play_card_msg)
		if play_card_msg:new_card() ~= CardConst.CardValues.INVALID_CARD_VALUE then
			self:dealWithNewCardOfPlayerSelf(play_card_msg:new_card())
		end
	elseif operation_id == CardConst.OperationIDs.OPERATION_GIVE_UP then     -- guo
	end
end

function NormalRoomScene:showOperationChi(play_card_msg)
	print("[NormalRoomScene:showOperationChi]")
	local operation_id = play_card_msg:operation_id()

	if operation_id == CardConst.OperationIDs.OPERATION_CHI then
		self:showOperationChiOnly(play_card_msg, display.bottom + 300)
	elseif operation_id == CardConst.OperationIDs.OPERATION_CHI_OR_PENG then
		self:showOperationPeng(play_card_msg, display.bottom + 300)
		self:showOperationChiOnly(play_card_msg, display.bottom + 470)
	elseif operation_id == CardConst.OperationIDs.OPERATION_CHI_OR_PENG_OR_GANG then
		self:showOperationPengGang(play_card_msg, display.bottom + 300)
		self:showOperationPeng(play_card_msg, display.bottom + 470)
		self:showOperationChiOnly(play_card_msg, display.bottom + 640)
	end
end

function NormalRoomScene:showOperationChiOnly(play_card_msg, pos_y1)
	local size = play_card_msg:operating_cards_size()
	if 3 == size then
		self:showOperationForThreeMahjongs1(CardConst.OperationIDs.OPERATION_CHI, 
			"i_operation_chi.png", play_card_msg:operating_cards(0), 
			play_card_msg:operating_cards(1), play_card_msg:operating_cards(2), true, pos_y1)
	elseif 6 == size then
		self:showOperationForThreeMahjongs1(CardConst.OperationIDs.OPERATION_CHI, 
			"i_operation_chi.png", play_card_msg:operating_cards(0), 
			play_card_msg:operating_cards(1), play_card_msg:operating_cards(2), true, pos_y1)
		self:showOperationForThreeMahjongs2(CardConst.OperationIDs.OPERATION_CHI, 
			"i_operation_chi.png", play_card_msg:operating_cards(3), 
			play_card_msg:operating_cards(4), play_card_msg:operating_cards(5), true, pos_y1 + 170)
	elseif 9 == size then
		self:showOperationForThreeMahjongs1(CardConst.OperationIDs.OPERATION_CHI, 
			"i_operation_chi.png", play_card_msg:operating_cards(0), 
			play_card_msg:operating_cards(1), play_card_msg:operating_cards(2), true, pos_y1)
		self:showOperationForThreeMahjongs2(CardConst.OperationIDs.OPERATION_CHI, 
			"i_operation_chi.png", play_card_msg:operating_cards(3), 
			play_card_msg:operating_cards(4), play_card_msg:operating_cards(5), true, pos_y1 + 170)
		self:showOperationForThreeMahjongs3(CardConst.OperationIDs.OPERATION_CHI, 
			"i_operation_chi.png", play_card_msg:operating_cards(6), 
			play_card_msg:operating_cards(7), play_card_msg:operating_cards(8), true, pos_y1 + 340)
	end
end

function NormalRoomScene:showOperationPeng(play_card_msg)
	print("[NormalRoomScene:showOperationPeng]")
	self:showOperationForOneMahjong1(CardConst.OperationIDs.OPERATION_PENG, 
		"i_operation_peng.png", play_card_msg:discard(), true, display.bottom + 300)
end

function NormalRoomScene:showOperationPengGang(play_card_msg)
	print("[NormalRoomScene:showOperationPengGang]")
	self:showOperationForOneMahjong1(CardConst.OperationIDs.OPERATION_PENG_GANG, 
		"i_operation_gang.png", play_card_msg:discard(), true, display.bottom + 300)
	self:showOperationForOneMahjong2(CardConst.OperationIDs.OPERATION_PENG, 
		"i_operation_peng.png", play_card_msg:discard(), true, display.bottom + 470)
end

function NormalRoomScene:showOperationMingGang(play_card_msg)
	print("[NormalRoomScene:showOperationMingGang]")
	self:showOperationForOneMahjong1(CardConst.OperationIDs.OPERATION_MING_GANG, 
		"i_operation_gang.png", play_card_msg:new_card(), true, display.bottom + 300)
end

function NormalRoomScene:showOperationAnGang(play_card_msg)
	print("[NormalRoomScene:showOperationAnGang]")
	self:showOperationForOneMahjong1(CardConst.OperationIDs.OPERATION_AN_GANG, 
		"i_operation_gang.png", play_card_msg:new_card(), true, display.bottom + 300)
end

function NormalRoomScene:showOperationBuhua(play_card_msg)
	print("[NormalRoomScene:showOperationBuhua]")
	if play_card_msg:operating_cards_size() > 0 then
		self:showOperationForOneMahjong1(CardConst.OperationIDs.OPERATION_BU_HUA, 
			"i_operation_buhua.png", play_card_msg:operating_cards(0), false, display.bottom + 300)
	elseif play_card_msg:new_card() ~= CardConst.CardValues.INVALID_CARD_VALUE then
		self:showOperationForOneMahjong1(CardConst.OperationIDs.OPERATION_BU_HUA, 
			"i_operation_buhua.png", play_card_msg:new_card(), false, display.bottom + 300)
	end
end

function NormalRoomScene:showOperationTing(play_card_msg)
	print("[NormalRoomScene:showOperationTing]")
	if play_card_msg:ting_cards_size() > 0 then
		local ting_card = play_card_msg:ting_cards(0)

		if 1 == ting_card:cards_of_ting_size() then
			self:showOperationForOneMahjong1(CardConst.OperationIDs.OPERATION_TING, 
				"i_operation_ting.png", ting_card:cards_of_ting(0), true, display.bottom + 300)
		elseif 2 == ting_card:cards_of_ting_size() then
			self:showOperationForTwoMahjongs(CardConst.OperationIDs.OPERATION_TING, 
				"i_operation_ting.png", ting_card:cards_of_ting(0), ting_card:cards_of_ting(1), 
				true, display.bottom + 300)
		end
	end
end

function NormalRoomScene:showOperationHu(play_card_msg)
	print("[NormalRoomScene:showOperationHu]")
	self:showOperationForOneMahjong1(CardConst.OperationIDs.OPERATION_HU, 
		"i_operation_hu.png", play_card_msg:discard(), true, display.bottom + 300)
end

function NormalRoomScene:showOperationZimo(play_card_msg)
	print("[NormalRoomScene:showOperationZimo]")
	self:showOperationForOneMahjong1(CardConst.OperationIDs.OPERATION_ZI_MO, 
		"i_operation_zimo.png", play_card_msg:new_card(), true, display.bottom + 300)
end

function NormalRoomScene:hideOperations()
	if self.node_operation1_ then
		self.node_operation1_:setVisible(false)
	end

	if self.node_operation2_ then
		self.node_operation2_:setVisible(false)
	end

	if self.node_operation3_ then
		self.node_operation3_:setVisible(false)
	end

	if self.node_operation4_ then
		self.node_operation4_:setVisible(false)
	end

	if self.node_operation5_ then
		self.node_operation5_:setVisible(false)
	end

	PlayCardHelper.setHasSpecialOperation(false)
end

function NormalRoomScene:showOperationForOneMahjong1(op_id, 
	img_name_op1, mj_value, op2_visible, pos_y)

	print("[NormalRoomScene:showOperationForOneMahjong1]")
	self:addOperationAnimNode1()

	self.node_operation1_:setPosition(cc.p(display.right, pos_y))
	self.node_operation1_:setVisible(true)
	self.img_operation1_2_:setVisible(op2_visible)

	self.img_operation1_1_:setTag(op_id)
	self.img_operation1_1_:loadTexture(img_name_op1, ccui.TextureResType.plistType)
			
	self.img_operation1_mj_:loadTexture(MahjongCreator.getCardPng(mj_value), 
		                                ccui.TextureResType.plistType)
				
	self.anim_operation1_:gotoFrameAndPlay(0, false)
end

function NormalRoomScene:showOperationForOneMahjong2(op_id, 
	img_name_op1, mj_value, op2_visible, pos_y)

	print("[NormalRoomScene:showOperationForOneMahjong2]")
	self:addOperationAnimNode2()

	self.node_operation2_:setPosition(cc.p(display.right, pos_y))
	self.node_operation2_:setVisible(true)

	self.img_operation2_1_:setTag(op_id)
	self.img_operation2_1_:loadTexture(img_name_op1, ccui.TextureResType.plistType)
	self.img_operation2_2_:setVisible(op2_visible)
		
	self.img_operation2_mj_:loadTexture(MahjongCreator.getCardPng(mj_value), 
		                                ccui.TextureResType.plistType)
				
	self.anim_operation2_:gotoFrameAndPlay(0, false)
end

function NormalRoomScene:showOperationForTwoMahjongs(op_id, 
	img_name_op1, mj_value1, mj_value2, op2_visible, pos_y)

	print("[NormalRoomScene:showOperationForTwoMahjongs]")
	self:addOperationAnimNode3()

	self.node_operation3_:setPosition(cc.p(display.right, pos_y))
	self.node_operation3_:setVisible(true)

	self.img_operation3_1_:setTag(op_id)
	self.img_operation3_1_:loadTexture(img_name_op1, ccui.TextureResType.plistType)
	self.img_operation3_2_:setVisible(op2_visible)
		
	self.img_operation3_mj_1_:loadTexture(MahjongCreator.getCardPng(mj_value1), 
		                                  ccui.TextureResType.plistType)
	self.img_operation3_mj_2_:loadTexture(MahjongCreator.getCardPng(mj_value2), 
		                                  ccui.TextureResType.plistType)			
	self.anim_operation3_:gotoFrameAndPlay(0, false)
end

function NormalRoomScene:showOperationForThreeMahjongs1(op_id, 
	img_name_op1, mj_val1, mj_val2, mj_val3, op2_visible, pos_y)
	
	print("[NormalRoomScene:showOperationForThreeMahjongs1]")
	self:addOperationAnimNode4()

	self.node_operation4_:setPosition(cc.p(display.right, pos_y))
	self.node_operation4_:setVisible(true)

	self.img_operation4_1_:setTag(op_id)
	self.img_operation4_1_:loadTexture(img_name_op1, ccui.TextureResType.plistType)
	self.img_operation4_2_:setVisible(op2_visible)
		
	self.img_operation4_mj_1_:setTag(mj_val1)
	self.img_operation4_mj_2_:setTag(mj_val2)
	self.img_operation4_mj_3_:setTag(mj_val3)

	self.img_operation4_mj_1_:loadTexture(MahjongCreator.getCardPng(mj_val1), 
		                                  ccui.TextureResType.plistType)
	self.img_operation4_mj_2_:loadTexture(MahjongCreator.getCardPng(mj_val2), 
		                                  ccui.TextureResType.plistType)	
	self.img_operation4_mj_3_:loadTexture(MahjongCreator.getCardPng(mj_val3), 
	                                      ccui.TextureResType.plistType)
	
	self.anim_operation4_:gotoFrameAndPlay(0, false)
end

function NormalRoomScene:showOperationForThreeMahjongs2(op_id, 
	img_name_op1, mj_val1, mj_val2, mj_val3, op2_visible, pos_y)

	print("[NormalRoomScene:showOperationForThreeMahjongs2]")
	self:addOperationAnimNode5()

	self.node_operation5_:setPosition(cc.p(display.right, pos_y))
	self.node_operation5_:setVisible(true)

	self.img_operation5_1_:setTag(op_id)
	self.img_operation5_1_:loadTexture(img_name_op1, ccui.TextureResType.plistType)
	self.img_operation5_2_:setVisible(op2_visible)
		
	self.img_operation5_mj_1_:setTag(mj_val1)
	self.img_operation5_mj_2_:setTag(mj_val2)
	self.img_operation5_mj_3_:setTag(mj_val3)

	self.img_operation5_mj_1_:loadTexture(MahjongCreator.getCardPng(mj_val1), 
		                                  ccui.TextureResType.plistType)
	self.img_operation5_mj_2_:loadTexture(MahjongCreator.getCardPng(mj_val2), 
		                                  ccui.TextureResType.plistType)	
	self.img_operation5_mj_3_:loadTexture(MahjongCreator.getCardPng(mj_val3), 
	                                      ccui.TextureResType.plistType)
	
	self.anim_operation5_:gotoFrameAndPlay(0, false)
end

function NormalRoomScene:showOperationForThreeMahjongs3(op_id, 
	img_name_op1, mj_val1, mj_val2, mj_val3, op2_visible, pos_y)

	print("[NormalRoomScene:showOperationForThreeMahjongs3]")
	self:addOperationAnimNode6()

	self.node_operation6_:setPosition(cc.p(display.right, pos_y))
	self.node_operation6_:setVisible(true)

	self.img_operation6_1_:setTag(op_id)
	self.img_operation6_1_:loadTexture(img_name_op1, ccui.TextureResType.plistType)
	self.img_operation6_2_:setVisible(op2_visible)
		
	self.img_operation6_mj_1_:setTag(mj_val1)
	self.img_operation6_mj_2_:setTag(mj_val2)
	self.img_operation6_mj_3_:setTag(mj_val3)

	self.img_operation6_mj_1_:loadTexture(MahjongCreator.getCardPng(mj_val1), 
		                                  ccui.TextureResType.plistType)
	self.img_operation6_mj_2_:loadTexture(MahjongCreator.getCardPng(mj_val2), 
		                                  ccui.TextureResType.plistType)	
	self.img_operation6_mj_3_:loadTexture(MahjongCreator.getCardPng(mj_val3), 
	                                      ccui.TextureResType.plistType)

	self.anim_operation6_:gotoFrameAndPlay(0, false)
end

-- has 1 card image
function NormalRoomScene:addOperationAnimNode1()
	if not self.node_operation1_ then 
		local node = AnimationCreator.create(MahjongConst.AnimationIDs.ANIMATION_OPERATION1)
		self.node_operation1_ = node.root
		self.anim_operation1_ = node.animation
		self.animation_layer_:addChild(self.node_operation1_)
		self.node_operation1_:setVisible(false)

		self.node_operation1_:setPosition(cc.p(display.right, display.bottom + 300))
		self.node_operation1_:runAction(self.anim_operation1_) -- not really run until call self.anim_operation_:gotoFrameAndPlay(0, false)

		local img_bg = self.node_operation1_:getChildByName("img_operation_bg")
		self.img_operation1_1_ = img_bg:getChildByName("img_operation1")
		self.img_operation1_1_:setTouchEnabled(true)
		self.img_operation1_1_:addClickEventListener(handler(self, self.onBtnOperatoinTouch))

		self.img_operation1_mj_ = img_bg:getChildByName("img_mahjong_fg")

		self.img_operation1_2_ = img_bg:getChildByName("img_operation2")
		self.img_operation1_2_:setTag(CardConst.OperationIDs.OPERATION_GIVE_UP)
		self.img_operation1_2_:setTouchEnabled(true)
		self.img_operation1_2_:addClickEventListener(handler(self, self.onBtnOperatoinTouch))
	end
end

-- has 1 card image
function NormalRoomScene:addOperationAnimNode2()
	if not self.node_operation2_ then 
		local node = AnimationCreator.create(MahjongConst.AnimationIDs.ANIMATION_OPERATION1)
		self.node_operation2_ = node.root
		self.anim_operation2_ = node.animation
		self.animation_layer_:addChild(self.node_operation2_)
		self.node_operation2_:setVisible(false)

		self.node_operation2_:setPosition(cc.p(display.right, display.bottom + 300))
		self.node_operation2_:runAction(self.anim_operation2_) -- not really run until call self.anim_operation_:gotoFrameAndPlay(0, false)

		local img_bg = self.node_operation2_:getChildByName("img_operation_bg")
		self.img_operation2_1_ = img_bg:getChildByName("img_operation1")
		self.img_operation2_1_:setTouchEnabled(true)
		self.img_operation2_1_:addClickEventListener(handler(self, self.onBtnOperatoinTouch))

		self.img_operation2_mj_ = img_bg:getChildByName("img_mahjong_fg")

		self.img_operation2_2_ = img_bg:getChildByName("img_operation2")
		self.img_operation2_2_:setTag(CardConst.OperationIDs.OPERATION_GIVE_UP)
		self.img_operation2_2_:setTouchEnabled(true)
		self.img_operation2_2_:addClickEventListener(handler(self, self.onBtnOperatoinTouch))
	end
end

-- has 2 card images
function NormalRoomScene:addOperationAnimNode3()
	if not self.node_operation3_ then 
		local node = AnimationCreator.create(MahjongConst.AnimationIDs.ANIMATION_OPERATION2)
		self.node_operation3_ = node.root
		self.anim_operation3_ = node.animation
		self.animation_layer_:addChild(self.node_operation3_)

		self.node_operation3_:setPosition(cc.p(display.right, display.bottom + 300))
		self.node_operation3_:runAction(self.anim_operation3_) -- not really run until call self.anim_operation3_:gotoFrameAndPlay(0, false)

		local img_bg = self.node_operation3_:getChildByName("img_operation_bg")
		self.img_operation3_1_ = img_bg:getChildByName("img_operation1")
		self.img_operation3_1_:setTouchEnabled(true)
		self.img_operation3_1_:addClickEventListener(handler(self, self.onBtnOperatoinTouch))

		self.img_operation3_mj_1_ = img_bg:getChildByName("img_mahjong_fg1")
		self.img_operation3_mj_2_ = img_bg:getChildByName("img_mahjong_fg2")

		self.img_operation3_2_ = img_bg:getChildByName("img_operation2")
		self.img_operation3_2_:setTag(CardConst.OperationIDs.OPERATION_GIVE_UP)
		self.img_operation3_2_:setTouchEnabled(true)
		self.img_operation3_2_:addClickEventListener(handler(self, self.onBtnOperatoinTouch))
	end
end

-- has 3 card image3
function NormalRoomScene:addOperationAnimNode4()
	if not self.node_operation4_ then 
		local node = AnimationCreator.create(MahjongConst.AnimationIDs.ANIMATION_OPERATION3)
		self.node_operation4_ = node.root
		self.anim_operation4_ = node.animation
		self.animation_layer_:addChild(self.node_operation4_)

		self.node_operation4_:setPosition(cc.p(display.right, display.bottom + 300))			
		self.node_operation4_:runAction(self.anim_operation4_) -- not really run until call self.anim_operation_:gotoFrameAndPlay(0, false)

		local img_bg = self.node_operation4_:getChildByName("img_operation_bg")
		self.img_operation4_1_ = img_bg:getChildByName("img_operation1")
		self.img_operation4_1_:setTouchEnabled(true)
		self.img_operation4_1_:addClickEventListener(handler(self, self.onBtnOperatoinTouch))

		self.img_operation4_2_ = img_bg:getChildByName("img_operation2")
		self.img_operation4_2_:setTag(CardConst.OperationIDs.OPERATION_GIVE_UP)
		self.img_operation4_2_:setTouchEnabled(true)
		self.img_operation4_2_:addClickEventListener(handler(self, self.onBtnOperatoinTouch))

		self.img_operation4_mj_1_ = img_bg:getChildByName("img_mahjong_fg1")
		self.img_operation4_mj_2_ = img_bg:getChildByName("img_mahjong_fg2")
		self.img_operation4_mj_3_ = img_bg:getChildByName("img_mahjong_fg3")
	end
end

-- has 3 card image3
function NormalRoomScene:addOperationAnimNode5()
	if not self.node_operation5_ then 
		local node = AnimationCreator.create(MahjongConst.AnimationIDs.ANIMATION_OPERATION3)
		self.node_operation5_ = node.root
		self.anim_operation5_ = node.animation
		self.animation_layer_:addChild(self.node_operation5_)

		self.node_operation5_:setPosition(cc.p(display.right, display.bottom + 300))			
		self.node_operation5_:runAction(self.anim_operation5_) -- not really run until call self.anim_operation_:gotoFrameAndPlay(0, false)

		local img_bg = self.node_operation5_:getChildByName("img_operation_bg")
		self.img_operation5_1_ = img_bg:getChildByName("img_operation1")
		self.img_operation5_1_:setTouchEnabled(true)
		self.img_operation5_1_:addClickEventListener(handler(self, self.onBtnOperatoinTouch))

		self.img_operation5_2_ = img_bg:getChildByName("img_operation2")
		self.img_operation5_2_:setTag(CardConst.OperationIDs.OPERATION_GIVE_UP)
		self.img_operation5_2_:setTouchEnabled(true)
		self.img_operation5_2_:addClickEventListener(handler(self, self.onBtnOperatoinTouch))

		self.img_operation5_mj_1_ = img_bg:getChildByName("img_mahjong_fg1")
		self.img_operation5_mj_2_ = img_bg:getChildByName("img_mahjong_fg2")
		self.img_operation5_mj_3_ = img_bg:getChildByName("img_mahjong_fg3")
	end
end

-- has 3 card image3
function NormalRoomScene:addOperationAnimNode6()
	if not self.node_operation6_ then 
		local node = AnimationCreator.create(MahjongConst.AnimationIDs.ANIMATION_OPERATION3)
		self.node_operation6_ = node.root
		self.anim_operation6_ = node.animation
		self.animation_layer_:addChild(self.node_operation6_)

		self.node_operation6_:setPosition(cc.p(display.right, display.bottom + 300))			
		self.node_operation6_:runAction(self.anim_operation6_) -- not really run until call self.anim_operation_:gotoFrameAndPlay(0, false)

		local img_bg = self.node_operation6_:getChildByName("img_operation_bg")
		self.img_operation6_1_ = img_bg:getChildByName("img_operation1")
		self.img_operation6_1_:setTouchEnabled(true)
		self.img_operation6_1_:addClickEventListener(handler(self, self.onBtnOperatoinTouch))

		self.img_operation6_2_ = img_bg:getChildByName("img_operation2")
		self.img_operation6_2_:setTag(CardConst.OperationIDs.OPERATION_GIVE_UP)
		self.img_operation6_2_:setTouchEnabled(true)
		self.img_operation6_2_:addClickEventListener(handler(self, self.onBtnOperatoinTouch))

		self.img_operation6_mj_1_ = img_bg:getChildByName("img_mahjong_fg1")
		self.img_operation6_mj_2_ = img_bg:getChildByName("img_mahjong_fg2")
		self.img_operation6_mj_3_ = img_bg:getChildByName("img_mahjong_fg3")
	end
end

function NormalRoomScene:showAnimationForPlayerOperation(player_id, operation_id)
	print("[NormalRoomScene:showAnimationForPlayerOperation]")
	local direction = PlayCardHelper.getPlayerDirection(player_id)
	local anim_node = nil
	
	if operation_id == CardConst.OperationIDs.OPERATION_CHI then           -- chi
		if not self.node_anim_chi_ then
			self.node_anim_chi_ = AnimationCreator.create(MahjongConst.AnimationIDs.ANIMATION_CHI)
			self.animation_layer_:addChild(self.node_anim_chi_.root)
			self.node_anim_chi_.root:runAction(self.node_anim_chi_.animation) -- not really run until call gotoFrameAndPlay(0, false)
		end
		anim_node = self.node_anim_chi_
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG then      -- peng
		if not self.node_anim_peng_ then
			self.node_anim_peng_ = AnimationCreator.create(MahjongConst.AnimationIDs.ANIMATION_PENG)
			self.animation_layer_:addChild(self.node_anim_peng_.root)
			self.node_anim_peng_.root:runAction(self.node_anim_peng_.animation) -- not really run until call gotoFrameAndPlay(0, false)
		end
		anim_node = self.node_anim_peng_
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG_GANG then -- peng gang
		if not self.node_anim_gang_ then
			self.node_anim_gang_ = AnimationCreator.create(MahjongConst.AnimationIDs.ANIMATION_GANG)
			self.animation_layer_:addChild(self.node_anim_gang_.root)
			self.node_anim_gang_.root:runAction(self.node_anim_gang_.animation) -- not really run until call gotoFrameAndPlay(0, false)
		end
		anim_node = self.node_anim_gang_
	elseif operation_id == CardConst.OperationIDs.OPERATION_MING_GANG then -- ming gang
		if not self.node_anim_gang_ then
			self.node_anim_gang_ = AnimationCreator.create(MahjongConst.AnimationIDs.ANIMATION_GANG)
			self.animation_layer_:addChild(self.node_anim_gang_.root)
			self.node_anim_gang_.root:runAction(self.node_anim_gang_.animation) -- not really run until call gotoFrameAndPlay(0, false)
		end
		anim_node = self.node_anim_gang_
	elseif operation_id == CardConst.OperationIDs.OPERATION_AN_GANG then   -- an gang
		if not self.node_anim_gang_ then
			self.node_anim_gang_ = AnimationCreator.create(MahjongConst.AnimationIDs.ANIMATION_GANG)
			self.animation_layer_:addChild(self.node_anim_gang_.root)
			self.node_anim_gang_.root:runAction(self.node_anim_gang_.animation) -- not really run until call gotoFrameAndPlay(0, false)
		end
		anim_node = self.node_anim_gang_
	elseif operation_id == CardConst.OperationIDs.OPERATION_BU_HUA then    -- bu hua
		if not self.node_anim_buhua_ then
			self.node_anim_buhua_ = AnimationCreator.create(MahjongConst.AnimationIDs.ANIMATION_BUHUA)
			self.animation_layer_:addChild(self.node_anim_buhua_.root)
			self.node_anim_buhua_.root:runAction(self.node_anim_buhua_.animation) -- not really run until call gotoFrameAndPlay(0, false)
		end
		anim_node = self.node_anim_buhua_
	elseif operation_id == CardConst.OperationIDs.OPERATION_TING then      -- ting
		if not self.node_anim_ting_ then
			self.node_anim_ting_ = AnimationCreator.create(MahjongConst.AnimationIDs.ANIMATION_TING)
			self.animation_layer_:addChild(self.node_anim_ting_.root)
			self.node_anim_ting_.root:runAction(self.node_anim_ting_.animation) -- not really run until call gotoFrameAndPlay(0, false)
		end
		anim_node = self.node_anim_ting_
	elseif operation_id == CardConst.OperationIDs.OPERATION_HU then        -- hu
		if not self.node_anim_hu_ then
			self.node_anim_hu_ = AnimationCreator.create(MahjongConst.AnimationIDs.ANIMATION_HU)
			self.animation_layer_:addChild(self.node_anim_hu_.root)
			self.node_anim_hu_.root:runAction(self.node_anim_hu_.animation) -- not really run until call gotoFrameAndPlay(0, false)
		end
		anim_node = self.node_anim_hu_
	elseif operation_id == CardConst.OperationIDs.OPERATION_ZI_MO then     -- zi mo
		if not self.node_anim_zimo_ then
			self.node_anim_zimo_ = AnimationCreator.create(MahjongConst.AnimationIDs.ANIMATION_ZIMO)
			self.animation_layer_:addChild(self.node_anim_zimo_.root)
			self.node_anim_zimo_.root:runAction(self.node_anim_zimo_.animation) -- not really run until call gotoFrameAndPlay(0, false)
		end
		anim_node = self.node_anim_zimo_
	end

	if anim_node then
		print("[NormalRoomScene:showAnimationForPlayerOperation] 2")
		if direction == MahjongConst.Directions.SELF then
			anim_node.root:setPosition(cc.p(display.cx, MahjongConst.Sizes.PLAYER_SELF_OPERATION_ANIM_Y))
		elseif direction == MahjongConst.Directions.LEFT then
			anim_node.root:setPosition(cc.p(MahjongConst.Sizes.LEFT_PLAYER_OPERATION_ANIM_X, display.cy))
		elseif direction == MahjongConst.Directions.OPPOSITE then
			anim_node.root:setPosition(cc.p(display.cx, MahjongConst.Sizes.OPPOSITE_PLAYER_OPERATION_ANIM_Y))
		elseif direction == MahjongConst.Directions.RIGHT then
			anim_node.root:setPosition(cc.p(MahjongConst.Sizes.RIGHT_PLAYER_OPERATION_ANIM_X, display.cy))	
		end
		anim_node.animation:gotoFrameAndPlay(0, false)
	end
end

function NormalRoomScene:showNewCardOfPlayerSelf(mahjong_value)
	local mj_node = MahjongCreator.create(MahjongConst.Directions.SELF, 
										  MahjongConst.Types.INVISIBLE, 
										  mahjong_value)
    if mj_node then
		local n = #self.invisible_mj_nodes_player_self_
		mj_node:setPosition(cc.p(self.player_self_invisible_mj_offset_x_ + MahjongConst.Sizes.CARD_W2 * (n + 0.5), 
	                             MahjongConst.Sizes.OFFSET_Y3))
		self.mahjong_layer_:addChild(mj_node)

		local img_bg = mj_node:getChildByName("img_bg")
		img_bg:setTouchEnabled(true)
		img_bg:addClickEventListener(handler(self, self.onMahjongNodeTouch))

		table.insert(self.invisible_mj_nodes_player_self_, mj_node)
		return true
	else
		print("[NormalRoomScene:showNewCardOfPlayerSelf] failed!")
	end
	return false
end

function NormalRoomScene:showDiscardOfPlayerSelf(mahjong_value)
	local mj = MahjongCreator.create(MahjongConst.Directions.SELF, 
									 MahjongConst.Types.VISIBLE_DISCARD, 
									 mahjong_value)
	if mj then
		local x, y = self:getNextDiscardPosOfPlayerSelf()
		mj:setPosition(cc.p(x, y))
		self.mahjong_layer_:addChild(mj)

		self.player_self_second_to_last_discard_ = self.player_self_last_discard_
		self.player_self_last_discard_ = mj
	end
end

function NormalRoomScene:showDiscardOfLeftPlayer(mahjong_value)
	local mj = MahjongCreator.create(MahjongConst.Directions.LEFT, 
									 MahjongConst.Types.VISIBLE_DISCARD, 
									 mahjong_value)
	if mj then
		local x, y = self:getNextDiscardPosOfLeftPlayer()
		local zorder = 1

		if self.left_player_last_discard_ then
			zorder = self.left_player_last_discard_:getLocalZOrder() + 1
		end

		if y == MahjongConst.Sizes.LEFT_DISCARD_Y1 then
			zorder = MahjongConst.ZOrders.DISCARD_LINE_1
		elseif y == MahjongConst.Sizes.LEFT_DISCARD_Y2 then
			zorder = MahjongConst.ZOrders.DISCARD_LINE_2
		elseif y == MahjongConst.Sizes.LEFT_DISCARD_Y3 then
			zorder = MahjongConst.ZOrders.DISCARD_LINE_3
		elseif y == MahjongConst.Sizes.LEFT_DISCARD_Y4 then
			zorder = MahjongConst.ZOrders.DISCARD_LINE_4
		end

		mj:setPosition(cc.p(x, y))
		mj:setLocalZOrder(zorder)
		self.mahjong_layer_:addChild(mj)

		self.left_player_second_to_last_discard_ = self.left_player_last_discard_
		self.left_player_last_discard_ = mj
	end
end

function NormalRoomScene:showDiscardOfOppositePlayer(mahjong_value)
	local mj = MahjongCreator.create(MahjongConst.Directions.OPPOSITE, 
									 MahjongConst.Types.VISIBLE_DISCARD, 
									 mahjong_value)
	if mj then
		local x, y = self:getNextDiscardPosOfOppositePlayer()
		mj:setPosition(cc.p(x, y))
		self.mahjong_layer_:addChild(mj)

		self.opposite_player_second_to_last_discard_ = self.opposite_player_last_discard_
		self.opposite_player_last_discard_ = mj
	end
end

function NormalRoomScene:showDiscardOfRightPlayer(mahjong_value)
	local mj = MahjongCreator.create(MahjongConst.Directions.RIGHT, 
									 MahjongConst.Types.VISIBLE_DISCARD, 
									 mahjong_value)
	if mj then
		local x, y = self:getNextDiscardPosOfRightPlayer()
		mj:setPosition(cc.p(x, y))
		self.mahjong_layer_:addChild(mj)

		self.right_player_second_to_last_discard_ = self.right_player_last_discard_
		self.right_player_last_discard_ = mj
	end
end

function NormalRoomScene:dealWithNewCardOfPlayerSelf(new_card)
	print("[NormalRoomScene:dealWithNewCardOfPlayerSelf]")
	print("[NormalRoomScene:dealWithNewCardOfPlayerSelf] new card : ", new_card)
	self:showNewCardOfPlayerSelf(new_card)
	self:updateRemainCardsNum(false)
end

function NormalRoomScene:dealWithNewCardOfOtherPlayer(play_card_msg)
	local direction = PlayCardHelper.getPlayerDirection(play_card_msg:next_operate_player_id())
	print("[NormalRoomScene:dealWithNewCardOfOtherPlayer] direction : ", direction)
	if direction == MahjongConst.Directions.LEFT then
		-- add mahjong(invisible) node
		local n = #self.invisible_mj_nodes_left_player_
		if 1 == (n % 3) then -- make sure num of invisible card nodes is correct after add one
			local x, y = self.invisible_mj_nodes_left_player_[n]:getPosition()
			local mj_node = MahjongCreator.create(MahjongConst.Directions.LEFT, MahjongConst.Types.INVISIBLE)
			mj_node:setPosition(cc.p(x - MahjongConst.Sizes.CARD_OFFSET_X1 * 1.5, 
									 y - MahjongConst.Sizes.CARD_OFFSET_Y1 * 1.5))
			self.mahjong_layer_:addChild(mj_node)
			table.insert(self.invisible_mj_nodes_left_player_, mj_node)
		end
	elseif direction == MahjongConst.Directions.OPPOSITE then
		-- add mahjong(invisible) node
		local n = #self.invisible_mj_nodes_opposite_player_
		if 1 == (n % 3) then -- make sure num of invisible card nodes is correct after add one
			local x = self.invisible_mj_nodes_opposite_player_[n]:getPositionX()
			local mj_node = MahjongCreator.create(MahjongConst.Directions.OPPOSITE, MahjongConst.Types.INVISIBLE)
			mj_node:setPosition(cc.p(x - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X2 -
									 MahjongConst.Sizes.CARD_INTERVAL2, 
									 MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_Y0))
			self.mahjong_layer_:addChild(mj_node)
			table.insert(self.invisible_mj_nodes_opposite_player_, mj_node)
		end
	elseif direction == MahjongConst.Directions.RIGHT then
		-- add mahjong(invisible) node
		local n = #self.invisible_mj_nodes_right_player_
		if 1 == (n % 3) then -- make sure num of invisible card nodes is correct after add one
			local x, y = self.invisible_mj_nodes_right_player_[n]:getPosition()
			local mj_node = MahjongCreator.create(MahjongConst.Directions.RIGHT, MahjongConst.Types.INVISIBLE)
			mj_node:setPosition(cc.p(x + MahjongConst.Sizes.CARD_OFFSET_X1 * 1.5, 
									 y - MahjongConst.Sizes.CARD_OFFSET_Y1 * 1.5))
			self.mahjong_layer_:addChild(mj_node)
			table.insert(self.invisible_mj_nodes_right_player_, mj_node)
		end
	end

	self:showFlagForOperatingPlayer()
	self:updateRemainCardsNum(false)
end

function NormalRoomScene:dealWithOtherPlayerOperationDiscard(play_card_msg)
	print("[NormalRoomScene:dealWithOtherPlayerOperationDiscard]")
	-- play play card effect music
	gamer.audio_mgr_.playEffectMusicForPlayCard(play_card_msg:discard())

	self:modifyMahjongsOfOtherPlayerAfterDiscard(play_card_msg)
	self:showAvailableOperationsForPlayerSelf(play_card_msg)
	self:showFlagForOperatingPlayer()
end

function NormalRoomScene:dealWithOtherPlayerOperationChi(play_card_msg)
	print("[NormalRoomScene:dealWithOtherPlayerOperationChi]")
	self:showAnimationForPlayerOperation(play_card_msg:player_id(), play_card_msg:operation_id())
	self:showFlagForOperatingPlayer()
	self:modifyMahjongsOfOtherPlayerAfterOperation()
end

function NormalRoomScene:dealWithOtherPlayerOperationPeng(play_card_msg)
	print("[NormalRoomScene:dealWithOtherPlayerOperationPeng]")
	self:showAnimationForPlayerOperation(play_card_msg:player_id(), play_card_msg:operation_id())
	self:showFlagForOperatingPlayer()
	self:modifyMahjongsOfOtherPlayerAfterOperation()
end

function NormalRoomScene:dealWithOtherPlayerOperationPengGang(play_card_msg)
	print("[NormalRoomScene:dealWithOtherPlayerOperationPengGang]")
	self:showAnimationForPlayerOperation(play_card_msg:player_id(), play_card_msg:operation_id())
	self:modifyMahjongsOfOtherPlayerAfterOperation()
	self:dealWithNewCardOfOtherPlayer(play_card_msg)
end

function NormalRoomScene:dealWithOtherPlayerOperationMingGang(play_card_msg)
	print("[NormalRoomScene:dealWithOtherPlayerOperationMingGang]")
	self:showAnimationForPlayerOperation(play_card_msg:player_id(), play_card_msg:operation_id())
	self:modifyMahjongsOfOtherPlayerAfterOperation()
end

function NormalRoomScene:dealWithOtherPlayerOperationAnGang(play_card_msg)
	print("[NormalRoomScene:dealWithOtherPlayerOperationAnGang]")
	self:showAnimationForPlayerOperation(play_card_msg:player_id(), play_card_msg:operation_id())
	self:modifyMahjongsOfOtherPlayerAfterOperation()
end

function NormalRoomScene:dealWithOtherPlayerOperationBuhua(play_card_msg)
	print("[NormalRoomScene:dealWithOtherPlayerOperationBuhua]")
	self:showAnimationForPlayerOperation(play_card_msg:player_id(), play_card_msg:operation_id())
	self:modifyMahjongsOfOtherPlayerAfterOperation()
end

function NormalRoomScene:dealWithOtherPlayerOperationTing(play_card_msg)
	print("[NormalRoomScene:dealWithOtherPlayerOperationTing]")
	self:showAnimationForPlayerOperation(play_card_msg:player_id(), play_card_msg:operation_id())
	-- TODO : update ting flag
end

function NormalRoomScene:dealWithOtherPlayerOperationHu(play_card_msg)
	print("[NormalRoomScene:dealWithOtherPlayerOperationHu]")
	self:stopPlayCardTimer()
	self:showAnimationForPlayerOperation(play_card_msg:player_id(), play_card_msg:operation_id())
	self:showInvisibleMahjongsForGameEnd(play_card_msg)
end

function NormalRoomScene:dealWithOtherPlayerOperationZimo(play_card_msg)
	print("[NormalRoomScene:dealWithOtherPlayerOperationZimo]")
	self:stopPlayCardTimer()
	self:showAnimationForPlayerOperation(play_card_msg:player_id(), play_card_msg:operation_id())
	self:showInvisibleMahjongsForGameEnd(play_card_msg)
end

function NormalRoomScene:dealWithOtherPlayerOperationGiveup(play_card_msg)
	print("[NormalRoomScene:dealWithOtherPlayerOperationGiveup]")
	local player_id = play_card_msg:next_operate_player_id()
	if player_id ~= PlayerConst.INVALID_PLAYER_ID and player_id ~= gamer.data_mgr_:self_player_id() then 
		-- means next player has got a new card
		if play_card_msg:has_next_operate_player_new_card() then
			self:dealWithNewCardOfOtherPlayer(play_card_msg)
		end
	end
end

function NormalRoomScene:dealWithPlayerSelfOperationDiscard(play_card_msg)
	if play_card_msg:next_operate_player_id() ~= PlayerConst.INVALID_PLAYER_ID and
		play_card_msg:has_next_operate_player_new_card() then -- means next player has got a new card
		self:dealWithNewCardOfOtherPlayer(play_card_msg)
	end
end

function NormalRoomScene:dealWithPlayerSelfOperationChi(play_card_msg)

end

function NormalRoomScene:dealWithPlayerSelfOperationPeng(play_card_msg)

end

function NormalRoomScene:dealWithPlayerSelfOperationPengGang(play_card_msg)
	self:showFlagForOperatingPlayer()
	self:showAvailableOperationsForPlayerSelf(play_card_msg)
end

function NormalRoomScene:dealWithPlayerSelfOperationMingGang(play_card_msg)
	if play_card_msg:new_card() ~= CardConst.CardValues.INVALID_CARD_VALUE then
		self:dealWithNewCardOfPlayerSelf(play_card_msg:new_card())
		self:startPlayCardTimer()
	end
end

function NormalRoomScene:dealWithPlayerSelfOperationAnGang(play_card_msg)
	if play_card_msg:new_card() ~= CardConst.CardValues.INVALID_CARD_VALUE then
		self:dealWithNewCardOfPlayerSelf(play_card_msg:new_card())
		self:startPlayCardTimer()
	end
end

function NormalRoomScene:dealWithPlayerSelfOperationBuhua(play_card_msg)
	self:showAvailableOperationsForPlayerSelf(play_card_msg)
	
	if play_card_msg:operating_cards_size() > 0 then
		-- after buhua, player self get some new cards whose stored in operating_cards
		-- 1.show new cards
		self:removeAllMahjongNodes(self.invisible_mj_nodes_player_self_)
		self:initInvisibleMahjongsOfPlayerSelf()
		-- 2.modify last new card position x
		local n = #self.invisible_mj_nodes_player_self_
		local x = self.invisible_mj_nodes_player_self_[n]:getPositionX()
		self.invisible_mj_nodes_player_self_[n]:setPositionX(x + MahjongConst.Sizes.CARD_INTERVAL3)

		self:startPlayCardTimer()
	end
end

function NormalRoomScene:dealWithPlayerSelfOperationTing(play_card_msg)
	if play_card_msg:new_card() ~= CardConst.CardValues.INVALID_CARD_VALUE then
		self:dealWithNewCardOfPlayerSelf(play_card_msg:new_card())
		self:startPlayCardTimer()
	end
end

function NormalRoomScene:dealWithPlayerSelfOperationHu(play_card_msg)

end

function NormalRoomScene:dealWithPlayerSelfOperationZimo(play_card_msg)

end

function NormalRoomScene:dealWithPlayerSelfOperationGiveup(play_card_msg)
	if play_card_msg:next_operate_player_id() == gamer.data_mgr_:self_player_id() then
		self:showAvailableOperationsForPlayerSelf(play_card_msg)
	end
end

function NormalRoomScene:doPlayerSelfOperationDiscard(mahjong_value)
	-- check mahjong value validity
	if not PlayCardHelper.isMahongValueValid(mahjong_value) then
		print("[NormalRoomScene:doPlayerSelfOperationDiscard] mahjong_value invalid!")
		return
	end

	-- play play card effect music
	gamer.audio_mgr_.playEffectMusicForPlayCard(mahjong_value)

	-- modify mahjongs
	self:modifyMahjongsOfPlayerSelfAfterDiscard(mahjong_value)

	-- send play mahjong msg 
	gamer.msg_helper_.sendPlayCardMsg(CardConst.OperationIDs.OPERATION_DISCARD, mahjong_value)
	-- clear cur operating player id
	gamer.data_mgr_:play_card_msg_protocol():set_next_operate_player_id(PlayerConst.INVALID_PLAYER_ID)
	
	-- start play card timer and show direction of next player
	self:showNextPlayCardDirectionAfterPlayerSelf()
	self:startPlayCardTimer()
end

function NormalRoomScene:doPlayerSelfOperationChi(sender)
	self:hideOperations()

	-- get cards of chi to send chi msg
	local cards = {}
	local parent = sender:getParent()
	cards[1] = parent:getChildByName("img_mahjong_fg1"):getTag()
	cards[2] = parent:getChildByName("img_mahjong_fg2"):getTag()
	cards[3] = parent:getChildByName("img_mahjong_fg3"):getTag()

	self:modifyMahjongsOfPlayerSelfAfterChi(cards)
	gamer.msg_helper_.sendPlayCardMsg(CardConst.OperationIDs.OPERATION_CHI, cards)

	self:showAnimationForPlayerOperation(gamer.data_mgr_:self_player_id(), 
	                                     CardConst.OperationIDs.OPERATION_CHI)
end

function NormalRoomScene:doPlayerSelfOperationPeng()
	self:hideOperations()
	self:modifyMahjongsOfPlayerSelfAfterPeng()
	self:showAnimationForPlayerOperation(gamer.data_mgr_:self_player_id(), 
	                                     CardConst.OperationIDs.OPERATION_PENG)

	gamer.msg_helper_.sendPlayCardMsg(CardConst.OperationIDs.OPERATION_PENG, 
	                     gamer.data_mgr_:play_card_msg_protocol():discard())
end

function NormalRoomScene:doPlayerSelfOperationPengGang()
	self:hideOperations()
	self:modifyMahjongsOfPlayerSelfAfterPengGang()
	self:showAnimationForPlayerOperation(gamer.data_mgr_:self_player_id(), 
	                                     CardConst.OperationIDs.OPERATION_PENG_GANG)

	gamer.msg_helper_.sendPlayCardMsg(CardConst.OperationIDs.OPERATION_PENG_GANG, 
	                     gamer.data_mgr_:play_card_msg_protocol():discard())
end

function NormalRoomScene:doPlayerSelfOperationMingGang()
	self:hideOperations()
	self:modifyMahjongsOfPlayerSelfAfterMingGang()
	self:showAnimationForPlayerOperation(gamer.data_mgr_:self_player_id(), 
	                                     CardConst.OperationIDs.OPERATION_MING_GANG)

	gamer.msg_helper_.sendPlayCardMsg(CardConst.OperationIDs.OPERATION_MING_GANG, 
	                     gamer.data_mgr_:play_card_msg_protocol():new_card())
end

function NormalRoomScene:doPlayerSelfOperationAnGang()
	self:hideOperations()
	self:modifyMahjongsOfPlayerSelfAfterAnGang()
	self:showAnimationForPlayerOperation(gamer.data_mgr_:self_player_id(), 
	                                     CardConst.OperationIDs.OPERATION_AN_GANG)

	gamer.msg_helper_.sendPlayCardMsg(CardConst.OperationIDs.OPERATION_AN_GANG, 
	                     gamer.data_mgr_:play_card_msg_protocol():new_card())
end

function NormalRoomScene:doPlayerSelfOperationBuhua()
	self:hideOperations()
	self:modifyMahjongsOfPlayerSelfAfterBuhua()
	self:showAnimationForPlayerOperation(gamer.data_mgr_:self_player_id(), 
	                                     CardConst.OperationIDs.OPERATION_BU_HUA)

	gamer.msg_helper_.sendPlayCardMsg(CardConst.OperationIDs.OPERATION_BU_HUA, 
	                     gamer.data_mgr_:play_card_msg_protocol():new_card())
end

function NormalRoomScene:doPlayerSelfOperationTing()
	self:hideOperations()
	self:showAnimationForPlayerOperation(gamer.data_mgr_:self_player_id(), 
	                                     CardConst.OperationIDs.OPERATION_TING)
	
	local play_card_proto = gamer.data_mgr_:play_card_msg_protocol()
	if play_card_proto:ting_cards_size() > 0 then
		local discard = play_card_proto:ting_cards(0):discard()

		self:modifyMahjongsOfPlayerSelfAfterDiscard(discard)
		-- TODO : update ting flag
		-- clear cur operating player id
		gamer.data_mgr_:play_card_msg_protocol():set_next_operate_player_id(PlayerConst.INVALID_PLAYER_ID)
	
		-- start play card timer and show direction of next player
		self:showNextPlayCardDirectionAfterPlayerSelf()
		self:startPlayCardTimer()

		gamer.msg_helper_.sendPlayCardMsg(CardConst.OperationIDs.OPERATION_TING, discard)
	end
end

function NormalRoomScene:doPlayerSelfOperationHu()
	self:hideOperations()
	self:stopPlayCardTimer()
	self:showAnimationForPlayerOperation(gamer.data_mgr_:self_player_id(), 
	                                     CardConst.OperationIDs.OPERATION_HU)
	self:showInvisibleMahjongsForGameEnd()		

	gamer.msg_helper_.sendPlayCardMsg(CardConst.OperationIDs.OPERATION_HU, 
	                     gamer.data_mgr_:play_card_msg_protocol():discard())
end

function NormalRoomScene:doPlayerSelfOperationZimo()
	self:hideOperations()
	self:stopPlayCardTimer()
	self:showAnimationForPlayerOperation(gamer.data_mgr_:self_player_id(), 
	                                     CardConst.OperationIDs.OPERATION_ZI_MO)
	self:showInvisibleMahjongsForGameEnd()
	
	gamer.msg_helper_.sendPlayCardMsg(CardConst.OperationIDs.OPERATION_ZI_MO)
end

function NormalRoomScene:doPlayerSelfOperationGiveup()
	self:hideOperations()
	gamer.msg_helper_.sendPlayCardMsg(CardConst.OperationIDs.OPERATION_GIVE_UP, 
	                     gamer.data_mgr_:play_card_msg_protocol():discard())
end

function NormalRoomScene:dealWithPlayCardMsgOfOtherPlayer(msg)
	print("[NormalRoomScene:dealWithPlayCardMsgOfOtherPlayer]")
	local operation_id = msg:operation_id()
	print("[NormalRoomScene:dealWithPlayCardMsgOfOtherPlayer] operation_id : ", operation_id)
	if operation_id == CardConst.OperationIDs.OPERATION_DISCARD then       -- discard
		-- show other player's discard and show available operations with that card
		gamer.writelog("[NormalRoomScene:dealWithPlayCardMsgOfOtherPlayer] OPERATION_DISCARD")
		self:dealWithOtherPlayerOperationDiscard(msg)	
	elseif operation_id == CardConst.OperationIDs.OPERATION_CHI then       -- chi
		gamer.audio_mgr_.playEffectMusicForPlayCard(gamer.audio_mgr_.Operations.CHI)
		self:dealWithOtherPlayerOperationChi(msg)
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG then      -- peng
		gamer.audio_mgr_.playEffectMusicForPlayCard(gamer.audio_mgr_.Operations.PENG)
		self:dealWithOtherPlayerOperationPeng(msg)
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG_GANG then -- peng gang
		gamer.audio_mgr_.playEffectMusicForPlayCard(gamer.audio_mgr_.Operations.GANG)
		self:dealWithOtherPlayerOperationPengGang(msg)
	elseif operation_id == CardConst.OperationIDs.OPERATION_MING_GANG then -- ming gang
		gamer.audio_mgr_.playEffectMusicForPlayCard(gamer.audio_mgr_.Operations.GANG)
		self:dealWithOtherPlayerOperationMingGang(msg)
	elseif operation_id == CardConst.OperationIDs.OPERATION_AN_GANG then   -- an gang
		gamer.audio_mgr_.playEffectMusicForPlayCard(gamer.audio_mgr_.Operations.GANG)
		self:dealWithOtherPlayerOperationAnGang(msg)
	elseif operation_id == CardConst.OperationIDs.OPERATION_BU_HUA then    -- bu hua
		-- after bu hua, player have a new card
		if msg:has_next_operate_player_new_card() then
			gamer.audio_mgr_.playEffectMusicForPlayCard(gamer.audio_mgr_.Operations.BUHUA)
			self:dealWithOtherPlayerOperationBuhua(msg)
		end
	elseif operation_id == CardConst.OperationIDs.OPERATION_TING then      -- ting
		gamer.writelog("[NormalRoomScene:dealWithPlayCardMsgOfOtherPlayer] OPERATION_TING")
		gamer.audio_mgr_.playEffectMusicForPlayCard(gamer.audio_mgr_.Operations.TING)
		self:dealWithOtherPlayerOperationTing(msg)
	elseif operation_id == CardConst.OperationIDs.OPERATION_HU then        -- hu
		gamer.audio_mgr_.playEffectMusicForPlayCard(gamer.audio_mgr_.Operations.HU)
		self:dealWithOtherPlayerOperationHu(msg)
	elseif operation_id == CardConst.OperationIDs.OPERATION_ZI_MO then     -- zi mo
		gamer.audio_mgr_.playEffectMusicForPlayCard(gamer.audio_mgr_.Operations.ZIMO)
		self:dealWithOtherPlayerOperationZimo(msg)
	elseif operation_id == CardConst.OperationIDs.OPERATION_GIVE_UP then   -- guo
		print("[NormalRoomScene:dealWithPlayCardMsgOfOtherPlayer] next_operate_player_id : ", msg:next_operate_player_id())
		print("[NormalRoomScene:dealWithPlayCardMsgOfOtherPlayer] self_player_id : ", gamer.data_mgr_:self_player_id())
		print("[NormalRoomScene:dealWithPlayCardMsgOfOtherPlayer] has_next_operate_player_new_card : ", tostring(msg:has_next_operate_player_new_card()))
		--gamer.audio_mgr_.playEffectMusicForPlayCard(gamer.audio_mgr_.Operations.GUO)
		self:dealWithOtherPlayerOperationGiveup(msg)
	end
end

function NormalRoomScene:dealWithPlayCardMsgOfPlayerSelf(msg)
	print("[NormalRoomScene:dealWithPlayCardMsgOfPlayerSelf]")
	local operation_id = msg:operation_id()
	print("[NormalRoomScene:dealWithPlayCardMsgOfPlayerSelf] operation_id : ", operation_id)
	print("[NormalRoomScene:dealWithPlayCardMsgOfPlayerSelf] next_operate_player_id : ", msg:next_operate_player_id())
	if operation_id == CardConst.OperationIDs.OPERATION_DISCARD then       -- discard
		self:dealWithPlayerSelfOperationDiscard(msg)
	elseif operation_id == CardConst.OperationIDs.OPERATION_CHI then       -- chi
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG then      -- peng
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG_GANG then -- peng gang
		self:dealWithPlayerSelfOperationPengGang(msg)
	elseif operation_id == CardConst.OperationIDs.OPERATION_MING_GANG then -- ming gang
		self:dealWithPlayerSelfOperationMingGang(msg)
	elseif operation_id == CardConst.OperationIDs.OPERATION_AN_GANG then   -- an gang
		self:dealWithPlayerSelfOperationAnGang(msg)
	elseif operation_id == CardConst.OperationIDs.OPERATION_BU_HUA then    -- bu hua
		self:dealWithPlayerSelfOperationBuhua(msg)
	elseif operation_id == CardConst.OperationIDs.OPERATION_TING then      -- ting
	elseif operation_id == CardConst.OperationIDs.OPERATION_HU then        -- hu
	elseif operation_id == CardConst.OperationIDs.OPERATION_ZI_MO then     -- zi mo
	elseif operation_id == CardConst.OperationIDs.OPERATION_GIVE_UP then   -- guo
		self:dealWithPlayerSelfOperationGiveup(msg)
	end

	-- deal with available operation
	if operation_id == CardConst.OperationIDs.OPERATION_UNKNOW and
	   msg:my_available_operation_id() ~= CardConst.OperationIDs.OPERATION_UNKNOW then
		self:showAvailableOperationsForPlayerSelf(msg)
	end
end

function NormalRoomScene:dealWithPlayCardMsgReceived(code, msg)
	print("[NormalRoomScene:dealWithPlayCardMsgReceived]")
	if code ~= gamer.MsgCodes.SUCCEED then
		print("[NormalRoomScene:dealWithPlayCardMsgReceived] failed")
		return
	end

	if msg:player_id() == gamer.data_mgr_:self_player_id() then -- player self play card msg
		print("[NormalRoomScene:dealWithPlayCardMsgReceived] player self play card msg")
		self:dealWithPlayCardMsgOfPlayerSelf(msg)
	else -- other player play card msg
		print("[NormalRoomScene:dealWithPlayCardMsgReceived] other player play card msg")
		self:dealWithPlayCardMsgOfOtherPlayer(msg)
	end
end

function NormalRoomScene:dealWithStartGameMsgReceived(code, msg)
	print("[NormalRoomScene:dealWithStartGameMsgReceived]")
	self:initForGameStart()
	self:initMahjongLayer()
end

function NormalRoomScene:dealWithGameEndMsgReceived(code, msg)
	print("[NormalRoomScene:dealWithGameEndMsgReceived]")
	do
		local game_end_data = msg:game_end_data(0)
		local score = game_end_data:diff_score_gold()
		print("[NormalRoomScene:dealWithGameEndMsgReceived] score : ", score)
		
		gamer.popup_mgr_.showPopup(gamer.PopupIDs.POPUP_ID_GAME_END, msg)
		
		return
	end

	--[[
	local func = function()
		gamer.msg_helper_.sendStartGameMsg()
	end
	local delay_action = cc.DelayTime:create(3)
	local call_action = cc.CallFunc:create(func)
	local sequence_action = cc.Sequence:create(delay_action, call_action)
	self:runAction(sequence_action)
	]]
end

function NormalRoomScene:addMsgListeners()
	gamer.msg_mgr_:addMsgListener(gamer.MsgTypes.S2C_MSG_TYPE_ROOM, handler(self, self.onServerMsgReceived))
end

function NormalRoomScene:removeMsgListeners()
	gamer.msg_mgr_:removeMsgListener(gamer.MsgTypes.S2C_MSG_TYPE_ROOM, 
		handler(self, self.onServerMsgReceived))
end

function NormalRoomScene:onBtnOperatoinTouch(sender)
    print("[NormalRoomScene:onBtnOperatoinTouch]")
	local operation_id = sender:getTag()
	print("[NormalRoomScene:onBtnOperatoinTouch] operation_id : ", operation_id)

	if operation_id == CardConst.OperationIDs.OPERATION_CHI then           -- chi
		gamer.audio_mgr_.playEffectMusicForPlayCard(gamer.audio_mgr_.Operations.CHI)
		self:doPlayerSelfOperationChi(sender)
		self:showFlagForOperatingPlayer()
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG then      -- peng
		gamer.audio_mgr_.playEffectMusicForPlayCard(gamer.audio_mgr_.Operations.PENG)
		self:doPlayerSelfOperationPeng()
		self:showFlagForOperatingPlayer()
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG_GANG then -- peng gang
		gamer.audio_mgr_.playEffectMusicForPlayCard(gamer.audio_mgr_.Operations.GANG)
		self:doPlayerSelfOperationPengGang()
		self:showFlagForOperatingPlayer()
	elseif operation_id == CardConst.OperationIDs.OPERATION_MING_GANG then -- ming gang
		gamer.audio_mgr_.playEffectMusicForPlayCard(gamer.audio_mgr_.Operations.GANG)
		self:doPlayerSelfOperationMingGang()
		self:startPlayCardTimer()
	elseif operation_id == CardConst.OperationIDs.OPERATION_AN_GANG then   -- an gang
		gamer.audio_mgr_.playEffectMusicForPlayCard(gamer.audio_mgr_.Operations.GANG)
		self:doPlayerSelfOperationAnGang()
		self:startPlayCardTimer()
	elseif operation_id == CardConst.OperationIDs.OPERATION_BU_HUA then    -- bu hua
		gamer.audio_mgr_.playEffectMusicForPlayCard(gamer.audio_mgr_.Operations.BUHUA)
		self:doPlayerSelfOperationBuhua()
		self:startPlayCardTimer()
	elseif operation_id == CardConst.OperationIDs.OPERATION_TING then      -- ting
		gamer.audio_mgr_.playEffectMusicForPlayCard(gamer.audio_mgr_.Operations.TING)
		self:doPlayerSelfOperationTing()
	elseif operation_id == CardConst.OperationIDs.OPERATION_HU then        -- hu
		gamer.audio_mgr_.playEffectMusicForPlayCard(gamer.audio_mgr_.Operations.HU)
		self:doPlayerSelfOperationHu()
	elseif operation_id == CardConst.OperationIDs.OPERATION_ZI_MO then     -- zi mo
		gamer.audio_mgr_.playEffectMusicForPlayCard(gamer.audio_mgr_.Operations.ZIMO)
		self:doPlayerSelfOperationZimo()
	elseif operation_id == CardConst.OperationIDs.OPERATION_GIVE_UP then   -- guo
		gamer.audio_mgr_.playEffectMusicForPlayCard(gamer.audio_mgr_.Operations.GUO)
		self:doPlayerSelfOperationGiveup()
		self:showFlagForOperatingPlayer()
	end
end

function NormalRoomScene:onMahjongNodeTouch(sender)
    print("[NormalRoomScene:onMahjongNodeTouch]")
	if not PlayCardHelper.iCanDiscard() then
		print("[NormalRoomScene:onMahjongNodeTouch] i can't discard now!")
		return
	end

	local mj_node = sender:getParent()
	local y = mj_node:getPositionY() 
	if y == MahjongConst.Sizes.OFFSET_Y3 then -- first selecte
		mj_node:setPositionY(MahjongConst.Sizes.OFFSET_Y4)
		if self.last_selected_mj_ then
			self.last_selected_mj_:setPositionY(MahjongConst.Sizes.OFFSET_Y3)
		end

		self.last_selected_mj_ = mj_node

	elseif y == MahjongConst.Sizes.OFFSET_Y4 then -- second selecte
		local mj_value = mj_node:getTag()
		print("[NormalRoomScene:onMahjongNodeTouch] mj_value : ", mj_value)
		self:doPlayerSelfOperationDiscard(mj_value)
	end
end

function NormalRoomScene:onServerMsgReceived(code, msg_type, msg_id, msg)
    print("[NormalRoomScene:onServerMsgReceived] code, msg_type, msg_id : ", code, msg_type, msg_id)
	if code ~= gamer.MsgCodes.SUCCEED then
		print("[NormalRoomScene:onServerMsgReceived] error")
	end

	if msg_type == gamer.MsgTypes.S2C_MSG_TYPE_ROOM then
		if msg_id == gamer.MsgIDs.MSG_ID_ROOM_PLAY_CARD then
			self:dealWithPlayCardMsgReceived(code, msg)
		elseif msg_id == gamer.MsgIDs.MSG_ID_ROOM_START_GAME then
			self:dealWithStartGameMsgReceived(code, msg)
		elseif msg_id == gamer.MsgIDs.MSG_ID_ROOM_GAME_END then
			self:dealWithGameEndMsgReceived(code, msg)
		end
	end
end

function NormalRoomScene:onEnter()
	-- TODO : dispatch layer enter event to all listeners
    print("[NormalRoomScene:onEnter]")
	self:addMsgListeners()
end

function NormalRoomScene:onExit()
	-- TODO : dispatch layer exit event to all listeners
    print("[NormalRoomScene:onExit]")
	self:removeMsgListeners()
end

return NormalRoomScene