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
    LOGIN_SCENE                 = 1
}

SceneConstants.SceneFiles =
{
	LOGIN_SCENE_FILE		    = "view.login.login_scene.lua"
}

SceneConstants.SceneViewFiles =
{
	LOGIN_SCENE_VIEW_FILE	    = nil
}

SceneConstants.ScenesCfg =
{
	[SceneConstants.SceneIDs.LOGIN_SCENE]		   = 
		{ 
			scene_file = SceneConstants.SceneFiles.LOGIN_SCENE_FILE,
			view_file  = SceneConstants.SceneViewFiles.LOGIN_SCENE_VIEW_FILE
		}
}

return SceneConstants