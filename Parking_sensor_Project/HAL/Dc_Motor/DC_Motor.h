/*
 * DC_Motor.h
 *
 * Created: 10/13/2023 10:53:39 PM
 *  Author: Super-Magic
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "../../MCAL/Dio/Dio.h"
#include "../../MCAL/Timer0/Timer0.h"

#define CW_DIR			(1)
#define CCW_DIR			(0)

void dcMotor_vidInit();
void dcMotor_vidSetDirection(u8 dir);
void dcMotor_vidStop(void);
void dcMotor_vidSetSpeed(u8 speedPercentage);



#endif /* DC_MOTOR_H_ */