/*
 * EXTI_INTERFACE.h
 *
 *  Created on: 17 Aug 2022
 *      Author: mo7am
 */

#ifndef MCAL_INTERRUPT_EXTI_INTERFACE_H_
#define MCAL_INTERRUPT_EXTI_INTERFACE_H_

#define EXTI_Interrupt_Enable  1
#define EXTI_Interrupt_Disable 0

#define EXTI_SENCE_CONTROL_LOW_LEVEL      0
#define EXTI_SENCE_CONTROL_ON_CHANGE      1
#define EXTI_SENCE_CONTROL_FALLING_EDGE   2
#define EXTI_SENCE_CONTROL_RAISING_EDGE   3

#define EXTI_INT0  0
#define EXTI_INT1  1
#define EXTI_INT2  2

#define SREG_GIE

#define GICR_INT0     6
#define GICR_INT1     7
#define GICR_INT2     5


#define MCUCR_ISC00   0
#define MCUCR_ISC01   1
#define MCUCR_ISC10   2
#define MCUCR_ISC11   3

#define MCUCSR_ISC2   6
/*
 * brief : set sense control to specific external interrupt and enable or disable it
 *@para:  Copy_u8INT External interrupt options :
 * 										EXTI_INT0
 *										EXTI_INT1
 *										EXTI_INT2
 *
 * @para: Copy_u8Sence select sense control options:
		 * 									EXTI_SENCE_CONTROL_LOW_LEVEL
		 *									EXTI_SENCE_CONTROL_ON_CHANGE
		 *									EXTI_SENCE_CONTROL_FALLING_EDGE
		 *									EXTI_SENCE_CONTROL_RAISING_EDGE
 *
 * @para: Copy_u8InterruptState enable  or disable options:
					 * 					      EXTI_Interrupt_Enable
					 *					      EXTI_Interrupt_Disable
 *    return : none
 *
 * */
void EXTI_VoidSetInterruptControl(u8 Copy_u8INT , u8 Copy_u8Sense , u8 Copy_u8InterruptState , void (*ptr)());


#endif /* MCAL_INTERRUPT_EXTI_INTERFACE_H_ */
