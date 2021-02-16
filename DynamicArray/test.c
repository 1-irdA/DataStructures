#include <stdio.h>
#include "dynamic.h"

#define NB_TESTS 9

/**
 * @brief To reconize several values
 */
#define FLAG -0.123456789

void testCreate(int * nbSuccess);
void testAdd(int * nbSuccess);
void testRmvAtInIndex(int * nbSuccess);
void testRmvAtOutIndex(int * nbSuccess);
void testRmv(int * nbSuccess);
void testRmvAll(int * nbSuccess);
void testCount(int * nbSuccess);
void testIndexOfIsPresent(int * nbSuccess);
void testIndexOfIsNotPresent(int * nbSuccess);
void displayStatus(int nbSuccess);

/**
 * @brief Launch test
 * @return int program code
 */
int main(void) {

    int nbSuccess = 0;
    
    testCreate(&nbSuccess);
    testAdd(&nbSuccess);
    testRmvAtInIndex(&nbSuccess);
    testRmvAtOutIndex(&nbSuccess);
    testRmv(&nbSuccess);
    testRmvAll(&nbSuccess);
    testCount(&nbSuccess);
    testIndexOfIsPresent(&nbSuccess);
    testIndexOfIsNotPresent(&nbSuccess);

    displayStatus(nbSuccess);

    return 0;
}

/**
 * @brief Test create function
 * @param nbSuccess Number of passed tests
 */
void testCreate(int * nbSuccess) {

    DynamicArray arr;

    create(&arr);

    if (arr.size == 0 && arr.array != NULL) {
        (*nbSuccess)++;
    } else {
        printf("Fail : testCreate\n");
    }
}

/**
 * @brief Test add function
 * @param nbSuccess Number of passed tests
 */
void testAdd(int * nbSuccess) {

    DynamicArray arr;
    double toAdd = 12.00;
    int oldSize;

    create(&arr);
    
    oldSize = arr.size;

    if (add(&arr, toAdd) == 0 
        && arr.size == 1 
        && arr.array[0] == toAdd
        && oldSize < arr.size) {
        (*nbSuccess)++;
    } else {
        printf("Fail : testAdd\n");
    }
}

/**
 * @brief Test rmvAt function with index in array
 * @param nbSuccess Number of passed tests
 */
void testRmvAtInIndex(int * nbSuccess) {

    DynamicArray arr;
    double num = 12.00;
    int index = 10, oldSize;

    create(&arr);
 
    for (int i = 0; i < num; i++) {
        add(&arr, num * i);
    }

    oldSize = arr.size;

    if (rmvAt(&arr, index) == 0 && oldSize > arr.size) {
        (*nbSuccess)++;
    } else {
        printf("Fail : testRmvAtInIndex\n");
    }
}

/**
 * @brief Test rmvAt function with index out array
 * @param nbSuccess Number of passed tests
 */
void testRmvAtOutIndex(int * nbSuccess) {

    DynamicArray arr;
    double num = 12.00;
    int index = 13, oldSize;

    create(&arr);
 
    for (int i = 0; i < index; i++) {
        add(&arr, num * i);
    }

    oldSize = arr.size;

    if (rmvAt(&arr, index) == -1 && oldSize == arr.size) {
        (*nbSuccess)++;
    } else {
        printf("Fail : testRmvAtOutIndex\n");
    }
}

/**
 * @brief Test rmv function
 * @param nbSuccess Number of passed tests
 */
void testRmv(int * nbSuccess) {

    DynamicArray arr;
    double num = 12.00;

    create(&arr);
    add(&arr, num);
    add(&arr, num);
    add(&arr, num);
    add(&arr, num);
    add(&arr, num);
    add(&arr, num);

    if (rmv(&arr, num) == 0) {
        (*nbSuccess)++;
    } else {
        printf("Fail : testRmv\n");
    }
}

/**
 * @brief Test rmvAll function
 * @param nbSuccess Number of passed tests
 */
void testRmvAll(int * nbSuccess) {

    DynamicArray arr;
    double num = 12.00;
    int nbToAdd = 6;

    create(&arr);
    
    for (int i = 0; i < nbToAdd; i++) {
        add(&arr, num);
    }

    if (rmvAll(&arr, num) == nbToAdd) {
        (*nbSuccess)++;
    } else {
        printf("Fail at testRmvAll\n");
    }
}

/**
 * @brief Test count function
 * @param nbSuccess Number of passed tests
 */
void testCount(int * nbSuccess) {

    DynamicArray arr;
    double num = 12.00;
    int nbToAdd = 6;

    create(&arr);
    
    for (int i = 0; i < nbToAdd; i++) {
        add(&arr, num);
    }

    if (count(arr, num) == nbToAdd) {
        (*nbSuccess)++;
    } else {
        printf("Fail at testCount\n");
    }
}

/**
 * @brief Test indexOf function with present number
 * @param nbSuccess Number of passed tests
 */
void testIndexOfIsPresent(int * nbSuccess) {

    DynamicArray arr;

    create(&arr);
    add(&arr, 9.87);
    add(&arr, 10.54);
    add(&arr, -89.81);
    add(&arr, 0.3);
    add(&arr, -897.6);
    add(&arr, 15);

    if (indexOf(arr, -89.81) == 2) {
        (*nbSuccess)++;
    } else {
        printf("Fail : testIndexOfIsPresent\n");
    }
}

/**
 * @brief Test indexOf function with not present number
 * @param nbSuccess Number of passed tests
 */
void testIndexOfIsNotPresent(int * nbSuccess) {

    DynamicArray arr;

    create(&arr);
    add(&arr, 9.87);
    add(&arr, 10.54);
    add(&arr, -89.81);
    add(&arr, 0.3);
    add(&arr, -897.6);
    add(&arr, 15);

    if (indexOf(arr, 1001) == -1) {
        (*nbSuccess)++;
    } else {
        printf("Fail : testIndexOfIsNotPresent\n");
    }
}

/**
 * @brief Display the number of passed tests
 * @param nbSuccess Number of passed tests
 */
void displayStatus(int nbSuccess) {
    printf("PASSED %d / %d\n", nbSuccess, NB_TESTS);
}