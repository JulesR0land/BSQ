#include <stddef.h>
#include <stdlib.h>

int *char_to_int_array(char *c_array, size_t size)
{
    int *i_array = malloc(sizeof(int) * size);

    for (size_t i = 0; i < size; i++)
        i_array[i] = (int)c_array[i];

    return i_array;
}