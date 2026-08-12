/*
 * KeyPad.h
 *
 * Created: 9/2/2023 10:37:22 PM
 *  Author: Super-Magic
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <util/delay.h>
#include "KeyPad_Cfg.h"
#include "../../LIB/Std_Types.h"
#include "../../MCAL/Dio/Dio.h"


u8	KB_u8GetPressedKey(void);
u8	KB_u8SimpleCal(void);


#endif /* KEYPAD_H_ */