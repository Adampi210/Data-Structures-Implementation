#ifndef __TREES_H__
#define __TREES_H__

typedef int data_type;

#include <stdbool.h>

// Tree node implementation
typedef struct _Tnode {
    data_type data;
    struct _Tnode* left;
    struct _Tnode* right;
} Tnode;

bool is_tree_empty(Tnode* root_node);

#endif