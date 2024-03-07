/*
 * mcon.h
 *
 *  Created on: Mar 6, 2024
 *      Author: beattie
 */
#include <stdint.h>


// Nucleo64 green LED on PA5
// GPIOA = AHB1
// AHB1_ADDRESS	= 0x4002'0000
// MODER OFFSET = 0x00
// ODR_OFFSET   = 0x14
// RCC_AHB1ENR	= 0x30

#define AHB1		0x4002'0000
#define RCC			0x3800
#define RCC_AHB1ENR	(*((volatile uint32_t *)(AHB1 + RCC + 0x30))
#define GPIOA_MODER (*((volatile uint32_t *)(AHB1 + 0x00))
#define GPIOA_ODR	(*((volatile uint32_t *)(AHB1 + 0x14))

class Led
{
public:
	typedef uint32_t port_type;
	typedef uint32_t bval_type;
	Led(const port_type p, bval_type b):port(p), bval(b)
	{
		// Disable pin
		* reinterpret_cast<volatile port_type *>(port) &= ~(1U<<bval);
	}

private:
	const port_type port;
	const bval_type bval;
};
