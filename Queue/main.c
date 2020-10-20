#include <stdio.h>
#include "link.h"

int main(void) {

    Queue q;

    create(&q);

    add(&q, 12510);
    add(&q, 98);

    display(q);

    printf("First value => %d\n", peek(q));
    printf("Is in queue ? %s\n", isInQueue(q, 45) ? "Yes" : "No");
    printf("Is in queue ? %s\n", isInQueue(q, 12510) ? "Yes" : "No");
    
    printf("Removed value => %d\n", rmvFirst(&q));

    display(q);

    empty(&q);

    display(q);

    return 0;
}
