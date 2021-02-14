#include "dynamic.h"

int main(void) {
    
    DynamicArray arr;

    create(&arr);
    add(&arr, 12.4);
    add(&arr, 13);
    add(&arr, 90);
    display(arr);
    rmvAt(&arr, 1);
    display(arr);

    return 0;
}