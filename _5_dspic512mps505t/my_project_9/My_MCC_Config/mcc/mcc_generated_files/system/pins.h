/**
 * PINS Generated Driver Header File 
 * 
 * @file      pins.h
 *            
 * @defgroup  pinsdriver Pins Driver
 *            
 * @brief     The Pin Driver directs the operation and function of 
 *            the selected device pins using dsPIC MCUs.
 *
 * @skipline @version   PLIB Version 1.0.5
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

#ifndef PINS_H
#define PINS_H
// Section: Includes
#include <xc.h>

/**
 * @ingroup  pinsdriver
 * @brief    Locks all the Peripheral Remapping registers and cannot be written.
 * @return   none  
 */
#define PINS_PPSLock()           (RPCONbits.IOLOCK = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Unlocks all the Peripheral Remapping registers and can be written.
 * @return   none  
 */
#define PINS_PPSUnlock()         (RPCONbits.IOLOCK = 0)

// Section: Device Pin Macros
/**
 * @ingroup  pinsdriver
 * @brief    Sets the RD1 GPIO Pin which has a custom name of BAND_SELECT to High
 * @pre      The RD1 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define BAND_SELECT_SetHigh()          (_LATD1 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RD1 GPIO Pin which has a custom name of BAND_SELECT to Low
 * @pre      The RD1 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define BAND_SELECT_SetLow()           (_LATD1 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RD1 GPIO Pin which has a custom name of BAND_SELECT
 * @pre      The RD1 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define BAND_SELECT_Toggle()           (_LATD1 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RD1 GPIO Pin which has a custom name of BAND_SELECT
 * @param    none
 * @return   none  
 */
#define BAND_SELECT_GetValue()         _RD1

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RD1 GPIO Pin which has a custom name of BAND_SELECT as Input
 * @param    none
 * @return   none  
 */
#define BAND_SELECT_SetDigitalInput()  (_TRISD1 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RD1 GPIO Pin which has a custom name of BAND_SELECT as Output
 * @param    none
 * @return   none  
 */
#define BAND_SELECT_SetDigitalOutput() (_TRISD1 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RD2 GPIO Pin which has a custom name of SPI_SS_0 to High
 * @pre      The RD2 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define SPI_SS_0_SetHigh()          (_LATD2 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RD2 GPIO Pin which has a custom name of SPI_SS_0 to Low
 * @pre      The RD2 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define SPI_SS_0_SetLow()           (_LATD2 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RD2 GPIO Pin which has a custom name of SPI_SS_0
 * @pre      The RD2 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define SPI_SS_0_Toggle()           (_LATD2 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RD2 GPIO Pin which has a custom name of SPI_SS_0
 * @param    none
 * @return   none  
 */
#define SPI_SS_0_GetValue()         _RD2

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RD2 GPIO Pin which has a custom name of SPI_SS_0 as Input
 * @param    none
 * @return   none  
 */
#define SPI_SS_0_SetDigitalInput()  (_TRISD2 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RD2 GPIO Pin which has a custom name of SPI_SS_0 as Output
 * @param    none
 * @return   none  
 */
#define SPI_SS_0_SetDigitalOutput() (_TRISD2 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Initializes the PINS module
 * @param    none
 * @return   none  
 */
void PINS_Initialize(void);



#endif
