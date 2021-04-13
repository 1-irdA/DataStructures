#ifndef __DYNAMICUTILS__
#define __DYNAMICUTILS__

#include "dynamic.h"

void refresh(DynamicArray * arr);

int expand(DynamicArray * arr, int more);

int decrease(DynamicArray * arr, int less);

void put_and_shift(DynamicArray * arr, double to_add, int mark);

void copy_values(DynamicArray * dst, DynamicArray * src);

#endif