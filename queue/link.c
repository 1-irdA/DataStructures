/**
 * @file link.c
 * @author Adrien GARROUSTE
 * @brief Represent a queue
 * @version 0.1
 * @date 2020-10-05
 * @copyright No copyright, no right
 */
#include <stdio.h>
#include <stdlib.h>
#include "link.h"

/**
 * \brief Initialize the queue
 * \param Queue * q queue to initialize
 */
void create(Queue * q) {
    *q = NULL;
}

/**
 * \brief Display all values in the queue
 * \param Queue q queue who contains value(s)
 */
void display(Queue q) {
    Queue pQ = NULL;

    if (q == NULL) {
        printf("Empty queue\n");
    } else {
        for (pQ = q; pQ != NULL; pQ = pQ->next) {
            printf("%d ", pQ->value);
	    }
    }
    printf("\n");
}

/**
 * \brief Add a value at the end of the queue
 * \param Queue * q the queue who contains value(s)
 * \param int toAdd value to add at the end of the list
 * \return int 1 if added, 0 else
 */
int add(Queue * q, int toAdd) {
    Queue pQ = NULL;
    int added;

    if (*q == NULL) {
        *q = (Link *) malloc(sizeof(Link));
	    (*q)->value = toAdd;
	    (*q)->next = NULL;
    } else {
        for (pQ = *q; pQ->next != NULL; pQ = pQ->next);

	    pQ->next = (Link *) malloc(sizeof(Link));
	    pQ->next->value = toAdd;
	    pQ->next->next = NULL;
        added = 1;
    }
    return added;
}

/**
 * \brief Remove the first element of the queue
 * \param Queue * q the queue who contains value(s)
 * \return int the value removed
 */
int rmvFirst(Queue * q) {
    Queue save = NULL;
    int removedValue;

    if (*q == NULL) {
        removedValue = -1;
    } else if ((*q)->next == NULL) {
        removedValue = (*q)->value;
        free(*q);
        *q = NULL;	
    } else {
	    removedValue = (*q)->value;
        save = (*q)->next;
	    free(*q);
	    *q = save;
    }
    return removedValue;
}


/**
 * \brief Return the first value in the queue
 * \param Queue q the queue who contains values
 * \return int the first value in queue
 */
int peek(Queue q) {
    int firstValue;

    if (q == NULL) {
        firstValue = -1;
    } else {
        firstValue = q->value;
    }
    return firstValue;
}

/**
 * \brief Determine if a value is in the queue
 * \param Queue q the queue who contains value(s)
 * \param int searchedValue the value to search
 * \return int 1 if value is in queue, 0 else
 */
int isInQueue(Queue q, int searchedValue) {
    Queue pQ = NULL;
    int present = 1;

    if (q == NULL) {
        present = 0;
    } else {
	    for (pQ = q; pQ != NULL && pQ->value != searchedValue; pQ = pQ->next);
         
        if (pQ == NULL)
            present = 0;
    }
    return present;
}    

/**
 * \brief Empty the queue
 * \param Queue * q the queue to be emptied
 */
void empty(Queue * q) {
    Queue save = NULL;

    while (*q) {
        save = (*q)->next;
	    free(*q);
	    *q = save;
    }
}
