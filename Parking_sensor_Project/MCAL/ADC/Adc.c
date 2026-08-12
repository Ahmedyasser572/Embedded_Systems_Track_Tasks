/*
 * Adc.c
 *
 * Created: 9/9/2023 10:27:23 PM
 *  Author: Super-Magic
 */ 
#include "Adc.h"

void	Adc_voidInit(void)
{
	/*	1 - Vreference Vcc = 5 volt 	*/
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
	/*	2 - Pre-scaller 128			 	*/
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	/*	3 - Right Adjustment		 	*/
	CLR_BIT(ADMUX,5);
	/*	4 - ADC Enable					*/
	SET_BIT(ADCSRA,7);
	
}

u16		Adc_u16ReadChannel(u8 Channel)
{
	/*	Assign the channel			*/
	ADMUX = (ADMUX & 0b11100000 );
	ADMUX = (ADMUX |  Channel 	);
	
	/*	ADC start Conversion		*/
	SET_BIT(ADCSRA,6);
	
	/*	Polling Wait till the flag raise	*/
	while((GET_BIT(ADCSRA,4)) == 0);
	
	/*	Cleare the flag 		*/
	SET_BIT(ADCSRA,4);
	
	return	ADC;
}