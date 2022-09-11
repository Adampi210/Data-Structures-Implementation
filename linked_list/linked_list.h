#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

// Node structure is equivalent to one node in the linked list
// It consits of an address to some value it stores and an address to the next node in the linked list
typedef struct _Node{
    void* a_value;
    struct _Node* next;
} Node;

#endif