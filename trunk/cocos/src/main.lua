
cc.FileUtils:getInstance():setPopupNotify(false)

require "config"
require "cocos.init"
require "logic.init_modules"

local function main()
    --require("app.MyApp"):create():run()
    gamer.initEngine()
    gamer.initModules()
    gamer.SceneManager.runScene(gamer.SceneConstants.SceneIDs.LOGIN_SCENE)
end

local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
    print(msg)
end
