/*
 * ADC_PROGRAM.c
 *
 *  Created on: 18 Aug 2022
 *      Author: mo7am
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "ADC_INTERFACE.h"
#include "ADC_PRIVATE.h"
#include "ADC_CONFIG.h"
void ADC_INIT (void)
{
	/*Select Max_ voltage ->AVCC*/
	CLR_BIT(ADMUX_REG ,  ADMUX_REFS1);
	SET_BIT(ADMUX_REG ,  ADMUX_REFS0);

	/* Left  Adjust */
	SET_BIT(ADMUX_REG ,  ADMUX_ADLAR);

	/* Prescaler CLK/64 */
	SET_BIT(ADCSRA_REG , ADCSRA_ADPS2);
	SET_BIT(ADCSRA_REG , ADCSRA_ADPS1);
	CLR_BIT(ADCSRA_REG , ADCSRA_ADPS0);

	/* AUTO triggerd */

	SET_BIT(ADCSRA_REG , ADCSRA_ADATE);

	/* Channel channel -> 0  */
	/*
	CLR_BIT(ADMUX_REG , ADMUX_MUX0);
	CLR_BIT(ADMUX_REG , ADMUX_MUX1);
	CLR_BIT(ADMUX_REG , ADMUX_MUX2);
	CLR_BIT(ADMUX_REG , ADMUX_MUX3);
	CLR_BIT(ADMUX_REG , ADMUX_MUX4);
	*/

	/*enable ADC*/
	SET_BIT(ADCSRA_REG ,ADCSRA_ADEN);
}


u16 ADC_GetDigitalValue(u8 Copy_u8Channel)
{
	//Clear first 5 bit in ADMUX register

	ADMUX_REG &= 0b11100000;

	ADMUX_REG |= Copy_u8Channel;

	//start conversion
	SET_BIT(ADCSRA_REG ,  ADCSRA_ADSC);

	while ((GET_BIT(ADCSRA_REG , ADCSRA_ADIF)) == 0);

	return ADC_Val ;
}






