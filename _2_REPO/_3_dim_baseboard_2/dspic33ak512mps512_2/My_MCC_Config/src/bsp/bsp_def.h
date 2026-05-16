#ifndef BSP_DEF_H
#define BSP_DEF_H


#include "tmr1.h"


enum ENUM_CALLBACK_ID
{
    CALLBACK_ID_I2C1 = 0,
    CALLBACK_ID_MAX
};


typedef struct
{
    uint32_t timer_count;
    bool is_called[CALLBACK_ID_MAX];
}bsp_t;


void bspCallbackInit(void);
bool bspIsCalled(enum ENUM_CALLBACK_ID callback_id);

void setTimerCount(uint32_t count);
uint32_t getTimerCount(void);

#endif