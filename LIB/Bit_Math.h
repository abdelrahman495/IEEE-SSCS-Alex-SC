/*
 * Bit_Math.h
 *
 *  Created on: Aug 5, 2024
 *      Author: abdelrahman
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define NUMBER_OF_BITS 				(8)

#define SET_BIT(reg, bit)			((reg) |= (1 << (bit)))
#define CLR_BIT(reg, bit)			((reg) &= ~(1 << (bit)))
#define TOG_BIT(reg, bit)			((reg) ^= (1 << (bit)))
#define GET_BIT(reg, bit)			(((reg) >> (bit)) & 0x01)
#define SET_BYTE(reg, value)		((reg) = (value))
#define ROT_LEFT(reg, bit)			((reg) << (bit)) | ((reg) >> (NUMBER_OF_BITS - (bit)))
#define ROT_RIGHT(reg, bit)			((reg) >> (bit)) | ((reg) << (NUMBER_OF_BITS - (bit)))

#endif /* BIT_MATH_H_ */
