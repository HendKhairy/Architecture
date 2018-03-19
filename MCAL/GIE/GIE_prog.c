/*
 * GIE_prog.c
 *
 *  Created on: Mar 17, 2018
 *      Author: Hend
 */

#include "BIT_MATH.h"
#include "GIE_priv.h"
#include "GIE_int.h"

void GIE_voidEnable(void)
{
	 SET_BIT(SREG , GIE_u8_I_BIT);
}

void GIE_voidDISable(void)
{
	CLR_BIT(SREG , GIE_u8_I_BIT);
}
