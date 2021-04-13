/**
 * @file link.c
 * @author Adrien GARROUSTE
 * @brief Represent an ordered list in ascending order
 * @version 0.1
 * @date 2020-10-05
 * @copyright No copyright, no right
 */
#include <stdio.h>
#include <stdlib.h>
#include "link.h"

/**
 * \brief Initialize the list
 * \param l the list to initialize
 */
void create(List * l) {
    *l = NULL;
}

/**
 * \brief Display all values of the list
 * \param l the list who contains values
 */
void display(List l) {
    List pL = NULL;
    
    if (l) {	    
        for (pL = l; pL != NULL; pL = pL->next) {
            printf("%d ", pL->value);
        }
    } else {
        printf("Empty list.");
    }	
    printf("\n");
}

/**
 * \brief Add a value and keep the ascending order
 * \param l the list to add value
 * \param toAdd the value to add
 */
void add(List * l, int toAdd) {
    List pL = NULL,
	     save = NULL;

    if (*l == NULL) {
        *l = (Link *) malloc(sizeof(Link));
	    (*l)->value = toAdd;
	    (*l)->next = NULL;
    } else if ((*l)->value >= toAdd) {
        save = *l;
	    *l = (Link *) malloc(sizeof(Link));
	    (*l)->next = save;
	    (*l)->value = toAdd;
    } else {
        for (pL = *l; pL->next && pL->next->value <= toAdd; pL = pL->next);

	    if (pL->next) {
	        save = pL->next;
	        pL->next = (Link *) malloc(sizeof(Link));
	        pL->next->value = toAdd;
	        pL->next->next = save;
        } else {
	        pL->next = (Link *) malloc(sizeof(Link));
	        pL->next->value = toAdd;
	        pL->next->next = NULL;
	    }   
    }
}

/**
 * \brief Remove the first occurence of the specified value
 * \param l the list who contains value
 * \param toRemove the first occurence of this value to remove
 */
void removeFirstOccur(List * l, int toRemove) {
    List pL = NULL,
	     save = NULL;

    if (*l) {
        if ((*l)->value == toRemove) {
            save = (*l)->next;
	        free(*l);
	        *l = save;
	    } else {
            for (pL = *l; pL->next && pL->next->value < toRemove; pL = pL->next);
         
            if (pL->next && pL->next->value == toRemove) {
                save = pL->next->next;
		        free(pL->next);
		        pL->next = save;
	        }
	    }
    }
}

/**
 * \brief Remove all occurences of the specified value
 * \param l the list who contains values
 * \param toRemove the value to remove
 */
void removeEachOccur(List * l, int toRemove) {
    List pL = NULL,
	     save = NULL;

    if (*l) {
        for (pL = *l; pL->next && pL->value <= toRemove; ) {
	        if ((*l)->value == toRemove) {
                save = (*l)->next;
		        free(*l);
		        *l = save;
		        pL = *l;
	        } else if (pL->next->value == toRemove) {
	            save = pL->next->next;
	            free(pL->next);
	            pL->next = save;
	        } else {
                pL = pL->next;
            }
	    }
    }
}

/**
 * \brief Empty the list
 * \param l the list to be emptied
 */
void empty(List * l) {
    List save = NULL;

    while (*l) {
        save = (*l)->next;
	    free(*l);
	    *l = save;
    }
}

/**
 * \brief Count number of values in list
 * \param l the list
 * \return the number of values in list
 */
int count(List l) {
    int nbValue = 0;

    while (l) {
        nbValue++;
	    l = l->next;
    }
    return nbValue;
}

/**
 * \brief Display all value lower than the specified value
 * \param l the list who contains values
 * \param maxLimit the limit value
 */
void displayIfLowerThan(List l, int maxLimit) {
    List pL = NULL;

    if (l) {
        for (pL = l; pL && pL->value < maxLimit; pL = pL->next) {
	        printf("%d ", pL->value);
	    }
	    printf("\n");
    }
}
