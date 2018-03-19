/*
 * UART_int.h
 *
 *  Created on: Mar 11, 2018
 *      Author: Hend
 */

#ifndef UART_INT_H_
#define UART_INT_H_

/* Description	*/
void UART_voidInit(void);

void UART_voidSendByte(u8 Copy_u8Byte);

u8 UART_u8ReceiveByte(void);

void UART_voidSetCallBack(void (*Copy_ptr)(void));

u8 UART_u8ReturnDataISR(void);
void (*UART_voidCallBack) (void);

#endif /* UART_INT_H_ */
