typedef struct link {
    int value;
    struct link * next;
} Link;

typedef Link * List;

/**
 * \brief Initialize the list
 * \param l the list to initialize
 */
void create(List * l);

/**
 * \brief Display all values of the list
 * \param l the list who contains values
 */
void display(List l);

/**
 * \brief Add a value and keep the ascending order
 * \param l the list to add value
 * \param toAdd the value to add
 */
void add(List * l, int toAdd);

/**
 * \brief Remove the first occurence of the specified value
 * \param l the list who contains value
 * \param toRemove the first occurence of this value to remove
 */
void removeFirstOccur(List * l, int toRemove);

/**
 * \brief Remove all occurences of the specified value
 * \param l the list who contains values
 * \param toRemove the value to remove
 */
void removeEachOccur(List * l, int toRemove);

/**
 * \brief Empty the list
 * \param l the list to be emptied
 */
void empty(List * l);

/**
 * \brief Count number of values in list
 * \param l the list
 * \return the number of values in list
 */
int count(List l);

/**
 * \brief Display all value lower than the specified value
 * \param l the list who contains values
 * \param maxLimit the limit value
 */
void displayIfLowerThan(List l, int maxValue);
