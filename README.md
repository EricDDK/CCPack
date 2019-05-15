# CCPack
is a C++ light weight serialization library within simple,clear naming and code style.

# Using in c++

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
  
 
