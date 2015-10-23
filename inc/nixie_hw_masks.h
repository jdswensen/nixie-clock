/**
 ******************************************************************************
 * @file    nixie_hw_masks.h     
 * @brief   HW Mask header file for Mark's Nixie tube layout
 * @details Mark's nixie tube board uses 2 HV5522 IC
 * @author  Jake Swensen
 * @date    1/10/2015
 * @version 0.0.1
 ****************************************************************************** 
*/

#ifndef _NIXIE_HW_MASKS_H
#define _NIXIE_HW_MASKS_H

/* Includes -----------------------------------------------------------------*/

/* Preprocessor Definitions -------------------------------------------------*/
// Hour bit masks
#define HOUR_TENS_POSITION_BLANK    0x003FFFFFFFFFFFFF      // AND bit mask
#define HOUR_TENS_POSITION_ONE      0x8000000000000000      // OR bit mask
#define HOUR_TENS_POSITION_TWO      0x4000000000000000      // OR bit mask
#define HOUR_TENS_POSITION_THREE    0x2000000000000000      // OR bit mask
#define HOUR_TENS_POSITION_FOUR     0x1000000000000000      // OR bit mask
#define HOUR_TENS_POSITION_FIVE     0x0800000000000000      // OR bit mask
#define HOUR_TENS_POSITION_SIX      0x0400000000000000      // OR bit mask
#define HOUR_TENS_POSITION_SEVEN    0x0200000000000000      // OR bit mask
#define HOUR_TENS_POSITION_EIGHT    0x0100000000000000      // OR bit mask
#define HOUR_TENS_POSITION_NINE     0x0080000000000000      // OR bit mask
#define HOUR_TENS_POSITION_ZERO     0x0040000000000000      // OR bit mask

#define HOUR_ONES_POSITION_BLANK    0xFFC00FFFFFFFFFFF      // AND bit mask
#define HOUR_ONES_POSITION_ONE      0x0020000000000000      // OR bit mask
#define HOUR_ONES_POSITION_TWO      0x0010000000000000      // OR bit mask
#define HOUR_ONES_POSITION_THREE    0x0008000000000000      // OR bit mask
#define HOUR_ONES_POSITION_FOUR     0x0004000000000000      // OR bit mask
#define HOUR_ONES_POSITION_FIVE     0x0002000000000000      // OR bit mask
#define HOUR_ONES_POSITION_SIX      0x0001000000000000      // OR bit mask
#define HOUR_ONES_POSITION_SEVEN    0x0000800000000000      // OR bit mask
#define HOUR_ONES_POSITION_EIGHT    0x0000400000000000      // OR bit mask
#define HOUR_ONES_POSITION_NINE     0x0000200000000000      // OR bit mask
#define HOUR_ONES_POSITION_ZERO     0x0000100000000000      // OR bit mask

// First colon bit masks
#define COLON_1_BLANK               0xFFFFF3FFFFFFFFFF      // AND bit mask
#define COLON_1_A                   0x0000080000000000      // OR bit mask
#define COLON_1_B                   0x0000040000000000      // OR bit mask

// Minute bit masks
#define MIN_TENS_POSITION_BLANK     0xFFFFFC00FFFFFFFF      // AND bit mask
#define MIN_TENS_POSITION_ONE       0x0000020000000000      // OR bit mask
#define MIN_TENS_POSITION_TWO       0x0000010000000000      // OR bit mask
#define MIN_TENS_POSITION_THREE     0x0000008000000000      // OR bit mask
#define MIN_TENS_POSITION_FOUR      0x0000004000000000      // OR bit mask
#define MIN_TENS_POSITION_FIVE      0x0000002000000000      // OR bit mask
#define MIN_TENS_POSITION_SIX       0x0000001000000000      // OR bit mask
#define MIN_TENS_POSITION_SEVEN     0x0000000800000000      // OR bit mask
#define MIN_TENS_POSITION_EIGHT     0x0000000400000000      // OR bit mask
#define MIN_TENS_POSITION_NINE      0x0000000200000000      // OR bit mask
#define MIN_TENS_POSITION_ZERO      0x0000000100000000      // OR bit mask

#define MIN_ONES_POSITION_BLANK     0xFFFFFFFF003FFFFF      // AND bit mask
#define MIN_ONES_POSITION_ONE       0x0000000080000000      // OR bit mask
#define MIN_ONES_POSITION_TWO       0x0000000040000000      // OR bit mask
#define MIN_ONES_POSITION_THREE     0x0000000020000000      // OR bit mask
#define MIN_ONES_POSITION_FOUR      0x0000000010000000      // OR bit mask
#define MIN_ONES_POSITION_FIVE      0x0000000008000000      // OR bit mask
#define MIN_ONES_POSITION_SIX       0x0000000004000000      // OR bit mask
#define MIN_ONES_POSITION_SEVEN     0x0000000002000000      // OR bit mask
#define MIN_ONES_POSITION_EIGHT     0x0000000001000000      // OR bit mask
#define MIN_ONES_POSITION_NINE      0x0000000000800000      // OR bit mask
#define MIN_ONES_POSITION_ZERO      0x0000000000400000      // OR bit mask

// Second colon bit masks
#define COLON_2_BLANK               0xFFFFFFFFFFCFFFFF      // AND bit mask
#define COLON_2_A                   0x0000000000200000      // OR bit mask
#define COLON_2_B                   0x0000000000100000      // OR bit mask

// Seconds bit masks
#define SEC_TENS_POSITION_BLANK     0xFFFFFFFFFFF003FF      // AND bit mask
#define SEC_TENS_POSITION_ONE       0x0000000000080000      // OR bit mask
#define SEC_TENS_POSITION_TWO       0x0000000000040000      // OR bit mask
#define SEC_TENS_POSITION_THREE     0x0000000000020000      // OR bit mask
#define SEC_TENS_POSITION_FOUR      0x0000000000010000      // OR bit mask
#define SEC_TENS_POSITION_FIVE      0x0000000000008000      // OR bit mask
#define SEC_TENS_POSITION_SIX       0x0000000000004000      // OR bit mask
#define SEC_TENS_POSITION_SEVEN     0x0000000000002000      // OR bit mask
#define SEC_TENS_POSITION_EIGHT     0x0000000000001000      // OR bit mask
#define SEC_TENS_POSITION_NINE      0x0000000000000800      // OR bit mask
#define SEC_TENS_POSITION_ZERO      0x0000000000000400      // OR bit mask

#define SEC_ONES_POSITION_BLANK     0xFFFFFFFFFFFFFC00      // AND bit mask
#define SEC_ONES_POSITION_ONE       0x0000000000000200      // OR bit mask
#define SEC_ONES_POSITION_TWO       0x0000000000000100      // OR bit mask
#define SEC_ONES_POSITION_THREE     0x0000000000000080      // OR bit mask
#define SEC_ONES_POSITION_FOUR      0x0000000000000040      // OR bit mask
#define SEC_ONES_POSITION_FIVE      0x0000000000000020      // OR bit mask
#define SEC_ONES_POSITION_SIX       0x0000000000000010      // OR bit mask
#define SEC_ONES_POSITION_SEVEN     0x0000000000000008      // OR bit mask
#define SEC_ONES_POSITION_EIGHT     0x0000000000000004      // OR bit mask
#define SEC_ONES_POSITION_NINE      0x0000000000000002      // OR bit mask
#define SEC_ONES_POSITION_ZERO      0x0000000000000001      // OR bit mask

// Test bit masks
#define TEST_DIGITS_ONE     (HOUR_TENS_POSITION_ONE | HOUR_ONES_POSITION_ONE | MIN_TENS_POSITION_ONE | MIN_ONES_POSITION_ONE | SEC_TENS_POSITION_ONE | SEC_ONES_POSITION_ONE)
#define TEST_DIGITS_TWO     (HOUR_TENS_POSITION_TWO | HOUR_ONES_POSITION_TWO | MIN_TENS_POSITION_TWO | MIN_ONES_POSITION_TWO | SEC_TENS_POSITION_TWO | SEC_ONES_POSITION_TWO)
#define TEST_DIGITS_THREE   (HOUR_TENS_POSITION_THREE | HOUR_ONES_POSITION_THREE | MIN_TENS_POSITION_THREE | MIN_ONES_POSITION_THREE | SEC_TENS_POSITION_THREE | SEC_ONES_POSITION_THREE)
#define TEST_DIGITS_FOUR    (HOUR_TENS_POSITION_FOUR | HOUR_ONES_POSITION_FOUR | MIN_TENS_POSITION_FOUR | MIN_ONES_POSITION_FOUR | SEC_TENS_POSITION_FOUR | SEC_ONES_POSITION_FOUR)
#define TEST_DIGITS_FIVE    (HOUR_TENS_POSITION_FIVE | HOUR_ONES_POSITION_FIVE | MIN_TENS_POSITION_FIVE | MIN_ONES_POSITION_FIVE | SEC_TENS_POSITION_FIVE | SEC_ONES_POSITION_FIVE)
#define TEST_DIGITS_SIX     (HOUR_TENS_POSITION_SIX | HOUR_ONES_POSITION_SIX | MIN_TENS_POSITION_SIX | MIN_ONES_POSITION_SIX | SEC_TENS_POSITION_SIX | SEC_ONES_POSITION_SIX)
#define TEST_DIGITS_SEVEN   (HOUR_TENS_POSITION_SEVEN | HOUR_ONES_POSITION_SEVEN | MIN_TENS_POSITION_SEVEN | MIN_ONES_POSITION_SEVEN | SEC_TENS_POSITION_SEVEN | SEC_ONES_POSITION_SEVEN)
#define TEST_DIGITS_EIGHT   (HOUR_TENS_POSITION_EIGHT | HOUR_ONES_POSITION_EIGHT | MIN_TENS_POSITION_EIGHT | MIN_ONES_POSITION_EIGHT | SEC_TENS_POSITION_EIGHT | SEC_ONES_POSITION_EIGHT)
#define TEST_DIGITS_NINE    (HOUR_TENS_POSITION_NINE | HOUR_ONES_POSITION_NINE | MIN_TENS_POSITION_NINE | MIN_ONES_POSITION_NINE | SEC_TENS_POSITION_NINE | SEC_ONES_POSITION_NINE)
#define TEST_DIGITS_ZERO    (HOUR_TENS_POSITION_ZERO | HOUR_ONES_POSITION_ZERO | MIN_TENS_POSITION_ZERO | MIN_ONES_POSITION_ZERO | SEC_TENS_POSITION_ZERO | SEC_ONES_POSITION_ZERO)


/* ==========================================================================*/
/* Public Information =======================================================*/
/* ==========================================================================*/
/* Public enumerations ------------------------------------------------------*/

/**
 ******************************************************************************
 * @enum 
 * @brief       
 ******************************************************************************
 */
 
/* Public structures --------------------------------------------------------*/

/**
 ******************************************************************************
 * @struct 
 * @brief       
 ******************************************************************************
 */
 
/* Public type definitions --------------------------------------------------*/

/**
 ******************************************************************************
 * @typedef 
 * @brief       
 ******************************************************************************
 */
 
/* Public definitions -------------------------------------------------------*/

/**
 ******************************************************************************
 * @def 
 * @brief       
 ******************************************************************************
 */
 
/* Public constants ---------------------------------------------------------*/
/* Public variables ---------------------------------------------------------*/
/* Public function prototypes -----------------------------------------------*/

/**
 ******************************************************************************
 * @fn 
 * @brief       
 ******************************************************************************
 */

#endif
