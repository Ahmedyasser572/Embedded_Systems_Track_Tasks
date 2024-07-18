/*
 * adc_8leds.c
 *
 * Created: 7/18/2024 3:48:28 AM
 *  Author: hoba6544
 */ 
/*
 * adc_test.c
 *
 * Created: 6/29/2024 1:56:19 PM
 *  Author: hoba6544
 */ 
#if 1
#include "Std_Types.h"
#include "Adc.h"
#include "Bit_Math.h"
#include "dio.h"



int main(void)
{	
	Adc_voidInit();
	u16 result = 0;
	u16 analog_mv = 0;
	Dio_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_INPUT);
	
	
	Dio_voidSetPinDirection(DIO_PORTB, DIO_PIN0, DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTB, DIO_PIN1, DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTB, DIO_PIN2, DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTB, DIO_PIN4, DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTB, DIO_PIN5, DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTB, DIO_PIN6, DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTB, DIO_PIN7, DIO_OUTPUT);
	
	


	while(1)
	{
		 result =	Adc_u16ReadChannel(ADC_CHANNEL_0);
		 analog_mv =  ((result *5000UL)/1023);
		 
		if(analog_mv <= 2500 && analog_mv >= 0)
		{
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN0, DIO_HIGH);
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN1, DIO_HIGH);
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN2, DIO_HIGH);
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN3, DIO_HIGH);
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN4, DIO_LOW);
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN5, DIO_LOW);
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN6, DIO_LOW);
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN7, DIO_LOW);
			
		}
		else if(analog_mv <= 5000 && analog_mv >= 2500 )
		{
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN0, DIO_HIGH);
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN1, DIO_HIGH);
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN2, DIO_HIGH);
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN3, DIO_HIGH);
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN4, DIO_HIGH);
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN5, DIO_HIGH);
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN6, DIO_HIGH);
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN7, DIO_HIGH);
		}
		else
		{
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN0, DIO_LOW);
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN1, DIO_LOW);
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN2, DIO_LOW);
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN3, DIO_LOW);
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN4, DIO_LOW);
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN5, DIO_LOW);
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN6, DIO_LOW);
			Dio_voidWriteChannel(DIO_PORTB, DIO_PIN7, DIO_LOW);

		}
		
		
	}
}
#endif