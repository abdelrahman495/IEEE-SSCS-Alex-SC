/*
 * GPIO_Program.c
 *
 *  Created on: Aug 12, 2024
 *      Author: abdelrahman
 */


#include "GPIO_Interface.h"

void GPIO_Init(GPIO_Config_t *config)
{
	GPIO_RegDef_t *gpiox = NULL;

	switch (config->port)
	{
		case PORTA:
			gpiox = GPIOA;
			break;

		case PORTB:
			gpiox = GPIOB;
			break;

		case PORTC:
			gpiox = GPIOC;
			break;

		case PORTD:
			gpiox = GPIOD;
			break;
	}

	if (config->pin_number < 8)
	{
		/* Mode Bits */
		/* Input Modes */
		if (config->mode < 3)
		{
			gpiox->CRL &= ~(0b11 << (4 * config->pin_number));
			if (config->pull_type == GPIO_PULL_DOWN)
			{
				gpiox->ODR &= ~(1 << config->pin_number);
			}
			else if (config->pull_type == GPIO_PULL_UP)
			{
				gpiox->ODR |= (1 << config->pin_number);
			}
		}
		/* Output Modes */
		else
		{
			gpiox->CRL &= ~(0b11 << (4 * config->pin_number));
			gpiox->CRL |= (config->speed << (4 * config->pin_number));
		}
		/* Configuration Bits */
		gpiox->CRL &= ~(0b11 << (4 * config->pin_number + 2));
		gpiox->CRL |= (config->mode << (4 * config->pin_number + 2));
	}
	else
	{
		/* Mode Bits */
		/* Input Modes */
		if (config->mode < 3)
		{
			gpiox->CRH &= ~(0b11 << (4 * (config->pin_number - 8)));
			if (config->pull_type == GPIO_PULL_DOWN)
			{
				gpiox->ODR &= ~(1 << config->pin_number);
			}
			else if (config->pull_type == GPIO_PULL_UP)
			{
				gpiox->ODR |= (1 << config->pin_number);
			}
		}
		/* Output Modes */
		else
		{
			gpiox->CRH &= ~(0b11 << (4 * (config->pin_number - 8)));
			gpiox->CRH |= (config->speed << (4 * (config->pin_number - 8)));
		}
		/* Configuration Bits */
		gpiox->CRH &= ~(0b11 << (4 * (config->pin_number - 8) + 2));
		gpiox->CRH |= (config->mode << (4 * (config->pin_number - 8) + 2));
	}
}

UInt8_t GPIO_ReadPin(GPIO_Port_t port, UInt8_t pin_number)
{
	GPIO_RegDef_t *gpiox = NULL;
	UInt8_t value = 0;

	switch (port)
	{
		case PORTA:
			gpiox = GPIOA;
			break;

		case PORTB:
			gpiox = GPIOB;
			break;

		case PORTC:
			gpiox = GPIOC;
			break;

		case PORTD:
			gpiox = GPIOD;
			break;
	}

	value = (gpiox->IDR >> pin_number) & 0x01;

	return value;
}

void GPIO_WritePin(GPIO_Port_t port, UInt8_t pin_number, UInt8_t value)
{
	GPIO_RegDef_t *gpiox = NULL;

	switch (port)
	{
		case PORTA:
			gpiox = GPIOA;
			break;

		case PORTB:
			gpiox = GPIOB;
			break;

		case PORTC:
			gpiox = GPIOC;
			break;

		case PORTD:
			gpiox = GPIOD;
			break;
	}

	if (1 == value)
	{
		gpiox->BSRR = (1 << pin_number);
	}
	else
	{
		gpiox->BRR = (1 << pin_number);
	}
}
