/*
 * EXTI_PROGRAM.c
 *
 *  Created on: 17 Aug 2022
 *      Author: mo7am
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "EXTI_INTERFACE.h"
#include "EXTI_PRIVATE.h"

void (*GLOBAL_voidPTrToFunction)();
void EXTI_VoidSetInterruptControl(u8 Copy_u8INT , u8 Copy_u8Sense , u8 Copy_u8InterruptState , void (*ptr)())
{
	switch(Copy_u8INT)
	{
		case EXTI_INT1:
		{
			/*                   Sense Control            */
			if      (Copy_u8Sense == EXTI_SENCE_CONTROL_LOW_LEVEL   ) {CLR_BIT(MCUCR , MCUCR_ISC10); CLR_BIT(MCUCR , MCUCR_ISC11);}
			else if (Copy_u8Sense == EXTI_SENCE_CONTROL_ON_CHANGE   ) {SET_BIT(MCUCR , MCUCR_ISC10); CLR_BIT(MCUCR , MCUCR_ISC11);}
			else if (Copy_u8Sense == EXTI_SENCE_CONTROL_RAISING_EDGE) {CLR_BIT(MCUCR , MCUCR_ISC10); SET_BIT(MCUCR , MCUCR_ISC11);}
			else if (Copy_u8Sense == EXTI_SENCE_CONTROL_FALLING_EDGE) {SET_BIT(MCUCR , MCUCR_ISC10); SET_BIT(MCUCR , MCUCR_ISC11);}
			else                                                      {/* Do nothing */}

			/*Enable PIE (peripheral interrupt enable)*/
			if       (Copy_u8InterruptState == EXTI_Interrupt_Enable)  {SET_BIT( GICR , GICR_INT1 );}
			else if  (Copy_u8InterruptState == EXTI_Interrupt_Disable) {CLR_BIT( GICR , GICR_INT1 );}
			else 											  {/* Do nothing */}
		}
	}
	GLOBAL_voidPTrToFunction=ptr;
}



/*ISR CODE*/
void __vector_2(void) __attribute__((signal)); //telling compiler not to delete this code whether it used or not
void __vector_2(void)
{
	GLOBAL_voidPTrToFunction();
}

