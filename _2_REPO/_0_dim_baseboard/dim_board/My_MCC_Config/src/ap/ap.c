#include "ap.h"


void apInit(void)
{
    // apFramInit();  // i2c pin 아트웍 문제 발생
    apLedInit();
    apCommInit();
    apAdcInit();
    apExtDacInit();
}

void apLoop(void)
{
    while(true)
    {
        apLedLoop();
        apAdcLoop();
        apCommLoop();
        apExtDacLoop();
        // apFramLoop();  // i2c pin 아트웍 문제 발생
    }
}
