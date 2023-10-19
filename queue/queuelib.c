#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

typedef struct queue_node_t queue_node_t;
typedef struct queue_t queue_t;

queue_t *queue_create(void);
int queue_dequeue(queue_t *queue);
int queue_destroy(queue_t *queue);
int queue_size(const queue_t *queue);
void queue_print(const queue_t *queue);
int queue_isempty(const queue_t *queue);
int queue_enqueue(queue_t *queue, int value);
queue_node_t *queue_top(const queue_t *queue);
void queue_node_print(const queue_node_t *queue_node);

typedef struct queue_node_t {
    int value;
    queue_node_t *tail;
} queue_node_t;

typedef struct queue_t {
    queue_node_t *entry;
    size_t size;
} queue_t;

// create
queue_t *queue_create(void)
{
    queue_t *new_queue = malloc(sizeof(queue_t));

    if (!new_queue)
    {
        return NULL;
    }

    new_queue->size = 0;
    new_queue->entry = NULL;
    return new_queue;
}

// destroy
int queue_destroy(queue_t *queue)
{
    if (!queue)
    {
        return 0;
    }

    while (queue->entry != NULL)
    {
        queue_node_t *current = queue->entry;
        queue->entry = current->tail;
        free(current);
    }

    free(queue);
    return 1;
}

// queue
int queue_enqueue(queue_t *queue, int value)
{
    if (!queue)
    {
        return 0;
    }

    queue_node_t *new_node = malloc(sizeof(queue_node_t));

    if (!new_node)
    {
        printf("Failed to alloc memory for new node\n");
        return 0;
    }

    new_node->tail = NULL;
    new_node->value = value;

    if (!queue->entry)
    {
        queue->entry = new_node;
    }
    else
    {
        // Find the last node in the queue
        queue_node_t *current = queue->entry;
        while (current->tail != NULL)
        {
            current = current->tail;
        }
        current->tail = new_node; // Append the new node to the end of the queue
    }
    queue->size++;
    return 1;
}

// dequeue
int queue_dequeue(queue_t *queue)
{
    if (!queue || queue_isempty(queue))
    {
        return 0;
    }

    queue_node_t *top = queue->entry;
    queue->entry = top->tail;
    free(top);
    queue->size--;
    return 1;
}

queue_node_t *queue_top(const queue_t *queue)
{
    if (!queue)
    {
        return NULL;
    }
    return queue->entry;
}

int queue_size(const queue_t *queue)
{
    return queue->size;
}

int queue_isempty(const queue_t *queue)
{
    return (0 == queue->size);
}

void queue_print(const queue_t *queue)
{
    queue_node_t *current = queue->entry;
    while (current != NULL)
    {
        queue_node_print(current);
        current = current->tail;
    }
}

void queue_node_print(const queue_node_t *queue_node)
{
    if (queue_node)
    {
        printf("Node: %d\n", queue_node->value);
    }
    else
    {
        return;
    }
}

