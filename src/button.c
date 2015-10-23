/**
 ******************************************************************************
 * @file    button.c
 * @brief   Operate a button
 * @details 
 * @author  Jake Swensen
 * @date    10/22/2015
 * @version 0.0.1
 * @todo    
 ****************************************************************************** 
 */
 
/* Includes -----------------------------------------------------------------*/
#include "button.h"

/* ==========================================================================*/
/* Public Information =======================================================*/
/* ==========================================================================*/
/* Public constants ---------------------------------------------------------*/
/* Public variables ---------------------------------------------------------*/

/* ==========================================================================*/
/* Private Information ======================================================*/
/* ==========================================================================*/
/* Private definitions ------------------------------------------------------*/
//#define BUTTON_DEBUG     0x00

#define buttonRead()  HAL_GPIO_ReadPin(thisButton->button_port, thisButton->button_pin)


void Button_StateMachine ( button_t* thisButton, buttonEvent_e event );

/* ***************************************************************************/
/* Public functions **********************************************************/
/* ***************************************************************************/

/**
 ******************************************************************************
 * @fn          
 * @brief       
 * @param[in]   
 * @retval      
 * @details     
 ******************************************************************************
 */
void Button_Init ( button_t* thisButton )
{
    // TODO: Error check input
    //       Make sure short < stand < long < longLong
    
    uint32_t prescalerCalc = 0;
    
    // Do we need a dedicated timer?
    // Otherwise, we will be using the systick as our time base
    if ( 0 == thisButton->useSysTick )
    {
        // Enable the clock to the timer
        if ( TIM3 == thisButton->instance )
        {
            __HAL_RCC_TIM3_CLK_ENABLE();
            HAL_NVIC_SetPriority(TIM3_IRQn, 3, 0);
            HAL_NVIC_EnableIRQ(TIM3_IRQn);
        }
        
        prescalerCalc = (uint32_t)(SystemCoreClock / 1000) - 1;
        
        thisButton->button_timer_handle->Instance               = thisButton->instance;
        thisButton->button_timer_handle->Init.Period            = 1000-1;
        thisButton->button_timer_handle->Init.Prescaler         = prescalerCalc;
        thisButton->button_timer_handle->Init.CounterMode       = TIM_COUNTERMODE_UP;
        thisButton->button_timer_handle->Init.RepetitionCounter = 0;
        HAL_TIM_Base_Init(thisButton->button_timer_handle);
    }
    
    
    
    thisButton->count           = 0;
    thisButton->currState       = BUTTON_STATE_RELEASED;
    thisButton->beenPressed     = 0;
    
    thisButton->shortIssued     = 0;
    thisButton->standIssued     = 0;
    thisButton->longIssued      = 0;
    thisButton->longLongIssued  = 0;
}

void Button_GpioIrqHandler ( button_t* thisButton )
{    
    if ( buttonRead() == GPIO_PIN_SET )
    {
        Button_StateMachine(thisButton, BUTTON_GPIO_ASSERTED);
    }
    else
    {
        Button_StateMachine(thisButton, BUTTON_GPIO_DEASSERTED);
    }
}

void Button_TimerIrqHandler ( button_t* thisButton )
{
    Button_StateMachine(thisButton, BUTTON_TIM_TICK);
    
    // TODO: Reset the timer
}


void Button_StateMachine ( button_t* thisButton, buttonEvent_e event )
{
    // Button is not being pressed
    if ( BUTTON_STATE_RELEASED == thisButton->currState )
    {
        switch ( event )
        {
            case BUTTON_GPIO_DEASSERTED:
                // Don't care case
                break;
            
            case BUTTON_GPIO_ASSERTED:
                // clear the count
                thisButton->count = 0;
                thisButton->debounceCount = 2;
            
                // Start timer if necessary (or depend on the systick)
                if ( 0 == thisButton->useSysTick )
                {
                    HAL_TIM_Base_Start_IT(thisButton->button_timer_handle);
                }

                // Now we wait
                break;
            
            case BUTTON_TIM_TICK:
                // Don't care case
                break;
        }
    }
    
    // Debouncing button
    if ( BUTTON_STATE_DEBOUNCING == thisButton->currState )
    {
        switch ( event )
        {
            case BUTTON_GPIO_DEASSERTED:
                // Debouncing, don't care case
                break;
            
            case BUTTON_GPIO_ASSERTED:
                // Debouncing, don't care case
                break;
            
            case BUTTON_TIM_TICK:
                thisButton->count++;
                
                if ( thisButton->count < thisButton->debounceCount )
                {
                    // We are still waiting for the debounce to finish
                }
                else
                {
                    // Debounced, change state based on gpio
                    if ( buttonRead() == GPIO_PIN_SET )
                    {
                        // The debounce was either the beginning of button press
                        // or a glitch, goto the proper state based on the 
                        // count variable
                        if ( thisButton->count < thisButton->shortDuration )
                        {
                            // Debounce was at the beginning of button press
                            thisButton->currState = BUTTON_STATE_PRESSED;
                        }
                        else if ( thisButton->count >= thisButton->shortDuration && thisButton->count < thisButton->standDuration )
                        {
                            // Debounce was a glitch in the short state
                            thisButton->currState = BUTTON_STATE_SHORT;
                            
                            // Check to see if we missed the transition from 
                            // pressed->short due to the bouncing switch
                            if ( 0 == thisButton->shortIssued )
                            {
                                thisButton->shortIssued = 1;
                                thisButton->beenPressed = 1;
                                thisButton->shortCallback();
                            }
                        }
                    }
                    else
                    {
                        thisButton->currState = BUTTON_STATE_RELEASED;
                        
                        thisButton->shortIssued     = 0;
                        thisButton->standIssued     = 0;
                        thisButton->longIssued      = 0;
                        thisButton->longLongIssued  = 0;
                        
                        // If we've made it passed the pressed state, callback
                        if ( 0 != thisButton->releaseCallback && 0 != thisButton->beenPressed )
                        {
                            thisButton->beenPressed = 0;
                            thisButton->releaseCallback();
                        }
                    }
                }
                break;
        }
    }
    
    // Button has been pressed
    if ( BUTTON_STATE_PRESSED == thisButton->currState )
    {
        switch ( event )
        {
            case BUTTON_GPIO_DEASSERTED:
                break;
            
            case BUTTON_GPIO_ASSERTED:
                break;
            
            case BUTTON_TIM_TICK:
                break;
        }
    }
    
    // Button has been pressed for short duration
    if ( BUTTON_STATE_SHORT == thisButton->currState )
    {
        switch ( event )
        {
            case BUTTON_GPIO_DEASSERTED:
                break;
            
            case BUTTON_GPIO_ASSERTED:
                break;
            
            case BUTTON_TIM_TICK:
                break;
        }
    }
    
    // Button has been pressed for standard duration
    if ( BUTTON_STATE_STANDARD == thisButton->currState )
    {
        switch ( event )
        {
            case BUTTON_GPIO_DEASSERTED:
                break;
            
            case BUTTON_GPIO_ASSERTED:
                break;
            
            case BUTTON_TIM_TICK:
                break;
        }
    }
    
    // Button has been pressed for long duration
    if ( BUTTON_STATE_LONG == thisButton->currState )
    {
        switch ( event )
        {
            case BUTTON_GPIO_DEASSERTED:
                break;
            
            case BUTTON_GPIO_ASSERTED:
                break;
            
            case BUTTON_TIM_TICK:
                break;
        }
    }
    
    // Button has been pressed for long, long duration
    if ( BUTTON_STATE_LONG_LONG == thisButton->currState )
    {
        switch ( event )
        {
            case BUTTON_GPIO_DEASSERTED:
                break;
            
            case BUTTON_GPIO_ASSERTED:
                break;
            
            case BUTTON_TIM_TICK:
                break;
        }
    }
    
}

