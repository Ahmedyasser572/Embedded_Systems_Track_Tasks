/*
 * CFile1.c
 *
 * Created: 8/29/2023 9:30:11 PM
 *  Author: Super-Magic
 */ 

#include "Lcd.h"

u16 Private_u16Power(u8 Copy_u8Op1, u8 Copy_u8Op2);
void	Lcd_voidInit(void)
{
	#if		LCD_MODE	==		LCD_8_BIT_MODE
	/*	Wait for more than 30 msec							*/
	_delay_ms(35);
	/*	Function Set Cmd 8bit, 2 lines display, font 5x7	*/
	Lcd_voidSendCmd(0b00111000);
	/*	Wait for more than 39 usec							*/
	_delay_ms(1);
	/*	Display ON/OFF control Display ON Cursor Off		*/
	Lcd_voidSendCmd(0b00001100);
	/*	Wait for more than 39 usec							*/
	_delay_ms(1);
	/*	Clear Display										*/
	Lcd_voidSendCmd(0b00000001);
	/*	Wait for more than 1.53 msec						*/
	_delay_ms(2);
	/*	Entery mode	Increase the cursor and shift is off	*/
	Lcd_voidSendCmd(0b00000110);
	/*	Wait for more than 1.53 msec						*/
	_delay_ms(2);
	#elif	LCD_MODE	==		LCD_4_BIT_MODE
	///*	Wait for more than 30 msec							*/
	//_delay_ms(20);
	///*	Function Set CmdLcd_voidSendCmd(0b00100000); 8bit, 2 lines display, font 5x7	*/
	//Lcd_voidSendCmd(0b00100000);
	//Lcd_voidSendCmd(0b00100000);
	//Lcd_voidSendCmd(0b10000000);
	///*	Wait for more than 39 usec							*/
	//_delay_ms(5);
	///*	Display ON/OFF control Display ON Cursor Off		*/
	//Lcd_voidSendCmd(0b00000000);
	//Lcd_voidSendCmd(0b11000000);
	///*	Wait for more than 39 usec							*/
	//_delay_us(100);
	///*	Clear Display										*/
	//Lcd_voidSendCmd(0b00000000);
	//Lcd_voidSendCmd(0b00010000);
	///*	Wait for more than 1.53 msec						*/
	//_delay_ms(2);
	///*	Entry mode	Increase the cursor and shift is off	*/
	//Lcd_voidSendCmd(0b00000000);
	//Lcd_voidSendCmd(0b01100000);
	//Lcd_voidGoToRowCol(LCD_ROW1,0);
	///*	Wait for more than 1.53 msec						*/
	//_delay_ms(2);
	
	_delay_ms(20);

	Lcd_voidSendCmd(0x03);
	_delay_ms(5);
	Lcd_voidSendCmd(0x03);
	_delay_us(100);
	Lcd_voidSendCmd(0x03);    
	Lcd_voidSendCmd(0x02);	  
	Lcd_voidSendCmd(0x28);	  
	Lcd_voidSendCmd(0x0C);	  
	Lcd_voidGoToRowCol(LCD_ROW1,0);
	#else
	#error	"Wrong choice of LCD mode!"
	#endif
	
}

void	Lcd_voidWriteChar(u8 Data)
{
	#if		LCD_MODE	==		LCD_8_BIT_MODE
	/*	RS	= 1	(Data)			*/
	Dio_voidWriteChannel(LCD_CONTROL_PORT,LCD_RS,DIO_HIGH);
	/*	RW	= 0	(Write)			*/
	Dio_voidWriteChannel(LCD_CONTROL_PORT,LCD_RW,DIO_LOW);
	/*	Send Data on the Bus	*/
	Dio_voidWritePort(LCD_DATA_PORT,Data);
	/*	Enable (Latch)			*/
	Dio_voidWriteChannel(LCD_CONTROL_PORT,LCD_EN,DIO_HIGH);
	_delay_ms(2);
	Dio_voidWriteChannel(LCD_CONTROL_PORT,LCD_EN,DIO_LOW);
	_delay_ms(2);
	#elif	LCD_MODE	==		LCD_4_BIT_MODE
	/*	RS	= 1	(Data)			*/
	Dio_voidWriteChannel(LCD_CONTROL_PORT,LCD_RS,DIO_HIGH);
	/*	RW	= 0	(Write)			*/
	Dio_voidWriteChannel(LCD_CONTROL_PORT,LCD_RW,DIO_LOW);
	/*	Send Data on the Most siginficant 4 bits	*/
	//Dio_voidWritePort(LCD_DATA_PORT,(Data<<4));
	Dio_voidWriteChannel(LCD_DATA_PORT,LCD_D4,(GET_BIT(Data,4)));
	Dio_voidWriteChannel(LCD_DATA_PORT,LCD_D5,(GET_BIT(Data,5)));
	Dio_voidWriteChannel(LCD_DATA_PORT,LCD_D6,(GET_BIT(Data,6)));
	Dio_voidWriteChannel(LCD_DATA_PORT,LCD_D7,(GET_BIT(Data,7)));
	/*	Enable (Latch)			*/
	Dio_voidWriteChannel(LCD_CONTROL_PORT,LCD_EN,DIO_HIGH);
	_delay_ms(2);
	Dio_voidWriteChannel(LCD_CONTROL_PORT,LCD_EN,DIO_LOW);
	_delay_ms(2);
	/*	Send Data on the Least siginficant 4 bits	*/
	//Dio_voidWritePort(LCD_DATA_PORT,(Data&0b11110000));
	Dio_voidWriteChannel(LCD_DATA_PORT,LCD_D4,(GET_BIT(Data,0)));
	Dio_voidWriteChannel(LCD_DATA_PORT,LCD_D5,(GET_BIT(Data,1)));
	Dio_voidWriteChannel(LCD_DATA_PORT,LCD_D6,(GET_BIT(Data,2)));
	Dio_voidWriteChannel(LCD_DATA_PORT,LCD_D7,(GET_BIT(Data,3)));
	/*	Enable (Latch)			*/
	Dio_voidWriteChannel(LCD_CONTROL_PORT,LCD_EN,DIO_HIGH);
	_delay_ms(2);
	Dio_voidWriteChannel(LCD_CONTROL_PORT,LCD_EN,DIO_LOW);
	_delay_ms(2);
	#else
	#error	"Wrong choice of LCD mode!"
	#endif
}

void	Lcd_voidWriteString(u8 *Str)
{
	u8 i = 0 ;
	while(Str[i] != '\0')
	{
		Lcd_voidWriteChar(Str[i]);
		i++;
	}
}

void	Lcd_voidSendCmd(u8 Cmd)
{
	#if		LCD_MODE	==		LCD_8_BIT_MODE
	/*	RS	= 0	(Cmd)			*/
	Dio_voidWriteChannel(LCD_CONTROL_PORT,LCD_RS,DIO_LOW);
	/*	RW	= 0	(Write)			*/
	Dio_voidWriteChannel(LCD_CONTROL_PORT,LCD_RW,DIO_LOW);
	/*	Send Data on the Bus	*/
	Dio_voidWritePort(LCD_DATA_PORT,Cmd);
	/*	Enable (Latch)			*/
	Dio_voidWriteChannel(LCD_CONTROL_PORT,LCD_EN,DIO_HIGH);
	_delay_ms(2);
	Dio_voidWriteChannel(LCD_CONTROL_PORT,LCD_EN,DIO_LOW);
	_delay_ms(2);
	#elif	LCD_MODE	==		LCD_4_BIT_MODE
	/*	RS	= 0	(Cmd)			*/
	Dio_voidWriteChannel(LCD_CONTROL_PORT,LCD_RS,DIO_LOW);
	/*	RW	= 0	(Write)			*/
	Dio_voidWriteChannel(LCD_CONTROL_PORT,LCD_RW,DIO_LOW);
	/*	Send Cmd 4 bits Most significant on the Bus	*/
	//Dio_voidWritePort(LCD_DATA_PORT,(Cmd<<4));
	Dio_voidWriteChannel(LCD_DATA_PORT,LCD_D4,(GET_BIT(Cmd,4)));
	Dio_voidWriteChannel(LCD_DATA_PORT,LCD_D5,(GET_BIT(Cmd,5)));
	Dio_voidWriteChannel(LCD_DATA_PORT,LCD_D6,(GET_BIT(Cmd,6)));
	Dio_voidWriteChannel(LCD_DATA_PORT,LCD_D7,(GET_BIT(Cmd,7)));
	/*	Enable (Latch)			*/
	Dio_voidWriteChannel(LCD_CONTROL_PORT,LCD_EN,DIO_HIGH);
	_delay_us(1);
	Dio_voidWriteChannel(LCD_CONTROL_PORT,LCD_EN,DIO_LOW);
	_delay_ms(2);
	/*	Send Cmd 4 bits Least significant on the Bus	*/
	//Dio_voidWritePort(LCD_DATA_PORT,(Cmd&0b11110000));
	Dio_voidWriteChannel(LCD_DATA_PORT,LCD_D4,(GET_BIT(Cmd,0)));
	Dio_voidWriteChannel(LCD_DATA_PORT,LCD_D5,(GET_BIT(Cmd,1)));
	Dio_voidWriteChannel(LCD_DATA_PORT,LCD_D6,(GET_BIT(Cmd,2)));
	Dio_voidWriteChannel(LCD_DATA_PORT,LCD_D7,(GET_BIT(Cmd,3)));
	/*	Enable (Latch)			*/
	Dio_voidWriteChannel(LCD_CONTROL_PORT,LCD_EN,DIO_HIGH);
	_delay_us(1);
	Dio_voidWriteChannel(LCD_CONTROL_PORT,LCD_EN,DIO_LOW);
	_delay_ms(2);
	#else
	#error	"Wrong choice of LCD mode!"
	#endif
}

void	Lcd_voidGoToRowCol(u8 Row , u8 col)
{
	switch (Row)
	{
		case LCD_ROW1 : Lcd_voidSendCmd(0x80 + col); break ;
		case LCD_ROW2 : Lcd_voidSendCmd(0xC0 + col); break ;
	}
}

void	Lcd_voidWriteCustomChar(u8 pos, u8 arr[])
{
	Lcd_voidSendCmd((0x40)+(8 * pos));
	for (u8 i = 0 ; i < 8 ; i++)
	{
		Lcd_voidWriteChar(arr[i]);
	}
}

u8 LCD_u8WriteINT(u16 Copy_u16NB)
{
	u8 Local_u8Error=0;

	if(Copy_u16NB==0)
	{
		Lcd_voidWriteChar(48);
	}
	else
	{
		u8 Local_u8Digits=0,Local_u8Counter;
		u16 Local_u16CopyOfNB=Copy_u16NB;

		/*		Get the number of digits of the Number*/
		while(Local_u16CopyOfNB !=0)
		{
			Local_u8Digits++; //Increment no of digits by one

			Local_u16CopyOfNB/=10; //get rid of the most right digit
		}

		Local_u16CopyOfNB=Copy_u16NB;

		/*		Loop on the number and print every single digit alone each iteration*/
		for(Local_u8Counter=0;Local_u8Counter<Local_u8Digits;Local_u8Counter++)
		{
			/*Get the most left digit*/
			Local_u16CopyOfNB/=Private_u16Power(10,Local_u8Digits-Local_u8Counter-1);

			/*Print the most left digit*/
			Lcd_voidWriteChar(48+Local_u16CopyOfNB);

			/*Load the original number*/
			Local_u16CopyOfNB=Copy_u16NB;

			/*Get rid of the left most digit*/
			Local_u16CopyOfNB%=Private_u16Power(10,Local_u8Digits-Local_u8Counter-1);
		}
	}
	return Local_u8Error;
}
u16 Private_u16Power(u8 Copy_u8Op1, u8 Copy_u8Op2)
{
	u8 Local_u8Counter;
	u16 Local_u16Result=1;
	for(Local_u8Counter=0;Local_u8Counter<Copy_u8Op2;Local_u8Counter++)
	{
		Local_u16Result*=Copy_u8Op1;
	}
	return Local_u16Result;
}