#include "../../headers/tests_utils.h"

/**
 * @brief Compare 2 arrays
 * @param toCompareWithB Array A to compare with array B
 * @param sizeOfA Size of array A 
 * @param toCompareWithA Array B to compare with array A
 * @param sizeOfB Size of array B
 * @return 0 if equals, -1 else
 */
int compare(double * toCompareWithB, int sizeOfA, double * toCompareWithA, int sizeOfB) {

    int i = -1;

    if (sizeOfA == sizeOfB) {      
        for (i = 0; i < sizeOfA && toCompareWithB[i] == toCompareWithA[i]; i++);
    }

    return i == sizeOfA ? 0 : -1;
}