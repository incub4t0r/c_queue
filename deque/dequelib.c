#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

typedef struct deque_node_t deque_node_t;
typedef struct deque_t deque_t;

int deque_destroy(deque_t *deque);
int deque_enqueue(deque_t *deque, int value);
void deque_node_print(const deque_node_t *deque_node);
void deque_print(const deque_t *deque);
void deque_reverseprint(const deque_t *deque);
int deque_leftenqueue(deque_t *deque, int value);
deque_t *deque_create(void);
int deque_isempty(const deque_t *deque);
int deque_size(const deque_t *deque);
int deque_dequeue(deque_t *deque);
int deque_leftdequeue(deque_t *deque);
// not implemented yet
deque_node_t *deque_top(const deque_t *deque);


typedef struct deque_node_t {
    deque_node_t *head;
    int value;
    deque_node_t *tail;
} deque_node_t;

typedef struct deque_t {
    deque_node_t *first;
    deque_node_t *last;
    size_t size;
} deque_t;

// a deque has the ability to queue/dequeue on the left or right
// using a master head and master tail, we can keep track of how big the queue is
// insertion for either head or tail would be O(1)
// a leftqueue would update the head to the new insertion
// a queue would update the master tail to the new insertion

// create
deque_t *deque_create(void)
{
    deque_t *new_deque = malloc(sizeof(deque_t));

    if (!new_deque)
    {
        return NULL;
    }

    new_deque->size = 0;
    new_deque->first = NULL;
    new_deque->last = NULL;
    return new_deque;
}

// destroy
int deque_destroy(deque_t *deque)
{
    if (!deque)
    {
        return 0;
    }

    while (deque->first != NULL)
    {
        deque_node_t *current = deque->first;
        deque->first = current->tail;
        free(current);
    }

    free(deque);
    return 1;
}

// queue
int deque_enqueue(deque_t *deque, int value)
{
    if (!deque)
    {
        return 0;
    }

    deque_node_t *new_node = malloc(sizeof(deque_node_t));

    if (!new_node)
    {
        printf("Failed to alloc memory for new node\n");
        return 0;
    }

    new_node->head = NULL;
    new_node->tail = NULL;
    new_node->value = value;

    if (!deque->first) // no elements in dequeue
    {
        deque->first = new_node;
        deque->last = new_node;
    }
    else
    {
        deque->last->tail = new_node;
        new_node->head = deque->last;
        deque->last = new_node;
    }
    deque->size++;
    return 1;
}

int deque_leftenqueue(deque_t *deque, int value)
{
    if (!deque)
    {
        return 0;
    }

    deque_node_t *new_node = malloc(sizeof(deque_node_t));

    if (!new_node)
    {
        printf("Failed to alloc memory for new node\n");
        return 0;
    }

    new_node->head = NULL;
    new_node->tail = NULL;
    new_node->value = value;

    if (!deque->first) // no elements in dequeue
    {
        deque->first = new_node;
        deque->last = new_node;
    }
    else
    {
        deque->first->head = new_node;
        new_node->tail = deque->first;
        deque->first = new_node;
    }
    deque->size++;
    return 1;
}

int deque_size(const deque_t *deque)
{
    return deque->size;
}

int deque_isempty(const deque_t *deque)
{
    return (0 == deque->size);
}

int deque_dequeue(deque_t *deque)
{
    if (!deque || deque_isempty(deque))
    {
        return 0;
    }

    deque_node_t *top = deque->first;
    deque->first = top->tail;
    deque->first->head = NULL;
    free(top);
    deque->size--;
    return 1;
}

int deque_leftdequeue(deque_t *deque)
{
    if (!deque || deque_isempty(deque))
    {
        return 0;
    }

    deque_node_t *bottom = deque->last;
    deque->last = bottom->head;
    deque->last->tail = NULL;
    free(bottom);
    deque->size--;
    return 1;
}





void deque_print(const deque_t *deque)
{
    deque_node_t *current = deque->first;
    while (current != NULL)
    {
        deque_node_print(current);
        current = current->tail;
    }
}

void deque_reverseprint(const deque_t *deque)
{
    deque_node_t *current = deque->last;
    while (current != NULL)
    {
        deque_node_print(current);
        current = current->head;
    }
}

void deque_node_print(const deque_node_t *deque_node)
{
    if (deque_node)
    {
        printf("Node: %d\n", deque_node->value);
    }
    else
    {
        return;
    }
}