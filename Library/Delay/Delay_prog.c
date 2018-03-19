/*
 * Delay_prog.c
 *
 *  Created on: Feb 23, 2018
 *      Author: Hend
 */

#include"STD_TYPES.h"
#include"Delay_int.h"
#include"Delay_priv.h"

//#define DDRA			*((u8*)0x3A)
#define PORTA			*((u8*)0x3B)
#define ITERATION_START 0

void voidDelayms(u32 Copy_u32Time)
{
	u32 Local_u8xTimes;
	u32 Local_u32Iteration;
	//PORTA=0x01;
	Local_u8xTimes=(Copy_u32Time-EQUATION_TIME-(2*CONTEXT_SWITCH))/(TIME_OF_1LOOP + Time_Period );

	//PORTA=0x00;
	for(Local_u32Iteration=0 ; Local_u32Iteration < Local_u8xTimes ; Local_u32Iteration++)
	{
		asm("NOP");
	}


	//PORTA=0x01;
	//PORTA=0x00;
}
