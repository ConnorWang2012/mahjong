--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   popup_constants.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: popup constants.
@ others:
@ history:
1.date:
author:
modification:
--]]

local PopupConstants = {}

PopupConstants.PopupIDs = {
	POPUP_ID_ROOM_CREATE	= 1,
	POPUP_ID_ROOM_JOIN		= 2
}

PopupConstants.POPUP_WRAPPER_ZORDER = 8888

PopupConstants.PopupFiles = {
	[PopupConstants.PopupIDs.POPUP_ID_ROOM_CREATE]		= "view.hall.popups.create_room_popup.lua",
	[PopupConstants.PopupIDs.POPUP_ID_ROOM_JOIN]		= "view.hall.popups.join_room_popup.lua"
}

PopupConstants.PopupLayoutFiles = {
	[PopupConstants.PopupIDs.POPUP_ID_ROOM_CREATE]		= "view.layouts.ui.hall.create_room_layer_layout.lua",
	[PopupConstants.PopupIDs.POPUP_ID_ROOM_JOIN]		= "view.layouts.ui.hall.join_room_layer_layout.lua"
}

return PopupConstants