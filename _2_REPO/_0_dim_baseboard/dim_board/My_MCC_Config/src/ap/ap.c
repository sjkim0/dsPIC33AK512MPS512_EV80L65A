#include "ap.h"


void apInit(void)
{
    apLedInit();
    apCommInit();
}

void apLoop(void)
{
    while(true)
    {
        apLedLoop();
        apCommLoop();
    }
}
