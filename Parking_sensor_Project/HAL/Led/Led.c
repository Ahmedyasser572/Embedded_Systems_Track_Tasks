/*
 * Led.c
 *
 * Created: 8/26/2023 10:46:28 PM
 *  Author: Super-Magic
 */ 
 
#include "Led.h"

void  Led_voidOn(u8 LedPort , u8 LedPin)
{
	Dio_voidWriteChannel(LedPort,LedPin,DIO_HIGH);
}

void  Led_voidOf(u8 LedPort , u8 LedPin)
{
	Dio_voidWriteChannel(LedPort,LedPin,DIO_LOW);
}

void  Led_voidToggel(u8 LedPort , u8 LedPin)
{
	Dio_voidFlipChannel(LedPort,LedPin);
}
