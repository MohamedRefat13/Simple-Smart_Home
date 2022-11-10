/*
 * TIMER_INTERFACE.h
 *
 *  Created on: 21 Aug 2022
 *      Author: mo7am
 */

#ifndef MCAL_TIMERS_TIMER_INTERFACE_H_
#define MCAL_TIMERS_TIMER_INTERFACE_H_

void TIMER0_INIT(void);
void TIMER_CALLBACK(void (*Overflow)(void));

#endif /* MCAL_TIMERS_TIMER_INTERFACE_H_ */
