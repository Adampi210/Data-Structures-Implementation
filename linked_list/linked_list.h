#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdbool.h>

typedef int data_type;

// Node structure is equivalent to one node in the linked list
// It consits of an address to some value it stores and an address to the next node in the linked list
typedef struct _Node {
    data_type value;
    struct _Node* next;
} Node;

typedef struct _Header {
    Node* head;
    Node* tail;
} Header;

Node* insert_node_at_end_w_tail(Header* header, data_type* addr_value);
Node* insert_node_at_end_no_tail(Node** a_head, data_type* addr_value);
Node* insert_node_at_start_w_tail(Header* header, data_type* addr_value);
Node* insert_node_at_start_no_tail(Node** a_head, data_type* addr_value);
Node* remove_node_at_head(Node** a_head);
Node* remove_node_at_tail_w_tail(Header* header);
Node* remove_node_at_tail_no_tail(Node** a_head);

bool if_list_empty(Node* head);

void print_list(Node** a_head, void (*print_function)(Node* node));
void print_address_node(Node* node);
void print_values_int(Node* node);
void destroy_list(Node* node);

#endif