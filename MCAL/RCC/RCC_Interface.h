/*
 * RCC_Interface.h
 *
 *  Created on: Aug 5, 2024
 *      Author: abdelrahman
 */

#ifndef RCC_RCC_INTERFACE_H_
#define RCC_RCC_INTERFACE_H_

#include "../../LIB/Std_Types.h"
#include "../../LIB/Bit_Math.h"

#include "RCC_Registers.h"
#include "RCC_Config.h"

typedef enum
{
	/* AHB Peripherals */
	RCC_DMA1_EN,
	RCC_DMA2_EN,
	RCC_SRAM_EN,
	RCC_FLITF_EN,
	RCC_CRC_EN,
	RCC_FSMC_EN,
	RCC_SDIO_EN,
	/* APB2 Peripherals */
	RCC_AFIO_EN,
	RCC_IOPA_EN,
	RCC_IOPB_EN,
	RCC_IOPC_EN,
	RCC_IOPD_EN,
	RCC_IOPE_EN,
	RCC_IOPF_EN,
	RCC_IOPG_EN,
	RCC_ADC1_EN,
	RCC_ADC2_EN,
	RCC_TIM1_EN,
	RCC_SPI1_EN,
	RCC_TIM8_EN,
	RCC_USART1_EN,
	RCC_ADC3_EN,
	RCC_TIM9_EN,
	RCC_TIM10_EN,
	RCC_TIM11_EN,
	/* APB1 Peripherals */
	RCC_TIM2_EN,
	RCC_TIM3_EN,
	RCC_TIM4_EN,
	RCC_TIM5_EN,
	RCC_TIM6_EN,
	RCC_TIM7_EN,
	RCC_TIM12_EN,
	RCC_TIM13_EN,
	RCC_TIM14_EN,
	RCC_WWDG_EN,
	RCC_SPI2_EN,
	RCC_SPI3_EN,
	RCC_USART2_EN,
	RCC_USART3_EN,
	RCC_UART4_EN,
	RCC_UART5_EN,
	RCC_I2C1_EN,
	RCC_I2C2_EN,
	RCC_USB_EN,
	RCC_CAN_EN,
	RCC_BKP_EN,
	RCC_PWR_EN,
	RCC_DAC_EN
} Peripheral_t;

/*
 * @brief	: Initializes the RCC driver
 * @param	: None
 * @retval	: None
 */
void RCC_Init(void);

/*
 * @brief	: Enables a peripheral's clock
 * @param	: A peripheral (of Peripheral_t data type) to enable its clock
 * @retval	: None
 */
void RCC_PeripheralEnable(Peripheral_t peripheral);

/*
 * @brief	: Disables a peripheral's clock
 * @param	: A peripheral (of Peripheral_t data type) to disable its clock
 * @retval	: None
 */
void RCC_PeripheralDisable(Peripheral_t peripheral);

#endif /* RCC_RCC_INTERFACE_H_ */
