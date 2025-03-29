#ifndef TESTCOMMONS_H_INCLUDED
#define TESTCOMMONS_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ringbuf.h"

#ifdef __cplusplus
extern "C"
{
#endif

static int testRingBuf(RingBufType* const context);

static int testRingBufByParams(size_t bufferByteSize, size_t elementSize)
{
    uint8_t* testBuffer = (uint8_t*)malloc(bufferByteSize);
    if (testBuffer == NULL)
    {
        printf("Pre-Test-Error: Could not allocate buffer of size %lu\n", bufferByteSize);
        return -1;
    }

    RingBufType ringbuf =
    {
        .head = 0,
        .tail = 0,
        .elementSize = elementSize,
        .buffer = testBuffer,
        .bufferSize = (size_t)(bufferByteSize/elementSize)
    };

    int rv = testRingBuf(&ringbuf);

    free(testBuffer);

    return rv;
}

static void printRingBuf(const RingBufType* const context)
{
    printf("RingBufType @ %p\n", context);
    printf("{\n");
    printf("    head = %lu\n", context->head);
    printf("    tail = %lu\n", context->tail);
    printf("    elementSize = %lu\n", context->elementSize);
    printf("    buffer = %p\n", context->buffer);
    printf("    bufferSize = %lu\n", context->bufferSize);
    printf("}\n");
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <bufferSize> <elementSize>\n", argv[0]);
        printf("argc: %d\n", argc);
        return -1;
    }

    size_t bufferByteSize = 0;
    size_t elementSize = 0;

    char* endptr;
    bufferByteSize = strtoul(argv[1], &endptr, 10);
    if (endptr == argv[1])
    {
        printf("Pre-Test-Error: Invalid bufferByteSize: %s\n", argv[1]);
        return -1;
    }

    elementSize = strtoul(argv[2], &endptr, 10);
    if (endptr == argv[2])
    {
        printf("Pre-Test-Error: Invalid elementSize: %s\n", argv[2]);
        return -1;
    }

    return testRingBufByParams(bufferByteSize, elementSize);
}

#ifdef __cplusplus
}
#endif

#endif /* TESTCOMMONS_H_INCLUDED */