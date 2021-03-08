#include <string.h>
#include "../../headers/tests_utils.h"

/**
 * @brief Compare two maps
 * @param first To compare with the second
 * @param second To compare with the first
 * @return int 0 if same, 1 else
 */
int compare(Map first, Map second) {

    int is_same = -1, i;

    if (first.length == second.length) {

        for (i = 0; 
            i < first.length 
            && first.pairs[i].key == second.pairs[i].key
            && strcmp(first.pairs[i].value, second.pairs[i].value) == 0; 
            i++);

        if (i == first.length) {
            is_same = 0;
        }
    }

    return is_same;
}