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

--Create node_zimo
local node_zimo=cc.Node:create()
node_zimo:setName("node_zimo")

--Create sp_zimo
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/operation.plist")
local sp_zimo = cc.Sprite:createWithSpriteFrameName("i_operation_zimo.png")
sp_zimo:setName("sp_zimo")
sp_zimo:setTag(60)
sp_zimo:setCascadeColorEnabled(true)
sp_zimo:setCascadeOpacityEnabled(true)
sp_zimo:setOpacity(229)
layout = ccui.LayoutComponent:bindLayoutComponent(sp_zimo)
layout:setSize({width = 199.0000, height = 143.0000})
layout:setLeftMargin(-99.5000)
layout:setRightMargin(-99.5000)
layout:setTopMargin(-71.5000)
layout:setBottomMargin(-71.5000)
sp_zimo:setBlendFunc({src = 1, dst = 771})
node_zimo:addChild(sp_zimo)

--Create sp_light
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_1_2.plist")
local sp_light = cc.Sprite:createWithSpriteFrameName("10019.png")
sp_light:setName("sp_light")
sp_light:setTag(24)
sp_light:setCascadeColorEnabled(true)
sp_light:setCascadeOpacityEnabled(true)
sp_light:setVisible(false)
sp_light:setPosition(15.3821, -5.8643)
layout = ccui.LayoutComponent:bindLayoutComponent(sp_light)
layout:setSize({width = 609.0000, height = 616.0000})
layout:setLeftMargin(-289.1179)
layout:setRightMargin(-319.8821)
layout:setTopMargin(-302.1357)
layout:setBottomMargin(-313.8643)
sp_light:setBlendFunc({src = 1, dst = 1})
node_zimo:addChild(sp_light)

--Create Animation
result['animation'] = ccs.ActionTimeline:create()
  
result['animation']:setDuration(45)
result['animation']:setTimeSpeed(0.5000)

--Create PositionTimeline
local PositionTimeline = ccs.Timeline:create()

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(0)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(0.0000)
localFrame:setY(0.0000)
PositionTimeline:addFrame(localFrame)

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(5)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(0.0000)
localFrame:setY(0.0000)
PositionTimeline:addFrame(localFrame)

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(7)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(0.0000)
localFrame:setY(0.0000)
PositionTimeline:addFrame(localFrame)

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(9)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(0.0000)
localFrame:setY(0.0000)
PositionTimeline:addFrame(localFrame)

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(11)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(0.0000)
localFrame:setY(0.0000)
PositionTimeline:addFrame(localFrame)

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(13)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(0.0000)
localFrame:setY(0.0000)
PositionTimeline:addFrame(localFrame)

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(35)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(0.0000)
localFrame:setY(0.0000)
PositionTimeline:addFrame(localFrame)

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(45)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(0.0000)
localFrame:setY(0.0000)
PositionTimeline:addFrame(localFrame)

result['animation']:addTimeline(PositionTimeline)
PositionTimeline:setNode(sp_zimo)

--Create ScaleTimeline
local ScaleTimeline = ccs.Timeline:create()

localFrame = ccs.ScaleFrame:create()
localFrame:setFrameIndex(0)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setScaleX(5.0000)
localFrame:setScaleY(5.0000)
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
localFrame:setFrameIndex(35)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setScaleX(1.0000)
localFrame:setScaleY(1.0000)
ScaleTimeline:addFrame(localFrame)

localFrame = ccs.ScaleFrame:create()
localFrame:setFrameIndex(45)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setScaleX(1.0000)
localFrame:setScaleY(1.0000)
ScaleTimeline:addFrame(localFrame)

result['animation']:addTimeline(ScaleTimeline)
ScaleTimeline:setNode(sp_zimo)

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
localFrame:setFrameIndex(35)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setSkewX(0.0000)
localFrame:setSkewY(0.0000)
RotationSkewTimeline:addFrame(localFrame)

localFrame = ccs.RotationSkewFrame:create()
localFrame:setFrameIndex(45)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setSkewX(0.0000)
localFrame:setSkewY(0.0000)
RotationSkewTimeline:addFrame(localFrame)

result['animation']:addTimeline(RotationSkewTimeline)
RotationSkewTimeline:setNode(sp_zimo)

--Create AlphaTimeline
local AlphaTimeline = ccs.Timeline:create()

localFrame = ccs.AlphaFrame:create()
localFrame:setFrameIndex(0)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setAlpha(25)
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
localFrame:setFrameIndex(35)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setAlpha(255)
AlphaTimeline:addFrame(localFrame)

localFrame = ccs.AlphaFrame:create()
localFrame:setFrameIndex(45)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setAlpha(0)
AlphaTimeline:addFrame(localFrame)

result['animation']:addTimeline(AlphaTimeline)
AlphaTimeline:setNode(sp_zimo)

--Create PositionTimeline
local PositionTimeline = ccs.Timeline:create()

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(4)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(15.3821)
localFrame:setY(-5.8643)
PositionTimeline:addFrame(localFrame)

localFrame = ccs.PositionFrame:create()
localFrame:setFrameIndex(23)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setX(15.3821)
localFrame:setY(-5.8643)
PositionTimeline:addFrame(localFrame)

result['animation']:addTimeline(PositionTimeline)
PositionTimeline:setNode(sp_light)

--Create ScaleTimeline
local ScaleTimeline = ccs.Timeline:create()

localFrame = ccs.ScaleFrame:create()
localFrame:setFrameIndex(4)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setScaleX(1.0000)
localFrame:setScaleY(1.0000)
ScaleTimeline:addFrame(localFrame)

localFrame = ccs.ScaleFrame:create()
localFrame:setFrameIndex(23)
localFrame:setTween(true)
localFrame:setTweenType(0)
localFrame:setScaleX(1.0000)
localFrame:setScaleY(1.0000)
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
localFrame:setFrameIndex(23)
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
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_1_1.plist")
localFrame:setTextureName("10001.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(5)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_1_1.plist")
localFrame:setTextureName("10001.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(6)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_1_1.plist")
localFrame:setTextureName("10002.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(7)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_1_1.plist")
localFrame:setTextureName("10003.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(8)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_1_1.plist")
localFrame:setTextureName("10004.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(9)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_1_1.plist")
localFrame:setTextureName("10005.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(10)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_1_1.plist")
localFrame:setTextureName("10006.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(11)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_1_1.plist")
localFrame:setTextureName("10007.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(12)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_1_1.plist")
localFrame:setTextureName("10008.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(13)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_1_1.plist")
localFrame:setTextureName("10009.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(14)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_1_2.plist")
localFrame:setTextureName("10010.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(15)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_1_2.plist")
localFrame:setTextureName("10011.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(16)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_1_2.plist")
localFrame:setTextureName("10012.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(17)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_1_2.plist")
localFrame:setTextureName("10013.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(18)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_1_2.plist")
localFrame:setTextureName("10014.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(19)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_1_2.plist")
localFrame:setTextureName("10015.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(20)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_1_2.plist")
localFrame:setTextureName("10016.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(21)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_1_2.plist")
localFrame:setTextureName("10017.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(22)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_1_2.plist")
localFrame:setTextureName("10018.png")
FileDataTimeline:addFrame(localFrame)

localFrame = ccs.TextureFrame:create()
localFrame:setFrameIndex(23)
localFrame:setTween(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/common/plist/light_1_2.plist")
localFrame:setTextureName("10019.png")
FileDataTimeline:addFrame(localFrame)

result['animation']:addTimeline(FileDataTimeline)
FileDataTimeline:setNode(sp_light)

--Create BlendFuncTimeline
local BlendFuncTimeline = ccs.Timeline:create()

result['animation']:addTimeline(BlendFuncTimeline)
BlendFuncTimeline:setNode(sp_light)

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
localFrame:setFrameIndex(23)
localFrame:setTween(false)
localFrame:setVisible(true)
VisibleForFrameTimeline:addFrame(localFrame)

localFrame = ccs.VisibleFrame:create()
localFrame:setFrameIndex(24)
localFrame:setTween(false)
localFrame:setVisible(false)
VisibleForFrameTimeline:addFrame(localFrame)

result['animation']:addTimeline(VisibleForFrameTimeline)
VisibleForFrameTimeline:setNode(sp_light)
--Create Animation List
local animation0 = {name="animation0", startIndex=0, endIndex=45}
result['animation']:addAnimationInfo(animation0)

result['root'] = node_zimo
return result;
end

return Result

