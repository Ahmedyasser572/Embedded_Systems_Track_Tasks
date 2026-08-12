/*
 * Bit_Math.h
 *
 * Created: 8/26/2023 10:04:55 PM
 *  Author: Super-Magic
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define		SET_BIT(REG,BIT)			(REG |=  (1<<BIT)) //REG = ((1<<BIT) | REG)
#define		CLR_BIT(REG,BIT)			(REG &= ~(1<<BIT))
#define		TOG_BIT(REG,BIT)			(REG ^=  (1<<BIT))
#define		GET_BIT(REG,BIT)			( (REG>>BIT) & 1 )


#endif /* BIT_MATH_H_ */