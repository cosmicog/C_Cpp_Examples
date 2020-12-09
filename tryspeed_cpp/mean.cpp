#include <iostream>

static const double BILLION = 1000000000.0;

int main ( int argc, char **argv )
{
	
	double d0 = 0.075384;

	double d1 = 0.0741677;

	double d2 = 0.074426;

	double d3 = 0.0740817;

	double d4 = 0.0734898;

	double d5 = 0.0747045;

	double d6 = 0.0727975;

	double d7 = 0.0772903;

	double d8 = 0.0726992;

	double s0 = 0.00806864;

	double s1 = 0.00727956;

	double s2 = 0.00202144;

	double s3 = 0.00195636;

	double s4 = 0.00203696;

	double s5 = 0.00387936;

	double s6 = 0.00276425;

	double s7 = 0.00200299;

	double s8 = 0.00207049;
	
	double s = s0 + s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8;
	
	double d = d0 + d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8;
	
	s /= 9;
	d /= 9;
	
    std::cout << "Process only:: mean: " << s << std::endl;
	std::cout << "Alloc Dealloc:: mean: " << d << std::endl;

return 0;
}
