/*
 * DC_Motor.c
 *
 * Created: 10/13/2023 10:53:16 PM
 *  Author: Super-Magic
 */ 

#include "DC_Motor.h"

void dcMotor_vidInit()
{
	Dio_voidSetPinDirection(DIO_PORTC,DIO_PIN0, DIO_OUTPUT);//m1
	Dio_voidSetPinDirection(DIO_PORTC,DIO_PIN5, DIO_OUTPUT);//m2
	Dio_voidSetPinDirection(DIO_PORTC,DIO_PIN6, DIO_OUTPUT);//m3
	Dio_voidSetPinDirection(DIO_PORTC,DIO_PIN7, DIO_OUTPUT);//m4
	
	/*	stop motor	*/
	dcMotor_vidStop();
	
	pwm0_init(PMW0_FAST_NON_INVERTED_MODE,PWM0_F_62_5_KHZ);
	pwm0_setDutyCycle(0);
	
}


void dcMotor_vidSetDirection(u8 dir)
{
	if (dir == CW_DIR)
	{
		Dio_voidWriteChannel(DIO_PORTC,DIO_PIN6, DIO_HIGH);//m3 OFF
		Dio_voidWriteChannel(DIO_PORTC,DIO_PIN5, DIO_LOW);//m2 OFF
		
		Dio_voidWriteChannel(DIO_PORTC,DIO_PIN0, DIO_LOW);	//m1 ON
		Dio_voidWriteChannel(DIO_PORTC,DIO_PIN7, DIO_HIGH);//m4 ON
	}
	else if (dir == CCW_DIR)
	{
		Dio_voidWriteChannel(DIO_PORTC,DIO_PIN0, DIO_HIGH);//m1 OFF
		Dio_voidWriteChannel(DIO_PORTC,DIO_PIN7, DIO_LOW);//m4 OFF
		
		Dio_voidWriteChannel(DIO_PORTC,DIO_PIN6, DIO_LOW); //m2 ON
		Dio_voidWriteChannel(DIO_PORTC,DIO_PIN5, DIO_HIGH);//m3 ON
	}
	else
	{
		/*	return error	*/
	}
}

void dcMotor_vidStop(void)
{
	/*	stop motor	*/
	Dio_voidWriteChannel(DIO_PORTC,DIO_PIN0, DIO_HIGH);
	Dio_voidWriteChannel(DIO_PORTC,DIO_PIN6, DIO_HIGH);
	
	Dio_voidWriteChannel(DIO_PORTC,DIO_PIN5, DIO_LOW);
	Dio_voidWriteChannel(DIO_PORTC,DIO_PIN7, DIO_LOW);
}

void dcMotor_vidSetSpeed(u8 speedPercentage)
{
	pwm0_setDutyCycle(speedPercentage);
}