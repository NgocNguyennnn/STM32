#include "uart.h"
#include "Ring_Buffer.h"
#define Max 64
uint8_t Buffer[3][Max];
Ring_Buffer Ringbuffer[3];

void uart_init(uint8_t uart_num)
{
	RingBuffer_init(&Ringbuffer[uart_num],Buffer[uart_num],Max);
}
void uart_receive(uint8_t data,uint8_t uart_num)
{
	RingBuffer_push(&Ringbuffer[uart_num],data);
}	
uint16_t uart_available(uint8_t uart_num)
{
	return RingBuffer_available(&Ringbuffer[uart_num]);
}
uint8_t uart_read(uint8_t uart_num)
{
	uint8_t data;
	RingBuffer_pop(&Ringbuffer[uart_num],&data);
	return data;
}
