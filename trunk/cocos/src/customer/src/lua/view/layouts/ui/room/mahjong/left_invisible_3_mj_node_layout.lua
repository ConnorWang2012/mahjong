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
img_bottom_bg1:loadTexture("mj_left_angang.png",1)
img_bottom_bg1:setLayoutComponentEnabled(true)
img_bottom_bg1:setName("img_bottom_bg1")
img_bottom_bg1:setTag(31)
img_bottom_bg1:setCascadeColorEnabled(true)
img_bottom_bg1:setCascadeOpacityEnabled(true)
img_bottom_bg1:setPosition(14.0000, 39.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_bottom_bg1)
layout:setSize({width = 91.0000, height = 68.0000})
layout:setLeftMargin(-31.5000)
layout:setRightMargin(-59.5000)
layout:setTopMargin(-73.0000)
layout:setBottomMargin(5.0000)
mahjong_node:addChild(img_bottom_bg1)

--Create img_bottom_bg2
local img_bottom_bg2 = ccui.ImageView:create()
img_bottom_bg2:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_bottom_bg2:loadTexture("mj_left_angang.png",1)
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
img_bottom_bg3:loadTexture("mj_left_angang.png",1)
img_bottom_bg3:setLayoutComponentEnabled(true)
img_bottom_bg3:setName("img_bottom_bg3")
img_bottom_bg3:setTag(30)
img_bottom_bg3:setCascadeColorEnabled(true)
img_bottom_bg3:setCascadeOpacityEnabled(true)
img_bottom_bg3:setPosition(-15.0000, -40.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_bottom_bg3)
layout:setSize({width = 91.0000, height = 68.0000})
layout:setLeftMargin(-60.5000)
layout:setRightMargin(-30.5000)
layout:setTopMargin(6.0000)
layout:setBottomMargin(-74.0000)
mahjong_node:addChild(img_bottom_bg3)

--Create img_top_bg
local img_top_bg = ccui.ImageView:create()
img_top_bg:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_top_bg:loadTexture("mj_left_angang.png",1)
img_top_bg:setLayoutComponentEnabled(true)
img_top_bg:setName("img_top_bg")
img_top_bg:setTag(33)
img_top_bg:setCascadeColorEnabled(true)
img_top_bg:setCascadeOpacityEnabled(true)
img_top_bg:setPosition(-7.4021, 21.7052)
layout = ccui.LayoutComponent:bindLayoutComponent(img_top_bg)
layout:setSize({width = 91.0000, height = 68.0000})
layout:setLeftMargin(-52.9021)
layout:setRightMargin(-38.0979)
layout:setTopMargin(-55.7052)
layout:setBottomMargin(-12.2948)
mahjong_node:addChild(img_top_bg)

--Create Animation
result['animation'] = ccs.ActionTimeline:create()
  
result['animation']:setDuration(0)
result['animation']:setTimeSpeed(1.0000)
--Create Animation List

result['root'] = mahjong_node
return result;
end

return Result
