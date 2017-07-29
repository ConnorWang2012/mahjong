--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   popup_manager.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: popup manager.
@ others:
@ history:
1.date:
author:
modification:
--]]

local PopupManager = {}
PopupManager.popups_ = {}

function PopupManager.showPopup(popup_id)
	if not popup_id then
		print("[PopupManager.showPopup] show popup failed, popup id is nil")
		return
	end

	local popup = PopupManager.addPopup(popup_id)
	if popup then
		popup:setVisible(true)
	end
end

function PopupManager.hidePopup(popup_id)
	local popup = PopupManager.getPopup(popup_id)
	if popup then
		popup:setVisible(false)
	end
end

function PopupManager.removePopup(popup_id)
	local popup = PopupManager.getPopup(popup_id)
	if popup then
		popup:removeFromParent(true)
	end
end

------------------------------------ private ------------------------------------

function PopupManager.init()
	if not PopupManager.popup_wrapper_ then
		PopupManager.popup_wrapper_ = cc.Layer:create()
		PopupManager.popup_wrapper_:setLocalZOrder(gamer.PopupConstants.POPUP_WRAPPER_ZORDER)
		local scene = gamer.g_scene_msg_:getRunningScene()
		if scene then
			scene:addChild(PopupManager.popup_wrapper_)
		end
	end
end

function PopupManager.createPopup(popup_id)
	if not popup_id then
		print("[PopupManager.createPopup] create popup failed, popup id is nil")
		return nil
	end

	local popup_file = gamer.PopupConstants.PopupFiles[popup_id]
	if not popup_file then
		print("[PopupManager.createPopup] create popup failed, popup view file nil")
		return nil
	end
	
	local popup_layout = gamer.PopupConstants.PopupLayoutFiles[popup_id]
	if not popup_layout then
		print("[PopupManager.createPopup] create popup failed, popup layout file nil")
		return nil
	end

	return require(popup_file):create(popup_layout)
end

function PopupManager.getPopup(popup_id)
	if PopupManager.popup_wrapper_ then
		return PopupManager.popup_wrapper_:getChildByTag(popup_id)
	end
	return nil
end

function PopupManager.addPopup(popup_id)
	local popup = PopupManager.getPopup(popup_id)
	if popup then
		return popup
	end

	PopupManager.init()

	popup = PopupManager.createPopup(popup_id)
	if popup then
		popup:setTag(popup_id)
		PopupManager.popup_wrapper_:addChild(popup)
	end

	return popup
end

--------------------------------- end private -----------------------------------

return PopupManager