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

--Create room_scene
local room_scene=cc.Node:create()
room_scene:setName("room_scene")

--Create img_room_bg
local img_room_bg = ccui.ImageView:create()
img_room_bg:ignoreContentAdaptWithSize(false)
img_room_bg:loadTexture("assets/room/normal_room_bg.jpg",0)
img_room_bg:setLayoutComponentEnabled(true)
img_room_bg:setName("img_room_bg")
img_room_bg:setTag(26)
img_room_bg:setCascadeColorEnabled(true)
img_room_bg:setCascadeOpacityEnabled(true)
img_room_bg:setPosition(960.0000, 540.0320)
layout = ccui.LayoutComponent:bindLayoutComponent(img_room_bg)
layout:setPositionPercentX(1.0000)
layout:setPositionPercentY(0.8438)
layout:setPercentWidth(2.0000)
layout:setPercentHeight(1.6875)
layout:setSize({width = 1920.0000, height = 1080.0000})
layout:setHorizontalEdge(3)
layout:setVerticalEdge(3)
layout:setRightMargin(-960.0000)
layout:setTopMargin(-440.0320)
layout:setBottomMargin(0.0320)
room_scene:addChild(img_room_bg)

--Create img_direction_bg
local img_direction_bg = ccui.ImageView:create()
img_direction_bg:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/table.plist")
img_direction_bg:loadTexture("room_direction_bg.png",1)
img_direction_bg:setLayoutComponentEnabled(true)
img_direction_bg:setName("img_direction_bg")
img_direction_bg:setTag(44)
img_direction_bg:setCascadeColorEnabled(true)
img_direction_bg:setCascadeOpacityEnabled(true)
img_direction_bg:setPosition(960.0000, 640.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_direction_bg)
layout:setPositionPercentX(1.0000)
layout:setPositionPercentY(1.0000)
layout:setPercentWidth(0.3740)
layout:setPercentHeight(0.3406)
layout:setSize({width = 359.0000, height = 218.0000})
layout:setLeftMargin(780.5000)
layout:setRightMargin(-179.5000)
layout:setTopMargin(-109.0000)
layout:setBottomMargin(531.0000)
room_scene:addChild(img_direction_bg)

--Create img_direction_cur1
local img_direction_cur1 = ccui.ImageView:create()
img_direction_cur1:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/table.plist")
img_direction_cur1:loadTexture("i_room_direction_player_self.png",1)
img_direction_cur1:setLayoutComponentEnabled(true)
img_direction_cur1:setName("img_direction_cur1")
img_direction_cur1:setTag(49)
img_direction_cur1:setCascadeColorEnabled(true)
img_direction_cur1:setCascadeOpacityEnabled(true)
img_direction_cur1:setVisible(false)
img_direction_cur1:setPosition(953.2761, 577.5009)
layout = ccui.LayoutComponent:bindLayoutComponent(img_direction_cur1)
layout:setPositionPercentX(0.9930)
layout:setPositionPercentY(0.9023)
layout:setPercentWidth(0.3469)
layout:setPercentHeight(0.1234)
layout:setSize({width = 333.0000, height = 79.0000})
layout:setLeftMargin(786.7761)
layout:setRightMargin(-159.7761)
layout:setTopMargin(22.9991)
layout:setBottomMargin(538.0009)
room_scene:addChild(img_direction_cur1)

--Create img_direction_cur2
local img_direction_cur2 = ccui.ImageView:create()
img_direction_cur2:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/table.plist")
img_direction_cur2:loadTexture("i_room_direction_player_right.png",1)
img_direction_cur2:setLayoutComponentEnabled(true)
img_direction_cur2:setName("img_direction_cur2")
img_direction_cur2:setTag(52)
img_direction_cur2:setCascadeColorEnabled(true)
img_direction_cur2:setCascadeOpacityEnabled(true)
img_direction_cur2:setVisible(false)
img_direction_cur2:setPosition(1093.0920, 651.1701)
layout = ccui.LayoutComponent:bindLayoutComponent(img_direction_cur2)
layout:setPositionPercentX(1.1386)
layout:setPositionPercentY(1.0175)
layout:setPercentWidth(0.0885)
layout:setPercentHeight(0.2766)
layout:setSize({width = 85.0000, height = 177.0000})
layout:setLeftMargin(1050.5920)
layout:setRightMargin(-175.5919)
layout:setTopMargin(-99.6701)
layout:setBottomMargin(562.6701)
room_scene:addChild(img_direction_cur2)

--Create img_direction_cur3
local img_direction_cur3 = ccui.ImageView:create()
img_direction_cur3:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/table.plist")
img_direction_cur3:loadTexture("i_room_direction_player_opposite.png",1)
img_direction_cur3:setLayoutComponentEnabled(true)
img_direction_cur3:setName("img_direction_cur3")
img_direction_cur3:setTag(51)
img_direction_cur3:setCascadeColorEnabled(true)
img_direction_cur3:setCascadeOpacityEnabled(true)
img_direction_cur3:setVisible(false)
img_direction_cur3:setPosition(960.4816, 726.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_direction_cur3)
layout:setPositionPercentX(1.0005)
layout:setPositionPercentY(1.1344)
layout:setPercentWidth(0.2521)
layout:setPercentHeight(0.0672)
layout:setSize({width = 242.0000, height = 43.0000})
layout:setLeftMargin(839.4816)
layout:setRightMargin(-121.4817)
layout:setTopMargin(-107.5000)
layout:setBottomMargin(704.5000)
room_scene:addChild(img_direction_cur3)

--Create img_direction_cur4
local img_direction_cur4 = ccui.ImageView:create()
img_direction_cur4:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/table.plist")
img_direction_cur4:loadTexture("i_room_direction_player_left.png",1)
img_direction_cur4:setLayoutComponentEnabled(true)
img_direction_cur4:setName("img_direction_cur4")
img_direction_cur4:setTag(50)
img_direction_cur4:setCascadeColorEnabled(true)
img_direction_cur4:setCascadeOpacityEnabled(true)
img_direction_cur4:setVisible(false)
img_direction_cur4:setPosition(826.4623, 649.8885)
layout = ccui.LayoutComponent:bindLayoutComponent(img_direction_cur4)
layout:setPositionPercentX(0.8609)
layout:setPositionPercentY(1.0155)
layout:setPercentWidth(0.0885)
layout:setPercentHeight(0.2766)
layout:setSize({width = 85.0000, height = 177.0000})
layout:setLeftMargin(783.9623)
layout:setRightMargin(91.0377)
layout:setTopMargin(-98.3885)
layout:setBottomMargin(561.3885)
room_scene:addChild(img_direction_cur4)

--Create img_direction_1
local img_direction_1 = ccui.ImageView:create()
img_direction_1:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/table.plist")
img_direction_1:loadTexture("i_room_direction_east.png",1)
img_direction_1:setLayoutComponentEnabled(true)
img_direction_1:setName("img_direction_1")
img_direction_1:setTag(45)
img_direction_1:setCascadeColorEnabled(true)
img_direction_1:setCascadeOpacityEnabled(true)
img_direction_1:setPosition(960.0000, 592.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_direction_1)
layout:setPositionPercentX(1.0000)
layout:setPositionPercentY(0.9250)
layout:setPercentWidth(0.0594)
layout:setPercentHeight(0.0906)
layout:setSize({width = 57.0000, height = 58.0000})
layout:setLeftMargin(931.5000)
layout:setRightMargin(-28.5000)
layout:setTopMargin(19.0000)
layout:setBottomMargin(563.0000)
room_scene:addChild(img_direction_1)

--Create img_direction_2
local img_direction_2 = ccui.ImageView:create()
img_direction_2:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/table.plist")
img_direction_2:loadTexture("i_room_direction_south.png",1)
img_direction_2:setLayoutComponentEnabled(true)
img_direction_2:setName("img_direction_2")
img_direction_2:setTag(46)
img_direction_2:setCascadeColorEnabled(true)
img_direction_2:setCascadeOpacityEnabled(true)
img_direction_2:setPosition(847.4874, 655.0000)
img_direction_2:setRotationSkewX(90.0000)
img_direction_2:setRotationSkewY(90.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_direction_2)
layout:setPositionPercentX(0.8828)
layout:setPositionPercentY(1.0234)
layout:setPercentWidth(0.0594)
layout:setPercentHeight(0.0906)
layout:setSize({width = 57.0000, height = 58.0000})
layout:setLeftMargin(818.9874)
layout:setRightMargin(84.0126)
layout:setTopMargin(-44.0000)
layout:setBottomMargin(626.0000)
room_scene:addChild(img_direction_2)

--Create img_direction_3
local img_direction_3 = ccui.ImageView:create()
img_direction_3:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/table.plist")
img_direction_3:loadTexture("i_room_direction_west.png",1)
img_direction_3:setLayoutComponentEnabled(true)
img_direction_3:setName("img_direction_3")
img_direction_3:setTag(47)
img_direction_3:setCascadeColorEnabled(true)
img_direction_3:setCascadeOpacityEnabled(true)
img_direction_3:setPosition(960.0000, 717.2043)
img_direction_3:setRotationSkewX(180.0000)
img_direction_3:setRotationSkewY(180.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_direction_3)
layout:setPositionPercentX(1.0000)
layout:setPositionPercentY(1.1206)
layout:setPercentWidth(0.0615)
layout:setPercentHeight(0.0750)
layout:setSize({width = 59.0000, height = 48.0000})
layout:setLeftMargin(930.5000)
layout:setRightMargin(-29.5000)
layout:setTopMargin(-101.2043)
layout:setBottomMargin(693.2043)
room_scene:addChild(img_direction_3)

--Create img_direction_4
local img_direction_4 = ccui.ImageView:create()
img_direction_4:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/table.plist")
img_direction_4:loadTexture("i_room_direction_north.png",1)
img_direction_4:setLayoutComponentEnabled(true)
img_direction_4:setName("img_direction_4")
img_direction_4:setTag(48)
img_direction_4:setCascadeColorEnabled(true)
img_direction_4:setCascadeOpacityEnabled(true)
img_direction_4:setPosition(1080.0000, 655.0000)
img_direction_4:setRotationSkewX(-90.0000)
img_direction_4:setRotationSkewY(-90.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(img_direction_4)
layout:setPositionPercentX(1.1250)
layout:setPositionPercentY(1.0234)
layout:setPercentWidth(0.0635)
layout:setPercentHeight(0.0781)
layout:setSize({width = 61.0000, height = 50.0000})
layout:setLeftMargin(1049.5000)
layout:setRightMargin(-150.5000)
layout:setTopMargin(-40.0000)
layout:setBottomMargin(630.0000)
room_scene:addChild(img_direction_4)

--Create node_play_card_timer
local node_play_card_timer=cc.Node:create()
node_play_card_timer:setName("node_play_card_timer")
node_play_card_timer:setTag(61)
node_play_card_timer:setCascadeColorEnabled(true)
node_play_card_timer:setCascadeOpacityEnabled(true)
node_play_card_timer:setPosition(960.0000, 660.0000)
layout = ccui.LayoutComponent:bindLayoutComponent(node_play_card_timer)
layout:setPositionPercentX(1.0000)
layout:setPositionPercentY(1.0313)
layout:setLeftMargin(960.0000)
layout:setTopMargin(-20.0000)
layout:setBottomMargin(660.0000)
room_scene:addChild(node_play_card_timer)

--Create img_remain_cards
local img_remain_cards = ccui.ImageView:create()
img_remain_cards:ignoreContentAdaptWithSize(false)
cc.SpriteFrameCache:getInstance():addSpriteFrames("assets/room/plist/table.plist")
img_remain_cards:loadTexture("i_remain_card_bg.png",1)
img_remain_cards:setLayoutComponentEnabled(true)
img_remain_cards:setName("img_remain_cards")
img_remain_cards:setTag(130)
img_remain_cards:setCascadeColorEnabled(true)
img_remain_cards:setCascadeOpacityEnabled(true)
img_remain_cards:setPosition(147.2226, 924.1318)
layout = ccui.LayoutComponent:bindLayoutComponent(img_remain_cards)
layout:setPositionPercentX(0.1534)
layout:setPositionPercentY(1.4440)
layout:setPercentWidth(0.2510)
layout:setPercentHeight(0.1531)
layout:setSize({width = 241.0000, height = 98.0000})
layout:setLeftMargin(26.7226)
layout:setRightMargin(692.2774)
layout:setTopMargin(-333.1318)
layout:setBottomMargin(875.1318)
room_scene:addChild(img_remain_cards)

--Create txt_remain_cards
local txt_remain_cards = ccui.Text:create()
txt_remain_cards:ignoreContentAdaptWithSize(true)
txt_remain_cards:setTextAreaSize({width = 0, height = 0})
txt_remain_cards:setFontName("assets/font/FZZhengHeiS-B-GB.ttf")
txt_remain_cards:setFontSize(35)
txt_remain_cards:setString([[96]])
txt_remain_cards:setLayoutComponentEnabled(true)
txt_remain_cards:setName("txt_remain_cards")
txt_remain_cards:setTag(131)
txt_remain_cards:setCascadeColorEnabled(true)
txt_remain_cards:setCascadeOpacityEnabled(true)
txt_remain_cards:setPosition(185.0000, 57.0000)
txt_remain_cards:setTextColor({r = 0, g = 255, b = 0})
layout = ccui.LayoutComponent:bindLayoutComponent(txt_remain_cards)
layout:setPositionPercentX(0.7676)
layout:setPositionPercentY(0.5816)
layout:setPercentWidth(0.2158)
layout:setPercentHeight(0.4388)
layout:setSize({width = 52.0000, height = 43.0000})
layout:setLeftMargin(159.0000)
layout:setRightMargin(30.0000)
layout:setTopMargin(19.5000)
layout:setBottomMargin(35.5000)
img_remain_cards:addChild(txt_remain_cards)

--Create img_chat
local img_chat = ccui.ImageView:create()
img_chat:ignoreContentAdaptWithSize(false)
img_chat:loadTexture("assets/common/i_chat.png",0)
img_chat:setLayoutComponentEnabled(true)
img_chat:setName("img_chat")
img_chat:setTag(123)
img_chat:setCascadeColorEnabled(true)
img_chat:setCascadeOpacityEnabled(true)
img_chat:setPosition(1835.9800, 110.5100)
layout = ccui.LayoutComponent:bindLayoutComponent(img_chat)
layout:setPositionPercentX(1.9125)
layout:setPositionPercentY(0.1727)
layout:setPercentWidth(0.0938)
layout:setPercentHeight(0.1406)
layout:setSize({width = 90.0000, height = 90.0000})
layout:setLeftMargin(1790.9800)
layout:setRightMargin(-920.9800)
layout:setTopMargin(484.4900)
layout:setBottomMargin(65.5100)
room_scene:addChild(img_chat)

--Create Animation
result['animation'] = ccs.ActionTimeline:create()
  
result['animation']:setDuration(0)
result['animation']:setTimeSpeed(1.0000)
--Create Animation List

result['root'] = room_scene
return result;
end

return Result

