/*
 * SYSTICK_Config.h
 *
 *  Created on: Aug 21, 2024
 *      Author: abdelrahman
 */

#ifndef SYSTICK_SYSTICK_CONFIG_H_
#define SYSTICK_SYSTICK_CONFIG_H_

#define SYSTICK_AHB_DIVD8				(0)
#define SYSTICK_AHB_DIVD1				(1)

#define SYSTICK_CLOCK_SOURCE			(SYSTICK_AHB_DIVD1)

/* AHB Clock in MHz */
#define SYSTEM_CLOCK					(16)

/* Periodic or Non-Periodic Interrupt */
#define SYSTICK_INTERRUPT_PERIODIC		(0)
#define SYSTICK_INTERRUPT_NON_PERIODIC	(1)

#define SYSTICK_INTERRUPT				(SYSTICK_INTERRUPT_NON_PERIODIC)

#endif /* SYSTICK_SYSTICK_CONFIG_H_ */
