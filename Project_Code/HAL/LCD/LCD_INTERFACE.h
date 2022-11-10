/*
 * LCD-INTERFACE.h
 *
 *  Created on: 14 Aug 2022
 *      Author: mo7am
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

void LCD_Init(void);
void LCD_SendCommand(u8 Command);
void LCD_SendData(u8 Data);
void LCD_SendString(u8 str[]);
void LCD_GotoPosition(u8 Row , u8 Col);
void LCD_SendNumber(u16 Number);
void LCD_ClearScreen(void);
void LCD_IntegerDisplay(s16 Data);
#endif /* HAL_LCD_LCD_INTERFACE_H_ */
