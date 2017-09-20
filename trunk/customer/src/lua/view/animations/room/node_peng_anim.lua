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

--Create node_peng
local node_peng=cc.Node:create()
node_peng:setName("node_peng")

--Create sp_peng
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/operation.plist")
local sp_peng = cc.Sprite:createWithSpriteFrameName("i_operation_peng1.png")
sp_peng:setName("sp_peng")
sp_peng:setTag(26)
sp_peng:setCascadeColorEnabled(true)
sp_peng:setCascadeOpacityEnabled(true)
sp_peng:setPosition(-6.0000, 17.0000)
sp_peng:setOpacity(0)
layout = ccui.LayoutComponent:bindLayoutComponent(sp_peng)
layout:setSize({width = 165.0000, height = 142.0000})
layout:setLeftMargin(-88.5000)
layout:setRightMargin(-76.5000)
layout:setTopMargin(-88.0000)
layout:setBottomMargin(-54.0000)
sp_peng:setBlendFunc({src = 1, dst = 771})
node_peng:addChild(sp_peng)

--Create sp_light
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_3.plist")
local sp_light = cc.Sprite:createWithSpriteFrameName("light_07.png")
sp_light:setName("sp_light")
sp_light:setTag(41)
sp_light:setCascadeColorEnabled(true)
sp_light:setCascadeOpacityEnabled(true)
sp_light:setVisible(false)
sp_light:setPosition(-4.5345, 19.6403)
sp_light:setScaleX(1.5000)
sp_light:setScaleY(1.5000)
layout = ccui.LayoutComponent:bindLayoutComponent(sp_light)
layout:setSize({width = 176.0000, height = 176.0000})
layout:setLeftMargin(-92.5345)
layout:setRightMargin(-83.4655)
layout:setTopMargin(-107.6403)
layout:setBottomMargin(-68.3597)
sp_light:setBlendFunc({src = 1, dst = 1})
node_peng:addChild(sp_light)

--Create Animation
result['animation'] = ccs.ActionTimeline:create()
  
result['animation']:setDuration(35)
result['animation']:setTimeSpeed(0.5000)

--Create PositionTimeline
local PositionTimeline = ccs.Timeline:create()

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(0)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(-6.0000)
localFrame:setY(17.0000)
PositionTimeline:addFrame(localFrame)

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(5)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(-6.0000)
localFrame:setY(17.0000)
PositionTimeline:addFrame(localFrame)

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(7)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(-6.0000)
localFrame:setY(17.0000)
PositionTimeline:addFrame(localFrame)

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(9)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(-6.0000)
localFrame:setY(17.0000)
PositionTimeline:addFrame(localFrame)

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(11)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(-6.0000)
localFrame:setY(17.0000)
PositionTimeline:addFrame(localFrame)

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(13)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(-6.0000)
localFrame:setY(17.0000)
PositionTimeline:addFrame(localFrame)

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(25)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(-6.0000)
localFrame:setY(17.0000)
PositionTimeline:addFrame(localFrame)

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(35)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(-6.0000)
localFrame:setY(17.0000)
PositionTimeline:addFrame(localFrame)

result['animation']:addTimeline(PositionTimeline)
PositionTimeline:setNode(sp_peng)

--Create ScaleTimeline
local ScaleTimeline = ccs.Timeline:create()

localFrame = ccs.ScaleFrame:create()
localFrame:setFrameIndex(0)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setScaleX(4.0000)
localFrame:setScaleY(4.0000)
ScaleTimeline:addFrame(localFrame)

localFrame = ccs.ScaleFrame:create()
localFrame:setFrameIndex(5)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setScaleX(1.0000)
localFrame:setScaleY(1.0000)
ScaleTimeline:addFrame(localFrame)

localFrame = ccs.ScaleFrame:create()
localFrame:setFrameIndex(7)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setScaleX(1.1000)
localFrame:setScaleY(1.1000)
ScaleTimeline:addFrame(localFrame)

localFrame = ccs.ScaleFrame:create()
localFrame:setFrameIndex(9)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setScaleX(1.0000)
localFrame:setScaleY(1.0000)
ScaleTimeline:addFrame(localFrame)

localFrame = ccs.ScaleFrame:create()
localFrame:setFrameIndex(11)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setScaleX(1.0500)
localFrame:setScaleY(1.0500)
ScaleTimeline:addFrame(localFrame)

localFrame = ccs.ScaleFrame:create()
localFrame:setFrameIndex(13)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setScaleX(1.0000)
localFrame:setScaleY(1.0000)
ScaleTimeline:addFrame(localFrame)

localFrame = ccs.ScaleFrame:create()
localFrame:setFrameIndex(25)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setScaleX(1.0000)
localFrame:setScaleY(1.0000)
ScaleTimeline:addFrame(localFrame)

localFrame = ccs.ScaleFrame:create()
localFrame:setFrameIndex(35)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setScaleX(1.0000)
localFrame:setScaleY(1.0000)
ScaleTimeline:addFrame(localFrame)

result['animation']:addTimeline(ScaleTimeline)
ScaleTimeline:setNode(sp_peng)

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
localFrame:setFrameIndex(5)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setSkewX(0.0000)
localFrame:setSkewY(0.0000)
RotationSkewTimeline:addFrame(localFrame)

localFrame = ccs.RotationSkewFrame:create()
localFrame:setFrameIndex(7)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setSkewX(0.0000)
localFrame:setSkewY(0.0000)
RotationSkewTimeline:addFrame(localFrame)

localFrame = ccs.RotationSkewFrame:create()
localFrame:setFrameIndex(9)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setSkewX(0.0000)
localFrame:setSkewY(0.0000)
RotationSkewTimeline:addFrame(localFrame)

localFrame = ccs.RotationSkewFrame:create()
localFrame:setFrameIndex(11)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setSkewX(0.0000)
localFrame:setSkewY(0.0000)
RotationSkewTimeline:addFrame(localFrame)

localFrame = ccs.RotationSkewFrame:create()
localFrame:setFrameIndex(13)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setSkewX(0.0000)
localFrame:setSkewY(0.0000)
RotationSkewTimeline:addFrame(localFrame)

localFrame = ccs.RotationSkewFrame:create()
localFrame:setFrameIndex(25)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setSkewX(0.0000)
localFrame:setSkewY(0.0000)
RotationSkewTimeline:addFrame(localFrame)

localFrame = ccs.RotationSkewFrame:create()
localFrame:setFrameIndex(35)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setSkewX(0.0000)
localFrame:setSkewY(0.0000)
RotationSkewTimeline:addFrame(localFrame)

result['animation']:addTimeline(RotationSkewTimeline)
RotationSkewTimeline:setNode(sp_peng)

--Create AlphaTimeline
local AlphaTimeline = ccs.Timeline:create()

localFrame = ccs.AlphaFrame:create()
localFrame:setFrameIndex(0)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setAlpha(0)
AlphaTimeline:addFrame(localFrame)

localFrame = ccs.AlphaFrame:create()
localFrame:setFrameIndex(5)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setAlpha(255)
AlphaTimeline:addFrame(localFrame)

localFrame = ccs.AlphaFrame:create()
localFrame:setFrameIndex(7)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setAlpha(255)
AlphaTimeline:addFrame(localFrame)

localFrame = ccs.AlphaFrame:create()
localFrame:setFrameIndex(9)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setAlpha(255)
AlphaTimeline:addFrame(localFrame)

localFrame = ccs.AlphaFrame:create()
localFrame:setFrameIndex(11)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setAlpha(255)
AlphaTimeline:addFrame(localFrame)

localFrame = ccs.AlphaFrame:create()
localFrame:setFrameIndex(13)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setAlpha(255)
AlphaTimeline:addFrame(localFrame)

localFrame = ccs.AlphaFrame:create()
localFrame:setFrameIndex(25)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setAlpha(255)
AlphaTimeline:addFrame(localFrame)

localFrame = ccs.AlphaFrame:create()
localFrame:setFrameIndex(35)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setAlpha(0)
AlphaTimeline:addFrame(localFrame)

result['animation']:addTimeline(AlphaTimeline)
AlphaTimeline:setNode(sp_peng)

--Create PositionTimeline
local PositionTimeline = ccs.Timeline:create()

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(4)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(-4.5345)
localFrame:setY(19.6403)
PositionTimeline:addFrame(localFrame)

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(6)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(-18.0000)
localFrame:setY(31.0000)
PositionTimeline:addFrame(localFrame)

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(7)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(6.5455)
localFrame:setY(13.4325)
PositionTimeline:addFrame(localFrame)

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(8)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(31.0909)
localFrame:setY(-4.1350)
PositionTimeline:addFrame(localFrame)

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(12)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(-4.5345)
localFrame:setY(19.6403)
PositionTimeline:addFrame(localFrame)

result['animation']:addTimeline(PositionTimeline)
PositionTimeline:setNode(sp_light)

--Create ScaleTimeline
local ScaleTimeline = ccs.Timeline:create()

localFrame = ccs.ScaleFrame:create()
localFrame:setFrameIndex(4)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setScaleX(1.5000)
localFrame:setScaleY(1.5000)
ScaleTimeline:addFrame(localFrame)

localFrame = ccs.ScaleFrame:create()
localFrame:setFrameIndex(6)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setScaleX(1.5000)
localFrame:setScaleY(1.5000)
ScaleTimeline:addFrame(localFrame)

localFrame = ccs.ScaleFrame:create()
localFrame:setFrameIndex(7)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setScaleX(1.5000)
localFrame:setScaleY(1.5000)
ScaleTimeline:addFrame(localFrame)

localFrame = ccs.ScaleFrame:create()
localFrame:setFrameIndex(8)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setScaleX(1.5000)
localFrame:setScaleY(1.5000)
ScaleTimeline:addFrame(localFrame)

localFrame = ccs.ScaleFrame:create()
localFrame:setFrameIndex(12)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setScaleX(1.5000)
localFrame:setScaleY(1.5000)
ScaleTimeline:addFrame(localFrame)

result['animation']:addTimeline(ScaleTimeline)
ScaleTimeline:setNode(sp_light)

--Create RotationSkewTimeline
local RotationSkewTimeline = ccs.Timeline:create()

localFrame = ccs.RotationSkewFrame:create()
localFrame:setFrameIndex(4)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setSkewX(0.0000)
localFrame:setSkewY(0.0000)
RotationSkewTimeline:addFrame(localFrame)

localFrame = ccs.RotationSkewFrame:create()
localFrame:setFrameIndex(6)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setSkewX(0.0000)
localFrame:setSkewY(0.0000)
RotationSkewTimeline:addFrame(localFrame)

localFrame = ccs.RotationSkewFrame:create()
localFrame:setFrameIndex(7)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setSkewX(0.0000)
localFrame:setSkewY(0.0000)
RotationSkewTimeline:addFrame(localFrame)

localFrame = ccs.RotationSkewFrame:create()
localFrame:setFrameIndex(8)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setSkewX(0.0000)
localFrame:setSkewY(0.0000)
RotationSkewTimeline:addFrame(localFrame)

localFrame = ccs.RotationSkewFrame:create()
localFrame:setFrameIndex(12)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setSkewX(0.0000)
localFrame:setSkewY(0.0000)
RotationSkewTimeline:addFrame(localFrame)

result['animation']:addTimeline(RotationSkewTimeline)
RotationSkewTimeline:setNode(sp_light)

--Create FileDataTimeline
local FileDataTimeline = ccs.Timeline:create()

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(4)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_3.plist")
localFrame:setTextureName("light_01.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(5)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_3.plist")
localFrame:setTextureName("light_01.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(6)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_3.plist")
localFrame:setTextureName("light_02.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(7)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_3.plist")
localFrame:setTextureName("light_03.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(8)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_3.plist")
localFrame:setTextureName("light_04.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(9)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_3.plist")
localFrame:setTextureName("light_05.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(10)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_3.plist")
localFrame:setTextureName("light_06.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(11)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_3.plist")
localFrame:setTextureName("light_07.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(12)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_3.plist")
localFrame:setTextureName("light_07.png")
FileDataTimeline:addFrame(localFrame)

result['animation']:addTimeline(FileDataTimeline)
FileDataTimeline:setNode(sp_light)

--Create VisibleForFrameTimeline
local VisibleForFrameTimeline = ccs.Timeline:create()

localFrame = ccs.VisibleFrame:create()
localFrame:setFrameIndex(4)
localFrame:setTween(false)
localFrame:setVisible(false)
VisibleForFrameTimeline:addFrame(localFrame)

localFrame = ccs.VisibleFrame:create()
localFrame:setFrameIndex(5)
localFrame:setTween(false)
localFrame:setVisible(true)
VisibleForFrameTimeline:addFrame(localFrame)

localFrame = ccs.VisibleFrame:create()
localFrame:setFrameIndex(6)
localFrame:setTween(false)
localFrame:setVisible(true)
VisibleForFrameTimeline:addFrame(localFrame)

localFrame = ccs.VisibleFrame:create()
localFrame:setFrameIndex(7)
localFrame:setTween(false)
localFrame:setVisible(true)
VisibleForFrameTimeline:addFrame(localFrame)

localFrame = ccs.VisibleFrame:create()
localFrame:setFrameIndex(8)
localFrame:setTween(false)
localFrame:setVisible(true)
VisibleForFrameTimeline:addFrame(localFrame)

localFrame = ccs.VisibleFrame:create()
localFrame:setFrameIndex(12)
localFrame:setTween(false)
localFrame:setVisible(false)
VisibleForFrameTimeline:addFrame(localFrame)

result['animation']:addTimeline(VisibleForFrameTimeline)
VisibleForFrameTimeline:setNode(sp_light)
--Create Animation List
local animation0 = {name="animation0", startIndex=0, endIndex=35}
result['animation']:addAnimationInfo(animation0)

result['root'] = node_peng
return result;
end

return Result
