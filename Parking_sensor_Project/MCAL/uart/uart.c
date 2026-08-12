/*
 * uart.c
 *
 * Created: 11/3/2023 10:08:34 PM
 *  Author: reBuyTech
 */
#include "uart_private.h"
#include "uart.h"
#include "../../LIB/Bit_Math.h"
#include <stdio.h> 
#include <avr/interrupt.h>
 
u8 tx_buffer_index=0; 
u8 tx_buffer[50];
 
void (*rxcClbkPtr)(void) = NULL; 
void (*txcClbkPtr)(void) = NULL; 

void uart_vidInit(u16 baudrate)
{
	/*	set UBRR value 	*/
	UART_UBRRL_REG = (u8) baudrate;
	UART_UBRRH_REG = (u8)(baudrate>>8);
	
	/*	enable Tx and Rx 	*/
	SET_BIT(UART_UCSRB_REG,TX_ENABLE_BIT_NO);
	SET_BIT(UART_UCSRB_REG,RX_ENABLE_BIT_NO);
	
	/*	set data size=8, 2 stop bits, even parity	*/
	UART_UCSRC_REG |= UCSRC_SELLECT | DATA_SIZE_8 | STOP_BIT_TWO | PARITY_EVEN;		
}
void uart_vidSendByte_synch(u8 byte)
{
	/*	wait until UDR become empty (last byte is sent)	*/
	while (GET_BIT(UART_UCSRA_REG, UDRE_FLAG_BIT_NO) == 0)
	{
		;	/*	wait*/
	}
	/*	set UDR with data byte	*/
	UART_UDR_REG = byte;
}

void uart_vidSendByte_asynch(u8 byte)
{
	/*	set UDR with data byte	*/
	UART_UDR_REG = byte;
}

u8 uart_u8ReceiveByte(void)
{
	/*	wait until UDR receives data	*/
	while (GET_BIT(UART_UCSRA_REG, RXC_FLAG_BIT_NO) == 0)
	{
		;	/*	wait*/
	}
	return UART_UDR_REG;
}

u8 uart_u8ReceiveByte_asynch(u8 byte)
{
	
	
	/*	wait until UDR receives data	*/
	//	while (GET_BIT(UART_UCSRA_REG, RXC_FLAG_BIT_NO) == 0)
	//	{
	//		;	/*	wait*/
	//	}
	return UART_UDR_REG;
}

u8 uart_u8ReceiveByte_synch(u8 byte)
{
	/*	wait until UDR receives data	*/
//	while (GET_BIT(UART_UCSRA_REG, RXC_FLAG_BIT_NO) == 0)
//	{
//		;	/*	wait*/
//	}
	return UART_UDR_REG;
}


u8 uart_u8ReceiveString_synch(u8 str [])
{
	u8 i = 0 ;
     while (str[i] != '\0' )	
	 {
		uart_u8ReceiveByte_synch(str[i]);
		 i++;
	 }
	
	
}

void checkString(void) {
	u8 i = 0 ;
	while (1){
	if (tx_buffer[i] == NULL || tx_buffer[i] == '\0') {
		
		
		} else 
		{
			 uart_u8ReceiveString_asynch(tx_buffer[i]);
		}
	}
}

u8 uart_u8ReceiveString_asynch(u8 str [])
{    
	u8 i = 0 ;
	
	while (str[i] != '\n' || str[i] != '\r' )
	{
		str[i] = uart_u8ReceiveByte();
		tx_buffer[i] = str[i];
		i++;
		
	}
	tx_buffer[i]='\0';
	
}


void uart_vidSendString_synch(u8 str[])
{
	u8 i=0;
	
	while (str[i] != '\0')
	{
		uart_vidSendByte(str[i]);
		i++;
	}
}

void uart_vidSendString_asynch(u8 str[])
{
	u8 i=0;
	
	while (str[i] != '\0')
	{
		tx_buffer[i] = str[i];
		i++;
	}
	tx_buffer[i]='\0';
	
	uart_vidSendByte_asynch(tx_buffer[tx_buffer_index]);
}

void uart_vidEnableRxCInterrupt(void (*fptr)(void))
{
	/*	enable RX complete interrupt	*/
	SET_BIT(UART_UCSRB_REG,RXC_INTERRUPT_ENABLE_BIT_NO);
	/*	set RXC callback	*/
	rxcClbkPtr = fptr;
}

void uart_vidEnableTxCInterrupt(void (*fptr)(void))
{
	/*	enable TX complete interrupt	*/
	SET_BIT(UART_UCSRB_REG,TXC_INTERRUPT_ENABLE_BIT_NO);
	/*	set RXC callback	*/
	txcClbkPtr = fptr;	
}

ISR(USART_RXC_vect)
{
	if (rxcClbkPtr != NULL)
	{
		rxcClbkPtr();
	}
}

ISR(USART_TXC_vect)
{
	tx_buffer_index++;
	if (tx_buffer[tx_buffer_index] != '\0')
	{
		uart_vidSendByte_asynch(tx_buffer[tx_buffer_index]);
	}
	else
	{
		tx_buffer_index=0;
		/*	don't send	*/
	}
}

//ISR(USART_RXC_vect)
//{
//	tx_buffer_index++;
//	if (tx_buffer[tx_buffer_index] != '\n')
//	{
//		uart_u8ReceiveByte_asynch(tx_buffer[tx_buffer_index]);
//	}
//	else
//	{
//		tx_buffer_index=0;
//		/*	don't send	*/
//	}
//}