#include <stdio.h>
#include <stdlib.h>
#include "dynamic.h"

/**
 * @brief To reconize several values
 */
#define FLAG -0.123456789

/**
 * @brief Create the DynamicArray
 * @param arr DynamicArray to create
 */
void create(DynamicArray * arr) {
    arr->size = 0;
    arr->array = malloc(0 * sizeof(double));
}

/**
 * @brief Add in DynamicArray
 * @param arr DynamicArray who contains values
 * @param toAdd Value to add
 */
void add(DynamicArray * arr, double toAdd) {
    arr->array = realloc(arr->array, 1);
    arr->array[arr->size] = toAdd;
    arr->size++;
}

/**
 * @brief Remove value at index
 * @param arr DynamicArray who contains values
 * @param removeAt Index to remove
 * @return double the removed value
 */
double rmvAt(DynamicArray * arr, int removeAt) {
    if (removeAt <= arr->size) {
        arr->array[removeAt] = FLAG;
        // refresh
    }
}

/**
 * @brief Remove a specified value
 * @param arr DynamicArray who contains values
 * @param toRemove Value to remove
 * @return double the removed value
 */
double rmv(DynamicArray * arr, double toRemove) {

    double value = FLAG;

    for (int i = 0; i < arr->size && value == FLAG; i++) {
        if (arr->array[i] == toRemove) {
            arr->array[i] = FLAG;
            value = arr->array[i];
        }
    }

    return value;
}

/**
 * @brief Remove all specified value
 * @param arr DynamicArray who contains values
 * @param toRemove Value to remove
 * @return int the number of removed values
 */
int rmvAll(DynamicArray * arr, double toRemove) {
    // TODO
}

void refresh(DynamicArray * arr) {
    // TODO
    // arr->size--;
}

/**
 * @brief Display all values in DynamicArray
 * @param arr DynamicArray who contains values
 */
void display(DynamicArray arr) {
    for(int i = 0; i < arr.size; i++) {
        printf("%.2f ", arr.array[i]);
    }
}

// int count
// int indexOf
// void sort