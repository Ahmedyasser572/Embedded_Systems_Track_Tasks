/*
 * timer1.c
 *
 * Created: 10/24/2023 8:37:43 PM
 *  Author: reBuyTech
 */ 
#include "../../LIB/Std_Types.h"
#include "../../MCAL/timer1/timer1_private.h"
#include "../../MCAL/timer1/timer1.h"

void pwm1_CHA_init(u8 mode, u8 frequancy)
{
	/*	timer1 mode set	*/
	TIMER1_TCCR1A_REG |=  (mode&0x03);
	TIMER1_TCCR1B_REG |=  (mode&0x0C)<<1;
	
	/*	compare mode set (inverted/non inverted)	*/
	TIMER1_TCCR1A_REG |= (mode&0xC0);
	
	/* timer1 clock 	*/
	TIMER1_TCCR1B_REG |= frequancy;	
}

void pwm1_setTopValue(u8 mode, u16 topVal)
{
	if (
		 (mode == PWM1_CHA_FAST_INVERTED_ICR1_MODE) ||
		 (mode == PWM1_CHA_FAST_NON_INVERTED_ICR1_MODE)
	   )
	{
		TIMER1_ICR1_REG = topVal;
	}
	else if (
				 (mode == PWM1_CHA_FAST_INVERTED_OCR1A_MODE) ||
				 (mode == PWM1_CHA_FAST_NON_INVERTED_OCR1A_MODE)
			)
			{
				TIMER1_OCR1A_REG = topVal;
			}
		else
		{
			/*	do nothing	*/
		}
}

void pwm1_setDutyCycle(f32 dutyPercentage, u16 topVal)
{
	u32 loc_ocrValue=0;
	
	loc_ocrValue = (u32)(dutyPercentage*topVal)/100;
	TIMER1_OCR1A_REG = (u16) loc_ocrValue;
}