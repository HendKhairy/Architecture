/*
 * EXTI_int.h
 *
 *  Created on: Mar 17, 2018
 *      Author: Hend
 */

#ifndef EXTI_INT_H_
#define EXTI_INT_H_

void EXTI_voidInitialize(void);

void EXTI_voidSetCallBack(void (*Copy_ptr)(void));

void EXTI_voidEnable(void);

void EXTI_voidDisable(void);

#endif /* EXTI_INT_H_ */
