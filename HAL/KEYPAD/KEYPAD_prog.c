/********************************************************************************/
/* Author : Hend Khairy                                                         */
/* Date   : 10 March 2018                                                        */
/* Version: V01                                                                 */
/********************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define  F_CPU 8000000UL
#include <AVR/delay.h>

#include "DIO_int.h"

#include "KEYPAD_priv.h"
#include "KEYPAD_config.h"
#include "KEYPAD_int.h"

u16 Local_u16Status;

void KEYPAD_voidInit(void)
{
	#if KEYPAD_u8_PULL_UP == KEYPAD_u8_INTERNAL
		DIO_SetPinValue(KEYPAD_u8_ROW_1, DIO_u8_HIGH);
		DIO_SetPinValue(KEYPAD_u8_ROW_2, DIO_u8_HIGH);
		DIO_SetPinValue(KEYPAD_u8_ROW_3, DIO_u8_HIGH);
		DIO_SetPinValue(KEYPAD_u8_ROW_4, DIO_u8_HIGH);
	#endif
}
u16 KEYPAD_u16GetStatus(void)
{
	Local_u16Status=0;
	/* Apply Sequence 1*/
	DIO_SetPinValue(KEYPAD_u8_COL_1, DIO_u8_LOW);
	DIO_SetPinValue(KEYPAD_u8_COL_2, DIO_u8_HIGH);
	DIO_SetPinValue(KEYPAD_u8_COL_3, DIO_u8_HIGH);
	DIO_SetPinValue(KEYPAD_u8_COL_4, DIO_u8_HIGH);
	CheckRows(0);

	DIO_SetPinValue(KEYPAD_u8_COL_1, DIO_u8_HIGH);
	DIO_SetPinValue(KEYPAD_u8_COL_2, DIO_u8_LOW);
	DIO_SetPinValue(KEYPAD_u8_COL_3, DIO_u8_HIGH);
	DIO_SetPinValue(KEYPAD_u8_COL_4, DIO_u8_HIGH);
	CheckRows(1);

	DIO_SetPinValue(KEYPAD_u8_COL_1, DIO_u8_HIGH);
	DIO_SetPinValue(KEYPAD_u8_COL_2, DIO_u8_HIGH);
	DIO_SetPinValue(KEYPAD_u8_COL_3, DIO_u8_LOW);
	DIO_SetPinValue(KEYPAD_u8_COL_4, DIO_u8_HIGH);
	CheckRows(2);

	DIO_SetPinValue(KEYPAD_u8_COL_1, DIO_u8_HIGH);
	DIO_SetPinValue(KEYPAD_u8_COL_2, DIO_u8_HIGH);
	DIO_SetPinValue(KEYPAD_u8_COL_3, DIO_u8_HIGH);
	DIO_SetPinValue(KEYPAD_u8_COL_4, DIO_u8_LOW);
	CheckRows(3);

}
void CheckRows(u8 Copy_u8Number)
{
	if(DIO_u8GetPinValue(KEYPAD_u8_ROW_1)==DIO_u8_LOW)
	{
		SET_BIT(Local_u16Status,Copy_u8Number *4)
	}

	if(DIO_u8GetPinValue(KEYPAD_u8_ROW_2)==DIO_u8_LOW)
	{
		SET_BIT(Local_u16Status,(Copy_u8Number *4) +1)
	}

	if(DIO_u8GetPinValue(KEYPAD_u8_ROW_3)==DIO_u8_LOW)
	{
		SET_BIT(Local_u16Status,(Copy_u8Number *4) +2)
	}

	if(DIO_u8GetPinValue(KEYPAD_u8_ROW_4)==DIO_u8_LOW)
	{
		SET_BIT(Local_u16Status,(Copy_u8Number *4) +3)
	}
}