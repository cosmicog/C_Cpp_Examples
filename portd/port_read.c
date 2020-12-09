#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>

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

int main ()
{
	uint8_t reply[20];
	uint8_t mes[64];
	
	mes[0] = '$';
	//mes[1] = 21; // READ_PID_DIFFERENTIAL_GAIN_X10_R
	//mes[1] = 106; // GET_DRIVE_VERSION
	mes[1] = 99; // READ_TELEMETRY_STRING
	mes[3] = 4; // Length 4
	genSum(mes);
	
	int status = 0, fd; // file descriptor

	fd = open("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_NONBLOCK);

	if(fd > 0)
	{
		printf("Open successfully\n");
		
		//status = write(fd, (void*)&mes[0], 8);
		
		printf("Not Transmitted message with status: %d\n Did nothing cause of try, edit code\n", status);
		
		close(fd);
	}
	else
	{
		printf("failed to open device\n");
	}
	
return 0;
}