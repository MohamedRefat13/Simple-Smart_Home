/*
 * GIE_Privete.h
 *
 *  Created on: 17 Aug 2022
 *      Author: mo7am
 */

#ifndef MCAL_GIE_GIE_PRIVETE_H_
#define MCAL_GIE_GIE_PRIVETE_H_

#define GLOBAL_INTERRUPT_ENABLE   1
#define GLOBAL_INTERRUPT_DISABLE  0

#define SREG   (*(volatile u8*)(0x5F))
#define SREG_I 7

#endif /* MCAL_GIE_GIE_PRIVETE_H_ */
