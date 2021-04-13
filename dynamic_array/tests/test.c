#include <stdio.h>
#include "../headers/dynamic.h"
#include "../headers/tests_utils.h"

/**
 * @brief To reconize several values
 */
#define FLAG -0.123456789

void test_create(int * nb_tests, int * nb_success);
void test_add(int * nb_tests, int * nb_success);
void test_remove_at_in_index(int * nb_tests, int * nb_success);
void test_remove_at_out_index(int * nb_tests, int * nb_success);
void test_rmv(int * nb_tests, int * nb_success);
void test_rmv_all(int * nb_tests, int * nb_success);
void test_count(int * nb_tests, int * nb_success);
void test_index_of_is_present(int * nb_tests, int * nb_success);
void test_index_of_is_not_present(int * nb_tests, int * nb_success);
void test_expand(int * nb_tests, int * nb_success);
void test_expand_with_zero_more(int * nb_tests, int * nb_success);
void test_expand_with_negative_more(int * nb_tests, int * nb_success);
void test_insert_at_in_array_at_begin(int * nb_tests, int * nb_success);
void test_insert_at_in_array_at_end(int * nb_tests, int * nb_success);
void test_insert_at_negative_index(int * nb_tests, int * nb_success);
void test_insert_at_bigger_index(int * nb_tests, int * nb_success);
void test_copy_with_same_size(int * nb_tests, int * nb_success);
void test_copy_with_src_size_bigger(int * nb_tests, int * nb_success);
void test_copy_with_src_size_lower(int * nb_tests, int * nb_success);

void display_status(int nb_tests, int nb_success);

/**
 * @brief Launch test
 * @return int program code
 */
int main(void) {

    int nb_tests = 0, nb_success = 0;

    printf("********** tests dynamic.c **********\n\n");
    
    test_create(&nb_tests, &nb_success);
    test_add(&nb_tests, &nb_success);
    test_remove_at_in_index(&nb_tests, &nb_success);
    test_remove_at_out_index(&nb_tests, &nb_success);
    test_rmv(&nb_tests, &nb_success);
    test_rmv_all(&nb_tests, &nb_success);
    test_count(&nb_tests, &nb_success);
    test_index_of_is_present(&nb_tests, &nb_success);
    test_index_of_is_not_present(&nb_tests, &nb_success);
    test_expand(&nb_tests, &nb_success);
    test_expand_with_zero_more(&nb_tests, &nb_success);
    test_expand_with_negative_more(&nb_tests, &nb_success);
    test_insert_at_in_array_at_begin(&nb_tests, &nb_success);
    test_insert_at_in_array_at_end(&nb_tests, &nb_success);
    test_insert_at_negative_index(&nb_tests, &nb_success);
    test_insert_at_bigger_index(&nb_tests, &nb_success);
    test_copy_with_same_size(&nb_tests, &nb_success);
    test_copy_with_src_size_bigger(&nb_tests, &nb_success);
    test_copy_with_src_size_lower(&nb_tests, &nb_success);

    display_status(nb_tests, nb_success);

    return 0;
}

/**
 * @brief Test create function
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_create(int * nb_tests, int * nb_success) {

    DynamicArray arr;

    create(&arr);

    if (arr.size == 0 && arr.array != NULL) {
        (*nb_success)++;
    } else {
        printf("Fail : test_create\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test add function
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_add(int * nb_tests, int * nb_success) {

    DynamicArray arr;
    double to_add = 12.00;
    int old_size, to_test;

    create(&arr);
    
    old_size = arr.size;
    to_test = add(&arr, to_add);

    if (to_test == 0 
        && arr.size == 1 
        && arr.array[0] == to_add
        && old_size < arr.size) {
        (*nb_success)++;
    } else {
        printf("Fail : test_add\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test rmv_at function with index in array
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_remove_at_in_index(int * nb_tests, int * nb_success) {

    DynamicArray arr;
    double num = 12.00;
    int index = 10, old_size;

    create(&arr);
 
    for (int i = 0; i < num; i++) {
        add(&arr, num * i);
    }

    old_size = arr.size;

    if (rmv_at(&arr, index) && old_size > arr.size) {
        (*nb_success)++;
    } else {
        printf("Fail : test_remove_at_in_index\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test rmv_at function with index out array
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_remove_at_out_index(int * nb_tests, int * nb_success) {

    DynamicArray arr;
    double num = 12.00;
    int index = 13, old_size;

    create(&arr);
 
    for (int i = 0; i < index; i++) {
        add(&arr, num * i);
    }

    old_size = arr.size;

    if (rmv_at(&arr, index) != 1 && old_size == arr.size) {
        (*nb_success)++;
    } else {
        printf("Fail : test_remove_at_out_index\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test rmv function
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_rmv(int * nb_tests, int * nb_success) {

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

    if (rmv(&arr, num) && compare(arr.array, arr.size, fixture, 5)) {
        (*nb_success)++;
    } else {
        printf("Fail : test_rmv\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test rmv_all function
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_rmv_all(int * nb_tests, int * nb_success) {

    DynamicArray arr;
    double num = 12.00;
    int nb_to_add = 6;
    double fixture[] = { };

    create(&arr);
    
    for (int i = 0; i < nb_to_add; i++) {
        add(&arr, num);
    }

    if (rmv_all(&arr, num) == nb_to_add
        && compare(arr.array, arr.size, fixture, 0)) {
        (*nb_success)++;
    } else {
        printf("Fail : test_rmv_all\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test count function
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_count(int * nb_tests, int * nb_success) {

    DynamicArray arr;
    double num = 12.00;
    int nb_to_add = 6;

    create(&arr);
    
    for (int i = 0; i < nb_to_add; i++) {
        add(&arr, num);
    }

    if (count(arr, num) == nb_to_add) {
        (*nb_success)++;
    } else {
        printf("Fail : test_count\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test index_of function with present number
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_index_of_is_present(int * nb_tests, int * nb_success) {

    DynamicArray arr;

    create(&arr);
    add(&arr, 9.87);
    add(&arr, 10.54);
    add(&arr, -89.81);
    add(&arr, 0.3);
    add(&arr, -897.6);
    add(&arr, 15);

    if (index_of(arr, -89.81) == 2) {
        (*nb_success)++;
    } else {
        printf("Fail : test_index_of_is_present\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test index_of function with not present number
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_index_of_is_not_present(int * nb_tests, int * nb_success) {

    DynamicArray arr;

    create(&arr);
    add(&arr, 9.87);
    add(&arr, 10.54);
    add(&arr, -89.81);
    add(&arr, 0.3);
    add(&arr, -897.6);
    add(&arr, 15);

    if (index_of(arr, 1001) == -1) {
        (*nb_success)++;
    } else {
        printf("Fail : test_index_of_is_not_present\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test expand function
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_expand(int * nb_tests, int * nb_success) {

    DynamicArray arr;
    int old_size, more = 10;
    
    create(&arr);

    old_size = arr.size;

    if (expand(&arr, more) == 0 && old_size < arr.size && arr.size == more) {
        (*nb_success)++;
    } else {
        printf("Fail : test_expand\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test expand function with zero size in more
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_expand_with_zero_more(int * nb_tests, int * nb_success) {

    DynamicArray arr;
    int old_size;
    
    create(&arr);

    old_size = arr.size;

    if (expand(&arr, 0) == -1 && old_size == arr.size) {
        (*nb_success)++;
    } else {
        printf("Fail : test_expand_with_zero_more\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test expand function with negative size in more
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_expand_with_negative_more(int * nb_tests, int * nb_success) {

    DynamicArray arr;
    int old_size;
    
    create(&arr);

    old_size = arr.size;

    if (expand(&arr, -10) == -1 && old_size == arr.size) {
        (*nb_success)++;
    } else {
        printf("Fail : test_expand_with_negative_more\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test insert_at function and add a value at 0 index
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_insert_at_in_array_at_begin(int * nb_tests, int * nb_success) {

    DynamicArray arr;
    int add_at = 0;
    double to_add = 4.4;
    double fixture[] = { 4.4, 1.1, 2.2, 3.3 };

    create(&arr);
    add(&arr, 1.1);
    add(&arr, 2.2);
    add(&arr, 3.3);

    if (insert_at(&arr, to_add, add_at) != -1
        && arr.array[add_at] == to_add
        && compare(arr.array, arr.size, fixture, 4)) {
        (*nb_success)++;
    } else {
        printf("Fail : test_insert_at_in_array_at_begin\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test insert_at function and add at end
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_insert_at_in_array_at_end(int * nb_tests, int * nb_success) {

    DynamicArray arr;
    int add_at = 3;
    double to_add = 4.4;
    double fixture[] = { 1.1, 2.2, 3.3, 4.4 };

    create(&arr);
    add(&arr, 1.1);
    add(&arr, 2.2);
    add(&arr, 3.3);

    if (insert_at(&arr, to_add, add_at) != -1
        && arr.array[add_at] == to_add
        && compare(arr.array, arr.size, fixture, 4)) {
        (*nb_success)++;
    } else {
        printf("Fail : test_insert_at_in_array_at_end\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test insert_at function with add at a negative index
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_insert_at_negative_index(int * nb_tests, int * nb_success) {

    DynamicArray arr;
    int add_at = -2;
    double to_add = 4.4;
    double fixture[] = { 1.1, 2.2, 3.3 };

    create(&arr);
    add(&arr, 1.1);
    add(&arr, 2.2);
    add(&arr, 3.3);

    if (insert_at(&arr, to_add, add_at) == -1
        && compare(arr.array, arr.size, fixture, 3)) {
        (*nb_success)++;
    } else {
        printf("Fail : test_insert_at_negative_index\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test insert_at function with add at a bigger index
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_insert_at_bigger_index(int * nb_tests, int * nb_success) {

    DynamicArray arr;
    int add_at = 15;
    double to_add = 4.4;
    double fixture[] = { 1.1, 2.2, 3.3 };

    create(&arr);
    add(&arr, 1.1);
    add(&arr, 2.2);
    add(&arr, 3.3);

    if (insert_at(&arr, to_add, add_at) == -1
        && compare(arr.array, arr.size, fixture, 3)) {
        (*nb_success)++;
    } else {
        printf("Fail : test_insert_at_bigger_index\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test copy two dynamic arrays with same size
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_copy_with_same_size(int * nb_tests, int * nb_success) {

    DynamicArray src, dst;

    create(&src);
    create(&dst);

    add(&src, 1.1);
    add(&src, 2.2);

    add(&dst, 0);
    add(&dst, 0);

    copy(&dst, &src);

    if (compare(src.array, src.size, dst.array, dst.size)) {
        (*nb_success)++;
    } else {
        printf("Fail : test_copy_with_same_size\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test copy two dynamic arrays with src size bigger
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_copy_with_src_size_bigger(int * nb_tests, int * nb_success) {

    DynamicArray src, dst;

    create(&src);
    create(&dst);

    add(&src, 1.1);
    add(&src, 2.2);
    add(&src, 3.3);
    add(&src, 4.4);

    add(&dst, 0);

    copy(&dst, &src);

    if (compare(src.array, src.size, dst.array, dst.size)
        && src.size == 4 
        && dst.size == 4) {
        (*nb_success)++;
    } else {
        printf("Fail : test_copy_with_src_size_bigger\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test copy two dynamic arrays with dst size lower
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_copy_with_src_size_lower(int * nb_tests, int * nb_success) {

    DynamicArray src, dst;

    create(&src);
    create(&dst);

    add(&src, 0);

    add(&dst, 1.1);
    add(&dst, 2.2);
    add(&dst, 3.3);
    add(&dst, 4.4);

    copy(&dst, &src);

    if (compare(src.array, src.size, dst.array, dst.size)
        && src.size == 1 
        && dst.size == 1) {
        (*nb_success)++;
    } else {
        printf("Fail : test_copy_with_src_size_lower\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Display the number of passed tests
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void display_status(int nb_tests, int nb_success) {
    printf("PASSED %d / %d\n", nb_success, nb_tests);
}