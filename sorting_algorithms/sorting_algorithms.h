#ifndef __SORTING_ALGORITHMS_H__
#define __SORTING_ALGORITHMS_H__
#include <stdio.h>
#include <stdint.h>

typedef int data_type;

// Array operations
data_type* generate_random_arr(int size_arr, data_type lower_bound, data_type upper_bound);
void print_int_arr(int* array, int size_arr);

// Heapsort
void heapsort_w_upward_heapify(data_type* array, int size_arr);
void heapsort_w_downward_heapify(data_type* array, int size_arr);

// Quicksort
void quicksort_recursion(data_type* array, int idx_left_bound, int idx_right_bound);

// Mergesort
void mergesort_recursive(data_type* array, data_type* copy_arr, int left_idx, int right_idx);
void mergesort_iterative(data_type* array, data_type* copy_arr, int left_idx, int right_idx);
void mergesort(data_type* array, int size_arr, void (*mergesort_fn)(data_type*, data_type*, int, int));


#endif