--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   game_end_popup.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-07-27
@ description: game end popup.
@ others:
@ history:
1.date:
author:
modification:
--]]

local GameEndPopup = class("GameEndPopup", require "view.base.popup_base")

function GameEndPopup:ctor(view_file, ...)
	print("[GameEndPopup:ctor]")
    self.super.ctor(self, view_file)

	local msg = ...
	self:initLayout(msg)
end

function GameEndPopup:initLayout(game_end_msg)
	-- items
	for i = 1, game_end_msg:game_end_data_size() do
		local item = self.root_node_:getChildByName("node_item" .. i)
		self:initItem(item, game_end_msg:game_end_data(i - 1), game_end_msg)
	end

	for i = game_end_msg:game_end_data_size() + 1, 4 do
		local item = self.root_node_:getChildByName("node_item" .. i)
		item:setVisible(false)
	end

	-- btn
	local img_goback_hall = self.root_node_:getChildByName("img_go_back_hall")
	img_goback_hall:setTouchEnabled(true)
	img_goback_hall:addClickEventListener(handler(self, self.onImgGobackHallTouch))

	local img_play_again = self.root_node_:getChildByName("img_play_again")
	img_play_again:setTouchEnabled(true)
	img_play_again:addClickEventListener(handler(self, self.onImgPlayAgainTouch))
end

function GameEndPopup:initItem(item, item_data, data)
	item:getChildByName("txt_name"):setString(item_data:nick_name())
	item:getChildByName("txt_round_num"):setString(data:total_round())
	item:getChildByName("txt_win_rate"):setString(math.floor(item_data:rate_winning() * 100) .. "%")
    item:getChildByName("txt_ming_gang_num"):setString(item_data:num_ming_gang())
	item:getChildByName("txt_an_gang_num"):setString(item_data:num_an_gang())
	item:getChildByName("txt_score"):setString(item_data:diff_score_gold())
	if data:winner_id() == item_data:player_id() then
		item:getChildByName("img_win"):setVisible(true)
	else
		item:getChildByName("img_win"):setVisible(false)
	end
end

function GameEndPopup:onImgGobackHallTouch()
	gamer.scene_mgr_.runScene(gamer.SceneConstants.SceneIDs.HALL_SCENE)
end

function GameEndPopup:onImgPlayAgainTouch()
	gamer.msg_helper_.sendStartGameMsg()
	self:removeFromParent(true)
end

function GameEndPopup:onEnter()
    print("[GameEndPopup:onEnter]")
end

function GameEndPopup:onExit()
    print("[GameEndPopup:onExit]")
end

return GameEndPopup