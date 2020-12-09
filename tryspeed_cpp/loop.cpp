#include <iostream>
#include <string.h>
#include <inttypes.h>
#include <iomanip>
#include <time.h>

static const double BILLION = 1000000000.0;
extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp) __THROW;

struct LedColor
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

class LoopSpeedTest
{
public:
	
	void doWithLoop()
	{
        for (unsigned int i = 0, j = 0; i < 40; i++)
        {
            leds_cmd[j++] =   leds[i].red;
            leds_cmd[j++] =   leds[i].green;
            leds_cmd[j++] =   leds[i].blue;
        }
	}
	
	void doWithoutLoop()
	{
        leds_cmd[0] =   leds[0].red;
        leds_cmd[1] =   leds[0].green;
        leds_cmd[2] =   leds[0].blue;

        leds_cmd[3] =   leds[1].red;
        leds_cmd[4] =   leds[1].green;
        leds_cmd[5] =   leds[1].blue;

        leds_cmd[6] =   leds[2].red;
        leds_cmd[7] =   leds[2].green;
        leds_cmd[8] =   leds[2].blue;

        leds_cmd[9] =   leds[3].red;
        leds_cmd[10] =  leds[3].green;
        leds_cmd[11] =  leds[3].blue;

        leds_cmd[12] =  leds[4].red;
        leds_cmd[13] =  leds[4].green;
        leds_cmd[14] =  leds[4].blue;

        leds_cmd[15] =  leds[5].red;
        leds_cmd[16] =  leds[5].green;
        leds_cmd[17] =  leds[5].blue;

        leds_cmd[18] =  leds[6].red;
        leds_cmd[19] =  leds[6].green;
        leds_cmd[20] =  leds[6].blue;

        leds_cmd[21] =  leds[7].red;
        leds_cmd[22] =  leds[7].green;
        leds_cmd[23] =  leds[7].blue;

        leds_cmd[24] =  leds[8].red;
        leds_cmd[25] =  leds[8].green;
        leds_cmd[26] =  leds[8].blue;

        leds_cmd[27] =  leds[9].red;
        leds_cmd[28] =  leds[9].green;
        leds_cmd[29] =  leds[9].blue;

        leds_cmd[30] =  leds[10].red;
        leds_cmd[31] =  leds[10].green;
        leds_cmd[32] =  leds[10].blue;

        leds_cmd[33] =  leds[11].red;
        leds_cmd[34] =  leds[11].green;
        leds_cmd[35] =  leds[11].blue;

        leds_cmd[36] =  leds[12].red;
        leds_cmd[37] =  leds[12].green;
        leds_cmd[38] =  leds[12].blue;

        leds_cmd[39] =  leds[13].red;
        leds_cmd[40] =  leds[13].green;
        leds_cmd[41] =  leds[13].blue;

        leds_cmd[42] =  leds[14].red;
        leds_cmd[43] =  leds[14].green;
        leds_cmd[44] =  leds[14].blue;

        leds_cmd[45] =  leds[15].red;
        leds_cmd[46] =  leds[15].green;
        leds_cmd[47] =  leds[15].blue;

        leds_cmd[48] =  leds[16].red;
        leds_cmd[49] =  leds[16].green;
        leds_cmd[50] =  leds[16].blue;

        leds_cmd[51] =  leds[17].red;
        leds_cmd[52] =  leds[17].green;
        leds_cmd[53] =  leds[17].blue;

        leds_cmd[54] =  leds[18].red;
        leds_cmd[55] =  leds[18].green;
        leds_cmd[56] =  leds[18].blue;

        leds_cmd[57] =  leds[19].red;
        leds_cmd[58] =  leds[19].green;
        leds_cmd[59] =  leds[19].blue;

        leds_cmd[60] =  leds[20].red;
        leds_cmd[61] =  leds[20].green;
        leds_cmd[62] =  leds[20].blue;

        leds_cmd[63] =  leds[21].red;
        leds_cmd[64] =  leds[21].green;
        leds_cmd[65] =  leds[21].blue;

        leds_cmd[66] =  leds[22].red;
        leds_cmd[67] =  leds[22].green;
        leds_cmd[68] =  leds[22].blue;

        leds_cmd[69] =  leds[23].red;
        leds_cmd[70] =  leds[23].green;
        leds_cmd[71] =  leds[23].blue;

        leds_cmd[72] =  leds[24].red;
        leds_cmd[73] =  leds[24].green;
        leds_cmd[74] =  leds[24].blue;

        leds_cmd[75] =  leds[25].red;
        leds_cmd[76] =  leds[25].green;
        leds_cmd[77] =  leds[25].blue;

        leds_cmd[78] =  leds[26].red;
        leds_cmd[79] =  leds[26].green;
        leds_cmd[80] =  leds[26].blue;

        leds_cmd[81] =  leds[27].red;
        leds_cmd[82] =  leds[27].green;
        leds_cmd[83] =  leds[27].blue;

        leds_cmd[84] =  leds[28].red;
        leds_cmd[85] =  leds[28].green;
        leds_cmd[86] =  leds[28].blue;

        leds_cmd[87] =  leds[29].red;
        leds_cmd[88] =  leds[29].green;
        leds_cmd[89] =  leds[29].blue;

        leds_cmd[90] =  leds[30].red;
        leds_cmd[91] =  leds[30].green;
        leds_cmd[92] =  leds[30].blue;

        leds_cmd[93] =  leds[31].red;
        leds_cmd[94] =  leds[31].green;
        leds_cmd[95] =  leds[31].blue;

        leds_cmd[96] =  leds[32].red;
        leds_cmd[97] =  leds[32].green;
        leds_cmd[98] =  leds[32].blue;

        leds_cmd[99] =  leds[33].red;
        leds_cmd[100] = leds[33].green;
        leds_cmd[101] = leds[33].blue;

        leds_cmd[102] = leds[34].red;
        leds_cmd[103] = leds[34].green;
        leds_cmd[104] = leds[34].blue;

        leds_cmd[105] = leds[35].red;
        leds_cmd[106] = leds[35].green;
        leds_cmd[107] = leds[35].blue;

        leds_cmd[108] = leds[36].red;
        leds_cmd[109] = leds[36].green;
        leds_cmd[110] = leds[36].blue;

        leds_cmd[111] = leds[37].red;
        leds_cmd[112] = leds[37].green;
        leds_cmd[113] = leds[37].blue;

        leds_cmd[114] = leds[38].red;
        leds_cmd[115] = leds[38].green;
        leds_cmd[116] = leds[38].blue;

        leds_cmd[117] = leds[39].red;
        leds_cmd[118] = leds[39].green;
        leds_cmd[119] = leds[39].blue;
	}
	
private:
    uint8_t leds_cmd[120];
    LedColor leds[40];
};


int main ( int argc, char **argv )
{
	int max = 50 * 60 * 60; // Rate * Seconds * Minutes
	struct timespec time1, time2;
    double time_diff = .0;
	LoopSpeedTest lst;
    
    std::cout << "Running both for 50 * 60 * 60 times. (Rate * Seconds * Minutes)" << std::endl;
	
	clock_gettime ( CLOCK_MONOTONIC, &time1 );
	lst.doWithLoop();
    clock_gettime ( CLOCK_MONOTONIC, &time2 );
	time_diff = time2.tv_sec - time1.tv_sec + ( time2.tv_nsec - time1.tv_nsec ) / BILLION;
	std::cout << "------------> :: With loop, time: " << std::fixed << std::setprecision(10) << time_diff << std::endl;
    
    clock_gettime ( CLOCK_MONOTONIC, &time1 );
	lst.doWithLoop();
    clock_gettime ( CLOCK_MONOTONIC, &time2 );
	time_diff = time2.tv_sec - time1.tv_sec + ( time2.tv_nsec - time1.tv_nsec ) / BILLION;
	std::cout << "------------> :: Without loop, time: " << std::fixed << std::setprecision(10)  << time_diff << std::endl;

return 0;
}
 
