#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "bsq.h"

int main(int UNUSED(ac), char **av)
{
    char *file = get_file(av[1]);
    char *map = NULL;
    size_t map_size = 0;

    if (!file)
        return 1;

    map = get_map_size(file, &map_size);
    map = algo(map, map_size);

    //printf("%s", map);

    free(file);
}