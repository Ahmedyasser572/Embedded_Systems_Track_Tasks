/*
 * Exti0_Private.h
 *
 * Created: 9/7/2023 5:05:05 AM
 *  Author: Super-Magic
 */ 


#ifndef EXTI0_PRIVATE_H_
#define EXTI0_PRIVATE_H_

#include "../../LIB/Std_Types.h"

#define		EXTI_FALLING			0
#define		EXTI_RISING				1
#define		EXTI_LOW				2
#define		EXTI_IOC				3

#define		GICR					*((volatile u8 *)0x5B)
#define		GIFR					*((volatile u8 *)0x5A)
#define		MCUCR					*((volatile u8 *)0x55)
#define		MCUSCR					*((volatile u8 *)0x54)

void	__vector_1	(void)	__attribute__((signal,used));

#endif /* EXTI0_PRIVATE_H_ */