# CCPack
is a C++ light weight serialization library within simple,clear naming and code style.

<p align="left">
    <a href="">
        <img src="https://img.shields.io/badge/OS-android%20iOS%20windows-yellow.svg">
    </a>
    <a href="https://isocpp.org/">
        <img src="https://img.shields.io/badge/language-C%2B%2B11-blue.svg">
    </a>
    <a href="https://travis-ci.org/felixguendling/cista">
        <img src="https://travis-ci.org/felixguendling/cista.svg?branch=master">
    </a>
    <a href="https://coveralls.io/github/felixguendling/cista?branch=master">
        <img src="https://coveralls.io/repos/github/felixguendling/cista/badge.svg?branch=master">
    </a>
    <a href="https://opensource.org/licenses/MIT" >
        <img src="https://img.shields.io/apm/l/vim-mode.svg">
    </a>
</p>

# Using in c++
## explanation
Serialization is the process of turning an object in memory into a stream of bytes so you can do stuff like store it on disk or send it over the network.Deserialization is the reverse process: turning a stream of bytes into an object in memory.
CCPack is used to serialization and deserialization. The corresponding operation(function) is read and write.

## 1.on heap
```
    auto writeBinary = CCPack::Binary::createWrite();
    writeBinary->writeChar('c');
    writeBinary->writeInt(12345);
    writeBinary->writeLong(5245678999);
    writeBinary->writeDouble(1.05);
    writeBinary->writeString8("test string 8");
    writeBinary->writeString("test auto length string ");
    int writeSize = 10;
    // array
    writeBinary->writeInt(writeSize);
    for (int i = 0; i < writeSize; ++i) 
    {
        writeBinary->writeShort((short)i);
        writeBinary->writeString16("index = " + std::to_string(i));
    }
    writeBinary->writeValue<unsigned short>(50);
    writeBinary->finish();
    std::string writeStream = writeBinary->getStream();
    delete writeBinary;
    
    auto readBinary = CCPack::Binary::createRead(writeStream);
    int streamLength = readBinary->readInt();
    char c = readBinary->readChar();
    int i = readBinary->readInt();
    long long l = readBinary->readLong();
    double d = readBinary->readDouble();
    std::string s8 = readBinary->readString8();
    std::string s = readBinary->readString();
    // array
    int readSize = readBinary->readInt();
    for (int i = 0; i < readSize; ++i) 
    {
      short s = readBinary->readShort();
      std::string s16 = readBinary->readString16();
    }
    // if not exist in interface, can use template.
    unsigned short us = readBinary->readValue<unsigned short>();
    delete readBinary;
```
## 2.on stack
```
    CCPack::Binary writeBinary;
    writeBinary.initWrite();
    writeBinary.writeChar('c');
    writeBinary.writeInt(12345);
    writeBinary.writeLong(5245678999);
    writeBinary.writeDouble(1.05);
    writeBinary.writeString8("test string 8");
    writeBinary.writeString("test auto length string ");
    writeBinary.finish();

    CCPack::Binary readBinary;
    readBinary.initRead(writeBinary.getStream());
    int streamLength = readBinary.readInt();
    char c = readBinary.readChar();
    int i = readBinary.readInt();
    long long l = readBinary.readLong();
    double d = readBinary.readDouble();
    std::string s8 = readBinary.readString8();
    std::string s = readBinary.readString();
```

# Compile using cocos2d-x
## windows and iOS
Copy Binary.cpp, Binary.h, lua_pack_binary_auto.cpp, lua_pack_binary_auto.hpp 
compile
## android
    Copy Binary.cpp, Binary.h to cocos2d-x/external/pack
    if lua framework, copy lua_pack_binary_auto.cpp, lua_pack_binary_auto.hpp to anywhere and register 
    ```register_all_Binary(L);```
    Modify cocos2d-x/cocos/Android.mk
    Add
    
    ```
    // only this one line
    ...
    ../external/pack/Binary.cpp \
    ...
    
    LOCAL_EXPORT_C_INCLUDES := ...
    ...
    
    ...
    LOCAL_C_INCLUDES := ...
    ...
    
    
    ```

# cocos2d-x lua
  be exported for cocos2d-x lua using and parse binary stream.
  the folder is cocos_lua
  the test case is test. A example of client.
  ## 1.Write
  ```
    local binary = cc.Binary:createWrite()
    binary:writeInt(1517440670)
    binary:writeString("weijiali")
    binary:writeString("111111")
    binary:writeString("2.5.0.0")
    binary:writeString("12345")
    binary:finish()
    local buffer = binary:getStream()
    ...
  ```
  ## 2.Read
  ```
    local binary = cc.Binary:createRead(buffer)
    local bufferLength = binary:readInt()
    local i = binary:readInt()
    local name = binary:readString()
    local pwd = binary:readString()
    local version = binary:readString()
    local key = binary:readString()
  ```
