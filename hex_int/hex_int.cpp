#include <iostream>
#include <stdio.h>
#include <inttypes.h>

using namespace std;

int main ()
{
	int i = 35;
    uint8_t b = i;

    cout << "i: " << i << ", b: " << b << endl;
    printf("Hex vers. of b: 0x%X\n", b);

    cout << "sizeof(uint8_t): " << sizeof(uint8_t) << endl
         << "sizeof(int16_t): " << sizeof(int16_t) << endl
         << "sizeof(int)    : " << sizeof(int)     << endl
         << endl;

return 0;
}
