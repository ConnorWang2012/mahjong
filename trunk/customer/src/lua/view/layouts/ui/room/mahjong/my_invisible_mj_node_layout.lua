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

--Create mahjong_node
local mahjong_node=cc.Node:create()
mahjong_node:setName("mahjong_node")

--Create img_bg
local img_bg = ccui.ImageView:create()
img_bg:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_bg:loadTexture("mj_my_invisible.png",1)
img_bg:setLayoutComponentEnabled(true)
img_bg:setName("img_bg")
img_bg:setTag(6)
img_bg:setCascadeColorEnabled(true)
img_bg:setCascadeOpacityEnabled(true)
layout = ccui.LayoutComponent:bindLayoutComponent(img_bg)
layout:setSize({width = 144.0000, height = 201.0000})
layout:setLeftMargin(-72.0000)
layout:setRightMargin(-72.0000)
layout:setTopMargin(-100.5000)
layout:setBottomMargin(-100.5000)
mahjong_node:addChild(img_bg)

--Create img_fg
local img_fg = ccui.ImageView:create()
img_fg:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_fg:loadTexture("wind_or_dragon_5.png",1)
img_fg:setLayoutComponentEnabled(true)
img_fg:setName("img_fg")
img_fg:setTag(10)
img_fg:setCascadeColorEnabled(true)
img_fg:setCascadeOpacityEnabled(true)
img_fg:setPosition(0.0000, -12.8480)
layout = ccui.LayoutComponent:bindLayoutComponent(img_fg)
layout:setSize({width = 102.0000, height = 124.0000})
layout:setLeftMargin(-51.0000)
layout:setRightMargin(-51.0000)
layout:setTopMargin(-49.1520)
layout:setBottomMargin(-74.8480)
mahjong_node:addChild(img_fg)

--Create Animation
result['animation'] = ccs.ActionTimeline:create()
  
result['animation']:setDuration(0)
result['animation']:setTimeSpeed(1.0000)
--Create Animation List

result['root'] = mahjong_node
return result;
end

return Result

