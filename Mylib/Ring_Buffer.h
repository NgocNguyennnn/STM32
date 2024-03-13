#ifndef RING_BUFFER_H
#define RING_BUFFER_H
#include <stdint.h>

typedef struct {
    uint8_t * buffer;
    uint16_t head;
    uint16_t tail;
    uint16_t maxlen;
} Ring_Buffer;

void RingBuffer_init(Ring_Buffer *Ringbuffer,uint8_t *buffer,uint16_t len);
int8_t RingBuffer_push(Ring_Buffer *Ringbuffer,uint8_t data);
int8_t RingBuffer_pop(Ring_Buffer *Ringbuffer,uint8_t *data);
uint16_t RingBuffer_available(Ring_Buffer *Ringbuffer);


#endif
