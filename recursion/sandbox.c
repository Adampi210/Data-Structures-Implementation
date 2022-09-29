#include <stdio.h>
#include <stdlib.h>
#include "recursion.h"

int main(int argc, char const *argv[])
{
    int a = recursive_adder(10, 12);
    printf("%d\n", a);

    long b = recursive_fib_number(10);
    printf("%ld\n", b);
    data_type arr[] = {1, 2, 3, 4, 5};

    Tnode* root_tree = create_BST(arr, 0, 4);

    return 0;

}
