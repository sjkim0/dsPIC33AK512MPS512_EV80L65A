#include "ap.h"


void apInit(void)
{
    apLedInit();
    apCommInit();
    apAdcInit();
}

void apLoop(void)
{
    while(true)
    {
        apLedLoop();
        apAdcLoop();
        apCommLoop();
    }
}
