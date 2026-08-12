/******************************************
 * wdg_private.h
 * Created: 10/28/2023 8:04:25 PM
 *  Author: mfawzi
 *******************************************/ 

#ifndef WDG_PRIVATE_H_
#define WDG_PRIVATE_H_

#include "../../LIB/Std_Types.h"

#define WDG_WDTCR_REG			(*(volatile u8*)0x41)
#define WDG_ENABLE_BIT_NO			(3)
#define WDG_ENABLE_OFF_BIT_NO		(4)

#endif /* WDG_PRIVATE_H_ */