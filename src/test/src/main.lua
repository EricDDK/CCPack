
cc.FileUtils:getInstance():setPopupNotify(false)


-- debug module
local breakSocketHandle,debugXpCall
-- only windows platform will start the process of debug module.
if cc.Application:getInstance():getTargetPlatform() == 0 then
    breakSocketHandle,debugXpCall = require("LuaDebugjit")("localhost",7003)
    cc.Director:getInstance():getScheduler():scheduleScriptFunc(breakSocketHandle, 0.3, false)
end

require "config"
require "cocos.init"

local function main()
    require("app.MyApp"):create():run()
end

local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
    print(msg)
end
