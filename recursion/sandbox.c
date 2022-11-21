#include <stdio.h>
#include <stdlib.h>
#include "recursion.h"

int main(int argc, char const *argv[])
{   
    // Add 2 numbers recursively
    int a = recursive_adder(10, 12);
    printf("%d\n", a);

    // Calculate fibonacci number recursively
    long b = recursive_fib_number(10);
    printf("%ld\n", b);


    // BST
    printf("BST:\n");
    data_type arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
    Tnode* root_tree = create_BST(arr, 0, 8);
    print_BST_preorder(root_tree, 'b');
    destroy_BST(root_tree);


    return 0;

}
