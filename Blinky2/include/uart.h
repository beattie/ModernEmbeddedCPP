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
#endif

extern UART_HandleTypeDef huart2;
void InitUART2 (void);

int uart2_putc(char);

#ifdef __cplusplus
	}
#endif
#endif /* UART_H_ */
