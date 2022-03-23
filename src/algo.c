#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include <string.h>

#include "bsq.h"

char *get_map_size(char *map, size_t *size)
{
    *size = atoi(map);

    while (map[0] != '\n')
        map++;

    return map + 1;
}

static int check_case(int *i_map, size_t count, size_t size)
{
    int smallest = i_map[count - (size + 1)];

    if (i_map[count - (size + 2)] < smallest)
        smallest = i_map[count - (size + 2)];

    if (i_map[count - 1] < smallest)
        return i_map[count - 1] + 1;

    return smallest + 1;
}

static void draw_square_on_c_map(char *c_map, size_t map_size, size_t coord, int square_size)
{
    for (int i = 0; i < square_size; i++)
        for (int j = 0; j < square_size; j++)
            c_map[coord - j - (i * (map_size + 1))] = 'X';
}


char *algo(char *c_map, size_t size)
{
    int *i_map = char_to_int_array(c_map, strlen(c_map));
    int count = 0;

    size_t square_coord = 0;
    int square_size = 0;

    for (; i_map[count] != '\n'; count++)
        if (i_map[count] == '.')
            i_map[count] = 1;
        else
            i_map[count] = 0;

    for (; (size_t)count != size * size + size - 1; count++) {
        switch (i_map[count]) {
            case '\n':
                count++;
                if (i_map[count] == '.')
                    i_map[count] = 1;
                else
                    i_map[count] = 0;
                break;
            case 'o':
                i_map[count] = 0;
                break;
            default:
                i_map[count] = check_case(i_map, count, size);
        }

        if (i_map[count] > square_size) {
            square_size = i_map[count];
            square_coord = count;
        }
    }

    draw_square_on_c_map(c_map, size, square_coord, square_size);

    free(i_map);
    return c_map;
}