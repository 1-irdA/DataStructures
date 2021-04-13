#include <string.h>
#include "../headers/map.h"
#include "../headers/map_utils.h"

#define FLAG_KEY -0.123456789987654321

/**
 * @brief Init a map
 * @param self map to initialize
 */
void init(Map * self) {

    // init map
    self->pairs = malloc(0 * sizeof(Pair));
    self->length = 0;

    // add map functions
    self->add = add;
    self->display = display;
    self->get_key_by_value = get_key_by_value;
    self->get_value_by_key = get_value_by_key;
    self->copy = copy;
    self->remove_first_by_value = remove_first_by_value;
    self->remove_all_by_value = remove_all_by_value;
    self->remove_by_key = remove_by_key;
    self->set = set;
    self->clear = clear;
    self->get_keys = get_keys;
    self->get_values = get_values;
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
    int added = -1;

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
        printf("%.2f: '%s'", self.pairs[i].key, self.pairs[i].value);

        if (i != self.length - 1) {
            printf(", ");
        }
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
    double finded_key = FLAG_KEY;

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
    char  * finded_value = NULL;

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
 */
char * remove_first_by_value(Map * self, char * to_remove) { 

    int to_rmv = get_index_of_value(*self, to_remove); 
    char  * removed = NULL; 

    if (to_rmv != -1) {
        removed = self->pairs[to_rmv].value;
        self->pairs[to_rmv].value = NULL;

        // remove null values
        self->copy(self, *self);
    }

    return removed;
}

/**
 * @brief Copy src map to dst map
 * Uses to remove NULL values too
 * @param dst Receives src values
 * @param src To copy
 */
void copy(Map * dst, Map src) {

    init(dst);

    for (int i = 0; i < src.length; i++) {
        if (src.pairs[i].value) {
            (*dst).add(dst, src.pairs[i].key, src.pairs[i].value);
        }
    }
}

/**
 * @brief Remove all pair specified by to_remove
 * @param self Map who contains values
 * @param to_remove value to remove
 * @return int number of removed values
 */
int remove_all_by_value(Map * self, char * to_remove) { 

    int removed = 0;

    for (int i = 0; i < self->length; i++) {
        if (strcmp(self->pairs[i].value, to_remove) == 0) {
            self->pairs[i].value = NULL;
            removed++;
        }
    }

    // remove null values
    self->copy(self, *self);

    return removed;
}

/**
 * @brief Remove a pair with his key
 * @param self Map to apply function 
 * @param to_remove Key to remove
 * @return Pair removed pair
 */
Pair remove_by_key(Map * self, double to_remove) { 
    
    Pair removed = { -1, NULL };
    int index_to_rmv = get_index_of_key(*self, to_remove);

    if (index_to_rmv != -1) {
        removed.key = self->pairs[index_to_rmv].key;
        removed.value = self->pairs[index_to_rmv].value;
        self->pairs[index_to_rmv].value = NULL;
    }

    // remove null values
    self->copy(self, *self);
    
    return removed;
}

/**
 * @brief Update to value at specified key and replace by to_set
 * @param self Map to apply function
 * @param key Key to search
 * @param to_set Value to set
 * @return int 0 if set, -1 else
 */
int set(Map * self, double key, char * to_set) {

    int is_set = -1, index_to_set = get_index_of_key(*self, key);
    
    if (index_to_set != -1) {
        self->pairs[index_to_set].value = to_set; 
        is_set = 0;
    }

    return is_set;
}

/**
 * @brief Clear map
 * @param self Map to clear
 */
void clear(Map * self) {
    self->pairs = malloc(0 * sizeof(Pair));
    self->length = 0;
}

/**
 * @brief Get the keys 
 * @param self Map who contains values
 * @return int* array of keys
 */
int * get_keys(Map self) {

    int * keys = NULL; 
    
    if (self.length > 0) {

        keys = calloc(self.length, sizeof(int));

        for (int i = 0; i < self.length; i++) {
            keys[i] = self.pairs[i].key;
        }
    }

    return keys;
}

/**
 * @brief Get the values 
 * @param self Map who contains values
 * @return char** array of string values
 */
char ** get_values(Map self) {

    char ** values = NULL;

    if (self.length > 0) {

        values = calloc(self.length, sizeof(char));

        for (int i = 0; i < self.length; i++) {
            values[i] = self.pairs[i].value; 
        }
    }

    return values;
}