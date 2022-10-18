#include <stdio.h>
#include <stdlib.h>
#include "trees.h"

/*
    Trees:
        - Recursive definition: 
            - 1 node is a tree by itself
            - An ordered collection of a root node and one or more disjoint trees that are children of the root node
        - Other definition: A graph that has no cycles and a single path between any 2 nodes
        - Trees are useful for reducing the complexity and finding solutions

        - Binary tree - has at most 2 children per node
        - n-ary tree - has at most n children per node
    
    Complete Binary tree:
        - All levels up to the tree depth are filled completely 
            - All non-leaf nodes have two child nodes
        - At each level L there are 2^L nodes (pow(2, L))
        - Tree height (depth) h, number of leaf nodes = 2^h
        - Number of nodes = 2^(h+1) - 1
        - Tree height h = O(log(n))
    
    Strictly Binary tree:
        - Every node has either 0 or 2 children
            - 0 = leaf node
            - 2 = non-leaf (internal) node
        - When there are n leaf nodes, the total number of nodes is 2n - 1
        - Ex: huffman coding, mathematical expression involving operators of 2 operands

*/

bool is_tree_empty(Tnode* root_node) {
    return(root_node == NULL);
}

// Create a binary tree by filling all its levels one by one
Tnode* create_binary_tree(data_type* array_data) {
    // TODO
}

