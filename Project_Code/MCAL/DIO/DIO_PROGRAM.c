#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_PRIVATE.h"
#include "DIO_INERFACE.h"


//Function to set pin direction
void DIO_SetPinDirection(u8 Port , u8 Pin , u8 Direction)
{
	if(Direction==OUTPUT)
	{
		switch(Port)
		{
			case PORTA : SET_BIT(DDRA_REG , Pin); break;
			case PORTB : SET_BIT(DDRB_REG , Pin); break;
			case PORTC : SET_BIT(DDRC_REG , Pin); break;
			case PORTD : SET_BIT(DDRD_REG , Pin); break;
		}
	}
	else if (Direction==INPUT)
	{
		switch(Port)
		{
			case PORTA : CLR_BIT(DDRA_REG , Pin); break;
			case PORTB : CLR_BIT(DDRB_REG , Pin); break;
			case PORTC : CLR_BIT(DDRC_REG , Pin); break;
			case PORTD : CLR_BIT(DDRD_REG , Pin); break;
		}
	}
}

//Function to set pin value
void DIO_SetPinValue(u8 Port , u8 Pin , u8 Value)
{
	if(Value==HIGH)
	{
		switch(Port)
		{
			case PORTA : SET_BIT(PORTA_REG , Pin); break;
			case PORTB : SET_BIT(PORTB_REG , Pin); break;
			case PORTC : SET_BIT(PORTC_REG , Pin); break;
			case PORTD : SET_BIT(PORTD_REG , Pin); break;
		}
	}
	else if (Value==LOW)
	{
		switch(Port)
		{
			case PORTA : CLR_BIT(PORTA_REG , Pin); break;
			case PORTB : CLR_BIT(PORTB_REG , Pin); break;
			case PORTC : CLR_BIT(PORTC_REG , Pin); break;
			case PORTD : CLR_BIT(PORTD_REG , Pin); break;
		}
	}
}

 u8   DIO_GetPinValue(u8 Port , u8 Pin)
{
	 u8 LOC_Return;
	switch(Port)
	{

		case PORTA :  LOC_Return =  GET_BIT(PINA_REG ,Pin);break;
		case PORTB :  LOC_Return =  GET_BIT(PINB_REG ,Pin);break;
		case PORTC :  LOC_Return =  GET_BIT(PINC_REG ,Pin);break;
		case PORTD :  LOC_Return =  GET_BIT(PIND_REG ,Pin);break;
	}
	return LOC_Return ;
}


 void DIO_SetPortDirection(u8 Port , u8 Direction)
 {
 	switch( Port )
 		{
			case PORTA : DDRA_REG = Direction ;  break;
			case PORTB : DDRB_REG = Direction ;  break;
			case PORTC : DDRC_REG = Direction ;  break;
			case PORTD : DDRD_REG = Direction ;  break;
 		}
 }


 void DIO_SetPortValue(u8 Port , u8 Value)
 {
 	switch( Port )
 		{
 		case PORTA : PORTA_REG = Value ;  break;
 		case PORTB : PORTB_REG = Value ;  break;
 		case PORTC : PORTC_REG = Value ;  break;
 		case PORTD : PORTD_REG = Value ;  break;

 		}
 }

