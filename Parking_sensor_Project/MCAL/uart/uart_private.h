/*
 * uart_private.h
 *
 * Created: 11/3/2023 10:08:09 PM
 *  Author: reBuyTech
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#include "../../LIB/Std_Types.h"

#define UART_UBRRL_REG			(*(volatile u8*)0x29)
#define UART_UBRRH_REG			(*(volatile u8*)0x40)
#define UART_UCSRA_REG			(*(volatile u8*)0x2B)
#define UART_UCSRB_REG			(*(volatile u8*)0x2A)
#define UART_UCSRC_REG			(*(volatile u8*)0x40)
#define UART_UDR_REG			(*(volatile u8*)0x2C)				
	
#define UDRE_FLAG_BIT_NO			(5)
#define RXC_FLAG_BIT_NO				(7)
#define TXC_FLAG_BIT_NO				(6)
#define RXC_INTERRUPT_ENABLE_BIT_NO	(7)			
#define TXC_INTERRUPT_ENABLE_BIT_NO	(6)	
					  
#endif /* UART_PRIVATE_H_ */