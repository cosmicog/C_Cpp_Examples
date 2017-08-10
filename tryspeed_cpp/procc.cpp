#include <iostream>
#include <string.h>
#include <inttypes.h>
#include <time.h>

static const double BILLION = 1000000000.0;
extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp) __THROW;

class AllocEvery
{
public:
	
	double pi, gold, ogh;
	std::string den_rit, jobs, bill;
	char c_str[64];
	
	int doSomething()
	{
		pi   = 3.1415926535;
		gold = 1.6180339887;
		ogh  = 0.0000000033;
		ogh += pi;
		ogh += gold;
		jobs = "Being the richest man in the cemetery doesn't matter to me. Going to bed at night saying we've done something wonderful, that's what matters to me.";
		bill = "Your most unhappy customers are your greatest source of learning.";
		den_rit = "UNIX is basically a simple operating system, but you have to be a genius to understand the simplicity.";
        return 0;
	}
};

int main ( int argc, char **argv )
{
	int max = 80 * 60 * 5; // Rate * Seconds * Minutes
	struct timespec time1, time2;
    double time_diff = .0;
	AllocEvery obj;
	
	clock_gettime ( CLOCK_MONOTONIC, &time1 );
	
	for (int i = 0; i < max; i++)
	{
		obj.doSomething();
	}

    clock_gettime ( CLOCK_MONOTONIC, &time2 );

	time_diff = time2.tv_sec - time1.tv_sec + ( time2.tv_nsec - time1.tv_nsec ) / BILLION;
    
	std::cout << "Process only:: Elapsed time: " << time_diff << std::endl;

return 0;
}
