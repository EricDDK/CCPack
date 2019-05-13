#include "Binary.h"

//custome define
//Header offset, currently protocol number 4 bytes
#define HEAD_OFFSET 4; 

CCPACK_NAMESPACE_START

Binary* Binary::createRead(std::string stream)
{
	Binary* binary = new Binary;
	if (binary && binary->initRead(stream))
		return binary;
	return nullptr;
}

Binary* Binary::createWrite()
{
	Binary* binary = new Binary;
	if (binary && binary->initWrite())
		return binary;
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

byte Binary::readByte()
{
	return readValue<byte>();
}

bool Binary::readBool()
{
	return readValue<bool>();
}

char Binary::readChar()
{
	return readValue<char>();
}

short Binary::readShort()
{
	return readValue<short>();
}

int Binary::readInt()
{
	return readValue<int>();
}

long long Binary::readLong()
{
	return readValue<long long>();
}

float Binary::readFloat()
{
	return readValue<float>();
}

double Binary::readDouble()
{
	return readValue<double>();
}

std::string Binary::readString()
{
	const int len = read7BitEncodedInt();
	if (len + _pos > _size)
		return NULL;
	std::string s = _stream.substr(_pos, len).c_str();
	_pos += len;
	return s;
}

std::string Binary::readString8()
{
	const int len = this->readChar();
	if (len + _pos > _size)
		return NULL;
	std::string s = _stream.substr(_pos, len).c_str();
	_pos += len;
	return s;
}

std::string Binary::readString16()
{
	const int len = this->readShort();
	if (len + _pos > _size)
		return NULL;
	std::string s = _stream.substr(_pos, len).c_str();
	_pos += len;
	return s;
}

std::string Binary::readString32()
{
	const int len = this->readInt();
	if (len + _pos > _size)
		return NULL;
	std::string s = _stream.substr(_pos, len).c_str();
	_pos += len;
	return s;
}

int Binary::read7BitEncodedInt()
{
	byte oneByte;
	int len = 0;
	int head = 0;
	do
	{
		if (head == 0x23)
			return 0;
		oneByte = readByte();
		len |= (oneByte & 0x7f) << head;
		head += 7;
	} while ((oneByte & 0x80) != 0);
	return len;
}

void Binary::writeByte(byte b)
{
	writeValue<byte>(b);
}

void Binary::writeBool(bool b)
{
	writeValue<bool>(b);
}

void Binary::writeChar(char c)
{
	writeValue<char>(c);
}

void Binary::writeShort(short sh)
{
	writeValue<short>(sh);
}

void Binary::writeInt(int i)
{
	writeValue<int>(i);
}

void Binary::writeLong(long long l)
{
	writeValue<long long>(l);
}

void Binary::writeFloat(float f)
{
	writeValue<float>(f);
}

void Binary::writeDouble(double d)
{
	writeValue<double>(d);
}

void Binary::writeString(std::string s)
{
	write7BitEncodedInt(s.size());
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

void Binary::write7BitEncodedInt(int len)
{
	unsigned int num = (unsigned int)len;
	while (num >= 0x80)
	{
		writeByte((byte)(num | 0x80));
		num = num >> 7;
	}
	writeByte((byte)num);
}

void Binary::finish()
{
	char dataLen[sizeof(short)];
	_head -= HEAD_OFFSET;
	memcpy(dataLen, &_head, sizeof(short));
	_stream[0] = dataLen[0];
	_stream[1] = dataLen[1];
}

CCPACK_NAMESPACE_END
