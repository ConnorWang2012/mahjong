--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   hall_player_info_popup.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-12-17
@ description: hall player info popup.
@ others:
@ history:
1.date:
author:
modification:
--]]

local HallPlayerInfoPopup = class("HallPlayerInfoPopup", require "view.base.popup_base")
local PlayerConst         = require "logic.constant.player_constants.lua"

function HallPlayerInfoPopup:ctor(view_file)
	print("[HallPlayerInfoPopup:ctor]")
    self.super.ctor(self, view_file)

	self:closeWhenTouchBackground(true)

	self:showLoadingView()
end

function HallPlayerInfoPopup:initLayout(player_info_msg)
	local panel_data = self.root_node_:getChildByName("panel_data")
	local txt_nickname = panel_data:getChildByName("txt_nickname")
	txt_nickname:setString(player_info_msg:nick_name())

	local img_female_selected = panel_data:getChildByName("img_female_selected")
	local img_male_selected = panel_data:getChildByName("img_male_selected")
	if player_info_msg:sex() == PlayerConst.Sex.FEMALE then
		img_female_selected:setVisible(true)
		img_male_selected:setVisible(false)
	else
		img_female_selected:setVisible(false)
		img_male_selected:setVisible(true)
	end

	local txt_gold = panel_data:getChildByName("txt_gold")
	txt_gold:setString(player_info_msg:score_gold())

	local txt_lv = panel_data:getChildByName("txt_lv")
	txt_lv:setString("Lv." .. player_info_msg:level())

	local txt_win_loss = panel_data:getChildByName("txt_win_loss")
	local total        = player_info_msg:num_played_games()
	local win          = player_info_msg:num_win_games()
	local loss         = player_info_msg:num_loss_games()
	local draw         = total - win - loss
	txt_win_loss:setString(string.format("%d胜//%d平//%d负", win, draw, loss))

	local txt_win_rate = panel_data:getChildByName("txt_win_rate")
	local win_rate = "0%"
	if total > 0 then
		win_rate = string.format("%0.2f%%", win / total)
	end
	txt_win_rate:setString(win_rate)

	local txt_vip_tip = panel_data:getChildByName("txt_vip_tip")
	if player_info_msg:vip_level() <= 0 then
		txt_vip_tip:setString("您现在还不是VIP")
	else
		txt_vip_tip:setString("VIP：" .. player_info_msg:vip_level())
	end
end

function HallPlayerInfoPopup:dealWithGetPlayerInfoMsgReceived(code, msg)
	print("[HallPlayerInfoPopup:dealWithGetPlayerInfoMsgReceived]")
	if tolua.isnull(self) then
		print("[HallPlayerInfoPopup:dealWithGetPlayerInfoMsgReceived] tolua.isnull(self)")
		return
	end

	if code == gamer.MsgCodes.SUCCEED then
		self:initLayout(msg)
		self:showDataView(msg)
	else
		self:showEmptyView()
	end
end

function HallPlayerInfoPopup:addEventListeners()
	print("[HallPlayerInfoPopup:addEventListeners]")
	gamer.msg_mgr_:addMsgListener(gamer.MsgTypes.S2C_MSG_TYPE_PROPERTY, handler(self, self.onServerMsgReceived))
end

function HallPlayerInfoPopup:removeEventListeners()
	print("[HallPlayerInfoPopup:removeEventListeners]")
end

function HallPlayerInfoPopup:onServerMsgReceived(code, msg_type, msg_id, msg)
    print("[HallPlayerInfoPopup:onServerMsgReceived] code, msg_type, msg_id : ", code, msg_type, msg_id)
	if code ~= gamer.MsgCodes.SUCCEED then
		print("[HallPlayerInfoPopup:onServerMsgReceived] error")
	end

	if msg_type == gamer.MsgTypes.S2C_MSG_TYPE_PROPERTY then
		if msg_id == gamer.MsgIDs.MSG_ID_PROPERTY_GET_PLAYER_INFO then
			self:dealWithGetPlayerInfoMsgReceived(code, msg)
		end
	end
end

function HallPlayerInfoPopup:onEnter()
    print("[HallPlayerInfoPopup:onEnter]")
	self:addEventListeners()
	gamer.msg_helper_.sendGetPlayerInfoMsg()
end

function HallPlayerInfoPopup:onExit()
    print("[HallPlayerInfoPopup:onExit]")
	self:removeEventListeners()
end

return HallPlayerInfoPopup