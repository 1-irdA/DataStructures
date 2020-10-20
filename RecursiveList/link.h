/**
 * @brief Represent a link
 */
typedef struct link {
    int value;
    struct link * next;
} Link;

typedef struct link * List;

/**
 * @brief Initialize the list
 * \param l the list
 */
void create(List * l);

/**
 * \brief Display all lists values
 * \param l the list who contains value(s) to display
 */ 
void display(List l);

/**
 * \brief Count the number of values in list
 * \param l the list who contains value(s)
 * \return the number of value(s)
 */
int count(List l);

/**
 * \brief Add a integer value at the end of the list
 * \param l the list to add value
 * \param the value to add at the end of the list
 */ 
void addAtEnd(List * l, int toAdd);

/*
 * \brief Remove the last value in the list
 * \param l the list who contains value(s)
 */ 
void removeAtEnd(List * l);

/**
 * \brief Remove the first occurence of value toRemove
 * \param l the list who contains value(s)
 * \param toRemove the value to remove one time
 */
void removeFirstOccur(List * l, int toRemove);

/**
 * \brief Remove all occurences of value toRemove
 * \param l the list who contains the value(s)
 * \param toRemove the value to remove
 */
void removeEachOccur(List * l, int toRemove);

/**
 * \brief Add a value after first specified value
 * \param l the list who contains value(s)
 * \param occurToSearch the searched occurence
 * \param toAdd the value toAdd after the first specified occurence
 */ 
void addAfterFirstOccur(List * l, int occurToSearch, int toAdd);

/**
 * \brief Add a value after each specified value
 * \param l the list who contains value(s)
 * \param occurToSearch the specified value
 * \param toAdd the value to add after earch specified value
 */ 
void addAfterEachOccur(List * l, int occurToSearch, int toAdd);

/**
 * \brief Empty the list
 * \param l the list to be emptied
 */
void empty(List * l);

/**
 * \brief Return the last value of the list
 * \param l the list who contains value(s)
 * \return the last value
 */ 
int getLastValue(List l);

/**
 * \brief Compare two lists
 * \param List A to compare with list B
 * \param List B to compare with list A
 * \return 1 if same, 0 else
 */
int isSame(List lA, List lB);

/**
 * \brief Count the number of occurence in the list
 * \param l the list who contains value(s)
 * \param occurToSearch the searched value 
 * \return the number of searcnd value in list, else 0
 */
int nbOccurInList(List l, int occurToSearch);
