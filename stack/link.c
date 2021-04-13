/**
 * @file link.c
 * @author Adrien GARROUSTE
 * @brief Represent a stack
 * @version 0.1
 * @date 2020-10-05
 * @copyright No copyright, no right
 */

#include <stdio.h>
#include <stdlib.h>
#include "link.h"

/**
 * \brief Initialise the stack
 * \param Stack * s stack to initialize
 */
void create(Stack * s) {
    *s = NULL;
}

/**
 * \brief Display all value(s) in stack
 * \param Stack s stack who contains integer values
 */
void display(Stack s) {
    Stack pS = NULL;

    if (s == NULL) {
        printf("Empty stack.\n");
    } else {
        for (pS = s; pS != NULL; pS = pS->next) {
	        printf("%d ", pS->value);
	    }
    }
    printf("\n");
}

/**
 * \brief Add an element at the end of the stack
 * \param Stack * s the stack to add the value
 * \param int toAdd the value to add at the end of the stack
 * \return int 1 if added, 0 else
 */
int push(Stack * s, int toAdd) {
    Stack pS = NULL;

    if (*s == NULL) {
        *s = (Link *) malloc(sizeof(Link));
	    (*s)->value = toAdd;
	    (*s)->next = NULL;
    } else {
        for (pS = *s; pS->next != NULL; pS = pS->next);

	    pS->next = (Link *) malloc(sizeof(Link));
	    pS->next->value = toAdd;
	    pS->next->next = NULL;
    } 
}

/**
 * \brief Remove the last element added (top value)
 * \param Stack * s the stack who contains values
 * \return int the removed element
 */
int pop(Stack * s) {
    Stack pS = NULL;
    int poppedValue;

    if (*s == NULL) {
        poppedValue = -1;
    } else if ((*s)->next == NULL) {
        poppedValue = (*s)->value;
	    free(*s);
	    *s = NULL;
    } else {	    
        for (pS = *s; pS->next->next != NULL; pS = pS->next);

	    poppedValue = pS->next->value;
	    free(pS->next);
	    pS->next = NULL;
    }
    return poppedValue;
}

/**
 * \brief Detemine if a value is in the stack
 * \param Stack s the stack who contains values
 * \param int searchedValue the searched value in the stack
 * \return int 1 if value is in stack, 0 else
 */
int isInStack(Stack s, int searchedValue) {
    Stack pS = NULL;
    int present = 1;

    if (s == NULL) {
        present = 0;
    } else {
        for (pS = s; pS != NULL && pS->value != searchedValue; pS = pS->next);

        if (pS == NULL)
	    present = 0;
    }
    return present;
}

/**
 * \brief Empty the stack
 * \param Stack * s the stack to be emptied
 */
void empty(Stack * s) {
    Stack save = NULL;

    while (*s) {
        save = (*s)->next;
	    free(*s);
	    *s = save;
    }
}

/**
 * \brief Return the value on top of stack without remove him
 * \param Stack s the stack who contains values
 */
int peek(Stack s) {
    Stack pS = NULL;
    int topElt;

    if (s == NULL) {
        topElt = -1;
    } else {
        for (pS = s; pS->next != NULL; pS = pS->next);

	    topElt = pS->value;
    }
    return topElt;
}
