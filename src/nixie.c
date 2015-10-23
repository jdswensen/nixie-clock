/**
 ******************************************************************************
 * @file    nixie.c
 * @brief   Nixie tube clock main application
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


/* ==========================================================================*/
/* Private Information ======================================================*/
/* ==========================================================================*/
/* Private enumeration ------------------------------------------------------*/
/* Private structures -------------------------------------------------------*/
/* Private type definition (static allocation) ------------------------------*/
/* Private type definition from public forward declarations -----------------*/
/* Private constants --------------------------------------------------------*/
/* Private variables --------------------------------------------------------*/
/* Private function prototypes ----------------------------------------------*/
static void SystemClock_Config ( void );
static void Error_Handler ( void );

/* ***************************************************************************/
/* Public functions **********************************************************/
/* ***************************************************************************/
int main ( void )
{
    
}


/* ***************************************************************************/
/* Private functions *********************************************************/
/* ***************************************************************************/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

}

static void SystemClock_Config ( void )
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  
  /* Select HSE Oscillator as PLL source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct)!= HAL_OK)
  {
    Error_Handler();
  }

  /* Select PLL as system clock source and configure the HCLK and PCLK1 clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1)!= HAL_OK)
  {
    Error_Handler();
  }
}


static void Error_Handler ( void )
{
  /* Turn LED4 on */
  while (1)
  {
  }
}