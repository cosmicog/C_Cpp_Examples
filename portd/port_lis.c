#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include "usb_serial_constants.h"

void printResult(uint8_t* command)
{
	switch(command[1])
	{
	case SET_SPEED_L:
		break;

	case SET_SPEED_R:
		break;

	case SET_SPEEDS:
		break;

	case GET_SPEED_L:
		break;

	case GET_SPEED_R:
		break;

	case GET_POSITIONS:
		break;

	case GET_POSITION_L:
		break;

	case GET_POSITION_R:
		break;

	case READ_ANALOG_INPUT_L:
		break;

	case READ_ANALOG_INPUT_R:
		break;

	case READ_FEEDBACK_L:
		break;
	case READ_FEEDBACK_R:
		break;

	case READ_PID_PROPORTIONAL_GAIN_X10_L:
		break;
	case READ_PID_PROPORTIONAL_GAIN_X10_R:
		break;

	case SET_PID_PROPORTIONAL_GAIN_L:
		break;
	case SET_PID_PROPORTIONAL_GAIN_R:
		break;

	case READ_PID_INTEGRAL_GAIN_X10_L:
		break;
	case READ_PID_INTEGRAL_GAIN_X10_R:
		break;

	case SET_PID_INTEGRAL_GAIN_L:
		break;
	case SET_PID_INTEGRAL_GAIN_R:
		break;

	case READ_PID_DIFFERENTIAL_GAIN_X10_L:
		break;
	case READ_PID_DIFFERENTIAL_GAIN_X10_R:
		if (command[3] == 8) printf(">>> READ_PID_DIFFERENTIAL_GAIN_R Success: %d\n", bytesToInt(&command[4]));
		else                 printf("!!! READ_PID_DIFFERENTIAL_GAIN_R Fail!\n");
		break;

	case SET_PID_DIFFERENTIAL_GAIN_L:
		break;
	case SET_PID_DIFFERENTIAL_GAIN_R:
		if (command[4] == 1) printf(">>> SET_PID_DIFFERENTIAL_GAIN_R Success!\n");
		else                 printf("!!! SET_PID_DIFFERENTIAL_GAIN_R Fail!\n");
		break;

	case READ_PID_INTEGRAL_CAP_L:
		break;
	case READ_PID_INTEGRAL_CAP_R:
		break;

	case SET_PID_INTEGRAL_CAP_L:
		break;
	case SET_PID_INTEGRAL_CAP_R:
		break;

	case READ_TURNS_MIN_MAX_X100_L:
		break;
	case READ_TURNS_MIN_MAX_X100_R:
		break;

	case SET_TURNS_MIN_MAX_L:
		break;
	case SET_TURNS_MIN_MAX_R:
		break;

	case READ_DEFAULT_POSITION_VELOCITY_L:
		break;
	case READ_DEFAULT_POSITION_VELOCITY_R:
		break;

	case SET_DEFAULT_POSITION_VELOCITY_L:
		break;
	case SET_DEFAULT_POSITION_VELOCITY_R:
		break;

	case READ_CURRENT_LIMIT_X10_L:
		break;
	case READ_CURRENT_LIMIT_X10_R:
		break;

	case SET_CURRENT_LIMIT_L:
		break;
	case SET_CURRENT_LIMIT_R:
		break;

	case READ_MAX_POWER_FORWARD_L:
		break;
	case READ_MAX_POWER_FORWARD_R:
		break;

	case SET_MAX_POWER_FORWARD_L:
		break;
	case SET_MAX_POWER_FORWARD_R:
		break;

	case READ_MAX_POWER_REVERSE_L:
		break;
	case READ_MAX_POWER_REVERSE_R:
		break;

	case SET_MAX_POWER_REVERSE_L:
		break;
	case SET_MAX_POWER_REVERSE_R:
		break;

	case READ_MAX_SPEED_L:
		break;
	case READ_MAX_SPEED_R:
		break;

	case SET_MAX_SPEED_L:
		if (command[4] == 1) printf(">>> SET_MAX_SPEED_L Success!\n");
		else                 printf("!!! SET_MAX_SPEED_L Fail!\n");
		break;
		
	case SET_MAX_SPEED_R:
		break;

	case READ_ACCELERATION_X10_L:
		break;
	case READ_ACCELERATION_X10_R:
		break;

	case SET_ACCELERATION_L:
		break;
	case SET_ACCELERATION_R:
		break;

	case READ_DECELERATION_X10_L:
		break;
	case READ_DECELERATION_X10_R:
		break;

	case SET_DECELERATION_L:
		break;
	case SET_DECELERATION_R:
		break;

	case READ_ANALOG_INPUT_MIN_L:
		break;
	case READ_ANALOG_INPUT_MIN_R:
		break;

	case SET_ANALOG_INPUT_MIN_L:
		break;
	case SET_ANALOG_INPUT_MIN_R:
		break;

	case READ_ANALOG_INPUT_CENTER_L:
		break;
	case READ_ANALOG_INPUT_CENTER_R:
		break;

	case SET_ANALOG_INPUT_CENTER_L:
		break;
	case SET_ANALOG_INPUT_CENTER_R:
		break;

	case READ_ANALOG_INPUT_MAX_L:
		break;
	case READ_ANALOG_INPUT_MAX_R:
		break;

	case SET_ANALOG_INPUT_MAX_L:
		break;
	case SET_ANALOG_INPUT_MAX_R:
		break;

	case READ_ANALOG_INPUT_POLARITY_L:
		break;
	case READ_ANALOG_INPUT_POLARITY_R:
		break;

	case SET_ANALOG_INPUT_POLARITY_L:
		break;
	case SET_ANALOG_INPUT_POLARITY_R:
		break;

	case READ_ANALOG_INPUT_DEAD_BAND_L:
		break;
	case READ_ANALOG_INPUT_DEAD_BAND_R:
		break;

	case SET_ANALOG_INPUT_DEAD_BAND_L:
		break;
	case SET_ANALOG_INPUT_DEAD_BAND_R:
		break;

	case READ_CL_ERROR_DETECTION_L:
		break;
	case READ_CL_ERROR_DETECTION_R:
		break;

	case SET_CL_ERROR_DETECTION_L:
		break;
	case SET_CL_ERROR_DETECTION_R:
		break;

	case READ_BATTERY_VOLTAGE_X10:
		break;

	case READ_MOTOR_COMMAND_L:
		break;
	case READ_MOTOR_COMMAND_R:
		break;

	case READ_CLOSED_LOOP_ERROR_L:
		break;
	case READ_CLOSED_LOOP_ERROR_R:
		break;

	case READ_MOTOR_AMPS_X10_L:
		break;
	case READ_MOTOR_AMPS_X10_R:
		break;

	case READ_MOTOR_POWER_L:
		break;
	case READ_MOTOR_POWER_R:
		break;

	case READ_RUNTIME_STATUS_L:
		break;
	case READ_RUNTIME_STATUS_R:
		break;

	case READ_FAULT_STATUS_L:
		break;
	case READ_FAULT_STATUS_R:
		break;

	case READ_TEMPERATURE_L:
		break;
	case READ_TEMPERATURE_R:
		break;

	case READ_TELEMETRY_STRING:
		command[command[3]] = '\0';
		if (command[3] != 5) printf( ">>> READ_PID_DIFFERENTIAL_GAIN_R Success: %s\n", (char*)&command[4] );
		else                 printf( "!!! READ_PID_DIFFERENTIAL_GAIN_R Fail!\n" );
		break;

	case SET_TELEMETRY_STRING:
		if (command[4] == 1) printf(">>> SET_TELEMETRY_STRING Success!\n");
		else                 printf("!!! SET_TELEMETRY_STRING Fail!\n");
		break;

	case SAVE_TO_EEPROM:
		break;

	case E_STOP_SOFT:
		break;

	case RELEASE_E_STOP_SOFT:
		break;

	case GO_L:
		break;
		
	case GO_R:
		break;

	case GET_DRIVE_VERSION:
		break;

	default:
		break; // TODO
	}
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
	uint8_t reply[64];
	uint8_t mes[64];
	
	/*
	* buf[0] --> $
	* buf[1] --> <COMMAND>
	* buf[2] --> CheckSum
	* buf[3] --> Message length
	*
	*
	* * if needed for setting value;
	* buf[4] --> fourBytes[0]
	* buf[5] --> fourBytes[1]
	* buf[6] --> fourBytes[2]
	* buf[7] --> fourBytes[3]
	*
	* * if value is string
	* buf[8] --> str[4]
	* ...
	*/
	
	mes[0] = '$';
	mes[1] = 1; // SET_SPEED_R
	mes[3] = 8; // Length 8
	mes[4] = 21;
	mes[5] = 205;
	mes[6] = 91;
	mes[7] = 7;
	genSum(mes);
	
	int status, fd; // file descriptor
	int i = 0;

	fd = open("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_NONBLOCK);

	if(fd > 0)
	{
		printf("Open successfully\n");
		
		while (1)
		{
			read(fd, reply, 64);
			if (reply[0] == '!')
			{
				printf("[%d]Corrupted data trasmitted to stm32!\n", i);
			}
// 			if (!checkSum(reply))
// 			{
// 				printf("[%d]Corrupted data received!\n", i);
// 			}
			else if(reply[3] >= 5)
			{
				printResult(reply);
				reply[3] = 0;
			}
			else if (reply[3] == 0)
			{
				printf("[%d]Returned: NOTHING...\n", i);
			}
			else
			{
				printf("[%d]Returned: %d\n", i, bytesToInt(&reply[4]));
				printf("reply[0] --> %c\n", reply[0]);
			}
			usleep(100000);	
			i++;
		}
		close(fd); // necessary?
	}
	else
	{
		printf("failed to open device\n");
	}
	
return 0;
}