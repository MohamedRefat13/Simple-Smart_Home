/*
 * TIMER_PROGRAM.c
 *
 *  Created on: 21 Aug 2022
 *      Author: mo7am
 */
//#include""
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"

#include "TIMER_CONFIG.h"
#include "TIMER_INTERFACE.h"
#include "TIMER_PRIVATE.h"
#include "../GIE/GIE_Interface.h"


//Global Function

void (*TIMER_OVF)(void)=0;

 void TIMER0_INIT(void)
{
	/* Select Normal Mode */
	CLR_BIT(TCCR0_REG , 3);
	CLR_BIT(TCCR0_REG , 6);

	/* Enable Global Interrupt */
	GIE_VoidGlobalInterruptControl(GLOBAL_INTERRUPT_ENABLE);

	/*Enable overflow*/
	SET_BIT(TIMSK_REG , 0);

	/*  Select  Prescaler --> 8  */

	CLR_BIT(TCCR0_REG,0);
	SET_BIT(TCCR0_REG,1);
	CLR_BIT(TCCR0_REG,2);

	/* preload Value */
	TCNT0_REG = 192 ;
}

void TIMER_CALLBACK(void (*Overflow)(void))
{
	TIMER_OVF = Overflow ;
}


void __vector_11(void)  __attribute__((signal));
void __vector_11(void)
{
	static u16 counter = 0;
	counter++;
	if(counter == 3907)
	{
		counter = 0;
		if(TIMER_OVF != 0 )
		{
			TIMER_OVF();
		}
	}
}












































