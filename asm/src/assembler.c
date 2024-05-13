/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** assembler
*/

#include <stdio.h>
#include "base.h"
#include "asm.h"
#include "str.h"
#include "pf.h"
#include "rules.h"

static int assemble_files(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        ASSERT_ERR(assemble_file(av[i]), ERROR);
    }
    return SUCCESS;
}

int assembler(int ac, char **av)
{
    ASSERT_ERR(check_files(ac, av, "s"), ERROR);
    ASSERT_ERR(assemble_files(ac, av), ERROR);
    return SUCCESS;
}
