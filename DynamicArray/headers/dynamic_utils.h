#ifndef __DYNAMICUTILS__
#define __DYNAMICUTILS__

#include "dynamic.h"

int refresh(DynamicArray * arr);

int expand(DynamicArray * arr, int more);

int decrease(DynamicArray * arr, int less);

void putAndShift(DynamicArray * arr, double toAdd, int mark);

void copyValues(DynamicArray * dst, DynamicArray * src);

#endif