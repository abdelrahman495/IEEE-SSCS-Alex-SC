/*
 * SYSTICK_Registers.h
 *
 *  Created on: Aug 21, 2024
 *      Author: abdelrahman
 */

#ifndef SYSTICK_SYSTICK_REGISTERS_H_
#define SYSTICK_SYSTICK_REGISTERS_H_

#define SYSTICK_BASE_ADDR	(0xE000E010)

typedef volatile struct
{
	UInt32_t CTRL;
	UInt32_t LOAD;
	UInt32_t VAL;
	UInt32_t CALIB;
} SYSTICK_RegDef_t;

#define SYSTICK				((SYSTICK_RegDef_t *) SYSTICK_BASE_ADDR)

#endif /* SYSTICK_SYSTICK_REGISTERS_H_ */
