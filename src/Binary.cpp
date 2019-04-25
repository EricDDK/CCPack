#include "Binary.h"

USING_NS_CC;

Binary* Binary::createRead(std::string stream)
{
	Binary* binary = new (std::nothrow) Binary;
	if (binary && binary->initRead(stream))
	{
		binary->autorelease();
		return binary;
	}
	return nullptr;
}

Binary* Binary::createWrite()
{
	Binary* binary = new (std::nothrow) Binary;
	if (binary && binary->initWrite())
	{
		binary->autorelease();
		return binary;
	}
	return nullptr;
}

Binary::Binary()
{
	
}

Binary::~Binary()
{
	
}

bool Binary::initRead(std::string stream)
{
	_stream = stream;
	_pos = 0;
	_size = _stream.size();
	return true;
}

bool Binary::initWrite()
{
	_head = 0;
	_pos = 0;
	_size = 0;
	writeShort(sizeof(short));
	_stream.clear();
	return true;
}

const void Binary::setEndian(const bool isBigEndian)
{
	_isBigEndian = isBigEndian;
}

const bool Binary::isBigEndian() const
{
	return _isBigEndian;
}

unsigned char Binary::readByte()
{
	unsigned char b;
	size_t len = sizeof(b);
	if (len + _pos > _size)
		return NULL;
	memcpy(&b, _stream.substr(_pos, _pos + len).c_str(), len);
	_pos += len;
	return b;
}

bool Binary::readBool()
{
	bool b;
	size_t len = sizeof(b);
	if (len + _pos > _size)
		return NULL;
	memcpy(&b, _stream.substr(_pos, _pos + len).c_str(), len);
	_pos += len;
	return b;
}

char Binary::readChar()
{
	char c;
	size_t len = sizeof(c);
	if (len + _pos > _size)
		return NULL;
	memcpy(&c, _stream.substr(_pos, _pos + len).c_str(), len);
	_pos += len;
	return c;
}

short Binary::readShort()
{
	short s;
	size_t len = sizeof(s);
	if (len + _pos > _size)
		return NULL;
	memcpy(&s, _stream.substr(_pos, _pos + len).c_str(), len);
	_pos += len;
	return s;
}

int Binary::readInt()
{
	int i;
	size_t len = sizeof(i);
	if (len + _pos > _size)
		return NULL;
	memcpy(&i, _stream.substr(_pos, _pos + len).c_str(), len);
	_pos += len;
	return i;
}

long long Binary::readLong()
{
	long long l;
	size_t len = sizeof(l);
	if (len + _pos > _size)
		return NULL;
	memcpy(&l, _stream.substr(_pos, _pos + len).c_str(), len);
	_pos += len;
	return l;
}

float Binary::readFloat()
{
	float f;
	size_t len = sizeof(f);
	if (len + _pos > _size)
		return NULL;
	memcpy(&f, _stream.substr(_pos, _pos + len).c_str(), len);
	_pos += len;
	return f;
}

double Binary::readDouble()
{
	double d;
	size_t len = sizeof(d);
	if (len + _pos > _size)
		return NULL;
	memcpy(&d, _stream.substr(_pos, _pos + len).c_str(), len);
	_pos += len;
	return d;
}

std::string Binary::readString()
{
	const size_t len = this->readChar();
	if (len + _pos > _size)
		return NULL;
	std::string s = _stream.substr(_pos, len).c_str();
	_pos += len;
	return s;
}

void Binary::writeByte(unsigned char b)
{
	size_t len = sizeof(b);
	memcpy(&_stream + _pos, &b, len);
	_head += len;
}

void Binary::writeBool(bool b)
{
	size_t len = sizeof(b);
	memcpy(&_stream + _pos, &b, len);
	_head += len;
}

void Binary::writeChar(char c)
{
	size_t len = sizeof(c);
	memcpy(&_stream + _pos, &c, len);
	_head += len;
}

void Binary::writeShort(short sh)
{
	const size_t len = sizeof(sh);
	char s[len];
	memcpy(s, &sh, len);
	_stream += s;
	_head += len;
}

void Binary::writeInt(int i)
{
	const size_t len = sizeof(i);
	char s[len];
	memcpy(s, &i, len);
	_stream += s;
	_head += len;
}

void Binary::writeLong(long long l)
{

}

void Binary::writeFloat(float f)
{

}

void Binary::writeDouble(double d)
{

}

void Binary::writeString(std::string s)
{
	writeChar(s.size());
	_stream += s;
	_head += (s.size() + 1);
}

void Binary::finish()
{
	char dataLen[sizeof(short)];
	memcpy(dataLen, &_head, sizeof(short));
	_stream[0] = dataLen[0];
	_stream[1] = dataLen[1];
}















