/**
 ******************************************************************************
 * @file    data_structures.c
 * @brief   Nixie tube clock data structures
 * @details 
 * @author  Jake Swensen
 * @date    12/13/2014
 * @version 0.0.1
 * @todo    
 ****************************************************************************** 
 */

/* Includes -----------------------------------------------------------------*/
#include "stm32f0xx_hal.h"
#include "data_structures.h"

/* ==========================================================================*/
/* Public Information =======================================================*/
/* ==========================================================================*/
/* Public constants ---------------------------------------------------------*/
/* Public variables ---------------------------------------------------------*/

GPIO_InitTypeDef    gpios[5];

shiftReg_t nixieShift = 
{
    // Data
    GPIOA,
    GPIO_PIN_7,
    &gpios[0],
        
    // Clock
    GPIOA,
    GPIO_PIN_5,
    &gpios[1],
        
    // Latch
    GPIOB,
    GPIO_PIN_4,
    &gpios[2],
       
    // Blank        
    GPIOB,
    GPIO_PIN_0,
    &gpios[3],
};


button_t nixieModeButton = 
{
    // Mode gpio
    (GPIO_TypeDef *) GPIOB_BASE,
    GPIO_PIN_9,
    &gpios[4],
    
    // Use sysTick?
    1,
    
    // Time base handle and instance
    0,
    TIM3,
    
    // Press durations
    10,
    250,
    1000,
    5000,
    
    // Callback functions
    0,
    0,
    0,
    0,
    0,
    
    // State variables
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};
