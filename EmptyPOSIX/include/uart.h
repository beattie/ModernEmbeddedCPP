/*
 * uart.h
 *
 *  Created on: Mar 10, 2024
 *      Author: beattie
 */

#ifndef UART_H_
#define UART_H_

#ifdef __cplusplus
	extern "C" {
const int uart_fd = 3;
#else
#define uart_fd	(3)
#endif

void uart2_init(uint32_t);

int uart2_putc(char);
int uart2_getc(void);
int uart2_write(const char *, unsigned);
int uart2_printf(const char *, ...);
int uart2_puts(const char *);
char *uart2_gets(char * buf, size_t n);

#ifdef __cplusplus
	}
#endif
#endif /* UART_H_ */
