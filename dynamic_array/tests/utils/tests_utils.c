#include "../../headers/tests_utils.h"

/**
 * @brief Compare 2 arrays
 * @param to_compare_with_b Array A to compare with array B
 * @param size_of_a Size of array A 
 * @param to_compare_with_a Array B to compare with array A
 * @param sizeOfB Size of array B
 * @return 1 if equals, 0 else
 */
int compare(double * to_compare_with_b, int size_of_a, double * to_compare_with_a, int size_of_b) {

    int i = -1;

    if (size_of_a == size_of_b) {      
        for (i = 0; i < size_of_a && to_compare_with_b[i] == to_compare_with_a[i]; i++);
    }

    return i == size_of_a ? 1 : 0;
}