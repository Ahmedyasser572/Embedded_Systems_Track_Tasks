/*
 * KeyPad.c
 *
 * Created: 9/2/2023 10:36:58 PM
 *  Author: Super-Magic
 */ 

#include "KeyPad.h"

static	u8	KB_Values[4][4] = {	{'+' , '-' , '*' , '/'},
								{'=' , '9' , '6' , '3'},
								{'7' , '8' , '5' , '2'},
								{'*' , '7' , '4' , '1'}
								};


u8	KB_u8GetPressedKey(void)
{
	u8	Local_u8Key = 0xFF;
	/*	To Send the Pattern 0111 then 1011 then 1101 then 1110 */
	for(u8 Col = 0 ; Col < 4 ; Col++)
	{
		/* To send Zero on specific Pattern */ //0111 1011
		Dio_voidWriteChannel(COLUMN_PORT,Col,DIO_LOW);
		/*	Check which switch is pressed */
		for(u8 Row = 0; Row < 4 ; Row++)
		{
			/*	Check if switch is pressed or not */
			if((Dio_u8ReadChannel(ROW_PORT,(Row+4)))==0)
			{
				/*	Debouncing */
				_delay_ms(20);
				/*	Return the switch */
				Local_u8Key = KB_Values[Col][Row];
				/*	Stuck to release the Swtich */
				while((Dio_u8ReadChannel(ROW_PORT,(Row+4)))==0);
			}
		}
		/* To Return Zero to one after the check */
		Dio_voidWriteChannel(COLUMN_PORT,Col,DIO_HIGH);
	}
	return Local_u8Key;
}

