/*
 * Exti2.c
 *
 * Created: 9/9/2023 12:14:45 AM
 *  Author: Super-Magic
 */ 

#include "Exti2.h"

static void (*Exti2CallBack) (void) = NULL ;

void	Exti2_voidInit(void)
{
	#if   EXTI2_SENSE_MODE == EXTI_FALLING
	CLR_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	#elif EXTI2_SENSE_MODE == EXTI_RISING
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	#else
	#error "Wrong choice of EXTI sense mode!"
	#endif
	/*	Disable the interrupt	"PIE"		*/
	CLR_BIT(GICR,5);
}


void	Exti2_voidEnableInterrupt(void)
{
	/*	Enable the interrupt	"PIE"		*/
	SET_BIT(GICR,5);
}

void	Exti2_voidDisableInterrupt(void)
{
	/*	Disable the interrupt	"PIE"		*/
	CLR_BIT(GICR,5);
}
void	Exti2_voidSetCallBack(void (*pf)(void))
{
	if (pf)
	{
		Exti2CallBack = pf ;
	}
}

void	__vector_3	(void)
{
	
	Exti2CallBack();
}