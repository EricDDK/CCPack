#include "CCBinary.h"

USING_NS_CC;

CCBinary* CCBinary::createRead(std::string stream)
{
	CCBinary* binary = new (std::nothrow) CCBinary;
	binary->initRead(stream);
	return binary;
}

CCBinary* CCBinary::createWrite()
{
	CCBinary* binary = new (std::nothrow) CCBinary;
	binary->initWrite();
	return binary;
}

CCBinary::CCBinary()
{

}

CCBinary::~CCBinary()
{
	_receiveStream.clear();
	_sendStream.clear();
}

bool CCBinary::initRead(std::string stream)
{
	_receiveStream = stream;
	_pos = 0;
	_size = _receiveStream.size();
	return true;
}

bool CCBinary::initWrite()
{
	_receiveStream.clear();
	_pos = 0;
	_size = 0;
	return true;
}

const void CCBinary::setEndian(const bool isBigEndian)
{
	_isBigEndian = isBigEndian;
}

const bool CCBinary::isBigEndian() const
{
	return _isBigEndian;
}

unsigned char CCBinary::readByte()
{
	unsigned char b;
	size_t len = sizeof(b);
	if (len + _pos > _size)
		return NULL;
	memcpy(&b, _receiveStream.substr(_pos, _pos + len).c_str(), len);
	_pos += len;
	return b;
}

bool CCBinary::readBool()
{
	bool b;
	size_t len = sizeof(b);
	if (len + _pos > _size)
		return NULL;
	memcpy(&b, _receiveStream.substr(_pos, _pos + len).c_str(), len);
	_pos += len;
	return b;
}

char CCBinary::readChar()
{
	char c;
	size_t len = sizeof(c);
	if (len + _pos > _size)
		return NULL;
	memcpy(&c, _receiveStream.substr(_pos, _pos + len).c_str(), len);
	_pos += len;
	return c;
}

short CCBinary::readShort()
{
	short s;
	size_t len = sizeof(s);
	if (len + _pos > _size)
		return NULL;
	memcpy(&s, _receiveStream.substr(_pos, _pos + len).c_str(), len);
	_pos += len;
	return s;
}

int CCBinary::readInt()
{
	int i;
	size_t len = sizeof(i);
	if (len + _pos > _size)
		return NULL;
	memcpy(&i, _receiveStream.substr(_pos, _pos + len).c_str(), len);
	_pos += len;
	return i;
}

long long CCBinary::readLong()
{
	long long l;
	size_t len = sizeof(l);
	if (len + _pos > _size)
		return NULL;
	memcpy(&l, _receiveStream.substr(_pos, _pos + len).c_str(), len);
	_pos += len;
	return l;
}

float CCBinary::readFloat()
{
	float f;
	size_t len = sizeof(f);
	if (len + _pos > _size)
		return NULL;
	memcpy(&f, _receiveStream.substr(_pos, _pos + len).c_str(), len);
	_pos += len;
	return f;
}

double CCBinary::readDouble()
{
	double d;
	size_t len = sizeof(d);
	if (len + _pos > _size)
		return NULL;
	memcpy(&d, _receiveStream.substr(_pos, _pos + len).c_str(), len);
	_pos += len;
	return d;
}

char* CCBinary::readString()
{
	size_t len = this->readChar();
	if (len + _pos > _size)
		return NULL;
	char* c = new char[len];
	memcpy(c, _receiveStream.substr(_pos, _pos + len).c_str(), len);
	c[len] = '\0';
	_pos += len;
	return c;
}

void CCBinary::writeByte(unsigned char b)
{

}

void CCBinary::writeBool(bool b)
{

}

void CCBinary::writeChar(char c)
{

}

void CCBinary::writeShort(short s)
{

}

void CCBinary::writeInt(int i)
{

}

void CCBinary::writeLong(long long l)
{

}

void CCBinary::writeFloat(float f)
{

}

void CCBinary::writeDouble(double d)
{

}

void CCBinary::writeString(std::string s)
{

}
















