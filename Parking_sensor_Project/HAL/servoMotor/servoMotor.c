/*
 * servoMotor.c
 *
 * Created: 10/24/2023 10:21:54 PM
 *  Author: reBuyTech
 */ 

#include "../../HAL/servoMotor/servoMotor_cfg.h"
#include "../../HAL/servoMotor/servoMotor.h"
#include "../../LIB/Std_Types.h"
#include "../../MCAL/timer1/timer1.h"
#include "../../MCAL/Dio/Dio.h"

void servoMotor_vidInit(void)
{
	pwm1_CHA_init(PWM_MODE,PWM_FREQUANCY);
	pwm1_setTopValue (PWM_MODE,TIMER1_50HZ_TOP);
	Dio_voidSetPinDirection(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);
}

void servoMotor_vidSetAngle(u8 angle)
{
	switch (angle)
	{
		case ANGLE_180:
		pwm1_setDutyCycle(ANGLE_180_DUTYCYCLE,TIMER1_50HZ_TOP);
		break;
		
		case ANGLE_90:
		pwm1_setDutyCycle(ANGLE_90_DUTYCYCLE,TIMER1_50HZ_TOP);
		break;
		
		case ANGLE_0:
		pwm1_setDutyCycle(ANGLE_90_DUTYCYCLE,TIMER1_50HZ_TOP);
		break;
	}
}