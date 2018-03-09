/********************************************************************************/
/* Author : Hend Khairy                                                         */
/* Date   : 9 March 2018                                                        */
/* Version: V01                                                                 */
/********************************************************************************/


#ifndef LCD_INT_H_
#define LCD_INT_H_

/* Description : This function shall initialize LCD 							*/
void LCD_voidInitilize(void);

/* Description : This function shall Write Command to LCD 						*/
void LCD_voidWriteCommand(u8 Copy_u8Cmd);

/* Description : This function shall Write Data to LCD 							*/
void LCD_voidWriteData(u8 Copy_u8Data);

#endif /* LCD_INT_H_ */