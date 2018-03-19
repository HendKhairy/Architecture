/*
 * EXTI_prog.c
 *
 *  Created on: Mar 17, 2018
 *      Author: Hend
 */
#include "BIT_MATH.h"

#include "EXTI_priv.h"
#include "EXTI_config.h"
#include "EXTI_int.h"

void (*EXTI_voidCallBack) (void);

void EXTI_voidInitialize(void)
{
	/*Set Mode		*/
	#if EXTI_u8_Mode == EXTI_u8_LOW_LEVEL
	 	 CLR_BIT(MCUCR, EXTI_u8_ISC0);
	 	 CLR_BIT(MCUCR, EXTI_u8_ISC1);

	#elif EXTI_u8_Mode == EXTI_u8_LOC
		 SET_BIT(MCUCR, EXTI_u8_ISC0);
		 CLR_BIT(MCUCR, EXTI_u8_ISC1);

	#elif EXTI_u8_Mode == EXTI_u8_FAL_EDGE
		 CLR_BIT(MCUCR, EXTI_u8_ISC0);
		 SET_BIT(MCUCR, EXTI_u8_ISC1);

	#else
		 SET_BIT(MCUCR, EXTI_u8_ISC0);
		 SET_BIT(MCUCR, EXTI_u8_ISC1);
	#endif
}

void EXTI_voidSetCallBack(void (*Copy_ptr)(void))
{
	EXTI_voidCallBack = Copy_ptr;

}

void EXTI_voidEnable(void)
{
	SET_BIT(GICR,EXTI_u8_BIT_INDEX);
}
void EXTI_voidDisable(void)
{
	CLR_BIT(GICR,EXTI_u8_BIT_INDEX);
}
void __vector_1 (void) __attribute__((signal,used));

void __vector_1 (void)
{
	EXTI_voidInitialize();
}
