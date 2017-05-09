--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   layer_constants.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: layer constants.
@ others:
@ history:
1.date:
author:
modification:
--]]

local LayerConstants = {}

LayerConstants.LayerIDs =
{
	LOGIN_LAYER				= 1
}

LayerConstants.LayerFiles =
{
	LOGIN_LAYER_FILE		= "view/login/login_layer.lua"
}

LayerConstants.LayerViewFiles =
{
	LOGIN_LAYER_VIEW_FILE	= nil
}

LayerConstants.LayersCfg =
{
	[LayerConstants.LayerIDs.LOGIN_LAYER]		   = 
		{ 
			layer_file = LayerConstants.LayerFiles.LOGIN_LAYER_FILE,
			view_file  = LayerConstants.LayerViewFiles.LOGIN_LAYER_VIEW_FILE 
		}
}

return LayerConstants