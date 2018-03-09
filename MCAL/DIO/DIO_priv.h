/* Author: Hend Khairy */
/* Date : 16 Feburary  2018 */
/* Version : V01 */

#ifndef DIO_PRIV_H
#define DIO_PRIV_H

#define DIO_u8_PORTA_START		0
#define DIO_u8_PORTA_END		7
#define DIO_u8_PORTA_SIZE		8

#define DIO_u8_PORTB_START		8
#define	DIO_u8_PORTB_END		15   
#define DIO_u8_PORTB_SIZE		8

#define DIO_u8_PORTC_START		16
#define	DIO_u8_PORTC_END		23
#define DIO_u8_PORTC_SIZE		8

#define DIO_u8_PORTD_START		24
#define	DIO_u8_PORTD_END		31
#define DIO_u8_PORTD_SIZE		8


#define DIO_u8_INPUT		0
#define DIO_u8_OUTPUT		1

#define DIO_u8_PORTA_DIRECTIONS	CONC_BIT(DIO_u8_PIN_DIR_7,DIO_u8_PIN_DIR_6,DIO_u8_PIN_DIR_5,DIO_u8_PIN_DIR_4,DIO_u8_PIN_DIR_3,DIO_u8_PIN_DIR_2,DIO_u8_PIN_DIR_1,DIO_u8_PIN_DIR_0)
#define DIO_u8_PORTB_DIRECTIONS	CONC_BIT(DIO_u8_PIN_DIR_15,DIO_u8_PIN_DIR_14,DIO_u8_PIN_DIR_13,DIO_u8_PIN_DIR_12,DIO_u8_PIN_DIR_11,DIO_u8_PIN_DIR_10,DIO_u8_PIN_DIR_9,DIO_u8_PIN_DIR_8)
#define DIO_u8_PORTC_DIRECTIONS	CONC_BIT(DIO_u8_PIN_DIR_23,DIO_u8_PIN_DIR_22,DIO_u8_PIN_DIR_21,DIO_u8_PIN_DIR_20,DIO_u8_PIN_DIR_19,DIO_u8_PIN_DIR_18,DIO_u8_PIN_DIR_17,DIO_u8_PIN_DIR_16)
#define	DIO_u8_PORTD_DIRECTIONS	CONC_BIT(DIO_u8_PIN_DIR_31,DIO_u8_PIN_DIR_30,DIO_u8_PIN_DIR_29,DIO_u8_PIN_DIR_28,DIO_u8_PIN_DIR_27,DIO_u8_PIN_DIR_26,DIO_u8_PIN_DIR_25,DIO_u8_PIN_DIR_24)

#define DDRA	*((u8*)0x3A)
#define PORTA	*((u8*)0x3B)
#define PINA	*((u8*)0x39)

#define DDRB	*((u8*)0x37)
#define PORTB	*((u8*)0x38)
#define PINB	*((u8*)0x36)

#define DDRC	*((u8*)0x34)
#define PORTC	*((u8*)0x35)
#define PINC	*((u8*)0x33)

#define DDRD	*((u8*)0x31)
#define PORTD	*((u8*)0x32)
#define PIND	*((u8*)0x30)


#endif
