/*
 * Dio.h
 *
 * Created: 8/26/2023 9:57:36 PM
 *  Author: Super-Magic
 */ 


#ifndef DIO_H_
#define DIO_H_

#include	"../../LIB/Std_Types.h"
#include	"../../LIB/Bit_Math.h"
#include	"Dio_private.h"

#define		DIO_HIGH			1
#define		DIO_LOW				0

#define		DIO_INPUT			0
#define		DIO_OUTPUT			1

#define		DIO_PORTA			0
#define		DIO_PORTB			1
#define		DIO_PORTC			2
#define		DIO_PORTD			3


#define		DIO_PIN0			0
#define		DIO_PIN1			1
#define		DIO_PIN2			2
#define		DIO_PIN3			3
#define		DIO_PIN4			4
#define		DIO_PIN5			5
#define		DIO_PIN6			6
#define		DIO_PIN7			7

void	Dio_voidSetPinDirection(u8 PortId,u8 PinId,u8 Direction);
void	Dio_voidWriteChannel(u8 PortId,u8 PinId,u8 Value);
u8		Dio_u8ReadChannel(u8 PortId,u8 PinId);

void	Dio_voidFlipChannel(u8 PortId,u8 PinId);

void	Dio_voidSetPortDirection(u8 PortId,u8 Direction);
void	Dio_voidWritePort(u8 PortId,u8 Value);




#endif /* DIO_H_ */