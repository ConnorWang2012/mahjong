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
	for i = 1, game_end_msg:game_end_data_size() do
		local item = self.root_node_:getChildByName("node_item" .. i)
		self:initItem(item, game_end_msg:game_end_data(i - 1), game_end_msg:winner_id())
	end

	for i = game_end_msg:game_end_data_size() + 1, 4 do
		local item = self.root_node_:getChildByName("node_item" .. i)
		item:setVisible(false)
	end
end

function GameEndPopup:initItem(item, item_data, winner_id)
    item:getChildByName("txt_name"):setString(item_data:nick_name())
	item:getChildByName("txt_score"):setString(item_data:diff_score_gold())
	if winner_id == item_data:player_id() then
		item:getChildByName("img_win"):setVisible(true)
	else
		item:getChildByName("img_win"):setVisible(false)
	end
end

function GameEndPopup:onEnter()
    print("[GameEndPopup:onEnter]")
end

function GameEndPopup:onExit()
    print("[GameEndPopup:onExit]")
end

return GameEndPopup