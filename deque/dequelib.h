#ifndef DEQUELIB_H
#define DEQUELIB_H

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

#endif // DEQUELIB_H