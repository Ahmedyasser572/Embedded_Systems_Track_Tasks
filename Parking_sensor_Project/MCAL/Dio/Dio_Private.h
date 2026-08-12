/*
 * Dio_Private.h
 *
 * Created: 8/26/2023 9:58:15 PM
 *  Author: Super-Magic
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/************************** PORT_A **************************/

#define  DDRA_REG          	(*((volatile u8 *)0x3A))
#define  PORTA_REG         	(*((volatile u8 *)0x3B))
#define  PINA_REG          	(*((volatile u8 *)0x39))

/************************** PORT_B **************************/

#define  DDRB_REG          	(*((volatile u8 *)0x37))
#define  PORTB_REG         	(*((volatile u8 *)0x38))
#define  PINB_REG          	(*((volatile u8 *)0x36))

/************************** PORT_C **************************/

#define  DDRC_REG          	(*((volatile u8 *)0x34))
#define  PORTC_REG         	(*((volatile u8 *)0x35))
#define  PINC_REG          	(*((volatile u8 *)0x33))

/************************** PORT_D **************************/

#define  DDRD_REG          	(*((volatile u8 *)0x31))
#define  PORTD_REG         	(*((volatile u8 *)0x32))
#define  PIND_REG          	(*((volatile u8 *)0x30))

#endif /* DIO_PRIVATE_H_ */