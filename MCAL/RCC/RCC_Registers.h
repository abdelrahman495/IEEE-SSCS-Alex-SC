/*
 * RCC_Registers.h
 *
 *  Created on: Aug 5, 2024
 *      Author: abdelrahman
 */

#ifndef RCC_RCC_REGISTERS_H_
#define RCC_RCC_REGISTERS_H_

#define RCC_BASE_ADDR	(0x40021000)

typedef volatile struct
{
	UInt32_t CR;
	UInt32_t CFGR;
	UInt32_t CIR;
	UInt32_t APB2RSTR;
	UInt32_t APB1RSTR;
	UInt32_t AHBENR;
	UInt32_t APB2ENR;
	UInt32_t APB1ENR;
	UInt32_t BDCR;
	UInt32_t CSR;
} RCC_RegDef_t;

#define RCC				((RCC_RegDef_t *) RCC_BASE_ADDR)

#endif /* RCC_RCC_REGISTERS_H_ */
