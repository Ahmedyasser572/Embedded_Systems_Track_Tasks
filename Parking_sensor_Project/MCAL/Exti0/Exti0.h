/*
 * Exti0.h
 *
 * Created: 9/7/2023 4:59:00 AM
 *  Author: Super-Magic
 */ 


#ifndef EXTI0_H_
#define EXTI0_H_

#include "../../LIB/Bit_Math.h"

#include "Exti0_Cfg.h"
#include "Exti0_Private.h"

#ifndef  NULL
#define  NULL      (void*)  0
#endif

void	Exti0_voidInit(void);
void	Exti0_voidEnableInterrupt(void);
void	Exti0_voidDisableInterrupt(void);
void	Exti0_voidSetCallBack(void (*pf)(void));

#endif /* EXTI0_H_ */