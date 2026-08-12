/*
 * CFile1.c
 *
 * Created: 8/29/2023 5:33:04 PM
 *  Author: Super-Magic
 */ 

#include "SevenSegment.h"

void SevenSegment_voidSelectNumber(u8 SevenSegment_Port , u8 Number)
{
	if ( SevenSegment_Port < 4 && Number < 10 )
	{
		if ( SevenSegment_Port == DIO_PORTA)
		{
			switch(Number)
			{
				case 0 : Dio_voidWritePort(DIO_PORTA,0XFF);		        Dio_voidWriteChannel(DIO_PORTA,DIO_PIN6,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTA,DIO_PIN7,DIO_LOW);  break;
						 
				case 1 : Dio_voidWritePort(DIO_PORTA,DIO_LOW);              Dio_voidWriteChannel(DIO_PORTA,DIO_PIN1,DIO_HIGH);	 Dio_voidWriteChannel(DIO_PORTA,DIO_PIN2,DIO_HIGH) ;
						 Dio_voidWriteChannel(DIO_PORTA,DIO_PIN7,DIO_LOW);  break;
				
				case 2 : Dio_voidWritePort(DIO_PORTA,0XFF);		        Dio_voidWriteChannel(DIO_PORTA,DIO_PIN2,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTA,DIO_PIN5,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTA,DIO_PIN7,DIO_LOW);  break;
						 
				case 3 : Dio_voidWritePort(DIO_PORTA,0XFF);		        Dio_voidWriteChannel(DIO_PORTA,DIO_PIN4,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTA,DIO_PIN5,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTA,DIO_PIN7,DIO_LOW);  break;
				
				case 4 : Dio_voidWritePort(DIO_PORTA,0XFF);		        Dio_voidWriteChannel(DIO_PORTA,DIO_PIN0,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTA,DIO_PIN3,DIO_LOW);  Dio_voidWriteChannel(DIO_PORTA,DIO_PIN4,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTA,DIO_PIN7,DIO_LOW);  break;
				
				case 5 : Dio_voidWritePort(DIO_PORTA,0XFF);		        Dio_voidWriteChannel(DIO_PORTA,DIO_PIN1,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTA,DIO_PIN4,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTA,DIO_PIN7,DIO_LOW);  break;		 

				case 6 : Dio_voidWritePort(DIO_PORTA,0XFF);		        Dio_voidWriteChannel(DIO_PORTA,DIO_PIN1,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTA,DIO_PIN7,DIO_LOW);  break;	
				
				case 7 : Dio_voidWritePort(DIO_PORTA,DIO_LOW);               Dio_voidWriteChannel(DIO_PORTA,DIO_PIN0,DIO_HIGH);
					   	 Dio_voidWriteChannel(DIO_PORTA,DIO_PIN1,DIO_HIGH) ;
						 Dio_voidWriteChannel(DIO_PORTA,DIO_PIN2,DIO_HIGH);  break;			
				
				case 8 : Dio_voidWritePort(DIO_PORTA,0XFF);		         Dio_voidWriteChannel(DIO_PORTA,DIO_PIN7,DIO_LOW);
						 break;
				
				case 9 : Dio_voidWritePort(DIO_PORTA,0XFF);		         Dio_voidWriteChannel(DIO_PORTA,DIO_PIN4,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTA,DIO_PIN7,DIO_LOW);   break;
			}
		}
		else if ( SevenSegment_Port == DIO_PORTB)
		{
			switch(Number)
			{
				case 0 : Dio_voidWritePort(DIO_PORTB,0XFF);		        Dio_voidWriteChannel(DIO_PORTB,DIO_PIN6,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTB,DIO_PIN7,DIO_LOW);  break;
						 
				case 1 : Dio_voidWritePort(DIO_PORTB,DIO_LOW);              Dio_voidWriteChannel(DIO_PORTB,DIO_PIN1,DIO_HIGH);	 Dio_voidWriteChannel(DIO_PORTB,DIO_PIN2,DIO_HIGH) ;
						 Dio_voidWriteChannel(DIO_PORTB,DIO_PIN7,DIO_LOW);  break;
				
				case 2 : Dio_voidWritePort(DIO_PORTB,0XFF);		        Dio_voidWriteChannel(DIO_PORTB,DIO_PIN2,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTB,DIO_PIN5,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTB,DIO_PIN7,DIO_LOW);  break;
						 
				case 3 : Dio_voidWritePort(DIO_PORTB,0XFF);		        Dio_voidWriteChannel(DIO_PORTB,DIO_PIN4,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTB,DIO_PIN5,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTB,DIO_PIN7,DIO_LOW);  break;
				
				case 4 : Dio_voidWritePort(DIO_PORTB,0XFF);		        Dio_voidWriteChannel(DIO_PORTB,DIO_PIN0,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTB,DIO_PIN3,DIO_LOW);  Dio_voidWriteChannel(DIO_PORTB,DIO_PIN4,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTB,DIO_PIN7,DIO_LOW);  break;
				
				case 5 : Dio_voidWritePort(DIO_PORTB,0XFF);		        Dio_voidWriteChannel(DIO_PORTB,DIO_PIN1,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTB,DIO_PIN4,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTB,DIO_PIN7,DIO_LOW);  break;		 

				case 6 : Dio_voidWritePort(DIO_PORTB,0XFF);		        Dio_voidWriteChannel(DIO_PORTB,DIO_PIN1,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTB,DIO_PIN7,DIO_LOW);  break;	
				
				case 7 : Dio_voidWritePort(DIO_PORTB,DIO_LOW);               Dio_voidWriteChannel(DIO_PORTB,DIO_PIN0,DIO_HIGH);
					   	 Dio_voidWriteChannel(DIO_PORTB,DIO_PIN1,DIO_HIGH) ;
						 Dio_voidWriteChannel(DIO_PORTB,DIO_PIN2,DIO_HIGH);  break;			
				
				case 8 : Dio_voidWritePort(DIO_PORTB,0XFF);		         Dio_voidWriteChannel(DIO_PORTB,DIO_PIN7,DIO_LOW);
						 break;
				
				case 9 : Dio_voidWritePort(DIO_PORTB,0XFF);		         Dio_voidWriteChannel(DIO_PORTB,DIO_PIN4,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTB,DIO_PIN7,DIO_LOW);   break;
			}
		}
		else if ( SevenSegment_Port == DIO_PORTC)
		{
			switch(Number)
			{
				case 0 : Dio_voidWritePort(DIO_PORTC,0XFF);		        Dio_voidWriteChannel(DIO_PORTC,DIO_PIN6,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTC,DIO_PIN7,DIO_LOW);  break;
						 
				case 1 : Dio_voidWritePort(DIO_PORTC,DIO_LOW);              Dio_voidWriteChannel(DIO_PORTC,DIO_PIN1,DIO_HIGH);	 Dio_voidWriteChannel(DIO_PORTC,DIO_PIN2,DIO_HIGH) ;
						 Dio_voidWriteChannel(DIO_PORTC,DIO_PIN7,DIO_LOW);  break;
				
				case 2 : Dio_voidWritePort(DIO_PORTC,0XFF);		        Dio_voidWriteChannel(DIO_PORTC,DIO_PIN2,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTC,DIO_PIN5,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTC,DIO_PIN7,DIO_LOW);  break;
						 
				case 3 : Dio_voidWritePort(DIO_PORTC,0XFF);		        Dio_voidWriteChannel(DIO_PORTC,DIO_PIN4,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTC,DIO_PIN5,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTC,DIO_PIN7,DIO_LOW);  break;
				
				case 4 : Dio_voidWritePort(DIO_PORTC,0XFF);		        Dio_voidWriteChannel(DIO_PORTC,DIO_PIN0,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTC,DIO_PIN3,DIO_LOW);  Dio_voidWriteChannel(DIO_PORTC,DIO_PIN4,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTC,DIO_PIN7,DIO_LOW);  break;
				
				case 5 : Dio_voidWritePort(DIO_PORTC,0XFF);		        Dio_voidWriteChannel(DIO_PORTC,DIO_PIN1,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTC,DIO_PIN4,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTC,DIO_PIN7,DIO_LOW);  break;		 

				case 6 : Dio_voidWritePort(DIO_PORTC,0XFF);		        Dio_voidWriteChannel(DIO_PORTC,DIO_PIN1,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTC,DIO_PIN7,DIO_LOW);  break;	
				
				case 7 : Dio_voidWritePort(DIO_PORTC,DIO_LOW);               Dio_voidWriteChannel(DIO_PORTC,DIO_PIN0,DIO_HIGH);
					   	 Dio_voidWriteChannel(DIO_PORTC,DIO_PIN1,DIO_HIGH) ;
						 Dio_voidWriteChannel(DIO_PORTC,DIO_PIN2,DIO_HIGH);  break;			
				
				case 8 : Dio_voidWritePort(DIO_PORTC,0XFF);		         Dio_voidWriteChannel(DIO_PORTC,DIO_PIN7,DIO_LOW);
						 break;
				
				case 9 : Dio_voidWritePort(DIO_PORTC,0XFF);		         Dio_voidWriteChannel(DIO_PORTC,DIO_PIN4,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTC,DIO_PIN7,DIO_LOW);   break;
			}
		}
		else if ( SevenSegment_Port == DIO_PORTD)
		{
			switch(Number)
			{
				case 0 : Dio_voidWritePort(DIO_PORTD,0XFF);		        Dio_voidWriteChannel(DIO_PORTD,DIO_PIN6,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTD,DIO_PIN7,DIO_LOW);  break;
						 
				case 1 : Dio_voidWritePort(DIO_PORTD,DIO_LOW);              Dio_voidWriteChannel(DIO_PORTD,DIO_PIN1,DIO_HIGH);	 Dio_voidWriteChannel(DIO_PORTD,DIO_PIN2,DIO_HIGH) ;
						 Dio_voidWriteChannel(DIO_PORTD,DIO_PIN7,DIO_LOW);  break;
				
				case 2 : Dio_voidWritePort(DIO_PORTD,0XFF);		        Dio_voidWriteChannel(DIO_PORTD,DIO_PIN2,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTD,DIO_PIN5,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTD,DIO_PIN7,DIO_LOW);  break;
						 
				case 3 : Dio_voidWritePort(DIO_PORTD,0XFF);		        Dio_voidWriteChannel(DIO_PORTD,DIO_PIN4,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTD,DIO_PIN5,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTD,DIO_PIN7,DIO_LOW);  break;
				
				case 4 : Dio_voidWritePort(DIO_PORTD,0XFF);		        Dio_voidWriteChannel(DIO_PORTD,DIO_PIN0,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTD,DIO_PIN3,DIO_LOW);  Dio_voidWriteChannel(DIO_PORTD,DIO_PIN4,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTD,DIO_PIN7,DIO_LOW);  break;
				
				case 5 : Dio_voidWritePort(DIO_PORTD,0XFF);		        Dio_voidWriteChannel(DIO_PORTD,DIO_PIN1,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTD,DIO_PIN4,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTD,DIO_PIN7,DIO_LOW);  break;		 

				case 6 : Dio_voidWritePort(DIO_PORTD,0XFF);		        Dio_voidWriteChannel(DIO_PORTD,DIO_PIN1,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTD,DIO_PIN7,DIO_LOW);  break;	
				
				case 7 : Dio_voidWritePort(DIO_PORTD,DIO_LOW);               Dio_voidWriteChannel(DIO_PORTD,DIO_PIN0,DIO_HIGH);
					   	 Dio_voidWriteChannel(DIO_PORTD,DIO_PIN1,DIO_HIGH) ;
						 Dio_voidWriteChannel(DIO_PORTD,DIO_PIN2,DIO_HIGH);  break;			
				
				case 8 : Dio_voidWritePort(DIO_PORTD,0XFF);		         Dio_voidWriteChannel(DIO_PORTD,DIO_PIN7,DIO_LOW);
						 break;
				
				case 9 : Dio_voidWritePort(DIO_PORTD,0XFF);		         Dio_voidWriteChannel(DIO_PORTD,DIO_PIN4,DIO_LOW);
						 Dio_voidWriteChannel(DIO_PORTD,DIO_PIN7,DIO_LOW);   break;
			}
		}
		else{/* Return Error */}

	}
	else{/* Return Error */}
}