/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** main_tools
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "asm.h"
#include "pf.h"
#include "str.h"
#include "len.h"
#include "rules.h"

static void print_help(void)
{
    fpf(1, "USAGE\n"
    "./asm file_name[.s]\n"
    "DESCRIPTION\n"
    "file_name file in assembly language to be converted into"
    "file_name.cor, an executable in the Virtual Machine.\n");
}

int check_args(int ac, char **av)
{
    if (ac < 2 || av == NULL) {
        epf("Usage: ./asm file_name[.s] ....\n");
        return ERROR;
    }
    if (ac == 2 && sexact(av[1], "-h")) {
        print_help();
        return SUCCESS;
    }
    return 1;
}
