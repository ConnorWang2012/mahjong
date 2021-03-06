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

--Create hall_top_node
local hall_top_node=cc.Node:create()
hall_top_node:setName("hall_top_node")

--Create img_role
local img_role = ccui.ImageView:create()
img_role:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/hall/plist/hall_top.plist")
img_role:loadTexture("hall_role.png",1)
img_role:setLayoutComponentEnabled(true)
img_role:setName("img_role")
img_role:setTag(13)
img_role:setCascadeColorEnabled(true)
img_role:setCascadeOpacityEnabled(true)
img_role:setPosition(-851.1896, 0.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_role)
layout:setSize({width = 175.0000, height = 175.0000})
layout:setLeftMargin(-938.6896)
layout:setRightMargin(763.6896)
layout:setTopMargin(-87.5000)
layout:setBottomMargin(-87.5000)
hall_top_node:addChild(img_role)

--Create txt_role_name
local txt_role_name = ccui.Text:create()
txt_role_name:ignoreContentAdaptWithSize(true)
txt_role_name:setTextAreaSize({width = 0, height = 0})
txt_role_name:setFontSize(60)
txt_role_name:setString([[role name]])
txt_role_name:setTextVerticalAlignment(1)
txt_role_name:setLayoutComponentEnabled(true)
txt_role_name:setName("txt_role_name")
txt_role_name:setTag(18)
txt_role_name:setCascadeColorEnabled(true)
txt_role_name:setCascadeOpacityEnabled(true)
txt_role_name:setAnchorPoint(0.0000, 0.5000)
txt_role_name:setPosition(-745.6177, 49.9995)
layout = ccui.LayoutComponent:bindLayoutComponent(txt_role_name)
layout:setSize({width = 270.0000, height = 60.0000})
layout:setLeftMargin(-745.6177)
layout:setRightMargin(475.6177)
layout:setTopMargin(-79.9995)
layout:setBottomMargin(19.9995)
hall_top_node:addChild(txt_role_name)

--Create img_top_title_bg
local img_top_title_bg = ccui.ImageView:create()
img_top_title_bg:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/hall/plist/hall_top.plist")
img_top_title_bg:loadTexture("hall_title_bg.png",1)
img_top_title_bg:setLayoutComponentEnabled(true)
img_top_title_bg:setName("img_top_title_bg")
img_top_title_bg:setTag(14)
img_top_title_bg:setCascadeColorEnabled(true)
img_top_title_bg:setCascadeOpacityEnabled(true)
layout = ccui.LayoutComponent:bindLayoutComponent(img_top_title_bg)
layout:setSize({width = 628.0000, height = 120.0000})
layout:setLeftMargin(-314.0000)
layout:setRightMargin(-314.0000)
layout:setTopMargin(-60.0000)
layout:setBottomMargin(-60.0000)
hall_top_node:addChild(img_top_title_bg)

--Create img_top_title
local img_top_title = ccui.ImageView:create()
img_top_title:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/hall/plist/hall_top.plist")
img_top_title:loadTexture("hall_title_name.png",1)
img_top_title:setLayoutComponentEnabled(true)
img_top_title:setName("img_top_title")
img_top_title:setTag(15)
img_top_title:setCascadeColorEnabled(true)
img_top_title:setCascadeOpacityEnabled(true)
layout = ccui.LayoutComponent:bindLayoutComponent(img_top_title)
layout:setSize({width = 628.0000, height = 120.0000})
layout:setLeftMargin(-314.0000)
layout:setRightMargin(-314.0000)
layout:setTopMargin(-60.0000)
layout:setBottomMargin(-60.0000)
hall_top_node:addChild(img_top_title)

--Create img_setting
local img_setting = ccui.ImageView:create()
img_setting:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/hall/plist/hall_top.plist")
img_setting:loadTexture("hall_set.png",1)
img_setting:setLayoutComponentEnabled(true)
img_setting:setName("img_setting")
img_setting:setTag(16)
img_setting:setCascadeColorEnabled(true)
img_setting:setCascadeOpacityEnabled(true)
img_setting:setPosition(813.1322, 0.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_setting)
layout:setSize({width = 110.0000, height = 110.0000})
layout:setLeftMargin(758.1322)
layout:setRightMargin(-868.1322)
layout:setTopMargin(-55.0000)
layout:setBottomMargin(-55.0000)
hall_top_node:addChild(img_setting)

--Create img_msg
local img_msg = ccui.ImageView:create()
img_msg:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/hall/plist/hall_top.plist")
img_msg:loadTexture("hall_msg.png",1)
img_msg:setLayoutComponentEnabled(true)
img_msg:setName("img_msg")
img_msg:setTag(17)
img_msg:setCascadeColorEnabled(true)
img_msg:setCascadeOpacityEnabled(true)
img_msg:setPosition(593.1660, 0.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_msg)
layout:setSize({width = 110.0000, height = 110.0000})
layout:setLeftMargin(538.1660)
layout:setRightMargin(-648.1660)
layout:setTopMargin(-55.0000)
layout:setBottomMargin(-55.0000)
hall_top_node:addChild(img_msg)

--Create Animation
result['animation'] = ccs.ActionTimeline:create()
  
result['animation']:setDuration(0)
result['animation']:setTimeSpeed(1.0000)
--Create Animation List

result['root'] = hall_top_node
return result;
end

return Result

