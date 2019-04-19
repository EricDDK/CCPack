#include "CCBinary.h"

USING_NS_CC;

CCBinary* CCBinary::create(const char* stream)
{
	CCBinary* binary = new (std::nothrow) CCBinary;
	binary->init(stream);
	return binary;
}

CCBinary::CCBinary()
{

}

CCBinary::~CCBinary()
{
	CC_SAFE_DELETE(_stream);
}

bool CCBinary::init(const char* stream)
{
	_stream = stream;
	_pos = 0;
	_size = strlen(stream);
	return true;
}

unsigned char CCBinary::readByte()
{
	unsigned char b;
	size_t len = sizeof(b);
	if (len + _pos > _size)
		return NULL;
	memcpy(&b, _stream, len);
	_pos += len;
	return b;
}

bool CCBinary::readBool()
{
	bool b;
	size_t len = sizeof(b);
	if (len + _pos > _size)
		return NULL;
	memcpy(&b, _stream, len);
	_pos += len;
	return b;
}

char CCBinary::readChar()
{
	char c;
	size_t len = sizeof(c);
	if (len + _pos > _size)
		return NULL;
	memcpy(&c, _stream, len);
	_pos += len;
	return c;
}

short CCBinary::readShort()
{
	short s;
	size_t len = sizeof(s);
	if (len + _pos > _size)
		return NULL;
	memcpy(&s, _stream, len);
	_pos += len;
	return s;
}

int CCBinary::readInt()
{
	int i;
	size_t len = sizeof(i);
	if (len + _pos > _size)
		return NULL;
	memcpy(&i, _stream, len);
	_pos += len;
	return i;
}

long long CCBinary::readLong()
{
	long long l;
	size_t len = sizeof(l);
	if (len + _pos > _size)
		return NULL;
	memcpy(&l, _stream, len);
	_pos += len;
	return l;
}

float CCBinary::readFloat()
{
	float f;
	size_t len = sizeof(f);
	if (len + _pos > _size)
		return NULL;
	memcpy(&f, _stream, len);
	_pos += len;
	return f;
}

double CCBinary::readDouble()
{
	double d;
	size_t len = sizeof(d);
	if (len + _pos > _size)
		return NULL;
	memcpy(&d, _stream, len);
	_pos += len;
	return d;
}

const char * CCBinary::readString()
{
	size_t len = this->readShort();
	const char* c;
	if (len + _pos > _size)
		return NULL;
	memcpy(&c, _stream, len);
	_pos += len;
	return c;
}

