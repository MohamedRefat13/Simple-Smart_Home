/*
 *  ADC_PRIVATE.h
 *
 *  Created on: 18 Aug 2022
 *      Author: mo7am
 */

#ifndef MCAL_ADC__ADC_PRIVATE_H_
#define MCAL_ADC__ADC_PRIVATE_H_

//Registers Initialization

#define ADMUX_REG    (*(volatile u8*)(0x27)) //ADC Multiplexer Selection Register
#define ADCSRA_REG   (*(volatile u8*)(0x26)) //ADC Control and status register

//#define ADCH_REG     (*(volatile u8*)(0x25))
//#define ADCL_REG     (*(volatile u8*)(0x24))

#define ADC_Val    (*(volatile u16*)(0x24)) //ADC right and left adjust register

/*Defining ADC ADMUX registers */
#define ADMUX_REFS1 7  //reference selection
#define ADMUX_REFS0 6  //reference selection

#define ADMUX_ADLAR 5 //left / right adjust 1 --> left      0 --> right

//channel and gain selection bits
#define ADMUX_MUX4  4
#define ADMUX_MUX3  3
#define ADMUX_MUX2  2
#define ADMUX_MUX1  1
#define ADMUX_MUX0  0


/*Defining ADC ADCSRA registers */
#define ADCSRA_ADEN  7  //enable ADC 1 --> Enable
#define ADCSRA_ADSC  6  //start conversion by writing 1 .. it returns to zero after finishing the conversion
#define ADCSRA_ADATE 5	// write  one to enable  Auto Triggering
#define ADCSRA_ADIF  4  // 1 --> after finish the conversion
#define ADCSRA_ADIE  3  //enable ADC interrupt
//3-bit --> determine the division factor (Prescaler)
#define ADCSRA_ADPS2  2
#define ADCSRA_ADPS1  1
#define ADCSRA_ADPS0  0












/*Defining ADC ADCSRA registers */
#endif /* MCAL_ADC__ADC_PRIVATE_H_ */
 
