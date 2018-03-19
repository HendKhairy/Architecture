/********************************************************************************/
/* Author : Hend Khairy                                                         */
/* Date   : 10 March 2018                                                        */
/* Version: V01                                                                 */
/********************************************************************************/

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

/* keypad Pins Configuration 														*/

#define KEYPAD_u8_ROW_1		DIO_u8_PIN_0
#define KEYPAD_u8_ROW_2		DIO_u8_PIN_8
#define KEYPAD_u8_ROW_3		DIO_u8_PIN_16
#define KEYPAD_u8_ROW_4		DIO_u8_PIN_24

#define KEYPAD_u8_COL_1		DIO_u8_PIN_1
#define KEYPAD_u8_COL_2		DIO_u8_PIN_9
#define KEYPAD_u8_COL_3		DIO_u8_PIN_17
#define KEYPAD_u8_COL_4		DIO_u8_PIN_25

/* Range : KEYPAD_u8_EXTERNAL
		   KEYPAD_u8_INTERNAL*/
#define KEYPAD_u8_PULL_UP	KEYPAD_u8_INTERNAL

#endif /* LCD_CONFIG_H_ */