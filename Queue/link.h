/**
 * @brief Represent a link
 */
typedef struct link {
    int value;
    struct link * next;
} Link;

typedef struct link * Queue;

/**
 * \brief Initialize the queue
 * \param Queue * q queue to initialize
 */
void create(Queue * q);

/**
 * \brief Display all values in the queue
 * \param Queue q queue who contains value(s)
 */
void display(Queue q);

/**
 * \brief Add a value at the end of the queue
 * \param Queue * q the queue who contains value(s)
 * \param int toAdd value to add at the end of the list
 * \return int 1 if added, 0 else
 */
int add(Queue * q, int toAdd);

/**
 * \brief Remove the first element of the queue
 * \param Queue * q the queue who contains value(s)
 * \return int the value removed
 */
int rmvFirst(Queue * q);

/**
 * \brief Return the first value in the queue
 * \param Queue q the queue who contains values
 * \return int the first value in queue
 */
int peek(Queue q);

/**
 * \brief Determine if a value is in the queue
 * \param Queue q the queue who contains value(s)
 * \param int searchedValue the value to search
 * \return int 1 if value is in queue, 0 else
 */
int isInQueue(Queue q, int searchedValue);

/**
 * \brief Empty the queue
 * \param Queue * q the queue to be emptied
 */
void empty(Queue * q);
