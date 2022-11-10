/*
 * EXTI_PRIVATE.h
 *
 *  Created on: 17 Aug 2022
 *      Author: mo7am
 */

#ifndef MCAL_INTERRUPT_EXTI_PRIVATE_H_
#define MCAL_INTERRUPT_EXTI_PRIVATE_H_

/*
 * REGESTERS Addresses */

#define EXTI_Interrupt_Enable  1
#define EXTI_Interrupt_Disable 0

#define EXTI_SENCE_CONTROL_LOW_LEVEL      0
#define EXTI_SENCE_CONTROL_ON_CHANGE      1
#define EXTI_SENCE_CONTROL_FALLING_EDGE   2
#define EXTI_SENCE_CONTROL_RAISING_EDGE   3

#define EXTI_INT0  0
#define EXTI_INT1  1
#define EXTI_INT2  2

#define SREG   (*(volatile u8*)(0x5F))
#define GICR   (*(volatile u8*)(0x5B))
#define MCUCR  (*(volatile u8*)(0x55))
#define MCUCSR (*(volatile u8*)(0x54))

#define SREG_GIE

#define GICR_INT0     6
#define GICR_INT1     7
#define GICR_INT2     5


#define MCUCR_ISC00   0
#define MCUCR_ISC01   1
#define MCUCR_ISC10   2
#define MCUCR_ISC11   3

#define MCUCSR_ISC2   6



#endif /* MCAL_INTERRUPT_EXTI_PRIVATE_H_ */
