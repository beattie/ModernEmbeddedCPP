/*
 * led.cpp
 *
 *  Created on: Mar 15, 2024
 *      Author: beattie
 */

#include "led.h"
#include "gpio.h"

led::led(unsigned port, unsigned pin):
		g(port, pin, GPIO_MODE_OUT,
		GPIO_OTYPE_PP, GPIO_SPEED_H, GPIO_PUPD_NO, 0)
{

}

void led::on()		{ g.on(); }
void led::off()		{ g.off(); }
bool led::toggle()	{ return g.toggle(); }
bool led::isOn()	{ return g.isOn(); }

