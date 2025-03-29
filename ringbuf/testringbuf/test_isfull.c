#include "testcommons.h"

static int testRingBuf(RingBufType* const context)
{
    context->head = 0;
    context->tail = 1;
    for (size_t i=0; i<(context->bufferSize+5); i++)
    {
        if (RingBuf_isFull(context) == false)
        {
            printf("Testing RingBuf_isFull with full buffer FAILED"
                   " @ ringbuf.head==%lu, ringbuf.tail==%lu\n",
                   context->head,
                   context->tail);
            printRingBuf(context);
            return -1;
        }
        context->tail++;
        context->tail %= context->bufferSize;
        context->head++;
        context->head %= context->bufferSize;
    }

    context->tail = 0;
    for (size_t k=0; k<(context->bufferSize+5); k++)
    {
        context->head = context->tail;
        for (size_t i=0; i<(context->bufferSize-1); i++)
        {
            if (RingBuf_isFull(context) == true)
            {
                printf("Testing RingBuf_isFull with non-full buffer FAILED"
                       " @ ringbuf.head==%lu, ringbuf.tail==%lu\n",
                       context->head,
                       context->tail);
                printRingBuf(context);
                return -1;
            }
            context->head++;
            context->head %= context->bufferSize;
        }
        context->tail++;
        context->tail %= context->bufferSize;
    }

    return 0;
}
