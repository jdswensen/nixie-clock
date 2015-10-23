/**
 ******************************************************************************
 * @file    shift_reg.h
 * @brief   Shift register interface
 * @details 
 * @author  Jake Swensen
 * @date    12/13/2014
 * @version 0.0.1
 ****************************************************************************** 
*/

#ifndef _SHIFT_REG_H
#define _SHIFT_REG_H

/* Includes -----------------------------------------------------------------*/
#include "stm32f0xx_hal.h"
#include "stdint.h"

/* Preprocessor Definitions -------------------------------------------------*/




/* ==========================================================================*/
/* Public Information =======================================================*/
/* ==========================================================================*/
/* Public enumerations ------------------------------------------------------*/
typedef enum 
{
    msb = 0x80,
    lsb = 0x01
} bitOrder_e;

/* Public structures --------------------------------------------------------*/
/* Public type definition ---------------------------------------------------*/
typedef struct shiftReg_s
{
    
    GPIO_TypeDef*       data_port;
    uint32_t            data_pin;
    GPIO_InitTypeDef*   data_gpio_handle;
    
    GPIO_TypeDef*       clk_port;
    uint32_t            clk_pin;
    GPIO_InitTypeDef*   clk_gpio_handle;
    
    GPIO_TypeDef*       latch_port;
    uint32_t            latch_pin;
    GPIO_InitTypeDef*   latch_gpio_handle;
    
    GPIO_TypeDef*       blank_port;
    uint32_t            blank_pin;
    GPIO_InitTypeDef*   blank_gpio_handle;
    
} shiftReg_t;

/* Public constants ---------------------------------------------------------*/
/* Public variables ---------------------------------------------------------*/
/* Public function prototypes -----------------------------------------------*/
void ShiftReg_Init          ( shiftReg_t* thisShiftReg );

void ShiftReg_ShiftByte     ( shiftReg_t* thisShiftReg, 
                              int8_t data, 
                              bitOrder_e order );
void ShiftReg_RepeatByte    ( shiftReg_t* thisShiftReg, 
                              int8_t data, 
                              uint8_t numRepeats, 
                              bitOrder_e order);
void ShiftReg_ShiftBit      ( shiftReg_t* thisShiftReg, 
                              int8_t data );
void ShiftReg_Latch         ( shiftReg_t* thisShiftReg );
void ShiftReg_Clear         ( shiftReg_t* thisShiftReg );
void ShiftReg_AssertClear   ( shiftReg_t* thisShiftReg );
void ShiftReg_ReleaseClear  ( shiftReg_t* thisShiftReg );

#endif
