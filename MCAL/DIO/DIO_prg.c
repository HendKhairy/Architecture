
/* Author: Sarah Diaa */
/* Date : 16 Feburary  2018 */
/* Version : V01 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include"DIO_config.h"
#include"DIO_priv.h"
#include"DIO_int.h"

/*	Descriptive : Initiate PINS direction	*/
void DIO_voidInitialize(void)
{
	DDRA = DIO_u8_PORTA_DIRECTIONS;
	DDRB = DIO_u8_PORTB_DIRECTIONS;
	DDRC = DIO_u8_PORTC_DIRECTIONS;
	DDRD = DIO_u8_PORTD_DIRECTIONS;
}

/*	Descriptive: this function to set the pin value to high or low	*/
void DIO_SetPinValue(u8 Copy_u8PinNum,u8 Copy_u8PinValue)
{
	/* Find port A pins*/
	if ( (Copy_u8PinNum >= DIO_u8_PORTA_START) && (Copy_u8PinNum <= DIO_u8_PORTA_END) )
	{
		/* Get valid range for port A*/
		//Copy_u8PinNum = Copy_u8PinNum - 
		
		if(Copy_u8PinValue == DIO_u8_HIGH)
		{
			SET_BIT(PORTA,Copy_u8PinNum);
		}
		else
		{
			CLR_BIT(PORTA,Copy_u8PinNum);
		}
		
		
	}
	
	
	/* Find port B pins*/
	else if ( (Copy_u8PinNum >= DIO_u8_PORTB_START) && (Copy_u8PinNum <= DIO_u8_PORTB_END) )
	{
		/* Get valid range for port B pins*/
		Copy_u8PinNum = Copy_u8PinNum - DIO_u8_PORTA_SIZE;
		
		
		if(Copy_u8PinValue == DIO_u8_HIGH)
		{
			SET_BIT(PORTB,Copy_u8PinNum);
		}
		else
		{
			CLR_BIT(PORTB,Copy_u8PinNum);
		}
		
		
	}
	
	
	/* Find port C pins*/
	else if ( (Copy_u8PinNum >= DIO_u8_PORTC_START) && (Copy_u8PinNum <= DIO_u8_PORTC_END) )
	{
		/* Get valid range for port C*/
		Copy_u8PinNum = Copy_u8PinNum - (DIO_u8_PORTA_SIZE +DIO_u8_PORTB_SIZE);
		
		if(Copy_u8PinValue == DIO_u8_HIGH)
		{
			SET_BIT(PORTC,Copy_u8PinNum);
		}
		else
		{
			CLR_BIT(PORTC,Copy_u8PinNum);
		}
		
		
	}
	
	
	/* Find port D pins*/
	else if ( (Copy_u8PinNum >= DIO_u8_PORTD_START) && (Copy_u8PinNum <= DIO_u8_PORTD_END) )
	{
		/* Get valid range for port D*/
		Copy_u8PinNum = Copy_u8PinNum - (DIO_u8_PORTA_SIZE +DIO_u8_PORTB_SIZE+DIO_u8_PORTC_SIZE);
		
		if(Copy_u8PinValue == DIO_u8_HIGH)
		{
			SET_BIT(PORTD,Copy_u8PinNum);
		}
		else
		{
			CLR_BIT(PORTD,Copy_u8PinNum);
		}
		
		
	}
	
}

u8 DIO_u8GETPinValue(u8 Copy_u8PinNum)
{
	u8 Copy_u8PinValue;
	
	/* Find port A pins*/
	if ( (Copy_u8PinNum >= DIO_u8_PORTA_START) && (Copy_u8PinNum <= DIO_u8_PORTA_END) )
	{
		/* Get valid range for port A*/
		//Copy_u8PinNum = Copy_u8PinNum -

		Copy_u8PinValue = GET_BIT(PINA,Copy_u8PinNum);

		return Copy_u8PinValue;
	}


	/* Find port B pins*/
	else if ( (Copy_u8PinNum >= DIO_u8_PORTB_START) && (Copy_u8PinNum <= DIO_u8_PORTB_END) )
	{
		/* Get valid range for port B pins*/
		Copy_u8PinNum = Copy_u8PinNum - DIO_u8_PORTA_SIZE;

		Copy_u8PinValue = GET_BIT(PINB,Copy_u8PinNum);

		return Copy_u8PinValue;
	}


	/* Find port C pins*/
	else if ( (Copy_u8PinNum >= DIO_u8_PORTC_START) && (Copy_u8PinNum <= DIO_u8_PORTC_END) )
	{
		/* Get valid range for port C*/
		Copy_u8PinNum = Copy_u8PinNum - (DIO_u8_PORTA_SIZE +DIO_u8_PORTB_SIZE);

		Copy_u8PinValue = GET_BIT(PINC,Copy_u8PinNum);
		return Copy_u8PinValue;
	}


	/* Find port D pins*/
	else if ( (Copy_u8PinNum >= DIO_u8_PORTD_START) && (Copy_u8PinNum <= DIO_u8_PORTD_END) )
	{
		/* Get valid range for port D*/
		Copy_u8PinNum = Copy_u8PinNum - (DIO_u8_PORTA_SIZE +DIO_u8_PORTB_SIZE+DIO_u8_PORTC_SIZE);

		Copy_u8PinValue = GET_BIT(PIND,Copy_u8PinNum);
		return Copy_u8PinValue;

	}
}
