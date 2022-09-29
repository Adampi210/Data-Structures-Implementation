#include <stdio.h>
#include <stdlib.h>
#include "recursion.h"

/*
    Memoy:
        call stack:
            - Every time a function is called some information is put on the stack
            - The space a function occupies is called a stack frame
            - The stack frame includes:
                - Function parameters, local variables, return address of the caller function
            - Every time some memory is being allocated and function info put on the stack
            - When the function is completed, its corresponding stack frame is popped from the call stack
            - This limits recursion - cannot call too many functions because it would overwhelm the stack
    Computation tree:
        - Computation tree shows the order in which functions are executed
        - Can be used to count how many stack frames are on the stack at a given point
    Recursion:
        - Technique of calling itself by a function
        - Essentially divide and conquer technique - decompose big problem into smaller ones
        - Keep calling itself to make smaller and smaller problems until base case is reached 
    Traversal:
        - Post-order - computation is done after all retursion calls
        - Pre-order - computation is done before all recursion calls
        - In-order - computation is done in between recursion calls
*/

/**
 * @brief This function implements an add operation recursively.
 * @param first_n - first number to add
 * @param second_n - second number to add
 * @return int - the sum of two numbers
 */
int recursive_adder(unsigned int first_n, unsigned int second_n) {
    // If the first number is not 1, call function with decreased first_n and add it to 1
    if(first_n != 1) {
        return 1 + recursive_adder(first_n - 1, second_n);
    }
    // Then if second number is not 1, call function with decreased second_n and add it to 1
    else if(second_n != 1) {
        return 1 + recursive_adder(first_n, second_n - 1);
    }
    // Otherwise first_n = second_n = 1, so the sum is 2, so return 2
    else {
        return 2;
    }
}

/**
 * @brief This function calculates a Fibonacci number corresponding to a given
 * index in the Fibonacci sequence.
 * @param idx_fib_sequence - index of the number in the Fibonacci sequence
 * @return long - value of the number in the Fibonacci sequence at the index idx_fib_sequence
 */
long recursive_fib_number(unsigned int idx_fib_sequence) {
    // If the index is 0 or 1, return the index
    // Because fib[0] = 0, and fib[1] = 1, where fib is the Fibonacci sequence
    if(idx_fib_sequence == 0 || idx_fib_sequence == 1) {
        return idx_fib_sequence;
    }
    // Otherwise use the inductive formula to calculate the sequence: fib[k] = fib[k - 1] + fib[k - 2]
    // To get the numbers recursive_fib_number with idx_fib_sequence - 1 and idx_fib_sequence - 2
    else {
        return recursive_fib_number(idx_fib_sequence - 1) + recursive_fib_number(idx_fib_sequence - 2);
    }
}

/**
 * @brief This function recursively creates a Binary Search Tree (BST) from a sorted array.
 * It does it by saving a value at the midpoint to a node and then calling itself twice. Once 
 * for a subarray of values lower than current midpoint value (and that will be node at the left),
 * and once for a subarray of values higher than current midpoint value (that will be the node to the right)
 * @param sorted_array - sorted array of values
 * @param left_most_idx_arr - left-most index of the array, initially 0, changes for the sublists
 * @param right_most_idx_arr - right-most index of the array, initially (n - 1) (size of array - 1), changes for the sublists
 * @return Tnode* - a tree node that is the root of the created binary search tree
 */
Tnode* create_BST(data_type* sorted_array, int left_most_idx_arr, int right_most_idx_arr) {
    // If the left most index is higher than the right most index, then nothing is left in the sublist
    // (The algorithm got into a sublist of size 1 and then went to a point where the sublist is empty)
    // So if nothing is left in the subarray, return NULL
    if(left_most_idx_arr > right_most_idx_arr) {
        return NULL;
    }
    // Otherwise, find the middle of the array (index of the middle element)
    // Done this way to prevent overflow (if I did (left_most_idx_arr + right_most_idx_arr) / 2 it could overflow over int range)
    int arr_middle = left_most_idx_arr + (right_most_idx_arr - left_most_idx_arr) / 2;
    // Declare and allocate memory for the new root_tree node
    Tnode* root_tree = malloc(sizeof(*root_tree));
    root_tree -> value = (*sorted_array + arr_middle);
    root_tree -> left_child = create_BST(sorted_array, left_most_idx_arr, arr_middle - 1);
    root_tree -> right_child = create_BST(sorted_array, arr_middle + 1, right_most_idx_arr);

    return root_tree;

}