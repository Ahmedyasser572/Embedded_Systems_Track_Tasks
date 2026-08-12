/*
 * Lcd.h
 *
 * Created: 9/29/2023 8:18:13 PM
 *  Author: Super-Magic
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 160000000UL
#include <util/delay.h>
#include "Lcd_Cfg.h"
#include "Lcd_Private.h"
#include "../../LIB/Std_Types.h"
#include "../../MCAL/Dio/Dio.h"


void	Lcd_voidInit(void);
void	Lcd_voidWriteChar(u8 Data);
void	Lcd_voidWriteString(u8 *Str);
void	Lcd_voidSendCmd(u8 Cmd);

void	Lcd_voidGoToRowCol(u8 Row , u8 col);
void	Lcd_voidWriteCustomChar(u8 pos, u8 arr[]);
u8 LCD_u8WriteINT(u16 Copy_u16NB);


#endif /* LCD_H_ */