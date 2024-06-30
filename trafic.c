#include "dio.h"
#include "Std_Types.h"
#include "Bit_Math.h"
#include "dioconfig.h"
#include <util/delay.h>


int main(void)
{
	
	Dio_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTA, DIO_PIN1, DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTA, DIO_PIN2, DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTA, DIO_PIN3, DIO_OUTPUT);
	
	
	while(1)
	
	{
									 
		Dio_voidWriteChannel(DIO_PORTA, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTA, DIO_PIN1, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTA, DIO_PIN2, DIO_LOW);
		
		_delay_ms(15000);
		
		Dio_voidWriteChannel(DIO_PORTA, DIO_PIN0, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTA, DIO_PIN1, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTA, DIO_PIN2, DIO_LOW);
		
		_delay_ms(5000);
		
		Dio_voidWriteChannel(DIO_PORTA, DIO_PIN2, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTA, DIO_PIN1, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTA, DIO_PIN0, DIO_LOW);
		
		_delay_ms(10000);
		
	}
	
	
	
}