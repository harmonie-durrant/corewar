/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** ftos
*/

#include <stdlib.h>
#include <unistd.h>
#include "str.h"

char *ftos(int fd)
{
    char *str = NULL;
    char *tmp = NULL;
    char buffer[2] = {0};

    if (fd < 0) {
        return NULL;
    }
    while (read(fd, buffer, 1) > 0) {
        tmp = str;
        str = smerge(str, buffer);
        free(tmp);
    }
    return str;
}
