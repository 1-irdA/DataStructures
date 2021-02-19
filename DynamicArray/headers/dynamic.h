#ifndef __DYNAMIC__
#define __DYNAMIC__

typedef struct dynamic {
    int size;
    double * array;
} DynamicArray;

void create(DynamicArray * arr);

int add(DynamicArray * arr, double toAdd);

int rmvAt(DynamicArray * arr, int removeAt);

int rmv(DynamicArray * arr, double toRemove);

int rmvAll(DynamicArray * arr, double toRemove);

int refresh(DynamicArray * arr);

void display(DynamicArray arr);

int count(DynamicArray arr, double toSearch);

int indexOf(DynamicArray arr, double toSearch);

void combSort(DynamicArray * arr);

void insertionSort(DynamicArray * arr);

int insertAt(DynamicArray * arr, double toAdd, int addAt);

void copy(DynamicArray * dst, DynamicArray * src);

void putAndShift(DynamicArray * arr, double toAdd, int mark);

int expand(DynamicArray * arr, int more);

#endif