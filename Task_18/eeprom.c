/*
 * eep24C08.c
 *
 * Created: 12/1/2023 10:59:42 PM
 *  Author: reBuyTech
 */ 

#define F_CPU		16000000UL
#include <util/delay.h>
#include "i2c.h"
#include "eeprom.h"

void eep24C08_init(void)
{
	i2c_masterInit(0x00);	
}

void eep24C08_writeByte(u16 addr, u8 byte)
{
	u8 loc_blkNo =0;
	u8 loc_byteNo =0;
	
	/*	calc block no and byte no from byte address(0:1023)	*/
	loc_blkNo = addr/EEP24C08_BLOCK_SIZE;
	loc_byteNo = addr%EEP24C08_BLOCK_SIZE;
	
	i2c_startCondition();
	i2c_sendAddrWithWrite(0b01010000 | loc_blkNo); // 0x50
	i2c_sendByte(loc_byteNo);
	i2c_sendByte(byte);
	i2c_stopCondition();
	_delay_ms(10);
}

void eep24C08_writePage(u16 addr, u8 size, u8 pageData[])
{
	u8 i=0;
	u8 loc_blkNo =0;
	u8 loc_byteNo =0;
	
	/*	calc block no and byte no from byte address(0:1023)	*/
	loc_blkNo = addr/EEP24C08_BLOCK_SIZE;
	loc_byteNo = addr%EEP24C08_BLOCK_SIZE;
	
	if ((loc_byteNo + size) <= EEP24C08_BLOCK_SIZE) /*	page located at the same block	*/ 
	{
		i2c_startCondition();
		i2c_sendAddrWithWrite(0b01010000 | loc_blkNo); // 0x50
		i2c_sendByte(loc_byteNo);
		
		for (i=0; i<size; i++)
		{
			i2c_sendByte(pageData[i]);
		}
		i2c_stopCondition();
		_delay_ms(10);		
	}
	else
	{
		/*	take it as a challenge 	*/
	}
	
}

u8 eep24C08_readByte(u16 addr)
{
	u8 loc_byte =0;
	u8 loc_blkNo =0;
	u8 loc_byteNo =0;
	
	/*	calc block no and byte no from byte address(0:1023)	*/
	loc_blkNo = addr/EEP24C08_BLOCK_SIZE;
	loc_byteNo = addr%EEP24C08_BLOCK_SIZE;	
	
	i2c_startCondition();	
	i2c_sendAddrWithWrite(0b01010000 | loc_blkNo);
	i2c_sendByte(loc_byteNo);
	
	i2c_repeatedStartCondition();
	i2c_sendAddrWithRead(0b01010000 | loc_blkNo);
	i2c_receiveByte(&loc_byte);
	i2c_stopCondition();
	
	return loc_byte;
}

void eep24C08_readPage(u16 addr, u8 size,  u8 pageData[])
{
	u8 i=0;
	u8 loc_blkNo =0;
	u8 loc_byteNo =0;
	
	/*	calc block no and byte no from byte address(0:1023)	*/
	loc_blkNo = addr/EEP24C08_BLOCK_SIZE;
	loc_byteNo = addr%EEP24C08_BLOCK_SIZE;
	if ((loc_byteNo + size) <= EEP24C08_BLOCK_SIZE) /*	page located at the same block	*/
		{	
			i2c_startCondition();
			i2c_sendAddrWithWrite(0b01010000 | loc_blkNo);
			i2c_sendByte(loc_byteNo);
			
			i2c_repeatedStartCondition();
			i2c_sendAddrWithRead(0b01010000 | loc_blkNo);
			
			for (i=0; i<size; i++)
			{
				i2c_receiveByte(pageData[i]);
			}
			i2c_stopCondition();	
		}
	else
		{
			/*	take it as a challenge 	*/
		}
}