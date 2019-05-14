#include "iostream"
#include <stdio.h>
#include "src/Binary.h"

#define EXPECT(expect, actual) \
do {\
    if (expect != actual)\
        fprintf(stderr, "%s:%d: ", __FILE__, __LINE__);\
}while(0)

void test1()
{
    auto writeBinary = CCPack::Binary::createWrite();
    writeBinary->writeChar('c');
    writeBinary->writeInt(12345);
    writeBinary->writeLong(5245678999);
    writeBinary->writeDouble(1.05);
    writeBinary->writeString8("test string 8");
    writeBinary->writeString("test auto length string ");
    int writeSize = 10;
    writeBinary->writeInt(writeSize);
    for (int i = 0; i < writeSize; ++i) {
        writeBinary->writeShort((short)i);
        writeBinary->writeString16("index = " + std::to_string(i));
    }
	writeBinary->writeValue<unsigned short>(50);
    writeBinary->finish();
    std::string writeStream = writeBinary->getStream();
    delete writeBinary;
    
    auto readBinary = CCPack::Binary::createRead(writeStream);
    int streamLength = readBinary->readInt();
	EXPECT(readBinary->readChar(), 'c');
	EXPECT(readBinary->readInt(), 12345);
	EXPECT(readBinary->readLong(), 5245678999);
	EXPECT(readBinary->readDouble(), 1.05);
	EXPECT(readBinary->readString8(), "test string 8");
	EXPECT(readBinary->readString(), "test auto length string ");
	int arrayLength = readBinary->readInt();
	EXPECT(arrayLength, 10);
	for (int i = 0; i < arrayLength; ++i) {
	EXPECT(readBinary->readShort(), i);
	EXPECT(readBinary->readString16(), "index = " + std::to_string(i));
	}
	EXPECT(readBinary->readValue<unsigned short>(), 50);
	delete readBinary;

	//char c = readBinary->readChar();
	//int i = readBinary->readInt();
	//long long l = readBinary->readLong();
	//double d = readBinary->readDouble();
	//std::string s8 = readBinary->readString8();
	//std::string s = readBinary->readString();
	//// array
	//int readSize = readBinary->readInt();
	//for (int i = 0; i < readSize; ++i) {
	//	short s = readBinary->readShort();
	//	std::string s16 = readBinary->readString16();
	//}
	//// if not exist in interface, can use template.
	//unsigned short us = readBinary->readValue<unsigned short>();
	//delete readBinary
}

void test2()
{
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
	EXPECT(readBinary.readChar(), 'c');
	EXPECT(readBinary.readInt(), 12345);
	EXPECT(readBinary.readLong(), 5245678999);
	EXPECT(readBinary.readDouble(), 1.05);
	EXPECT(readBinary.readString8(), "test string 8");
	EXPECT(readBinary.readString(), "test auto length string ");
	/*char c = readBinary.readChar();
	int i = readBinary.readInt();
	long long l = readBinary.readLong();
	double d = readBinary.readDouble();
	std::string s8 = readBinary.readString8();
	std::string s = readBinary.readString();*/
}

int main()
{
    test1();
	test2();
    return 1;
}
