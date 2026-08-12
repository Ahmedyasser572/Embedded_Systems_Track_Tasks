/*
 * ledBar.h
 *
 * Created: 10/27/2023 7:34:47 PM
 *  Author: reBuyTech
 */ 


#ifndef LEDBAR_H_
#define LEDBAR_H_

#include "../../LIB/Std_Types.h"

void ledBar_init(void);
void ledBar_setStatus(u8 percentage);

#endif /* LEDBAR_H_ */