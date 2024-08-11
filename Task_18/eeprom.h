/*
 * eep24C08.h
 *
 * Created: 12/1/2023 10:59:27 PM
 *  Author: reBuyTech
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
#include "Std_Types.h"

#define EEP24C08_BLOCK_SIZE			(256)

void eep24C08_init(void);
void eep24C08_writeByte(u16 addr, u8 byte);
void eep24C08_writePage(u16 addr, u8 size, u8 pageData[]);

u8 eep24C08_readByte(u16 addr);
void eep24C08_readPage(u16 addr, u8 size,  u8 pageData[]);

#endif /* EEPROM_H_ */