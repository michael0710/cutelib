#include "testcommons.h"

static int testRingBuf(RingBufType* const context)
{
    context->tail = 0;
    for (size_t k=0; k<(context->bufferSize+5); k++)
    {
        context->head = context->tail;
        for (size_t i=0; i<context->bufferSize+5; i+=3)
        {
            if (RingBuf_increaseHeadMore(context, 3) != 0)
            {
                if (RingBuf_isFull(context) == false)
                {
                    printf("Testing RingBuf_increaseHeadMore FAILED"
                        " @ ringbuf.head==%lu, ringbuf.tail==%lu\n",
                        context->head,
                        context->tail);
                    printRingBuf(context);
                    return -1;
                }
                break;
            }
            else if (context->head != ((i+context->tail+3) % context->bufferSize))
            {
                printf("Testing RingBuf_increaseHeadMore FAILED"
                       " @ ringbuf.head==%lu, ringbuf.tail==%lu, i=%lu\n",
                       context->head,
                       context->tail,
                       i);
                printRingBuf(context);
                return -1;
            }
        }
        context->tail++;
        context->tail %= context->bufferSize;
    }

    return 0;
}
