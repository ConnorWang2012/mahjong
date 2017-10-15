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
img_bottom_bg:loadTexture("mj_my_an_gang.png",1)
img_bottom_bg:setLayoutComponentEnabled(true)
img_bottom_bg:setName("img_bottom_bg")
img_bottom_bg:setTag(12)
img_bottom_bg:setCascadeColorEnabled(true)
img_bottom_bg:setCascadeOpacityEnabled(true)
layout = ccui.LayoutComponent:bindLayoutComponent(img_bottom_bg)
layout:setSize({width = 102.0000, height = 145.0000})
layout:setLeftMargin(-51.0000)
layout:setRightMargin(-51.0000)
layout:setTopMargin(-72.5000)
layout:setBottomMargin(-72.5000)
mahjong_node:addChild(img_bottom_bg)

--Create img_top_bg
local img_top_bg = ccui.ImageView:create()
img_top_bg:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_top_bg:loadTexture("mj_my_an_gang.png",1)
img_top_bg:setLayoutComponentEnabled(true)
img_top_bg:setName("img_top_bg")
img_top_bg:setTag(9)
img_top_bg:setCascadeColorEnabled(true)
img_top_bg:setCascadeOpacityEnabled(true)
img_top_bg:setPosition(0.0000, 33.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_top_bg)
layout:setSize({width = 102.0000, height = 145.0000})
layout:setLeftMargin(-51.0000)
layout:setRightMargin(-51.0000)
layout:setTopMargin(-105.5000)
layout:setBottomMargin(-39.5000)
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

