#ifndef Bitmask_hpp
#define Bimask_hpp
#include <stdint.h>

class Bitmask
{
public:
    Bitmask();
    void setMask(Bitmask& other);
    uint32_t getMask() const;
    bool getBit(int pos) const;
    void setBit(int pos, bool on);
    void setBit(int pos);
    void clearBit(int pos);
    void clear();
private:
    uint32_t bits;
};

#endif