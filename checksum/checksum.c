
#include <stdio.h>
#include <inttypes.h>

int bytesToInt( uint8_t fourBytes[4])
{
	return *( int* ) fourBytes;
}

void intToBytes(  int num, uint8_t fourBytes[4])
{
	fourBytes[0] = num & 0xFF;
	fourBytes[1] = (num >> 8) & 0xFF;
	fourBytes[2] = (num >> 16) & 0xFF;
	fourBytes[3] = (num >> 24) & 0xFF;
}

void genSum(uint8_t* msg_arr)
{
	int sum = 0, i;
	sum += msg_arr[0];
	sum += msg_arr[1];
	
	for (i = 3; i < msg_arr[3]; i++) sum += msg_arr[i];
	
	msg_arr[2] = sum % 256;
}

_Bool checkSum(uint8_t* msg_arr)
{
	int sum = 0, i;
	sum += msg_arr[0];
	sum += msg_arr[1];
	
	for (i = 3; i < msg_arr[3]; i++) sum += msg_arr[i];
	
	sum = sum % 256;
	if (sum == msg_arr[2]) return 1;
	else return 0;
}

int main ()
{
	uint8_t UserRxBufferFS[64];
	
	UserRxBufferFS[0] = '$';
	UserRxBufferFS[1] = 1; // SET_SPEED_R

	UserRxBufferFS[3] = 8; // Length 8
	UserRxBufferFS[4] = 21;
	UserRxBufferFS[5] = 205;
	UserRxBufferFS[6] = 91;
	UserRxBufferFS[7] = 7;
	
	genSum(UserRxBufferFS); 
	
	if (checkSum(UserRxBufferFS))
	{
		printf("What does the Fox say?\n");
	}
	
	
return 0;
}