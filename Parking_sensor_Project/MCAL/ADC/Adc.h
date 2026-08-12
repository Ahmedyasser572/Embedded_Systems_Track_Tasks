/*
 * Adc.h
 *
 * Created: 9/9/2023 10:27:36 PM
 *  Author: Super-Magic
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "../../LIB/Bit_Math.h"
#include "../../LIB/Std_Types.h"

#include "Adc_Private.h"
#include "Adc_Cfg.h"

void	Adc_voidInit(void);
u16		Adc_u16ReadChannel(u8 Channel);


#endif /* ADC_H_ */