#include "ap.h"
#include "ap_fram.h"


void apInit(void)
{
    apFramInit();
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
        apFramLoop();
    }
}
