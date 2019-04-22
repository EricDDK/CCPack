#ifndef __CCBINARY_H__
#define __CCBINARY_H__

#include "cocos2d.h"

NS_CC_BEGIN

class CC_DLL CCBinary
{
public:
	static CCBinary* createRead(std::string stream);
	static CCBinary* createWrite();

	CCBinary();
	~CCBinary();

	bool initRead(std::string stream);
	bool initWrite();

	const void setEndian(const bool isBigEndian);
	const bool isBigEndian() const;

	unsigned char readByte();
	bool readBool();
	char readChar();
	short readShort();
	int readInt();
	long long readLong();
	float readFloat();
	double readDouble();
	char* readString();

	void writeByte(unsigned char b);
	void writeBool(bool b);
	void writeChar(char c);
	void writeShort(short s);
	void writeInt(int i);
	void writeLong(long long l);
	void writeFloat(float f);
	void writeDouble(double d);
	void writeString(std::string s);

private:
	std::string _receiveStream;
	std::string _sendStream;
	int _pos;
	int _size;
	bool _isBigEndian = true;
};

NS_CC_END

#endif