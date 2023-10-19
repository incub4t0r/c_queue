#ifndef QUEUELIB_H
#define QUEUELIB_h

typedef struct queue_node_t_ queue_node_t;
typedef struct queue_t_ queue_t;

int queue_deque(queue_t *queue);
int queue_destroy(queue_t *queue);
int queue_enqueue(queue_t *queue, int value);
int queue_isempty(const queue_t *queue);
int queue_size(const queue_t *queue);
queue_node_t *queue_top(const queue_t *queue);
queue_t *queue_create(void);
void queue_node_print(const queue_node_t *queue_node);
void queue_print(const queue_t *queue);


#endif // QUEUELIB_H