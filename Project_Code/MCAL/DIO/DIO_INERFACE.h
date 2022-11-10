#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H
enum PORT
{
	PORTA = 1,
	PORTB = 2,
	PORTC = 3,
	PORTD = 4
};

enum DIRECTION
{
	INPUT  = 0,
	OUTPUT = 1
};

enum PIN
{
	PIN0 = 0 ,
	PIN1 = 1 ,
	PIN2 = 2 ,
	PIN3 = 3 ,
	PIN4 = 4 ,
	PIN5 = 5 ,
	PIN6 = 6 ,
	PIN7 = 7 
};

enum VALUE
{
	LOW  = 0,
	HIGH = 1
};

void DIO_SetPinDirection(u8 Port , u8 Pin , u8 Direction);
void DIO_SetPinValue(u8 Port , u8 Pin , u8 Value);
u8   DIO_GetPinValue(u8 Port , u8 Pin);
void DIO_SetPortDirection(u8 Port , u8 Direction);
void DIO_SetPortValue(u8 Port , u8 Value);







#endif /*DIO_INTERFACE_H*/
