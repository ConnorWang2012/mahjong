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
img_operation_bg:setScale9Enabled(true)
img_operation_bg:setCapInsets({x = 157, y = 53, width = 189, height = 55})
img_operation_bg:setLayoutComponentEnabled(true)
img_operation_bg:setName("img_operation_bg")
img_operation_bg:setTag(30)
img_operation_bg:setCascadeColorEnabled(true)
img_operation_bg:setCascadeOpacityEnabled(true)
img_operation_bg:setPosition(288.0000, -0.0001)
layout = ccui.LayoutComponent:bindLayoutComponent(img_operation_bg)
layout:setSize({width = 585.0000, height = 161.0000})
layout:setLeftMargin(-4.5000)
layout:setRightMargin(-580.5000)
layout:setTopMargin(-80.4999)
layout:setBottomMargin(-80.5001)
node_operation:addChild(img_operation_bg)

--Create img_operation1
local img_operation1 = ccui.ImageView:create()
img_operation1:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/operation.plist")
img_operation1:loadTexture("i_operation_chi.png",1)
img_operation1:setLayoutComponentEnabled(true)
img_operation1:setName("img_operation1")
img_operation1:setTag(31)
img_operation1:setCascadeColorEnabled(true)
img_operation1:setCascadeOpacityEnabled(true)
img_operation1:setPosition(83.0000, 82.0000)
img_operation1:setScaleX(0.8000)
img_operation1:setScaleY(0.8000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_operation1)
layout:setPositionPercentX(0.1419)
layout:setPositionPercentY(0.5093)
layout:setPercentWidth(0.2000)
layout:setPercentHeight(0.7391)
layout:setSize({width = 117.0000, height = 119.0000})
layout:setLeftMargin(24.5000)
layout:setRightMargin(443.5000)
layout:setTopMargin(19.5000)
layout:setBottomMargin(22.5000)
img_operation_bg:addChild(img_operation1)

--Create img_mahjong_bg1
local img_mahjong_bg1 = ccui.ImageView:create()
img_mahjong_bg1:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_mahjong_bg1:loadTexture("mj_my_invisible.png",1)
img_mahjong_bg1:setLayoutComponentEnabled(true)
img_mahjong_bg1:setName("img_mahjong_bg1")
img_mahjong_bg1:setTag(5)
img_mahjong_bg1:setCascadeColorEnabled(true)
img_mahjong_bg1:setCascadeOpacityEnabled(true)
img_mahjong_bg1:setPosition(224.8283, 78.0000)
img_mahjong_bg1:setScaleX(0.7000)
img_mahjong_bg1:setScaleY(0.7000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_mahjong_bg1)
layout:setPositionPercentX(0.3843)
layout:setPositionPercentY(0.4845)
layout:setPercentWidth(0.2462)
layout:setPercentHeight(1.2484)
layout:setSize({width = 144.0000, height = 201.0000})
layout:setLeftMargin(152.8283)
layout:setRightMargin(288.1717)
layout:setTopMargin(-17.5000)
layout:setBottomMargin(-22.5000)
img_operation_bg:addChild(img_mahjong_bg1)

--Create img_mahjong_bg2
local img_mahjong_bg2 = ccui.ImageView:create()
img_mahjong_bg2:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_mahjong_bg2:loadTexture("mj_my_invisible.png",1)
img_mahjong_bg2:setLayoutComponentEnabled(true)
img_mahjong_bg2:setName("img_mahjong_bg2")
img_mahjong_bg2:setTag(13)
img_mahjong_bg2:setCascadeColorEnabled(true)
img_mahjong_bg2:setCascadeOpacityEnabled(true)
img_mahjong_bg2:setPosition(311.0000, 78.0000)
img_mahjong_bg2:setScaleX(0.7000)
img_mahjong_bg2:setScaleY(0.7000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_mahjong_bg2)
layout:setPositionPercentX(0.5316)
layout:setPositionPercentY(0.4845)
layout:setPercentWidth(0.2462)
layout:setPercentHeight(1.2484)
layout:setSize({width = 144.0000, height = 201.0000})
layout:setLeftMargin(239.0000)
layout:setRightMargin(202.0000)
layout:setTopMargin(-17.5000)
layout:setBottomMargin(-22.5000)
img_operation_bg:addChild(img_mahjong_bg2)

--Create img_mahjong_bg3
local img_mahjong_bg3 = ccui.ImageView:create()
img_mahjong_bg3:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_mahjong_bg3:loadTexture("mj_my_invisible.png",1)
img_mahjong_bg3:setLayoutComponentEnabled(true)
img_mahjong_bg3:setName("img_mahjong_bg3")
img_mahjong_bg3:setTag(14)
img_mahjong_bg3:setCascadeColorEnabled(true)
img_mahjong_bg3:setCascadeOpacityEnabled(true)
img_mahjong_bg3:setPosition(397.0000, 78.0000)
img_mahjong_bg3:setScaleX(0.7000)
img_mahjong_bg3:setScaleY(0.7000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_mahjong_bg3)
layout:setPositionPercentX(0.6786)
layout:setPositionPercentY(0.4845)
layout:setPercentWidth(0.2462)
layout:setPercentHeight(1.2484)
layout:setSize({width = 144.0000, height = 201.0000})
layout:setLeftMargin(325.0000)
layout:setRightMargin(116.0000)
layout:setTopMargin(-17.5000)
layout:setBottomMargin(-22.5000)
img_operation_bg:addChild(img_mahjong_bg3)

--Create img_mahjong_fg1
local img_mahjong_fg1 = ccui.ImageView:create()
img_mahjong_fg1:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_mahjong_fg1:loadTexture("bamboo_7.png",1)
img_mahjong_fg1:setLayoutComponentEnabled(true)
img_mahjong_fg1:setName("img_mahjong_fg1")
img_mahjong_fg1:setTag(6)
img_mahjong_fg1:setCascadeColorEnabled(true)
img_mahjong_fg1:setCascadeOpacityEnabled(true)
img_mahjong_fg1:setPosition(223.0000, 66.0000)
img_mahjong_fg1:setScaleX(0.7000)
img_mahjong_fg1:setScaleY(0.7000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_mahjong_fg1)
layout:setPositionPercentX(0.3812)
layout:setPositionPercentY(0.4099)
layout:setPercentWidth(0.1744)
layout:setPercentHeight(0.7702)
layout:setSize({width = 102.0000, height = 124.0000})
layout:setLeftMargin(172.0000)
layout:setRightMargin(311.0000)
layout:setTopMargin(33.0000)
layout:setBottomMargin(4.0000)
img_operation_bg:addChild(img_mahjong_fg1)

--Create img_mahjong_fg2
local img_mahjong_fg2 = ccui.ImageView:create()
img_mahjong_fg2:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_mahjong_fg2:loadTexture("bamboo_8.png",1)
img_mahjong_fg2:setLayoutComponentEnabled(true)
img_mahjong_fg2:setName("img_mahjong_fg2")
img_mahjong_fg2:setTag(15)
img_mahjong_fg2:setCascadeColorEnabled(true)
img_mahjong_fg2:setCascadeOpacityEnabled(true)
img_mahjong_fg2:setPosition(310.0000, 66.0000)
img_mahjong_fg2:setScaleX(0.7000)
img_mahjong_fg2:setScaleY(0.7000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_mahjong_fg2)
layout:setPositionPercentX(0.5299)
layout:setPositionPercentY(0.4099)
layout:setPercentWidth(0.1744)
layout:setPercentHeight(0.7702)
layout:setSize({width = 102.0000, height = 124.0000})
layout:setLeftMargin(259.0000)
layout:setRightMargin(224.0000)
layout:setTopMargin(33.0000)
layout:setBottomMargin(4.0000)
img_operation_bg:addChild(img_mahjong_fg2)

--Create img_mahjong_fg3
local img_mahjong_fg3 = ccui.ImageView:create()
img_mahjong_fg3:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/cards.plist")
img_mahjong_fg3:loadTexture("bamboo_9.png",1)
img_mahjong_fg3:setLayoutComponentEnabled(true)
img_mahjong_fg3:setName("img_mahjong_fg3")
img_mahjong_fg3:setTag(16)
img_mahjong_fg3:setCascadeColorEnabled(true)
img_mahjong_fg3:setCascadeOpacityEnabled(true)
img_mahjong_fg3:setPosition(396.0000, 66.0000)
img_mahjong_fg3:setScaleX(0.7000)
img_mahjong_fg3:setScaleY(0.7000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_mahjong_fg3)
layout:setPositionPercentX(0.6769)
layout:setPositionPercentY(0.4099)
layout:setPercentWidth(0.1744)
layout:setPercentHeight(0.7702)
layout:setSize({width = 102.0000, height = 124.0000})
layout:setLeftMargin(345.0000)
layout:setRightMargin(138.0000)
layout:setTopMargin(33.0000)
layout:setBottomMargin(4.0000)
img_operation_bg:addChild(img_mahjong_fg3)

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
img_operation2:setPosition(524.3735, 80.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_operation2)
layout:setPositionPercentX(0.8964)
layout:setPositionPercentY(0.4969)
layout:setPercentWidth(0.1966)
layout:setPercentHeight(0.7205)
layout:setSize({width = 115.0000, height = 116.0000})
layout:setLeftMargin(466.8735)
layout:setRightMargin(3.1265)
layout:setTopMargin(23.0000)
layout:setBottomMargin(22.0000)
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
localFrame:setX(288.0000)
localFrame:setY(-0.0001)
PositionTimeline:addFrame(localFrame)

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(15)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(-293.0000)
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

