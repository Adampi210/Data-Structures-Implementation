#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main(int argc, char const* argv[]) {
    // Initialize variables
    Queue_node* queue_head = NULL;
    Queue_header* q_header = malloc(sizeof(*q_header));
    q_header -> front = NULL;
    q_header -> rear = NULL;

    // Show enqueue to stdout
    for(int i = 0; i < 10; ++i) {
        enqueue(q_header, i);
    }
    print_queue(q_header, print_int);
    
    // Show dequeue to stdout
    for(int i = 0; i < 3; ++i) {
        free(dequeue(q_header));
    }
    print_queue(q_header, print_int);

    // Show other functions to stdout
    printf("Front: %d\n", front(q_header) -> value);
    printf("Rear: %d\n", rear(q_header) -> value);
    printf("Is empty: %d\n", is_emtpy_queue(q_header));

    destroy_queue(q_header);

    return 0;
}
