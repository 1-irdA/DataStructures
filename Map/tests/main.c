#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/map.h"
#include "../headers/tests_utils.h"

#define FLAG -0.123456789987654321

void display_status(int nb_tests, int nb_success);
void test_init(int * nb_tests, int * nb_success);
void test_add(int * nb_tests, int * nb_success);
void test_add_same_key(int * nb_tests, int * nb_success);
void test_get_key_by_value(int * nb_tests, int * nb_success);
void test_get_key_by_value_no_value(int * nb_tests, int * nb_success);
void test_get_value_by_key(int * nb_tests, int * nb_success);
void test_get_value_by_key_no_key(int * nb_tests, int * nb_success);
void test_remove_first_by_value(int * nb_tests, int * nb_success);

int main() {
    
    int nb_tests = 0, nb_success = 0;

    test_init(&nb_tests, &nb_success);
    test_add(&nb_tests, &nb_success);
    test_add_same_key(&nb_tests, &nb_success);
    test_get_key_by_value(&nb_tests, &nb_success);
    test_get_key_by_value_no_value(&nb_tests, &nb_success);
    test_get_value_by_key(&nb_tests, &nb_success);
    test_get_value_by_key_no_key(&nb_tests, &nb_success);
    test_remove_first_by_value(&nb_tests, &nb_success);

    display_status(nb_tests, nb_success);
}

/**
 * @brief Display tests status
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void display_status(int nb_tests, int nb_success) {
    printf("PASSED : %d / %d\n", nb_success, nb_tests);
}

/**
 * @brief Test map initialization
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_init(int * nb_tests, int * nb_success) {

    Map map;

    init(&map);

    if (map.length == 0) {
        (*nb_success)++;
    } else {
        printf("FAIL => test_init\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test add key value in map
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_add(int * nb_tests, int * nb_success) {

    Map map;

    init(&map);

    map.add(&map, 12, "First");
    map.add(&map, 13, "Second");
    map.add(&map, 14, "Third");

    if (map.length == 3 
        && map.pairs[0].key == 12
        && map.pairs[1].key == 13
        && map.pairs[2].key == 14
        && strcmp(map.pairs[0].value, "First") == 0
        && strcmp(map.pairs[1].value, "Second") == 0
        && strcmp(map.pairs[2].value, "Third") == 0) {
        (*nb_success)++;
    } else {
        printf("FAIL => test_add\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test when add same keys
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_add_same_key(int * nb_tests, int * nb_success) {

    Map map;
    int added = 0;

    init(&map);

    added = map.add(&map, 12, "First") 
            + map.add(&map, 12, "Never add") 
            + map.add(&map, 13, "Second");

    if (map.length == 2
        && added == 1
        && map.pairs[0].key == 12
        && map.pairs[1].key == 13
        && strcmp(map.pairs[0].value, "First") == 0
        && strcmp(map.pairs[1].value, "Second") == 0) {
        (*nb_success)++;
    } else {
        printf("FAIL => test_add_same_key\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test get key by value
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_get_key_by_value(int * nb_tests, int * nb_success) {

    Map map;

    init(&map);

    map.add(&map, 12, "First");
    map.add(&map, 13, "Second");
    map.add(&map, 14, "Third");

    if (map.get_key_by_value(map, "First") == 12
        && map.get_key_by_value(map, "Second") == 13
        && map.get_key_by_value(map, "Third") == 14) {
        (*nb_success)++;
    } else {
        printf("FAIL => test_get_key_by_value\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test get key by value with not existing value
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_get_key_by_value_no_value(int * nb_tests, int * nb_success) {

    Map map;

    init(&map);

    map.add(&map, 12, "First");
    map.add(&map, 13, "Second");
    map.add(&map, 14, "Third");

    if (map.get_key_by_value(map, "Not exists") == FLAG) {
        (*nb_success)++;
    } else {
        printf("FAIL => test_get_key_by_value_no_value\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Get value with specified key
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_get_value_by_key(int * nb_tests, int * nb_success) {

    Map map;

    init(&map);

    map.add(&map, 12, "First");
    map.add(&map, 13, "Second");
    map.add(&map, 14, "Third");

    if (strcmp(map.get_value_by_key(map, 12), "First") == 0
        && strcmp(map.get_value_by_key(map, 13), "Second") == 0
        && strcmp(map.get_value_by_key(map, 14), "Third") == 0) {
        (*nb_success)++;
    } else {
        printf("FAIL => test_get_value_by_key\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Get value with specied key with not existing key
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_get_value_by_key_no_key(int * nb_tests, int * nb_success) {

    Map map;

    init(&map);

    map.add(&map, 12, "First");
    map.add(&map, 13, "Second");
    map.add(&map, 14, "Third");

    if (map.get_value_by_key(map, 100) == NULL) {
        (*nb_success)++;
    } else {
        printf("FAIL => test_get_value_by_key_no_key\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test remove a pair with specified value
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_remove_first_by_value(int * nb_tests, int * nb_success) {

    Map map, expected;

    init(&map);
    init(&expected);

    map.add(&map, 12, "First");
    map.add(&map, 13, "Second");
    map.add(&map, 14, "Third");

    // init expected result
    expected.add(&expected, 13, "Second");
    expected.add(&expected, 14, "Third");

    map.remove_first_by_value(&map, "First");

    if (compare(map, expected) == 0) {
        (*nb_success)++;
    } else {
        printf("FAIL => test_remove_first_by_value\n");
    }

    (*nb_tests)++;
}

/**
 * @brief Test copy method to dst with dst length equals 0
 * @param nb_tests Number of tests
 * @param nb_success Number of passed tests
 */
void test_copy_dst_more_smaller(int * nb_tests, int * nb_success) {

    Map src, dst;

    init(&src);
    init(&dst);

    src.add(&src, 12, "First");
    src.add(&src, 13, "Second");
    src.add(&src, 14, "Third");

    src.copy(&dst, &src);

    if (compare(src, dst) == 0) {
        (*nb_success)++;
    } else {
        printf("FAIL => test_copy_dst_more_smaller\n");
    }

    (*nb_tests)++;
}