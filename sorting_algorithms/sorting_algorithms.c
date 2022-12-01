#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sorting_algorithms.h"

/*
    Selection sort:

    Tournament sort:
        - Winners proceed to next round of tournament
        - Champions goes through O(logn) comparisons
        - Total number of comparisons O(n)

    Heap sort:
        - Heap - almost complete binary tree with all the child nodes having values less or equal to the parent
        - Max heap if children are less or equal to parent, min heap if children greater or equal to parent
        - Heap sort uses max-heap -> almost complete binary tree
        - Heap offers O(logn) insert and remove operations
            - It is a priority queue with O(logn) enqueue and dequeue
        - 
    Quicksort:
        - 
*/

// Basic array operation functions
/**
 * @brief Generate array of random numbers of data_type type with specified size and selected lower and upper bounds
 * 
 * @param size_arr    size of the array to be generated
 * @param lower_bound lower bound for the numbers in the array
 * @param upper_bound upper bound for the numbers in the array
 * @return data_type* pointer to the newly created array of random numbers
 */
data_type* generate_random_arr(int size_arr, data_type lower_bound, data_type upper_bound) {
    data_type* rand_arr = malloc(size_arr * sizeof(*rand_arr)); // Allocate size of the array

    srand(time(NULL)); // Initialize random number generator seed using current time
    // For all place in the array generate the number in required range
    for(int i = 0; i < size_arr; ++i) {
        *(rand_arr + i) = (rand() + lower_bound) % upper_bound;
    }
    // And return the pointer
    return rand_arr;
}

/**
 * @brief Print an integer array
 * 
 * @param array    array to be printed
 * @param size_arr size of the array
 */
void print_int_arr(int* array, int size_arr) {
    printf("Array:\n");
    for(int i = 0; i < size_arr; ++i) {
        printf("%d ", *(array + i));
    }
    printf("\n");
}

// Heapsort Functions
/**
 * @brief Add a new value to the array representing a max heap and perform an
 * upward heapify operation to keep the array as a max heap. The new value is already in
 * the array, just the size of the array changes. This way by going through the whole array
 * a max heap will be created.
 * 
 * @param array          array to be heapified into a max heap
 * @param curr_heap_size current size of the max heap
 */
static void upward_heapify(data_type* array, int curr_heap_size) {
    data_type value_to_add_heap = array[curr_heap_size];      // Value to be added to heap is the value at the current size
    int idx_value_to_add = curr_heap_size;                    // The index of that value is the current size
    int idx_parent_value_to_add = (idx_value_to_add - 1) / 2; // The index of the parent of the node in the heap is (curr_idx - 1) / 2
    // While the current index is greater than 0 (if 0 - reached top of max heap)
    // and the value of parent of the current node is lower than the value of current node 
    // Keep heapifying up
    while(idx_value_to_add > 0 && array[idx_parent_value_to_add] < value_to_add_heap) {
        // Set the current value to the value of the parent
        array[idx_value_to_add] = array[idx_parent_value_to_add];
        // Move the current index to the index of the parent
        idx_value_to_add = idx_parent_value_to_add;
        // Move the index of the parent to a new parent (which happens to be the parent of current index = current parent)
        idx_parent_value_to_add = (idx_value_to_add - 1) / 2;
    } 
    // Finally after getting to a point of either reaching max heap root OR the value of the parent is greater than current value
    // Put the current value at its calculated current index and return
    array[idx_value_to_add] = value_to_add_heap;
    return;
}

/**
 * @brief Perform a downward heapify process to keep an array a max heap array. Can be used for insertion and deletion.
 * Go down the heap from current node and check if the node should be swapped with one of its child nodes.
 * Check which child node is bigger, then if it's bigger than the current node, swap the two -> moves the current node down.
 * Can be used for creating max heap, or sorting from a heap.
 *
 * @param array        array containing the values to be arranged into the max heap
 * @param idx_curr_val index of the node that is currently being evaluated where to be inserted in the max heap
 * @param max_idx      max index at which the value can be inserted in the max heap
 */
static void downward_heapify(data_type* array, int idx_curr_val, int max_idx) {
    data_type curr_node_value = array[idx_curr_val]; // Set the current value to the value at idx_curr_size in the array
    int idx_child_arr = 2 * idx_curr_val + 1;        // Set the index of the child of current node in array to 2 * curr_idx + 1 (first look at left child)
    // Next keep doing downward heapify until idx_child_arr goes over the max index allowable - max_idx
    while(idx_child_arr <= max_idx) {
        // If the loop is not at the end of the array, and the right child is bigger than the left child
        if(idx_child_arr < max_idx && array[idx_child_arr] < array[idx_child_arr + 1]) {
            // Then increase the idx_child_arr to move it to the right child (I will swap it with the larger)
            idx_child_arr += 1;
        }
        // If the current node value is greater than the value in its largest child no more downward heapify is necessary
        // So break the loop
        if(curr_node_value >= array[idx_child_arr]) {
            break;
        }
        // Otherwise, move the larger child into the current nodes place, and change the idx_curr_val to the child index
        else {
            array[idx_curr_val] = array[idx_child_arr];
            idx_curr_val = idx_child_arr;
        }
        // Move the child idx to new child node
        idx_child_arr = 2 * idx_curr_val + 1;
    }
    // Finally after the loop finishes, place the curr_node_value in the correct place - the current idx_curr_val
    array[idx_curr_val] = curr_node_value;
    return;
}

/**
 * @brief Sort the array using heapsort and upward heapify. Firstly use upward heapify on the unsorted
 * array to create a max heap. Then, since the first value (array[0]) is always max, swap it with last value
 * in the array, and run downward heapify to create a new max heap (on the subarray of new size decreased by 1).
 * When the size of ne heap becomes 1, the array is sorted. 
 * Time complexity: O(nlog(n))
 * Auxiliary Space: O(1) (in-place algorithm)
 * 
 * @param array    array to be sorted
 * @param size_arr size of the array to be sorted
 */
void heapsort_w_upward_heapify(data_type* array, int size_arr) {
    int temp; // Stores value from array during swapping
    // Create a max heap by calling upward_heapify on all members of the array
    for(int i = 1; i < size_arr; ++i) {
        upward_heapify(array, i);
    }
    // Sort the array by swapping the values and recreating the max heap using downward_heapify on a decreased array (the sorted value is in right place)
    for(int i = size_arr - 1; i >= 1; --i) {
        // Swap
        temp = array[i];
        array[i] = array[0];
        array[0] = temp;
        // Downward heapify on the subarray to recreate a max heap
        // Start at index = 0 since that is where the last value in the heap was written
        // Go up to i - 1 -> max index of the subarray (i now has max value from previous subarray so is considered to be sorted)
        downward_heapify(array, 0, i - 1);
    }
    return;
}

/**
 * @brief Sort the array using heapsort and only downward heapify. 
 * Firstly use downward heapify on the unsorted array to create a max heap. Start at last node with
 * at least one child, and then keep going up the heap and moving the nodes in their right spots to
 * create max heap. Then, since the first value (array[0]) is always max, swap it with last value
 * in the array, and run downward heapify to create a new max heap (on the subarray of new size decreased by 1).
 * When the size of the heap becomes 1, the array is sorted. Offers time optimization over upward heapify.
 * Time complexity: O(nlog(n))
 * Auxiliary Space: O(1) (in-place algorithm)
 * 
 * @param array    array to be sorted
 * @param size_arr size of the array to be sorted
 */
void heapsort_w_downward_heapify(data_type* array, int size_arr) {
    int temp; // Stores value from array during swapping
    // First create a max heap by calling downward_heapify on last node with at least one child node
    // and going back up the array up to index 0. Allows to save up some time when creating max heap
    for(int i = size_arr / 2 - 1; i >= 0; --i) {
        // Always start at i and keep going until the end of the whole array - always size_arr - 1
        downward_heapify(array, i, size_arr - 1);
    }
    // Sort the array by swapping the values and recreating the max heap using downward_heapify on a decreased array (the sorted value is in right place)
    for(int i = size_arr - 1; i >= 1; --i) {
        // Swap
        temp = array[i];
        array[i] = array[0];
        array[0] = temp;
        // Downward heapify on the subarray to recreate a max heap
        // Start at index = 0 since that is where the last value in the heap was written
        // Go up to i - 1 -> max index of the subarray (i now has max value from previous subarray so is considered to be sorted)
        downward_heapify(array, 0, i - 1);
    }
    return;
}

// Quicksort functions
/**
 * @brief Partition an array into two parts based on the pivot = value at partition index. 
 * This function chooses pivot as the value at left bound index, and then partitions the 
 * array into two parts - values less than pivot will be on the left of pivot (have lower indecies),
 * and values greater than pivot will be on the right of pivot (have higher indecies). The function
 * partitions the array, and returns the new index of the partition -> where the pivot ended up in 
 * the array.
 * 
 * @param array           array to partition 
 * @param idx_left_bound  index of the left bound of the array
 * @param idx_right_bound index of the right bound of the array
 * @return int partition_idx index of the new partition in the array
 */
static int partition_left_bound(data_type* array, int idx_left_bound, int idx_right_bound) {
    int value_at_partition = array[idx_left_bound]; // Start partition by setting value at partition to array[left bound]
    int down_idx = idx_left_bound;                  // Set lower index to left bound index
    int up_idx = idx_right_bound;                   // Set upper index to right bound index
    
    // Go until down index meets up index
    while(down_idx < up_idx) {
        // Keep increasing the down index as long as the value in the array at that index is
        // less than the partition value AND down index doesn't go over right bound
        while(array[down_idx] <= value_at_partition && down_idx < idx_right_bound) {
            down_idx++;
        }
        // Then keep decreasing the up index as long as the value it the array at that index is greater than partition value
        while(array[up_idx] > value_at_partition) {
            up_idx--;
        }

        // If down index is less than up index then 2 values were found that can be swapped
        if(down_idx < up_idx) {
            // So swap them
            int temp = array[up_idx];
            array[up_idx] = array[down_idx];
            array[down_idx] = temp;
        }
        // And loop back to keep going
        // This way when the main loop finishes, I will know that the values less or equal to 
        // the partition value are on the left of the partition value, and the values greater than
        // the partition value will be on the right of it
    }
    // Finally, I need to swap the partition value with the value at up_idx
    // This way again I will split the array into 2 regions -> values <= partition on the left
    // and values >= partition on the right
    array[idx_left_bound] = array[up_idx];
    array[up_idx] = value_at_partition;
    // Return up_idx = new partition index (split the array into 2 arrays)
    return up_idx;
}

/**
 * @brief Run quicksort on the specified array. Each time partition the array into two subarrays,
 * left one which has values less than some pivot, and right one which has values greater than some pivot.
 * Partition function chooses the pivot and finds the partition index. Then call quicksort on the two subarrays.
 * 
 * @param array           array to be sorted
 * @param idx_left_bound  left bound index of the array
 * @param idx_right_bound right bound index of the array
 */
void quicksort_recursion(data_type *array, int idx_left_bound, int idx_right_bound)
{
    // Base case is when left bound is >= right bound -> return then
    if(idx_left_bound >= idx_right_bound) return;
    // Otherwise, find the partition index using the partition function
    int partition_idx = partition_left_bound(array, idx_left_bound, idx_right_bound);
    // And run quicksort on left and right subarrays
    quicksort_recursion(array, idx_left_bound, partition_idx - 1);
    quicksort_recursion(array, partition_idx + 1, idx_right_bound);
}

// Mergesort

int min(int left_value, int right_value) {
    if(left_value > right_value) {
        return right_value;
    }
    return left_value;
}

/**
 * @brief This function merges two sorted arrays into a 1 sorted array.
 * Used during mergesort. Not optimized.
 * 
 * @param array     array with two subarrays that will be merged
 * @param copy_arr  copy of the array used for merging
 * @param left_idx  left index in the array - indicates where the start of left subarray is
 * @param mid_idx   mid index in the array - indicates where the start of the right subarray is
 * @param right_idx right index in the array - indicates where the end of the right subarray is
 */
void merge_slow(data_type* array, data_type* copy_arr, int left_idx, int mid_idx, int right_idx) {
    // First copy the contents from array into copy array
    // Copy the two sorted subarrays:
    // left subarray starts at left idx and has a size of mid_idx - left_idx + 1
    // Right subarray starts at mid_idx + 1, and has a size of right_idx - mid_idx
    memcpy(&copy_arr[left_idx], &array[left_idx], (mid_idx - left_idx + 1) * sizeof(copy_arr[left_idx]));
    memcpy(&copy_arr[mid_idx + 1], &array[mid_idx + 1], (right_idx - mid_idx) * sizeof(copy_arr[left_idx]));
    
    // Then initialize idecies in the left and right subarrays -> will go through the subarrays
    // And compare the fields in each of the subarray
    int idx_left_array = left_idx;     // Index in the left subarray, start at left_idx
    int idx_right_array = mid_idx + 1; // Index in the right subarray, start at mid_idx + 1

    // Then go through the two subarrays, comparing the elements each time and place them in the array
    // In the correct order, based on which element is larger
    for(int idx_array = left_idx; idx_array <= right_idx; ++idx_array) {
        // First, if the left subarray index went over the mid_idx
        // Then that means the whole left subarray has been added to the new merged (sorted) array
        if(idx_left_array > mid_idx) {
            // So therefore, add item from the right subarray, and increment the index in the right subarray
            array[idx_array] = copy_arr[idx_right_array++];
        }
        // Else, if the right subarray went over the right_idx
        // Then the whole right subarray has been added to the new merged (sorted) array
        else if(idx_right_array > right_idx) {
            // So, add item from the left subarray, and increment the index in the left subarray
            array[idx_array] = copy_arr[idx_left_array++];
        }
        // Else, compare the values at current indecies in the left and right subarrays
        // If the value in the right subarray is less than the value in the left subarray (at current right and left subarray indecies)
        else if(copy_arr[idx_right_array] < copy_arr[idx_left_array]) {
            // Then add the item from the right subarray into the new merged (sorted) array
            // And increment the place in the right subarray
            array[idx_array] = copy_arr[idx_right_array++];
        }
        // Otherwise, if the value in the left subarray is less or equal to the value in the right subarray
        // At current left and right subarray indecies
        else {
            // Then add the item from the left subarray into the new merged (sorted) array
            // And increment the place in the left subarray
            array[idx_array] = copy_arr[idx_left_array++];
        }
    }
    // After merging the two subarrays, return
    return;
}

/**
 * @brief This function merges two sorted arrays into a 1 sorted array.
 * Used during mergesort. Optimized - copies the right sublist in reverse. This way there is 
 * no need to check if the index in left subarray or the right subarray went over the bound
 * 
 * @param array     array with two subarrays that will be merged
 * @param copy_arr  copy of the array used for merging
 * @param left_idx  left index in the array - indicates where the start of left subarray is
 * @param mid_idx   mid index in the array - indicates where the start of the right subarray is
 * @param right_idx right index in the array - indicates where the end of the right subarray is
 */
void merge_fast(data_type* array, data_type* copy_arr, int left_idx, int mid_idx, int right_idx) {
    // First initialize idecies in the left and right subarrays -> will go through the subarrays
    // And compare the fields in each of the subarray
    // This time start idx_right_array at right_idx
    int idx_left_array = left_idx;     // Index in the left subarray, start at left_idx
    int idx_right_array = right_idx;   // Index in the right subarray, start at right_idx

    // Then copy the contents from array into copy array
    // Copy the two sorted subarrays:
    // left subarray starts at left idx and has a size of mid_idx - left_idx + 1
    memcpy(&(copy_arr[left_idx]), &(array[left_idx]), (mid_idx - left_idx + 1) * sizeof(copy_arr[left_idx]));
    
    // Optimization: copy the right subarray in reverse:
    // In the array, start at mid_idx + 1 (where the right subarray normally starts)
    // And go up to the right idx
    for(int idx_array = mid_idx + 1; idx_array <= right_idx; ++idx_array) {
        // Copy the value from the right subarray in reverse (idx_right_array starts at the end of the right array)
        copy_arr[idx_array] = array[idx_right_array];
        // And decrease the index in the right array
        --idx_right_array;
    }
    // Then, reset the index in the right array to start at the end of the right subarray again (which is now in reverse so starts at smallest value in right subarray)
    idx_right_array = right_idx;

    // Then go through the two subarrays, comparing the elements each time and place them in the array
    // In the correct order, based on which element is larger
    for (int idx_array = left_idx; idx_array <= right_idx; ++idx_array) {
        // If the value in right subarray is less than the value in left subarray
        // At current indecies in both subarray
        if(copy_arr[idx_right_array] < copy_arr[idx_left_array]) {
            // Then insert that value in the new merged (sorted) array
            // And decrease the index in the right subarray (size it's reversed - so index decreases)
            array[idx_array] = copy_arr[idx_right_array--];
        }
        // Otherwise, the value in left subarray is less or equal to the value in right subarray
        // At current indecies in both subarrays
        else {
            // So insert that value in the new merged (sorted) array
            // And increase the index in left subarray
            array[idx_array] = copy_arr[idx_left_array++];
        }
        // One of these two conditions will always be satisfied because the left and right subarrays
        // Are both sorted respecively, so if I get to the end of one of the arrays then the values in the other
        // will always be either larger or smaller (so one of the conditions above will be satisfied)
    }
    // After merging the two subarrays, return
    return;
}

/**
 * @brief Sort the values in the array using recrusive mergesort method. This method goes DOWN then UP
 * starts at the full array and divides it into smaller and smaller subarrays until it gets to arrays of size 1 - base case
 * Then it goes up, and merges respective subarrays each time into new sorted merged arrays.
 * 
 * @param array     address of the array to be sorted
 * @param copy_arr  copy of the array used when merging
 * @param left_idx  left index in the array to be sorted
 * @param right_idx right index in the array to be sorted
 */
void mergesort_recursive(data_type* array, data_type* copy_arr, int left_idx, int right_idx) {
    // Base condition - if left index is the same or greater than the right index, then the array has 1 element (or none)
    // So it is already sorted, so return
    if(left_idx >= right_idx) {
        return;
    }
    int mid_idx = (left_idx + right_idx) / 2; // First find the middle index, where the array is split into the two
    // Sorted subarrays -> left and right subarray, each sorted
    mergesort_recursive(array, copy_arr, left_idx, mid_idx);       // Then mergesort the left subarray recursively
    mergesort_recursive(array, copy_arr, mid_idx + 1, right_idx);  // And mergesort the right subarray recursively
    merge_slow(array, copy_arr, left_idx, mid_idx, right_idx);     // Finally, merge the two sorted subarrays into a new sorted array
    // And return
    return;
}

/**
 * @brief Sort the values in the array using iterative mergesort method. This method goes UP - 
 * divides the array into single elements and merges them into arrays with increasing sizes until
 * a single sorted (fully merged) array is created
 * 
 * @param array     address of the array to be sorted
 * @param copy_arr  copy of the array used when merging
 * @param left_idx  left index in the array to be sorted
 * @param right_idx right index in the array to be sorted
 */
void mergesort_iterative(data_type* array, data_type* copy_arr, int left_idx, int right_idx) {
    // The function would normally accept different parameters, but is structured this way so that
    // It can be passed into another function
    int size_full_arr = right_idx + 1; // Initialize size of the full array as the right index + 1
    int size_subarrays = 1;            // Initialize size of the subarrays - start at each having 1 element
    int start_idx_subarr;              // Declare start index of subarray - will change for each subarray
    // Then keep going as long as the size of the subarrays is less than the full array size
    // When the size of the subarrays eclipses the full arrays size then that's after the final merge -> so stop
    while(size_subarrays < size_full_arr) {
        // Set starting index for the subarrays at 0 (start at leftmost subarray)
        start_idx_subarr = 0;

        // Then go through each of the subarrays and merge them - merge 2 subarrays at a time
        while(start_idx_subarr < size_full_arr - size_subarrays) {
            merge_fast(array, copy_arr, start_idx_subarr, start_idx_subarr + size_subarrays - 1, min(start_idx_subarr + 2 * size_subarrays - 1, size_full_arr - 1));
            start_idx_subarr = start_idx_subarr + 2 * size_subarrays;
        }
        size_subarrays *= 2;
    }
    return;
}

/**
 * @brief Uses one of the mergesort functions of a specific type to sort the array.
 * 
 * @param array        array to be sorted
 * @param size_arr     size of the array to be sorted
 * @param mergesort_fn mergesort function of a certain type specyfing which method should be used to sort
 */
void mergesort(data_type* array, int size_arr, void (*mergesort_fn)(data_type*, data_type*, int, int)) {
    data_type* temp_copy_arr = malloc(size_arr * sizeof(*temp_copy_arr));
    mergesort_fn(array, temp_copy_arr, 0, size_arr - 1);
    free(temp_copy_arr);
}