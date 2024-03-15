/*
 * uart.c
 *
 *  Created on: Mar 10, 2024
 *      Author: beattie
 */
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_cortex.h"

#include "stdio.h"
#include "stdarg.h"
#include "string.h"


void uart2_init()
{

	RCC->AHB1ENR |= 0x1;		// Enable GPIOA clock/
	RCC->APB1ENR |= 0x20000;	// Enale USART2 clock/

	// Configure PA2,PA3 for USART2 TX, RX/
	GPIOA->AFR[0] |= 0x7700;	// 7 =0111, alt7 for usart2/
	GPIOA->MODER |= 0x00A0;		// enable alternate function for PA2,PA3

	// pclk = 42,000,000
	// BRR = pclk / (16*BPS) * 16 + 0.5
	USART2->BRR = 0x016c;	// 115200 baud @ 42Mhz/
	USART2->CR1 = 0x000C;	// enbale Tx,Rx, 8-bit data/
	USART2->CR2 = 0x000;	// 1 stop bit/
	USART2->CR3 = 0x000;	// no flow control/
	USART2->CR1 |= 0x2000;	// enable USART2/
}

int uart2_putc(char ch)
{
	while (!(USART2->SR & USART_SR_TXE)) {
	} //wait until Tx empty
	USART2->DR = (ch & 0xFF);
	return 1;
}

int uart2_getc(void)
{
	while (!(USART2->SR & USART_SR_RXNE)) {
	}

	return USART2->DR & 0xff;
}

int uart2_write(const char *buf, unsigned nbyte)
{
	unsigned i;

	for (i = 0; i < nbyte; i++) {
		uart2_putc(buf[i]);
	}
	return nbyte;
}

int uart2_printf(const char *format, ...)
{
	static char printbuf[1024];
	ssize_t s;
	va_list args;
	va_start(args, format);

	s = vsnprintf(printbuf, sizeof(printbuf), format, args);
	if (s > 0) {
		uart2_write(printbuf, s);
	}
	return s;
}

int uart2_puts(const char *buf)
{
	return uart2_write(buf, strlen(buf));
}

char* uart2_gets(char *buf, size_t n)
{
	ssize_t r = 0;

	while (--n > 0) {	// leave one byte for null termination
		int c = uart2_getc();
		uart2_putc(c);	// echo
		if (c < 0) {	// if error or EOF
			buf[r] = 0;
			return buf;
		}
		if (c == '\n' || c == '\r') {
			uart2_putc('\n');
			uart2_putc('\r');
			buf[r++] = '\n';
			buf[r] = 0;
			return buf;
		}
		buf[r++] = c;
	}
	buf[r] = 0;
	return buf;
}

