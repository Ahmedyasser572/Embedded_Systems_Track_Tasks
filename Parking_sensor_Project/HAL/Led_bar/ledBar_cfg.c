/*
 * ledBar_cfg.c
 *
 * Created: 10/27/2023 8:40:09 PM
 *  Author: reBuyTech
 */ 


#include "ledBar_cfg.h"
#include "../../MCAL/Dio/Dio.h"

u8 ledBar_ledsPinsCfg[MAX_NO_LEDS][LED_PIN_NO_CFG]={
	{DIO_PORTC,DIO_PIN0},	/*	LED1	*/
	{DIO_PORTA,DIO_PIN1},	/*	LED2	*/
	{DIO_PORTA,DIO_PIN2},	/*	LED3	*/
	{DIO_PORTA,DIO_PIN3},	/*	LED4	*/
	{DIO_PORTB,DIO_PIN4},	/*	LED5	*/
	{DIO_PORTB,DIO_PIN5},	/*	LED6	*/
	{DIO_PORTB,DIO_PIN6},	/*	LED7	*/
	{DIO_PORTB,DIO_PIN7},	/*	LED8	*/
	{DIO_PORTB,DIO_PIN0},	/*	LED9	*/
	{DIO_PORTB,DIO_PIN1}	/*	LED10	*/
};