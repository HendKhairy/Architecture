/*
 * EXTI_priv.h
 *
 *  Created on: Mar 17, 2018
 *      Author: Hend
 */

#ifndef EXTI_PRIV_H_
#define EXTI_PRIV_H_

#define GICR	(*((volatile u8*) 0x5B ))
#define MCUCR	(*((volatile u8*) 0x55 ))
#define GIFR	(*((volatile u8*) 0x5A ))
#define MCUCSR	(*((volatile u8*) 0x54 ))


#define EXTI_u8_BIT_INDEX	6
#define EXTI_u8_ISC0		0
#define EXTI_u8_ISC1		1



#define EXTI_u8_LOW_LEVEL	0
#define EXTI_u8_LOC      	1
#define EXTI_u8_RIS_EDGE 	2
#define EXTI_u8_FAL_EDGE    3

#endif /* EXTI_PRIV_H_ */

