#include "ap.h"
#include "user_comm.h"


void apInit(void)
{
    userCommInit();
}

void apLoop(void)
{
    userCommLoop();
}
