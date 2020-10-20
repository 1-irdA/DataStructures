#include <stdio.h>
#include "link.h"

int main(void) {

    List lA, 
	 lB;
    
    create(&lA);
    create(&lB);
    
    addAtBegin(&lA, 12);
    addAtBegin(&lB, 12);
    addAtEnd(&lB, 45);
    addAtEnd(&lA, 45);

    printf("Is same ? %s\n", isSameList(lA, lB) ? "Yes" : "No");

    printf("Is present ? %s\n", isPresent(lA, 12) ? "Yes" : "No");

    return 0;
}
