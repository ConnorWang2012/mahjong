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

local SceneConstants = {}

SceneConstants.SceneIDs =
{
    LOGIN_SCENE                 = 1,
    HALL_SCENE                  = 2,
    NORMAL_ROOM_SCENE           = 3
}

SceneConstants.SceneFiles =
{
	LOGIN_SCENE_FILE		    = "view.login.login_scene.lua",
    HALL_SCENE_FILE		        = "view.hall.hall_scene.lua",
    NORMAL_ROOM_SCENE_FILE		= "view.room.room_scene.lua"
}

SceneConstants.SceneLayoutFiles =
{
	LOGIN_SCENE_LAYOUT_FILE	        = "view.layouts.scene.login.login_scene_layout.lua",
    HALL_SCENE_LAYOUT_FILE	        = "view.layouts.scene.hall.hall_scene_layout.lua",
    NORMAL_ROOM_SCENE_LAYOUT_FILE	= "view.layouts.scene.room.normal_room_scene_layout.lua"
}

SceneConstants.ScenesCfg =
{
	[SceneConstants.SceneIDs.LOGIN_SCENE]		   = 
		{ 
			scene_file = SceneConstants.SceneFiles.LOGIN_SCENE_FILE,
			view_file  = SceneConstants.SceneLayoutFiles.LOGIN_SCENE_LAYOUT_FILE
		},
	[SceneConstants.SceneIDs.HALL_SCENE]		   = 
		{ 
			scene_file = SceneConstants.SceneFiles.HALL_SCENE_FILE,
			view_file  = SceneConstants.SceneLayoutFiles.HALL_SCENE_LAYOUT_FILE
		},
    [SceneConstants.SceneIDs.NORMAL_ROOM_SCENE]	    = 
		{ 
			scene_file = SceneConstants.SceneFiles.NORMAL_ROOM_SCENE_FILE,
			view_file  = SceneConstants.SceneLayoutFiles.NORMAL_ROOM_SCENE_LAYOUT_FILE
		}
}

return SceneConstants