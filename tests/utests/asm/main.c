/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** main
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "asm.h"

Test(main, check_args, .init = cr_redirect_stderr)
{
    int ac = 0;
    char **av = NULL;

    cr_assert_eq(check_args(ac, av), 84);
}

Test(main, check_args_2, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[3] = {"./asm", "-h", NULL};

    cr_assert_eq(check_args(ac, av), 0);
}

Test(main, check_args_3)
{
    int ac = 2;
    char *av[3] = {"./asm", "tests/champions/src/pdd.s", NULL};

    cr_assert_eq(check_args(ac, av), 1);
}

Test(main, assembler)
{
    cr_assert(1);
}
