#include "ap.h"
#include "ap_cmp_dac.h"


void apInit(void)
{
    // apFramInit();  // i2c pin 아트웍 문제 발생
    apLedInit();
    apCommInit();
    apCmpDacInit();
    apAdcInit();
    apExtDacInit();
}

void apLoop(void)
{
    while(true)
    {
        apLedLoop();
        apCmpDacLoop();
        apAdcLoop();
        apCommLoop();
        apExtDacLoop();
        // apFramLoop();  // i2c pin 아트웍 문제 발생
    }
}
