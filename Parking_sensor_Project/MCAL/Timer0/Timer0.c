/*
 * Timer0.c
 *
 * Created: 10/7/2023 7:47:35 PM
 *  Author: Super-Magic
 */ 

#include "Timer0.h"

void (*ovClbkPtr)(void) = NULL;
void (*ctcClbkPtr)(void) = NULL;

void timer0_init(u8 mode)
{
	REG_TCCR0 |= mode;
}

void timer0_start(u8 clk)
{
	REG_TCCR0 &= TIMER0_CLOCK_SELECT_CLEAR_MASK;
	REG_TCCR0 |= clk ;
}

void timer0_stop(void)
{
	REG_TCCR0 &= TIMER0_CLOCK_SELECT_CLEAR_MASK;
}

void timer0_setPreloadValue(u8 preLdVal)
{
	REG_TCNT0 = preLdVal ;
}

u8 timer0_getCounterValue(void)
{
	return (REG_TCNT0);
}

u8 timer0_getOvFlag(void)
{
	return(GET_BIT( REG_TIFR , TIMER0_OVF_BIT_NO ));
}
void timer0_clearOvFlag(void)
{
	SET_BIT ( REG_TIFR , TIMER0_OVF_BIT_NO );
}

/********************************* Ov_Interrupt *********************************/

void timer0_enableOvInterrupt(void)
{
	SET_BIT(REG_TIMSK , TIMER0_OV_INTERRUPT_ENABLE_BIT_NO );
}

void timer0_setOvClbk(void (*fPtr)(void))
{
	ovClbkPtr = fPtr;
}

/*********************************** Ctc_Mode ************************************/


void timer0_setCompareValue(u8 cmpVal)
{
	REG_OCR0 = cmpVal;
}

void timer0_enableCtcInterrupt(void)
{
	SET_BIT(REG_TIMSK,TIMER0_CTC_INTERRUPT_ENABLE_BIT_NO);
}

u8 timer0_getCtcFlag(void)
{
	return (GET_BIT(REG_TIFR,TIMER0_CTCF_BIT_NO));
}

void timer0_clearCtcFlag(void)
{
	SET_BIT(REG_TIFR,TIMER0_CTCF_BIT_NO);
}

void timer0_setCtcClbk(void (*fPtr)(void))
{
	ctcClbkPtr = fPtr;
}


/********************************* ISR_Ov_Interrupt *********************************/


ISR(TIMER0_OVF_vect)
{
	if (ovClbkPtr != NULL)
	{
		ovClbkPtr();
	}
}

/********************************* ISR_Ctc_Interrupt ********************************/

ISR(TIMER0_COMP_vect)
{
	if (ctcClbkPtr != NULL)
	{
		ctcClbkPtr();
	}
	
}

/*********************************** pWM0 ************************************/

void pwm0_init(u8 mode, u8 freq)
{
	Dio_voidSetPinDirection(DIO_PORTB , DIO_PIN3 , DIO_OUTPUT);
	
	REG_TCCR0 |= mode;
	
	REG_TCCR0 |= freq ;
}

void pwm0_setDutyCycle(u16 dutyPercentage )
 {
	u16 loc_ocrValue = 0;
	
	if (dutyPercentage <= 100)
	{
		loc_ocrValue = (dutyPercentage * TIMER0_TOP_VALUE) / 100;
		REG_OCR0 = (u8) loc_ocrValue;
	}
	else 
	{
		REG_OCR0 = TIMER0_TOP_VALUE;
	}
}
