/*
 * ADC_INTERFACE.h
 *
 *  Created on: 18 Aug 2022
 *      Author: mo7am
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#define   channel_0		0
#define   Channel_1  	1
#define   Channel_2 	2
#define   Channel_3 	3
#define   Channel_4 	4
#define   Channel_5 	5
#define   Channel_6 	6
#define   Channel_7 	7





void ADC_INIT ();

/*
 * brief: Function to set the channel and start conversion
 *
 * @para:  Copy_u8Channel   channel options:
 * 									channel_0
 * 									Channel_1
 * 									Channel_2
 * 									Channel_3
 * 									Channel_4
 * 									Channel_5
 * 									Channel_6
 * 									Channel_7
 *
 *
 * return: digital value of input signal(analog signal ) after conversion it to digital values
 *
 * */
u16 ADC_GetDigitalValue(u8 Copy_u8Channel);


#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
