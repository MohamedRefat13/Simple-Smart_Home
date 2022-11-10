/*
 * PWM_PRIVATE.h
 *
 *  Created on: 22 Aug 2022
 *      Author: Mohamed Refat
 */

#ifndef MCAL_PWM_PWM_PRIVATE_H_
#define MCAL_PWM_PWM_PRIVATE_H_

#define TIMSK_REG   (*(volatile u8*)(0x59))
#define TIFR_REG    (*(volatile u8*)(0x58))
#define TCCR0_REG   (*(volatile u8*)(0x53))
#define TCNT0_REG   (*(volatile u8*)(0x52))
#define OCR0_REG    (*(volatile u8*)(0x5C))



#endif /* MCAL_PWM_PWM_PRIVATE_H_ */
