/*
 * UART_prog.c
 *
 *  Created on: Mar 11, 2018
 *      Author: Hend
 */


#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_int.h"
#include "UART_config.h"
#include "UART_priv.h"

void (*UART_voidCallBack) (void);

void UART_voidInit(void)
{
	/* Select Transmitting & receiving			*/
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);

	/* Select 8-bit Data in the frame			*/
	CLR_BIT(UCSRB,UCSZ2);
	SET_BIT(UCSRC,UCSZ1);
	SET_BIT(UCSRC,UCSZ0);

	/* Select Asynchronous mode					*/
	CLR_BIT(UCSRC,UMSEL);

	/*  Select N Parity							*/
	CLR_BIT(UCSRC,UPM0);
	CLR_BIT(UCSRC,UPM1);

	/* Clear 1-bit Stop 						*/
	CLR_BIT(UCSRC,USBS);

	/* Clear Clock Polarity 					*/
	CLR_BIT(UCSRC,UCPOL);

	/* Select 9600 Baud Rate					*/
	UBRRH = 0 ;
	UBRRL = 51 ;

	/* Enable Interrupt							*/
	SET_BIT(UCSRB,RXCIE);
}

void UART_voidSendByte(u8 Copy_u8Byte)
{
	while( GET_BIT( UCSRA,UDRE )==0 );

	UDR = Copy_u8Byte ;
}

u8 UART_u8ReceiveByte(void)
{
	while( GET_BIT( UCSRA , RXC ) == 0 );

	return UDR;
}

u8 UART_u8ReturnDataISR(void)
{
	return UDR;
}
void UART_voidSetCallBack(void (*Copy_ptr)(void))
{
	UART_voidCallBack = Copy_ptr;
}

void __vector_13 (void) __attribute__((signal,used));

void __vector_13 (void)
{
	UART_voidCallBack();
}
