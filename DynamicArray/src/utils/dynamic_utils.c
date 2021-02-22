#include <stdlib.h>
#include "../../headers/dynamic.h"

/**
 * @brief To reconize several values
 */
#define FLAG -0.123456789123456789

/**
 * @brief Resize list and remove the FLAG values in DynamicArray
 * @param arr DynamicArray
 */
int refresh(DynamicArray * arr) {
    
    int nbValues = 0;
    double * temp = malloc(0 * sizeof(double));
    
    // Copy old array in new temporal array
    for (int i = 0; i < arr->size; i++) {
	    if (arr->array[i] != FLAG) {
            nbValues++;
	        if ((temp = realloc(temp, (0 + nbValues) * sizeof(double)))) {
                temp[nbValues - 1] = arr->array[i];
            }
        }
    }

    if (nbValues > 0) {
        // Init a new array
        arr->array = malloc(nbValues * sizeof(double));
        arr->size = nbValues;

        // Copy values from temporal array to current array
        for (int i = 0; i < arr->size; i++) {
	        arr->array[i] = temp[i];
        }
    }
    
    return nbValues > 0 ? 0 : -1;
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
void putAndShift(DynamicArray * arr, double toAdd, int mark) {
    
    double temp, toStore = arr->array[mark];

    arr->array[mark] = toAdd;

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
void copyValues(DynamicArray * dst, DynamicArray * src) {
    for (int i = 0; i < src->size; i++) {
        dst->array[i] = src->array[i];
    }
}