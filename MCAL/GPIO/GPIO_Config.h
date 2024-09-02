/*
 * GPIO_Config.h
 *
 *  Created on: Aug 12, 2024
 *      Author: abdelrahman
 */

#ifndef GPIO_GPIO_CONFIG_H_
#define GPIO_GPIO_CONFIG_H_

/* Input Modes */
#define GPIO_MODE_INPUT_ANALOG			(0b00)
#define GPIO_MODE_INPUT_FLOATING		(0b01)
#define GPIO_MODE_INPUT_PU_PD			(0b10)

/* Pull Type */
#define GPIO_PULL_UP					(0)
#define GPIO_PULL_DOWN					(1)

/* Output Modes */
#define GPIO_MODE_OUTPUT_PUSH_PULL		(0b00)
#define GPIO_MODE_OUTPUT_OPEN_DRAIN		(0b01)
#define GPIO_MODE_ALTFN_PUSH_PULL		(0b10)
#define GPIO_MODE_ALTFN_OPEN_DRAIN		(0b11)

/* Output Max Speed */
#define GPIO_SPEED_10_MHZ				(0b01)
#define GPIO_SPEED_2_MHZ				(0b10)
#define GPIO_SPEED_50_MHZ				(0b11)

#endif /* GPIO_GPIO_CONFIG_H_ */
