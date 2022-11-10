/*

 * PWM_PROGRAM.c
 *
 *  Created on: 22 Aug 2022
 *      Author: mo7am
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include "PWM_CONFIG.h"
#include "PWM_INTERFACE.h"
#include "PWM_PRIVATE.h"
void PWM0_INIT(void)
{

	/* FAST PWM MODE*/

	SET_BIT(TCCR0_REG ,6);
	SET_BIT(TCCR0_REG ,3);

	/*  Non Inverting Mode */

	CLR_BIT(TCCR0_REG ,4);
	SET_BIT(TCCR0_REG ,5);

	/* Select Prescaller */

	CLR_BIT(TCCR0_REG ,2);
	SET_BIT(TCCR0_REG ,1);
	CLR_BIT(TCCR0_REG ,0);
}
void PWM_CTCValue(u8 Copy_u8Value)
{
	OCR0_REG= Copy_u8Value;
}
