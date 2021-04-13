#ifndef __DYNAMIC__
#define __DYNAMIC__

typedef struct dynamic {
    int size;
    double * array;
} DynamicArray;

void create(DynamicArray * arr);

int add(DynamicArray * arr, double to_add);

int rmv_at(DynamicArray * arr, int remove_at);

int rmv(DynamicArray * arr, double to_remove);

int rmv_all(DynamicArray * arr, double to_remove);

void display(DynamicArray arr);

int count(DynamicArray arr, double to_search);

int index_of(DynamicArray arr, double to_search);

void comb_sort(DynamicArray * arr);

void insertion_sort(DynamicArray * arr);

int insert_at(DynamicArray * arr, double to_add, int add_at);

void copy(DynamicArray * dst, DynamicArray * src);

void put_and_shift(DynamicArray * arr, double to_add, int mark);

int expand(DynamicArray * arr, int more);

#endif