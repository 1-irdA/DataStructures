#include <stdio.h>
#include <stdlib.h>
#include "../headers/dynamic.h"
#include "../headers/dynamic_utils.h"

/**
 * @brief To reconize several values
 */
#define FLAG -0.123456789123456789

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
int add(DynamicArray * arr, double to_add) {
    
    int reallocCode = 0;
    
    if (expand(arr, 1) == 0) {
        arr->array[arr->size - 1] = to_add;
    } else {
        reallocCode = -1;
    }
    
    return reallocCode;
}

/**
 * @brief Remove value at index
 * @param arr DynamicArray who contains values
 * @param remove_at Index to remove
 * @return 1 if removed
 */
int rmv_at(DynamicArray * arr, int remove_at) {
    
    int removed = 0;

    if (remove_at < arr->size) {
        arr->array[remove_at] = FLAG; 
        refresh(arr);
        removed = 1;
    }

    return removed;
}

/**
 * @brief Remove a specified value
 * @param arr DynamicArray who contains values
 * @param to_remove Value to remove
 * @return 1 if removed
 */
int rmv(DynamicArray * arr, double to_remove) {

    int removed = 0;

    for (int i = 0; i < arr->size && removed == 0; i++) {
        if (arr->array[i] == to_remove) {
            arr->array[i] = FLAG;
            removed = 1;
        }
    }

    if (removed == 1) {
       refresh(arr);
    }

    return removed;
}

/**
 * @brief Remove all specified value
 * @param arr DynamicArray who contains values
 * @param to_remove Value to remove
 * @return int the number of removed values
 */
int rmv_all(DynamicArray * arr, double to_remove) {
    
    int nb_removed = 0;

    for (int i = 0; i < arr->size; i++) {
        if (arr->array[i] == to_remove) {
            arr->array[i] = FLAG;
            nb_removed++;
        }
    }

    if (nb_removed > 0) {
        refresh(arr);
    }

    return nb_removed;
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
 * @param to_search Values to search
 * @return int the number of specified values
 */
int count(DynamicArray arr, double to_search) {

    int nb_occur = 0;

    for (int i = 0; i < arr.size; i++) {       
        if (arr.array[i] == to_search) {
            nb_occur++;
        }
    }

    return nb_occur;
}

/**
 * @brief Get the index of value to search
 * @param arr DynamicArray who contains values
 * @param to_search Value to search
 * @return int indesx of searched value
 */
int index_of(DynamicArray arr, double to_search) {

    int index = -1;

    for (int i = 0; i < arr.size && index == -1; i++) {
        if (arr.array[i] == to_search) {
            index = i;
        }
    }

    return index;
}

/**
 * @brief Sort values
 * @param arr DynamicArray who contains values
 */
void comb_sort(DynamicArray * arr) {

    int inter = arr->size;
    int is_swap = 1;
    int size = inter, i;
    double temp;

    while (inter > 1 || is_swap == 1) {

        inter = (int) (inter / 1.3);

        if (inter < 1) {
            inter = 1;
        }

        i = 0;
        is_swap = 0;

        while (i < size - inter) {

            if (arr->array[i] > arr->array[i + inter]) {

                temp = arr->array[i + inter];
                arr->array[i + inter] = arr->array[i];
                arr->array[i] = temp;
                is_swap = 1;
            }

            i++;
        }
    }
}

/**
 * @brief Insert ascending sort
 * @param arr DynamicArray who contains values
 */
void insertion_sort(DynamicArray * arr) {

    double to_insert;
    int place;

    for (int step = 1; step < arr->size; step++) {
        to_insert = arr->array[step];    
        // search place to insert
        for (place = step; place > 0 && arr->array[place - 1] > to_insert; place--) {
            arr->array[place] = arr->array[place - 1];
        }

        arr->array[place] = to_insert;
    }
}

/**
 * @brief Insert a value at specified position
 * @param arr DynamicArray who contains values
 * @param to_add Value to add
 * @param add_at Position to add value
 * @return -1 if not added, > 0 else
 */
int insert_at(DynamicArray * arr, double to_add, int add_at) {
    
    int oldSize = arr->size;

    if (add_at >= 0 && add_at < arr->size) {
        expand(arr, 1);
        put_and_shift(arr, to_add, add_at);
    } else if (add_at == arr->size) {
        add(arr, to_add);
    }

    return oldSize < arr->size ? 0 : -1;
}

/**
 * @brief Copy a DynamicArray in other 
 * @param dst From DynamicArray
 * @param src To DynamicArray
 */
void copy(DynamicArray * dst, DynamicArray * src) {
    
    if (dst->size < src->size) {
        expand(dst, src->size - dst->size);
    } else if (dst->size > src->size) {
        decrease(dst, dst->size - src->size);
    }

    copy_values(dst, src);
}