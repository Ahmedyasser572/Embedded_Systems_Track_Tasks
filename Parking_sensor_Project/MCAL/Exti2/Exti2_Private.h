/*
 * Exti2_Private.h
 *
 * Created: 9/9/2023 12:15:58 AM
 *  Author: Super-Magic
 */ 


#ifndef EXTI2_PRIVATE_H_
#define EXTI2_PRIVATE_H_

#include "../../LIB/Std_Types.h"

#define		EXTI_FALLING			0
#define		EXTI_RISING				1

#define		GICR					*((volatile u8 *)0x5B)
#define		GIFR					*((volatile u8 *)0x5A)
#define		MCUCR					*((volatile u8 *)0x55)
#define		MCUSCR					*((volatile u8 *)0x54)

void	__vector_3	(void)	__attribute__((signal,used));



#endif /* EXTI2_PRIVATE_H_ */