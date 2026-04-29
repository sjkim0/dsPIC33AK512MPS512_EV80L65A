/**
 * CMP2 Generated Driver Source File
 * 
 * @file      cmp2.c
 *            
 * @ingroup   cmpdriver
 *            
 * @brief     This is the generated driver source file for CMP2 driver
 *
 * @skipline @version   PLIB Version 1.1.5
 *            
 * @skipline  Device : dsPIC33AK512MPS505
*/


/*
? [2026] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

// Section: Included Files

#include <xc.h>
#include "../cmp2.h"

#ifndef CMP_FPDMDAC_ADDRESS
#define CMP_FPDMDAC_ADDRESS 0x7F20B0UL
#endif //CMP_FPDMDAC_ADDRESS

// Section: File specific functions

static void (*CMP2_EventHandler)(void) = NULL;

// Section: Driver Interface
static const struct DAC_DC_INTERFACE dac2_dc_interface = {
    .Enable = &CMP2_DACEnable,
    .Disable = &CMP2_DACDisable,
    .DataWrite = &CMP2_DACDataWrite,
};

const struct CMP_INTERFACE CMP_REF_BAND_B = {
    .Initialize = &CMP2_Initialize,
    .Deinitialize = &CMP2_Deinitialize,
    .Enable = &CMP2_Enable,
    .Disable = &CMP2_Disable,
    .StatusGet = &CMP2_StatusGet,
    .Calibrate = &CMP2_Calibrate,
    
    .EventCallbackRegister = &CMP2_EventCallbackRegister,
    .Tasks = &CMP2_Tasks,
    .cmp_dac_dc_interface = &dac2_dc_interface,
    .cmp_dac_slope_interface = NULL,
};

// Section: CMP2 Module APIs

void CMP2_Initialize(void)
{           
    // Comparator Register settings
    DACCTRL1 = 0x3F7F0000UL; //FCLKDIV 1:1; DNLADJ 0x0; SIDL disabled; ON disabled; NEGINLADJ 127; POSINLADJ 63; RREN disabled; 
    DACCTRL2 = 0x8A0001UL; //TMODTIME 1; SSTIME 138; 
    DAC2CON = 0x800CUL; //DACOEN disabled; UPDTMDIS disabled; IRQM Interrupts are disabled; DACEN enabled; UPDREQ disabled; UPDTRG Any write(s) to DACDAT or SLPDAT sets the UPDATE bit immediately; TMCB 0; 
    DAC2CMP = 0x0UL; //INNSEL DACx; INPSEL CMP2A; CMPSTAT disabled; FLTREN disabled; CBE disabled; HYSSEL No hysteresis is selected; HYSPOL Rising Edge; 

    //Slope Settings
    DAC2DAT = 0xF3200CDUL; //DACLOW 205; DACDAT 3890; 
    DAC2SLPCON = 0x0UL; //SLPSTRT None; SLPSTOPB None; SLPSTOPA None; HCFSEL None; FFSEN disabled; PSE Negative; TWME disabled; HME disabled; SLOPEN disabled; 
    DAC2SLPDAT = 0x0UL; //SLPDAT 0; 
    
    CMP2_EventCallbackRegister(&CMP2_EventCallback);
    
    DACCTRL1bits.ON = 1U;
    //wait till update is complete, data registers are not writable until update is complete
    while(DAC2CONbits.UPDATE == 1U)
    {
    }
}

void CMP2_Deinitialize(void)
{ 
    DACCTRL1bits.ON = 0;
    
    
    // Comparator Register settings
    DACCTRL1 = 0x3F7F0000UL;
    DACCTRL2 = 0x8A0001UL;
    DAC2CON = 0x0UL;
    DAC2CMP = 0x0UL;

    //Slope Settings
    DAC2DAT = 0x0UL;
    DAC2SLPCON = 0x0UL;
    DAC2SLPDAT = 0x0UL;
}

void CMP2_Calibrate(void)
{
    uint32_t *fpdmdac = (uint32_t*)CMP_FPDMDAC_ADDRESS;
    DACCTRL1bits.POSINLADJ = ((*fpdmdac) & _DACCTRL1_POSINLADJ_MASK) >> _DACCTRL1_POSINLADJ_POSITION;
    DACCTRL1bits.NEGINLADJ = ((*fpdmdac) & _DACCTRL1_NEGINLADJ_MASK) >> _DACCTRL1_NEGINLADJ_POSITION;
    DACCTRL1bits.DNLADJ = ((*fpdmdac) & _DACCTRL1_DNLADJ_MASK) >> _DACCTRL1_DNLADJ_POSITION;
    DACCTRL1bits.RREN = 1U;
}

void CMP2_EventCallbackRegister(void (*handler)(void))
{
    if(NULL != handler)
    {
        CMP2_EventHandler = handler;
    }
}

void __attribute__ ((weak)) CMP2_EventCallback(void)
{ 
   
}
 
void CMP2_Tasks(void)
{
    if(IFS2bits.CMP2IF == 1U)
    {
        // CMP2 callback function 
        if(NULL != CMP2_EventHandler)
        {
            (*CMP2_EventHandler)();
        }
    
        // clear the CMP2 interrupt flag
        IFS2bits.CMP2IF = 0U;
    }
}

/**
 End of File
*/
