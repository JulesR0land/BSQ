#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include <fcntl.h>
#include <sys/stat.h>

char *get_file(char *path)
{
    int fd = open(path, O_RDONLY);
    char *file = NULL;
    struct stat statbuf;

    if (!fd) {
        perror("open error");
        return NULL;
    }

    if (fstat(fd, &statbuf) < 0) {
        perror("fstat error");
        return NULL;
    }

    file = malloc(sizeof(char) * statbuf.st_size);
    read(fd, file, statbuf.st_size);

    return file;
}