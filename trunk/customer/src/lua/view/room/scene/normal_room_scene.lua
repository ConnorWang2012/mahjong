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

local NormalRoomScene = class("NormalRoomScene", require "view.room.scene.room_scene.lua")
local MahjongCreator  = require "view.room.mahjong.mahjong_creator.lua"
local OperationAnim   = require "view.animations.room.node_operation_anim.lua"
local OperationAnim2  = require "view.animations.room.node_operation_anim2.lua"
local MahjongConst    = require "view.constant.mahjong_constants.lua"
local CardConst       = require "logic.constant.card_constants.lua"
local PlayCardHelper  = require "logic.util.play_card_helper.lua"

function NormalRoomScene:ctor(view_file)
	print("[NormalRoomScene:ctor]")
    self.super.ctor(self, view_file)
	self:dealWithGameStart()
end

function NormalRoomScene:dealWithGameStart()
	self:initMahjongLayer()
	self:initPlayCardTimerAndDirection()
end

function NormalRoomScene:initMahjongLayer()
	if not self.mahjong_layer_ then
		self.mahjong_layer_ = cc.Layer:create()
		self:addChild(self.mahjong_layer_)
	end

	self:initMahjongsOfPlayerSelf()
	local players_num = gamer.data_mgr_:room_msg_protocol():players_num()
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
end

function NormalRoomScene:initPlayCardTimerAndDirection()
	-- show timer and direction
	PlayCardHelper.setPlayerDirection(gamer.data_mgr_:self_player_id(), MahjongConst.Directions.SELF)	
	self:startPlayCardTimer()
	self:showNextPlayCardDirection()
end

function NormalRoomScene:initMahjongsOfPlayerSelf()
	-- visible hand cards
	self.player_self_invisible_mj_offset_x_ = self:initVisibleMahjongsOfPlayerSelf()
	
	-- invisible hand cards	
	self:initInvisibleMahjongsOfPlayerSelf()

	-- direction
	local player_cards = gamer.data_mgr_:cards_msg_protocol_of_player_self()
	PlayCardHelper.setPlayerDirection(player_cards:player_id(), MahjongConst.Directions.SELF)
end

function NormalRoomScene:initMahjongsOfLeftPlayer()
	-- visible hand cards	
	local offset_x, offset_y = self:initVisibleMahjongsOfLeftPlayer()

	-- invisible hand cards
	self:initInvisibleMahjongsOfLeftPlayer(offset_x, offset_y)

	-- direction
	local player_cards = gamer.data_mgr_:cards_msg_protocol_of_left_player()
	PlayCardHelper.setPlayerDirection(player_cards:player_id(), MahjongConst.Directions.LEFT)
end

function NormalRoomScene:initMahjongsOfOppositePlayer()
	-- visible hand cards	
	self.opposite_player_invisible_mj_offset_x_ = self:initVisibleMahjongsOfOppositePlayer()

	-- invisible hand cards	
	self:initInvisibleMahjongsOfOppositePlayer()

	-- direction
	local player_cards = gamer.data_mgr_:cards_msg_protocol_of_opposite_player()
	PlayCardHelper.setPlayerDirection(player_cards:player_id(), MahjongConst.Directions.OPPOSITE)
end

function NormalRoomScene:initMahjongsOfRightPlayer()
	-- visible hand cards	
	local offset_x, offset_y = self:initVisibleMahjongsOfRightPlayer()

	-- invisible hand cards	
	self:initInvisibleMahjongsOfRightPlayer(offset_x, offset_y)

	-- direction
	local player_cards = gamer.data_mgr_:cards_msg_protocol_of_right_player()
	PlayCardHelper.setPlayerDirection(player_cards:player_id(), MahjongConst.Directions.RIGHT)
end

-- @ return : position offset x for invisible card
function NormalRoomScene:initVisibleMahjongsOfPlayerSelf()
	-- ming gang
	local player_cards         = gamer.data_mgr_:cards_msg_protocol_of_player_self()
	local ming_gang_cards_size = player_cards:ming_gang_cards_size()
	local an_gang_cards_size   = player_cards:an_gang_cards_size()
	local peng_cards_size      = player_cards:peng_cards_size()
	local chi_cards_size       = player_cards:chi_cards_size()
	local offset_x             = MahjongConst.Sizes.OFFSET_X1
	local offsetx			   = MahjongConst.Sizes.OFFSET_X1 -- for return
	self.visible_mj_nodes_player_self_ = {}

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
		if peng_cards_size <= 0 and (ming_gang_cards_size > 0 or an_gang_cards_size > 0) then
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

	return offsetx
end

function NormalRoomScene:initInvisibleMahjongsOfPlayerSelf()
	self.invisible_mj_nodes_player_self_ = {}
	local myInsert = table.insert
	local player_cards = gamer.data_mgr_:cards_msg_protocol_of_player_self()
	for i = 0, player_cards:invisible_hand_cards_size() - 1 do
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

-- @ return : position offset x, y for invisible card
function NormalRoomScene:initVisibleMahjongsOfLeftPlayer()
	-- ming gang
	local player_cards         = gamer.data_mgr_:cards_msg_protocol_of_left_player()
	local ming_gang_cards_size = player_cards:ming_gang_cards_size()
	local an_gang_cards_size   = player_cards:an_gang_cards_size()
	local peng_cards_size      = player_cards:peng_cards_size()
	local chi_cards_size       = player_cards:chi_cards_size()
	local offset_x             = MahjongConst.Sizes.LEFT_CARD_OFFSET_X0
	local offset_y             = MahjongConst.Sizes.CARD_OFFSET_Y0
	local offsetx			   = offset_x -- for return
	local offsety			   = offset_y -- for return

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
			end
		end
	end

	-- chi 
	if chi_cards_size > 0 then
		if peng_cards_size <= 0 and (ming_gang_cards_size > 0 or an_gang_cards_size > 0) then
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
			end
		end
	end

	return offset_x, offset_y
end

function NormalRoomScene:initInvisibleMahjongsOfLeftPlayer(offset_x, offset_y)
	local player_cards = gamer.data_mgr_:ards_msg_protocol_of_left_player()
	for i = 0, player_cards:invisible_hand_cards_num() - 1 do
		local mj_node = MahjongCreator.create(MahjongConst.Directions.LEFT, 
											  MahjongConst.Types.INVISIBLE)
		if mj_node then
			mj_node:setPosition(cc.p(offset_x - MahjongConst.Sizes.CARD_OFFSET_X1 * i, 
			                         offset_y - MahjongConst.Sizes.CARD_OFFSET_Y1 * i))
			self.mahjong_layer_:addChild(mj_node)
		end
	end
end

-- @ return : position offset x for invisible card
function NormalRoomScene:initVisibleMahjongsOfOppositePlayer()
	-- ming gang
	local player_cards         = gamer.data_mgr_:cards_msg_protocol_of_opposite_player()
	local ming_gang_cards_size = player_cards:ming_gang_cards_size()
	local an_gang_cards_size   = player_cards:an_gang_cards_size()
	local peng_cards_size      = player_cards:peng_cards_size()
	local chi_cards_size       = player_cards:chi_cards_size()
	local offset_x             = MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X0
	local offsetx			   = MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X0 -- for return
	self.visible_mj_nodes_opposite_player_ = {}

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
		if peng_cards_size <= 0 and (ming_gang_cards_size > 0 or an_gang_cards_size > 0) then
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

	return offsetx
end

function NormalRoomScene:initInvisibleMahjongsOfOppositePlayer()
	local player_cards = gamer.data_mgr_:cards_msg_protocol_of_opposite_player()
	local myInsert = table.insert
	self.invisible_mj_nodes_opposite_player_ = {}
	print("[NormalRoomScene:initInvisibleMahjongsOfOppositePlayer] invisible_hand_cards_num : ", player_cards:invisible_hand_cards_num())
	for i = 0, player_cards:invisible_hand_cards_num() - 1 do
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

-- @ return : position offset x, y for invisible card
function NormalRoomScene:initVisibleMahjongsOfRightPlayer()
	-- ming gang
	local player_cards         = gamer.data_mgr_:cards_msg_protocol_of_right_player()
	local ming_gang_cards_size = player_cards:ming_gang_cards_size()
	local an_gang_cards_size   = player_cards:an_gang_cards_size()
	local peng_cards_size      = player_cards:peng_cards_size()
	local chi_cards_size       = player_cards:chi_cards_size()
	local offset_x             = MahjongConst.Sizes.RIGHT_CARD_OFFSET_X0
	local offset_y             = MahjongConst.Sizes.CARD_OFFSET_Y0

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
			end
		end
	end

	-- chi 
	if chi_cards_size > 0 then
		if peng_cards_size <= 0 and (ming_gang_cards_size > 0 or an_gang_cards_size > 0) then
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
			end
		end
	end

	return offset_x, offset_y
end

function NormalRoomScene:initInvisibleMahjongsOfRightPlayer(offset_x, offset_y)
	local player_cards = gamer.data_mgr_:cards_msg_protocol_of_right_player()
	for i = 0, player_cards:invisible_hand_cards_num() - 1 do
		local mj_node = MahjongCreator.create(MahjongConst.Directions.RIGHT, 
											  MahjongConst.Types.INVISIBLE)
		if mj_node then
			mj_node:setPosition(cc.p(offset_x + MahjongConst.Sizes.CARD_OFFSET_X1 * i, 
			                         offset_y - MahjongConst.Sizes.CARD_OFFSET_Y1 * i))
			self.mahjong_layer_:addChild(mj_node)
		end
	end
end

function NormalRoomScene:initMahjongsAfterOperationForPlayerSelf()
	self:removeAllMahjongNodes(self.visible_mj_nodes_player_self_)
	self:removeAllMahjongNodes(self.invisible_mj_nodes_player_self_)

	self:initMahjongsOfPlayerSelf()

	self:removeLastDiscardNodeForPlayerSelf()
end

function NormalRoomScene:initMahjongsAfterOperationForLeftPlayer()
end

function NormalRoomScene:initMahjongsAfterOperationForOppositePlayer()
	self:removeAllMahjongNodes(self.visible_mj_nodes_opposite_player_)
	self:removeAllMahjongNodes(self.invisible_mj_nodes_opposite_player_)

	self:initMahjongsOfOppositePlayer()

	self:removeLastDiscardNodeForOppositePlayer()
end

function NormalRoomScene:initMahjongsAfterOperationForRightPlayer()
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
	self.play_card_timer_count_ = 15 -- TODO 
	self.play_card_timer_ = cc.Director:getInstance():getScheduler():scheduleScriptFunc(handler(self, self.playCardTimer), 1, false)
end

function NormalRoomScene:stopPlayCardTimer()
	if self.play_card_timer_ then
		cc.Director:getInstance():getScheduler():unscheduleScriptEntry(self.play_card_timer_)
		self.play_card_timer_ = nil
	end
end

function NormalRoomScene:playCardTimer()
	if self.play_card_timer_count_ >= 0 then
		if not self.node_play_card_timer_ then
			self.node_play_card_timer_ = self.root_view_node_:getChildByName("node_play_card_timer")
		end
		self.node_play_card_timer_:removeAllChildren()
		local text = ccui.TextAtlas:create(tostring(self.play_card_timer_count_), 
			"assets/common/numbers_blue.png", 42, 58, "0");
		self.node_play_card_timer_:addChild(text)

		self.play_card_timer_count_ = self.play_card_timer_count_ - 1
	else
		-- set timer and direction for next player
		--self.play_card_timer_count_ = 15 -- TODO

		--self:showNextPlayCardDirection()
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

function NormalRoomScene:modifyMahjongsOfPlayerSelfAfterDiscard(mahjong_value)
	-- remove discard from invisible cards
	gamer.data_mgr_:updateCardForDiscardOfPlayerSelf(mahjong_value)

	-- add discard node
	self:showDiscardOfPlayerSelf(mahjong_value)

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

	self.last_selected_mj_ = nil
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

function NormalRoomScene:modifyOtherPlayerMahjongsAfterDiscard(play_card_msg)
	print("[NormalRoomScene:modifyOtherPlayerMahjongsAfterDiscard]")
	local direction = PlayCardHelper.getPlayerDirection(play_card_msg:player_id())

	if direction == MahjongConst.Directions.LEFT then
	elseif direction == MahjongConst.Directions.OPPOSITE then
		self:showDiscardOfOppositePlayer(play_card_msg:discard())
		self:removeLastMahjongNode(self.invisible_mj_nodes_opposite_player_)
	elseif direction == MahjongConst.Directions.RIGHT then
	end
end

function NormalRoomScene:modifyOtherPlayerMahjongsAfterChi()
	print("[NormalRoomScene:modifyOtherPlayerMahjongsAfterChi]")
	local player_id = gamer.data_mgr_:play_card_msg_protocol():player_id()
	local direction = PlayCardHelper.getPlayerDirection(player_id)

	if direction == MahjongConst.Directions.LEFT then
	elseif direction == MahjongConst.Directions.OPPOSITE then
		self:initMahjongsAfterOperationForOppositePlayer()
	elseif direction == MahjongConst.Directions.RIGHT then
	end
end

function NormalRoomScene:modifyOtherPlayerMahjongsAfterPeng()
	print("[NormalRoomScene:modifyOtherPlayerMahjongsAfterPeng]")
	local player_id = gamer.data_mgr_:play_card_msg_protocol():player_id()
	local direction = PlayCardHelper.getPlayerDirection(player_id)

	if direction == MahjongConst.Directions.LEFT then
	elseif direction == MahjongConst.Directions.OPPOSITE then
		self:initMahjongsAfterOperationForOppositePlayer()
	elseif direction == MahjongConst.Directions.RIGHT then
	end
end

function NormalRoomScene:modifyOtherPlayerMahjongsAfterPengGang()
	print("[NormalRoomScene:modifyOtherPlayerMahjongsAfterPengGang]")
	local player_id = gamer.data_mgr_:play_card_msg_protocol():player_id()
	local direction = PlayCardHelper.getPlayerDirection(player_id)

	if direction == MahjongConst.Directions.LEFT then
	elseif direction == MahjongConst.Directions.OPPOSITE then
		self:initMahjongsAfterOperationForOppositePlayer()
	elseif direction == MahjongConst.Directions.RIGHT then
	end
end

function NormalRoomScene:modifyOtherPlayerMahjongsAfterMingGang()
	print("[NormalRoomScene:modifyOtherPlayerMahjongsAfterMingGang]")
	local player_id = gamer.data_mgr_:play_card_msg_protocol():player_id()
	local direction = PlayCardHelper.getPlayerDirection(player_id)

	if direction == MahjongConst.Directions.LEFT then
	elseif direction == MahjongConst.Directions.OPPOSITE then
		self:initMahjongsAfterOperationForOppositePlayer()
	elseif direction == MahjongConst.Directions.RIGHT then
	end
end

function NormalRoomScene:modifyOtherPlayerMahjongsAfterAnGang()
	print("[NormalRoomScene:modifyOtherPlayerMahjongsAfterAnGang]")
	local player_id = gamer.data_mgr_:play_card_msg_protocol():player_id()
	local direction = PlayCardHelper.getPlayerDirection(player_id)

	if direction == MahjongConst.Directions.LEFT then
	elseif direction == MahjongConst.Directions.OPPOSITE then
		self:initMahjongsAfterOperationForOppositePlayer()
	elseif direction == MahjongConst.Directions.RIGHT then
	end
end

function NormalRoomScene:modifyOtherPlayerMahjongsAfterBuhua()
	print("[NormalRoomScene:modifyOtherPlayerMahjongsAfterBuhua]")
	local player_id = gamer.data_mgr_:play_card_msg_protocol():player_id()
	local direction = PlayCardHelper.getPlayerDirection(player_id)

	if direction == MahjongConst.Directions.LEFT then
	elseif direction == MahjongConst.Directions.OPPOSITE then

	elseif direction == MahjongConst.Directions.RIGHT then
	end
end

function NormalRoomScene:modifyOtherPlayerMahjongsAfterHu()
	print("[NormalRoomScene:modifyOtherPlayerMahjongsAfterHu]")
	local player_id = gamer.data_mgr_:play_card_msg_protocol():player_id()
	local direction = PlayCardHelper.getPlayerDirection(player_id)

	if direction == MahjongConst.Directions.LEFT then
	elseif direction == MahjongConst.Directions.OPPOSITE then
		self:modifyMahjongsOfOppositePlayerAfterHu()
	elseif direction == MahjongConst.Directions.RIGHT then
	end
end

function NormalRoomScene:modifyOtherPlayerMahjongsAfterZimo()
	print("[NormalRoomScene:modifyOtherPlayerMahjongsAfterZimo]")
	local player_id = gamer.data_mgr_:play_card_msg_protocol():player_id()
	local direction = PlayCardHelper.getPlayerDirection(player_id)

	if direction == MahjongConst.Directions.LEFT then
	elseif direction == MahjongConst.Directions.OPPOSITE then

	elseif direction == MahjongConst.Directions.RIGHT then
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

function NormalRoomScene:showNextPlayCardDirection()
	if self.img_player_direction_ then
		self.img_player_direction_:setVisible(false)
	end

	local players_num = gamer.data_mgr_:room_msg_protocol():players_num()
	local player_id = gamer.data_mgr_:play_card_msg_protocol():next_operate_player_id()
	local img_name = PlayCardHelper.getNextPlayerDirectionImageName(players_num, player_id)
	print("[NormalRoomScene:initNextPlayCardDirection] img_name £º ", img_name)
	self.img_player_direction_ = self.root_view_node_:getChildByName(img_name)
	self.img_player_direction_:setVisible(true)
end

function NormalRoomScene:showInvisibleMahjongsForGameEnd()
	print("[NormalRoomScene:showInvisibleMahjongsForGameEnd]")
	self:showInvisibleMahjongsOfPlayerSelf()

	local players_num = gamer.data_mgr_:room_msg_protocol():players_num()
	if 2 == players_num then
		self:showInvisibleMahjongsOfOppositePlayer()
	elseif 3 == players_num then
		self:showInvisibleMahjongsOfLeftPlayer()
		self:showInvisibleMahjongsOfRightPlayer()
	elseif 4 == players_num then
		self:showInvisibleMahjongsOfLeftPlayer()
		self:showInvisibleMahjongsOfOppositePlayer()
		self:showInvisibleMahjongsOfRightPlayer()
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

function NormalRoomScene:showInvisibleMahjongsOfLeftPlayer()
end

function NormalRoomScene:showInvisibleMahjongsOfOppositePlayer()
end

function NormalRoomScene:showInvisibleMahjongsOfRightPlayer()
end

function NormalRoomScene:showAvailableOperationsForPlayerSelf(play_card_msg)
	print("[NormalRoomScene:showAvailableOperationsForPlayerSelf]")
	local operation_id = play_card_msg:my_available_operation_id()
	local discard = play_card_msg:discard()
	print("[NormalRoomScene:showAvailableOperationsForPlayerSelf] operation_id : ", operation_id)
	if operation_id == CardConst.OperationIDs.OPERATION_NONE then		   -- none
		-- i have a new card and i can't operate except discard
		print("[NormalRoomScene:showAvailableOperationsForPlayerSelf] new_card : ", play_card_msg:new_card())
		if play_card_msg:new_card() ~= CardConst.CardValues.INVALID_CARD_VALUE then
			self:dealWithNewCardOfPlayerSelf(play_card_msg, true)
		elseif play_card_msg:next_operate_player_id() ~= CardConst.CardValues.INVALID_PLAYER_ID then -- means next player has got a new card
			self:dealWithNewCardOfOtherPlayer(play_card_msg)
		end
	elseif operation_id == CardConst.OperationIDs.OPERATION_CHI then       -- chi
		self:showOperationChi()
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG then      -- peng
		self:showOperation(operation_id, "i_operation_peng.png", discard, true)
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG_GANG then -- peng + gang
		self:showOperation(operation_id, "i_operation_gang.png", discard, true)
	elseif operation_id == CardConst.OperationIDs.OPERATION_MING_GANG then -- ming gang
		self:showOperation(operation_id, "i_operation_gang.png", play_card_msg:new_card(), true)
		if play_card_msg:new_card() ~= CardConst.CardValues.INVALID_CARD_VALUE then
			self:dealWithNewCardOfPlayerSelf(play_card_msg, true)
		end
	elseif operation_id == CardConst.OperationIDs.OPERATION_AN_GANG then   -- an gang
		self:showOperation(operation_id, "i_operation_gang.png", play_card_msg:new_card(), true)
		if play_card_msg:new_card() ~= CardConst.CardValues.INVALID_CARD_VALUE then
			self:dealWithNewCardOfPlayerSelf(play_card_msg, true)
		end
	elseif operation_id == CardConst.OperationIDs.OPERATION_BU_HUA then    -- bu hua
		self:showOperation(operation_id, "i_operation_buhua.png", play_card_msg:new_card(), false)
		if play_card_msg:new_card() ~= CardConst.CardValues.INVALID_CARD_VALUE then
			self:dealWithNewCardOfPlayerSelf(play_card_msg, true)
		end
	elseif operation_id == CardConst.OperationIDs.OPERATION_HU then        -- hu
		self:showOperation(operation_id, "i_operation_hu.png", discard, true)
	elseif operation_id == CardConst.OperationIDs.OPERATION_ZI_MO then     -- zi mo
		self:showOperation(operation_id, "i_operation_zimo.png", discard, true)
		if play_card_msg:new_card() ~= CardConst.CardValues.INVALID_CARD_VALUE then
			self:dealWithNewCardOfPlayerSelf(play_card_msg, true)
		end
	elseif operation_id == CardConst.OperationIDs.OPERATION_GIVE_UP then   -- guo
	end
end

function NormalRoomScene:showOperationChi()
	print("[NormalRoomScene:showOperationChi]")
	local init_func1 = function() 
		if not self.node_operation_chi_1_ then -- node for operation chi 1
			local layout = OperationAnim2:create()
			self.node_operation_chi_1_ = layout.root
			self.anim_operation_chi_1_ = layout.animation
			self:addChild(self.node_operation_chi_1_)

			self.node_operation_chi_1_:setPosition(cc.p(display.right, display.bottom + 300))
			self.node_operation_chi_1_:runAction(self.anim_operation_chi_1_) -- not really run until call self.anim_operation_:gotoFrameAndPlay(0, false)

			local img_bg = self.node_operation_chi_1_:getChildByName("img_operation_bg")
			self.img_operation_chi_11_ = img_bg:getChildByName("img_operation1")
			self.img_operation_chi_11_:setTag(CardConst.OperationIDs.OPERATION_CHI)
			self.img_operation_chi_11_:setName("operation_chi_1")
			self.img_operation_chi_11_:setTouchEnabled(true)
			self.img_operation_chi_11_:addClickEventListener(handler(self, self.onBtnOperatoinTouch))

			self.img_operation_chi_12_ = img_bg:getChildByName("img_operation2")
			self.img_operation_chi_12_:setTag(CardConst.OperationIDs.OPERATION_GIVE_UP)
			self.img_operation_chi_12_:setTouchEnabled(true)
			self.img_operation_chi_12_:addClickEventListener(handler(self, self.onBtnOperatoinTouch))

			self.img_mj_chi_11_ = img_bg:getChildByName("img_mahjong_fg1")
			self.img_mj_chi_12_ = img_bg:getChildByName("img_mahjong_fg2")
			self.img_mj_chi_13_ = img_bg:getChildByName("img_mahjong_fg3")
		end

		local proto = gamer.data_mgr_:play_card_msg_protocol()
		local card1 = proto:operating_cards(0)
		local card2 = proto:operating_cards(1)
		local card3 = proto:operating_cards(2)
		self.img_mj_chi_11_:loadTexture(MahjongCreator.getCardPng(card1), ccui.TextureResType.plistType)
		self.img_mj_chi_12_:loadTexture(MahjongCreator.getCardPng(card2), ccui.TextureResType.plistType)
		self.img_mj_chi_13_:loadTexture(MahjongCreator.getCardPng(card3), ccui.TextureResType.plistType)
	
		self.node_operation_chi_1_:setVisible(true)
		self.anim_operation_chi_1_:gotoFrameAndPlay(0, false)
	end

	local init_func2 = function() 
		if not self.node_operation_chi_2_ then -- node for operation chi 2
			local layout = OperationAnim2:create()
			self.node_operation_chi_2_ = layout.root
			self.anim_operation_chi_2_ = layout.animation
			self:addChild(self.node_operation_chi_2_)

			self.node_operation_chi_2_:setPosition(cc.p(display.right, display.bottom + 470))
			self.node_operation_chi_2_:runAction(self.anim_operation_chi_2_) -- not really run until call self.anim_operation_:gotoFrameAndPlay(0, false)

			local img_bg = self.node_operation_chi_2_:getChildByName("img_operation_bg")
			self.img_operation_chi_21_ = img_bg:getChildByName("img_operation1")
			self.img_operation_chi_21_:setTag(CardConst.OperationIDs.OPERATION_CHI)
			self.img_operation_chi_21_:setName("operation_chi_2")
			self.img_operation_chi_21_:setTouchEnabled(true)
			self.img_operation_chi_21_:addClickEventListener(handler(self, self.onBtnOperatoinTouch))

			self.img_operation_chi_22_ = img_bg:getChildByName("img_operation2")
			self.img_operation_chi_22_:setTag(CardConst.OperationIDs.OPERATION_GIVE_UP)
			self.img_operation_chi_22_:setTouchEnabled(true)
			self.img_operation_chi_22_:addClickEventListener(handler(self, self.onBtnOperatoinTouch))

			self.img_mj_chi_21_ = img_bg:getChildByName("img_mahjong_fg1")
			self.img_mj_chi_22_ = img_bg:getChildByName("img_mahjong_fg2")
			self.img_mj_chi_23_ = img_bg:getChildByName("img_mahjong_fg3")
		end

		local proto = gamer.data_mgr_:play_card_msg_protocol()
		local card1 = proto:operating_cards(3)
		local card2 = proto:operating_cards(4)
		local card3 = proto:operating_cards(5)
		self.img_mj_chi_21_:loadTexture(MahjongCreator.getCardPng(card1), ccui.TextureResType.plistType)
		self.img_mj_chi_22_:loadTexture(MahjongCreator.getCardPng(card2), ccui.TextureResType.plistType)
		self.img_mj_chi_23_:loadTexture(MahjongCreator.getCardPng(card3), ccui.TextureResType.plistType)
	
		self.node_operation_chi_2_:setVisible(true)
		self.anim_operation_chi_2_:gotoFrameAndPlay(0, false)
	end

	local init_func3 = function() 
		if not self.node_operation_chi_3_ then -- node for operation chi 3
			local layout = OperationAnim2:create()
			self.node_operation_chi_3_ = layout.root
			self.anim_operation_chi_3_ = layout.animation
			self:addChild(self.node_operation_chi_3_)

			self.node_operation_chi_3_:setPosition(cc.p(display.right, display.bottom + 640))
			self.node_operation_chi_3_:runAction(self.anim_operation_chi_3_) -- not really run until call self.anim_operation_:gotoFrameAndPlay(0, false)

			local img_bg = self.node_operation_chi_3_:getChildByName("img_operation_bg")
			self.img_operation_chi_31_ = img_bg:getChildByName("img_operation1")
			self.img_operation_chi_31_:setTag(CardConst.OperationIDs.OPERATION_CHI)
			self.img_operation_chi_31_:setName("operation_chi_3")
			self.img_operation_chi_31_:setTouchEnabled(true)
			self.img_operation_chi_31_:addClickEventListener(handler(self, self.onBtnOperatoinTouch))

			self.img_operation_chi_32_ = img_bg:getChildByName("img_operation2")
			self.img_operation_chi_32_:setTag(CardConst.OperationIDs.OPERATION_GIVE_UP)
			self.img_operation_chi_32_:setTouchEnabled(true)
			self.img_operation_chi_32_:addClickEventListener(handler(self, self.onBtnOperatoinTouch))

			self.img_mj_chi_31_ = img_bg:getChildByName("img_mahjong_fg1")
			self.img_mj_chi_32_ = img_bg:getChildByName("img_mahjong_fg2")
			self.img_mj_chi_33_ = img_bg:getChildByName("img_mahjong_fg3")
		end

		local proto = gamer.data_mgr_:play_card_msg_protocol()
		local card1 = proto:operating_cards(6)
		local card2 = proto:operating_cards(7)
		local card3 = proto:operating_cards(8)
		self.img_mj_chi_31_:loadTexture(MahjongCreator.getCardPng(card1), ccui.TextureResType.plistType)
		self.img_mj_chi_32_:loadTexture(MahjongCreator.getCardPng(card2), ccui.TextureResType.plistType)
		self.img_mj_chi_33_:loadTexture(MahjongCreator.getCardPng(card3), ccui.TextureResType.plistType)
	
		self.node_operation_chi_3_:setVisible(true)
		self.anim_operation_chi_3_:gotoFrameAndPlay(0, false)
	end

	local size = gamer.data_mgr_:play_card_msg_protocol():operating_cards_size()
	print("[NormalRoomScene:showOperationChi] size : ", size)
	if 3 == size then
		init_func1()
	elseif 6 == size then
		init_func1()
		init_func2()
	elseif 9 == size then
		init_func1()
		init_func2()
		init_func3()
	end
end

function NormalRoomScene:showOperation(operation_id, operation1_img_name, operation_mj_value, operation2_visible)
	if not self.node_operation_ then -- node for operations except chi
		local layout = OperationAnim:create()
		self.node_operation_ = layout.root
		self.anim_operation_ = layout.animation
		self:addChild(self.node_operation_)
		self.node_operation_:setVisible(false)

		self.node_operation_:setPosition(cc.p(display.right, display.bottom + 300))
		self.node_operation_:runAction(self.anim_operation_) -- not really run until call self.anim_operation_:gotoFrameAndPlay(0, false)

		local img_bg = self.node_operation_:getChildByName("img_operation_bg")
		self.img_operation1_ = img_bg:getChildByName("img_operation1")
		self.img_operation1_:setTouchEnabled(true)
		self.img_operation1_:addClickEventListener(handler(self, self.onBtnOperatoinTouch))

		self.img_operation_mj_ = img_bg:getChildByName("img_mahjong_fg")

		self.img_operation2_ = img_bg:getChildByName("img_operation2")
		self.img_operation2_:setTag(CardConst.OperationIDs.OPERATION_GIVE_UP)
		self.img_operation2_:setTouchEnabled(true)
		self.img_operation2_:addClickEventListener(handler(self, self.onBtnOperatoinTouch))
	end

	self.img_operation1_:setTag(operation_id)
	self.img_operation1_:loadTexture(operation1_img_name, ccui.TextureResType.plistType)
	self.img_operation_mj_:loadTexture(MahjongCreator.getCardPng(operation_mj_value), ccui.TextureResType.plistType)
	self.img_operation2_:setVisible(operation2_visible)
	self.node_operation_:setVisible(true)
	self.anim_operation_:gotoFrameAndPlay(0, false)

	PlayCardHelper.setHasSpecialOperation(true)

	-- if operation is peng_gang, we need to offer peng operation
	if operation_id == CardConst.OperationIDs.OPERATION_PENG_GANG then
		if not self.node_operation2_ then
			local layout = OperationAnim:create()
			self.node_operation2_ = layout.root
			self.anim_operation2_ = layout.animation
			self:addChild(self.node_operation2_)
			self.node_operation2_:setVisible(false)

			self.node_operation2_:setPosition(cc.p(display.right, display.bottom + 470))
			self.node_operation2_:runAction(self.anim_operation2_) -- not really run until call self.anim_operation2_:gotoFrameAndPlay(0, false)

			local img_bg = self.node_operation2_:getChildByName("img_operation_bg")
			self.img_operation21_ = img_bg:getChildByName("img_operation1")
			self.img_operation21_:setTouchEnabled(true)
			self.img_operation21_:addClickEventListener(handler(self, self.onBtnOperatoinTouch))

			self.img_operation2_mj_ = img_bg:getChildByName("img_mahjong_fg")

			self.img_operation22_ = img_bg:getChildByName("img_operation2")
			self.img_operation22_:setTag(CardConst.OperationIDs.OPERATION_GIVE_UP)
			self.img_operation22_:setTouchEnabled(true)
			self.img_operation22_:addClickEventListener(handler(self, self.onBtnOperatoinTouch))
		end

		self.img_operation21_:setTag(CardConst.OperationIDs.OPERATION_PENG)
		self.img_operation21_:loadTexture("i_operation_peng.png", ccui.TextureResType.plistType)
		self.img_operation2_mj_:loadTexture(MahjongCreator.getCardPng(operation_mj_value), ccui.TextureResType.plistType)
		self.img_operation22_:setVisible(operation2_visible)
		self.node_operation2_:setVisible(true)
		self.anim_operation2_:gotoFrameAndPlay(0, false)
	end
end

function NormalRoomScene:hideOperations()
	if self.node_operation_ then
		self.node_operation_:setVisible(false)
	end

	if self.node_operation2_ then
		self.node_operation2_:setVisible(false)
	end

	if self.node_operation_chi_1_ then
		self.node_operation_chi_1_:setVisible(false)
	end
	if self.node_operation_chi_2_ then
		self.node_operation_chi_2_:setVisible(false)
	end
	if self.node_operation_chi_3_ then
		self.node_operation_chi_3_:setVisible(false)
	end

	PlayCardHelper.setHasSpecialOperation(false)
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
	end
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

function NormalRoomScene:showDiscardOfOtherPlayer(play_card_msg)
	print("[NormalRoomScene:showDiscardOfOtherPlayer]")
	local direction = PlayCardHelper.getPlayerDirection(play_card_msg:player_id())
	print("[NormalRoomScene:showDiscardOfOtherPlayer] direction : ", direction)

	if direction == MahjongConst.Directions.LEFT then
	elseif direction == MahjongConst.Directions.OPPOSITE then
		print("[NormalRoomScene:showDiscardOfOtherPlayer] discard : ", play_card_msg:discard())
		self:showDiscardOfOppositePlayer(play_card_msg:discard())
	elseif direction == MahjongConst.Directions.RIGHT then
	end
end

function NormalRoomScene:dealWithNewCardOfPlayerSelf(play_card_msg, change_diretion)
	print("[NormalRoomScene:dealWithNewCardOfPlayerSelf]")
	print("[NormalRoomScene:dealWithNewCardOfPlayerSelf] new card : ", play_card_msg:new_card())

	self:showNewCardOfPlayerSelf(play_card_msg:new_card())

	-- show timer and direction
	self:startPlayCardTimer()
	if change_diretion then
		self:showNextPlayCardDirection()
	end
end

function NormalRoomScene:dealWithNewCardOfOtherPlayer(play_card_msg)
	local direction = PlayCardHelper.getPlayerDirection(play_card_msg:next_operate_player_id())
	print("[NormalRoomScene:dealWithNewCardOfPlayerSelf] direction : ", direction)
	if direction == MahjongConst.Directions.LEFT then
	elseif direction == MahjongConst.Directions.OPPOSITE then
		local mj_node = MahjongCreator.create(MahjongConst.Directions.OPPOSITE, 
											  MahjongConst.Types.INVISIBLE)
		local n = #self.invisible_mj_nodes_opposite_player_
		local last_pos_x = self.opposite_player_invisible_mj_offset_x_
		if n > 0 then
			last_pos_x = self.invisible_mj_nodes_opposite_player_[n]:getPositionX()
		end
		mj_node:setPosition(cc.p(last_pos_x - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X2 -
								 MahjongConst.Sizes.CARD_INTERVAL2, 
			                     MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_Y0))
		self.mahjong_layer_:addChild(mj_node)
		table.insert(self.invisible_mj_nodes_opposite_player_, mj_node)
	elseif direction == MahjongConst.Directions.RIGHT then
	end

	self:showNextPlayCardDirection()
end

function NormalRoomScene:dealWithPlayCardMsgOfOtherPlayer(msg)
	print("[NormalRoomScene:dealWithPlayCardMsgOfOtherPlayer]")
	local operation_id = msg:operation_id()
	print("[NormalRoomScene:dealWithPlayCardMsgOfOtherPlayer] operation_id : ", operation_id)
	if operation_id == CardConst.OperationIDs.OPERATION_DISCARD then       -- discard
		-- show other player's discard and show available operations with that card
		--self:showDiscardOfOtherPlayer(msg)
		self:modifyOtherPlayerMahjongsAfterDiscard(msg)
		self:showAvailableOperationsForPlayerSelf(msg)
	elseif operation_id == CardConst.OperationIDs.OPERATION_NONE then      
		
	elseif operation_id == CardConst.OperationIDs.OPERATION_CHI then       -- chi
		self:modifyOtherPlayerMahjongsAfterChi()
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG then      -- peng
		self:modifyOtherPlayerMahjongsAfterPeng()
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG_GANG then -- peng + gang
		self:modifyOtherPlayerMahjongsAfterPengGang()
	elseif operation_id == CardConst.OperationIDs.OPERATION_MING_GANG then -- ming gang
		self:modifyOtherPlayerMahjongsAfterMingGang()
	elseif operation_id == CardConst.OperationIDs.OPERATION_AN_GANG then   -- an gang
		self:modifyOtherPlayerMahjongsAfterAnGang()
	elseif operation_id == CardConst.OperationIDs.OPERATION_BU_HUA then    -- bu hua

	elseif operation_id == CardConst.OperationIDs.OPERATION_HU then        -- hu

	elseif operation_id == CardConst.OperationIDs.OPERATION_ZI_MO then     -- zi mo

	elseif operation_id == CardConst.OperationIDs.OPERATION_GIVE_UP then   -- guo
		print("[NormalRoomScene:dealWithPlayCardMsgOfOtherPlayer] next_operate_player_id : ", msg:next_operate_player_id())
		print("[NormalRoomScene:dealWithPlayCardMsgOfOtherPlayer] self_player_id : ", gamer.data_mgr_:self_player_id())
		print("[NormalRoomScene:dealWithPlayCardMsgOfOtherPlayer] has_next_operate_player_new_card : ", tostring(msg:has_next_operate_player_new_card()))
		if msg:next_operate_player_id() ~= CardConst.CardValues.INVALID_PLAYER_ID and
		   msg:next_operate_player_id() ~= gamer.data_mgr_:self_player_id() then -- means next player has got a new card
			if msg:has_next_operate_player_new_card() then
				self:dealWithNewCardOfOtherPlayer(msg)
			end
		end
	end
end

function NormalRoomScene:dealWithPlayCardMsgOfPlayerSelf(msg)
	print("[NormalRoomScene:dealWithPlayCardMsgOfPlayerSelf]")
	local operation_id = msg:operation_id()
	print("[NormalRoomScene:dealWithPlayCardMsgOfPlayerSelf] operation_id : ", operation_id)
	print("[NormalRoomScene:dealWithPlayCardMsgOfPlayerSelf] next_operate_player_id : ", msg:next_operate_player_id())
	if operation_id == CardConst.OperationIDs.OPERATION_DISCARD then       -- discard
		if msg:next_operate_player_id() ~= CardConst.CardValues.INVALID_PLAYER_ID then -- means next player has got a new card
			self:dealWithNewCardOfOtherPlayer(msg)
		end
	elseif operation_id == CardConst.OperationIDs.OPERATION_NONE then      -- new card
		self:dealWithNewCardOfPlayerSelf(msg, false)
	elseif operation_id == CardConst.OperationIDs.OPERATION_CHI then       -- chi
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG then      -- peng
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG_GANG then -- peng + gang
		self:showAvailableOperationsForPlayerSelf(msg)
	elseif operation_id == CardConst.OperationIDs.OPERATION_MING_GANG then -- ming gang
		self:dealWithNewCardOfPlayerSelf(msg, false)
	elseif operation_id == CardConst.OperationIDs.OPERATION_AN_GANG then   -- an gang
		self:dealWithNewCardOfPlayerSelf(msg, false)
	elseif operation_id == CardConst.OperationIDs.OPERATION_BU_HUA then    -- bu hua
		self:dealWithNewCardOfPlayerSelf(msg, false)
	elseif operation_id == CardConst.OperationIDs.OPERATION_HU then        -- hu
	elseif operation_id == CardConst.OperationIDs.OPERATION_ZI_MO then     -- zi mo
		self:dealWithNewCardOfPlayerSelf(msg, false)
	elseif operation_id == CardConst.OperationIDs.OPERATION_GIVE_UP then   -- guo
		if msg:next_operate_player_id() == gamer.data_mgr_:self_player_id() then
			self:showAvailableOperationsForPlayerSelf(msg)
		end
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

function NormalRoomScene:sendPlayCardMsg(operation_id, cards)
	local proto = gamer.protocol.PlayCardMsgProtocol()
	proto:set_player_id(gamer.data_mgr_:self_player_id())
	proto:set_room_id(gamer.data_mgr_:room_msg_protocol():room_id())
	proto:set_cur_round(1) -- TODO : get cur round
	proto:set_operation_id(operation_id)
	if operation_id == CardConst.OperationIDs.OPERATION_CHI then
		local discard = gamer.data_mgr_:play_card_msg_protocol():discard()
		proto:set_discard(discard)
		for k, v in pairs(cards) do
			if v ~= discard then
				proto:add_operating_cards(v)
			end
		end
	else
		proto:set_discard(cards[1])
	end

	gamer.msg_mgr_:sendMsg(gamer.MsgTypes.C2S_MSG_TYPE_ROOM, gamer.MsgIDs.MSG_ID_ROOM_PLAY_CARD, proto)
end

function NormalRoomScene:addMsgListeners()
	gamer.msg_mgr_:addMsgListener(gamer.MsgTypes.S2C_MSG_TYPE_ROOM, handler(self, self.onServerMsgReceived))
end

function NormalRoomScene:removeMsgListeners()
	gamer.msg_mgr_:removeMsgListener(gamer.MsgTypes.S2C_MSG_TYPE_ROOM, handler(self, self.onServerMsgReceived))
end

function NormalRoomScene:onBtnOperatoinTouch(sender)
    print("[NormalRoomScene:onBtnOperatoinTouch]")
	local operation_id = sender:getTag()
	print("[NormalRoomScene:onBtnOperatoinTouch] operation_id : ", operation_id)

	if operation_id == CardConst.OperationIDs.OPERATION_CHI then           -- chi
		--self:showNextPlayCardDirection()
		self:hideOperations()

		local proto = gamer.data_mgr_:play_card_msg_protocol()
		local size = proto:operating_cards_size()
		local cards = {}
		local name = sender:getName()
		if "operation_chi_1" == name then
			if size >= 3 then
				cards[1] = proto:operating_cards(0)
				cards[2] = proto:operating_cards(1)
				cards[3] = proto:operating_cards(2)
			end
		elseif "operation_chi_2" == name then
			if size >= 6 then
				cards[1] = proto:operating_cards(3)
				cards[2] = proto:operating_cards(4)
				cards[3] = proto:operating_cards(5)
			end
		elseif "operation_chi_3" == name then
			if 9 == size then
				cards[1] = proto:operating_cards(6)
				cards[2] = proto:operating_cards(7)
				cards[3] = proto:operating_cards(8)
			end
		end

		self:modifyMahjongsOfPlayerSelfAfterChi(cards)
		self:sendPlayCardMsg(CardConst.OperationIDs.OPERATION_CHI, cards)
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG then      -- peng
		--self:showNextPlayCardDirection()
		self:hideOperations()
		self:modifyMahjongsOfPlayerSelfAfterPeng()
		local cards = { gamer.data_mgr_:play_card_msg_protocol():discard() }
		self:sendPlayCardMsg(CardConst.OperationIDs.OPERATION_PENG, cards)
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG_GANG then -- peng + gang
		--self:showNextPlayCardDirection()
		self:hideOperations()
		self:modifyMahjongsOfPlayerSelfAfterPengGang()
		local cards = { gamer.data_mgr_:play_card_msg_protocol():discard() }
		self:sendPlayCardMsg(CardConst.OperationIDs.OPERATION_PENG_GANG, cards)
	elseif operation_id == CardConst.OperationIDs.OPERATION_MING_GANG then -- ming gang
		self:hideOperations()
		self:modifyMahjongsOfPlayerSelfAfterMingGang()
		local cards = { gamer.data_mgr_:play_card_msg_protocol():new_card() }
		self:sendPlayCardMsg(CardConst.OperationIDs.OPERATION_MING_GANG, cards)
	elseif operation_id == CardConst.OperationIDs.OPERATION_AN_GANG then   -- an gang
		self:hideOperations()
		self:modifyMahjongsOfPlayerSelfAfterAnGang()
		local cards = { gamer.data_mgr_:play_card_msg_protocol():new_card() }
		self:sendPlayCardMsg(CardConst.OperationIDs.OPERATION_AN_GANG, cards)
	elseif operation_id == CardConst.OperationIDs.OPERATION_BU_HUA then    -- bu hua
		self:hideOperations()

		-- send bu hua msg
		local card_buhua = gamer.data_mgr_:play_card_msg_protocol():new_card()
		self:sendPlayCardMsg(CardConst.OperationIDs.OPERATION_BU_HUA, { card_buhua })

		-- remove mahjong node of hua
		local n = #self.invisible_mj_nodes_player_self_
		if n > 0 then
			self.invisible_mj_nodes_player_self_[n]:removeFromParent()
			table.remove(self.invisible_mj_nodes_player_self_, n)
		end
	elseif operation_id == CardConst.OperationIDs.OPERATION_HU then        -- hu
		self:hideOperations()

		self:stopPlayCardTimer()
		self:showInvisibleMahjongsForGameEnd()
		
		self:sendPlayCardMsg(CardConst.OperationIDs.OPERATION_HU)
	elseif operation_id == CardConst.OperationIDs.OPERATION_ZI_MO then     -- zi mo
		self:hideOperations()

		self:stopPlayCardTimer()
		self:showInvisibleMahjongsForGameEnd()

		self:sendPlayCardMsg(CardConst.OperationIDs.OPERATION_ZI_MO)
	elseif operation_id == CardConst.OperationIDs.OPERATION_GIVE_UP then   -- guo
		self:hideOperations()
		local cards = { gamer.data_mgr_:play_card_msg_protocol():discard() }
		self:sendPlayCardMsg(CardConst.OperationIDs.OPERATION_GIVE_UP, cards)
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
		self:modifyMahjongsOfPlayerSelfAfterDiscard(mj_value)

		-- send play mahjong msg 
		self:sendPlayCardMsg(CardConst.OperationIDs.OPERATION_DISCARD, { mj_value })

		-- start play card timer and show direction of next player to play card
		--self:startPlayCardTimer()
		--self:showNextPlayCardDirection()
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