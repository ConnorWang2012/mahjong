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
	print("[NormalRoomScene:initMahjongLayer] players_num : ", players_num)
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
	self.invisible_mj_nodes_player_self_ = {}
	self.visible_mj_nodes_player_self_   = {} -- not including ming gang
	self.visible_ming_gang_mj_nodes_player_self_ = {}

	-- visible hand cards	
	local player_cards = gamer.data_mgr_:cards_msg_protocol_of_player_self()
	print("[NormalRoomScene:initMahjongsOfPlayerSelf] invisible_mahjongs_num : ", player_cards:invisible_hand_cards_size())
	local visible_mahjongs_num = player_cards:visible_hand_cards_size()
	local ming_gang_num = self:getMingGangNum(visible_mahjongs_num)
	self.player_self_invisible_mj_offset_x_ = self:initVisibleMahjongsOfPlayerSelf(player_cards, ming_gang_num)
	
	-- invisible hand cards
	self:initInvisibleMahjongsOfPlayerSelf(player_cards, self.player_self_invisible_mj_offset_x_)
end

function NormalRoomScene:initMahjongsOfLeftPlayer()
	-- visible hand cards	
	local player_cards = gamer.data_mgr_.cards_msg_protocol_of_left_player()
	local visible_mahjongs_num = player_cards:visible_hand_cards_size()
	local ming_gang_num = self:getMingGangNum(visible_mahjongs_num)
	print("ming_gang_num : ", ming_gang_num)
	local offset_x, offset_y = self:initVisibleMahjongsOfLeftPlayer(player_cards, ming_gang_num)

	-- invisible hand cards	
	print("offset_x, offset_y : ", offset_x, offset_y)
	self:initInvisibleMahjongsOfLeftPlayer(player_cards, offset_x, offset_y)

	-- direction
	PlayCardHelper.setPlayerDirection(player_cards:player_id(), MahjongConst.Directions.LEFT)
end

function NormalRoomScene:initMahjongsOfOppositePlayer()
	self.invisible_mj_nodes_opposite_player_ = {}
	self.visible_mj_nodes_opposite_player_   = {} -- not including ming gang
	self.visible_ming_gang_mj_nodes_opposite_player_ = {}

	-- visible hand cards	
	local player_cards = gamer.data_mgr_:cards_msg_protocol_of_opposite_player()
	local visible_mahjongs_num = player_cards:visible_hand_cards_size()
	local ming_gang_num = self:getMingGangNum(visible_mahjongs_num)
	self.opposite_player_invisible_mj_offset_x_ = self:initVisibleMahjongsOfOppositePlayer(player_cards, ming_gang_num)

	-- invisible hand cards	
	self:initInvisibleMahjongsOfOppositePlayer(player_cards, self.opposite_player_invisible_mj_offset_x_)

	-- direction
	PlayCardHelper.setPlayerDirection(player_cards:player_id(), MahjongConst.Directions.OPPOSITE)
end

function NormalRoomScene:initMahjongsOfRightPlayer()
	-- visible hand cards	
	local player_cards = gamer.data_mgr_.cards_msg_protocol_of_right_player()
	local visible_mahjongs_num = player_cards:visible_hand_cards_size()
	local ming_gang_num = self:getMingGangNum(visible_mahjongs_num)
	local offset_x, offset_y = self:initVisibleMahjongsOfRightPlayer(player_cards, ming_gang_num)

	-- invisible hand cards	
	self:initInvisibleMahjongsOfRightPlayer(player_cards, offset_x, offset_y)

	-- direction
	PlayCardHelper.setPlayerDirection(player_cards:player_id(), MahjongConst.Directions.RIGHT)
end

-- @ return : position offset x for invisible card
function NormalRoomScene:initVisibleMahjongsOfPlayerSelf(mahjongs, ming_gang_num)
	-- ming gang
	local offset_x1 = MahjongConst.Sizes.OFFSET_X1
	for i = 1, ming_gang_num do
		local mj_node = MahjongCreator.create(MahjongConst.Directions.SELF, 
											  MahjongConst.Types.VISIBLE_MING_GANG, 
											  mahjongs:visible_hand_cards(4 * (i - 1)))
		if mj_node then
			offset_x1 = MahjongConst.Sizes.OFFSET_X2 + MahjongConst.Sizes.CARD_W3 * (i - 1)
			mj_node:setPosition(cc.p(offset_x1, MahjongConst.Sizes.OFFSET_Y2))
			self.mahjong_layer_:addChild(mj_node)

			table.insert(self.visible_ming_gang_mj_nodes_player_self_, mj_node)
		end
	end

	-- not ming gang
	local offset_x2 = MahjongConst.Sizes.OFFSET_X1
	if ming_gang_num > 0 then
		offset_x1 = offset_x1 + MahjongConst.Sizes.CARD_W3 / 2 + MahjongConst.Sizes.CARD_W1 / 2
	end

	local mahjongs_num = mahjongs:visible_hand_cards_size()
	for i = 4 * ming_gang_num, mahjongs_num - 1 do
		local mj_node = MahjongCreator.create(MahjongConst.Directions.SELF, 
										      MahjongConst.Types.VISIBLE, 
										      mahjongs:visible_hand_cards(i))

		if mj_node then
			offset_x2 = offset_x1 + MahjongConst.Sizes.CARD_W1 * (i - 4 * ming_gang_num)
			mj_node:setPosition(cc.p(offset_x2, MahjongConst.Sizes.OFFSET_Y1))
			self.mahjong_layer_:addChild(mj_node)

			table.insert(self.visible_mj_nodes_player_self_, mj_node)
		end
	end

	-- get offset x for invisible mahjongs
	local offset_x = 0
	if ming_gang_num > 0 then
		if offset_x2 ~= MahjongConst.Sizes.OFFSET_X1 then -- contain ming gang and peng(not ming gang) or chi  
			offset_x = offset_x2 + MahjongConst.Sizes.CARD_W1 / 2 + MahjongConst.Sizes.CARD_INTERVAL1
		else -- only contains ming gang 
			offset_x = offset_x1 + MahjongConst.Sizes.CARD_W1 / 2
		end
	else
		if mahjongs_num > 0 then
			offset_x = offset_x2 + MahjongConst.Sizes.CARD_W1 / 2 + MahjongConst.Sizes.CARD_INTERVAL1
		else
			offset_x = MahjongConst.Sizes.OFFSET_X1
		end
	end

	return offset_x
end

function NormalRoomScene:initInvisibleMahjongsOfPlayerSelf(mahjongs, offset_x)
	for i = 0, mahjongs:invisible_hand_cards_size() - 1 do
		local mj_node = MahjongCreator.create(MahjongConst.Directions.SELF, 
											  MahjongConst.Types.INVISIBLE, 
											  mahjongs:invisible_hand_cards(i))
		if mj_node then
			mj_node:setPosition(cc.p(offset_x + MahjongConst.Sizes.CARD_W2 * i, MahjongConst.Sizes.OFFSET_Y3))
			self.mahjong_layer_:addChild(mj_node)

			local img_bg = mj_node:getChildByName("img_bg")
			img_bg:setTouchEnabled(true)
			img_bg:addClickEventListener(handler(self, self.onMahjongNodeTouch))

			table.insert(self.invisible_mj_nodes_player_self_, mj_node)
		end
	end
end

-- @ return : position offset x, y for invisible card
function NormalRoomScene:initVisibleMahjongsOfLeftPlayer(mahjongs, ming_gang_num)
	-- ming gang
	local offset_x1 = MahjongConst.Sizes.LEFT_CARD_OFFSET_X0
	local offset_y1 = MahjongConst.Sizes.CARD_OFFSET_Y0
	for i = 1, ming_gang_num do
		local mj_node = MahjongCreator.create(MahjongConst.Directions.LEFT, 
											  MahjongConst.Types.VISIBLE_MING_GANG, 
											  mahjongs:visible_hand_cards(4 * (i - 1)))
		if mj_node then
			offset_x1 = MahjongConst.Sizes.LEFT_CARD_OFFSET_X0 - MahjongConst.Sizes.CARD_OFFSET_X3 * (i - 1)
			offset_y1 = MahjongConst.Sizes.CARD_OFFSET_Y0 - MahjongConst.Sizes.CARD_OFFSET_Y3 * (i - 1)
			mj_node:setPosition(cc.p(offset_x1, offset_y1))
			self.mahjong_layer_:addChild(mj_node)
		end
	end

	-- not ming gang
	local offset_x2 = MahjongConst.Sizes.LEFT_CARD_OFFSET_X0
	local offset_y2 = MahjongConst.Sizes.CARD_OFFSET_Y0
	if ming_gang_num > 0 then
		offset_x1 = offset_x1 - MahjongConst.Sizes.CARD_OFFSET_X3 / 2 - MahjongConst.Sizes.CARD_OFFSET_X1 / 2
		offset_y1 = offset_y1 - MahjongConst.Sizes.CARD_OFFSET_Y3 / 2 - MahjongConst.Sizes.CARD_OFFSET_Y1 / 2
	end

	local mahjongs_num = mahjongs:visible_hand_cards_size()
	for i = 4 * ming_gang_num, mahjongs_num - 1 do
		local mj_node = MahjongCreator.create(MahjongConst.Directions.LEFT, 
										      MahjongConst.Types.VISIBLE, 
										      mahjongs:visible_hand_cards(i))

		if mj_node then
			offset_x2 = offset_x1 - MahjongConst.Sizes.CARD_OFFSET_X1 * (i - 4 * ming_gang_num)
			offset_y2 = offset_y1 - MahjongConst.Sizes.CARD_OFFSET_Y1 * (i - 4 * ming_gang_num)
			mj_node:setPosition(cc.p(offset_x2, offset_y2))
			self.mahjong_layer_:addChild(mj_node)
		end
	end

	-- get cur offset
	local offset_x = 0
	local offset_y = 0
	if ming_gang_num > 0 then
		if offset_x2 ~= MahjongConst.Sizes.LEFT_CARD_OFFSET_X0 then -- contain ming gang and peng(not ming gang) or chi
			offset_x = offset_x2 - MahjongConst.Sizes.CARD_OFFSET_X1
			offset_y = offset_y2 - MahjongConst.Sizes.CARD_OFFSET_Y1
		else -- only contains ming gang 
			offset_x = offset_x1 - MahjongConst.Sizes.CARD_OFFSET_X1 / 2
			offset_y = offset_y1 - MahjongConst.Sizes.CARD_OFFSET_Y1 / 2
		end
	else
		if mahjongs_num > 0 then
			offset_x = offset_x2 - MahjongConst.Sizes.CARD_OFFSET_X1 / 2
			offset_y = offset_y2 - MahjongConst.Sizes.CARD_OFFSET_Y1 / 2
		else
			offset_x = MahjongConst.Sizes.LEFT_CARD_OFFSET_X0
			offset_y = MahjongConst.Sizes.CARD_OFFSET_Y0
		end
	end

	return offset_x, offset_y
end

function NormalRoomScene:initInvisibleMahjongsOfLeftPlayer(mahjongs, offset_x, offset_y)
	for i = 0, mahjongs:invisible_hand_cards_num() - 1 do
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
function NormalRoomScene:initVisibleMahjongsOfOppositePlayer(mahjongs, ming_gang_num)
	-- ming gang
	local myInsert = table.insert
	local offset_x1 = MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X0
	for i = 1, ming_gang_num do
		local mj_node = MahjongCreator.create(MahjongConst.Directions.OPPOSITE, 
											  MahjongConst.Types.VISIBLE_MING_GANG, 
											  mahjongs:visible_hand_cards(4 * (i - 1)))
		if mj_node then
			offset_x1 = MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X0 - 
			            MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1 * (i - 1)
			mj_node:setPosition(cc.p(offset_x1, MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_Y0))
			self.mahjong_layer_:addChild(mj_node)
			myInsert(self.visible_ming_gang_mj_nodes_opposite_player_, mj_node)
		end
	end

	-- not ming gang
	local offset_x2 = MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X0
	if ming_gang_num > 0 then
		offset_x1 = offset_x1 - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X3 / 2 - 
		            MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1 / 2
	end

	local mahjongs_num = mahjongs:visible_hand_cards_size()
	for i = 4 * ming_gang_num, mahjongs_num - 1 do
		local mj_node = MahjongCreator.create(MahjongConst.Directions.OPPOSITE, 
										      MahjongConst.Types.VISIBLE, 
										      mahjongs:visible_hand_cards(i))

		if mj_node then
			offset_x2 = offset_x1 - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1 * (i - 4 * ming_gang_num)
			mj_node:setPosition(cc.p(offset_x2, MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_Y0))
			self.mahjong_layer_:addChild(mj_node)
			myInsert(self.visible_mj_nodes_opposite_player_, mj_node)
		end
	end

	-- get cur offset x
	local offset_x = 0
	if ming_gang_num > 0 then
		if offset_x2 ~= MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X0 then -- contain ming gang and peng(not ming gang) or chi 
			offset_x = offset_x2 - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1 - MahjongConst.Sizes.CARD_INTERVAL2
		else -- only contains ming gang 
			offset_x = offset_x1 - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1 / 2
		end
	else
		if mahjongs_num > 0 then
			offset_x = offset_x2 - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1 - MahjongConst.Sizes.CARD_INTERVAL2
		else
			offset_x = MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X0
		end
	end

	return offset_x
end

function NormalRoomScene:initInvisibleMahjongsOfOppositePlayer(mahjongs, offset_x)
	print("NormalRoomScene:initInvisibleMahjongsOfOppositePlayer, invisible_hand_cards_num : ", mahjongs:invisible_hand_cards_num())
	local myInsert = table.insert
	for i = 0, mahjongs:invisible_hand_cards_num() - 1 do
		local mj_node = MahjongCreator.create(MahjongConst.Directions.OPPOSITE, 
											  MahjongConst.Types.INVISIBLE)
		if mj_node then
			mj_node:setPosition(cc.p(offset_x - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X2 * i, 
			                         MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_Y0))
			self.mahjong_layer_:addChild(mj_node)
			myInsert(self.invisible_mj_nodes_opposite_player_, mj_node)
		end
	end
end

-- @ return : position offset x, y for invisible card
function NormalRoomScene:initVisibleMahjongsOfRightPlayer(mahjongs, ming_gang_num)
	-- ming gang
	local offset_x1 = MahjongConst.Sizes.RIGHT_CARD_OFFSET_X0
	local offset_y1 = MahjongConst.Sizes.CARD_OFFSET_Y0
	for i = 1, ming_gang_num do
		local mj_node = MahjongCreator.create(MahjongConst.Directions.RIGHT, 
											  MahjongConst.Types.VISIBLE_MING_GANG, 
											  mahjongs:visible_hand_cards(4 * (i - 1)))
		if mj_node then
			offset_x1 = MahjongConst.Sizes.RIGHT_CARD_OFFSET_X0 + MahjongConst.Sizes.CARD_OFFSET_X3 * (i - 1)
			offset_y1 = MahjongConst.Sizes.CARD_OFFSET_Y0 - MahjongConst.Sizes.CARD_OFFSET_Y3 * (i - 1)
			mj_node:setPosition(cc.p(offset_x1, offset_y1))
			self.mahjong_layer_:addChild(mj_node)
		end
	end

	-- not ming gang
	local offset_x2 = MahjongConst.Sizes.RIGHT_CARD_OFFSET_X0
	local offset_y2 = MahjongConst.Sizes.CARD_OFFSET_Y0
	if ming_gang_num > 0 then
		offset_x1 = offset_x1 + MahjongConst.Sizes.CARD_OFFSET_X3 / 2 + MahjongConst.Sizes.CARD_OFFSET_X1 / 2
		offset_y1 = offset_y1 - MahjongConst.Sizes.CARD_OFFSET_Y3 / 2 - MahjongConst.Sizes.CARD_OFFSET_Y1 / 2
	end

	local mahjongs_num = mahjongs:visible_hand_cards_size()
	for i = 4 * ming_gang_num, mahjongs_num - 1 do
		local mj_node = MahjongCreator.create(MahjongConst.Directions.RIGHT, 
										      MahjongConst.Types.VISIBLE, 
										      mahjongs:visible_hand_cards(i))

		if mj_node then
			offset_x2 = offset_x1 + MahjongConst.Sizes.CARD_OFFSET_X1 * (i - 4 * ming_gang_num)
			offset_y2 = offset_y1 - MahjongConst.Sizes.CARD_OFFSET_Y1 * (i - 4 * ming_gang_num)
			mj_node:setPosition(cc.p(offset_x2, offset_y2))
			self.mahjong_layer_:addChild(mj_node)
		end
	end

	-- get cur offset
	local offset_x = 0
	local offset_y = 0
	if ming_gang_num > 0 then
		if offset_x2 ~= MahjongConst.Sizes.RIGHT_CARD_OFFSET_X0 then -- contain ming gang and peng(not ming gang) or chi
			offset_x = offset_x2 + MahjongConst.Sizes.CARD_OFFSET_X1
			offset_y = offset_y2 - MahjongConst.Sizes.CARD_OFFSET_Y1
		else -- only contains ming gang 
			offset_x = offset_x1 + MahjongConst.Sizes.CARD_OFFSET_X1 / 2
			offset_y = offset_y1 - MahjongConst.Sizes.CARD_OFFSET_Y1 / 2
		end
	else
		if mahjongs_num > 0 then
			offset_x = offset_x2 + MahjongConst.Sizes.CARD_OFFSET_X1 / 2
			offset_y = offset_y2 - MahjongConst.Sizes.CARD_OFFSET_Y1 / 2
		else
			offset_x = MahjongConst.Sizes.RIGHT_CARD_OFFSET_X0
			offset_y = MahjongConst.Sizes.CARD_OFFSET_Y0
		end
	end

	return offset_x, offset_y
end

function NormalRoomScene:initInvisibleMahjongsOfRightPlayer(mahjongs, offset_x, offset_y)
	for i = 0, mahjongs:invisible_hand_cards_num() - 1 do
		local mj_node = MahjongCreator.create(MahjongConst.Directions.RIGHT, 
											  MahjongConst.Types.INVISIBLE)
		if mj_node then
			mj_node:setPosition(cc.p(offset_x + MahjongConst.Sizes.CARD_OFFSET_X1 * i, 
			                         offset_y - MahjongConst.Sizes.CARD_OFFSET_Y1 * i))
			self.mahjong_layer_:addChild(mj_node)
		end
	end
end

function NormalRoomScene:getMingGangNum(visible_mahjongs_num)
	local ming_gang_num = 0
	if 4 == visible_mahjongs_num then      -- 1 ming gang
		ming_gang_num = 1
	elseif 7 == visible_mahjongs_num then  -- 1 ming gang
		ming_gang_num = 1
	elseif 8 == visible_mahjongs_num then  -- 2 ming gang
		ming_gang_num = 2
	elseif 10 == visible_mahjongs_num then -- 1 ming gang
		ming_gang_num = 1
	elseif 11 == visible_mahjongs_num then -- 2 ming gang
		ming_gang_num = 2
	elseif 12 == visible_mahjongs_num then -- 3 ming gang
		ming_gang_num = 3
	end
	return ming_gang_num
end

function NormalRoomScene:getNextDiscardPosOfPlayerSelf()
	local x, y = MahjongConst.Sizes.DISCARD_X1, MahjongConst.Sizes.DISCARD_Y1
	if self.player_self_last_discard_ then
		local pos_x, pos_y = self.player_self_last_discard_:getPosition() 
		--print("[NormalRoomScene:getNextDiscardPosOfPlayerSelf] pos_x, pos_y : ", pos_x,  pos_y)
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
		--print("[NormalRoomScene:getNextDiscardPosOfLeftPlayer] pos_x, pos_y : ", pos_x,  pos_y)
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
		--print("[NormalRoomScene:getNextDiscardPosOfOppositePlayer] pos_x, pos_y : ", pos_x,  pos_y)
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
		--print("[NormalRoomScene:getNextDiscardPosOfLeftPlayer] pos_x, pos_y : ", pos_x,  pos_y)
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

function NormalRoomScene:addVisibleMahjongNodesForPlayerSelf(mahjong_values)
	local offset_x = MahjongConst.Sizes.OFFSET_X1
	local n1 = #self.visible_ming_gang_mj_nodes_player_self_
	local n2 = #self.visible_mj_nodes_player_self_
	if n1 > 0 then
		offset_x = self.visible_ming_gang_mj_nodes_player_self_[n1]:getPositionX() + 
			        MahjongConst.Sizes.CARD_W3 / 2 + MahjongConst.Sizes.CARD_W1 / 2
	end
	if n2 > 0 then
		offset_x = offset_x + MahjongConst.Sizes.CARD_W1 * n2
	end

	local offsetx = MahjongConst.Sizes.OFFSET_X1
	for i = 1, #mahjong_values do
		local mj_node = MahjongCreator.create(MahjongConst.Directions.SELF, 
										      MahjongConst.Types.VISIBLE, 
										      mahjong_values[i])
		if mj_node then
			offsetx = offset_x + MahjongConst.Sizes.CARD_W1 * (i - 1)
			mj_node:setPosition(cc.p(offsetx, MahjongConst.Sizes.OFFSET_Y1))
			self.mahjong_layer_:addChild(mj_node)

			table.insert(self.visible_mj_nodes_player_self_, mj_node)
		end
	end

	return offsetx
end

function NormalRoomScene:addVisibleMahjongNodesForOppositePlayer(mahjong_values)
	local offset_x = MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X0
	local n1 = #self.visible_ming_gang_mj_nodes_opposite_player_
	local n2 = #self.visible_mj_nodes_opposite_player_
	if n1 > 0 then
		offset_x = self.visible_ming_gang_mj_nodes_opposite_player_[n1]:getPositionX() - 
			       MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X3 / 2 - 
				   MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1 / 2
	end
	if n2 > 0 then
		offset_x = offset_x - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1 * n2
	end

	local offsetx = MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X0
	for i = 1, #mahjong_values do
		local mj_node = MahjongCreator.create(MahjongConst.Directions.OPPOSITE, 
										      MahjongConst.Types.VISIBLE, 
										      mahjong_values[i])
		if mj_node then
			offsetx = offset_x - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1 * (i - 1)
			mj_node:setPosition(cc.p(offsetx, MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_Y0))
			self.mahjong_layer_:addChild(mj_node)

			table.insert(self.visible_mj_nodes_opposite_player_, mj_node)
		end
	end

	return offsetx
end

function NormalRoomScene:modifyInvisibleMjPosOfOppositePlayer(num, pos_last_visible_mj)
	-- remove num mahjong nodes from invisible mahjong nodes
	local n = #self.invisible_mj_nodes_opposite_player_
	if n < num then
		return
	end
	
	for i = 1, num do
		local last = n - i + 1
		self.invisible_mj_nodes_opposite_player_[last]:removeFromParent()
		table.remove(self.invisible_mj_nodes_opposite_player_, last)
	end

	-- modify invisibl mahjong nodes position
	self.opposite_player_invisible_mj_offset_x_ = pos_last_visible_mj - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1 - 
											      MahjongConst.Sizes.CARD_INTERVAL2
	self:resetPositionOfInvisibleMahjongsForOppositePlayer()
end

function NormalRoomScene:modifyMahjongsOfPlayerSelfAfterChi(cards)
	-- add 3 visivle mahjong nodes for chi
	local offset_x = self:addVisibleMahjongNodesForPlayerSelf(cards)

	-- remove 2 invisivle mahjong nodes those use to chi
	local discard = gamer.data_mgr_:play_card_msg_protocol():discard()
	for _, v in pairs(cards) do
		if v ~= discard then
			self:removeMahjongNode(self.invisible_mj_nodes_player_self_, v)
		end
	end

	-- modify position of invisivle mahjong nodes
	self.player_self_invisible_mj_offset_x_ = offset_x + MahjongConst.Sizes.CARD_W1 / 2 + 
			                                  MahjongConst.Sizes.CARD_INTERVAL1
	self:resetPositionOfInvisibleMahjongsForPlayerSelf()
end

function NormalRoomScene:modifyMahjongsOfPlayerSelfAfterPeng()
	local discard = gamer.data_mgr_:play_card_msg_protocol():discard()
	-- add 3 visivle mahjong nodes for peng
	local offset_x = self:addVisibleMahjongNodesForPlayerSelf({ discard, discard, discard })

	-- remove 2 invisivle mahjong nodes those use to peng
	self:removeMahjongNode(self.invisible_mj_nodes_player_self_, discard)
	self:removeMahjongNode(self.invisible_mj_nodes_player_self_, discard)

	-- modify position of invisivle mahjong nodes
	self.player_self_invisible_mj_offset_x_ = offset_x + MahjongConst.Sizes.CARD_W1 / 2 + 
			                                  MahjongConst.Sizes.CARD_INTERVAL1
	self:resetPositionOfInvisibleMahjongsForPlayerSelf()
end

function NormalRoomScene:modifyMahjongsOfOppositePlayerAfterChi()
	-- add mahjong for chi
	local proto = gamer.data_mgr_:play_card_msg_protocol()
	local size = proto:operating_cards_size()
	if size ~= 2 then
		print("[NormalRoomScene:modifyMahjongsOfOppositePlayerAfterChi] data error")
		return
	end

	local cards = { proto:discard(), proto:operating_cards(0), proto:operating_cards(1) }
	table.sort(cards)
	local offset_x = self:addVisibleMahjongNodesForOppositePlayer(cards)
	
	-- remove 2 mahjong nodes from invisible mahjong nodes and reset invisibl mahjong nodes position
	self:modifyInvisibleMjPosOfOppositePlayer(2, offset_x)
end

function NormalRoomScene:modifyMahjongsOfOppositePlayerAfterPeng()
	-- add mahjong for peng
	local discard = gamer.data_mgr_:play_card_msg_protocol():discard()
	local cards = { discard, discard, discard }
	local offset_x = self:addVisibleMahjongNodesForOppositePlayer(cards)

	-- remove 2 mahjong nodes from invisible mahjong nodes and reset invisibl mahjong nodes position
	self:modifyInvisibleMjPosOfOppositePlayer(2, offset_x)
end

function NormalRoomScene:modifyOtherPlayerMahjongsAfterChi()
	print("[NormalRoomScene:modifyOtherPlayerMahjongsAfterChi]")
	local player_id = gamer.data_mgr_:play_card_msg_protocol():player_id()
	local direction = PlayCardHelper.getPlayerDirection(player_id)
	print("[NormalRoomScene:modifyOtherPlayerMahjongsAfterChi] direction : ", direction)

	if direction == MahjongConst.Directions.LEFT then
	elseif direction == MahjongConst.Directions.OPPOSITE then
		self:modifyMahjongsOfOppositePlayerAfterChi()
	elseif direction == MahjongConst.Directions.RIGHT then
	end
end

function NormalRoomScene:modifyOtherPlayerMahjongsAfterPeng()
	print("[NormalRoomScene:modifyOtherPlayerMahjongsAfterPeng]")
	local player_id = gamer.data_mgr_:play_card_msg_protocol():player_id()
	local direction = PlayCardHelper.getPlayerDirection(player_id)

	if direction == MahjongConst.Directions.LEFT then
	elseif direction == MahjongConst.Directions.OPPOSITE then
		self:modifyMahjongsOfOppositePlayerAfterPeng()
	elseif direction == MahjongConst.Directions.RIGHT then
	end
end

function NormalRoomScene:showNextPlayCardDirection()
	if self.img_player_direction_ then
		self.img_player_direction_:setVisible(false)
	end

	local players_num = gamer.data_mgr_:room_msg_protocol():players_num()
	local cur_acting_player_id = gamer.data_mgr_:room_msg_protocol():cur_acting_player_id()
	local img_name = PlayCardHelper.getNextPlayerDirectionImageName(players_num, cur_acting_player_id)
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
		-- may be i have a new card
		if play_card_msg:new_card() ~= CardConst.CardValues.INVALID_CARD_VALUE then
			self:dealWithNewCardOfPlayerSelf(msg, true)
		end
	elseif operation_id == CardConst.OperationIDs.OPERATION_CHI then       -- chi
		self:showOperationChi()
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG then      -- peng
		self:showOperation(operation_id, "i_operation_peng.png", discard, true)
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG_GANG then -- peng + gang
		self:showOperation(operation_id, "i_operation_gang.png", discard, true)
	elseif operation_id == CardConst.OperationIDs.OPERATION_MING_GANG then -- ming gang
		self:showOperation(operation_id, "i_operation_gang.png", discard, true)
	elseif operation_id == CardConst.OperationIDs.OPERATION_AN_GANG then   -- an gang
		self:showOperation(operation_id, "i_operation_gang.png", discard, true)
	elseif operation_id == CardConst.OperationIDs.OPERATION_BU_HUA then    -- bu hua
		self:showOperation(operation_id, "i_operation_buhua.png", discard, false)
	elseif operation_id == CardConst.OperationIDs.OPERATION_HU then        -- hu
		self:showOperation(operation_id, "i_operation_hu.png", discard, true)
	elseif operation_id == CardConst.OperationIDs.OPERATION_ZI_MO then     -- zi mo
		self:showOperation(operation_id, "i_operation_zimo.png", discard, true)
	end
end

function NormalRoomScene:showOperationChi()
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

		local card1 = gamer.data_mgr_:play_card_msg_protocol():operating_cards(0)
		local card2 = gamer.data_mgr_:play_card_msg_protocol():operating_cards(1)
		local card3 = gamer.data_mgr_:play_card_msg_protocol():operating_cards(2)
		self.img_mj_chi_11_:loadTexture(MahjongCreator.getCardPng(card1), ccui.TextureResType.plistType)
		self.img_mj_chi_12_:loadTexture(MahjongCreator.getCardPng(card2), ccui.TextureResType.plistType)
		self.img_mj_chi_13_:loadTexture(MahjongCreator.getCardPng(card3), ccui.TextureResType.plistType)
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

		local card1 = gamer.data_mgr_:play_card_msg_protocol():operating_cards(3)
		local card2 = gamer.data_mgr_:play_card_msg_protocol():operating_cards(4)
		local card3 = gamer.data_mgr_:play_card_msg_protocol():operating_cards(5)
		self.img_mj_chi_21_:loadTexture(MahjongCreator.getCardPng(card1), ccui.TextureResType.plistType)
		self.img_mj_chi_22_:loadTexture(MahjongCreator.getCardPng(card2), ccui.TextureResType.plistType)
		self.img_mj_chi_23_:loadTexture(MahjongCreator.getCardPng(card3), ccui.TextureResType.plistType)
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

		local card1 = gamer.data_mgr_:play_card_msg_protocol():operating_cards(6)
		local card2 = gamer.data_mgr_:play_card_msg_protocol():operating_cards(7)
		local card3 = gamer.data_mgr_:play_card_msg_protocol():operating_cards(8)
		self.img_mj_chi_31_:loadTexture(MahjongCreator.getCardPng(card1), ccui.TextureResType.plistType)
		self.img_mj_chi_32_:loadTexture(MahjongCreator.getCardPng(card2), ccui.TextureResType.plistType)
		self.img_mj_chi_33_:loadTexture(MahjongCreator.getCardPng(card3), ccui.TextureResType.plistType)
	end

	local size = gamer.data_mgr_:play_card_msg_protocol():operating_cards_size()
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
end

function NormalRoomScene:hideOperations()
	if self.node_operation_ then
		self.node_operation_:setVisible(false)
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
		--print("[NormalRoomScene:showDiscardOfLeftPlayer] y : ", y)
		--print("[NormalRoomScene:showDiscardOfLeftPlayer] zorder : ", zorder)
		mj:setPosition(cc.p(x, y))
		mj:setLocalZOrder(zorder)
		self.mahjong_layer_:addChild(mj)

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

		self.opposite_player_last_discard_ = mj
	end
end

function NormalRoomScene:showDiscardOfRightPlayer(mahjong_value)
	local mj = MahjongCreator.create(MahjongConst.Directions.RIGHT, 
									 MahjongConst.Types.VISIBLE_DISCARD, 
									 mahjong_value)
	if mj then
		local x, y = self:getNextDiscardPosOfRightPlayer()
		--print("[NormalRoomScene:showDiscardOfRightPlayer] y : ", y)
		mj:setPosition(cc.p(x, y))
		self.mahjong_layer_:addChild(mj)

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

function NormalRoomScene:dealWithDiscardOfPlayerSelf(mahjong_node)
	-- add discard node
	local mahjong_value = mahjong_node:getTag()
	local mj = MahjongCreator.create(MahjongConst.Directions.SELF, 
									 MahjongConst.Types.VISIBLE_DISCARD, 
									 mahjong_value)
	if mj then
		local x, y = self:getNextDiscardPosOfPlayerSelf()
		mj:setPosition(cc.p(x, y))
		self.mahjong_layer_:addChild(mj)

		self.player_self_last_discard_ = mj
	end

	-- modify invisible mahjong position
	for k, v in pairs(self.invisible_mj_nodes_player_self_) do
		if mahjong_node == v then
			--print("[NormalRoomScene:dealWithDiscardOfPlayerSelf] remove mj node")
			table.remove(self.invisible_mj_nodes_player_self_, k)
			break
		end
	end

	self:resetPositionOfInvisibleMahjongsForPlayerSelf()

	mahjong_node:removeFromParent()
	self.last_selected_mj_ = nil	
end

function NormalRoomScene:dealWithNewCardOfPlayerSelf(play_card_msg, change_diretion)
	print("[NormalRoomScene:dealWithNewCardOfPlayerSelf]")
	print("[NormalRoomScene:dealWithNewCardOfPlayerSelf] new card : ", play_card_msg:new_card())
	PlayCardHelper.setNewCardOfPlayerSelf(play_card_msg:new_card())

	self:showNewCardOfPlayerSelf(play_card_msg:new_card())

	-- show timer and direction
	self:startPlayCardTimer()
	if change_diretion then
		self:showNextPlayCardDirection()
	end

	-- show zi mo or ming gang or an gang or bu hua
	--self:showAvailableOperationsForPlayerSelf(play_card_msg)
end

function NormalRoomScene:dealWithPlayCardMsgOfOtherPlayer(msg)
	print("[NormalRoomScene:dealWithPlayCardMsgOfOtherPlayer]")
	local operation_id = msg:operation_id()
	print("[NormalRoomScene:dealWithPlayCardMsgOfOtherPlayer] operation_id : ", operation_id)
	if operation_id == CardConst.OperationIDs.OPERATION_DISCARD then       -- discard
		-- show other player's discard and show available operations with that card
		self:showDiscardOfOtherPlayer(msg)
		self:showAvailableOperationsForPlayerSelf(msg)
	elseif operation_id == CardConst.OperationIDs.OPERATION_NONE then      
		
	elseif operation_id == CardConst.OperationIDs.OPERATION_CHI then       -- chi
		self:modifyOtherPlayerMahjongsAfterChi()
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG then      -- peng
		self:modifyOtherPlayerMahjongsAfterPeng()
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG_GANG then -- peng + gang

	elseif operation_id == CardConst.OperationIDs.OPERATION_MING_GANG then -- ming gang

	elseif operation_id == CardConst.OperationIDs.OPERATION_AN_GANG then   -- an gang

	elseif operation_id == CardConst.OperationIDs.OPERATION_BU_HUA then    -- bu hua

	elseif operation_id == CardConst.OperationIDs.OPERATION_HU then        -- hu

	elseif operation_id == CardConst.OperationIDs.OPERATION_ZI_MO then     -- zi mo

	elseif operation_id == CardConst.OperationIDs.OPERATION_GIVE_UP then   -- guo
		
	end
end

function NormalRoomScene:dealWithPlayCardMsgOfPlayerSelf(msg)
	print("[NormalRoomScene:dealWithPlayCardMsgOfPlayerSelf]")
	local operation_id = msg:operation_id()
	if operation_id == CardConst.OperationIDs.OPERATION_DISCARD then       -- discard
		-- update invisible hand card
		local new_card = PlayCardHelper.getNewCardOfPlayerSelf()
		if new_card ~= CardConst.CardValues.INVALID_CARD_VALUE then
			gamer.data_mgr_:updateCardForDiscard(msg:discard())
			PlayCardHelper.setNewCardOfPlayerSelf(CardConst.CardValues.INVALID_CARD_VALUE)
		end
	elseif operation_id == CardConst.OperationIDs.OPERATION_NONE then      -- new card
		self:dealWithNewCardOfPlayerSelf(msg, false)
	elseif operation_id == CardConst.OperationIDs.OPERATION_CHI then       -- chi
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG then      -- peng
	elseif operation_id == CardConst.OperationIDs.OPERATION_PENG_GANG then -- peng + gang
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
		self.node_operation_:setVisible(false)
		self:sendPlayCardMsg(CardConst.OperationIDs.OPERATION_PENG_GANG)
	elseif operation_id == CardConst.OperationIDs.OPERATION_MING_GANG then -- ming gang
		self:hideOperations()
		self:sendPlayCardMsg(CardConst.OperationIDs.OPERATION_MING_GANG)
	elseif operation_id == CardConst.OperationIDs.OPERATION_AN_GANG then   -- an gang
		self:hideOperations()
		self:sendPlayCardMsg(CardConst.OperationIDs.OPERATION_AN_GANG)
	elseif operation_id == CardConst.OperationIDs.OPERATION_BU_HUA then    -- bu hua
		self:hideOperations()

		-- send bu hua msg
		local discard = PlayCardHelper.getNewCardOfPlayerSelf()
		if discard ~= CardConst.CardValues.INVALID_CARD_VALUE then
			self:sendPlayCardMsg(CardConst.OperationIDs.OPERATION_BU_HUA, discard)
		end

		local n = #self.invisible_mj_nodes_player_self_
		local node_new_card = self.invisible_mj_nodes_player_self_[n]
		node_new_card:removeFromParent()
		table.remove(self.invisible_mj_nodes_player_self_, n)
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
		-- TODO : reset position y of pre selected mahjong
		if self.last_selected_mj_ then
			self.last_selected_mj_:setPositionY(MahjongConst.Sizes.OFFSET_Y3)
		end

		self.last_selected_mj_ = mj_node

	elseif y == MahjongConst.Sizes.OFFSET_Y4 then -- second selecte
		-- do play mahjong action, modify invisible mahjong position, send play mahjong msg 
		-- update play card timer and direction of next player to play card
		local mj_value = mj_node:getTag()
		print("[NormalRoomScene:onMahjongNodeTouch] mj_value : ", mj_value)
		self:dealWithDiscardOfPlayerSelf(mj_node)

		-- send play mahjong msg 
		self:sendPlayCardMsg(CardConst.OperationIDs.OPERATION_DISCARD, { mj_value })

		-- start play card timer and show direction of next player to play card
		self:startPlayCardTimer()
		self:showNextPlayCardDirection()
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