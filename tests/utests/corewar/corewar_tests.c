/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

Test(corewar_tests, corewar_double_dump, .init = cr_redirect_stderr)
{
    char *av[4] = {"./corewar", "-dump", "-dump", NULL};

    cr_assert_eq(corewar(3, av), 84);
}
