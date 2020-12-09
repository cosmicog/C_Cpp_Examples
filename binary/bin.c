
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

void int32ToBinary(int32_t val, uint8_t array[4])
{
	int i;
	for(i = 0; i < 4; i++)
	{
		array[i] = (uint8_t)val%2;
		val /= 2;
		if (val < 0) return;
	}
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
	printf("1111 : getBumperStateCompressed(): %d\n\n", (int)getBumperStateCompressed());
	
	printf ("\n");
	printf ("BIN  : DEC\n");
	printf ("----------\n");
	printf ("0000 :   0\n");
	printf ("0001 :   1\n");
	printf ("0010 :   2\n");
	printf ("0011 :   3\n");
	printf ("0100 :   4\n");
	printf ("0101 :   5\n");
	printf ("0110 :   6\n");
	printf ("0111 :   7\n");
	printf ("1000 :   8\n");
	printf ("1001 :   9\n");
	printf ("1010 :  10\n");
	printf ("1011 :  11\n");
	printf ("1100 :  12\n");
	printf ("1101 :  13\n");
	printf ("1110 :  14\n");
	printf ("1111 :  15\n");
	printf ("\n");
	
	printf ("DECIMAL : I2B\n");
	printf ("-------------\n");
	uint8_t bin_arr[4] = {0, 0, 0, 0};
	int32_t val;
	int i;
	
	for (val = 0; val < 16; val++)
	{
		printf("%d	:", (int)val);
		int32ToBinary(val, bin_arr);
		for (i = 3; i >=0; i--)
		{
			printf("%d", (int) bin_arr[i]);
		}
		printf("\n");
	}
	
return 0;
}