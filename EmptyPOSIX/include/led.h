/*
 * led.h
 *
 *  Created on: Mar 15, 2024
 *      Author: beattie
 */
#include <stdint.h>
#include "gpio.h"

#ifndef LED_H_
#define LED_H_

class led {
	public:
		led(unsigned, unsigned);
		void on();
		void off();
		bool toggle();
		bool isOn();
	private:
		gpio g;
};



#endif /* LED_H_ */
