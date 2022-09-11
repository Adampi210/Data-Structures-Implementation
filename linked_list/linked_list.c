#include <stdio.h>
#include "linked_list.h"
/*
    This file contains several functions that are used to create, manipulate, and destroy a list
*/

// This function adds a node at the end of a linked list
// And returns the address of the head of the linked list
// Note: this functiona assumes the user is keeping track of the tail of the list
Node* insert_node_at_end_w_tail(Node** a_head, Node** a_tail, void* addr_value) {
    // declare and initialize a new tail that will be added to the end of the linked list
    Node* new_tail = malloc(sizeof(*new_tail));
    new_tail -> a_value = addr_value;
    new_tail -> next = NULL;
    // If value at the address of the head was empty, set that value to new_tail
    if((*a_head) == NULL) {
        *a_head = new_tail;
    }
    // else, point the current tail to the new tail
    // This will only run when *a_tail exists, so not the first time (when no *a_head is defined, no *a_tail is defined)
    else {
        (*a_tail) -> next = new_tail;
    }
    // Finally set the current tail to new tail (move the tail)
    *a_tail = new_tail;

    // Return the value at a_head (address of head)
    return *a_head;
}

// 
Node* insert_node_at_end_no_tail(Node** a_head, void* addr_value) {
    Node* new_tail = malloc(sizeof(*new_tail));
    Node* curr_tail = *a_head;

    new_tail -> a_value = addr_value;
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


