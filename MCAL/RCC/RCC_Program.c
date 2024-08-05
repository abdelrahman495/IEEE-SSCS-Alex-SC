/*
 * RCC_Program.c
 *
 *  Created on: Aug 5, 2024
 *      Author: abdelrahman
 */


#include "RCC_Interface.h"

void RCC_Init()
{
#if SYSTEM_CLOCK == RCC_HSI
	/* Enable HSI clock */
	SET_BIT(RCC->CR, 0);
	/* Wait until the HSI clock ready flag is set */
	while (!GET_BIT(RCC->CR, 1));
	/* Select SYSCLK source */
	CLR_BIT(RCC->CFGR, 0);
	CLR_BIT(RCC->CFGR, 1);

#elif SYSTEM_CLOCK == RCC_HSE
	/* Select HSE clock source */
#if HSEBYP == BYPASS_OFF
	CLR_BIT(RCC->CR, 18);
#elif HSEBYP == BYPASS_ON
	SET_BIT(RCC->CR, 18);
#endif
	/* Enable HSE clock */
	SET_BIT(RCC->CR, 16);
	/* Wait until the HSE clock ready flag is set */
	while (!GET_BIT(RCC->CR, 17));
	/* Select SYSCLK source */
	SET_BIT(RCC->CFGR, 0);
	CLR_BIT(RCC->CFGR, 1);

#elif SYSTEM_CLOCK == RCC_PLL
	/* Select PLL clock source */
#if PLL_SOURCE == PLL_HSI
	CLR_BIT(RCC->CFGR, 16);
#elif PLL_SOURCE == PLL_HSE
	SET_BIT(RCC->CFGR, 16);
#endif
	/* Enable PLL clock */
	SET_BIT(RCC->CR, 24);
	/* Wait until the PLL clock ready flag is set */
	while (!GET_BIT(RCC->CR, 25));
	/* Select SYSCLK source */
	CLR_BIT(RCC->CFGR, 0);
	SET_BIT(RCC->CFGR, 1);
#endif
	/* Check whether the clock source is chosen or not */
	while ((RCC->CFGR & (0b11 << 2)) != (RCC->CFGR & 0b11));

	/* AHB Prescaler */
	CLR_BIT(RCC->CFGR, 4);
	CLR_BIT(RCC->CFGR, 5);
	CLR_BIT(RCC->CFGR, 6);
	CLR_BIT(RCC->CFGR, 7);
	RCC->CFGR |= (AHB_PRESCALER << 4);
}

void RCC_PeripheralEnable(Peripheral_t peripheral)
{
	switch (peripheral)
	{
		/* AHB Peripherals */
		case RCC_DMA1_EN:
			SET_BIT(RCC->AHBENR, 0);
			break;

		case RCC_DMA2_EN:
			SET_BIT(RCC->AHBENR, 1);
			break;

		case RCC_SRAM_EN:
			SET_BIT(RCC->AHBENR, 2);
			break;

		case RCC_FLITF_EN:
			SET_BIT(RCC->AHBENR, 4);
			break;

		case RCC_CRC_EN:
			SET_BIT(RCC->AHBENR, 6);
			break;

		case RCC_FSMC_EN:
			SET_BIT(RCC->AHBENR, 8);
			break;

		case RCC_SDIO_EN:
			SET_BIT(RCC->AHBENR, 10);
			break;

		/* APB2 Peripherals */
		case RCC_AFIO_EN:
			SET_BIT(RCC->APB2ENR, 0);
			break;

		case RCC_IOPA_EN:
			SET_BIT(RCC->APB2ENR, 2);
			break;

		case RCC_IOPB_EN:
			SET_BIT(RCC->APB2ENR, 3);
			break;

		case RCC_IOPC_EN:
			SET_BIT(RCC->APB2ENR, 4);
			break;

		case RCC_IOPD_EN:
			SET_BIT(RCC->APB2ENR, 5);
			break;

		case RCC_IOPE_EN:
			SET_BIT(RCC->APB2ENR, 6);
			break;

		case RCC_IOPF_EN:
			SET_BIT(RCC->APB2ENR, 7);
			break;

		case RCC_IOPG_EN:
			SET_BIT(RCC->APB2ENR, 8);
			break;

		case RCC_ADC1_EN:
			SET_BIT(RCC->APB2ENR, 9);
			break;

		case RCC_ADC2_EN:
			SET_BIT(RCC->APB2ENR, 10);
			break;

		case RCC_TIM1_EN:
			SET_BIT(RCC->APB2ENR, 11);
			break;

		case RCC_SPI1_EN:
			SET_BIT(RCC->APB2ENR, 12);
			break;

		case RCC_TIM8_EN:
			SET_BIT(RCC->APB2ENR, 13);
			break;

		case RCC_USART1_EN:
			SET_BIT(RCC->APB2ENR, 14);
			break;

		case RCC_ADC3_EN:
			SET_BIT(RCC->APB2ENR, 15);
			break;

		case RCC_TIM9_EN:
			SET_BIT(RCC->APB2ENR, 19);
			break;

		case RCC_TIM10_EN:
			SET_BIT(RCC->APB2ENR, 20);
			break;

		case RCC_TIM11_EN:
			SET_BIT(RCC->APB2ENR, 21);
			break;

		/* APB1 Peripherals */
		case RCC_TIM2_EN:
			SET_BIT(RCC->APB1ENR, 0);
			break;

		case RCC_TIM3_EN:
			SET_BIT(RCC->APB1ENR, 1);
			break;

		case RCC_TIM4_EN:
			SET_BIT(RCC->APB1ENR, 2);
			break;

		case RCC_TIM5_EN:
			SET_BIT(RCC->APB1ENR, 3);
			break;

		case RCC_TIM6_EN:
			SET_BIT(RCC->APB1ENR, 4);
			break;

		case RCC_TIM7_EN:
			SET_BIT(RCC->APB1ENR, 5);
			break;

		case RCC_TIM12_EN:
			SET_BIT(RCC->APB1ENR, 6);
			break;

		case RCC_TIM13_EN:
			SET_BIT(RCC->APB1ENR, 7);
			break;

		case RCC_TIM14_EN:
			SET_BIT(RCC->APB1ENR, 8);
			break;

		case RCC_WWDG_EN:
			SET_BIT(RCC->APB1ENR, 11);
			break;

		case RCC_SPI2_EN:
			SET_BIT(RCC->APB1ENR, 14);
			break;

		case RCC_SPI3_EN:
			SET_BIT(RCC->APB1ENR, 15);
			break;

		case RCC_USART2_EN:
			SET_BIT(RCC->APB1ENR, 17);
			break;

		case RCC_USART3_EN:
			SET_BIT(RCC->APB1ENR, 18);
			break;

		case RCC_UART4_EN:
			SET_BIT(RCC->APB1ENR, 19);
			break;

		case RCC_UART5_EN:
			SET_BIT(RCC->APB1ENR, 20);
			break;

		case RCC_I2C1_EN:
			SET_BIT(RCC->APB1ENR, 21);
			break;

		case RCC_I2C2_EN:
			SET_BIT(RCC->APB1ENR, 22);
			break;

		case RCC_USB_EN:
			SET_BIT(RCC->APB1ENR, 23);
			break;

		case RCC_CAN_EN:
			SET_BIT(RCC->APB1ENR, 25);
			break;

		case RCC_BKP_EN:
			SET_BIT(RCC->APB1ENR, 27);
			break;

		case RCC_PWR_EN:
			SET_BIT(RCC->APB1ENR, 28);
			break;

		case RCC_DAC_EN:
			SET_BIT(RCC->APB1ENR, 29);
			break;

		default:
			break;
	}
}

void RCC_PeripheralDisable(Peripheral_t peripheral)
{
	switch (peripheral)
	{
		/* AHB Peripherals */
		case RCC_DMA1_EN:
			CLR_BIT(RCC->AHBENR, 0);
			break;

		case RCC_DMA2_EN:
			CLR_BIT(RCC->AHBENR, 1);
			break;

		case RCC_SRAM_EN:
			CLR_BIT(RCC->AHBENR, 2);
			break;

		case RCC_FLITF_EN:
			CLR_BIT(RCC->AHBENR, 4);
			break;

		case RCC_CRC_EN:
			CLR_BIT(RCC->AHBENR, 6);
			break;

		case RCC_FSMC_EN:
			CLR_BIT(RCC->AHBENR, 8);
			break;

		case RCC_SDIO_EN:
			CLR_BIT(RCC->AHBENR, 10);
			break;

		/* APB2 Peripherals */
		case RCC_AFIO_EN:
			CLR_BIT(RCC->APB2ENR, 0);
			break;

		case RCC_IOPA_EN:
			CLR_BIT(RCC->APB2ENR, 2);
			break;

		case RCC_IOPB_EN:
			CLR_BIT(RCC->APB2ENR, 3);
			break;

		case RCC_IOPC_EN:
			CLR_BIT(RCC->APB2ENR, 4);
			break;

		case RCC_IOPD_EN:
			CLR_BIT(RCC->APB2ENR, 5);
			break;

		case RCC_IOPE_EN:
			CLR_BIT(RCC->APB2ENR, 6);
			break;

		case RCC_IOPF_EN:
			CLR_BIT(RCC->APB2ENR, 7);
			break;

		case RCC_IOPG_EN:
			CLR_BIT(RCC->APB2ENR, 8);
			break;

		case RCC_ADC1_EN:
			CLR_BIT(RCC->APB2ENR, 9);
			break;

		case RCC_ADC2_EN:
			CLR_BIT(RCC->APB2ENR, 10);
			break;

		case RCC_TIM1_EN:
			CLR_BIT(RCC->APB2ENR, 11);
			break;

		case RCC_SPI1_EN:
			CLR_BIT(RCC->APB2ENR, 12);
			break;

		case RCC_TIM8_EN:
			CLR_BIT(RCC->APB2ENR, 13);
			break;

		case RCC_USART1_EN:
			CLR_BIT(RCC->APB2ENR, 14);
			break;

		case RCC_ADC3_EN:
			CLR_BIT(RCC->APB2ENR, 15);
			break;

		case RCC_TIM9_EN:
			CLR_BIT(RCC->APB2ENR, 19);
			break;

		case RCC_TIM10_EN:
			CLR_BIT(RCC->APB2ENR, 20);
			break;

		case RCC_TIM11_EN:
			CLR_BIT(RCC->APB2ENR, 21);
			break;

		/* APB1 Peripherals */
		case RCC_TIM2_EN:
			CLR_BIT(RCC->APB1ENR, 0);
			break;

		case RCC_TIM3_EN:
			CLR_BIT(RCC->APB1ENR, 1);
			break;

		case RCC_TIM4_EN:
			CLR_BIT(RCC->APB1ENR, 2);
			break;

		case RCC_TIM5_EN:
			CLR_BIT(RCC->APB1ENR, 3);
			break;

		case RCC_TIM6_EN:
			CLR_BIT(RCC->APB1ENR, 4);
			break;

		case RCC_TIM7_EN:
			CLR_BIT(RCC->APB1ENR, 5);
			break;

		case RCC_TIM12_EN:
			CLR_BIT(RCC->APB1ENR, 6);
			break;

		case RCC_TIM13_EN:
			CLR_BIT(RCC->APB1ENR, 7);
			break;

		case RCC_TIM14_EN:
			CLR_BIT(RCC->APB1ENR, 8);
			break;

		case RCC_WWDG_EN:
			CLR_BIT(RCC->APB1ENR, 11);
			break;

		case RCC_SPI2_EN:
			CLR_BIT(RCC->APB1ENR, 14);
			break;

		case RCC_SPI3_EN:
			CLR_BIT(RCC->APB1ENR, 15);
			break;

		case RCC_USART2_EN:
			CLR_BIT(RCC->APB1ENR, 17);
			break;

		case RCC_USART3_EN:
			CLR_BIT(RCC->APB1ENR, 18);
			break;

		case RCC_UART4_EN:
			CLR_BIT(RCC->APB1ENR, 19);
			break;

		case RCC_UART5_EN:
			CLR_BIT(RCC->APB1ENR, 20);
			break;

		case RCC_I2C1_EN:
			CLR_BIT(RCC->APB1ENR, 21);
			break;

		case RCC_I2C2_EN:
			CLR_BIT(RCC->APB1ENR, 22);
			break;

		case RCC_USB_EN:
			CLR_BIT(RCC->APB1ENR, 23);
			break;

		case RCC_CAN_EN:
			CLR_BIT(RCC->APB1ENR, 25);
			break;

		case RCC_BKP_EN:
			CLR_BIT(RCC->APB1ENR, 27);
			break;

		case RCC_PWR_EN:
			CLR_BIT(RCC->APB1ENR, 28);
			break;

		case RCC_DAC_EN:
			CLR_BIT(RCC->APB1ENR, 29);
			break;

		default:
			break;
	}
}
