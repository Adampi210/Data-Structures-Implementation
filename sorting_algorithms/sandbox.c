#include "sorting_algorithms.h"
#include <assert.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {   
    int size_arr = 1e7;
    int lower_bound_arr = 0;
    int upper_bound_arr = 10000;
    data_type* test_arr = generate_random_arr(size_arr, lower_bound_arr, upper_bound_arr);
    heapsort_w_downward_heapify(test_arr, size_arr);

    for(int i = 1; i < size_arr; ++i) {
        assert(test_arr[i - 1] <= test_arr[i]);
    }
    free(test_arr);
    return 0;
}
