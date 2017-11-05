--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   scene_constants.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: scene constants.
@ others:
@ history:
1.date:
author:
modification:
--]]

local M = {}

M.SceneIDs =
{
    LOGIN_SCENE                 = 1,
    HALL_SCENE                  = 2,
    NORMAL_ROOM_SCENE           = 3
}

M.SceneFiles =
{
	LOGIN_SCENE_FILE		    = "view.login.login_scene.lua",
    HALL_SCENE_FILE		        = "view.hall.hall_scene.lua",
    NORMAL_ROOM_SCENE_FILE		= "view.room.scene.normal_room_scene.lua"
}

M.SceneLayoutFiles =
{
	LOGIN_SCENE_LAYOUT_FILE	        = "view.layouts.scene.login.login_scene_layout.lua",
    HALL_SCENE_LAYOUT_FILE	        = "view.layouts.scene.hall.hall_scene_layout.lua",
    NORMAL_ROOM_SCENE_LAYOUT_FILE	= "view.layouts.scene.room.normal_room_scene_layout.lua"
}

M.ScenesCfg =
{
	[M.SceneIDs.LOGIN_SCENE]		   = 
		{ 
			scene_file = M.SceneFiles.LOGIN_SCENE_FILE,
			view_file  = M.SceneLayoutFiles.LOGIN_SCENE_LAYOUT_FILE
		},
	[M.SceneIDs.HALL_SCENE]		   = 
		{ 
			scene_file = M.SceneFiles.HALL_SCENE_FILE,
			view_file  = M.SceneLayoutFiles.HALL_SCENE_LAYOUT_FILE
		},
    [M.SceneIDs.NORMAL_ROOM_SCENE]	    = 
		{ 
			scene_file = M.SceneFiles.NORMAL_ROOM_SCENE_FILE,
			view_file  = M.SceneLayoutFiles.NORMAL_ROOM_SCENE_LAYOUT_FILE
		}
}

M.LocalZOrders =
{
    ROOM_MAHJONG_LAYER                 = 100,
    ROOM_PLAYER_HEAD_LAYER			   = 101,
	ROOM_MENU_LAYER			           = 102,
	ROOM_ANIMATION_LAYER			   = 103,
	ROOM_NOTIFICATION_LAYER			   = 104
}

return M