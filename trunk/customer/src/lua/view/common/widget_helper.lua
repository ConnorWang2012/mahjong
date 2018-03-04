--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   widget_helper.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2018-01-13
@ description: 
@ others:
@ history:
1.date:
author:
modification:
--]]

local M = {}

function M.playDefaultTouchActionForImage(ui_image)
	if ui_image then
		local scale_by = cc.ScaleBy:create(0.1, 1.2)
		local sequence = cc.Sequence:create(scale_by, scale_by:reverse())
		ui_image:runAction(sequence)
	end
end

function M.showTipIfTouchTooMuch(time_last, time_now, time_interval)
	if time_last and (time_now - time_last < time_interval) then
		gamer.popup_mgr_.showCenterTipPopup(gamer.strings_["str_touch_too_much"], 3)
		return true
	end
	return false
end

return M