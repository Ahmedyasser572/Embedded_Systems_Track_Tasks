/*
 * SimpleCal_main.c
 *
 * Created: 9/8/2023 10:09:52 PM
 *  Author: Super-Magic
 */ 

#if 1

#include "App_main.h"

int main()
{
	/*	Lcd Control Pins direction output pin (D0,D1,D2)	*/
	Dio_voidSetPinDirection(DIO_PORTD,DIO_PIN0,DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTD,DIO_PIN1,DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTD,DIO_PIN6,DIO_OUTPUT);
	
	/*	LCD Data Port Direction is Output(C0 : C7)			*/
	Dio_voidSetPortDirection(DIO_PORTC,0xFF);
	
	/*	Lcd init											*/
	Lcd_voidInit();
	/*	KeyPad Direction pins (C0 : C3) ==> OutPut (C4 : C7) ==> Input	*/
	Dio_voidSetPortDirection(DIO_PORTA,0b00001111);
	/* (C4 : C7) ==> Input and internal Pull up 			*/
	Dio_voidWritePort(DIO_PORTA,0b11111111);
	
	u8 Data = 0xFF;

	u8 Num1 , Num2 , Opr , Result ;
	u8 flag = 0 ;
	while(1)
	{
		Data = KB_u8GetPressedKey();
		if(Data != 0xFF)
		{
			Lcd_voidWriteChar(Data);
			//_delay_ms(500);
			if (flag == 0 )
			{
				Num1 = (Data-48);
				flag++;
			}
			else if (flag == 1)
			{
				Opr = Data ;
				flag++;
			}
			else if (flag == 2)
			{
				Num2 = (Data-48);
				flag++ ;
			}
			else
			{
				switch(Opr)
				{
					case '+': Result = Num1 + Num2 ; break;
					case '-': Result = Num1 - Num2 ; break;
					case '*': Result = Num1 * Num2 ; break;
					case '/': Result = Num1 / Num2 ; break;
				}
				Lcd_voidWriteChar(Result+48);
				Lcd_voidWriteChar(' ');
				flag = 0 ;
			}
		}
		
	}
}



#endif
