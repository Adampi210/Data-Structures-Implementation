#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*
    Queues:
        - Queue = ordered collection of items where items are inserted (enqueued) at the end and removed (dequeued) at the front
        - Can also be called FIFO - First In First Out
        - Ex: a check-out at grocery store
            - the queue is either empty or not empty
            - the cashier serves the customer at the front of the line
            - customers are ordered from the front to the end of line
            - customers can only join at the end of the line
*/

// Queue Primitive operations 
// Linked list implementation

// Put an item on the queue
Queue_node* enqueue(Queue_header* header, data_type value_to_enqueue) {
    Queue_node* new_queue_node = malloc(sizeof(*new_queue_node)); // Allocate memory for the new node
    new_queue_node -> next_node = NULL; // New rear points to NULL
    new_queue_node -> value = value_to_enqueue; 
    // If first insert then set rear and front to the new node
    if(header -> front == NULL) {
        header -> front = new_queue_node;
        header -> rear = new_queue_node;
    }
    // Enqueue at the rear
    header -> rear -> next_node = new_queue_node;
    header -> rear = new_queue_node;
    // Return the new Queue
    return header -> front;
}

// Take a front item off the queue
Queue_node* dequeue(Queue_header* header) {
    if(header -> front == NULL) return NULL;

    Queue_node* dequeued_node = header -> front; // set dequeued_node to current head
    header -> front = dequeued_node -> next_node; // Move the head to the next node
    
    return dequeued_node;
}

// Return the front item in the queue without changing the queue
Queue_node* front(Queue_header* header) {
    return(header -> front);
}

// Return the last item in the queue without changing it
Queue_node* rear(Queue_header* header) {
    if(header -> front == NULL) return NULL;
    return(header -> rear);
}

// Return if queue is empty
bool is_emtpy_queue(Queue_header* header) {
    return header -> front == NULL ? true : false; 
}

// Print queue with a specified print function
void print_queue(Queue_header* header, void (*print_function)(Queue_node* queue_node)) {
    for(Queue_node* curr = header -> front; curr != NULL; curr = curr -> next_node) {
        print_function(curr);
    }
    printf("NULL\n");
}

// Print function that prints integers
void print_int(Queue_node* queue_node) {
    printf("%d -> ", queue_node -> value);
}

// Print function that prints addresses
void print_addr(Queue_node* queue_node) {
    printf("%p -> ", queue_node);
}

// This function frees the memory of the queue and the header
void destroy_queue(Queue_header* header) {
    while(header -> front != NULL) {
        Queue_node* temp_node = header -> front;
        header -> front = temp_node -> next_node;
        free(temp_node);
    }
    free(header);
}