#include <stdio.h>

/**
 * \brief Compare two arrays
 * \param to_compare_with_b array to compare with an other array
 * \param size_of_a array size
 * \param to_compare_with_a array to compare with an other array
 * \param size_of_b array size
 * \return 0 if same, else -1
 */
int compare(int * to_compare_with_b, int size_of_a, int * to_compare_with_a, int size_of_b) {

    int i = -1;

    if (size_of_a == size_of_b) {      
        for (i = 0; i < size_of_a && to_compare_with_b[i] == to_compare_with_a[i]; i++);
    }

    return i == size_of_a ? 1 : 0;
}

/**
 * \brief Display an array
 * \param to_display array to display
 * \param size array size
 */
void display_arr(int * to_display, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", to_display[i]);
    }
}