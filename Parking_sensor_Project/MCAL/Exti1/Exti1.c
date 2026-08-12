/*
 * Exti1c.c
 *
 * Created: 9/8/2023 11:20:14 PM
 *  Author: Super-Magic
 */ 

#include "Exti1.h"

static void (*Exti1CallBack) (void) = NULL ;

void	Exti1_voidInit(void)
{
	#if   EXTI1_SENSE_MODE == EXTI_FALLING
	CLR_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	#elif EXTI1_SENSE_MODE == EXTI_RISING
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	#elif EXTI1_SENSE_MODE == EXTI_LOW
	CLR_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);
	#elif EXTI1_SENSE_MODE == EXTI_IOC
	SET_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);
	#else
	#error "Wrong choice of EXTI sense mode!"
	#endif
	/*	Disable the interrupt	"PIE"		*/
	CLR_BIT(GICR,7);
}

void	Exti1_voidEnableInterrupt(void)
{
	/*	Enable the interrupt	"PIE"		*/
	SET_BIT(GICR,7);
}

void	Exti1_voidDisableInterrupt(void)
{
	/*	Disable the interrupt	"PIE"		*/
	CLR_BIT(GICR,7);
}
void	Exti1_voidSetCallBack(void (*pf)(void))
{
	if (pf)
	{
		Exti1CallBack = pf ;
	}
}

void	__vector_2	(void)
{
	
	Exti1CallBack();
}