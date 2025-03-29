#include "testcommons.h"

static int testRingBuf(RingBufType* const context)
{
    context->head = 0;
    for (size_t k=0; k<(context->bufferSize+5); k++)
    {
        context->tail = (context->head+1)%context->bufferSize;
        for (size_t i=0; i<context->bufferSize+1; i++)
        {
            if (RingBuf_increaseTail(context) != 0)
            {
                if (RingBuf_isEmpty(context) == false)
                {
                    printf("Testing RingBuf_increaseTail FAILED"
                        " @ ringbuf.head==%lu, ringbuf.tail==%lu\n",
                        context->head,
                        context->tail);
                    printRingBuf(context);
                    return -1;
                }
                break;
            }
            else if (context->tail != ((i+context->head+2) % context->bufferSize))
            {
                printf("Testing RingBuf_increaseTail FAILED"
                       " @ ringbuf.head==%lu, ringbuf.tail==%lu, i=%lu\n",
                       context->head,
                       context->tail,
                       i);
                printRingBuf(context);
                return -1;
            }
        }
        context->head++;
        context->head %= context->bufferSize;
    }

    return 0;
}
