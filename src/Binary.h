#ifndef _CCPACK_BINARY_H__
#define _CCPACK_BINARY_H__

#define CCPACK_NAMESPACE_START namespace CCPack {
#define CCPACK_NAMESPACE_END }
#define CCPACK_NAMESPACE_USING using namespace CCPack;

#include <string>
#include "IPack.h"

CCPACK_NAMESPACE_START

typedef unsigned char byte;

class Binary
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
	std::string readString();  //for C# ReadString
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
	void writeString(std::string s);  //for C# WriteString
	void writeString8(std::string s);
	void writeString16(std::string s);
	void writeString32(std::string s);

	void finish();
    
public:
    template<class T>
    T readValue();
    template<class T>
    void writeValue(const T &value);

private:
	int read7BitEncodedInt();  //for C# ReadString
	void write7BitEncodedInt(int len);  //for C# WriteString

private:
	std::string _stream;
	short _head;
	int _pos;
	int _size;
	bool _isBigEndian = true;
};

CCPACK_NAMESPACE_END

#endif
