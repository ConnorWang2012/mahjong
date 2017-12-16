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

local M = {}

M.PopupIDs = {
	-- hall
	POPUP_ID_ROOM_CREATE		= 1,
	POPUP_ID_ROOM_JOIN			= 2,
	POPUP_ID_STORE				= 3,
	POPUP_ID_HALL_PLAYER_INFO	= 4,

	-- room
	POPUP_ID_GAME_END			= 5
}

M.POPUP_ROOT_ZORDER = 8888

M.PopupFiles = {
	[M.PopupIDs.POPUP_ID_ROOM_CREATE]		= "view.hall.create_room.create_room_popup.lua",
	[M.PopupIDs.POPUP_ID_ROOM_JOIN]			= "view.hall.join_room.join_room_popup.lua",
	[M.PopupIDs.POPUP_ID_STORE]				= "view.hall.store.store_popup.lua",
	[M.PopupIDs.POPUP_ID_HALL_PLAYER_INFO]	= "view.hall.player_info.hall_player_info_popup.lua",
	[M.PopupIDs.POPUP_ID_GAME_END]			= "view.room.game_end.game_end_popup.lua"
}

M.PopupLayoutFiles = {
	[M.PopupIDs.POPUP_ID_ROOM_CREATE]		= "view.layouts.ui.hall.create_room.create_room_layer_layout.lua",
	[M.PopupIDs.POPUP_ID_ROOM_JOIN]			= "view.layouts.ui.hall.join_room.join_room_layer_layout.lua",
	[M.PopupIDs.POPUP_ID_STORE]				= "view.layouts.ui.hall.store.store_layer_layout.lua",
	[M.PopupIDs.POPUP_ID_HALL_PLAYER_INFO]	= "view.layouts.ui.hall.player_info.hall_player_info_layer_layout.lua",
	[M.PopupIDs.POPUP_ID_GAME_END]			= "view.layouts.ui.room.game_end.game_end_layer_layout.lua"
}

return M