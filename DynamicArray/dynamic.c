#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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
int add(DynamicArray * arr, double toAdd) {
    
    int reallocCode = 0;
    
    if ((arr->array = realloc(arr->array, (arr->size + 1) * sizeof(double)))) {
        arr->array[arr->size] = toAdd;
        arr->size++;
    } else {
        reallocCode = -1;
    }
    
    return reallocCode;
}

/**
 * @brief Remove value at index
 * @param arr DynamicArray who contains values
 * @param removeAt Index to remove
 * @return double the removed value
 */
int rmvAt(DynamicArray * arr, int removeAt) {
    
    int removed = -1;

    if (removeAt < arr->size) {
        arr->array[removeAt] = FLAG; 
        if (refresh(arr) == 0) {
            removed = 0;
        }
    }

    return removed;
}

/**
 * @brief Remove a specified value
 * @param arr DynamicArray who contains values
 * @param toRemove Value to remove
 * @return double the removed value
 */
int rmv(DynamicArray * arr, double toRemove) {

    int removed = -1;

    for (int i = 0; i < arr->size && removed == -1; i++) {
        if (arr->array[i] == toRemove) {
            arr->array[i] = FLAG;
            removed = 0;
        }
    }

    if (removed == 0 && refresh(arr) == -1) {
        removed = -1;
    }

    return removed;
}

/**
 * @brief Remove all specified value
 * @param arr DynamicArray who contains values
 * @param toRemove Value to remove
 * @return int the number of removed values
 */
int rmvAll(DynamicArray * arr, double toRemove) {
    
    int nbRemoved = 0;

    for (int i = 0; i < arr->size; i++) {
        if (arr->array[i] == toRemove) {
            arr->array[i] = FLAG;
            nbRemoved++;
        }
    }

    if (refresh(arr) == 0) {
        nbRemoved = -1;
    }

    return nbRemoved;
}

/**
 * @brief Resize list and remove the FLAG values
 * in DynamicArray
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
 * @brief Display all values in DynamicArray
 * @param arr DynamicArray who contains values
 */
void display(DynamicArray arr) {

    for (int i = 0; i < arr.size; i++) {
        printf("%.2f ", arr.array[i]);
    }

    printf("\n");
}

/**
 * @brief Count the number 
 * @param arr DynamicArray who contains values
 * @param toCount Values to count
 * @return int the number of specified values
 */
int count(DynamicArray arr, double toCount) {

    int nbOccur = 0;

    for (int i = 0; i < arr.size; i++) {       
        if (arr.array[i] == toCount) {
            nbOccur++;
        }
    }

    return nbOccur;
}

/**
 * @brief 
 * @param arr 
 * @param toCount 
 * @return int 
 */
int indexOf(DynamicArray arr, double toCount) {

    int index = -1;

    for (int i = 0; i < arr.size && index == -1; i++) {
        if (arr.array[i] == toCount) {
            index = i;
        }
    }

    return index;
}

/**
 * @brief Sort values
 * @param arr DynamicArray who contains values
 */
void combSort(DynamicArray * arr) {

    int inter = arr->size;
    int isSwap = 1;
    int size = inter, i;
    double temp;

    while (inter > 1 || isSwap == 1) {

        inter = (int) (inter / 1.3);

        if (inter < 1) {
            inter = 1;
        }

        i = 0;
        isSwap = 0;

        while (i < size - inter) {

            if (arr->array[i] > arr->array[i + inter]) {

                temp = arr->array[i + inter];
                arr->array[i + inter] = arr->array[i];
                arr->array[i] = temp;
                isSwap = 1;
            }

            i++;
        }
    }
}

/**
 * @brief Insert ascending sort
 * @param arr DynamicArray who contains values
 */
void insertionSort(DynamicArray * arr) {

    double toInsert;
    int place;

    for (int step = 1; step < arr->size; step++) {
        toInsert = arr->array[step];    
        // search place to insert
        for (place = step; place > 0 && arr->array[place - 1] > toInsert; place--) {
            arr->array[place] = arr->array[place - 1];
        }

        arr->array[place] = toInsert;
    }
}

void insertAt(DynamicArray * arr, double toAdd, int addAt) {
    // TODO
}

void copy(DynamicArray * dst, DynamicArray * src) {
    // TODO
}