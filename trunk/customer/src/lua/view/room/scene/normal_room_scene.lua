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
local MahjongConst    = require "view.constant.mahjong_constants.lua"

function NormalRoomScene:ctor(view_file)
	print("[NormalRoomScene:ctor]")
    self.super.ctor(self, view_file)
	self:initLayout()
end

function NormalRoomScene:initLayout()
	self:initMahjongLayer()
end

function NormalRoomScene:initMahjongLayer()
	if not self.mahjong_layer_ then
		self.mahjong_layer_ = cc.Layer:create()
		self:addChild(self.mahjong_layer_)
	end

	self:initMahjongOfPlayerSelf()
	self:initMahjongOfLeftPlayer() -- TODO : remove
	self:initMahjongOfOppositePlayer() -- TODO : remove
	self:initMahjongOfRightPlayer() -- TODO : remove

	local players_num = gamer.g_data_mgr_.getRoomPlayersNum()
	if 2 == players_num then
		self:initMahjongOfOppositePlayer()
	elseif 3 == players_num then
		self:initMahjongOfLeftPlayer()
		self:initMahjongOfRightPlayer()
	elseif 4 == players_num then
		self:initMahjongOfLeftPlayer()
		self:initMahjongOfOppositePlayer()
		self:initMahjongOfRightPlayer()
	end
end

function NormalRoomScene:initMahjongOfPlayerSelf()
	-- visible hand cards	
	local player_cards = gamer.g_data_mgr_.getMahjongOfPlayerSelf()
	
	local playercards = gamer.protocol.PlayerCardsMsgProtocol()
--[[
	local playercards = gamer.protocol.PlayerCardsMsgProtocol()
	playercards:add_visible_hand_cards(11)
	playercards:add_visible_hand_cards(11)
	playercards:add_visible_hand_cards(11)
	playercards:add_visible_hand_cards(11)

	playercards:add_visible_hand_cards(21)
	playercards:add_visible_hand_cards(21)
	playercards:add_visible_hand_cards(21)
	playercards:add_visible_hand_cards(21)
	
	playercards:add_visible_hand_cards(31)
	playercards:add_visible_hand_cards(31)
	playercards:add_visible_hand_cards(31)
	playercards:add_visible_hand_cards(31)
]]
	local visible_mahjongs_num = playercards:visible_hand_cards_size()
	local ming_gang_num = self:getMingGangNum(visible_mahjongs_num)
	print("ming_gang_num : ", ming_gang_num)
	local offset_x = self:initVisibleMahjongOfPlayerSelf(playercards, ming_gang_num)
	
	-- invisible hand cards
	print("offset_x : ", offset_x)
	self:initInvisibleMahjongOfPlayerSelf(player_cards, offset_x)
end

function NormalRoomScene:initMahjongOfLeftPlayer()
	-- visible hand cards	
	local player_cards = gamer.g_data_mgr_.getMahjongOfPlayerSelf()

	local playercards = gamer.protocol.PlayerCardsMsgProtocol()
	playercards:add_visible_hand_cards(11)
	playercards:add_visible_hand_cards(11)
	playercards:add_visible_hand_cards(11)
	playercards:add_visible_hand_cards(11)

	playercards:add_visible_hand_cards(47)
	playercards:add_visible_hand_cards(47)
	playercards:add_visible_hand_cards(47)
--[[	playercards:add_visible_hand_cards(47)

	playercards:add_visible_hand_cards(45)
	playercards:add_visible_hand_cards(45)
	playercards:add_visible_hand_cards(45)
	playercards:add_visible_hand_cards(45)
]]
	local visible_mahjongs_num = playercards:visible_hand_cards_size()
	local ming_gang_num = self:getMingGangNum(visible_mahjongs_num)
	print("ming_gang_num : ", ming_gang_num)
	local offset_x, offset_y = self:initVisibleMahjongOfLeftPlayer(playercards, ming_gang_num)

	-- invisible hand cards	
	print("offset_x, offset_y : ", offset_x, offset_y)
	self:initInvisibleMahjongOfLeftPlayer(player_cards, offset_x, offset_y)
end

function NormalRoomScene:initMahjongOfOppositePlayer()
	-- visible hand cards	
	local player_cards = gamer.g_data_mgr_.getMahjongOfPlayerSelf()

	local playercards = gamer.protocol.PlayerCardsMsgProtocol()
	playercards:add_visible_hand_cards(11)
	playercards:add_visible_hand_cards(11)
	playercards:add_visible_hand_cards(11)
	playercards:add_visible_hand_cards(11)

	playercards:add_visible_hand_cards(47)
	playercards:add_visible_hand_cards(47)
	playercards:add_visible_hand_cards(47)
--[[	playercards:add_visible_hand_cards(47)

	playercards:add_visible_hand_cards(45)
	playercards:add_visible_hand_cards(45)
	playercards:add_visible_hand_cards(45)
	playercards:add_visible_hand_cards(45)
]]
	local visible_mahjongs_num = playercards:visible_hand_cards_size()
	local ming_gang_num = self:getMingGangNum(visible_mahjongs_num)
	print("ming_gang_num : ", ming_gang_num)
	local offset_x = self:initVisibleMahjongOfOppositePlayer(playercards, ming_gang_num)

	-- invisible hand cards	
	print("offset_x : ", offset_x)
	self:initInvisibleMahjongOfOppositePlayer(player_cards, offset_x)
end

function NormalRoomScene:initMahjongOfRightPlayer()
	-- visible hand cards	
	local player_cards = gamer.g_data_mgr_.getMahjongOfPlayerSelf()

	local playercards = gamer.protocol.PlayerCardsMsgProtocol()
	playercards:add_visible_hand_cards(11)
	playercards:add_visible_hand_cards(11)
	playercards:add_visible_hand_cards(11)
	playercards:add_visible_hand_cards(11)

	playercards:add_visible_hand_cards(37)
	playercards:add_visible_hand_cards(37)
	playercards:add_visible_hand_cards(37)
--[[	playercards:add_visible_hand_cards(37)

	playercards:add_visible_hand_cards(45)
	playercards:add_visible_hand_cards(45)
	playercards:add_visible_hand_cards(45)
	playercards:add_visible_hand_cards(45)
]]
	local visible_mahjongs_num = playercards:visible_hand_cards_size()
	local ming_gang_num = self:getMingGangNum(visible_mahjongs_num)
	print("ming_gang_num : ", ming_gang_num)
	local offset_x, offset_y = self:initVisibleMahjongOfRightPlayer(playercards, ming_gang_num)

	-- invisible hand cards	
	print("offset_x, offset_y : ", offset_x, offset_y)
	self:initInvisibleMahjongOfRightPlayer(player_cards, offset_x, offset_y)
end

-- maybe contain 0 or 1 or 2 or 3 ming gang
-- @ return : position offset x of invisible card
function NormalRoomScene:initVisibleMahjongOfPlayerSelf(mahjongs, ming_gang_num)
	-- ming gang
	local offset_x1 = MahjongConst.Sizes.OFFSET_X1
	for i = 1, ming_gang_num do
		local mj_node = MahjongCreator.create(mahjongs:visible_hand_cards(4 * (i - 1)),
											  MahjongConst.Directions.SELF, 
											  MahjongConst.Types.VISIBLE_MING_GANG, 
											  MahjongConst.States.NORMAL)
		if mj_node then
			offset_x1 = MahjongConst.Sizes.OFFSET_X2 + MahjongConst.Sizes.CARD_W3 * (i - 1)
			mj_node:setPosition(cc.p(offset_x1, MahjongConst.Sizes.OFFSET_Y2))
			self.mahjong_layer_:addChild(mj_node)
		end
	end

	-- not ming gang
	local offset_x2 = MahjongConst.Sizes.OFFSET_X1
	if ming_gang_num > 0 then
		offset_x1 = offset_x1 + MahjongConst.Sizes.CARD_W3 / 2 + MahjongConst.Sizes.CARD_W1 / 2
	end

	local mahjongs_num = mahjongs:visible_hand_cards_size()
	for i = 4 * ming_gang_num, mahjongs_num - 1 do
		local mj_node = MahjongCreator.create(mahjongs:visible_hand_cards(i), 
										      MahjongConst.Directions.SELF, 
										      MahjongConst.Types.VISIBLE, 
										      MahjongConst.States.NORMAL)

		if mj_node then
			offset_x2 = offset_x1 + MahjongConst.Sizes.CARD_W1 * (i - 4 * ming_gang_num)
			mj_node:setPosition(cc.p(offset_x2, MahjongConst.Sizes.OFFSET_Y1))
			self.mahjong_layer_:addChild(mj_node)
		end
	end

	-- get cur offset x
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

function NormalRoomScene:initInvisibleMahjongOfPlayerSelf(mahjongs, offset_x)
	for i = 0, mahjongs:invisible_hand_cards_size() - 1 do
		local mj_node = MahjongCreator.create(mahjongs:invisible_hand_cards(i), 
											  MahjongConst.Directions.SELF, 
											  MahjongConst.Types.INVISIBLE, 
											  MahjongConst.States.NORMAL)
		if mj_node then
			mj_node:setPosition(cc.p(offset_x + MahjongConst.Sizes.CARD_W2 * i, MahjongConst.Sizes.OFFSET_Y3))
			self.mahjong_layer_:addChild(mj_node)

			local img_bg = mj_node:getChildByName("img_bg")
			img_bg:setTouchEnabled(true)
			img_bg:addClickEventListener(handler(self, self.onMahjongNodeTouch))
		end
	end
end

-- maybe contain 0 or 1 or 2 or 3 ming gang
-- @ return : position offset x, y of invisible card
function NormalRoomScene:initVisibleMahjongOfLeftPlayer(mahjongs, ming_gang_num)
	-- ming gang
	local offset_x1 = MahjongConst.Sizes.LEFT_CARD_OFFSET_X0
	local offset_y1 = MahjongConst.Sizes.CARD_OFFSET_Y0
	for i = 1, ming_gang_num do
		local mj_node = MahjongCreator.create(mahjongs:visible_hand_cards(4 * (i - 1)),
											  MahjongConst.Directions.LEFT, 
											  MahjongConst.Types.VISIBLE_MING_GANG, 
											  MahjongConst.States.NORMAL)
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
		local mj_node = MahjongCreator.create(mahjongs:visible_hand_cards(i), 
										      MahjongConst.Directions.LEFT, 
										      MahjongConst.Types.VISIBLE, 
										      MahjongConst.States.NORMAL)

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

function NormalRoomScene:initInvisibleMahjongOfLeftPlayer(mahjongs, offset_x, offset_y)
	for i = 0, mahjongs:invisible_hand_cards_size() - 1 do
		local mj_node = MahjongCreator.create(mahjongs:invisible_hand_cards(i), 
											  MahjongConst.Directions.LEFT, 
											  MahjongConst.Types.INVISIBLE, 
											  MahjongConst.States.NORMAL)
		if mj_node then
			mj_node:setPosition(cc.p(offset_x - MahjongConst.Sizes.CARD_OFFSET_X1 * i, 
			                         offset_y - MahjongConst.Sizes.CARD_OFFSET_Y1 * i))
			self.mahjong_layer_:addChild(mj_node)
		end
	end
end

-- maybe contain 0 or 1 or 2 or 3 ming gang
-- @ return : position offset x of invisible card
function NormalRoomScene:initVisibleMahjongOfOppositePlayer(mahjongs, ming_gang_num)
	-- ming gang
	local offset_x1 = MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X0
	for i = 1, ming_gang_num do
		local mj_node = MahjongCreator.create(mahjongs:visible_hand_cards(4 * (i - 1)),
											  MahjongConst.Directions.OPPOSITE, 
											  MahjongConst.Types.VISIBLE_MING_GANG, 
											  MahjongConst.States.NORMAL)
		if mj_node then
			offset_x1 = MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X0 - 
			            MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1 * (i - 1)
			mj_node:setPosition(cc.p(offset_x1, MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_Y0))
			self.mahjong_layer_:addChild(mj_node)
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
		local mj_node = MahjongCreator.create(mahjongs:visible_hand_cards(i), 
										      MahjongConst.Directions.OPPOSITE, 
										      MahjongConst.Types.VISIBLE, 
										      MahjongConst.States.NORMAL)

		if mj_node then
			offset_x2 = offset_x1 - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X1 * (i - 4 * ming_gang_num)
			mj_node:setPosition(cc.p(offset_x2, MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_Y0))
			self.mahjong_layer_:addChild(mj_node)
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

function NormalRoomScene:initInvisibleMahjongOfOppositePlayer(mahjongs, offset_x)
	for i = 0, mahjongs:invisible_hand_cards_size() - 1 do
		local mj_node = MahjongCreator.create(mahjongs:invisible_hand_cards(i), 
											  MahjongConst.Directions.OPPOSITE, 
											  MahjongConst.Types.INVISIBLE, 
											  MahjongConst.States.NORMAL)
		if mj_node then
			mj_node:setPosition(cc.p(offset_x - MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_X2 * i, 
			                         MahjongConst.Sizes.OPPOSITE_CARD_OFFSET_Y0))
			self.mahjong_layer_:addChild(mj_node)
		end
	end
end

-- maybe contain 0 or 1 or 2 or 3 ming gang
-- @ return : position offset x, y of invisible card
function NormalRoomScene:initVisibleMahjongOfRightPlayer(mahjongs, ming_gang_num)
	-- ming gang
	local offset_x1 = MahjongConst.Sizes.RIGHT_CARD_OFFSET_X0
	local offset_y1 = MahjongConst.Sizes.CARD_OFFSET_Y0
	for i = 1, ming_gang_num do
		local mj_node = MahjongCreator.create(mahjongs:visible_hand_cards(4 * (i - 1)),
											  MahjongConst.Directions.RIGHT, 
											  MahjongConst.Types.VISIBLE_MING_GANG, 
											  MahjongConst.States.NORMAL)
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
		local mj_node = MahjongCreator.create(mahjongs:visible_hand_cards(i), 
										      MahjongConst.Directions.RIGHT, 
										      MahjongConst.Types.VISIBLE, 
										      MahjongConst.States.NORMAL)

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

function NormalRoomScene:initInvisibleMahjongOfRightPlayer(mahjongs, offset_x, offset_y)
	for i = 0, mahjongs:invisible_hand_cards_size() - 1 do
		local mj_node = MahjongCreator.create(mahjongs:invisible_hand_cards(i), 
											  MahjongConst.Directions.RIGHT, 
											  MahjongConst.Types.INVISIBLE, 
											  MahjongConst.States.NORMAL)
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

function NormalRoomScene:dealWithDiscardOfPlayerSelf(mahjong_value)
	local mj = MahjongCreator.create(mahjong_value, 
									 MahjongConst.Directions.SELF, 
									 MahjongConst.Types.VISIBLE_DISCARD, 
									 MahjongConst.States.NORMAL)
	if mj then
		local x, y = self:getNextDiscardPosOfPlayerSelf()
		mj:setPosition(cc.p(x, y))
		self.mahjong_layer_:addChild(mj)

		self.player_self_last_discard_ = mj
	end
end

function NormalRoomScene:dealWithDiscardOfLeftPlayer(mahjong_value)
	local mj = MahjongCreator.create(mahjong_value, 
									 MahjongConst.Directions.LEFT, 
									 MahjongConst.Types.VISIBLE_DISCARD, 
									 MahjongConst.States.NORMAL)
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
		--print("[NormalRoomScene:dealWithDiscardOfLeftPlayer] y : ", y)
		--print("[NormalRoomScene:dealWithDiscardOfLeftPlayer] zorder : ", zorder)
		mj:setPosition(cc.p(x, y))
		mj:setLocalZOrder(zorder)
		self.mahjong_layer_:addChild(mj)

		self.left_player_last_discard_ = mj
	end
end

function NormalRoomScene:dealWithDiscardOfOppositePlayer(mahjong_value)
	local mj = MahjongCreator.create(mahjong_value, 
									 MahjongConst.Directions.OPPOSITE, 
									 MahjongConst.Types.VISIBLE_DISCARD, 
									 MahjongConst.States.NORMAL)
	if mj then
		local x, y = self:getNextDiscardPosOfOppositePlayer()
		mj:setPosition(cc.p(x, y))
		self.mahjong_layer_:addChild(mj)

		self.opposite_player_last_discard_ = mj
	end
end

function NormalRoomScene:dealWithDiscardOfRightPlayer(mahjong_value)
	local mj = MahjongCreator.create(mahjong_value, 
									 MahjongConst.Directions.RIGHT, 
									 MahjongConst.Types.VISIBLE_DISCARD, 
									 MahjongConst.States.NORMAL)
	if mj then
		local x, y = self:getNextDiscardPosOfRightPlayer()
		--print("[NormalRoomScene:dealWithDiscardOfRightPlayer] y : ", y)
		mj:setPosition(cc.p(x, y))
		self.mahjong_layer_:addChild(mj)

		self.right_player_last_discard_ = mj
	end
end

function NormalRoomScene:onMahjongNodeTouch(sender)
    print("[NormalRoomScene:onMahjongNodeTouch]")
	local mj_node = sender:getParent()
	local y = mj_node:getPositionY() 
	--print("[NormalRoomScene:onMahjongNodeTouch] y : ", y)
	if y == MahjongConst.Sizes.OFFSET_Y3 then -- first selecte
		mj_node:setPositionY(MahjongConst.Sizes.OFFSET_Y4)
		-- TODO : reset position y of pre selected mahjong
		if self.last_selected_mj_ then
			self.last_selected_mj_:setPositionY(MahjongConst.Sizes.OFFSET_Y3)
		end

		self.last_selected_mj_ = mj_node

	elseif y == MahjongConst.Sizes.OFFSET_Y4 then -- second selecte
		-- TODO : do play mahjong action, modify invisible mahjong position, send play mahjong msg 
		local mj_value = mj_node:getTag()
		print("[NormalRoomScene:onMahjongNodeTouch] mj_value : ", mj_value)
		--[[
		do
			self:dealWithDiscardOfOppositePlayer(mj_value)
			self:dealWithDiscardOfLeftPlayer(mj_value)
			self:dealWithDiscardOfRightPlayer(mj_value)
		end
		]]

		self:dealWithDiscardOfPlayerSelf(mj_value)
		mj_node:removeFromParent()
		self.last_selected_mj_ = nil	
	end
end

function NormalRoomScene:onEnter()
	-- TODO : dispatch layer enter event to all listeners
    print("[NormalRoomScene:onEnter]")
	--[[local player_cards = gamer.g_data_mgr_.getMahjongOfPlayerSelf()
	for i = 0, player_cards:invisible_hand_cards_size() - 1 do
		print("[NormalRoomScene:onEnter] i : ",  i)
		print("[NormalRoomScene:onEnter] invisible_hand_cards : ", player_cards:invisible_hand_cards(i))
	end
	]]
end

function NormalRoomScene:onExit()
	-- TODO : dispatch layer exit event to all listeners
    print("[NormalRoomScene:onExit]")
end

return NormalRoomScene