/*
 * Dio.c
 *
 * Created: 8/26/2023 9:56:52 PM
 *  Author: Super-Magic
 */ 

#include	"Dio.h"

//Dio_voidSetPinDirection(PORTA,PIN0,DIO_HIGH);


void	Dio_voidSetPinDirection(u8 PortId,u8 PinId,u8 Direction)
{
	
	/*		Range Check 		*/
	if((PortId < 4 )&&(PinId < 8))
	{
		if(Direction == DIO_INPUT)
		{
			switch(PortId)
			{
				case DIO_PORTA	:	CLR_BIT(DDRA_REG,PinId);	break;
				case DIO_PORTB	:	CLR_BIT(DDRB_REG,PinId);	break;
				case DIO_PORTC	:	CLR_BIT(DDRC_REG,PinId);	break;
				case DIO_PORTD	:	CLR_BIT(DDRD_REG,PinId);	break;
			}
		}
		else if(Direction == DIO_OUTPUT)
		{
			switch(PortId)
			{
				case DIO_PORTA	:	SET_BIT(DDRA_REG,PinId);	break;
				case DIO_PORTB	:	SET_BIT(DDRB_REG,PinId);	break;
				case DIO_PORTC	:	SET_BIT(DDRC_REG,PinId);	break;
				case DIO_PORTD	:	SET_BIT(DDRD_REG,PinId);	break;
			}
		}
		else{	/*	Return error	*/	}
		
	}
	else{	/*	Return error	*/	}
	
}

void	Dio_voidWriteChannel(u8 PortId,u8 PinId,u8 Value)
{
	/*		Range Check 		*/
	if((PortId < 4 )&&(PinId < 8))
	{
		if(Value == DIO_LOW)
		{
			switch(PortId)
			{
				case DIO_PORTA	:	CLR_BIT(PORTA_REG,PinId);	break;
				case DIO_PORTB	:	CLR_BIT(PORTB_REG,PinId);	break;
				case DIO_PORTC	:	CLR_BIT(PORTC_REG,PinId);	break;
				case DIO_PORTD	:	CLR_BIT(PORTD_REG,PinId);	break;
			}
		}
		else if(Value == DIO_HIGH)
		{
			switch(PortId)
			{
				case DIO_PORTA	:	SET_BIT(PORTA_REG,PinId);	break;
				case DIO_PORTB	:	SET_BIT(PORTB_REG,PinId);	break;
				case DIO_PORTC	:	SET_BIT(PORTC_REG,PinId);	break;
				case DIO_PORTD	:	SET_BIT(PORTD_REG,PinId);	break;
			}
		}
		else{	/*	Return error	*/	}
		
	}
	else{	/*	Return error	*/	}
}

u8		Dio_u8ReadChannel(u8 PortId,u8 PinId)
{
	
	u8	Local_u8RetVal	= 0x33 ;
	/*		Range Check 		*/
	if((PortId < 4 )&&(PinId < 8))
	{
		switch(PortId)
		{
			case DIO_PORTA	:	Local_u8RetVal	=	GET_BIT(PINA_REG,PinId);	break;
			case DIO_PORTB	:	Local_u8RetVal	=	GET_BIT(PINB_REG,PinId);	break;
			case DIO_PORTC	:	Local_u8RetVal	=	GET_BIT(PINC_REG,PinId);	break;
			case DIO_PORTD	:	Local_u8RetVal	=	GET_BIT(PIND_REG,PinId);	break;
		}
		
	}
	else{	/*	Return error	*/	}
		
	return	Local_u8RetVal;
	
}

void	Dio_voidFlipChannel(u8 PortId,u8 PinId)
{
	if (PortId < 4 && PinId < 8)
	{
		switch(PortId)
		{
			case DIO_PORTA : TOG_BIT(PORTA_REG,PinId);  break;
			case DIO_PORTB : TOG_BIT(PORTB_REG,PinId);  break;
			case DIO_PORTC : TOG_BIT(PORTC_REG,PinId);  break;
			case DIO_PORTD : TOG_BIT(PORTD_REG,PinId);  break;
		}
	}
	else{/* Return Error */}
}

void	Dio_voidSetPortDirection(u8 PortId,u8 Value)
{
	if (PortId < 4)
	{
		switch(PortId)
		{
			case DIO_PORTA : DDRA_REG = Value; break;
			case DIO_PORTB : DDRB_REG = Value; break;
			case DIO_PORTC : DDRC_REG = Value; break;
			case DIO_PORTD : DDRD_REG = Value; break;
		}
	}
	else{ /* Return Error */}
}

void	Dio_voidWritePort(u8 PortId,u8 Value)
{
	if (PortId < 4)
	{
		switch(PortId)
		{
			case DIO_PORTA : PORTA_REG = Value; break;					 	 
			case DIO_PORTB : PORTB_REG = Value; break;
			case DIO_PORTC : PORTC_REG = Value; break;
			case DIO_PORTD : PORTD_REG = Value; break;	
		}
	}
	else{ /* Return Error */}
}
