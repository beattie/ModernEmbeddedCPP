/*
 * gpio.cpp
 *
 *  Created on: Mar 15, 2024
 *      Author: beattie
 */

#include <stdint.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "gpio.h"

gpio::gpio(unsigned port, unsigned pin, unsigned mode, unsigned type,
		unsigned speed, unsigned pupd) :
			port(GPIOA + port), pin(pin)
{
	GPIO_TypeDef *p = GPIOA + port;

	RCC->AHB1ENR |= 1 << port;

	// clear the alternate function for the pin
	p->AFR[pin>>3] = (p->AFR[pin >> 3] &
			~(0xf << ((pin << 2) & 0x1f)));
	p->MODER = (p->MODER & ~(3UL << (pin << 1))) |
			(mode & 3) << (pin << 1);
	p->OTYPER = (p->OTYPER & ~(1UL << pin)) |
			((type & 1) << pin);
	p->OSPEEDR = (p->OSPEEDR & ~(3 << (pin<<1))) |
			((speed & 3) << (pin << 1));
	p->PUPDR = (p->PUPDR & ~(3 << (pin << 1))) |
			((pupd & 3) << (pin << 1));
}

// delegating constructor
gpio::gpio(unsigned port, unsigned pin, unsigned mode, unsigned type,
		unsigned speed, unsigned pupd, unsigned initial) :
				gpio(port, pin, mode, type, speed, pupd)
{
	this->port->ODR = (this->port->ODR & ~(1 << pin)) |
			((initial & 1) << pin);

}

void gpio::on()
{
	port->BSRR = 1 << pin;
}

void gpio::off()
{
	port->BSRR = 1 << (pin + 16);
}

// return new value of pin
bool gpio::toggle()
{
	uint32_t val = port->ODR & 1 << pin;

	port->ODR = (port->ODR & ~(1 << pin)) |
			(val ^ (1 << pin));

	return val == 0;
}

bool gpio::isOn()
{
	return (port->ODR & (1 << pin)) != 0;
}


#if 0
#endif
