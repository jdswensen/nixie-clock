/**
 ******************************************************************************
 * @file    button.h
 * @brief   
 * @details 
 * @author  Jake Swensen
 * @date    10/22/2015
 * @version 0.0.1
 ****************************************************************************** 
*/

#ifndef BUTTON_H
#define BUTTON_H

/* Includes -----------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Preprocessor Definitions -------------------------------------------------*/

typedef enum 
{
    BUTTON_STATE_RELEASED,  
    BUTTON_STATE_DEBOUNCING,
    BUTTON_STATE_PRESSED,
    BUTTON_STATE_SHORT,
    BUTTON_STATE_STANDARD,
    BUTTON_STATE_LONG,
    BUTTON_STATE_LONG_LONG
} buttonState_e;

typedef enum 
{
    BUTTON_GPIO_DEASSERTED,
    BUTTON_GPIO_ASSERTED,
    BUTTON_TIM_TICK
} buttonEvent_e;

/* ==========================================================================*/
/* Public Information =======================================================*/
/* ==========================================================================*/
/* Public enumerations ------------------------------------------------------*/


/* Public structures --------------------------------------------------------*/
/* Public type definition ---------------------------------------------------*/
typedef struct button_s
{
    // Input pin
    GPIO_TypeDef*       button_port;
    uint32_t            button_pin;
    GPIO_InitTypeDef*   button_gpio_handle;

    // Use sysTick?
    uint8_t             useSysTick;
    
    // Timer handle and instance
    TIM_HandleTypeDef*  button_timer_handle;
    TIM_TypeDef*        instance;
    
    // Button press times (ms)
    uint32_t            shortDuration;
    uint32_t            standDuration;
    uint32_t            longDuration;
    uint32_t            longLongDuration;
    
    // Callback functions
    void (*shortCallback)(void);
    void (*standCallback)(void);
    void (*longCallaback)(void);
    void (*longLongCallback)(void);
    void (*releaseCallback)(void);
    
    // State variables
    uint32_t            count;
    uint32_t            debounceCount;
    buttonState_e       currState;
    uint8_t             beenPressed;
    uint8_t             shortIssued;
    uint8_t             standIssued;
    uint8_t             longIssued;
    uint8_t             longLongIssued;
    
} button_t;

/* Public constants ---------------------------------------------------------*/
/* Public variables ---------------------------------------------------------*/
/* Public function prototypes -----------------------------------------------*/


#endif
