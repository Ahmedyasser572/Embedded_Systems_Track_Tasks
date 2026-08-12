/*
 * ledBar_cfg.h
 *
 * Created: 10/27/2023 8:29:22 PM
 *  Author: reBuyTech
 */ 


#ifndef LEDBAR_CFG_H_
#define LEDBAR_CFG_H_

#include "../../LIB/Std_Types.h"

#define MAX_NO_LEDS				(10)
#define LED_PIN_NO_CFG			(2)

extern u8 ledBar_ledsPinsCfg[MAX_NO_LEDS][LED_PIN_NO_CFG];


#endif /* LEDBAR_CFG_H_ */