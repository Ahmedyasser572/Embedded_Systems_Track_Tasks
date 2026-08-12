/*
 * servoMotor.h
 *
 * Created: 10/24/2023 10:21:44 PM
 *  Author: reBuyTech
 */ 


#ifndef SERVOMOTOR_H_
#define SERVOMOTOR_H_
#include "../../LIB/Std_Types.h"

#define ANGLE_180				(0)
#define ANGLE_90				(1)
#define ANGLE_0					(2)

void servoMotor_vidInit(void);
void servoMotor_vidSetAngle(u8 angle);


#endif /* SERVOMOTOR_H_ */