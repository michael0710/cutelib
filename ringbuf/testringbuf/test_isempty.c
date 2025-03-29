#include "testcommons.h"

static int testRingBuf(RingBufType* const context)
{
    for (size_t i=0; i<context->bufferSize; i++)
    {
        if (RingBuf_isEmpty(context) == false)
        {
            printf("Testing RingBuf_isEmpty with empty buffer FAILED"
                   " @ ringbuf.head==%lu, ringbuf.tail==%lu\n",
                   context->head,
                   context->tail);
            printRingBuf(context);
            return -1;
        }
        context->head++;
        context->tail++;
    }

    context->tail = 0;
    for (size_t k=0; k<(context->bufferSize+5); k++)
    {
        context->head = (context->tail + 1) % context->bufferSize;
        for (size_t i=0; i<(context->bufferSize-1); i++)
        {
            if (RingBuf_isEmpty(context) == true)
            {
                printf("Testing RingBuf_isEmpty with non empty buffer FAILED"
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
