/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for check_files.c funcs
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "base.h"

Test(check_files_tests, check_files, .init = cr_redirect_stderr)
{
    char *av[3] = {"./test", "test.ext", NULL};

    cr_assert_eq(check_files(2, av, "ext"), 84);
}

Test(check_files_tests, check_files_1, .init = cr_redirect_stderr)
{
    char *av[5] = {"./test", "test.ext", "test.notext", NULL};

    cr_assert_eq(check_files(3, av, "ext"), 84);
}

Test(check_files_tests, check_files_2, .init = cr_redirect_stderr)
{
    char *av[5] = {"./test", "test.ext", "test.notext", NULL};

    cr_assert_eq(check_files(3, av, "ext"), 84);
}

Test(check_files_tests, check_file, .init = cr_redirect_stderr)
{
    cr_assert_eq(check_file("notexist.ext"), 84);
}
