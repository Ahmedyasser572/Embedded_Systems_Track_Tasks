/******************************************
 * wdg.c
 * Created: 10/28/2023 8:04:25 PM
 *  Author: mfawzi
 *******************************************/ 
#include "wdg_private.h"
#include "../../LIB/Bit_Math.h"

void wdg_vidEnable(u8 wdgWindow)
{
	/*	enable WDG	*/
	SET_BIT(WDG_WDTCR_REG,WDG_ENABLE_BIT_NO);
	
	/*	select WDG window	*/
	WDG_WDTCR_REG |= wdgWindow;
}

void wdg_vidDisable(void)
{	
	WDG_WDTCR_REG|= (1<<WDG_ENABLE_BIT_NO)|(1<<WDG_ENABLE_OFF_BIT_NO);
	CLR_BIT(WDG_WDTCR_REG,WDG_ENABLE_BIT_NO);
}

void wdg_vidRefresh(void)
{
	asm("WDR");
}