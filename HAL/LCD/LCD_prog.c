/********************************************************************************/
/* Author : Hend Khairy                                                         */
/* Date   : 9 March 2018                                                        */
/* Version: V01                                                                 */
/********************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define F_CPU 8000000UL
#include <AVR/delay.h>

#include "DIO_int.h"

#include "LCD_config.h"
#include "LCD_priv.h"
#include "LCD_int.h"

/* Description : This function shall initialize LCD 							*/
void LCD_voidInitilize(void)
{
	/* Wait for more than 30ms													*/
	_delay_ms(35);
	
	/* Function Set LCD_voidWriteCommand 										*/
	LCD_voidWriteCommand(0b00111000);
	/* Wait for more than 39 us 												*/
	_delay_ms(1);

	/* Display ON/OFF LCD_voidWriteCommand 										*/
	LCD_voidWriteCommand(0b00001100);
	
	/* Wait for more than 39 us 												*/
	_delay_ms(1);

	/* Display Clear LCD_voidWriteCommand 										*/
	LCD_voidWriteCommand(0b00000001);

	/* Wait for more than 1.53 us 												*/
	_delay_ms(2);

	/* Entry Mode Set LCD_voidWriteCommand 										*/
	LCD_voidWriteCommand(0b00000110);

	/*	Reset Enable 															*/
	DIO_SetPinValue(LCD_u8_PIN_E,DIO_u8_LOW);


	
}

void LCD_voidExcute(u8 Copy_u8DataCmd)
{
	/* Rw=0																		*/
	DIO_SetPinValue(LCD_u8_PIN_RW, DIO_u8_LOW);
	
	/* Out the Command variable to the Command lines 							*/
	/*	LCD_u8_PIN_0															*/
	if(GET_BIT(Copy_u8DataCmd,0))
	{
		DIO_SetPinValue(LCD_u8_PIN_0,DIO_u8_HIGH);
	}
	else
	{
		DIO_SetPinValue(LCD_u8_PIN_0,DIO_u8_LOW);
	}

	/*	LCD_u8_PIN_1															*/
	if(GET_BIT(Copy_u8DataCmd,1))
	{
		DIO_SetPinValue(LCD_u8_PIN_1,DIO_u8_HIGH);
	}
	else
	{
		DIO_SetPinValue(LCD_u8_PIN_1,DIO_u8_LOW);
	}

	/*	LCD_u8_PIN_2															*/
	if(GET_BIT(Copy_u8DataCmd,2))
	{
		DIO_SetPinValue(LCD_u8_PIN_2,DIO_u8_HIGH);
	}
	else
	{
		DIO_SetPinValue(LCD_u8_PIN_2,DIO_u8_LOW);
	}
	
	/*	LCD_u8_PIN_3															*/
	if(GET_BIT(Copy_u8DataCmd,3))
	{
		DIO_SetPinValue(LCD_u8_PIN_3,DIO_u8_HIGH);
	}
	else
	{
		DIO_SetPinValue(LCD_u8_PIN_3,DIO_u8_LOW);
	}

	/*	LCD_u8_PIN_4															*/
	if(GET_BIT(Copy_u8DataCmd,4))
	{
		DIO_SetPinValue(LCD_u8_PIN_4,DIO_u8_HIGH);
	}
	else
	{
		DIO_SetPinValue(LCD_u8_PIN_4,DIO_u8_LOW);
	}

	/*	LCD_u8_PIN_5															*/
	if(GET_BIT(Copy_u8DataCmd,5))
	{
		DIO_SetPinValue(LCD_u8_PIN_5,DIO_u8_HIGH);
	}
	else
	{
		DIO_SetPinValue(LCD_u8_PIN_5,DIO_u8_LOW);
	}

	/*	LCD_u8_PIN_6															*/
	if(GET_BIT(Copy_u8DataCmd,6))
	{
		DIO_SetPinValue(LCD_u8_PIN_6,DIO_u8_HIGH);
	}
	else
	{
		DIO_SetPinValue(LCD_u8_PIN_6,DIO_u8_LOW);
	}
	
	/*	LCD_u8_PIN_7															*/
	if(GET_BIT(Copy_u8DataCmd,7))
	{
		DIO_SetPinValue(LCD_u8_PIN_7,DIO_u8_HIGH);
	}
	else
	{
		DIO_SetPinValue(LCD_u8_PIN_7,DIO_u8_LOW);
	}
	/* E=Pulse																	*/

	DIO_SetPinValue(LCD_u8_PIN_E,DIO_u8_HIGH);
	_delay_us(1);
	DIO_SetPinValue(LCD_u8_PIN_E,DIO_u8_LOW);
	/* To finish the cuurent task 												*/
	_delay_ms(2);

}


/* Description : This function shall Write Command to LCD 						*/
void LCD_voidWriteCommand(u8 Copy_u8Cmd)
{
	/* RS=0*/
	DIO_SetPinValue(LCD_u8_PIN_RS, DIO_u8_LOW);
	/* Call Excute*/
	LCD_voidExcute(Copy_u8Cmd);
}

/* Description : This function shall Write Data to LCD 							*/
void LCD_voidWriteData(u8 Copy_u8Data)
{
	/* RS=1																		*/
	DIO_SetPinValue(LCD_u8_PIN_RS, DIO_u8_HIGH);
	/* Call Excute 																*/
	LCD_voidExcute(Copy_u8Data);
}

