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
int get_index_of_value(Map self, char * to_find) {

    int i, index = -1;
    for (i = 0; 
        i < self.length && strcmp(self.pairs[i].value, to_find) != 0;
        i++);

    if (i != self.length) {
        index = i;
    }
    
    return index;
}

/**
 * @brief Get the index of key 
 * @param self Map who contains values
 * @param to_find Key to find
 * @return int -1 if not in, >= 0 else
 */
int get_index_of_key(Map self, double to_find) {
    
    int i, index = -1;
    for (i = 0; 
        i < self.length && self.pairs[i].key != to_find;
        i++);

    if (i != self.length) {
        index = i;
    }
    
    return index;
}