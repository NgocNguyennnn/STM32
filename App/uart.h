#ifndef UART_H
#define UART_H
#include <stdint.h>
#define UART_NUM_1 0
#define UART_NUM_2 1
#define UART_NUM_3 2

void uart_receive(uint8_t data,uint8_t uart_num);
void uart_init(uint8_t uart_num);
uint16_t uart_available(uint8_t uart_num);
uint8_t uart_read(uint8_t uart_num);
#endif
