#include <stdlib.h>
#include "../../headers/dynamic_utils.h"
#include <stdio.h>
/**
 * @brief To reconize several values
 */
#define FLAG -0.123456789123456789

/**
 * @brief Resize list and remove the FLAG values in DynamicArray
 * @param arr DynamicArray
 */
void refresh(DynamicArray * arr) {
    
    int nb_values = 0;
    double * temp = malloc(0 * sizeof(double));

    // Copy old array in new temporal array
    for (int i = 0; i < arr->size; i++) {
	    if (arr->array[i] != FLAG) {
            nb_values++;
	        if ((temp = realloc(temp, nb_values * sizeof(double)))) {
                temp[nb_values - 1] = arr->array[i];
            }
        }
    }

    // Init a new array
    arr->array = malloc(nb_values * sizeof(double));
    arr->size = nb_values;

    // Copy values from temporal array to current array
    for (int i = 0; i < arr->size; i++) {
	    arr->array[i] = temp[i];
    }
}

/**
 * @brief Expand array size
 * @param arr DynamicArray to expand
 * @param more Size in more
 * @return -1 if not expanded, 0 else
 */
int expand(DynamicArray * arr, int more) {
    
    int result = -1;

    if (more > 0 && (arr->array = realloc(arr->array, (arr->size + more) * sizeof(double)))) {
        arr->size += more;
        result = 0;
    }
    
    return result;
}

/**
 * @brief Decrease array size
 * @param arr DynamicArray to decrease
 * @param less Size in less
 * @return int -1 if not decreased, 0 else
 */
int decrease(DynamicArray * arr, int less) {

    int result = -1;

    if (less > 0 && (arr->array = realloc(arr->array, (arr->size - less) * sizeof(double)))) {
        arr->size -= less;
        result = 0;
    }
    
    return result;
}

/**
 * @brief Put toAdd value and shift other values
 * @param arr DynamicArray who contains values
 * @param toAdd Value to add
 * @param mark Index to add value
 */
void put_and_shift(DynamicArray * arr, double to_add, int mark) {
    
    double temp, toStore = arr->array[mark];

    arr->array[mark] = to_add;

    for (int i = mark + 1; i < arr->size; i++) {
        temp = arr->array[i];
        arr->array[i] = toStore;
        toStore = temp;
    }
}

/**
 * @brief Copy values in array
 * @param dst DynamicArray destination
 * @param src DynamicArray source
 */
void copy_values(DynamicArray * dst, DynamicArray * src) {
    for (int i = 0; i < src->size; i++) {
        dst->array[i] = src->array[i];
    }
}