/*
 * RCC_Config.h
 *
 *  Created on: Aug 5, 2024
 *      Author: abdelrahman
 */

#ifndef RCC_RCC_CONFIG_H_
#define RCC_RCC_CONFIG_H_

/* USB Prescaler */
#define USB_PRESCALER_ON		(0) // PLL clock is divided by 1.5
#define USB_PRESCALER_OFF		(1)

#define USB_PRESCALER			(USB_PRESCALER_OFF)

/*****************************************************************/

/* PLL multiplication factor */
#define PLL_2					(0b0000)
#define PLL_3					(0b0001)
#define PLL_4					(0b0010)
#define PLL_5					(0b0011)
#define PLL_6					(0b0100)
#define PLL_7					(0b0101)
#define PLL_8					(0b0110)
#define PLL_9					(0b0111)
#define PLL_10					(0b1000)
#define PLL_11					(0b1001)
#define PLL_12					(0b1010)
#define PLL_13					(0b1011)
#define PLL_14					(0b1100)
#define PLL_15					(0b1101)
#define PLL_16					(0b1110)

/*Caution: The PLL output frequency must not exceed 72 MHz.*/
#define PLL_MULTIPLIER 			(PLL_2)

/*****************************************************************/

/* HSE divider for PLL entry */
#define HSE_DIVIDER_OFF			(0)
#define HSE_DIVIDER_ON			(1)

#define HSE_DIVIDER				(HSE_DIVIDER_OFF)

/*****************************************************************/

/* PLL entry clock source */
#define PLL_HSI 				(0)
#define PLL_HSE 				(1)

#define PLL_SOURCE				(PLL_HSI)

/*****************************************************************/

/* ADC prescaler */
#define ADC_2					(0b00)
#define ADC_4					(0b01)
#define ADC_6					(0b10)
#define ADC_8					(0b11)

#define ADC_PRESCALER			(ADC_2)

/*****************************************************************/

/* APB high-speed prescaler (APB2) */
#define APB2_1					(0b000)
#define APB2_2					(0b100)
#define APB2_4					(0b101)
#define APB2_8					(0b110)
#define APB2_16					(0b111)

#define APB2_PRESCALER			(APB2_1)

/*****************************************************************/

/*  APB low-speed prescaler (APB1) */
#define APB1_1					(0b000)
#define APB1_2					(0b100)
#define APB1_4					(0b101)
#define APB1_8					(0b110)
#define APB1_16					(0b111)

#define APB1_PRESCALER			(APB2_1)

/*****************************************************************/

/* AHB prescaler */
#define AHB_1 					(0b0000)
#define AHB_2 					(0b1000)
#define AHB_4 					(0b1001)
#define AHB_8 					(0b1010)
#define AHB_16 					(0b1011)
#define AHB_64 					(0b1100)
#define AHB_128 				(0b1101)
#define AHB_256 				(0b1110)
#define AHB_512 				(0b1111)

#define AHB_PRESCALER 			(AHB_1)

/*****************************************************************/

/* System clock switch */
#define RCC_HSI 				(0b00)
#define RCC_HSE 				(0b01)
#define RCC_PLL 				(0b10)

#define SYSCLK_SOURCE 			(RCC_HSI)

/*****************************************************************/

/* External high-speed clock bypass */
#define BYPASS_OFF				(0)
#define BYPASS_ON				(1)

#define HSEBYP 					(BYPASS_OFF)

/*****************************************************************/

#endif /* RCC_RCC_CONFIG_H_ */
