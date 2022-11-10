/*
 * GIE_Program.c
 *
 *  Created on: 17 Aug 2022
 *      Author: mo7am
 */
#include "../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include "GIE_Privete.h"
#include "GIE_Interface.h"

void GIE_VoidGlobalInterruptControl(u8 copy_u8Control)
{
	switch (copy_u8Control)
	{
		case GLOBAL_INTERRUPT_ENABLE  : SET_BIT(SREG , SREG_I); break;
		case GLOBAL_INTERRUPT_DISABLE : CLR_BIT(SREG , SREG_I); break;
		default:           	/* Return nothing */				break;
	}
}

