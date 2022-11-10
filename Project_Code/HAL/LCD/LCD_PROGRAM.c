/*
 * LCD_PROGRAM.c
 *
 *  Created on: 14 Aug 2022
 *      Author: mo7am
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_INERFACE.h"
#include "LCD_INTERFACE.h"
#include  "LCD_CONFIG.h"
#include <util/delay.h>
#include<stdlib.h>
void LCD_Init(void)
{
	//all pins output
	DIO_SetPinDirection(LCD_RS_Port , LCD_RS_PIN , OUTPUT); //RS
	DIO_SetPinDirection(LCD_EN_Port , LCD_EN_PIN , OUTPUT); //EN
	//set Port as Output
	DIO_SetPortDirection(LCD_DataPort  ,0xFF);
	_delay_ms(100);
	//Set Function
	LCD_SendCommand(0b00111100);
	_delay_ms(1);
	//Display on off
	LCD_SendCommand(0b00001110);
	_delay_ms(1);
	//clear screen
	LCD_SendCommand(0b00000001);
	_delay_ms(2);
	//Entry mode set
	LCD_SendCommand(0b00000110);
	//LCD_SendCommand(0x06);
}

void LCD_SendCommand(u8 Command)
{
	// RS --> 0
	DIO_SetPinValue(LCD_RS_Port , LCD_RS_PIN , LOW);
	//R/W ->> connect it with GND

	//Send Data
	DIO_SetPortValue(LCD_DataPort ,Command );

	//Enable PIN
	DIO_SetPinValue(LCD_EN_Port , LCD_EN_PIN , HIGH);
	_delay_ms(100);
	DIO_SetPinValue(LCD_EN_Port , LCD_EN_PIN , LOW);
	_delay_ms(10);
}

void LCD_SendData(u8 Data)
{
	// RS --> 1
	DIO_SetPinValue(LCD_EN_Port , LCD_RS_PIN , HIGH);
	//R/W ->> connect it with GND

	//Send Data
	DIO_SetPortValue(LCD_DataPort , Data );

	//Enable PIN
	DIO_SetPinValue(LCD_EN_Port , LCD_EN_PIN , HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_EN_Port , LCD_EN_PIN , LOW);
	_delay_ms(5);
}

void LCD_SendNumber(u16 Number)
{
	u16 rem , rev=0 ;

	if(Number==0)
	{
		LCD_SendData(0+'0');
	}
	while (Number !=0 )
	{
		 rem =Number %10 ;
		 Number/=10;
		rev = (rev*10) +rem ;
	}

	while (rev !=0 )
	{
			 rem =rev %10 ;
			 rev/=10;
			 LCD_SendData(rem+'0');
	}
}

void LCD_SendString(u8 str[])
{
	u8 i=0;
	while(str[i]!='\0')
	{
		LCD_SendData(str[i]);
		i++;
	}
}

void LCD_GotoPosition(u8 Row , u8 Col)
{
	if(Row==1)
	{
		Col=Col-1;
		LCD_SendCommand(0x80+Col);
	}
	if(Row==2)
	{
		Col=Col-1;
		LCD_SendCommand(0xC0+Col);
	}
}

void LCD_ClearScreen(void)
{
	LCD_SendCommand(0b00000001);
}
void LCD_IntegerDisplay(s16 Data)
{
	 /* !Comment: String to hold the ascii result */
	 u8 u8LocalResult[17];
	 /* !Comment: 10 for decimal */
	 itoa(Data, u8LocalResult, 10);
	 /* !Comment: Display The Result */
	 LCD_SendString(u8LocalResult);
}
