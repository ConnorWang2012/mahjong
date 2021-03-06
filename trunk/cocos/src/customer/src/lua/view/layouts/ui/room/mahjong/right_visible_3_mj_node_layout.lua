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

--Create img_bottom_bg1
local img_bottom_bg1 = ccui.ImageView:create()
img_bottom_bg1:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_bottom_bg1:loadTexture("mj_left_gang.png",1)
img_bottom_bg1:setFlippedX(true)
img_bottom_bg1:setLayoutComponentEnabled(true)
img_bottom_bg1:setName("img_bottom_bg1")
img_bottom_bg1:setTag(98)
img_bottom_bg1:setCascadeColorEnabled(true)
img_bottom_bg1:setCascadeOpacityEnabled(true)
img_bottom_bg1:setPosition(-15.0000, 40.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_bottom_bg1)
layout:setSize({width = 91.0000, height = 68.0000})
layout:setLeftMargin(-60.5000)
layout:setRightMargin(-30.5000)
layout:setTopMargin(-74.0000)
layout:setBottomMargin(6.0000)
mahjong_node:addChild(img_bottom_bg1)

--Create img_bottom_bg2
local img_bottom_bg2 = ccui.ImageView:create()
img_bottom_bg2:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_bottom_bg2:loadTexture("mj_left_gang.png",1)
img_bottom_bg2:setFlippedX(true)
img_bottom_bg2:setLayoutComponentEnabled(true)
img_bottom_bg2:setName("img_bottom_bg2")
img_bottom_bg2:setTag(32)
img_bottom_bg2:setCascadeColorEnabled(true)
img_bottom_bg2:setCascadeOpacityEnabled(true)
layout = ccui.LayoutComponent:bindLayoutComponent(img_bottom_bg2)
layout:setSize({width = 91.0000, height = 68.0000})
layout:setLeftMargin(-45.5000)
layout:setRightMargin(-45.5000)
layout:setTopMargin(-34.0000)
layout:setBottomMargin(-34.0000)
mahjong_node:addChild(img_bottom_bg2)

--Create img_bottom_bg3
local img_bottom_bg3 = ccui.ImageView:create()
img_bottom_bg3:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_bottom_bg3:loadTexture("mj_left_gang.png",1)
img_bottom_bg3:setFlippedX(true)
img_bottom_bg3:setLayoutComponentEnabled(true)
img_bottom_bg3:setName("img_bottom_bg3")
img_bottom_bg3:setTag(99)
img_bottom_bg3:setCascadeColorEnabled(true)
img_bottom_bg3:setCascadeOpacityEnabled(true)
img_bottom_bg3:setPosition(15.0000, -40.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_bottom_bg3)
layout:setSize({width = 91.0000, height = 68.0000})
layout:setLeftMargin(-30.5000)
layout:setRightMargin(-60.5000)
layout:setTopMargin(6.0000)
layout:setBottomMargin(-74.0000)
mahjong_node:addChild(img_bottom_bg3)

--Create img_top_fg1
local img_top_fg1 = ccui.ImageView:create()
img_top_fg1:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_top_fg1:loadTexture("dot_9.png",1)
img_top_fg1:setFlippedX(true)
img_top_fg1:setFlippedY(true)
img_top_fg1:setLayoutComponentEnabled(true)
img_top_fg1:setName("img_top_fg1")
img_top_fg1:setTag(109)
img_top_fg1:setCascadeColorEnabled(true)
img_top_fg1:setCascadeOpacityEnabled(true)
img_top_fg1:setPosition(-11.0000, 55.0000)
img_top_fg1:setScaleX(0.3400)
img_top_fg1:setScaleY(0.4300)
img_top_fg1:setRotationSkewX(90.0000)
img_top_fg1:setRotationSkewY(69.9982)
layout = ccui.LayoutComponent:bindLayoutComponent(img_top_fg1)
layout:setSize({width = 102.0000, height = 124.0000})
layout:setLeftMargin(-62.0000)
layout:setRightMargin(-40.0000)
layout:setTopMargin(-117.0000)
layout:setBottomMargin(-7.0000)
mahjong_node:addChild(img_top_fg1)

--Create img_top_bg
local img_top_bg = ccui.ImageView:create()
img_top_bg:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_top_bg:loadTexture("mj_left_gang.png",1)
img_top_bg:setFlippedX(true)
img_top_bg:setLayoutComponentEnabled(true)
img_top_bg:setName("img_top_bg")
img_top_bg:setTag(33)
img_top_bg:setCascadeColorEnabled(true)
img_top_bg:setCascadeOpacityEnabled(true)
img_top_bg:setPosition(5.0000, 22.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_top_bg)
layout:setSize({width = 91.0000, height = 68.0000})
layout:setLeftMargin(-40.5000)
layout:setRightMargin(-50.5000)
layout:setTopMargin(-56.0000)
layout:setBottomMargin(-12.0000)
mahjong_node:addChild(img_top_bg)

--Create img_top_fg2
local img_top_fg2 = ccui.ImageView:create()
img_top_fg2:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_top_fg2:loadTexture("dot_9.png",1)
img_top_fg2:setFlippedX(true)
img_top_fg2:setFlippedY(true)
img_top_fg2:setLayoutComponentEnabled(true)
img_top_fg2:setName("img_top_fg2")
img_top_fg2:setTag(39)
img_top_fg2:setCascadeColorEnabled(true)
img_top_fg2:setCascadeOpacityEnabled(true)
img_top_fg2:setPosition(9.0000, 37.0000)
img_top_fg2:setScaleX(0.3400)
img_top_fg2:setScaleY(0.4300)
img_top_fg2:setRotationSkewX(90.0000)
img_top_fg2:setRotationSkewY(69.9982)
layout = ccui.LayoutComponent:bindLayoutComponent(img_top_fg2)
layout:setSize({width = 102.0000, height = 124.0000})
layout:setLeftMargin(-42.0000)
layout:setRightMargin(-60.0000)
layout:setTopMargin(-99.0000)
layout:setBottomMargin(-25.0000)
mahjong_node:addChild(img_top_fg2)

--Create img_top_fg3
local img_top_fg3 = ccui.ImageView:create()
img_top_fg3:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_top_fg3:loadTexture("dot_9.png",1)
img_top_fg3:setFlippedX(true)
img_top_fg3:setFlippedY(true)
img_top_fg3:setLayoutComponentEnabled(true)
img_top_fg3:setName("img_top_fg3")
img_top_fg3:setTag(108)
img_top_fg3:setCascadeColorEnabled(true)
img_top_fg3:setCascadeOpacityEnabled(true)
img_top_fg3:setPosition(19.0000, -25.0000)
img_top_fg3:setScaleX(0.3400)
img_top_fg3:setScaleY(0.4300)
img_top_fg3:setRotationSkewX(90.0000)
img_top_fg3:setRotationSkewY(69.9981)
layout = ccui.LayoutComponent:bindLayoutComponent(img_top_fg3)
layout:setSize({width = 102.0000, height = 124.0000})
layout:setLeftMargin(-32.0000)
layout:setRightMargin(-70.0000)
layout:setTopMargin(-37.0000)
layout:setBottomMargin(-87.0000)
mahjong_node:addChild(img_top_fg3)

--Create Animation
result['animation'] = ccs.ActionTimeline:create()
  
result['animation']:setDuration(0)
result['animation']:setTimeSpeed(1.0000)
--Create Animation List

result['root'] = mahjong_node
return result;
end

return Result

