/*
 * Exti1.h
 *
 * Created: 9/8/2023 11:20:29 PM
 *  Author: Super-Magic
 */ 


#ifndef EXTI1_H_
#define EXTI1_H_


#include "../../LIB/Bit_Math.h"


#include "Exti1_Cfg.h"
#include "Exti1_Private.h"

#ifndef  NULL
#define  NULL      (void*)  0
#endif

void	Exti1_voidInit(void);
void	Exti1_voidEnableInterrupt(void);
void	Exti1_voidDisableInterrupt(void);
void	Exti1_voidSetCallBack(void (*pf)(void));


#endif /* EXTI1_H_ */