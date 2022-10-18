#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>

typedef int data_type;

// Queue node structure for the linked list queue implementation
typedef struct _Queue_node {
    data_type value;
    struct _Queue_node* next_node;
} Queue_node;

// Header structure for the linked list queue implementation
typedef struct _Queue_header {
    Queue_node* front;
    Queue_node* rear;
} Queue_header;

// Structure for the array queue implementation
typedef struct _Queue_arr {
    data_type* addr_q_arr; // Array storing the queue
    int total_arr_size;    // Total size of the array
    int idx_front_q;       // Index of the front of the queue
    int idx_rear_q;        // Index of the rear of the queue
} Queue_arr;

Queue_node* enqueue(Queue_header* header, data_type value_to_enqueue);
Queue_node* dequeue(Queue_header* header);
Queue_node* front(Queue_header* header);
Queue_node* rear(Queue_header* header);
bool is_emtpy_queue(Queue_header* header);

void print_queue(Queue_header* header, void (*print_function)(Queue_node* queue_node));
void print_int(Queue_node* queue_node);
void print_addr(Queue_node* queue_node);
void destroy_queue(Queue_header* header);

#endif