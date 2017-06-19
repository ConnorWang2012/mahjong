--------------------------------------------------------------
-- This file was automatically generated by Cocos Studio.
-- Do not make changes to this file.
-- All changes will be lost.
--------------------------------------------------------------

local luaExtend = require "LuaExtend"

-- using for layout to decrease count of local variables
local layout = nil
local localLuaFile = nil
local innerCSD = nil
local innerProject = nil
local localFrame = nil

local Result = {}
------------------------------------------------------------
-- function call description
-- create function caller should provide a function to 
-- get a callback function in creating scene process.
-- the returned callback function will be registered to 
-- the callback event of the control.
-- the function provider is as below :
-- Callback callBackProvider(luaFileName, node, callbackName)
-- parameter description:
-- luaFileName  : a string, lua file name
-- node         : a Node, event source
-- callbackName : a string, callback function name
-- the return value is a callback function
------------------------------------------------------------
function Result.create(callBackProvider)

local result={}
setmetatable(result, luaExtend)

--Create room_scene
local room_scene=cc.Node:create()
room_scene:setName("room_scene")

--Create img_room_bg
local img_room_bg = ccui.ImageView:create()
img_room_bg:ignoreContentAdaptWithSize(false)
img_room_bg:loadTexture("assets/room/normal_room_bg.jpg",0)
img_room_bg:setLayoutComponentEnabled(true)
img_room_bg:setName("img_room_bg")
img_room_bg:setTag(26)
img_room_bg:setCascadeColorEnabled(true)
img_room_bg:setCascadeOpacityEnabled(true)
img_room_bg:setPosition(960.0000, 540.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_room_bg)
layout:setPositionPercentX(1.0000)
layout:setPositionPercentY(0.8438)
layout:setPercentWidth(2.0000)
layout:setPercentHeight(1.6875)
layout:setSize({width = 1920.0000, height = 1080.0000})
layout:setRightMargin(-960.0000)
layout:setTopMargin(-440.0000)
room_scene:addChild(img_room_bg)

--Create Animation
result['animation'] = ccs.ActionTimeline:create()
  
result['animation']:setDuration(0)
result['animation']:setTimeSpeed(1.0000)
--Create Animation List

result['root'] = room_scene
return result;
end

return Result
