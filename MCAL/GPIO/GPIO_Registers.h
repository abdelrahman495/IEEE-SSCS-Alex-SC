/*
 * GPIO_Registers.h
 *
 *  Created on: Aug 12, 2024
 *      Author: abdelrahman
 */

#ifndef GPIO_GPIO_REGISTERS_H_
#define GPIO_GPIO_REGISTERS_H_

#define GPIOA_BASE_ADDR		(0x40010800)
#define GPIOB_BASE_ADDR		(0x40010C00)
#define GPIOC_BASE_ADDR		(0x40011000)
#define GPIOD_BASE_ADDR		(0x40011400)

typedef volatile struct
{
	UInt32_t CRL;
	UInt32_t CRH;
	UInt32_t IDR;
	UInt32_t ODR;
	UInt32_t BSRR;
	UInt32_t BRR;
	UInt32_t LCKR;
} GPIO_RegDef_t;

#define GPIOA				((GPIO_RegDef_t *) GPIOA_BASE_ADDR)
#define GPIOB				((GPIO_RegDef_t *) GPIOB_BASE_ADDR)
#define GPIOC				((GPIO_RegDef_t *) GPIOC_BASE_ADDR)
#define GPIOD				((GPIO_RegDef_t *) GPIOD_BASE_ADDR)

#endif /* GPIO_GPIO_REGISTERS_H_ */
