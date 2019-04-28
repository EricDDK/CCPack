
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()
    -- add background image
    display.newSprite("HelloWorld.png")
        :move(display.center)
        :addTo(self)

    -- add HelloWorld label
    cc.Label:createWithSystemFont("Hello World", "Arial", 40)
        :move(display.cx, display.cy + 200)
        :addTo(self)

    require("network.NetMgr")
    -- 尝试连接 127.0.0.1:19810
    cc.NetMgr:getInstance():connect("61.172.243.196", "19810")
    --cc.NetMgr:getInstance():connect("127.0.0.1", "19810")
end

return MainScene
