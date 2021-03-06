#include <string.h>
#include "../../headers/map.h"

/**
 * @brief Determine if a key is in map
 * @param self map who contains keys values
 * @param key key to find
 * @return int return 0 if not present, 1 else
 */
int is_not_present(Map * self, double key) {

    int i, is_not_present = 1;

    for (i = 0; i < self->length && self->pairs[i].key != key; i++);

    if (i == self->length) {
        is_not_present = 0;
    }

    return is_not_present;
}

/**
 * @brief Get the index of specified string
 * @param self map who contains values
 * @param to_find string to search
 * @return int the string index
 */
int get_index_of(Map * self, char * to_find) {

    int i, index = -1;
    for (i = 0; 
        i < self->length && strcmp(self->pairs[i].value, to_find) != 0;
        i++);

    if (i != self->length) {
        index = i;
    }
    
    return index;
}

/**
 * @brief Expand size of to_expand array
 * @param to_expand Map to expand
 * @param more Size to add
 * @return int return 0 if ok, 1 else
 */
int expand(Map * to_expand, int more) {

    int result = 1;

    if (more > 0 && (to_expand->pairs = realloc(to_expand->pairs, (to_expand->length + more) * sizeof(Pair)))) {
        to_expand->length += more;
        result = 0;
    }

    return result;
}

/**
 * @brief Decrease map size
 * @param to_decrease Map to decrease
 * @param less Size to remove
 * @return int 0 if ok, 1 else
 */
int decrease(Map * to_decrease, int less) {

    int result = 1;

    if (less > 0 && less <= to_decrease->length 
        && (to_decrease->pairs = realloc(to_decrease->pairs, (to_decrease->length - less) * sizeof(Pair)))) {
        to_decrease->length -= less;
        result = 0;
    }

    return result;
}

/**
 * @brief Copy each values differents of FLAG
 * from src to dst
 * @param dst Dst map
 * @param src Src map
 */
void copy_values(Map * dst, Map * src) {

    for (int i = 0; i < src->length; i++) {
        if (src->pairs[i].value != NULL) {
            dst->pairs[i] = src->pairs[i];
        }
    }
}

/**
 * @brief Remove FLAG key and NULL value
 * @param to_refresh Map to refresh
 */
void refresh(Map * to_refresh) {

    Map temp;

    init(&temp);
    
    if ((temp.pairs = realloc(temp.pairs, (to_refresh->length - 1) * sizeof(Pair)))) {
        copy_values(&temp, to_refresh);
    }

    temp.display(temp);

    if ((to_refresh->pairs = realloc(to_refresh->pairs, (temp.length) * sizeof(Pair)))) {
        copy_values(to_refresh, &temp);
    }
}