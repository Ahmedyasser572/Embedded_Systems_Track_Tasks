/*
 * ledBar.c
 *
 * Created: 10/27/2023 7:35:01 PM
 *  Author: reBuyTech
 */ 

#include "../../MCAL/Dio/Dio.h"
#include "ledBar_cfg.h"

void ledBar_init(void)
{
	u8 i=0;
	for (i=0; i<MAX_NO_LEDS; i++)
	{
		Dio_voidSetPinDirection(ledBar_ledsPinsCfg[i][0],ledBar_ledsPinsCfg[i][1], DIO_OUTPUT);
	}
}

void ledBar_setStatus(u8 percentage)
{
	u16 onLeds = percentage/10;
	u8 i=0, j=0;
	
	/*	turn ON Leds	*/
	for (i=0; i<(u16)onLeds; i++)
	{
		Dio_voidWriteChannel(ledBar_ledsPinsCfg[i][0],ledBar_ledsPinsCfg[i][1],DIO_HIGH);
	}
	
	/*	turn Off Leds	*/
	for (j=onLeds; j< MAX_NO_LEDS; j++)
	{
		Dio_voidWriteChannel(ledBar_ledsPinsCfg[j][0],ledBar_ledsPinsCfg[j][1],DIO_LOW);
	}	
}