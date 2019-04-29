#ifndef __CCBINARY_H__
#define __CCBINARY_H__

#include "cocos2d.h"

NS_CC_BEGIN

class Binary : public cocos2d::Ref
{
public:
	static Binary* createRead(std::string stream);
	static Binary* createWrite();

	Binary();
	virtual ~Binary();

	bool initRead(std::string stream);
	bool initWrite();

	const void setEndian(const bool isBigEndian);
	const bool isBigEndian() const;

	const std::string getStream() const { return _stream; }

	unsigned char readByte();
	bool readBool();
	char readChar();
	short readShort();
	int readInt();
	long long readLong();
	float readFloat();
	double readDouble();
	std::string readString();
	std::string readString8();
	std::string readString16();
	std::string readString32();

	void writeByte(unsigned char b);
	void writeBool(bool b);
	void writeChar(char c);
	void writeShort(short s);
	void writeInt(int i);
	void writeLong(long long l);
	void writeFloat(float f);
	void writeDouble(double d);
	void writeString(std::string s);
	void writeString8(std::string s);
	void writeString16(std::string s);
	void writeString32(std::string s);

	void finish();

private:
	std::string _stream;
	short _head;
	int _pos;
	int _size;
	bool _isBigEndian = true;
};

NS_CC_END

#endif