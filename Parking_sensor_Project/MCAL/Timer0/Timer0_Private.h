/*
 * Timer0_Private.h
 *
 * Created: 10/7/2023 7:48:20 PM
 *  Author: Super-Magic
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define		REG_TCCR0		*((volatile u8 *)0x53)
#define		REG_TCNT0		*((volatile u8 *)0x52)
#define		REG_OCR0		*((volatile u8 *)0x5C)
#define		REG_TIMSK		*((volatile u8 *)0x59)
#define		REG_TIFR		*((volatile u8 *)0x58)

#define TIMER0_CLOCK_SELECT_CLEAR_MASK		(0xF8)   // F8 = 1111 1000
#define TIMER0_TOP_VALUE					(255)

#define TIMER0_OVF_BIT_NO					(0)
#define TIMER0_CTCF_BIT_NO					(1)

#define TIMER0_OV_INTERRUPT_ENABLE_BIT_NO	(0)
#define TIMER0_CTC_INTERRUPT_ENABLE_BIT_NO  (1)

#endif /* TIMER0_PRIVATE_H_ */