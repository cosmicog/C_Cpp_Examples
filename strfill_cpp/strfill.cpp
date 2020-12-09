
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <boost/concept_check.hpp>

using std::string;

int main ()
{
    uint8_t cstr_uint8[64] = "Hello Mina's Street. I'm Gandalf. Hearken to me...\n";

    sprintf ( ( char* ) &cstr_uint8[4], "My name is Optimus Prime mtfckr!\n" );

    string* str1;

    str1 = new string();

    *str1 = ( char* ) &cstr_uint8[4];

    std::cout << *str1 ;



    int a = 1234;

    a /= 1000;

    std::cout << "AAAAAAAAAA: " << a << std::endl;

    return 0;
}