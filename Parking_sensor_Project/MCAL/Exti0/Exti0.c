/*
 * Exti0.c
 *
 * Created: 9/7/2023 4:58:19 AM
 *  Author: Super-Magic
 */ 

#include "Exti0.h"

static void (*Exti0CallBack) (void) = NULL ;

void	Exti0_voidInit(void)
{
	#if   EXTI0_SENSE_MODE == EXTI_FALLING
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
	#elif EXTI0_SENSE_MODE == EXTI_RISING
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
	#elif EXTI0_SENSE_MODE == EXTI_LOW
		CLR_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
	#elif EXTI0_SENSE_MODE == EXTI_IOC
		SET_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
	#else 
		#error "Wrong choice of EXTI sense mode!"
	#endif
	/*	Disable the interrupt	"PIE"		*/
	CLR_BIT(GICR,6);
}

void	Exti0_voidEnableInterrupt(void)
{
	/*	Enable the interrupt	"PIE"		*/
	SET_BIT(GICR,6);
}

void	Exti0_voidDisableInterrupt(void)
{
	/*	Disable the interrupt	"PIE"		*/
	CLR_BIT(GICR,6);
}
void	Exti0_voidSetCallBack(void (*pf)(void))
{
	if (pf)
	{
		Exti0CallBack = pf ;
	}
}

void	__vector_1	(void)
{
	Exti0CallBack();
}