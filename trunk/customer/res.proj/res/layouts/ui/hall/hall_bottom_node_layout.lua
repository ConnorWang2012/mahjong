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

--Create hall_bottom_node
local hall_bottom_node=cc.Node:create()
hall_bottom_node:setName("hall_bottom_node")

--Create img_hall_bottom_bg
local img_hall_bottom_bg = ccui.ImageView:create()
img_hall_bottom_bg:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/hall/plist/hall_bottom.plist")
img_hall_bottom_bg:loadTexture("hall_bottom_bg.png",1)
img_hall_bottom_bg:setLayoutComponentEnabled(true)
img_hall_bottom_bg:setName("img_hall_bottom_bg")
img_hall_bottom_bg:setTag(9)
img_hall_bottom_bg:setCascadeColorEnabled(true)
img_hall_bottom_bg:setCascadeOpacityEnabled(true)
layout = ccui.LayoutComponent:bindLayoutComponent(img_hall_bottom_bg)
layout:setSize({width = 1920.0000, height = 150.0000})
layout:setLeftMargin(-960.0000)
layout:setRightMargin(-960.0000)
layout:setTopMargin(-75.0000)
layout:setBottomMargin(-75.0000)
hall_bottom_node:addChild(img_hall_bottom_bg)

--Create img_shop
local img_shop = ccui.ImageView:create()
img_shop:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/hall/plist/hall_bottom.plist")
img_shop:loadTexture("hall_shop.png",1)
img_shop:setLayoutComponentEnabled(true)
img_shop:setName("img_shop")
img_shop:setTag(10)
img_shop:setCascadeColorEnabled(true)
img_shop:setCascadeOpacityEnabled(true)
img_shop:setPosition(798.8724, 0.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_shop)
layout:setSize({width = 170.0000, height = 170.0000})
layout:setLeftMargin(713.8724)
layout:setRightMargin(-883.8724)
layout:setTopMargin(-85.0000)
layout:setBottomMargin(-85.0000)
hall_bottom_node:addChild(img_shop)

--Create img_rank
local img_rank = ccui.ImageView:create()
img_rank:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/hall/plist/hall_bottom.plist")
img_rank:loadTexture("hall_rank.png",1)
img_rank:setLayoutComponentEnabled(true)
img_rank:setName("img_rank")
img_rank:setTag(11)
img_rank:setCascadeColorEnabled(true)
img_rank:setCascadeOpacityEnabled(true)
img_rank:setPosition(584.3376, 0.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_rank)
layout:setSize({width = 170.0000, height = 170.0000})
layout:setLeftMargin(499.3376)
layout:setRightMargin(-669.3376)
layout:setTopMargin(-85.0000)
layout:setBottomMargin(-85.0000)
hall_bottom_node:addChild(img_rank)

--Create img_activity
local img_activity = ccui.ImageView:create()
img_activity:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/hall/plist/hall_bottom.plist")
img_activity:loadTexture("hall_activity.png",1)
img_activity:setLayoutComponentEnabled(true)
img_activity:setName("img_activity")
img_activity:setTag(12)
img_activity:setCascadeColorEnabled(true)
img_activity:setCascadeOpacityEnabled(true)
img_activity:setPosition(383.1753, 0.0004)
layout = ccui.LayoutComponent:bindLayoutComponent(img_activity)
layout:setSize({width = 170.0000, height = 170.0000})
layout:setLeftMargin(298.1753)
layout:setRightMargin(-468.1753)
layout:setTopMargin(-85.0004)
layout:setBottomMargin(-84.9996)
hall_bottom_node:addChild(img_activity)

--Create Animation
result['animation'] = ccs.ActionTimeline:create()
  
result['animation']:setDuration(0)
result['animation']:setTimeSpeed(1.0000)
--Create Animation List

result['root'] = hall_bottom_node
return result;
end

return Result
