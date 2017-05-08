
local LoginLayer = class("LoginLayer", require "view.base.layer_base")

function LoginLayer:ctor()
    -- add background image
    display.newSprite("HelloWorld.png")
        :move(display.center)
        :addTo(self)

    -- add HelloWorld label
--    cc.Label:createWithSystemFont("Hello World", "Arial", 40)
--        :move(display.cx, display.cy + 200)
--        :addTo(self)

end

return LoginLayer
