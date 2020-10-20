/**
 * @brief Represent a link
 */
typedef struct link {
    int value;
    struct link * next;
} Link;

typedef struct link * Stack;

/**
 * \brief Initialise the stack
 * \param Stack * s stack to initialize
 */
void create(Stack * s);

/**
 * \brief Display all value(s) in stack
 * \param Stack s stack who contains integer values
 */
void display(Stack s);

/**
 * \brief Add an element at the end of the stack
 * \param Stack * s the stack to add the value
 * \param int toAdd the value to add at the end of the stack
 * \return int 1 if added, 0 else
 */
int push(Stack * s, int toAdd);

/**
 * \brief Remove the last element added (top value)
 * \param Stack * s the stack who contains values
 * \return int the removed element
 */
int pop(Stack * s);

/**
 * \brief Detemine if a value is in the stack
 * \param Stack s the stack who contains values
 * \param int searchedValue the searched value in the stack
 * \return int 1 if value is in stack, 0 else
 */
int isInStack(Stack s, int searchedValue);

/**
 * \brief Empty the stack
 * \param Stack * s the stack to be emptied
 */
void empty(Stack * s);

/**
 * \brief Return the value on top of stack without remove him
 * \param Stack s the stack who contains values
 */
int peek(Stack s);
