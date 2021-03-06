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

--Create hall_player_info_layer
local hall_player_info_layer=cc.Node:create()
hall_player_info_layer:setName("hall_player_info_layer")
layout = ccui.LayoutComponent:bindLayoutComponent(hall_player_info_layer)
layout:setSize({width = 1920.0000, height = 1080.0000})

--Create img_bg
local img_bg = ccui.ImageView:create()
img_bg:ignoreContentAdaptWithSize(false)
img_bg:loadTexture("assets/common/popup_bg1.png",0)
img_bg:setLayoutComponentEnabled(true)
img_bg:setName("img_bg")
img_bg:setTag(89)
img_bg:setCascadeColorEnabled(true)
img_bg:setCascadeOpacityEnabled(true)
img_bg:setPosition(960.0000, 486.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_bg)
layout:setPositionPercentXEnabled(true)
layout:setPositionPercentYEnabled(true)
layout:setPositionPercentX(0.5000)
layout:setPositionPercentY(0.4500)
layout:setPercentWidth(0.8333)
layout:setPercentHeight(0.7407)
layout:setSize({width = 1600.0000, height = 800.0000})
layout:setLeftMargin(160.0000)
layout:setRightMargin(160.0000)
layout:setTopMargin(194.0000)
layout:setBottomMargin(86.0000)
hall_player_info_layer:addChild(img_bg)

--Create img_tab
local img_tab = ccui.ImageView:create()
img_tab:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/hall/plist/hall_top.plist")
img_tab:loadTexture("hall_title_bg.png",1)
img_tab:setFlippedY(true)
img_tab:setLayoutComponentEnabled(true)
img_tab:setName("img_tab")
img_tab:setTag(91)
img_tab:setCascadeColorEnabled(true)
img_tab:setCascadeOpacityEnabled(true)
img_tab:setPosition(800.0000, 861.6801)
layout = ccui.LayoutComponent:bindLayoutComponent(img_tab)
layout:setPositionPercentXEnabled(true)
layout:setPositionPercentYEnabled(true)
layout:setPositionPercentX(0.5000)
layout:setPositionPercentY(1.0771)
layout:setPercentWidth(0.3650)
layout:setPercentHeight(0.1700)
layout:setSize({width = 584.0000, height = 136.0000})
layout:setLeftMargin(508.0000)
layout:setRightMargin(508.0000)
layout:setTopMargin(-129.6801)
layout:setBottomMargin(793.6801)
img_bg:addChild(img_tab)

--Create txt_title
local txt_title = ccui.Text:create()
txt_title:ignoreContentAdaptWithSize(true)
txt_title:setTextAreaSize({width = 0, height = 0})
txt_title:setFontName("assets/font/FZZhengHeiS-B-GB.ttf")
txt_title:setFontSize(50)
txt_title:setString([[头像选择]])
txt_title:setLayoutComponentEnabled(true)
txt_title:setName("txt_title")
txt_title:setTag(94)
txt_title:setCascadeColorEnabled(true)
txt_title:setCascadeOpacityEnabled(true)
txt_title:setPosition(800.0000, 846.7200)
layout = ccui.LayoutComponent:bindLayoutComponent(txt_title)
layout:setPositionPercentXEnabled(true)
layout:setPositionPercentYEnabled(true)
layout:setPositionPercentX(0.5000)
layout:setPositionPercentY(1.0584)
layout:setPercentWidth(0.1262)
layout:setPercentHeight(0.0763)
layout:setSize({width = 202.0000, height = 61.0000})
layout:setLeftMargin(699.0000)
layout:setRightMargin(699.0000)
layout:setTopMargin(-77.2200)
layout:setBottomMargin(816.2200)
img_bg:addChild(txt_title)

--Create panel_data
local panel_data = ccui.Layout:create()
panel_data:ignoreContentAdaptWithSize(false)
panel_data:setClippingEnabled(false)
panel_data:setBackGroundColorOpacity(102)
panel_data:setTouchEnabled(true);
panel_data:setLayoutComponentEnabled(true)
panel_data:setName("panel_data")
panel_data:setTag(43)
panel_data:setCascadeColorEnabled(true)
panel_data:setCascadeOpacityEnabled(true)
panel_data:setAnchorPoint(0.5000, 0.5000)
panel_data:setPosition(960.0000, 486.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(panel_data)
layout:setPositionPercentXEnabled(true)
layout:setPositionPercentYEnabled(true)
layout:setPositionPercentX(0.5000)
layout:setPositionPercentY(0.4500)
layout:setPercentWidth(0.8333)
layout:setPercentHeight(0.7407)
layout:setSize({width = 1600.0000, height = 800.0000})
layout:setLeftMargin(160.0000)
layout:setRightMargin(160.0000)
layout:setTopMargin(194.0000)
layout:setBottomMargin(86.0000)
hall_player_info_layer:addChild(panel_data)

--Create sv_head_portrait
local sv_head_portrait = ccui.ScrollView:create()
sv_head_portrait:setBounceEnabled(true)
sv_head_portrait:setDirection(2)
sv_head_portrait:setInnerContainerSize({width = 1400, height = 500})
sv_head_portrait:ignoreContentAdaptWithSize(false)
sv_head_portrait:setClippingEnabled(true)
sv_head_portrait:setBackGroundColorOpacity(102)
sv_head_portrait:setLayoutComponentEnabled(true)
sv_head_portrait:setName("sv_head_portrait")
sv_head_portrait:setTag(112)
sv_head_portrait:setCascadeColorEnabled(true)
sv_head_portrait:setCascadeOpacityEnabled(true)
sv_head_portrait:setPosition(104.0000, 233.2000)
layout = ccui.LayoutComponent:bindLayoutComponent(sv_head_portrait)
layout:setPositionPercentXEnabled(true)
layout:setPositionPercentYEnabled(true)
layout:setPositionPercentX(0.0650)
layout:setPositionPercentY(0.2915)
layout:setPercentWidth(0.8750)
layout:setPercentHeight(0.6250)
layout:setSize({width = 1400.0000, height = 500.0000})
layout:setLeftMargin(104.0000)
layout:setRightMargin(96.0000)
layout:setTopMargin(66.8000)
layout:setBottomMargin(233.2000)
panel_data:addChild(sv_head_portrait)

--Create img_ok
local img_ok = ccui.ImageView:create()
img_ok:ignoreContentAdaptWithSize(false)
img_ok:loadTexture("assets/common/btn_yellow1.png",0)
img_ok:setLayoutComponentEnabled(true)
img_ok:setName("img_ok")
img_ok:setTag(54)
img_ok:setCascadeColorEnabled(true)
img_ok:setCascadeOpacityEnabled(true)
img_ok:setPosition(1288.9600, 120.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_ok)
layout:setPositionPercentXEnabled(true)
layout:setPositionPercentYEnabled(true)
layout:setPositionPercentX(0.8056)
layout:setPositionPercentY(0.1500)
layout:setPercentWidth(0.1250)
layout:setPercentHeight(0.1000)
layout:setSize({width = 200.0000, height = 80.0000})
layout:setLeftMargin(1188.9600)
layout:setRightMargin(211.0400)
layout:setTopMargin(640.0000)
layout:setBottomMargin(80.0000)
panel_data:addChild(img_ok)

--Create txt_ok
local txt_ok = ccui.Text:create()
txt_ok:ignoreContentAdaptWithSize(true)
txt_ok:setTextAreaSize({width = 0, height = 0})
txt_ok:setFontName("assets/font/FZZhengHeiS-B-GB.ttf")
txt_ok:setFontSize(40)
txt_ok:setString([[确定]])
txt_ok:setLayoutComponentEnabled(true)
txt_ok:setName("txt_ok")
txt_ok:setTag(55)
txt_ok:setCascadeColorEnabled(true)
txt_ok:setCascadeOpacityEnabled(true)
txt_ok:setPosition(100.0000, 39.2000)
layout = ccui.LayoutComponent:bindLayoutComponent(txt_ok)
layout:setPositionPercentXEnabled(true)
layout:setPositionPercentYEnabled(true)
layout:setPositionPercentX(0.5000)
layout:setPositionPercentY(0.4900)
layout:setPercentWidth(0.4100)
layout:setPercentHeight(0.6125)
layout:setSize({width = 82.0000, height = 49.0000})
layout:setLeftMargin(59.0000)
layout:setRightMargin(59.0000)
layout:setTopMargin(16.3000)
layout:setBottomMargin(14.7000)
img_ok:addChild(txt_ok)

--Create img_cancel
local img_cancel = ccui.ImageView:create()
img_cancel:ignoreContentAdaptWithSize(false)
img_cancel:loadTexture("assets/common/btn_yellow1.png",0)
img_cancel:setLayoutComponentEnabled(true)
img_cancel:setName("img_cancel")
img_cancel:setTag(108)
img_cancel:setCascadeColorEnabled(true)
img_cancel:setCascadeOpacityEnabled(true)
img_cancel:setPosition(957.2800, 120.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_cancel)
layout:setPositionPercentXEnabled(true)
layout:setPositionPercentYEnabled(true)
layout:setPositionPercentX(0.5983)
layout:setPositionPercentY(0.1500)
layout:setPercentWidth(0.1250)
layout:setPercentHeight(0.1000)
layout:setSize({width = 200.0000, height = 80.0000})
layout:setLeftMargin(857.2800)
layout:setRightMargin(542.7200)
layout:setTopMargin(640.0000)
layout:setBottomMargin(80.0000)
panel_data:addChild(img_cancel)

--Create txt_cancel
local txt_cancel = ccui.Text:create()
txt_cancel:ignoreContentAdaptWithSize(true)
txt_cancel:setTextAreaSize({width = 0, height = 0})
txt_cancel:setFontName("assets/font/FZZhengHeiS-B-GB.ttf")
txt_cancel:setFontSize(40)
txt_cancel:setString([[取消]])
txt_cancel:setLayoutComponentEnabled(true)
txt_cancel:setName("txt_cancel")
txt_cancel:setTag(109)
txt_cancel:setCascadeColorEnabled(true)
txt_cancel:setCascadeOpacityEnabled(true)
txt_cancel:setPosition(100.0000, 39.2000)
layout = ccui.LayoutComponent:bindLayoutComponent(txt_cancel)
layout:setPositionPercentXEnabled(true)
layout:setPositionPercentYEnabled(true)
layout:setPositionPercentX(0.5000)
layout:setPositionPercentY(0.4900)
layout:setPercentWidth(0.4050)
layout:setPercentHeight(0.6125)
layout:setSize({width = 81.0000, height = 49.0000})
layout:setLeftMargin(59.5000)
layout:setRightMargin(59.5000)
layout:setTopMargin(16.3000)
layout:setBottomMargin(14.7000)
img_cancel:addChild(txt_cancel)

--Create img_select_from_phone
local img_select_from_phone = ccui.ImageView:create()
img_select_from_phone:ignoreContentAdaptWithSize(false)
img_select_from_phone:loadTexture("assets/common/btn_yellow1.png",0)
img_select_from_phone:setScale9Enabled(true)
img_select_from_phone:setCapInsets({x = 85, y = 33, width = 88, height = 34})
img_select_from_phone:setLayoutComponentEnabled(true)
img_select_from_phone:setName("img_select_from_phone")
img_select_from_phone:setTag(110)
img_select_from_phone:setCascadeColorEnabled(true)
img_select_from_phone:setCascadeOpacityEnabled(true)
img_select_from_phone:setPosition(430.5600, 120.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_select_from_phone)
layout:setPositionPercentXEnabled(true)
layout:setPositionPercentYEnabled(true)
layout:setPositionPercentX(0.2691)
layout:setPositionPercentY(0.1500)
layout:setPercentWidth(0.1875)
layout:setPercentHeight(0.1000)
layout:setSize({width = 300.0000, height = 80.0000})
layout:setLeftMargin(280.5600)
layout:setRightMargin(1019.4400)
layout:setTopMargin(640.0000)
layout:setBottomMargin(80.0000)
panel_data:addChild(img_select_from_phone)

--Create txt_select
local txt_select = ccui.Text:create()
txt_select:ignoreContentAdaptWithSize(true)
txt_select:setTextAreaSize({width = 0, height = 0})
txt_select:setFontName("assets/font/FZZhengHeiS-B-GB.ttf")
txt_select:setFontSize(40)
txt_select:setString([[从相册选择]])
txt_select:setLayoutComponentEnabled(true)
txt_select:setName("txt_select")
txt_select:setTag(111)
txt_select:setCascadeColorEnabled(true)
txt_select:setCascadeOpacityEnabled(true)
txt_select:setPosition(150.0000, 39.2000)
layout = ccui.LayoutComponent:bindLayoutComponent(txt_select)
layout:setPositionPercentXEnabled(true)
layout:setPositionPercentYEnabled(true)
layout:setPositionPercentX(0.5000)
layout:setPositionPercentY(0.4900)
layout:setPercentWidth(0.6733)
layout:setPercentHeight(0.6125)
layout:setSize({width = 202.0000, height = 49.0000})
layout:setLeftMargin(49.0000)
layout:setRightMargin(49.0000)
layout:setTopMargin(16.3000)
layout:setBottomMargin(14.7000)
img_select_from_phone:addChild(txt_select)

--Create Animation
result['animation'] = ccs.ActionTimeline:create()
  
result['animation']:setDuration(0)
result['animation']:setTimeSpeed(1.0000)
--Create Animation List

result['root'] = hall_player_info_layer
return result;
end

return Result

