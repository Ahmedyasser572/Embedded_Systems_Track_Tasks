/*
 * timer1.h
 *
 * Created: 10/24/2023 8:37:31 PM
 *  Author: reBuyTech
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

/*	B0:B3 -> WGM10:WGM13	*/
/*	B6_B7 -> COMP1A0:COMP1A1	*/
#define PWM1_CHA_FAST_INVERTED_8BIT_MODE        (0b11000101)
#define PWM1_CHA_FAST_INVERTED_9BIT_MODE		(0b11000110)	
#define PWM1_CHA_FAST_INVERTED_10BIT_MODE		(0b11000111)
#define PWM1_CHA_FAST_INVERTED_ICR1_MODE		(0b11001110)
#define PWM1_CHA_FAST_INVERTED_OCR1A_MODE		(0b11001111)

#define PWM1_CHA_FAST_NON_INVERTED_8BIT_MODE    (0b10000101)
#define PWM1_CHA_FAST_NON_INVERTED_9BIT_MODE	(0b10000110)
#define PWM1_CHA_FAST_NON_INVERTED_10BIT_MODE	(0b10000111)
#define PWM1_CHA_FAST_NON_INVERTED_ICR1_MODE	(0b10001110)
#define PWM1_CHA_FAST_NON_INVERTED_OCR1A_MODE	(0b10001111)
								
/*	timer1 frequency configuration	*/
#define TIMER1_CLK_F_CPU				(1)
#define TIMER1_CLK_F_CPU_DIV_8			(2)
#define TIMER1_CLK_F_CPU_DIV_64			(3)
#define TIMER1_CLK_F_CPU_DIV_256		(4)
#define TIMER1_CLK_F_CPU_DIV_1024		(5)							
												
/*	PWM1	*/
void pwm1_CHA_init(u8 mode, u8 timerFrequancy);
void pwm1_CHB_init(u8 mode, u8 frequancy);

void pwm1_setTopValue(u8 mode, u16 topVal);
void pwm1_setDutyCycle(f32 dutyPercentage, u16 topVal);


#endif /* TIMER1_H_ */