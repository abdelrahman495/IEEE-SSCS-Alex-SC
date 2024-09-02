/*
 * GPIO_Interface.h
 *
 *  Created on: Aug 12, 2024
 *      Author: abdelrahman
 */

#ifndef GPIO_GPIO_INTERFACE_H_
#define GPIO_GPIO_INTERFACE_H_

#include "../../LIB/Std_Types.h"
#include "../../LIB/Bit_Math.h"

#include "GPIO_Registers.h"
#include "GPIO_Config.h"

typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD
} GPIO_Port_t;

typedef struct
{
	GPIO_Port_t port;
	UInt8_t pin_number;
	UInt8_t mode;
	UInt8_t speed;
	UInt8_t pull_type;
} GPIO_Config_t;

void GPIO_Init(GPIO_Config_t *config);

UInt8_t GPIO_ReadPin(GPIO_Port_t port, UInt8_t pin_number);

void GPIO_WritePin(GPIO_Port_t port, UInt8_t pin_number, UInt8_t value);

#endif /* GPIO_GPIO_INTERFACE_H_ */
