/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** main_tools_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

Test(main_tools_tests, check_args, .init = cr_redirect_stderr)
{
    char *av[2] = {"./corewar", NULL};

    cr_assert_eq(check_args(1, av), 84);
}

Test(main_tools_tests, check_args_1, .init = cr_redirect_stdout)
{
    char *av[3] = {"./corewar", "-h", NULL};

    cr_assert_eq(check_args(2, av), 0);
}

Test(main_tools_tests, check_args_2, .init = cr_redirect_stdout)
{
    char *av[4] = {"./corewar", "-dump", "50", NULL};

    cr_assert_eq(check_args(3, av), 1);
}
