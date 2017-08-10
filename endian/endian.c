
#include <stdio.h>
#include <inttypes.h>

int32_t bytesToInt32( uint8_t fourBytes[4])
{
	return *( int32_t* ) fourBytes;
}

int bytesToInt( uint8_t fourBytes[4])
{
	return *( int* ) fourBytes;
}

int16_t bytesToInt16( uint8_t twoBytes[2])
{
	return *( int16_t* ) twoBytes;
}

float bytes2Float( uint8_t fourBytes[4] )
{
	return *( float* ) fourBytes;
}

void int32ToBytes(  int32_t num, uint8_t fourBytes[4])
{
	fourBytes[0] = num & 0xFF;
	fourBytes[1] = (num >> 8) & 0xFF;
	fourBytes[2] = (num >> 16) & 0xFF;
	fourBytes[3] = (num >> 24) & 0xFF;
}

void int16ToBytes(  int16_t num, uint8_t twoBytes[2])
{
	twoBytes[1] = (num >> 8) & 0xFF;
	twoBytes[0] = num & 0xFF;
}

void intToBytes(  int num, uint8_t fourBytes[4])
{
	fourBytes[0] = num & 0xFF;
	fourBytes[1] = (num >> 8) & 0xFF;
	fourBytes[2] = (num >> 16) & 0xFF;
	fourBytes[3] = (num >> 24) & 0xFF;
}

void float2Bytes( float num, uint8_t fourBytes[4])
{
	unsigned int* asInt = (unsigned int*)&num;

	fourBytes[0] =  *asInt        & 0xFF;
	fourBytes[1] = (*asInt >> 8 ) & 0xFF;
	fourBytes[2] = (*asInt >> 16) & 0xFF;
	fourBytes[3] = (*asInt >> 24) & 0xFF;
}

int main ()
{
	int32_t reis_out = 0;
	int32_t reis_in = 999999999;
	
	uint8_t bytes[4];
	uint8_t extended_bytes[6];
	
	int32ToBytes(reis_in, &bytes[1]);
	
// 	bytes[3] = (reis_in >> 24) & 0xff;
// 	bytes[2] = (reis_in >> 16) & 0xff;
// 	bytes[1] = (reis_in >> 8) & 0xff;
// 	bytes[0] = reis_in & 0xff;
	
	reis_out = bytesToInt32( &bytes[1] );//*( int* ) bytes;
	
	printf("reis_in: %u\nreis_out: %u\n", reis_in, reis_out);
	
	int sayi= 1234567890;//123456789;
	float s2 = 123.456;
	uint8_t sayi_bytes[4];
	
	intToBytes(sayi, sayi_bytes);
	printf ("%d:\n", sayi);
	printf ("%d\n", sayi_bytes[0]);
	printf ("%d\n", sayi_bytes[1]);
	printf ("%d\n", sayi_bytes[2]);
	printf ("%d\n", sayi_bytes[3]);
	
	float float_of_int_1234_bytes = bytes2Float(sayi_bytes);
	
	printf( "float_of_int_1234_bytes: %f\n", float_of_int_1234_bytes);
	
	float2Bytes(s2, sayi_bytes);
	printf ("%f:\n", s2);
	printf ("%d\n", sayi_bytes[0]);
	printf ("%d\n", sayi_bytes[1]);
	printf ("%d\n", sayi_bytes[2]);
	printf ("%d\n", sayi_bytes[3]);
	
	
	int dummy_int = bytesToInt(sayi_bytes);
	float dummy_float = bytes2Float(sayi_bytes);
	
	printf("dummy_int: %d\n", dummy_int);
	printf("dumm_float: %f\n", dummy_float);
	
	
return 0;
}