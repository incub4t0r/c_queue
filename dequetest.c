
#include <stdio.h>
#include <stdlib.h>
#include "deque/dequelib.h"

int main(void)
{
    deque_t *deque = deque_create();
    if (!deque)
    {
        printf("Failed to create deque\n");
        exit(EXIT_FAILURE);
    }
    printf("Created deque!\n");

    for (int idx = 0; idx < 10; idx++)
    {
        printf("Enqueueing %d\n", idx);
        deque_enqueue(deque, idx);
    }
    for (int idx = 100; idx > 90; idx--)
    {
        printf("Left enqueueing %d\n", idx);
        deque_leftenqueue(deque, idx);
    }
    deque_print(deque);
    // deque_reverseprint(deque);
    printf("Dequeueing the top 5 and bottom 5\n");
    for (int idx = 0; idx < 5; idx++)
    {
        deque_dequeue(deque);
        deque_leftdequeue(deque);
    }
    deque_print(deque);
    // deque_reverseprint(deque);
    deque_destroy(deque);
    exit(EXIT_SUCCESS);
}