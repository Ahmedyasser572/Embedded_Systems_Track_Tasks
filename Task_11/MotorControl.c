/*
 * Two_Motors_control.c
 *
 * Created: 7/5/2024 6:17:47 PM
 *  Author: hoba6544
 */ 
#include <util/delay.h>
#include "Bit_Math.h"
#include "Std_Types.h"
#include "MCAL/DIO/dio.h"
#include "dio.h"
#include "dioconfig.h"


int main(void)
{
	Dio_voidSetPinDirection(DIO_PORTC, DIO_PIN0, DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTC, DIO_PIN1, DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTC, DIO_PIN2, DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTC, DIO_PIN3, DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_INPUT);
	Dio_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_INPUT);
	Dio_voidWriteChannel(DIO_PORTA, DIO_PIN0, DIO_HIGH);//pull up
	Dio_voidWriteChannel(DIO_PORTA, DIO_PIN1, DIO_HIGH);// pull up
	Dio_voidSetPinDirection(DIO_PORTA, DIO_PIN2, DIO_INPUT);// pull up
	Dio_voidWriteChannel(DIO_PORTA, DIO_PIN2, DIO_HIGH);
	u8 counter=0 ;
	u8 counter1=0;
	
while(1)	
{
	if (GET_BIT(PINA_REG,0)== 0 && counter == 0) // forward
	{
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_LOW);
		while(GET_BIT(PINA_REG,0)== 0);
		
		++counter;
	}
	
	else if (GET_BIT(PINA_REG,0)== 0 && counter == 1) //back
	{
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_LOW);
		while(GET_BIT(PINA_REG,0)== 0);
		counter = 0;
	}
	
	else if (GET_BIT(PINA_REG,1)== 0 && counter1 == 0) // Left
	{
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_HIGH);
		while(GET_BIT(PINA_REG,1)== 0);
		++counter1;
	}
	
	else if (GET_BIT(PINA_REG,1)== 0 && counter1 == 1)  // Right 
	{
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_HIGH);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_LOW);
		while(GET_BIT(PINA_REG,1)== 0);
		counter1 = 0;
	}
	
	else if (GET_BIT(PINA_REG,2)== 0) // Stops the 2 Motors
	{
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN0, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN1, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN2, DIO_LOW);
		Dio_voidWriteChannel(DIO_PORTC, DIO_PIN3, DIO_LOW);
		
		
	}
	
	
	
}
	
		
}