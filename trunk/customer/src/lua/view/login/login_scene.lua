--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   login_scene.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: login scene.
@ others:
@ history:
1.date:
author:
modification:
--]]

local LoginScene = class("LoginScene", require "view.base.layer_base")

function LoginScene:ctor(view_file)
    self.super.ctor(self, view_file)
    local btn_login = self.root_node_:getChildByName("btn_login")
    btn_login:addClickEventListener(handler(self, self.onBtnLoginTouch))
end

function LoginScene:onBtnLoginTouch(sender)
    print("[LoginScene:onBtnLoginTouch]")

    local connected = gamer.NetworkManager:getInstance():is_connected()
    print("[LoginScene:onBtnLoginTouch] connected : ", tostring(connected))

	math.randomseed(tostring(os.time()):reverse():sub(1, 7))
	local account = math.random(1, 1000)
	print("[LoginScene:onBtnLoginTouch] account : ", account)

    local proto = gamer.protocol.MyLoginMsgProtocol()
    proto:set_account(tostring(account))
    proto:set_password("2030")

    gamer.MsgManager:getInstance():sendMsg(gamer.MsgTypes.C2S_MSG_TYPE_LOGIN, 
        gamer.MsgIDs.MSG_ID_LOGIN_MY, 
        proto)

	--gamer.wx_mgr_:shareImage(0, "Icon-100.png")
	--[[
	local listview = ccui.ListView:create()
	listview:setContentSize(450, 800)
	listview:setInnerContainerSize(cc.size(400, 800))
	listview:setAnchorPoint(0.5, 0.5)
	listview:setBounceEnabled(true)
	listview:setTouchEnabled(true)
	listview:setPosition(display.center)
	self:addChild(listview)
	

	for i = 1, 3 do
		local layout = ccui.Layout:create()
		layout:setContentSize(400, 113)
		listview:pushBackCustomItem(layout)

		local btn = ccui.Button:create("assets/common/btn_common_purple.png", "", "", 0)
		btn:setAnchorPoint(0.5, 0.5)
		btn:setPosition(200, 57)
		--local img_bg = ccui.ImageView:create()
		--img_bg:loadTexture("assets/common/btn_common_purple.png",0)
		layout:addChild(btn) 
	end

	listview:addEventListener(function(sender, eventType)
		print("listview, item click, eventType : ", eventType)
		if 0 == eventType then -- touch begin(hallen when scroll and touch)
		elseif 1 == eventType then -- touch end(happen only touch)
		end
	end)
	]]
end

function LoginScene:dealWithMyLoginMsgReceived(code, msg)
	gamer.scene_msg_.runScene(gamer.SceneConstants.SceneIDs.HALL_SCENE)
end

function LoginScene:addMsgListeners()
	gamer.msg_mgr_:addMsgListener(gamer.MsgTypes.S2C_MSG_TYPE_LOGIN, handler(self, self.onServerMsgReceived))
end

function LoginScene:removeMsgListeners()
	gamer.msg_mgr_:removeMsgListener(gamer.MsgTypes.S2C_MSG_TYPE_LOGIN, handler(self, self.onServerMsgReceived))
end

function LoginScene:onServerMsgReceived(code, msg_type, msg_id, msg)
    print("[LoginScene:onServerMsgReceived] code, msg_type, msg_id : ", code, msg_type, msg_id)
	if code ~= gamer.MsgCodes.SUCCEED then
		print("[LoginScene:onServerMsgReceived] error")
	end

	if msg_type == gamer.MsgTypes.S2C_MSG_TYPE_LOGIN then
		if msg_id == gamer.MsgIDs.MSG_ID_LOGIN_MY then
			self:dealWithMyLoginMsgReceived(code, msg)
		end
	end
end

function LoginScene:onEnter()
	-- TODO : dispatch layer enter event to all listeners
    print("[LoginScene:onEnter]")
    self:addMsgListeners()
end

function LoginScene:onExit()
	-- TODO : dispatch layer exit event to all listeners
    print("[LoginScene:onExit]")
	self:removeMsgListeners()
end

return LoginScene
