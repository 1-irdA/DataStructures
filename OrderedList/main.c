#include <stdio.h>
#include "link.h"

int main(void) {

    List l;

    create(&l);

    display(l);

    add(&l, -100);
    add(&l, -100);
    add(&l, 45);
    add(&l, 45);
    add(&l, 12);
    add(&l, 1);
    add(&l, 15);
    add(&l, -87);

    display(l);
    
    printf("Nb values : %d\n", count(l));
    
    displayIfLowerThan(l, 45);

    removeFirstOccur(&l, 15);

    display(l);
 
    printf("Nb values : %d\n", count(l));

    removeEachOccur(&l, 45);

    display(l);

    empty(&l);

    display(l);

    printf("Nb values : %d\n", count(l));
    
    return 0;
}
