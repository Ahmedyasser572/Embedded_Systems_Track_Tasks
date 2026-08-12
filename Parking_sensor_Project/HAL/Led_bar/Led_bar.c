/*
 * Led_bar.c
 *
 * Created: 10/27/2023 7:49:36 PM
 *  Author: hoba6544
 */ 
#include "../../LIB/Std_Types.h"
#include "Led_bar.h"


void Led_barInit(void)
{
	
	Dio_voidSetPinDirection(DIO_PORTC,DIO_PIN0,DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTC,DIO_PIN1,DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTC,DIO_PIN2,DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTC,DIO_PIN3,DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTC,DIO_PIN4,DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTC,DIO_PIN5,DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTC,DIO_PIN6,DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTC,DIO_PIN7,DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTD,DIO_PIN0,DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTD,DIO_PIN1,DIO_OUTPUT);
	
}


void Led_bar10(void)
{
	Dio_voidWriteChannel(led_port0,led_1)
	
	
	
	
	
	
}