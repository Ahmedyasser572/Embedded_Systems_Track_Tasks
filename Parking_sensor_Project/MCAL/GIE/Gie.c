/*
 * Gie.c
 *
 * Created: 9/7/2023 6:06:29 AM
 *  Author: Super-Magic
 */ 

#include "Gie.h"

void	GIE_voidEnableInterrupt(void)
{
	SET_BIT(SREG,7);
}

void	GIE_voidDisableInterrupt(void)
{
	CLR_BIT(SREG,7);
}
