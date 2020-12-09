#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>

#include <time.h>

extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp) __THROW;

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

int bytes2Int( uint8_t fourBytes[4])
{
	return *( int* ) fourBytes;
}

void int2Bytes(  int num, uint8_t fourBytes[4])
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
	//mes[1] = 23; // SET_PID_DIFFERENTIAL_GAIN_R
	mes[1] = 100; // SET_TELEMETRY_STRING
	sprintf((char*)&mes[4], "?A:?V:?T:#200"); 
	mes[3] = strlen ( (char*)&mes[4] ) + 4;
	genSum(mes);
	printf("&mes[4]: %s\n", &mes[4]);
	printf("mes[3]: %d\n", mes[3]);
	printf("mes[2]: %d\n", mes[2]);
	
	reply[4] = 0;
	
	struct timespec tv1, tv2, wait_ts1, wait_ts2;
	double time_diff = .0;
	wait_ts1.tv_sec = 0;
	wait_ts1.tv_nsec = 10000000L ; /// 10 milliseconds
	clock_gettime ( CLOCK_MONOTONIC, &tv1 );
	
	int status, fd; // file descriptor

	fd = open("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_NONBLOCK);

	if(fd > 0)
	{
		printf("Open successfully\n");
		
		int i = 0, k;
		do
		{
			status = write(fd, (void*)&mes[0], 17);
			printf("%d: Transmitted message with status: %d\n", i, status);
			
			usleep(12000);   /// 11 ms
			reply[4] = 0;
			
			read(fd, reply, 64);
			if (reply[0] == '$') k = reply[4];
			else k = -17;
			
			printf("%d: REPLY: %d\n", i, k);
			
			i++;
		} while (i < 100);
		
		close(fd);
	}
	else
	{
		printf("failed to open device\n");
	}

	
return 0;
}