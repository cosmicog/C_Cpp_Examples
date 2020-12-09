#include <iostream>
#include <inttypes.h>
#include <cstring>
#include <bitset>

struct HexCharStruct
{
  unsigned char c;
  HexCharStruct(unsigned char _c) : c(_c) { }
};

inline std::ostream& operator<<(std::ostream& o, const HexCharStruct& hs)
{
  return (o << std::hex << (int)hs.c);
}

inline HexCharStruct hex(unsigned char _c)
{
  return HexCharStruct(_c);
}

int main ( int argc, char **argv )
{
	
    uint8_t arr[2];
    int16_t test = 143;
    
    std::memcpy(&arr[0], &test, sizeof test);
	
    
    std::cout << hex(arr[0]) << std::endl;
    
    std::cout << hex(arr[1]) << std::endl;
    
    
    
    unsigned char cmd_bytes_[4];
    int32_t a = 5 * 10000;
    
    std::cout << static_cast<int>(a) << std::endl;
    
    
    int b = 5;
    cmd_bytes_[0] =  (b*10000)      & 0xFF;
    cmd_bytes_[1] = ((b*10000)>>8)  & 0xFF;
    cmd_bytes_[2] = ((b*10000)>>16) & 0xFF;
    cmd_bytes_[3] = ((b*10000)>>24) & 0xFF;
    
    
    std::memcpy(&a, &cmd_bytes_[0], sizeof (int32_t));
    std::cout << static_cast<int>(a) << std::endl;
    

return 0;
}
 
