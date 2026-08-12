/*
 * timer1_private.h
 *
 * Created: 10/24/2023 8:37:17 PM
 *  Author: reBuyTech
 */ 


#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_


#define	TIMER1_TCCR1A_REG		(*(volatile u8*)0x4F)
#define	TIMER1_TCCR1B_REG		(*(volatile u8*)0x4E)
#define	TIMER1_TCNT1_REG		(*(volatile u16*)0x4C)
#define	TIMER1_OCR1A_REG		(*(volatile u16*)0x4A)
#define	TIMER1_OCR1B_REG		(*(volatile u16*)0x48)
#define	TIMER1_ICR1_REG			(*(volatile u16*)0x46)

#endif /* TIMER1_PRIVATE_H_ */