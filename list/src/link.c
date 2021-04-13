/**
 * \file link.c
 * \author Adrien GARROUSTE
 * \brief Represent a linked list
 * \version 0.1
 * \date 2020-10-05
 * \copyright No copyright, no right
 */

#include <stdio.h>
#include <stdlib.h>
#include "../headers/link.h"

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
    List pl = NULL;	

    if (l == NULL) {
        printf("Empty list.");
    } else {
	    for (pl = l; pl; pl = pl->next) {
            printf("%d ", pl->value);
        }
    }
    printf("\n");
}

/**
 * \brief Count the number of values in the list
 * \param List l first link in the list
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
 * \param int to_add integer to add at the beginning of the list
 * \return int 1 if removed, 0 else
 */ 
int add_at_begin(List * l, int to_add) {
    List pl = *l;
    int added = 0;
    
    *l = (Link *) malloc(sizeof(Link));
    (*l)->value = to_add;
    (*l)->next = pl;
    added = 1;

    return added;
}

/**
 * \brief Add an element at the end of the list
 * \param List * l address of the first link list
 * \param int to_add integer to add at the list
 * \return int 1 if added, 0 else
 */ 
int add_at_end(List * l, int to_add) {
    List pl = NULL;
    int added = 1;

    if (*l == NULL) {
        add_at_begin(&(*l), to_add);
    } else {
	    for (pl = *l; pl->next; pl = pl->next) {
        }

	    pl->next = (Link *)malloc(sizeof(Link));
	    pl->next->next = NULL;
	    pl->next->value = to_add;
    }

    return added;
}

/**
 * \brief Remove the first link of list 
 * \param List * l address of the first link
 * \return int 1 if removed, 0 else
 */ 
int remove_at_begin(List * l) {
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
int remove_at_end(List * l) {
    List pl = NULL;
    int removed = 1;

    if (*l) {
	    if ((*l)->next == NULL) {
            free(*l);
	        *l = NULL;
        } else {
            for (pl = *l; pl->next->next; pl = pl->next) {
            }
	        free(pl->next);
	        pl->next = NULL;
	    }
    } else {
        removed = 0;	
    }

    return removed;
}

/**
 * \brief Remove the first occurence of a value
 * \param List * l address of the first link list
 * \param int occur_to_remove the value to removed one time
 * \return int 1 if removed, 0 else
 */ 
int remove_first_occur(List * l, int occur_to_remove) {
    List pl = NULL, save = NULL;
    int removed = -1;

    if (*l == NULL) {
        removed = 0;
    } else if ((*l)->value == occur_to_remove) {
        remove_at_begin(&(*l));
    } else {
        for (pl = *l; pl->next->next && pl->next->value != occur_to_remove; pl = pl->next) {
        }
        
	    if (pl && pl->next && pl->next->value == occur_to_remove) {
            save = pl->next->next;
	        free(pl->next);
	        pl->next = save;
	    } else {
	        removed = 0;
	    }
    }

    return removed;
}

/**
 * \brief Remove all occurence of a value
 * \param List * l address of the first link list
 * \param int occur_to_remove the value to removed one time
 * \return int number of removed value
 */ 
void remove_all_occur(List * l, int occur_to_remove) {
    if (count(*l) == 1 && (*l)->value == occur_to_remove) {
        remove_at_begin(l);
    } else {
        copy_without_occur(l, l, occur_to_remove);
    }
}

/**
 * \brief Copy all value(s) different(s) of notToCopy
 * \param List * l list who contains several values
 * \param List * modified_list a list with all values different of not_to_copy
 * \param int not_to_copy the forbidden value to copy
 */ 
void copy_without_occur(List * l, List * modified_list, int not_to_copy) {
    List pl = NULL;

    if (l && modified_list) {

        empty(modified_list);

        for (pl = *l; pl->next; pl = pl->next) {
            if (pl->value != not_to_copy) {
                add_at_end(modified_list, pl->value);
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
 * \param int occur_to_search searched value in the list
 * \param int to_add value to add after searched occurence
 * \return int 1 if added, 0 else
 */ 
int insert_after_occur(List * l, int occur_to_search, int to_add) {
    List pl = NULL, save = NULL;
    int added = 1;

    if (*l == NULL) {
        added = 0;
    } else {
        for (pl = *l; pl->next && pl->value != occur_to_search; pl = pl->next) {
        }

	    if (pl) {
            save = pl->next;
	        pl->next = (Link *)malloc(sizeof(List));
	        pl->next->value = to_add;
	        pl->next->next = save;
        } else {
	        added = 0;
	    }
    }
    return added;
}

/**
 * \brief Insert a value after an occurence
 * \param List * l address of the first element of the list
 * \param int occur_to_search searched value 
 * \param int to_add value to insert after the occur_to_search
 * \return int number of elements added, 0 else
 */ 
int insert_after_each_occur(List * l, int occur_to_search, int to_add) {
    List pl = NULL, save = NULL;
    int added = 0;

    if (*l) {
	    for (pl = *l; pl; pl = pl->next) {
            if (pl->value == occur_to_search) {
                save = pl->next;
		        pl->next = (Link *)malloc(sizeof(Link));
		        pl->next->value = to_add;
		        pl->next->next = save;
		        added++;
	        }
	    }
    }
    return added;
}

/**
 * \brief Compare two lists
 * \param List first_list list to compare with the second
 * \param List second_list list to compare with the first
 * \return int 1 lists are same, 0 else
 */ 
int is_same_list(List first_list, List second_list) {
    List p_fl = NULL, p_sl = NULL;
    int is_same = 0;

    if (first_list && second_list) {
        for (p_fl = first_list, p_sl = second_list; 
	         p_fl && p_sl && p_fl->value == p_sl->value;
	         p_fl = p_fl->next, p_sl = p_sl->next) {
             }

	    if (p_fl == NULL && p_sl == NULL) {
	        is_same = 1;
        }
    }

    return is_same;
}

/**
 * \brief Determine if value is in the list
 * \param List l list contains value(s)
 * \param int searched_value value to search in the list
 * \return 1 if value is present, 0 else
 */ 
int is_present(List l, int searched_value) {
    List pl = NULL;
    int present = 0;

    for (pl = l; pl && pl->value != searched_value; pl = pl->next) {
    }

	if (pl) {
	    present = 1;
    }

    return present;
}

/**
 * \brief Convert a list to an array
 * \param List l list to convert
 * \return an array pointer
 */
int * to_array(List l) {
    List pl = NULL;
    int * arr = malloc(sizeof(int) * count(l));
    int i = 0;

    for (pl = l; pl; pl = pl->next, i++) {
        arr[i] = pl->value;
    }

    return arr;
}