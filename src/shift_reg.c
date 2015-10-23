/**
 ******************************************************************************
 * @file    shift_reg.c
 * @brief   Shift register interface
 * @details Use gpios to shift data out to an external shift register
 * @author  Jake Swensen
 * @date    12/13/2014
 * @version 0.0.1
 * @todo    Use SPI w/ DMA for faster processing
 ****************************************************************************** 
 */
 
/* Includes -----------------------------------------------------------------*/
#include "shift_reg.h"

/* ==========================================================================*/
/* Public Information =======================================================*/
/* ==========================================================================*/
/* Public constants ---------------------------------------------------------*/
/* Public variables ---------------------------------------------------------*/

/* ==========================================================================*/
/* Private Information ======================================================*/
/* ==========================================================================*/
/* Private definitions ------------------------------------------------------*/
//#define SHIFT_REG_DEBUG     0x00

#define dataRead()  HAL_GPIO_ReadPin(thisShiftReg->data_port, thisShiftReg->data_pin)
#define dataWrite() HAL_GPIO_WritePin(thisShiftReg->data_port, thisShiftReg->data_pin, GPIO_PIN_SET)
#define dataClear() HAL_GPIO_WritePin(thisShiftReg->data_port, thisShiftReg->data_pin, GPIO_PIN_RESET)

#define clkWrite() HAL_GPIO_WritePin(thisShiftReg->clk_port, thisShiftReg->clk_pin, GPIO_PIN_SET)
#define clkClear() HAL_GPIO_WritePin(thisShiftReg->clk_port, thisShiftReg->clk_pin, GPIO_PIN_RESET)

#define latchWrite() HAL_GPIO_WritePin(thisShiftReg->latch_port, thisShiftReg->latch_pin, GPIO_PIN_SET)
#define latchClear() HAL_GPIO_WritePin(thisShiftReg->latch_port, thisShiftReg->latch_pin, GPIO_PIN_RESET)

#define blankWrite() HAL_GPIO_WritePin(thisShiftReg->blank_port, thisShiftReg->blank_pin, GPIO_PIN_SET)
#define blankClear() HAL_GPIO_WritePin(thisShiftReg->blank_port, thisShiftReg->blank_pin, GPIO_PIN_RESET)

#define clearWrite() HAL_GPIO_WritePin(thisShiftReg->clear_port, thisShiftReg->clear_pin, GPIO_PIN_SET)
#define clearClear() HAL_GPIO_WritePin(thisShiftReg->clear_port, thisShiftReg->clear_pin, GPIO_PIN_RESET)


/* ***************************************************************************/
/* Public functions **********************************************************/
/* ***************************************************************************/

/**
 ******************************************************************************
 * @fn          ShiftReg_Init
 * @brief       Initialize a shift register
 * @param[in]   thisShiftReg - shift register structure
 * @retval      none
 * @details     Initialize a shift register by passing this init function
 *              a structure filled with gpio definitions
 *              Written for a STM32 device
 ******************************************************************************
 */
void ShiftReg_Init (shiftReg_t* thisShiftReg)
{
    // GPIO Clock setup
    // TODO: Setup gpio clocks
    
    // Data pin setup
    thisShiftReg->data_gpio_handle->Pin         = thisShiftReg->data_pin;
    thisShiftReg->data_gpio_handle->Mode        = GPIO_MODE_OUTPUT_PP;
    thisShiftReg->data_gpio_handle->Pull        = GPIO_PULLUP;
    thisShiftReg->data_gpio_handle->Speed       = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(thisShiftReg->data_port, (thisShiftReg->data_gpio_handle));
    
    // Clock pin setup
    thisShiftReg->clk_gpio_handle->Pin          = thisShiftReg->clk_pin;
    thisShiftReg->clk_gpio_handle->Mode         = GPIO_MODE_OUTPUT_PP;
    thisShiftReg->clk_gpio_handle->Pull         = GPIO_PULLUP;
    thisShiftReg->clk_gpio_handle->Speed        = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(thisShiftReg->clk_port, (thisShiftReg->clk_gpio_handle));
    
    // Latch pin setup
    thisShiftReg->latch_gpio_handle->Pin        = thisShiftReg->latch_pin;
    thisShiftReg->latch_gpio_handle->Mode       = GPIO_MODE_OUTPUT_PP;
    thisShiftReg->latch_gpio_handle->Pull       = GPIO_PULLUP;
    thisShiftReg->latch_gpio_handle->Speed      = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(thisShiftReg->latch_port, (thisShiftReg->latch_gpio_handle));
    
    // Blank pin setup
    thisShiftReg->blank_gpio_handle->Pin        = thisShiftReg->blank_pin;
    thisShiftReg->blank_gpio_handle->Mode       = GPIO_MODE_OUTPUT_PP;
    thisShiftReg->blank_gpio_handle->Pull       = GPIO_PULLUP;
    thisShiftReg->blank_gpio_handle->Speed      = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(thisShiftReg->blank_port, (thisShiftReg->blank_gpio_handle));

    // Initial pin values
    blankWrite();
    latchWrite();
    clkClear();
    dataClear();
}


/**
 ******************************************************************************
 * @fn          ShiftReg_ShiftByte
 * @brief       Shift a byte of data out the shift register gpios
 * @param[in]   thisShiftReg - shift register structure
 * @param[in]   data - 8 bit data to shift out
 * @param[in]   order - data shifted out in msb or lsb
 * @retval      none
 * @details     Shift out a byte of data in msb or lsb order
 ******************************************************************************
 */
void ShiftReg_ShiftByte ( shiftReg_t* thisShiftReg, 
                          int8_t data, 
                          bitOrder_e order )
{
    uint8_t mask;
    uint8_t index;
    
    if ( msb == order )
    {
        mask = 0x80;   
    }
    else
    {
        mask = 0x01;   
    }
    
#if defined (SHIFT_REG_DEBUG)
        printf("[ INFO ] ShiftByte: Data shifted - ");
#endif
    
    for ( index = 0; index < 8; index++ )
    {
        if ( data & mask )
        {
            dataWrite();  
        }
        else
        {
            dataClear();
        }

#if defined (SHIFT_REG_DEBUG)
        printf("%d ", dataRead());
#endif

        if ( msb == order )
        {
            mask = mask >> 1;
        }
        else
        {
            mask = mask << 1;   
        }
        
        HAL_Delay(1);   // Allow for data setup time
        clkWrite();
        HAL_Delay(1);   // Let clock stabalize
        clkClear();
    }
    
#if defined (SHIFT_REG_DEBUG)
        printf("\n\r");
#endif
}


/**
 ******************************************************************************
 * @fn          ShiftReg_RepeatByte
 * @brief       Not implimented
 * @retval      none
 * @details     
 ******************************************************************************
 */
void ShiftReg_RepeatByte ( shiftReg_t* thisShiftReg, 
                           int8_t data, 
                           uint8_t numRepeats, 
                           bitOrder_e order)
{
    
}

/**
 ******************************************************************************
 * @fn          ShiftReg_ShiftBit
 * @brief       Shift a single bit out the shift register gpio
 * @param[in]   thisShiftReg - shift register structure
 * @param[in]   data - Single bit to shift out
 * @retval      none
 * @details     
 ******************************************************************************
 */
void ShiftReg_ShiftBit ( shiftReg_t* thisShiftReg, 
                         int8_t data )
{
    if ( data )
    {
        dataWrite();
    }
    else
    {
        dataClear();
    }
    
    HAL_Delay(1);   // Allow for data setup time
    clkWrite();
    HAL_Delay(1);   // Let clock stabalize
    clkClear();
}


/**
 ******************************************************************************
 * @fn          ShiftReg_Latch
 * @brief       Latch the data currently in the shift register
 * @retval      none
 * @details     
 ******************************************************************************
 */
void ShiftReg_Latch ( shiftReg_t* thisShiftReg )
{
    latchClear();       // Assert the latch signal
    HAL_Delay(1);       // Let it stabalize
    latchWrite();       // Turn it off
}


/**
 ******************************************************************************
 * @fn          ShiftReg_Clear
 * @brief       Not implimented
 * @retval      none
 * @details     
 ******************************************************************************
 */
void ShiftReg_Clear ( shiftReg_t* thisShiftReg )
{

}


/**
 ******************************************************************************
 * @fn          ShiftReg_AssertClear
 * @brief       Not implimented
 * @retval      none
 * @details     
 ******************************************************************************
 */
void ShiftReg_AssertBlank ( shiftReg_t* thisShiftReg )
{
    
}


/**
 ******************************************************************************
 * @fn          ShiftReg_Clear
 * @brief       Not implimented
 * @retval      none
 * @details     
 ******************************************************************************
 */
void ShiftReg_ReleaseBlank ( shiftReg_t* thisShiftReg )
{

}
