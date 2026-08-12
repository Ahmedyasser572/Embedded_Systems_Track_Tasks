/*
 * PushButtonSwitch.h
 *
 * Created: 8/29/2023 6:47:43 PM
 *  Author: Super-Magic
 */ 


#ifndef PUSHBUTTONSWITCH_H_
#define PUSHBUTTONSWITCH_H_

#include "../../LIB/Std_Types.h"
#include "../../MCAL/Dio/Dio.h"

void PushButtonSwitch_voiodInit(u8 PortId,u8 PinId);
u8 PushButtonSwitch_u8Status (u8 PortId,u8 PinId);


#endif /* PUSHBUTTONSWITCH_H_ */