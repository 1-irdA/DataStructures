#include "map.h"

int is_not_present(Map * self, double key);

int get_index_of(Map * self, char * to_find);

int expand(Map * to_expand, int more);

int decrease(Map * to_decrease, int less);

void refresh(Map * to_refresh);

void copy_values(Map * dst, Map * src);