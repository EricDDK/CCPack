#ifndef _CCPACK_IPACK_H__
#define _CCPACK_IPACK_H__

class IPack {
public:
    virtual IPack read() = 0;
    virtual void write(const Ipack &data) = 0;
};

#endif
