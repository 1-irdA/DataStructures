/**
 * \file link.h
 * \author Adrien GARROUSTE
 * \brief Represent a linked list
 * \version 0.1
 * \date 2020-10-05
 * \copyright No copyright, no right
 */

#ifndef __LIST__
#define __LIST__

/**
 * @brief Represent a link
 */
typedef struct link {
    int value;
    struct link * next;
} Link;

typedef struct link * List;

/**
 * \brief Initialize the list 
 * \param List * l address of the list
 */ 
void create(List * l);

/**
 * \brief Display list value(s)
 * \param List l first element in list
 */ 
void display(List l);

/**
 * \brief Count the number of values in the list
 * \param List * l first link in the list
 * \return int number of element(s) in the list
 */ 
int count(List l);

/**
 * \brief Add an element at the beginning of the list
 * \param List * l address of the first link list
 * \param int to_add integer to add at the beginning of the list
 * \return int 1 if removed, 0 else
 */ 
int add_at_begin(List * l, int to_add);

/**
 * \brief Add an element at the end of the list
 * \param List * l address of the first link list
 * \param int to_add integer to add at the list
 * \return int 1 if added, 0 else
 */ 
int add_at_end(List * l, int to_add);

/**
 * \brief Remove the first link of list 
 * \param List * l address of the first link
 * \return int 1 if removed, 0 else
 */ 
int remove_at_begin(List * l);

/**
 * \brief Remove the last element of the list
 * \param List * l address of the first link list
 * \return int 1 if removed, 0 else
 */ 
int remove_at_end(List * l);

/**
 * \brief Remove the first occurence of a value
 * \param List * l address of the first link list
 * \param int occur_to_remove the value to removed one time
 * \return int 1 if removed, 0 else
 */
int remove_first_occur(List * l, int occur_to_remove);

/**
 * \brief Remove all occurence of a value
 * \param List * l address of the first link list
 * \param int occur_to_remove the value to removed one time
 * \return the number of removed values
 */
int remove_all_occur(List * l, int occur_to_remove);

/**
 * \brief Copy all value(s) different(s) of notToCopy
 * \param List * l src who contains several values
 * \param List * modifiedList a list with all values different of notToCopy
 * \param int not_to_copy the forbidden value to copy
 */ 
void copy_without_occur(List * src, List * dst, int not_to_copy);

/**
 * \brief Empty the list l
 * \param List l address of first link list
 */
void empty(List * l);

/**
 * \brief Insert a value after the first occurence
 * \param List * l address of first element of the list
 * \param int occur_to_search searched value in the list
 * \param int to_add value to add after searched occurence
 * \return int 1 if added, 0 else
 */ 
int insert_after_occur(List * l, int occur_to_search, int to_add);

/**
 * \brief Insert a value after an occurence
 * \param List * l address of the first element of the list
 * \param int occur_to_search searched value 
 * \param int to_add value to insert after the occur_to_search
 * \return int number of elements added, 0 else
 */ 
int insert_after_each_occur(List * l, int occur_to_search, int to_add);

/**
 * \brief Compare two lists
 * \param List first_list list to compare with the second
 * \param List second_list list to compare with the first
 * \return int 1 lists are same, 0 else
 */ 
int is_same_list(List first_list, List second_list);

/**
 * \brief Determine if value is in the list
 * \param List l list contains value(s)
 * \param int searched_value value to search in the list
 * \return 1 if value is present, 0 else
 */ 
int is_present(List l, int searched_value);

/**
 * \brief convert a list to an array
 * \param List l list to convert in array
 * \return an array with list values
 */
int * to_array(List l);

#endif
