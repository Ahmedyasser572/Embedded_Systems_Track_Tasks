/*
 * PushButtonSwitch.c
 *
 * Created: 8/29/2023 6:47:30 PM
 *  Author: Super-Magic
 */ 

#include "PushButtonSwitch.h"

void PushButtonSwitch_voiodInit(u8 PortId,u8 PinId)
{
	if((PortId < 4 )&&(PinId < 8))
	{
		switch (PortId)
		{
			case DIO_PORTA : Dio_voidSetPinDirection(DIO_PORTA,PinId,DIO_INPUT);
							 Dio_voidWriteChannel(DIO_PORTA,PinId,DIO_HIGH);
							 break;
							 
			case DIO_PORTB : Dio_voidSetPinDirection(DIO_PORTB,PinId,DIO_INPUT);
							 Dio_voidWriteChannel(DIO_PORTB,PinId,DIO_HIGH);
							 break;
			
			case DIO_PORTC : Dio_voidSetPinDirection(DIO_PORTC,PinId,DIO_INPUT);
			                 Dio_voidWriteChannel(DIO_PORTC,PinId,DIO_HIGH);
							 break;
			
			case DIO_PORTD : Dio_voidSetPinDirection(DIO_PORTD,PinId,DIO_INPUT);
							 Dio_voidWriteChannel(DIO_PORTD,PinId,DIO_HIGH);
							 break;
		}
	}
	else{/* Return Error*/}
}

u8 PushButtonSwitch_u8Status (u8 PortId,u8 PinId)
{
	u8	Local_u8RetVal	= 0x33 ;
	
	if((PortId < 4 )&&(PinId < 8))
	{
		switch (PortId)
		{
			case DIO_PORTA : if ( Dio_u8ReadChannel(DIO_PORTA,PinId) == 0)
								 Local_u8RetVal = 0 ;
							 else
								 Local_u8RetVal = 1 ;
							 break;
							 
			case DIO_PORTB : if ( Dio_u8ReadChannel(DIO_PORTB,PinId) == 0)
								 Local_u8RetVal = 0 ;
							 else
								 Local_u8RetVal = 1 ;
							 break;
			
			case DIO_PORTC : if ( Dio_u8ReadChannel(DIO_PORTC,PinId) == 0)
							 	 Local_u8RetVal = 0 ;
							 else
								 Local_u8RetVal = 1 ;
							 break;
			
			case DIO_PORTD : if ( Dio_u8ReadChannel(DIO_PORTD,PinId) == 0)
							 	 Local_u8RetVal = 0 ;
							 else
								 Local_u8RetVal = 1 ;
							 break;
		}
	}
	else{/* Return Error*/}
		
	return Local_u8RetVal ;
}
