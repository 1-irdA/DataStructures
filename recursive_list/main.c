#include <stdio.h>
#include "link.h"

int main(void) {

    List l,
	 l2,
	 l3;

    create(&l);
    create(&l2);
    create(&l3);

    addAtEnd(&l, 44); 
    addAtEnd(&l, 44); 
    addAtEnd(&l, 98);
    addAtEnd(&l, 44);
    addAtEnd(&l, 48);
     
    display(l);

    removeFirstOccur(&l, 48);
    
    display(l);  
    // 44 44 98 44
 
    addAfterEachOccur(&l, 44, 222); 
    // 44 222 44 222 98 44 222
  
    display(l);

    printf("Last value => %d\n", getLastValue(l));

    addAtEnd(&l, 44);
    // 44 222 44 222 98 44 222 44
    
    printf("Same ? %s\n", isSame(l,l2) ? "Yes" : "No");

    removeEachOccur(&l, 44);
    // 222 222 98 222
    
    display(l);

    addAtEnd(&l2, 222);
    addAtEnd(&l2, 222); 
    addAtEnd(&l2, 98);
    addAtEnd(&l2, 222);

    display(l2);

    printf("Same ? %s\n", isSame(l,l2) ? "Yes" : "No");
    
    printf("Occurence(s) in list ? %d\n", nbOccurInList(l, 222));

    display(l);

    return 0;
}
