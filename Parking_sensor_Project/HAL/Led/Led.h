/*
 * Led.h
 *
 * Created: 8/26/2023 10:46:50 PM
 *  Author: Super-Magic
 */ 

#include "../../LIB/Std_Types.h"
#include "../../MCAL/Dio/Dio.h"

#ifndef LED_H_
#define LED_H_

void  Led_voidOn(u8 LedPort , u8 LedPin);
void  Led_voidOf(u8 LedPort , u8 LedPin);
void  Led_voidToggel(u8 LedPort , u8 LedPin);



#endif /* LED_H_ */