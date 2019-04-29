#include "Binary.h"

//custome define
//Header offset, currently protocol number 4 bytes
//包头偏移量，当前为协议号4字节
#define HEAD_OFFSET 4; 

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
	_pos = 0;
	_size = 0;
	_stream.clear();
	writeInt(sizeof(int));
	_head = 0; //data length not contained in _head value
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

std::string Binary::readString8()
{
	const size_t len = this->readChar();
	if (len + _pos > _size)
		return NULL;
	std::string s = _stream.substr(_pos, len).c_str();
	_pos += len;
	return s;
}

std::string Binary::readString16()
{
	const size_t len = this->readShort();
	if (len + _pos > _size)
		return NULL;
	std::string s = _stream.substr(_pos, len).c_str();
	_pos += len;
	return s;
}

std::string Binary::readString32()
{
	const size_t len = this->readInt();
	if (len + _pos > _size)
		return NULL;
	std::string s = _stream.substr(_pos, len).c_str();
	_pos += len;
	return s;
}

void Binary::writeByte(unsigned char b)
{
	const size_t len = sizeof(b);
	char s[len];
	memcpy(s, &b, len);
	_stream += std::string(s, len);
	_head += len;
}

void Binary::writeBool(bool b)
{
	const size_t len = sizeof(b);
	char s[len];
	memcpy(s, &b, len);
	_stream += std::string(s, len);
	_head += len;
}

void Binary::writeChar(char c)
{
	const size_t len = sizeof(c);
	char s[len];
	memcpy(s, &c, len);
	_stream += std::string(s, len);
	_head += len;
}

void Binary::writeShort(short sh)
{
	const size_t len = sizeof(sh);
	char s[len];
	memcpy(s, &sh, len);
	_stream += std::string(s, len);
	_head += len;
}

void Binary::writeInt(int i)
{
	const size_t len = sizeof(i);
	char s[len];
	memcpy(s, &i, len);
	_stream += std::string(s, len);
	_head += len;
}

void Binary::writeLong(long long l)
{
	const size_t len = sizeof(l);
	char s[len];
	memcpy(s, &l, len);
	_stream += std::string(s, len);
	_head += len;
}

void Binary::writeFloat(float f)
{
	const size_t len = sizeof(f);
	char s[len];
	memcpy(s, &f, len);
	_stream += std::string(s, len);
	_head += len;
}

void Binary::writeDouble(double d)
{
	const size_t len = sizeof(d);
	char s[len];
	memcpy(s, &d, len);
	_stream += std::string(s, len);
	_head += len;
}

void Binary::writeString(std::string s)
{
	writeChar(s.size());
	_stream += s;
	_head += (s.size() + 1);
}

void Binary::writeString8(std::string s)
{
	writeChar(s.size());
	_stream += s;
	_head += (s.size() + sizeof(char));
}

void Binary::writeString16(std::string s)
{
	writeShort(s.size());
	_stream += s;
	_head += (s.size() + sizeof(short));
}

void Binary::writeString32(std::string s)
{
	writeInt(s.size());
	_stream += s;
	_head += (s.size() + sizeof(int));
}

void Binary::finish()
{
	char dataLen[sizeof(short)];
	_head -= HEAD_OFFSET;
	memcpy(dataLen, &_head, sizeof(short));
	_stream[0] = dataLen[0];
	_stream[1] = dataLen[1];
}















