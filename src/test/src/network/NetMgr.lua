
local NetMgr = class("NetMgr")

local socket = require("luasocket.socket")
local scheduler = cc.Director:getInstance():getScheduler()

local CHECK_SELECT_INTERVAL = 0.05  -- 定时器检测间隔时间

--[[
    构造函数  
]]
function NetMgr:ctor()
    self._isConnected = false  -- 标识符是否已经连接
    self._sendTaskQueue = {}  -- 发送消息队列
end

--[[
    单利模式  
    @return: NetMgr实例
]]
function NetMgr:getInstance()
    if not self.instance_ then
        self.instance_ = NetMgr:new()
    end
    return self.instance_
end

--[[
    外部调用入口，发起长连接请求  
    @param: ip    ip地址
    @param: port  端口号
]]
function NetMgr:connect(ip, port)
    print("[NetMgr:connect] ip, port = ", ip, port)
    self._ip = ip
    self._port = port
    self._socket = socket.tcp()  -- socket 对象
    self._socket:settimeout(0) -- 非阻塞
    self._socket:setoption("tcp-nodelay", true) -- 去掉优化
    self._socket:connect(self._ip, self._port) -- 链接

    -- 定时器回调函数，每CHECK_SELECT_INTERVAL秒执行一次，直到连接发现断开
    local function checkConnect(dt)
        print("[NetMgr:connect] => checkConnect")
        if self:isConnected() then
            self._isConnected = true
            scheduler:unscheduleScriptEntry(self._schedulerID)
            self._processID = scheduler:scheduleScriptFunc(
                function(...)
                    -- 这里是尝试读取socket
                    self:disposeTCPIO()
                end,
                CHECK_SELECT_INTERVAL,
                false
            )
        end
    end
    self._schedulerID = scheduler:scheduleScriptFunc(checkConnect, CHECK_SELECT_INTERVAL, false)
end

--[[
    停止发送接受socket
    @param: 
    @return: 
]]
function NetMgr:stop()
    scheduler:unscheduleScriptEntry(self._processID)
end

--[[
    判断是否连接着  
    @param: 
    @return: 
]]
function NetMgr:isConnected()
    local forWrite = {}
    table.insert(forWrite, self._socket)
    local readyForWrite
    _, readyForWrite, _ = socket.select(nil, forWrite, 0)
    if #readyForWrite > 0 then
        return true
    end
    return false
end

--[[
    处理socket  
    @param: 
    @return: 
]]
function NetMgr:disposeTCPIO()
    if not self._isConnected then
        return
    end
    self:disposeReceiveTask()
    self:disposeSendTask()
end

--[[
    处理接受任务  
    @param: 
    @return: 
]]
function NetMgr:disposeReceiveTask()
    --检测是否有可读的socket
    local recvt, sendt, status = socket.select({self._socket}, nil, 0)
    print("[NetMgr:disposeReceiveTask] = ", #recvt, sendt, status)
    if #recvt <= 0 then
        return
    end
    -- 根据我们的服务器定义，包头2字节，是包的长度，为了处理粘包拆包等问题
    local buffer = self._socket:receive(2)
    -- 如果有2个字节的包头，那么说明有socket需要读取
    if buffer then
        -- 分别读取第一个，和第二个字节，从左往右的读取
        local first, sencond = string.byte(buffer, 1, 2)
        -- 这里因为服务端是是小端字节序，所以是first + second * 256
        -- 如果服务端是大端字节序，就是first * 256 + second
        local len = first + sencond * 256 
        -- 获取到整个包的内容，与头部拼接
        buffer = buffer .. self._socket:receive(len + 2)

        local binary = cc.Binary:createRead(buffer)
        local head = binary:readInt()
        local protocolID = binary:readInt()
        if protocolID == -847330270 then
            local cryKey = binary:readString()
            local version = binary:readString()
            local rs = 0
            self:send(protocolID, {key = cryKey})
        end

        -- -- 获取 protocolID ，第三个字节开始到第六个字节我们定义的是协议号，这些都可以随意修改
        -- -- 解释下为什么是 <Ii 因为是小端字节序，所以是 < .... 包头2字节所以是I .... 协议号是4字节所以是i
        -- local len, head, protocolID = string.unpack(buffer, "<Ii")
        -- -- 这里举例一下如何处理这样的一个结构体 => 
        -- if true then
        --     -- event是要接受的结构体构造
        --     local event = {
        --         name = "test_111",
        --         password = "csd131edfs",
        --         version = 25,
        --         key = "12dsacdss",
        --     }
        --     local len, head, protocolID, name, password, key, version = string.unpack(buffer, "<Iippip")
        --     print("content = ", name, password, key, version)
        -- end
    end
end

--[[
    处理发送任务  
    @param: 
    @return: 
]]
function NetMgr:disposeSendTask()
    -- 要发送的任务都存放在 _sendTaskQueue 队列中等待处理
    if self._sendTaskQueue and #self._sendTaskQueue > 0 then
        local data = self._sendTaskQueue[#self._sendTaskQueue]
        if data then
            local _len, _error = self._socket:send(data)
            --发送长度不为空，并且发送长度==数据长度
            if _len ~= nil and _len == #data then
                -- 出队列,删除包
                table.remove(self._sendTaskQueue, #self._sendTaskQueue)
            else

            end
        end
    end
end

--[[
    发送消息  
    @param: protocolID 协议号
    @param: event 要发送的lua对象
]]
function NetMgr:send(protocolID, event)
    local data
    if protocolID == -847330270 then
        local binary = cc.Binary:createWrite()
        binary:writeInt(1517440670)
        binary:writeString("weijiali")
        binary:writeString("111111")
        binary:writeString("2.5.0.0")
        binary:writeString(event.key)
        binary:finish()
        local data = binary:getStream()
        table.insert(self._sendTaskQueue, 1, data)

        -- local buffer = cc.Binary:createRead(data)
        -- local len = buffer:readShort()
        -- local head = buffer:readInt()
        -- local name = buffer:readString()
        -- local pwd = buffer:readString()
        -- local version = buffer:readString()
        -- local key = buffer:readString()
        -- local a = 1

        -- -- event 是要发送的lua对象
        -- -- local event = {
        -- --     score = 1000,
        -- -- }
        -- -- 4 + 4 中， 第一个4是协议号，第二个4是event.score
        -- local len = 4 + 4
        -- -- data 是包的二进制
        -- data = string.pack("<Iii", len, protocolID, event.score)
        -- table.insert(self._sendTaskQueue, 1, data)
    elseif protocolID == 22222222 then

        -- event 是要发送的lua对象
        -- local event = {
        --     name = "test_111",
        --     password = "csd131edfs",
        --     version = 25,
        --     key = "12dsacdss",
        -- }

        -- 4:协议号大小  加上3个字符串的长度 加上1个int的长度是4
        -- 最后加3是因为字符串的发送流，小于2^8的字符串，首字节是表示长度的，如果是2^16的字符串，字符串前2字节是表示的长度
        local len = 4 + string.len(event.name) + string.len(event.password) + 4 + string.len(event.key) + 3
        data = string.pack("<Iippip", len, protocolID, event.name, event.password, event.version, event.key)
    end
    -- 如果data存在就存入发送任务队列
    if data then
        table.insert(self._sendTaskQueue, 1, data)
    end
end

cc.NetMgr = NetMgr
return NetMgr
