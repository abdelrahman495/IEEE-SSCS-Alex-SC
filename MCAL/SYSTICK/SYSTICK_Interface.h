/*
 * SYSTICK_Interface.h
 *
 *  Created on: Aug 21, 2024
 *      Author: abdelrahman
 */

#ifndef SYSTICK_SYSTICK_INTERFACE_H_
#define SYSTICK_SYSTICK_INTERFACE_H_

#include "../../LIB/Std_Types.h"
#include "../../LIB/Bit_Math.h"

#include "SYSTICK_Registers.h"
#include "SYSTICK_Config.h"

void SYSTICK_Init(void);
void SYSTICK_DelayMilliSeconds(UInt32_t ms);
void SYSTICK_DelayMicroSeconds(UInt32_t us);
UInt32_t SYSTICK_GetRemainingTime(void);
UInt32_t SYSTICK_GetElapsedTime(void);
void SYSTICK_EnableInterrupt(void);
void SYSTICK_StartCountMillisecondsIT(UInt32_t ms, void (*ptr)(void));
void SYSTICK_StartCountMicrosecondsIT(UInt32_t us, void (*ptr)(void));

#endif /* SYSTICK_SYSTICK_INTERFACE_H_ */
