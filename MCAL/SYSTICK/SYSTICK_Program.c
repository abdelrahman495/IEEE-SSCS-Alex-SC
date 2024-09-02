/*
 * SYSTICK_Program.c
 *
 *  Created on: Aug 21, 2024
 *      Author: abdelrahman
 */


#include "SYSTICK_Interface.h"

void (*SYSTICK_callback)(void) = NULL;

void SYSTICK_Init(void)
{
#if SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD1
	SYSTICK->CTRL |= (1 << 2);
#elif SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD8
	SYSTICK->CTRL &= ~(1 << 2);
#endif
}

void SYSTICK_DelayMilliSeconds(UInt32_t ms)
{
	/* Optional: Ensure that the value which will be written into the reload value register is not greater that 0xFFFFFF.
		 * If it is, do the delay on multiple steps. */

	/* Value of Reload register */
#if SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD1
	SYSTICK->LOAD = SYSTEM_CLOCK * ms * 1000 - 1;
#elif SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD8
	SYSTICK->LOAD = SYSTEM_CLOCK / 8 * ms * 1000 - 1;
#endif
	/* Start the counter */
	SYSTICK->CTRL |= (1 << 0);
	/* Wait until counter flag is set */
	while (!GET_BIT(SYSTICK->CTRL, 16));
	/* Stop the counter */
	SYSTICK->CTRL &= ~(1 << 0);
}

void SYSTICK_DelayMicroSeconds(UInt32_t us)
{
	/* Optional: Ensure that the value which will be written into the reload value register is not greater that 0xFFFFFF.
	 * If it is, do the delay on multiple steps. */

	/* Value of Reload register */
#if SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD1
	SYSTICK->LOAD = SYSTEM_CLOCK * us - 1;
#elif SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD8
	SYSTICK->LOAD = SYSTEM_CLOCK / 8 * us - 1;
#endif
	/* Start the counter */
	SYSTICK->CTRL |= (1 << 0);
	/* Wait until counter flag is set */
	while (!GET_BIT(SYSTICK->CTRL, 16));
	/* Stop the counter */
	SYSTICK->CTRL &= ~(1 << 0);
}

UInt32_t SYSTICK_GetRemainingTime(void)
{
	UInt32_t remaining_time = 0;
	UInt32_t current_val = SYSTICK->VAL;

#if SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD1
	remaining_time = (current_val + 1) / SYSTEM_CLOCK;
#elif SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD8
	remaining_time = (current_val + 1) / (SYSTEM_CLOCK / 8);
#endif

	return remaining_time;
}

UInt32_t SYSTICK_GetElapsedTime(void)
{
	UInt32_t elapsed_time = 0;
	UInt32_t load_val = SYSTICK->LOAD;
	UInt32_t current_val = SYSTICK->VAL;

#if SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD1
	elapsed_time = (load_val - current_val) / SYSTEM_CLOCK;
#elif SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD8
	elapsed_time = (load_val - current_val) / (SYSTEM_CLOCK / 8);
#endif

	return elapsed_time;
}

void SYSTICK_EnableInterrupt(void)
{
	SYSTICK->CTRL |= (1 << 1);
}

void SYSTICK_StartCountMillisecondsIT(UInt32_t ms, void (*ptr)(void))
{
	SYSTICK_callback = ptr;
	/* Value of Reload register */
#if SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD1
	SYSTICK->LOAD = SYSTEM_CLOCK * ms * 1000;
#elif SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD8
	SYSTICK->LOAD = SYSTEM_CLOCK / 8 * ms * 1000;
#endif
	/* Start the counter */
	SYSTICK->CTRL |= (1 << 0);
}

void SYSTICK_StartCountMicrosecondsIT(UInt32_t us, void (*ptr)(void))
{
	SYSTICK_callback = ptr;
	/* Value of Reload register */
#if SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD1
	SYSTICK->LOAD = SYSTEM_CLOCK * us;
#elif SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIVD8
	SYSTICK->LOAD = SYSTEM_CLOCK / 8 * us;
#endif
	/* Start the counter */
	SYSTICK->CTRL |= (1 << 0);
}

void SysTick_Handler(void)
{
	SYSTICK_callback();
#if SYSTICK_INTERRUPT == SYSTICK_INTERRUPT_NON_PERIODIC
	/* Stop the counter */
	SYSTICK->CTRL &= ~(1 << 0);
	/* Disable the interrupt */
	SYSTICK->CTRL &= ~(1 << 1);
#endif
}
