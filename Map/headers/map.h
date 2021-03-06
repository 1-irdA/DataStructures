#ifndef __MAP__
#define __MAP__

#include <stdio.h>
#include <stdlib.h>
#include "pair.h"

typedef struct map Map;

struct map {
    Pair * pairs;
    int length;
    
    int (*add)(Map *, double key, char * value);
    void (*display)(Map);
    double (*get_key_by_value)(Map self, char * to_search);
    char * (*get_value_by_key)(Map self, double to_search);
    char * (*remove_first_by_value)(Map * self, char * to_remove);
    char ** (*remove_all_by_value)(Map * self, char * to_remove);
    double (*remove_by_key)(Map * self, double to_remove);
    void (*copy)(Map * dst, Map * src);
};

void init(Map * self);
int add(Map * self, double key, char * value);
void display(Map self);
double get_key_by_value(Map self, char * to_search);
char * get_value_by_key(Map self, double to_search);
char * remove_first_by_value(Map * self, char * to_remove);
char ** remove_all_by_value(Map * self, char * to_remove);
double remove_by_key(Map * self, double to_remove);
void copy(Map * dst, Map * src);

// get_keys
// get_values
// set value with key void map.set(&map, key, value)

#endif