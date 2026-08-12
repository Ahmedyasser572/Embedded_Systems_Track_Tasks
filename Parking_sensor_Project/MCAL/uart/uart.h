/*
 * uart.h
 *
 * Created: 11/3/2023 10:08:20 PM
 *  Author: reBuyTech
 */ 
#include "../../LIB/Std_Types.h"

#ifndef UART_H_
#define UART_H_

/*	UBRR values for actual baudrate	*/
#define BAUDRATE_9600			(103)
#define BAUDRATE_115200			(8)


#define PARITY_EVEN				(2<<4)
#define PARITY_ODD				(3<<4)
#define PARITY_OFF				(0<<4)

#define STOP_BIT_ONE			(0<<3)
#define STOP_BIT_TWO			(1<<3)

#define DATA_SIZE_5				(0<<1)
#define DATA_SIZE_6				(1<<1)
#define DATA_SIZE_7				(2<<1)
#define DATA_SIZE_8				(3<<1)


#define UCSRC_SELLECT				(1<<7)

#define TX_ENABLE_BIT_NO			(3)
#define RX_ENABLE_BIT_NO			(4)


void uart_vidInit(u16 baudrate);
void uart_vidSendByte(u8 byte);
u8 uart_u8ReceiveByte(void);
void uart_vidSendString_synch(u8 str[]);
void uart_vidSendString_asynch(u8 str[]);
u8 uart_u8ReceiveByte_synch(u8 byte);
u8 uart_u8ReceiveByte_asynch(u8 byte);
u8 uart_u8ReceiveString_asynch(u8 str []);
u8 uart_u8ReceiveString_synch(u8 str []);
void checkString(void);

void uart_vidEnableRxCInterrupt(void (*fptr)(void));
void uart_vidEnableTxCInterrupt(void (*fptr)(void));


#endif /* UART_H_ */