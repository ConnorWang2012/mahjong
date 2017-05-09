
cc.FileUtils:getInstance():setPopupNotify(false)

require "config"
require "cocos.init"
require "logic.init_modules"

local function main()
    --require("app.MyApp"):create():run()
--    local scene = require("view.login.login_scene.lua"):create()
--    local director = cc.Director:getInstance()
--    if director:getRunningScene() then
--        director:replaceScene(scene)
--    else
--        director:runWithScene(scene)
--    end

    gamer.initEngine()
    gamer.initModules()
    gamer.SceneManager.runScene(gamer.SceneConstants.SceneIDs.LOGIN_SCENE)

end

local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
    print(msg)
end
