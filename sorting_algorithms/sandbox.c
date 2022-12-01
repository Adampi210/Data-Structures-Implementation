#include "sorting_algorithms.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {  
    clock_t start_time, end_time;
    double total_runtime;

    int size_arr = 1e6;
    int lower_bound_arr = 0;
    int upper_bound_arr = 100;
    data_type* test_arr = generate_random_arr(size_arr, lower_bound_arr, upper_bound_arr);
    
    //#define TEST_QUICKSORT
    #ifdef TEST_QUICKSORT
        start_time = clock();
        quicksort_recursion(test_arr, 0, size_arr - 1);
        end_time = clock();
        total_runtime = ((double) (end_time - start_time)) / CLOCKS_PER_SEC * 1000;
        printf("Quicksort ran in: %.2lfms.\n", total_runtime);
    #endif
    #define TEST_HEAPSORT
    #ifdef TEST_HEAPSORT
        start_time = clock();
        heapsort_w_downward_heapify(test_arr, size_arr);
        end_time = clock();
        total_runtime = ((double) (end_time - start_time)) / CLOCKS_PER_SEC * 1000;
        printf("Heapsort ran in: %.2lfms.\n", total_runtime);
    #endif
    //#define TEST_MERGESORT
    #ifdef TEST_MERGESORT
        start_time = clock();
        mergesort(test_arr, size_arr, mergesort_recursive);
        end_time = clock();
        total_runtime = ((double) (end_time - start_time)) / CLOCKS_PER_SEC * 1000;
        printf("Mergesort ran in: %.2lfms.\n", total_runtime);
    #endif
    
    // Test if array correctly sorted
    for(int i = 1; i < size_arr; ++i) {
        assert(test_arr[i - 1] <= test_arr[i]);
    }

    free(test_arr);
    return EXIT_SUCCESS;
}
