/*
 * main.c
 *
 *  Created on: 23 Aug 2022
 *      Author: Mohamed Refat
 */

#include  "../LIB/STD_TYPES.h"
#include  "../LIB/BIT_MATH.h"
#include  "../HAL/LCD/LCD_INTERFACE.h"
#include "../MCAL/DIO/DIO_INERFACE.h"
#include "../MCAL/ADC/ADC_INTERFACE.h"
#include "../HAL/KEPAD/KEYPAD.INTERFACE.h"
#include <util/delay.h>

int main()
{

	/*Initialization  LED PINS*/
	DIO_SetPinDirection(PORTB , PIN6 , OUTPUT );
	DIO_SetPinDirection(PORTB , PIN7 , OUTPUT );

	/*Initialization  PWM0 PIN*/
	DIO_SetPinDirection(PORTB , PIN3 , OUTPUT);

	/*Initialization  Buzzer  PIN*/
	DIO_SetPinDirection(PORTB , PIN5 , OUTPUT);

	/* Initialization  HW peripherals */
	LCD_Init();
	KEYPAD_Init();

	/* Initialization  PWM0 */
	PWM0_INIT();

	/* password */
	u8 Pass[4]={'1','2','3','4'};

	/* i           --> counter for array of pass
	 * Pass_count  --> counter for password
	 * Press_value --> read pressed key from keypad
	 * */
	u8 i ,Press_value ,Pass_count ;

	/*Password algorithm to enter the system   */

	/* back -->  label for goto statement */
	back:
	Pass_count=0;
	LCD_ClearScreen();
	LCD_SendString("Enter Password :");
	for(i=0 ; i<4 ; i++)
	{
		/* check whether the key pressed or not
		 * if not pressed --> KEYPAD_GetPressedKey return oXFF so the program stuck at the loop
		 *  till the button get pressed
		 * */
		while(KEYPAD_GetPressedKey()==0xff);
		Press_value = KEYPAD_GetPressedKey();
		LCD_GotoPosition(2 , i+1);
		LCD_SendData('*');//Press_value);
		_delay_ms(150);
		 if(Pass[i] == Press_value)
		 {
			 Pass_count++;
		 }
	}
	while(1)
	{
		if(Pass_count==4)
		{
			LCD_ClearScreen();
			LCD_SendString("WELCOME");
			_delay_ms(1000);
			break;
		}
		else
		{
			DIO_SetPinValue(PORTB , PIN5 , HIGH );
			LCD_ClearScreen();
			LCD_SendString("TRY AGAIN");
			_delay_ms(500);
			DIO_SetPinValue(PORTB , PIN5 , LOW );
			goto back;
		}
	}
	/* Initialization  ADC peripheral */
	ADC_INIT();
	/* temp is a variable that store the temperature from LM35 */
	u16 temp=0;
	/* main system*/
	while(1)
	{
		temp = ((ADC_GetDigitalValue(channel_0)*7.9)/1023);
		LCD_GotoPosition(1 , 1);
		LCD_SendString("Temp is ");
		LCD_GotoPosition(1 , 9);
		LCD_SendString(" ");
		LCD_IntegerDisplay(temp);
		LCD_GotoPosition(1 , 13);
		LCD_SendData('C');

		if(temp > 25)
		{
			PWM_CTCValue((temp*3));
			DIO_SetPinValue(PORTB , PIN7 , HIGH );
			DIO_SetPinValue(PORTB , PIN6 , LOW );
		}
		else if(temp <= 25)
		{
			PWM_CTCValue((temp*2));
			DIO_SetPinValue(PORTB , PIN7 , LOW );
			DIO_SetPinValue(PORTB , PIN6 , HIGH );
		}
	}

}

