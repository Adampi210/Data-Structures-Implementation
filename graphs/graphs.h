#ifndef __GRAPHS_H__
#define __GRAPHS_H__



typedef int data_type; 

typedef struct _Graph_node {
    data_type key;
    struct _Graph_node* neighbors;
    int place_in_pq;
} Graph_node;

typedef struct _Graph {
    int no_nodes;
    Graph_node* node_list;
} Graph;

#endif