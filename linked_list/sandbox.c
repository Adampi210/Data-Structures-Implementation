#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(int argc, char const *argv[])
{
    // Declare and initialize header
    Header* header = malloc(sizeof(*header));
    header -> head = NULL;
    header -> tail = NULL;

    // Insert nodes at the end with the tail
    for(int i = 0; i < 7; ++i) {
        insert_node_at_end_w_tail(header, &i);
    }

    // Insert a value without the tail
    data_type insert_val_0 = 42;
    insert_node_at_end_no_tail(&(header -> head), &insert_val_0);

    // Print the list
    print_list(&(header -> head), print_values_int);

    // Insert some nodes at the start with and without the tail
    for(int i = -4; i < 0; ++i) {
        insert_node_at_start_w_tail(header, &i);
    }

    insert_val_0 *= -1;
    insert_node_at_start_no_tail(&(header -> head), &insert_val_0);

    // Print the list
    print_list(&(header -> head), print_values_int);

    // Remove nodes using different functions (also free removed nodes)
    free(remove_node_at_head(&(header -> head)));
    free(remove_node_at_tail_no_tail(&(header -> head)));
    free(remove_node_at_tail_w_tail(header));

    // Print the list
    print_list(&(header -> head), print_values_int);

    destroy_list(header -> head); // Free the list memory
    free(header); // Free header memory
    return 0;
}
