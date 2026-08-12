/*
 * servoMotor_cfg.h
 *
 * Created: 10/24/2023 10:36:02 PM
 *  Author: reBuyTech
 */ 


#ifndef SERVOMOTOR_CFG_H_
#define SERVOMOTOR_CFG_H_

#define PWM_MODE					PWM1_CHA_FAST_NON_INVERTED_ICR1_MODE
#define PWM_FREQUANCY				TIMER1_CLK_F_CPU_DIV_64
#define TIMER1_50HZ_TOP				(4999)

#define ANGLE_180_DUTYCYCLE					(2.6)
#define ANGLE_90_DUTYCYCLE					(12)
#define ANGLE_0_DUTYCYCLE					(7)



#endif /* SERVOMOTOR_CFG_H_ */