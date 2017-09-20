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

--Create img_bottom_bg
local img_bottom_bg = ccui.ImageView:create()
img_bottom_bg:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_bottom_bg:loadTexture("mj_left_gang.png",1)
img_bottom_bg:setLayoutComponentEnabled(true)
img_bottom_bg:setName("img_bottom_bg")
img_bottom_bg:setTag(32)
img_bottom_bg:setCascadeColorEnabled(true)
img_bottom_bg:setCascadeOpacityEnabled(true)
layout = ccui.LayoutComponent:bindLayoutComponent(img_bottom_bg)
layout:setSize({width = 91.0000, height = 68.0000})
layout:setLeftMargin(-45.5000)
layout:setRightMargin(-45.5000)
layout:setTopMargin(-34.0000)
layout:setBottomMargin(-34.0000)
mahjong_node:addChild(img_bottom_bg)

--Create img_top_bg
local img_top_bg = ccui.ImageView:create()
img_top_bg:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_top_bg:loadTexture("mj_left_gang.png",1)
img_top_bg:setLayoutComponentEnabled(true)
img_top_bg:setName("img_top_bg")
img_top_bg:setTag(33)
img_top_bg:setCascadeColorEnabled(true)
img_top_bg:setCascadeOpacityEnabled(true)
img_top_bg:setPosition(-5.4021, 20.7052)
layout = ccui.LayoutComponent:bindLayoutComponent(img_top_bg)
layout:setSize({width = 91.0000, height = 68.0000})
layout:setLeftMargin(-50.9021)
layout:setRightMargin(-40.0979)
layout:setTopMargin(-54.7052)
layout:setBottomMargin(-13.2948)
mahjong_node:addChild(img_top_bg)

--Create img_top_fg
local img_top_fg = ccui.ImageView:create()
img_top_fg:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_top_fg:loadTexture("dot_9.png",1)
img_top_fg:setLayoutComponentEnabled(true)
img_top_fg:setName("img_top_fg")
img_top_fg:setTag(39)
img_top_fg:setCascadeColorEnabled(true)
img_top_fg:setCascadeOpacityEnabled(true)
img_top_fg:setPosition(-10.0000, 35.8100)
img_top_fg:setScaleX(0.3400)
img_top_fg:setScaleY(0.4300)
img_top_fg:setRotationSkewX(90.0000)
img_top_fg:setRotationSkewY(110.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_top_fg)
layout:setSize({width = 102.0000, height = 124.0000})
layout:setLeftMargin(-61.0000)
layout:setRightMargin(-41.0000)
layout:setTopMargin(-97.8100)
layout:setBottomMargin(-26.1900)
mahjong_node:addChild(img_top_fg)

--Create Animation
result['animation'] = ccs.ActionTimeline:create()
  
result['animation']:setDuration(0)
result['animation']:setTimeSpeed(1.0000)
--Create Animation List

result['root'] = mahjong_node
return result;
end

return Result
