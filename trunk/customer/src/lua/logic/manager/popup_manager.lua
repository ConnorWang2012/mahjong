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

local M = {}
M.popups_ = {}

function M.showPopup(popup_id, ...)
	if not popup_id then
		print("[PopupManager.showPopup] show popup failed, popup id is nil")
		return nil
	end

	local popup = M.addPopup(popup_id, ...)
	if not popup then
		print("[PopupManager.showPopup] show popup failed, add popup failed")
		return nil
	end

	popup:setVisible(true)
	return popup
end

function M.hidePopup(popup_id)
	local popup = M.getPopup(popup_id)
	if popup then
		popup:setVisible(false)
	end
	return popup
end

function M.getPopup(popup_id)
	if M.popup_root_ then
		return M.popup_root_:getChildByTag(popup_id)
	end
	return nil
end

function M.removePopup(popup_id)
	local popup = M.getPopup(popup_id)
	if popup then
		popup:removeFromParent(true)
	end
end

------------------------------------ private ------------------------------------

function M.init()
	if not M.popup_root_ then
		M.popup_root_ = cc.Layer:create()
		M.popup_root_:setLocalZOrder(gamer.PopupConstants.POPUP_ROOT_ZORDER)
		local scene = gamer.scene_mgr_:getRunningScene()
		if scene then
			scene:addChild(M.popup_root_)
		end
	end
end

function M.createPopup(popup_id, ...)
	if not popup_id then
		print("[PopupManager.createPopup] create popup failed, popup id nil")
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

	return require(popup_file):create(popup_layout, ...)
end

function M.addPopup(popup_id, ...)
	local popup = M.getPopup(popup_id)
	if popup then
		return popup
	end

	M.init()

	popup = M.createPopup(popup_id, ...)
	if popup then
		popup:setTag(popup_id)
		M.popup_root_:addChild(popup)
	end

	return popup
end

--------------------------------- end private -----------------------------------

return M