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
img_bg:loadTexture("mj_left_visible.png",1)
img_bg:setLayoutComponentEnabled(true)
img_bg:setName("img_bg")
img_bg:setTag(17)
img_bg:setCascadeColorEnabled(true)
img_bg:setCascadeOpacityEnabled(true)
layout = ccui.LayoutComponent:bindLayoutComponent(img_bg)
layout:setSize({width = 90.0000, height = 67.0000})
layout:setLeftMargin(-45.0000)
layout:setRightMargin(-45.0000)
layout:setTopMargin(-33.5000)
layout:setBottomMargin(-33.5000)
mahjong_node:addChild(img_bg)

--Create img_fg
local img_fg = ccui.ImageView:create()
img_fg:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_fg:loadTexture("dot_8.png",1)
img_fg:setLayoutComponentEnabled(true)
img_fg:setName("img_fg")
img_fg:setTag(18)
img_fg:setCascadeColorEnabled(true)
img_fg:setCascadeOpacityEnabled(true)
img_fg:setPosition(-3.0000, 16.0000)
img_fg:setScaleX(0.3500)
img_fg:setScaleY(0.5300)
img_fg:setRotationSkewX(90.0000)
img_fg:setRotationSkewY(101.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_fg)
layout:setSize({width = 102.0000, height = 124.0000})
layout:setLeftMargin(-54.0000)
layout:setRightMargin(-48.0000)
layout:setTopMargin(-78.0000)
layout:setBottomMargin(-46.0000)
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

