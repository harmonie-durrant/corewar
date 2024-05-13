/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** check_files
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "len.h"
#include "str.h"
#include "pf.h"
#include "rules.h"

static int get_last_occ(char *str, char c)
{
    int i_occ = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            i_occ = i;
        }
    }
    return i_occ;
}

static int check_extension(char *filename, char *extension)
{
    int i_ext = 0;
    char *file_ext = NULL;

    i_ext = get_last_occ(filename, '.');
    if (i_ext == -1) {
        fpf(2, "Error: Invalid extension for the file '%s'.\n", filename);
        return ERROR;
    }
    file_ext = filename + i_ext;
    if (sequal(file_ext, extension) != 0) {
        fpf(2, "Error: Invalid extension for the file '%s'.\n", filename);
        return ERROR;
    }
    return SUCCESS;
}

int check_file(char *filename)
{
    int fd = 0;

    fd = open(filename, O_RDONLY, 0777);
    if (fd == -1) {
        epf("Error in function open: No such file or directory.\n");
        return ERROR;
    }
    close(fd);
    return SUCCESS;
}

int check_files(int ac, char **av, char *extension)
{
    for (int i = 1; i < ac; i++) {
        if (check_extension(av[i], extension) == ERROR) {
            return ERROR;
        }
        if (check_file(av[i]) == ERROR) {
            return ERROR;
        }
    }
    return SUCCESS;
}
