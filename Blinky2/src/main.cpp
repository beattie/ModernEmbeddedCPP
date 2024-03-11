/*
 * This file is part of the µOS++ distribution.
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

#include "timer.h"
#include "led.h"
#include "uart.h"
#include <cstring>

// ----------------------------------------------------------------------------
//
// Standalone STM32F4 led blink sample (trace via DEBUG).
//
// In debug configurations, demonstrate how to print a greeting message
// on the trace device. In release configurations the message is
// simply discarded.
//
// Then demonstrates how to blink a led with 1 Hz, using a
// continuous loop and SysTick delays.
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the DEBUG output,
// but can be rerouted to any device or completely suppressed, by
// changing the definitions required in system/src/diag/trace-impl.c
// (currently OS_USE_TRACE_ITM, OS_USE_TRACE_SEMIHOSTING_DEBUG/_STDOUT).
//

// Definitions visible only within this translation unit.
namespace {
	// ----- Timing definitions -------------------------------------------------

	// Keep the LED on for 2/3 of a second.
	constexpr timer::ticks_t BLINK_ON_TICKS = timer::FREQUENCY_HZ * 3 / 4;
	constexpr timer::ticks_t BLINK_OFF_TICKS = timer::FREQUENCY_HZ
			- BLINK_ON_TICKS;
}

// ----- LED definitions ------------------------------------------------------

// Assume a NUCLEO-F411RE board, PA5, active high.

#define BLINK_PORT_NUMBER         (0)
#define BLINK_PIN_NUMBER          (5)
#define BLINK_ACTIVE_LOW          (false)

led blinkLeds[1] =
		{ { BLINK_PORT_NUMBER, BLINK_PIN_NUMBER, BLINK_ACTIVE_LOW }, };

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

extern UART_HandleTypeDef huart2;

int main(int argc, char *argv[])
{
	InitUART2();
	// Send a greeting to the trace device (skipped on Release).
	trace_puts("Hello Arm World!");

	const char *msg = "Hello from the UART\n\r";

	// At this stage the system clock should have already been configured
	// at high speed.
	trace_printf("System clock: %u Hz\n", SystemCoreClock);

	HAL_UART_Transmit(&huart2, (uint8_t*) msg, strlen(msg), 0xFFFF);

	timer timer;
	timer.start();

	// Perform all necessary initialisations for the LEDs.
	for (size_t i = 0; i < (sizeof(blinkLeds) / sizeof(blinkLeds[0])); ++i) {
		blinkLeds[i].power_up();
	}

	uint32_t seconds = 0;

	for (size_t i = 0; i < (sizeof(blinkLeds) / sizeof(blinkLeds[0])); ++i) {
		blinkLeds[i].turn_on();
	}

	// First second is long.
	timer.sleep(timer::FREQUENCY_HZ);

	for (size_t i = 0; i < (sizeof(blinkLeds) / sizeof(blinkLeds[0])); ++i) {
		blinkLeds[i].turn_off();
	}

	timer.sleep(BLINK_OFF_TICKS);

	++seconds;
	trace_printf("Second %u\n", seconds);

	uart2_putc('U');
	//HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), 0xFFFF);

	if ((sizeof(blinkLeds) / sizeof(blinkLeds[0])) > 1) {
		// Blink individual LEDs.
		for (size_t i = 0; i < (sizeof(blinkLeds) / sizeof(blinkLeds[0]));
				++i) {
			blinkLeds[i].turn_on();
			timer.sleep(BLINK_ON_TICKS);

			blinkLeds[i].turn_off();
			timer.sleep(BLINK_OFF_TICKS);

			++seconds;
			trace_printf("Second %u\n", seconds);
			uart2_putc('V');
		}

		// Blink binary.
		while (1) {
			for (size_t l = 0; l < (sizeof(blinkLeds) / sizeof(blinkLeds[0]));
					++l) {
				blinkLeds[l].toggle();
				if (blinkLeds[l].isOn()) {
					break;
				}
			}
			timer.sleep(timer::FREQUENCY_HZ);

			++seconds;
			trace_printf("Second %u\n", seconds);
			uart2_putc('W');
		}
		// Infinite loop, never return.
	} else {
		while (1) {
			blinkLeds[0].turn_on();
			timer.sleep(BLINK_ON_TICKS);

			blinkLeds[0].turn_off();
			timer.sleep(BLINK_OFF_TICKS);

			++seconds;
			trace_printf("Second %u\n", seconds);
			uart2_putc('Z');
		}
		// Infinite loop, never return.
	}
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
