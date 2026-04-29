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
 * @skipline  Device : dsPIC33AK512MPS512
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
 * @brief    Sets the RG9 GPIO Pin which has a custom name of BAND_INPUT to High
 * @pre      The RG9 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define BAND_INPUT_SetHigh()          (_LATG9 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RG9 GPIO Pin which has a custom name of BAND_INPUT to Low
 * @pre      The RG9 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define BAND_INPUT_SetLow()           (_LATG9 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RG9 GPIO Pin which has a custom name of BAND_INPUT
 * @pre      The RG9 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define BAND_INPUT_Toggle()           (_LATG9 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RG9 GPIO Pin which has a custom name of BAND_INPUT
 * @param    none
 * @return   none  
 */
#define BAND_INPUT_GetValue()         _RG9

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RG9 GPIO Pin which has a custom name of BAND_INPUT as Input
 * @param    none
 * @return   none  
 */
#define BAND_INPUT_SetDigitalInput()  (_TRISG9 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RG9 GPIO Pin which has a custom name of BAND_INPUT as Output
 * @param    none
 * @return   none  
 */
#define BAND_INPUT_SetDigitalOutput() (_TRISG9 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RH0 GPIO Pin which has a custom name of SPI_SS to High
 * @pre      The RH0 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define SPI_SS_SetHigh()          (_LATH0 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RH0 GPIO Pin which has a custom name of SPI_SS to Low
 * @pre      The RH0 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define SPI_SS_SetLow()           (_LATH0 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RH0 GPIO Pin which has a custom name of SPI_SS
 * @pre      The RH0 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define SPI_SS_Toggle()           (_LATH0 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RH0 GPIO Pin which has a custom name of SPI_SS
 * @param    none
 * @return   none  
 */
#define SPI_SS_GetValue()         _RH0

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RH0 GPIO Pin which has a custom name of SPI_SS as Input
 * @param    none
 * @return   none  
 */
#define SPI_SS_SetDigitalInput()  (_TRISH0 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RH0 GPIO Pin which has a custom name of SPI_SS as Output
 * @param    none
 * @return   none  
 */
#define SPI_SS_SetDigitalOutput() (_TRISH0 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Initializes the PINS module
 * @param    none
 * @return   none  
 */
void PINS_Initialize(void);



#endif
