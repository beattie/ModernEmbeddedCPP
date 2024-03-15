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
#ifndef NO_IOSTREAM
#include <iostream>
#endif

extern UART_HandleTypeDef huart2;

int main()
{
	// At this stage the system clock should have already been configured
	// at high speed.
	uart2_init();
#if 1	// Demo code
	const char *Hello = "\n\rHello from the UART\n\r";
	write(uart_fd, Hello, strlen(Hello));

#ifndef NO_IOSTREAM
	std::cout << "Hello from C++ iostream" << std::endl;
#endif

	// Infinite loop
	while (1) {
		char buf[64];

		uart2_puts ("<< ");
		uart2_gets (buf, sizeof(buf));
		char *newline;
		if ((newline = rindex (buf, '\n')) != nullptr) {
			*newline = 0;	// get rid of newline
		}
		uart2_printf ("Input = \"%s\"\n\r uwTick %u\n\r", buf,
				HAL_GetTick());
	}
#endif // end of Demo code
}

// ----------------------------------------------------------------------------
