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
	-- nick name
	self.panel_data_ = self.root_node_:getChildByName("panel_data")

	self:initNickname(player_info_msg:nick_name())

	local img_modify_nickname = self.panel_data_:getChildByName("img_modify_nickname")
	img_modify_nickname:setTouchEnabled(true)
	img_modify_nickname:addClickEventListener(handler(self, self.onImgModifyNicknameTouch))

	-- sex
	local img_sex = self.panel_data_:getChildByName("img_female_select_bg")
	img_sex:setTag(PlayerConst.Sex.FEMALE)
	img_sex:setTouchEnabled(true)
	img_sex:addClickEventListener(handler(self, self.onImgModifySexTouch))

	img_sex = self.panel_data_:getChildByName("img_male_select_bg")
	img_sex:setTag(PlayerConst.Sex.MALE)
	img_sex:setTouchEnabled(true)
	img_sex:addClickEventListener(handler(self, self.onImgModifySexTouch))

	self:initSex(player_info_msg:sex())

	-- head portrait
	local node_head = self.panel_data_:getChildByName("node_head")
	local img_head = node_head:getChildByName("img_head")
	img_head:setTouchEnabled(true)
	img_head:addClickEventListener(handler(self, self.onImgHeadPortraitTouch))

	-- score gold
	local txt_gold = self.panel_data_:getChildByName("txt_gold")
	txt_gold:setString(player_info_msg:score_gold())

	-- level
	local txt_lv = self.panel_data_:getChildByName("txt_lv")
	txt_lv:setString("Lv." .. player_info_msg:level())

	-- win loss games num
	local txt_win_loss = self.panel_data_:getChildByName("txt_win_loss")
	local total        = player_info_msg:num_played_games()
	local win          = player_info_msg:num_win_games()
	local loss         = player_info_msg:num_loss_games()
	local draw         = total - win - loss
	txt_win_loss:setString(string.format(gamer.strings_["str_win_draw_loss"], win, draw, loss))

	-- win rate
	local txt_win_rate = self.panel_data_:getChildByName("txt_win_rate")
	local win_rate = "0%"
	if total > 0 then
		win_rate = string.format("%0.2f%%", win / total)
	end
	txt_win_rate:setString(win_rate)

	-- vip level
	local txt_vip_tip = self.panel_data_:getChildByName("txt_vip_tip")
	if player_info_msg:vip_level() <= 0 then
		txt_vip_tip:setString(gamer.strings_["str_not_vip_tip"])
	else
		txt_vip_tip:setString(gamer.strings_["str_vip_lv"], player_info_msg:vip_level())
	end
end

function HallPlayerInfoPopup:initNickname(nickname)
	print("[HallPlayerInfoPopup:initNickname] nickname :", nickname)
	if nickname then
		local txt_nickname = self.panel_data_:getChildByName("txt_nickname")
		txt_nickname:setString(nickname)
	end
end

function HallPlayerInfoPopup:initSex(sex)
	print("[HallPlayerInfoPopup:initSex] sex :", sex)
	if sex then
		local img_female_selected = self.panel_data_:getChildByName("img_female_selected")
		local img_male_selected = self.panel_data_:getChildByName("img_male_selected")
		if tonumber(sex) == PlayerConst.Sex.FEMALE then
			img_female_selected:setVisible(true)
			img_male_selected:setVisible(false)
		else
			img_female_selected:setVisible(false)
			img_male_selected:setVisible(true)
		end
	end
end

function HallPlayerInfoPopup:initPersonalHeadPortrait(buffer)
	print("[HallPlayerInfoPopup:initPersonalHeadPortrait]")
end

function HallPlayerInfoPopup:initLocalHeadPortrait(head_id)
	print("[HallPlayerInfoPopup:initLocalHeadPortrait]")
end

function HallPlayerInfoPopup:setProperty(set_property_msg)
	print("[HallPlayerInfoPopup:setProperty]")

	if set_property_msg then
		for i = 0, set_property_msg:property_ids_size() - 1 do
			local prop_id = set_property_msg:property_ids(i)
			print("[HallPlayerInfoPopup:setProperty] property_id :", prop_id)
			if prop_id == gamer.PropertyIDs.PROP_ID_NICKNAME then
				self:initNickname(set_property_msg:new_properties(i))
			elseif prop_id == gamer.PropertyIDs.PROP_ID_SEX then
				self:initSex(set_property_msg:new_properties(i))
			elseif prop_id == gamer.PropertyIDs.PROP_ID_HEAD_PORTRAIT_LOCAL then
				self:initLocalHeadPortrait(set_property_msg:new_properties(i))
			elseif prop_id == gamer.PropertyIDs.PROP_ID_HEAD_PORTRAIT_PERSONAL then
				self:initPersonalHeadPortrait(set_property_msg:new_properties(i))
			end
		end
	end
end

function HallPlayerInfoPopup:dealWithGetPlayerInfoMsgReceived(code, msg)
	print("[HallPlayerInfoPopup:dealWithGetPlayerInfoMsgReceived]")
	if tolua.isnull(self) then
		print("[HallPlayerInfoPopup:dealWithGetPlayerInfoMsgReceived] tolua.isnull(self), return")
		return
	end

	if code == gamer.MsgCodes.SUCCEED then
		self:initLayout(msg)
		self:showDataView()
	else
		self:showEmptyView()
	end
end

function HallPlayerInfoPopup:dealWithSetPropertyMsgReceived(code, msg)
	print("[HallPlayerInfoPopup:dealWithSetPropertyMsgReceived] code :", code)
	if tolua.isnull(self) then
		print("[HallPlayerInfoPopup:dealWithSetPropertyMsgReceived] tolua.isnull(self), return")
		return
	end

	if code == gamer.MsgCodes.SUCCEED then
		self:setProperty(msg)

		local tip_pop = gamer.popup_mgr_.showTipPopup(gamer.PopupIDs.POPUP_ID_CENTER_TIP)
		tip_pop:setTip(gamer.strings_["str_modify_success"])

		gamer.popup_mgr_.removePopup(gamer.PopupIDs.POPUP_ID_INPUT)
	else
		local tip_pop = gamer.popup_mgr_.showTipPopup(gamer.PopupIDs.POPUP_ID_CENTER_TIP)
		tip_pop:setTip(gamer.strings_["str_modify_failed"])
	end
end

function HallPlayerInfoPopup:dealWithPropertyChangedMsgReceived(code, msg)
	print("[HallPlayerInfoPopup:dealWithPropertyChangedMsgReceived] code :", code)
	if tolua.isnull(self) then
		print("[HallPlayerInfoPopup:dealWithPropertyChangedMsgReceived] tolua.isnull(self), return")
		return
	end

	if code == gamer.MsgCodes.SUCCEED then
		self:setProperty(msg)
	end
end

function HallPlayerInfoPopup:addEventListeners()
	print("[HallPlayerInfoPopup:addEventListeners]")
	gamer.msg_mgr_:addMsgListener(gamer.MsgTypes.S2C_MSG_TYPE_PROPERTY, handler(self, self.onServerMsgReceived))
end

function HallPlayerInfoPopup:removeEventListeners()
	print("[HallPlayerInfoPopup:removeEventListeners]")
	gamer.msg_mgr_:removeMsgListener(gamer.MsgTypes.S2C_MSG_TYPE_PROPERTY, handler(self, self.onServerMsgReceived))
end

function HallPlayerInfoPopup:onImgModifyNicknameTouch(sender)
    print("[HallPlayerInfoPopup:onImgModifyNicknameTouch]")
	gamer.widget_helper_.playDefaultTouchActionForImage(sender)

	local input_popup = gamer.popup_mgr_.showPopup(gamer.PopupIDs.POPUP_ID_INPUT)
	input_popup:setTitle(gamer.strings_["str_modify_nickname"])
	input_popup:setTip(gamer.strings_["str_input_time_tip"])
	input_popup:getEditbox():setPlaceHolder(gamer.strings_["str_input_nickname"])
	input_popup:setOKTouchCallback(function()
		local context = input_popup:getInputContext()
		print("[HallPlayerInfoPopup:onImgModifyNicknameTouch:onOKTouch] context :", tostring(context))
		if context and "" ~= context then
			gamer.msg_helper_.sendModifyNicknameMsg(context)
		end
	end)
end

function HallPlayerInfoPopup:onImgModifySexTouch(sender)
	print("[HallPlayerInfoPopup:onImgModifySexTouch]")
	local time_now = os.time()
	if gamer.widget_helper_.showTipIfTouchTooMuch(self.time_last_touch_, time_now, 10) then
		print("[HallPlayerInfoPopup:onImgModifySexTouch] touch too much, return")
		return
	else
		self.time_last_touch_ = time_now
	end

	local sex = sender:getTag()
	gamer.msg_helper_.sendModifySexMsg(sex)
end

function HallPlayerInfoPopup:onImgHeadPortraitTouch(sender)
	print("[HallPlayerInfoPopup:onImgHeadPortraitTouch]")
	gamer.widget_helper_.playDefaultTouchActionForImage(sender)

	gamer.popup_mgr_.showPopup(gamer.PopupIDs.POPUP_ID_HEAD_PORTRAIT_SELECT)
end

function HallPlayerInfoPopup:onServerMsgReceived(code, msg_type, msg_id, msg)
    print("[HallPlayerInfoPopup:onServerMsgReceived] code, msg_type, msg_id : ", code, msg_type, msg_id)
	if code ~= gamer.MsgCodes.SUCCEED then
		print("[HallPlayerInfoPopup:onServerMsgReceived] error")
	end

	if msg_type == gamer.MsgTypes.S2C_MSG_TYPE_PROPERTY then
		if msg_id == gamer.MsgIDs.MSG_ID_PROPERTY_GET_PLAYER_INFO then
			self:dealWithGetPlayerInfoMsgReceived(code, msg)
		elseif msg_id == gamer.MsgIDs.MSG_ID_PROPERTY_SET then
			self:dealWithSetPropertyMsgReceived(code, msg)
		elseif msg_id == gamer.MsgIDs.MSG_ID_PROPERTY_CHANGED then
			self:dealWithPropertyChangedMsgReceived(code, msg)
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