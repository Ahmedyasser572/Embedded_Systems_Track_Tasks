/*
 * Lcd_Cfg.h
 *
 * Created: 8/29/2023 9:31:20 PM
 *  Author: Super-Magic
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define		LCD_CONTROL_PORT		DIO_PORTC
#define		LCD_RS					DIO_PIN2
#define		LCD_RW					DIO_PIN3
#define		LCD_EN					DIO_PIN4

#define		LCD_DATA_PORT			DIO_PORTA
#define		LCD_D4					DIO_PIN4
#define		LCD_D5					DIO_PIN5
#define		LCD_D6					DIO_PIN6
#define		LCD_D7					DIO_PIN7


#define		LCD_MODE				LCD_4_BIT_MODE

#define     LCD_ROW1                0
#define     LCD_ROW2                1



#endif /* LCD_CFG_H_ */