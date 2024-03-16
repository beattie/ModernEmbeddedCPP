/*
 * gpio.h
 *
 *  Created on: Mar 15, 2024
 *      Author: beattie
 */

#include <stdint.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

#ifndef GPIO_H_
#define GPIO_H_

#define GPIO_MODE_IN	0
#define GPIO_MODE_OUT	1
#define GPIO_MODE_ALTF	2
#define GPIO_MODE_ANLOG	3

#define GPIO_OTYPE_PP	0	// Pull Up/Down
#define GPIO_OTYPE_OD	1	// Open Drain

#define GPIO_SPEED_L	0
#define GPIO_SPEED_M	1
#define GPIO_SPEED_F	2
#define GPIO_SPEED_H	3

#define GPIO_PUPD_NO	0
#define GPIO_PUPD_UP	1
#define GPIO_PUPD_DN	2

class gpio {
	public:
		gpio(unsigned, unsigned, unsigned, unsigned, unsigned,
				unsigned);
		gpio(unsigned, unsigned, unsigned, unsigned, unsigned,
				unsigned, unsigned);
		void on();
		void off();
		bool toggle();
		bool isOn();
	private:
		GPIO_TypeDef	*port;
		uint8_t			pin;
};



#endif /* GPIO_H_ */
