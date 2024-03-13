#include "Ring_Buffer.h"

void RingBuffer_init(Ring_Buffer *Ringbuffer,uint8_t *buffer,uint16_t len)
{
		Ringbuffer->buffer = buffer;
		Ringbuffer->head = 0;
	  Ringbuffer->tail = 0;
		Ringbuffer->maxlen = len;
}
int8_t RingBuffer_push(Ring_Buffer *Ringbuffer,uint8_t data)
{
		uint16_t next = Ringbuffer->head+1;

		if(next >= Ringbuffer->maxlen)
			next = 0;
		if(next == Ringbuffer->tail)
			return -1;
		
		Ringbuffer->buffer[Ringbuffer->head] = data;
		Ringbuffer->head = next;
		
		return 0;
}
int8_t RingBuffer_pop(Ring_Buffer *Ringbuffer,uint8_t *data)
{
		uint16_t next;

    if (Ringbuffer->head == Ringbuffer->tail)  // if the head == tail, we don't have any data
        return -1;

    next = Ringbuffer->tail + 1;  // next is where tail will point to after this read.
    if(next >= Ringbuffer->maxlen)
        next = 0;

    *data = Ringbuffer->buffer[Ringbuffer->tail];  // Read data and then move
    Ringbuffer->tail = next;              // tail to next offset.
    return 0;  // return success to indicate successful push.
}
uint16_t RingBuffer_available(Ring_Buffer *Ringbuffer)
{
		if(Ringbuffer->head < Ringbuffer->tail)
		{
			return 5 - (Ringbuffer->tail - Ringbuffer->head);
		}
		return Ringbuffer->head - Ringbuffer->tail;
}

