#include <stdio.h>
#include <stdlib.h>
#include "queue/queuelib.h"

int main(void)
{
    queue_t *queue = queue_create();
    if (!queue)
    {
        printf("Failed to create queue\n");
        exit(EXIT_FAILURE);
    }
    printf("Created queue!\n");

    for (int idx = 0; idx < 20; idx++)
    {
        printf("Enqueueing %d\n", idx);
        queue_enqueue(queue, idx);
    }
    queue_print(queue);

    for (int idx = 0; idx < 5; idx++)
    {
        queue_deque(queue);
    }
    queue_print(queue);
    queue_destroy(queue);
    exit(EXIT_SUCCESS);
}