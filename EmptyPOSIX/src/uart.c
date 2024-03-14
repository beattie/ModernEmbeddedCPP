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

UART_HandleTypeDef huart2;

/* USART2 init function */
static void MX_USART2_UART_Init(void)
{
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  HAL_UART_Init(&huart2);
}

void HAL_UART_MspInit(UART_HandleTypeDef* huart)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  if(huart->Instance==USART2)
  {
    /* Peripheral clock enable */
	  __GPIOA_CLK_ENABLE();
    __USART2_CLK_ENABLE();

    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  }
}

void InitUART2()
{
  MX_USART2_UART_Init();
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
	while (!(USART2->SR & USART_SR_RXNE)) { }

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
	ssize_t	s;
	va_list args;
	va_start (args, format);

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

char *uart2_gets(char * buf, size_t n)
{
	ssize_t	r = 0;

	while(--n > 0) {	// leave one byte for null termination
		int c = uart2_getc();
		if (c < 0) {	// if error or EOF
			buf[r] = 0;
			return buf;
		}
		if (c == '\n' || c == '\r') {
			buf[r++] = c;
			buf[r] = 0;
			return buf;
		}
		buf[r++] = uart2_getc();
	}
	buf[r] = 0;
	return buf;
}

