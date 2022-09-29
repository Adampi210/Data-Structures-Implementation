#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
/*
    This file contains several functions that are used to create, manipulate, and destroy a list
*/

// This function adds a node at the end of a linked list
// And returns the address of the head of the linked list
// Note: this functiona assumes the user is keeping track of the tail of the list
Node* insert_node_at_end_w_tail(Header* header, data_type* addr_value) {
    // declare and initialize a new tail that will be added to the end of the linked list
    Node* new_tail = malloc(sizeof(*new_tail));
    new_tail -> value = *addr_value;
    new_tail -> next = NULL;
    // If value at the address of the head was empty, set that value to new_tail
    if((header -> head) == NULL) {
        header -> head = new_tail;
    }
    // else, point the current tail to the new tail
    // This will only run when *a_tail exists, so not the first time (when no *a_head is defined, no *a_tail is defined)
    else {
        header -> tail -> next = new_tail;
    }
    // Finally set the current tail to new tail (move the tail)
    header -> tail = new_tail;

    // Return the value at a_head (address of head)
    return header -> head;
}

Node* insert_node_at_end_no_tail(Node** a_head, data_type* addr_value) {
    Node* new_tail = malloc(sizeof(*new_tail));
    Node* curr_tail = *a_head;

    new_tail -> value = *addr_value;
    new_tail -> next = NULL;

    if((*a_head) == NULL) {
        *a_head = new_tail;
    }
    else {
        // Move through the list until the end of it
        while(curr_tail -> next != NULL) {
            curr_tail = curr_tail -> next;
        }
        // insert the new tail at the end of the list
        curr_tail -> next = new_tail;
    }

    return *a_head;
}

Node* insert_node_at_start_w_tail(Header* header, data_type* addr_value) {
    Node* new_head = malloc(sizeof(*new_head));
    new_head -> value = *addr_value;
    new_head -> next = header -> head;
    header -> head = *(&new_head);
    return new_head;
}

Node* insert_node_at_start_no_tail(Node** a_head, data_type* addr_value) {
    Node* new_head = malloc(sizeof(*new_head));
    new_head -> value = *addr_value;
    new_head -> next = *a_head;
    *a_head = *(&new_head);
    return new_head;
}

bool if_list_empty(Node* head) {
    if(head == NULL) {
        return true;
    }
    return false;
}

Node* remove_node_at_head(Node** a_head) {
    Node* temp_node = (*a_head) -> next;
    *a_head = temp_node;

    return temp_node;
}

Node* remove_node_at_tail_w_tail(Header* header) {
    Node* temp_node = header -> head;

    while(temp_node -> next != header -> tail) {
        temp_node = temp_node -> next;
    }
    Node* temp_new_tail = temp_node;
    temp_node = temp_node -> next;
    temp_new_tail -> next = NULL;
    header -> tail = temp_new_tail;

    return temp_node;
}

Node* remove_node_at_tail_no_tail(Node** a_head) {
    Node* temp_node = *a_head;
    while(temp_node -> next -> next != NULL) {
        temp_node = temp_node -> next;
    }
    Node* old_tail = temp_node -> next;
    temp_node -> next = NULL;

    return old_tail;
}

void print_list_addresses(Node** a_head, void (*print_function)(Node* node)) {
    Node* temp = *a_head;
    while(temp != NULL) {
        print_function(temp);
        temp = temp -> next;
    }
    printf("NULL\n");
}

void print_address_node(Node* node) {
    printf("%p -> ", node);
}

void print_values_int(Node* node) {
    int int_value = node -> value;
    printf("%d -> ", int_value);
}