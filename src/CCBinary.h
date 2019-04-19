#ifndef __CCBINARY_H__
#define __CCBINARY_H__

#include "cocos2d.h"

NS_CC_BEGIN

class CC_DLL CCBinary
{
public:
	static CCBinary* create(const char * binary);

	CCBinary();
	~CCBinary();

	bool init(const char* stream);

	unsigned char readByte();
	bool readBool();
	char readChar();
	short readShort();
	int readInt();
	long long readLong();
	float readFloat();
	double readDouble();
	const char * readString();

private:
	const char * _stream;
	int _pos;
	int _size;
};

NS_CC_END

#endif