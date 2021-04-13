/**
 * @file link.c
 * @author Adrien GARROUSTE
 * @brief Represent a recursive list
 * @version 0.1
 * @date 2020-10-05
 * @copyright No cpyright, no right
 */

#include <stdio.h>
#include <stdlib.h>
#include "link.h"

/**
 * @brief Initialize the list
 * \param l the list
 */
void create(List * l) {
    *l = NULL;
}

/**
 * \brief Display all lists values
 * \param l the list who contains value(s) to display
 */ 
void display(List l) {
    if (l) {
	    printf("%d ", l->value);
	    display(l->next);
    } else {
        printf("\n");
    }
}

/**
 * \brief Count the number of values in list
 * \param l the list who contains value(s)
 * \return the number of value(s)
 */
int count(List l) {
    if (l == NULL) {
        return 0;
    } else {
        return 1 + count(l->next);
    }
}

/**
 * \brief Add a integer value at the end of the list
 * \param l the list to add value
 * \param the value to add at the end of the list
 */ 
void addAtEnd(List * l, int toAdd) {
    if (*l == NULL) {
        *l = (Link *) malloc(sizeof(Link));
	    (*l)->value = toAdd;
	    (*l)->next = NULL;
    } else if ((*l)->next) {
	    addAtEnd(&(*l)->next, toAdd);
    } else {
	    (*l)->next = (Link *) malloc(sizeof(Link));
	    (*l)->next->value = toAdd;
	    (*l)->next->next = NULL;
    }
}

/*
 * \brief Remove the last value in the list
 * \param l the list who contains value(s)
 */ 
void removeAtEnd(List * l) {
    if (*l && (*l)->next) {
	    removeAtEnd(&(*l)->next);
    } else {
        free(*l);
	    *l = NULL;
    }
}

/**
 * \brief Remove the first occurence of value toRemove
 * \param l the list who contains value(s)
 * \param toRemove the value to remove one time
 */
void removeFirstOccur(List * l, int toRemove) {
    List save = NULL;
    if (*l) {
	    if ((*l)->value == toRemove) {
            save = (*l)->next;
	        free(*l);
	        *l = save;
	    } else {
            removeFirstOccur(&(*l)->next, toRemove);
	    }
    }
}	    

/**
 * \brief Remove all occurences of value toRemove
 * \param l the list who contains the value(s)
 * \param toRemove the value to remove
 */
void removeEachOccur(List * l, int toRemove) {
    List save = NULL;
    if (*l) {
	    // first value == toRemove and only one value
        if ((*l)->value == toRemove && !(*l)->next) {
	        free(*l);
	        *l = NULL;
	    } else if ((*l)->next && (*l)->value == toRemove) {
            save = (*l)->next;
	        free(*l);
	        *l = save;
	        removeEachOccur(&(*l), toRemove);
	    } else {
	        removeEachOccur(&(*l)->next, toRemove);
        }
    }
}

/**
 * \brief Add a value after first specified value
 * \param l the list who contains value(s)
 * \param occurToSearch the searched occurence
 * \param toAdd the value toAdd after the first specified occurence
 */ 
void addAfterFirstOccur(List * l, int occurToSearch, int toAdd) {
    List save = NULL;
    if (*l) {
        if ((*l)->value == occurToSearch) {
            save = (*l)->next;
	        (*l)->next = (Link *) malloc(sizeof(Link));
	        (*l)->next->value = toAdd;
	        (*l)->next->next = save;
	    } else {
	        addAfterFirstOccur(&(*l)->next, occurToSearch, toAdd);
	    }
    }
}

/**
 * \brief Add a value after each specified value
 * \param l the list who contains value(s)
 * \param occurToSearch the specified value
 * \param toAdd the value to add after earch specified value
 */ 
void addAfterEachOccur(List * l, int occurToSearch, int toAdd) {
    List save = NULL;
    if (*l) {
        if ((*l)->value == occurToSearch) {
            save = (*l)->next;
	        (*l)->next = (Link *) malloc(sizeof(Link));
	        (*l)->next->value = toAdd;
	        (*l)->next->next = save;
	    }
	    addAfterEachOccur(&(*l)->next, occurToSearch, toAdd);
    }
}

/**
 * \brief Empty the list
 * \param l the list to be emptied
 */ 
void empty(List * l) {
    List save = NULL;
    if (*l) {
        save = (*l)->next;
	    free(*l);
	    *l = save;
	    empty(&(*l));
    }
}

/**
 * \brief Return the last value of the list
 * \param l the list who contains value(s)
 * \return the last value
 */ 
int getLastValue(List l) {
    if (!l) {
        return 0;
    } else if (l->next) {
        return getLastValue(l->next);
    } else {
        return l->value;
    }
}

/**
 * \brief Compare two lists
 * \param List A to compare with list B
 * \param List B to compare with list A
 * \return 1 if same, 0 else
 */
int isSame(List lA, List lB) {
    int same = 0;

    if (lA && lB && lA->value == lB->value) {
        return isSame(lA->next, lB->next);
    }

    if (!lA && !lA)
        same = 1;

    return same;
}

/**
 * \brief Count the number of occurence in the list
 * \param l the list who contains value(s)
 * \param occurToSearch the searched value 
 * \return the number of searcnd value in list, else 0
 */
int nbOccurInList(List l, int occurToSearch) {
    if (l) {
        if (l->value == occurToSearch)
	        return 1 + nbOccurInList(l->next, occurToSearch);
	    else
	        return nbOccurInList(l->next, occurToSearch);
    }
    return 0;

}
