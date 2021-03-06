#include <string.h>
#include "../headers/map.h"
#include "../headers/map_utils.h"

#define FLAG -0.123456789987654321

/**
 * @brief Init a map
 * @param self map to initialize
 */
void init(Map * self) {

    self->pairs = malloc(0 * sizeof(Pair));
    self->length = 0;

    self->add = add;
    self->display = display;
    self->get_key_by_value = get_key_by_value;
    self->get_value_by_key = get_value_by_key;
    self->copy = copy;
    /*
    self->remove_first_by_value = remove_first_by_value;
    self->remove_all_by_value = remove_all_by_value;
    self->remove_by_key = remove_by_key;
    */
}

/**
 * @brief Add key, value pair in map
 * @param self map container
 * @param key key 
 * @param value value
 * @return int 0 if added
 */
int add(Map * self, double key, char * value) {

    Pair toAdd = { key, value };
    int added = 1;

    if (is_not_present(self, key) == 0) {
        self->length++;
        self->pairs = realloc(self->pairs, self->length * sizeof(Pair));
        self->pairs[self->length - 1] = toAdd;
        added = 0;
    }

    return added;
}

/**
 * @brief Display key values 
 * @param self map to display
 */
void display(Map self) {

    printf("{ ");

    for (int i = 0; i < self.length; i++) {
        printf("%.2f: %s, ", self.pairs[i].key, self.pairs[i].value);
    }

    printf(" }\n");
}

/**
 * @brief Get the key by value
 * @param self map who contains keys values
 * @param to_search value to search
 * @return double key of finded value or flag
 */
double get_key_by_value(Map self, char * to_search) {

    int i;
    double finded_key = FLAG;

    for (i = 0; i < self.length && strcmp(self.pairs[i].value, to_search) != 0; i++);

    if (i != self.length) {
        finded_key = self.pairs[i].key;
    }

    return finded_key;
}

/**
 * @brief Get the value by key
 * @param self map who contains keys values
 * @param to_search key to search
 * @return char* return value a key
 */
char * get_value_by_key(Map self, double to_search) {

    int i;
    char * finded_value = NULL;

    for (i = 0; i < self.length && self.pairs[i].key != to_search; i++);

    if (i != self.length) {
        finded_value = self.pairs[i].value;
    }

    return finded_value;
}

/**
 * @brief Remove specified value and return her
 * @param self Map who contains values
 * @param to_remove String to remove
 * @return char* removed string
 */
char * remove_first_by_value(Map * self, char * to_remove) { 

    Pair replace = { FLAG, NULL };
    int to_rmv = get_index_of(self, to_remove);  
    char * removed = NULL;  

    if (to_rmv != -1) {
        removed = self->pairs[to_rmv].value;
        self->pairs[to_rmv] = replace;
        refresh(self);
        self->length--;
    }

    return removed;
}

/**
 * @brief Copy src map to dst map
 * @param dst Receives src values
 * @param src To copy
 */
void copy(Map * dst, Map * src) {

    if (dst->length < src->length) {
        expand(dst, src->length - dst->length);
    } else if (dst->length > src->length) {
        decrease(dst, dst->length - src->length);
    }

    copy_values(dst, src);
}

/*
char ** remove_all_by_value(Map * self, char * to_remove) { }
double remove_by_key(Map * self, double to_remove) { }
*/