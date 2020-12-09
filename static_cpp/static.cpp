
#include <iostream>
#include <stdio.h>
#include <inttypes.h>
#include <boost/lexical_cast.hpp>

int staticTester(int val)
{
	static int ret = ++val;
	return ret;
}

int main ()
{
	
	for (int i = 0; i < 10; i++)
	{
		std::cout << staticTester(i) << std::endl;
	}
	
	/// EKKKKKKKKKKKKKKKKKKKKKKKKKK
	std::string str;
	
	str = boost::lexical_cast<std::string>(-15);
	
	std::cout << str << std::endl;
	
	
return 0;
}