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

--Create hall_middle_node
local hall_middle_node=cc.Node:create()
hall_middle_node:setName("hall_middle_node")

--Create node_left
local node_left=cc.Node:create()
node_left:setName("node_left")
node_left:setTag(20)
node_left:setCascadeColorEnabled(true)
node_left:setCascadeOpacityEnabled(true)
node_left:setPosition(-800.0000, 0.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(node_left)
layout:setLeftMargin(-800.0000)
layout:setRightMargin(800.0000)
hall_middle_node:addChild(node_left)

--Create node_middle
local node_middle=cc.Node:create()
node_middle:setName("node_middle")
node_middle:setTag(21)
node_middle:setCascadeColorEnabled(true)
node_middle:setCascadeOpacityEnabled(true)
layout = ccui.LayoutComponent:bindLayoutComponent(node_middle)
hall_middle_node:addChild(node_middle)

--Create img_middle_girl
local img_middle_girl = ccui.ImageView:create()
img_middle_girl:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/hall/plist/hall_middle.plist")
img_middle_girl:loadTexture("hall_middle_girl.png",1)
img_middle_girl:setLayoutComponentEnabled(true)
img_middle_girl:setName("img_middle_girl")
img_middle_girl:setTag(23)
img_middle_girl:setCascadeColorEnabled(true)
img_middle_girl:setCascadeOpacityEnabled(true)
layout = ccui.LayoutComponent:bindLayoutComponent(img_middle_girl)
layout:setSize({width = 545.0000, height = 479.0000})
layout:setLeftMargin(-272.5000)
layout:setRightMargin(-272.5000)
layout:setTopMargin(-239.5000)
layout:setBottomMargin(-239.5000)
node_middle:addChild(img_middle_girl)

--Create node_right
local node_right=cc.Node:create()
node_right:setName("node_right")
node_right:setTag(22)
node_right:setCascadeColorEnabled(true)
node_right:setCascadeOpacityEnabled(true)
node_right:setPosition(800.0000, 0.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(node_right)
layout:setLeftMargin(800.0000)
layout:setRightMargin(-800.0000)
hall_middle_node:addChild(node_right)

--Create Animation
result['animation'] = ccs.ActionTimeline:create()
  
result['animation']:setDuration(0)
result['animation']:setTimeSpeed(1.0000)
--Create Animation List

result['root'] = hall_middle_node
return result;
end

return Result
