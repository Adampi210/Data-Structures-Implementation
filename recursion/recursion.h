#ifndef __RECURSION_H__
#define __RECURSION_H__

typedef int data_type;

// This structure is the node of the binary tree
// It stores the value of the node and two addresses of child nodes - left child and right child
typedef struct _Tnode{
    data_type value;
    struct _Tnode* left_child;
    struct _Tnode* right_child;
} Tnode;

int recursive_adder(unsigned int first_n, unsigned int second_n);
long recursive_fib_number(unsigned int idx_fib_sequence);
Tnode* create_BST(data_type* sorted_array, int left_most_idx_arr, int right_most_idx_arr);

#endif