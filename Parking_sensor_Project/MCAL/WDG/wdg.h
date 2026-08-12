/******************************************
 * wdg.h
 * Created: 10/28/2023 8:04:25 PM
 *  Author: mfawzi
 *******************************************/ 
#include "../../LIB/Std_Types.h"
#ifndef WDG_H_
#define WDG_H_

#define WDGW_16_3MS			(0)
#define WDGE_32_5MS			(1)
#define WDGE_65MS			(2)
#define WDGE_130MS			(3)
#define WDGE_260MS			(4)
#define WDGE_520MS			(5)
#define WDGE_1S				(6)
#define WDGE_2_1S			(7)

void wdg_vidEnable(u8 wdgWindow);
void wdg_vidDisable(void);
void wdg_vidRefresh(void);



#endif /* WDG_H_ */