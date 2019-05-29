#ifndef _CCPACK_IPACK_H__
#define _CCPACK_IPACK_H__

template<class T>
class IPack {
public:
	virtual T read() = 0;
	virtual void write(const T &data) = 0;
};

#endif
