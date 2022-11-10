#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"KEYPAD.CONFIG.h"
#include"KEYPAD.INTERFACE.h"
#include "../../MCAL/DIO/DIO_INERFACE.h"

u16 Buttons[4][4]=
{
	{'7','4','1','C'},
		{'8','5','2','0'},
			{'9','6','3','='},
				{'/','X','-','+'}
};

void KEYPAD_Init()
{
	//define rows as input //active pull up
	DIO_SetPinDirection(KEYPAD_PORT , KEYPAD_R1  ,INPUT);
	DIO_SetPinDirection(KEYPAD_PORT , KEYPAD_R2  ,INPUT);
	DIO_SetPinDirection(KEYPAD_PORT , KEYPAD_R3  ,INPUT);
	DIO_SetPinDirection(KEYPAD_PORT , KEYPAD_R4  ,INPUT);


	DIO_SetPinValue(KEYPAD_PORT , KEYPAD_R1  ,HIGH);
	DIO_SetPinValue(KEYPAD_PORT , KEYPAD_R2  ,HIGH);
	DIO_SetPinValue(KEYPAD_PORT , KEYPAD_R3  ,HIGH);
	DIO_SetPinValue(KEYPAD_PORT , KEYPAD_R4  ,HIGH);

	//define columns  as output  -> HIGH
	DIO_SetPinDirection(KEYPAD_PORT , KEYPAD_C1  ,OUTPUT);
	DIO_SetPinDirection(KEYPAD_PORT , KEYPAD_C2  ,OUTPUT);
	DIO_SetPinDirection(KEYPAD_PORT , KEYPAD_C3  ,OUTPUT);
	DIO_SetPinDirection(KEYPAD_PORT , KEYPAD_C4  ,OUTPUT);

	DIO_SetPinValue(KEYPAD_PORT , KEYPAD_C1,HIGH);
	DIO_SetPinValue(KEYPAD_PORT , KEYPAD_C2,HIGH);
	DIO_SetPinValue(KEYPAD_PORT , KEYPAD_C3,HIGH);
	DIO_SetPinValue(KEYPAD_PORT , KEYPAD_C4,HIGH);
}
 u8 KEYPAD_GetPressedKey(void)
 {
	 u8 i,j ;
	 u8 read= 1;
	 u16 index_pressed=0xFF;
	 for (i = KEYPAD_C1 ; i<=KEYPAD_C4 ; i++)
	 {
		 DIO_SetPinValue(KEYPAD_PORT , i , LOW);

		 for(j=KEYPAD_R1 ; j<=KEYPAD_R4 ; j++)
		 {

			 read = DIO_GetPinValue(KEYPAD_PORT , j);

			 if (read == LOW)
			 {

				 DIO_SetPinValue(KEYPAD_PORT , i , HIGH);

				 index_pressed=Buttons[i-4][j];
				 return index_pressed;

			 }
		 }
		 DIO_SetPinValue(KEYPAD_PORT , i , HIGH);
	 }
	 return 0xFF;
 }

