/*
 * IncFile1.h
 *
 * Created: 10/7/2023 7:47:43 PM
 *  Author: Super-Magic
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include <avr/interrupt.h>
#include <stdio.h>
#include "Timer0_Private.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/Bit_Math.h"
#include "../Dio/Dio.h"

/*	timer0 clock configuration	*/
#define TIMER0_CLK_F_CPU				(1)
#define TIMER0_CLK_F_CPU_DIV_8			(2)
#define TIMER0_CLK_F_CPU_DIV_64			(3)
#define TIMER0_CLK_F_CPU_DIV_256		(4)
#define TIMER0_CLK_F_CPU_DIV_1024		(5)


/*	timer0 operation modes configuration	*/
#define TIMER0_NORMAL_MODE				(0b00000000)
#define TIMER0_CTC_MODE					(0b00001000)


/*   	PMW0  modes configuration	  */
#define PMW0_FAST_INVERTED_MODE			(0b01111000)
#define PMW0_FAST_NON_INVERTED_MODE		(0b01101000)

#define PMW0_PHASE_INVERTED_MODE		(0b01110000)
#define PMW0_PHASE_NON_INVERTED_MODE	(0b01100000)


/*  	pwm0 freq configuration	      */
#define PWM0_F_62_5_KHZ 				(1)
#define PWM0_F_7_8_KHZ					(2)
#define PWM0_F_1_KHZ					(3)
#define PWM0_F_244_HZ					(4)
#define PWM0_F_61_HZ					(5)


void timer0_init(u8 mode); // normal, CTC, PWM
void timer0_start(u8 clk);
void timer0_stop(void);

void timer0_setPreloadValue(u8 preLdVal);
u8 timer0_getCounterValue(void);
u8 timer0_getOvFlag(void);
void timer0_clearOvFlag(void);
void timer0_enableOvInterrupt(void);
void timer0_setOvClbk(void (*fPtr)(void));

void timer0_setCompareValue(u8 cmpVal);
void timer0_enableCtcInterrupt(void);
u8 timer0_getCtcFlag(void);
void timer0_clearCtcFlag(void);
void timer0_setCtcClbk(void (*fPtr)(void));

/*	     PWM0	     */
void pwm0_init(u8 mode, u8 freq);   // fast pwm, phase pwm
void pwm0_setDutyCycle(u16 dutyPercentage);


#endif /* TIMER0_H_ */