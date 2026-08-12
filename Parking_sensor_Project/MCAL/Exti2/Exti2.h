/*
 * Exti2.h
 *
 * Created: 9/9/2023 12:14:59 AM
 *  Author: Super-Magic
 */ 


#ifndef EXTI2_H_
#define EXTI2_H_

#include "../../LIB/Bit_Math.h"


#include "Exti2_Cfg.h"
#include "Exti2_Private.h"

#ifndef  NULL
#define  NULL      (void*)  0
#endif

void	Exti2_voidInit(void);
void	Exti2_voidEnableInterrupt(void);
void	Exti2_voidDisableInterrupt(void);
void	Exti2_voidSetCallBack(void (*pf)(void));




#endif /* EXTI2_H_ */