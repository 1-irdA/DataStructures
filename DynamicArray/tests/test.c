#include <stdio.h>
#include "../headers/dynamic.h"
#include "../headers/tests_utils.h"

/**
 * @brief To reconize several values
 */
#define FLAG -0.123456789

void testCreate(int * nbTests, int * nbSuccess);
void testAdd(int * nbTests, int * nbSuccess);
void testRmvAtInIndex(int * nbTests, int * nbSuccess);
void testRmvAtOutIndex(int * nbTests, int * nbSuccess);
void testRmv(int * nbTests, int * nbSuccess);
void testRmvAll(int * nbTests, int * nbSuccess);
void testCount(int * nbTests, int * nbSuccess);
void testIndexOfIsPresent(int * nbTests, int * nbSuccess);
void testIndexOfIsNotPresent(int * nbTests, int * nbSuccess);
void testExpand(int * nbTests, int * nbSuccess);
void testExpandWithZeroMore(int * nbTests, int * nbSuccess);
void testExpandWithNegativeMore(int * nbTests, int * nbSuccess);
void testInsertAtInArrayAtBegin(int * nbTests, int * nbSuccess);
void testInsertAtInArrayAtEnd(int * nbTests, int * nbSuccess);
void testInsertAtNegativeIndex(int * nbTests, int * nbSuccess);
void testInsertAtBiggerIndex(int * nbTests, int * nbSuccess);
void testCopyWithSameSize(int * nbTests, int * nbSuccess);
void testCopyWithSrcSizeBigger(int * nbTests, int * nbSuccess);
void testCopyWithSrcSizeLower(int * nbTests, int * nbSuccess);

void displayStatus(int nbTests, int nbSuccess);

/**
 * @brief Launch test
 * @return int program code
 */
int main(void) {

    int nbTests = 0, nbSuccess = 0;
    
    testCreate(&nbTests, &nbSuccess);
    testAdd(&nbTests, &nbSuccess);
    testRmvAtInIndex(&nbTests, &nbSuccess);
    testRmvAtOutIndex(&nbTests, &nbSuccess);
    testRmv(&nbTests, &nbSuccess);
    testRmvAll(&nbTests, &nbSuccess);
    testCount(&nbTests, &nbSuccess);
    testIndexOfIsPresent(&nbTests, &nbSuccess);
    testIndexOfIsNotPresent(&nbTests, &nbSuccess);
    testExpand(&nbTests, &nbSuccess);
    testExpandWithZeroMore(&nbTests, &nbSuccess);
    testExpandWithNegativeMore(&nbTests, &nbSuccess);
    testInsertAtInArrayAtBegin(&nbTests, &nbSuccess);
    testInsertAtInArrayAtEnd(&nbTests, &nbSuccess);
    testInsertAtNegativeIndex(&nbTests, &nbSuccess);
    testInsertAtBiggerIndex(&nbTests, &nbSuccess);
    testCopyWithSameSize(&nbTests, &nbSuccess);
    testCopyWithSrcSizeBigger(&nbTests, &nbSuccess);
    testCopyWithSrcSizeLower(&nbTests, &nbSuccess);

    displayStatus(nbTests, nbSuccess);

    return 0;
}

/**
 * @brief Test create function
 * @param nbTests Number of tests
 * @param nbSuccess Number of passed tests
 */
void testCreate(int * nbTests, int * nbSuccess) {

    DynamicArray arr;

    create(&arr);

    if (arr.size == 0 && arr.array != NULL) {
        (*nbSuccess)++;
    } else {
        printf("Fail : testCreate\n");
    }

    (*nbTests)++;
}

/**
 * @brief Test add function
 * @param nbTests Number of tests
 * @param nbSuccess Number of passed tests
 */
void testAdd(int * nbTests, int * nbSuccess) {

    DynamicArray arr;
    double toAdd = 12.00;
    int oldSize, toTest;

    create(&arr);
    
    oldSize = arr.size;
    toTest = add(&arr, toAdd);

    if (toTest == 0 
        && arr.size == 1 
        && arr.array[0] == toAdd
        && oldSize < arr.size) {
        (*nbSuccess)++;
    } else {
        printf("Fail : testAdd\n");
    }

    (*nbTests)++;
}

/**
 * @brief Test rmvAt function with index in array
 * @param nbTests Number of tests
 * @param nbSuccess Number of passed tests
 */
void testRmvAtInIndex(int * nbTests, int * nbSuccess) {

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

    (*nbTests)++;
}

/**
 * @brief Test rmvAt function with index out array
 * @param nbTests Number of tests
 * @param nbSuccess Number of passed tests
 */
void testRmvAtOutIndex(int * nbTests, int * nbSuccess) {

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

    (*nbTests)++;
}

/**
 * @brief Test rmv function
 * @param nbTests Number of tests
 * @param nbSuccess Number of passed tests
 */
void testRmv(int * nbTests, int * nbSuccess) {

    DynamicArray arr;
    double num = 12.00;
    double fixture[] = { num, num, num, num, num };

    create(&arr);
    add(&arr, num);
    add(&arr, num);
    add(&arr, num);
    add(&arr, num);
    add(&arr, num);
    add(&arr, num);

    if (rmv(&arr, num) == 0
        && compare(arr.array, arr.size, fixture, 5) == 0) {
        (*nbSuccess)++;
    } else {
        printf("Fail : testRmv\n");
    }

    (*nbTests)++;
}

/**
 * @brief Test rmvAll function
 * @param nbTests Number of tests
 * @param nbSuccess Number of passed tests
 */
void testRmvAll(int * nbTests, int * nbSuccess) {

    DynamicArray arr;
    double num = 12.00;
    int nbToAdd = 6;
    double fixture[] = { };

    create(&arr);
    
    for (int i = 0; i < nbToAdd; i++) {
        add(&arr, num);
    }

    if (rmvAll(&arr, num) == nbToAdd
        && compare(arr.array, arr.size, fixture, 0)) {
        (*nbSuccess)++;
    } else {
        printf("Fail : testRmvAll\n");
    }

    (*nbTests)++;
}

/**
 * @brief Test count function
 * @param nbTests Number of tests
 * @param nbSuccess Number of passed tests
 */
void testCount(int * nbTests, int * nbSuccess) {

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
        printf("Fail : testCount\n");
    }

    (*nbTests)++;
}

/**
 * @brief Test indexOf function with present number
 * @param nbTests Number of tests
 * @param nbSuccess Number of passed tests
 */
void testIndexOfIsPresent(int * nbTests, int * nbSuccess) {

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

    (*nbTests)++;
}

/**
 * @brief Test indexOf function with not present number
 * @param nbTests Number of tests
 * @param nbSuccess Number of passed tests
 */
void testIndexOfIsNotPresent(int * nbTests, int * nbSuccess) {

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

    (*nbTests)++;
}

/**
 * @brief Test expand function
 * @param nbTests Number of tests
 * @param nbSuccess Number of passed tests
 */
void testExpand(int * nbTests, int * nbSuccess) {

    DynamicArray arr;
    int oldSize, more = 10;
    
    create(&arr);

    oldSize = arr.size;

    if (expand(&arr, more) == 0 && oldSize < arr.size && arr.size == more) {
        (*nbSuccess)++;
    } else {
        printf("Fail : testExpand\n");
    }

    (*nbTests)++;
}

/**
 * @brief Test expand function with zero size in more
 * @param nbTests Number of tests
 * @param nbSuccess Number of passed tests
 */
void testExpandWithZeroMore(int * nbTests, int * nbSuccess) {

    DynamicArray arr;
    int oldSize;
    
    create(&arr);

    oldSize = arr.size;

    if (expand(&arr, 0) == -1 && oldSize == arr.size) {
        (*nbSuccess)++;
    } else {
        printf("Fail : testExpandWithZeroMore\n");
    }

    (*nbTests)++;
}

/**
 * @brief Test expand function with negative size in more
 * @param nbTests Number of tests
 * @param nbSuccess Number of passed tests
 */
void testExpandWithNegativeMore(int * nbTests, int * nbSuccess) {

    DynamicArray arr;
    int oldSize;
    
    create(&arr);

    oldSize = arr.size;

    if (expand(&arr, -10) == -1 && oldSize == arr.size) {
        (*nbSuccess)++;
    } else {
        printf("Fail : testExpandWithNegativeMore\n");
    }

    (*nbTests)++;
}

/**
 * @brief Test insertAt function and add a value at 0 index
 * @param nbTests Number of tests
 * @param nbSuccess Number of passed tests
 */
void testInsertAtInArrayAtBegin(int * nbTests, int * nbSuccess) {

    DynamicArray arr;
    int addAt = 0;
    double toAdd = 4.4;
    double fixture[] = { 4.4, 1.1, 2.2, 3.3 };

    create(&arr);
    add(&arr, 1.1);
    add(&arr, 2.2);
    add(&arr, 3.3);

    if (insertAt(&arr, toAdd, addAt) != -1
        && arr.array[addAt] == toAdd
        && compare(arr.array, arr.size, fixture, 4) == 0) {
        (*nbSuccess)++;
    } else {
        printf("Fail : testInsertAtInArrayAtBegin\n");
    }

    (*nbTests)++;
}

/**
 * @brief Test insertAt function and add at end
 * @param nbTests Number of tests
 * @param nbSuccess Number of passed tests
 */
void testInsertAtInArrayAtEnd(int * nbTests, int * nbSuccess) {

    DynamicArray arr;
    int addAt = 3;
    double toAdd = 4.4;
    double fixture[] = { 1.1, 2.2, 3.3, 4.4 };

    create(&arr);
    add(&arr, 1.1);
    add(&arr, 2.2);
    add(&arr, 3.3);

    if (insertAt(&arr, toAdd, addAt) != -1
        && arr.array[addAt] == toAdd
        && compare(arr.array, arr.size, fixture, 4) == 0) {
        (*nbSuccess)++;
    } else {
        printf("Fail : testInsertAtInArrayAtEnd\n");
    }

    (*nbTests)++;
}

/**
 * @brief Test inserAt function with add at a negative index
 * @param nbTests Number of tests
 * @param nbSuccess Number of passed tests
 */
void testInsertAtNegativeIndex(int * nbTests, int * nbSuccess) {

    DynamicArray arr;
    int addAt = -2;
    double toAdd = 4.4;
    double fixture[] = { 1.1, 2.2, 3.3 };

    create(&arr);
    add(&arr, 1.1);
    add(&arr, 2.2);
    add(&arr, 3.3);

    if (insertAt(&arr, toAdd, addAt) == -1
        && compare(arr.array, arr.size, fixture, 3) == 0) {
        (*nbSuccess)++;
    } else {
        printf("Fail : testInsertAtNegativeIndex\n");
    }

    (*nbTests)++;
}

/**
 * @brief Test inserAt function with add at a bigger index
 * @param nbTests Number of tests
 * @param nbSuccess Number of passed tests
 */
void testInsertAtBiggerIndex(int * nbTests, int * nbSuccess) {

    DynamicArray arr;
    int addAt = 15;
    double toAdd = 4.4;
    double fixture[] = { 1.1, 2.2, 3.3 };

    create(&arr);
    add(&arr, 1.1);
    add(&arr, 2.2);
    add(&arr, 3.3);

    if (insertAt(&arr, toAdd, addAt) == -1
        && compare(arr.array, arr.size, fixture, 3) == 0) {
        (*nbSuccess)++;
    } else {
        printf("Fail : testInsertAtBiggerIndex\n");
    }

    (*nbTests)++;
}

/**
 * @brief Test copy two dynamic arrays with same size
 * @param nbTests Number of tests
 * @param nbSuccess Number of passed tests
 */
void testCopyWithSameSize(int * nbTests, int * nbSuccess) {

    DynamicArray src, dst;

    create(&src);
    create(&dst);

    add(&src, 1.1);
    add(&src, 2.2);

    add(&dst, 0);
    add(&dst, 0);

    copy(&dst, &src);

    if (compare(src.array, src.size, dst.array, dst.size) == 0) {
        (*nbSuccess)++;
    } else {
        printf("Fail : testCopyWithSameSize\n");
    }

    (*nbTests)++;
}

/**
 * @brief Test copy two dynamic arrays with src size bigger
 * @param nbTests Number of tests
 * @param nbSuccess Number of passed tests
 */
void testCopyWithSrcSizeBigger(int * nbTests, int * nbSuccess) {

    DynamicArray src, dst;

    create(&src);
    create(&dst);

    add(&src, 1.1);
    add(&src, 2.2);
    add(&src, 3.3);
    add(&src, 4.4);

    add(&dst, 0);

    copy(&dst, &src);

    if (compare(src.array, src.size, dst.array, dst.size) == 0
        && src.size == 4 
        && dst.size == 4) {
        (*nbSuccess)++;
    } else {
        printf("Fail : testCopyWithSrcSizeBigger\n");
    }

    (*nbTests)++;
}

/**
 * @brief Test copy two dynamic arrays with dst size lower
 * @param nbTests Number of tests
 * @param nbSuccess Number of passed tests
 */
void testCopyWithSrcSizeLower(int * nbTests, int * nbSuccess) {

    DynamicArray src, dst;

    create(&src);
    create(&dst);

    add(&src, 0);

    add(&dst, 1.1);
    add(&dst, 2.2);
    add(&dst, 3.3);
    add(&dst, 4.4);

    copy(&dst, &src);

    if (compare(src.array, src.size, dst.array, dst.size) == 0
        && src.size == 1 
        && dst.size == 1) {
        (*nbSuccess)++;
    } else {
        printf("Fail : testCopyWithSrcSizeLower\n");
    }

    (*nbTests)++;
}

/**
 * @brief Display the number of passed tests
 * @param nbTests Number of tests
 * @param nbSuccess Number of passed tests
 */
void displayStatus(int nbTests, int nbSuccess) {
    printf("PASSED %d / %d\n", nbSuccess, nbTests);
}