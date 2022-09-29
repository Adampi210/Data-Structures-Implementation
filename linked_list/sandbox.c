#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(int argc, char const *argv[])
{
    Node* head = NULL;
    Node* tail = NULL;
    Header* header = malloc(sizeof(*header));
    header -> head = head;
    header -> tail = tail;

    for(int i = 0; i < 7; ++i) {
        int akaf_adam = i; // fix
        insert_node_at_end_w_tail(header, &akaf_adam);
    }


    print_list_addresses(&(header -> head), print_values_int);

    return 0;
}
