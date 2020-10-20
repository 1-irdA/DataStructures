/**
 * @file link.c
 * @author Adrien GARROUSTE
 * @brief Represent a linked list
 * @version 0.1
 * @date 2020-10-05
 * @copyright No copyright, no right
 */

#include <stdio.h>
#include <stdlib.h>
#include "link.h"

/**
 * \brief Initialize the list 
 * \param List * l address of the list
 */ 
void create(List * l) {
    *l = NULL;
}

/**
 * \brief Display list value(s)
 * \param List l first element in list
 */ 
void display(List l) {
    List pL = NULL;	

    if (l == NULL) {
        printf("Empty list.");
    } else {
	    for (pL = l; pL; pL = pL->next) {
            printf("%d ", pL->value);
        }
    }
    printf("\n");
}

/**
 * \brief Count the number of values in the list
 * \param List * l first link in the list
 * \return int number of element(s) in the list
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
 * \brief Add an element at the beginning of the list
 * \param List * l address of the first link list
 * \param int toAdd integer to add at the beginning of the list
 * \return int 1 if removed, 0 else
 */ 
int addAtBegin(List * l, int toAdd) {
    List pL = *l;
    int added = 0;
    
    *l = (Link *) malloc(sizeof(Link));
    (*l)->value = toAdd;
    (*l)->next = pL;
    added = 1;

    return added;
}

/**
 * \brief Add an element at the end of the list
 * \param List * l address of the first link list
 * \param int toAdd integer to add at the list
 * \return int 1 if added, 0 else
 */ 
int addAtEnd(List * l, int toAdd) {
    List pL = NULL;
    int added = 1;

    if (*l == NULL) {
        addAtBegin(&(*l), toAdd);
    } else {
	    for (pL = *l; pL->next; pL = pL->next);

	    pL->next = (Link *)malloc(sizeof(Link));
	    pL->next->next = NULL;
	    pL->next->value = toAdd;
    }

    return added;
}

/**
 * \brief Remove the first link of list 
 * \param List * l address of the first link
 * \return int 1 if removed, 0 else
 */ 
int removeAtBegin(List * l) {
    int removed = 0;
    List save = NULL;

    if (*l) {
        save = (*l)->next;
        free(*l);
        *l = save;
        removed = 1;
    }
    return removed;
}

/**
 * \brief Remove the last element of the list
 * \param List * l address of the first link list
 * \return int 1 if removed, 0 else
 */ 
int removeAtEnd(List * l) {
    List pL = NULL;
    int removed = 1;

    if (*l) {
	    if ((*l)->next == NULL) {
            free(*l);
	        *l = NULL;
        } else {
            for (pL = *l; pL->next->next; pL = pL->next);
	        free(pL->next);
	        pL->next = NULL;
	    }
    } else {
        removed = 0;	
    }

    return removed;
}

/**
 * \brief Remove the first occurence of a value
 * \param List * l address of the first link list
 * \param int occurToRemove the value to removed one time
 * \return int 1 if removed, 0 else
 */ 
int removeFirstOccur(List * l, int occurToRemove) {
    List pL = NULL,
	     save = NULL;
    int removed = 1;

    if (*l == NULL) {
        removed = 0;
    } else if ((*l)->value == occurToRemove) {
        removeAtBegin(&(*l));
    } else {
        for (pL = *l; pL->next->next && pL->next->value != occurToRemove; pL = pL->next);
        
	    if (pL) {
            save = pL->next;
	        free(pL->next);
	        pL->next = NULL;
	    } else {
	        removed = 0;
	    }
    }

    return removed;
}

/**
 * \brief Copy all value(s) different(s) of notToCopy
 * \param List * l list who contains several values
 * \param List * modifiedList a list with all values different of notToCopy
 * \param int notToCopy the forbidden value to copy
 */ 
void copyWithoutOccur(List * l, List * modifiedList, int notToCopy) {
    List pL = NULL;

    if (*l) {
        for (pL = *l; pL->next; pL = pL->next) {
            if (pL->value != notToCopy) {
                addAtEnd(&(*modifiedList), pL->value);
	        }
	    }
    }
}

/**
 * \brief Empty the list l
 * \param List l address of first link list
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
 * \brief Insert a value after the first occurence
 * \param List * l address of first element of the list
 * \param int occurToSearch searched value in the list
 * \param int toAdd value to add after searched occurence
 * \return int 1 if added, 0 else
 */ 
int insertAfterOccur(List * l, int occurToSearch, int toAdd) {
    List pL = NULL,
	     save = NULL;
    int added = 1;

    if (*l == NULL) {
        added = 0;
    } else {
        for (pL = *l; pL->next && pL->value != occurToSearch; pL = pL->next);

	    if (pL) {
            save = pL->next;
	        pL->next = (Link *)malloc(sizeof(List));
	        pL->next->value = toAdd;
	        pL->next->next = save;
        } else {
	        added = 0;
	    }
    }
    return added;
}

/**
 * \brief Insert a value after an occurence
 * \param List * l address of the first element of the list
 * \param int occurToSearch searched value 
 * \param int toAdd value to insert after the occurToSearch
 * \return int number of elements added, 0 else
 */ 
int insertAfterEachOccur(List * l, int occurToSearch, int toAdd) {
    List pL = NULL, 
	     save = NULL;
    int added = 0;

    if (*l) {
	    for (pL = *l; pL; pL = pL->next) {
            if (pL->value == occurToSearch) {
                save = pL->next;
		        pL->next = (Link *)malloc(sizeof(Link));
		        pL->next->value = toAdd;
		        pL->next->next = save;
		        added++;
	        }
	    }
    }
    return added;
}

/**
 * \brief Compare two lists
 * \param List firstList list to compare with the second
 * \param List secondList list to compare with the first
 * \return int 1 lists are same, 0 else
 */ 
int isSameList(List firstList, List secondList) {
    List pFL = NULL,
	 pSL = NULL;
    int isSame = 0;

    if (firstList && secondList ) {
        for (pFL = firstList, pSL = secondList; 
	         pFL && pSL && pFL->value == pSL->value;
	         pFL = pFL->next, pSL = pSL->next);

	    if (pFL == NULL && pSL == NULL)
	        isSame = 1;
    }

    return isSame;
}

/**
 * \brief Determine if value is in the list
 * \param List l list contains value(s)
 * \param int searchedValue value to search in the list
 * \return 1 if value is present, 0 else
 */ 
int isPresent(List l, int searchedValue) {
    List pL = NULL;
    int present = 0;

    if (l) {
        for (pL = l; pL && pL->value != searchedValue; pL = pL->next);

	    if (pL != NULL)
	        present = 1;
    }
    return present;
}
