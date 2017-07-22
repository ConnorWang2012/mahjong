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
	self:initMahjongOfLeftPlayer()
	self:initMahjongOfOppositePlayer()
	self:initMahjongOfRightPlayer()
end

function NormalRoomScene:initMahjongOfPlayerSelf()
	-- visible hand cards	
	local player_cards = gamer.g_data_mgr_.getMahjongOfPlayerSelf()
	
	local playercards = gamer.protocol.PlayerCardsMsgProtocol()
--[[	playercards:add_visible_hand_cards(11)
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
	local invisible_hand_cards_size = player_cards:invisible_hand_cards_size()
	self:initInvisibleMahjongOfPlayerSelf(player_cards, invisible_hand_cards_size, offset_x)
end

function NormalRoomScene:initMahjongOfLeftPlayer()
	
end

function NormalRoomScene:initMahjongOfOppositePlayer()
	
end

function NormalRoomScene:initMahjongOfRightPlayer()
	
end

-- maybe con 0 or 1 or 2 or 3 ming gang
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

	--for i = 4 * ming_gang_num, mahjongs_num - ming_gang_num do
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

	local offset_x = 0
	if ming_gang_num > 0 then
		if offset_x2 ~= MahjongConst.Sizes.OFFSET_X1 then -- contain ming gang and not ming gang 
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

function NormalRoomScene:initInvisibleMahjongOfPlayerSelf(mahjongs, mahjongs_num, offset_x)
	for i = 0, mahjongs_num - 1 do
		local mj_node = MahjongCreator.create(mahjongs:invisible_hand_cards(i), 
											  MahjongConst.Directions.SELF, 
											  MahjongConst.Types.INVISIBLE, 
											  MahjongConst.States.NORMAL)
		if mj_node then
			mj_node:setPosition(cc.p(offset_x + MahjongConst.Sizes.CARD_W2 * i, MahjongConst.Sizes.OFFSET_Y3))
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