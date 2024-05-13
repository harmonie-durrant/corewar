/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** assemble_file
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "asm.h"

Test(assemble_file, assembler, .init = cr_redirect_stderr)
{
    char *av[4] = {"./asm", "test.txt", NULL};

    cr_assert_eq(assembler(2, av), 84);
}

Test(assemble_file, assembler_1, .init = cr_redirect_stderr)
{
    char *av[3] = {"./asm", "notexist.s", NULL};

    cr_assert_eq(assembler(2, av), 84);
}
