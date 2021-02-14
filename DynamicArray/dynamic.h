#ifndef __DYNAMIC__
#define __DYNAMIC__

typedef struct dynamic {
    int size;
    double * array;
} DynamicArray;

void create(DynamicArray * arr);

void add(DynamicArray * arr, double toAdd);

double rmvAt(DynamicArray * arr, int removeAt);

double rmv(DynamicArray * arr, double toRemove);

int rmvAll(DynamicArray * arr, double toRemove);

void refresh(DynamicArray * arr);

void display(DynamicArray arr);

#endif