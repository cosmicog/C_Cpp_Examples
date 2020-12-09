
#include <stdio.h>
#include <inttypes.h>

typedef struct /// fl : fr : rl : rr
{
	_Bool fl;
	_Bool fr;
	_Bool rl;
	_Bool rr;
}bumperstate_t;

bumperstate_t bumperstate;

uint8_t getBumperStateCompressed()
{
	uint8_t ret = bumperstate.fl;
	ret = (ret << 1) | bumperstate.fr;
	ret = (ret << 1) | bumperstate.rl;
	ret = (ret << 1) | bumperstate.rr;

	return ret;
}

int main ()
{
	printf("0000 : getBumperStateCompressed(): %d\n", (int)getBumperStateCompressed());
	
	bumperstate.rr = 1;
	printf("0001 : getBumperStateCompressed(): %d\n", (int)getBumperStateCompressed());
	
	bumperstate.rl = 1;
	printf("0011 : getBumperStateCompressed(): %d\n", (int)getBumperStateCompressed());
	
	bumperstate.fr = 1;
	printf("0111 : getBumperStateCompressed(): %d\n", (int)getBumperStateCompressed());
	
	bumperstate.fl = 1;
	printf("1111 : getBumperStateCompressed(): %d\n", (int)getBumperStateCompressed());
	
	
return 0;
}