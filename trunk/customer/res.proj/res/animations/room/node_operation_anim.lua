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

--Create node_operation
local node_operation=cc.Node:create()
node_operation:setName("node_operation")

--Create img_operation_bg
local img_operation_bg = ccui.ImageView:create()
img_operation_bg:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/operation.plist")
img_operation_bg:loadTexture("operation_bg.png",1)
img_operation_bg:setLayoutComponentEnabled(true)
img_operation_bg:setName("img_operation_bg")
img_operation_bg:setTag(30)
img_operation_bg:setCascadeColorEnabled(true)
img_operation_bg:setCascadeOpacityEnabled(true)
img_operation_bg:setPosition(206.0000, 0.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_operation_bg)
layout:setSize({width = 412.0000, height = 161.0000})
layout:setRightMargin(-412.0000)
layout:setTopMargin(-80.5000)
layout:setBottomMargin(-80.5000)
node_operation:addChild(img_operation_bg)

--Create img_operation1
local img_operation1 = ccui.ImageView:create()
img_operation1:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/operation.plist")
img_operation1:loadTexture("i_operation_hu.png",1)
img_operation1:setLayoutComponentEnabled(true)
img_operation1:setName("img_operation1")
img_operation1:setTag(31)
img_operation1:setCascadeColorEnabled(true)
img_operation1:setCascadeOpacityEnabled(true)
img_operation1:setPosition(83.0000, 82.0000)
img_operation1:setScaleX(0.8000)
img_operation1:setScaleY(0.8000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_operation1)
layout:setPositionPercentX(0.2015)
layout:setPositionPercentY(0.5093)
layout:setPercentWidth(0.4175)
layout:setPercentHeight(1.0745)
layout:setSize({width = 172.0000, height = 173.0000})
layout:setLeftMargin(-3.0000)
layout:setRightMargin(243.0000)
layout:setTopMargin(-7.5000)
layout:setBottomMargin(-4.5000)
img_operation_bg:addChild(img_operation1)

--Create img_mahjong_bg
local img_mahjong_bg = ccui.ImageView:create()
img_mahjong_bg:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_mahjong_bg:loadTexture("mj_my_invisible.png",1)
img_mahjong_bg:setLayoutComponentEnabled(true)
img_mahjong_bg:setName("img_mahjong_bg")
img_mahjong_bg:setTag(5)
img_mahjong_bg:setCascadeColorEnabled(true)
img_mahjong_bg:setCascadeOpacityEnabled(true)
img_mahjong_bg:setPosition(224.8283, 78.0430)
img_mahjong_bg:setScaleX(0.7000)
img_mahjong_bg:setScaleY(0.7000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_mahjong_bg)
layout:setPositionPercentX(0.5457)
layout:setPositionPercentY(0.4847)
layout:setPercentWidth(0.3495)
layout:setPercentHeight(1.2484)
layout:setSize({width = 144.0000, height = 201.0000})
layout:setLeftMargin(152.8283)
layout:setRightMargin(115.1717)
layout:setTopMargin(-17.5430)
layout:setBottomMargin(-22.4570)
img_operation_bg:addChild(img_mahjong_bg)

--Create img_mahjong_fg
local img_mahjong_fg = ccui.ImageView:create()
img_mahjong_fg:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_mahjong_fg:loadTexture("bamboo_9.png",1)
img_mahjong_fg:setLayoutComponentEnabled(true)
img_mahjong_fg:setName("img_mahjong_fg")
img_mahjong_fg:setTag(6)
img_mahjong_fg:setCascadeColorEnabled(true)
img_mahjong_fg:setCascadeOpacityEnabled(true)
img_mahjong_fg:setPosition(222.2309, 66.7833)
img_mahjong_fg:setScaleX(0.7000)
img_mahjong_fg:setScaleY(0.7000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_mahjong_fg)
layout:setPositionPercentX(0.5394)
layout:setPositionPercentY(0.4148)
layout:setPercentWidth(0.2476)
layout:setPercentHeight(0.7702)
layout:setSize({width = 102.0000, height = 124.0000})
layout:setLeftMargin(171.2309)
layout:setRightMargin(138.7691)
layout:setTopMargin(32.2167)
layout:setBottomMargin(4.7833)
img_operation_bg:addChild(img_mahjong_fg)

--Create img_operation2
local img_operation2 = ccui.ImageView:create()
img_operation2:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/operation.plist")
img_operation2:loadTexture("i_operation_guo.png",1)
img_operation2:setLayoutComponentEnabled(true)
img_operation2:setName("img_operation2")
img_operation2:setTag(32)
img_operation2:setCascadeColorEnabled(true)
img_operation2:setCascadeOpacityEnabled(true)
img_operation2:setPosition(355.0000, 82.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_operation2)
layout:setPositionPercentX(0.8617)
layout:setPositionPercentY(0.5093)
layout:setPercentWidth(0.2791)
layout:setPercentHeight(0.7205)
layout:setSize({width = 115.0000, height = 116.0000})
layout:setLeftMargin(297.5000)
layout:setRightMargin(-0.5000)
layout:setTopMargin(21.0000)
layout:setBottomMargin(24.0000)
img_operation_bg:addChild(img_operation2)

--Create Animation
result['animation'] = ccs.ActionTimeline:create()
  
result['animation']:setDuration(15)
result['animation']:setTimeSpeed(0.5000)

--Create PositionTimeline
local PositionTimeline = ccs.Timeline:create()

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(0)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(206.0000)
localFrame:setY(0.0000)
PositionTimeline:addFrame(localFrame)

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(15)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(-206.0000)
localFrame:setY(0.0000)
PositionTimeline:addFrame(localFrame)

result['animation']:addTimeline(PositionTimeline)
PositionTimeline:setNode(img_operation_bg)

--Create ScaleTimeline
local ScaleTimeline = ccs.Timeline:create()

localFrame = ccs.ScaleFrame:create()
localFrame:setFrameIndex(0)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setScaleX(1.0000)
localFrame:setScaleY(1.0000)
ScaleTimeline:addFrame(localFrame)

localFrame = ccs.ScaleFrame:create()
localFrame:setFrameIndex(15)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setScaleX(1.0000)
localFrame:setScaleY(1.0000)
ScaleTimeline:addFrame(localFrame)

result['animation']:addTimeline(ScaleTimeline)
ScaleTimeline:setNode(img_operation_bg)

--Create RotationSkewTimeline
local RotationSkewTimeline = ccs.Timeline:create()

localFrame = ccs.RotationSkewFrame:create()
localFrame:setFrameIndex(0)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setSkewX(0.0000)
localFrame:setSkewY(0.0000)
RotationSkewTimeline:addFrame(localFrame)

localFrame = ccs.RotationSkewFrame:create()
localFrame:setFrameIndex(15)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setSkewX(0.0000)
localFrame:setSkewY(0.0000)
RotationSkewTimeline:addFrame(localFrame)

result['animation']:addTimeline(RotationSkewTimeline)
RotationSkewTimeline:setNode(img_operation_bg)
--Create Animation List

result['root'] = node_operation
return result;
end

return Result

