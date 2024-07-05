/*
 * _7_segment.c
 *
 * Created: 6/30/2024 4:58:13 PM
 *  Author: hoba6544
 */ 
#if 1

#include "dio.h"
#include "Std_Types.h"
#include "Bit_Math.h"
#include "dioconfig.h"
#include <util/delay.h>



int main(void)
{
	Dio_voidSetPinDirection(DIO_PORTC, DIO_PIN0, DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTC, DIO_PIN1, DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTC, DIO_PIN2, DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTC, DIO_PIN3, DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTD, DIO_PIN0, DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTD, DIO_PIN1, DIO_OUTPUT);
	
	Dio_voidSetPinDirection(DIO_PORTB, DIO_PIN0, DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTB, DIO_PIN1, DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTB, DIO_PIN2, DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);
	
	
	while(1)
	{
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_LOW);
		
		Dio_voidWriteChannel(DIO_PORTB, DIO_PIN0, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTB, DIO_PIN1, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTB, DIO_PIN2, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTB, DIO_PIN3, DIO_LOW);
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_LOW);
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_LOW);
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_LOW);
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_LOW);
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_LOW);
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_LOW);
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_LOW);
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_LOW);
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_HIGH);
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_HIGH);
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		////////////////////////////////////////////////
		////////////////////////////////////////////////
		
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_LOW);
		
		Dio_voidWriteChannel(DIO_PORTB, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTB, DIO_PIN1, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTB, DIO_PIN2, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTB, DIO_PIN3, DIO_LOW);
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_LOW);
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_LOW);
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_LOW);
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_LOW);
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_LOW);
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_LOW);
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_LOW);
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_LOW);
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_HIGH);
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_HIGH);
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_LOW);
		
		
		Dio_voidWriteChannel(DIO_PORTB, DIO_PIN0, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTB, DIO_PIN1, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTB, DIO_PIN2, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTB, DIO_PIN3, DIO_LOW);
		
		
		
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTD, DIO_PIN1, DIO_HIGH);
		
		_delay_ms(1000);
		
		
		
	}
}
#endif