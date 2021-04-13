#include <stdio.h>
#include "link.h"

int main(void) {

    Stack s;

    create(&s);

    pop(&s);

    printf("In stack ? %s\n", isInStack(s, 152) ? "Yes" : "No");
    
    push(&s, 45);
    push(&s, 125);
    display(s);
    
    printf("In stack ? %s\n", isInStack(s, 454) ? "Yes" : "No");
    printf("In stack ? %s\n", isInStack(s, 45) ? "Yes" : "No");
    
    printf("Popped value : %d\n", pop(&s));

    display(s);

    push(&s, 12510);

    display(s);

    printf("Top value : %d\n", peek(s));

    empty(&s);

    display(s);

    return 0;
}
