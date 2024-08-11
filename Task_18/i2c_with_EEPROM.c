#define F_CPU  16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include "lcd.h"
#include "Led.h"
#include "eep24C08.h"

/* I used the I2C to send the data to An External EEPROM(eep24C08) to display the data from it on the LCD*/
int main(void)
{
	u8 counter =0;
	u8 loc_byte =0;
		
	Led_voidInit();
	eep24C08_init();
	/*	Lcd pins direction									*/
	Dio_voidSetPortDirection(DIO_PORTC,0xFF);
	Dio_voidSetPortDirection(DIO_PORTA,0xFF);
	
	/*	Lcd init											*/
	Lcd_voidInit();
	
	/*	Lcd Control Pins direction output pin (C0\2,C3,C4)	*/
	Dio_voidSetPinDirection(DIO_PORTC,DIO_PIN2,DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTC,DIO_PIN3,DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTC,DIO_PIN4,DIO_OUTPUT);
	
	Lcd_voidGoToRowCol(0,0);
	Lcd_voidWriteString("Counter:");
	
	if (eep24C08_readByte(0) != 0xFF)
	{
		counter = eep24C08_readByte(0);
	}
	while(1)
	{
		Lcd_voidGoToRowCol(1,0);	
		LCD_u8WriteINT(counter);
		_delay_ms(1000);
		counter++;
		eep24C08_writeByte(0, counter);
	}
}
