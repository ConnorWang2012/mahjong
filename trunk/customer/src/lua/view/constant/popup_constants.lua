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

M.PopupIDs = 
{
	-- common
	POPUP_ID_CENTER_TIP			    = 1,
	POPUP_ID_INPUT				    = 2,

	-- hall
	POPUP_ID_ROOM_CREATE		    = 3,
	POPUP_ID_ROOM_JOIN			    = 4,
	POPUP_ID_STORE				    = 5,
	POPUP_ID_HALL_PLAYER_INFO	    = 6,
	POPUP_ID_HEAD_PORTRAIT_SELECT	= 7,
	POPUP_ID_SETTING	            = 8,

	-- room
	POPUP_ID_GAME_END			    = 9
}

M.PopupFiles = 
{
	[M.PopupIDs.POPUP_ID_CENTER_TIP]			= "view.common.center_tip_popup.lua",
	[M.PopupIDs.POPUP_ID_INPUT]					= "view.common.input_popup.lua",
	[M.PopupIDs.POPUP_ID_ROOM_CREATE]			= "view.hall.create_room.create_room_popup.lua",
	[M.PopupIDs.POPUP_ID_ROOM_JOIN]				= "view.hall.join_room.join_room_popup.lua",
	[M.PopupIDs.POPUP_ID_STORE]					= "view.hall.store.store_popup.lua",
	[M.PopupIDs.POPUP_ID_HALL_PLAYER_INFO]		= "view.hall.player_info.hall_player_info_popup.lua",
	[M.PopupIDs.POPUP_ID_HEAD_PORTRAIT_SELECT]	= "view.hall.player_info.head_portrait_select_popup.lua",
	[M.PopupIDs.POPUP_ID_SETTING]	            = "view.hall.setting.setting_popup.lua",
	[M.PopupIDs.POPUP_ID_GAME_END]				= "view.room.game_end.game_end_popup.lua"
}

M.PopupLayoutFiles = 
{
	[M.PopupIDs.POPUP_ID_CENTER_TIP]			= "view.layouts.ui.common.center_tip_node_layout.lua",
	[M.PopupIDs.POPUP_ID_INPUT]					= "view.layouts.ui.common.input_popup_layer_layout.lua",
	[M.PopupIDs.POPUP_ID_ROOM_CREATE]			= "view.layouts.ui.hall.create_room.create_room_layer_layout.lua",
	[M.PopupIDs.POPUP_ID_ROOM_JOIN]				= "view.layouts.ui.hall.join_room.join_room_layer_layout.lua",
	[M.PopupIDs.POPUP_ID_STORE]					= "view.layouts.ui.hall.store.store_layer_layout.lua",
	[M.PopupIDs.POPUP_ID_HALL_PLAYER_INFO]		= "view.layouts.ui.hall.player_info.hall_player_info_layer_layout.lua",
	[M.PopupIDs.POPUP_ID_HEAD_PORTRAIT_SELECT]	= "view.layouts.ui.hall.player_info.head_portrait_select_layer_layout.lua",
	[M.PopupIDs.POPUP_ID_SETTING]	            = "view.layouts.ui.hall.setting.setting_layer_layout.lua",
	[M.PopupIDs.POPUP_ID_GAME_END]				= "view.layouts.ui.room.game_end.game_end_layer_layout.lua"
}

M.POPUP_ZORDER_ROOT = 8888
M.POPUP_ZORDER_TOP  = 9999

return M