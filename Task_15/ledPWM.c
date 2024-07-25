#ifndef F_CPU
#define F_CPU		16000000UL
#endif

#include "App_main.h"


void Tog_Led (void)
{
	static u16 no_of_overflow;
	no_of_overflow ++;
	
	//timer0_setPreloadValue(6);
	
	if (no_of_overflow == 1000)
	{
		Dio_voidFlipChannel(DIO_PORTC , DIO_PIN5);
		no_of_overflow = 0 ;
	}
}


int main()
{
	/*	Adc Channel 0 is Input pin (A0)	controling the light intensity */
	Dio_voidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_INPUT);
	
	pwm0_init(PMW0_FAST_NON_INVERTED_MODE , PWM0_F_62_5_KHZ);
	
	Adc_voidInit();
	
	u16 Result = 0;
	u16 Analog_mv = 0;
	
	while(1)
	{
		Result 		= 	Adc_u16ReadChannel(ADC_CHANNEL0);
		Analog_mv 	=	((Result * 5000UL)/1023);
		
		if(Analog_mv < 500)
		{
			pwm0_setDutyCycle(0);
		}
		else if((Analog_mv >= 500)	&&	(Analog_mv < 1000))
		{
			pwm0_setDutyCycle(100);
		}
		else if((Analog_mv >= 1000)	&&	(Analog_mv < 2000))
		{
			pwm0_setDutyCycle(140);
		}
		else
		{
			pwm0_setDutyCycle(255);
		}
	}
return 0;
}