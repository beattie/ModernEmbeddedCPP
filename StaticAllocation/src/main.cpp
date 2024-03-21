/*
 * This file started as part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

// ----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "diag/trace.h"
#include "stm32f4xx.h"
#include "uart.h"
#include <cstring>
#undef NO_IOSTREAM
#ifndef NO_IOSTREAM
#include <iostream>
#endif
#include "gpio.h"

// Demonstrate possible methods to disable C++ dynamic allocation
// via new.
#if 0
void *operator new(std::size_t) =delete;
#endif
#if 1
void *operator_new_blocker();
void *operator new(std::size_t) { return operator_new_blocker(); }
#endif

int main()
{
#if 0
	gpio *d2 = new gpio(PORTA, 10, GPIO_MODE_OUT, GPIO_OTYPE_PP,
			GPIO_SPEED_H, GPIO_PUPD_UP, 1);
#endif
#if 0
	int *p = new int[1];
#endif

#ifndef NO_IOSTREAM
	std::cout << "Hello from C++ iostream" << std::endl;
#endif

	// Infinite loop
	while (1) {
	}
}

// ----------------------------------------------------------------------------
