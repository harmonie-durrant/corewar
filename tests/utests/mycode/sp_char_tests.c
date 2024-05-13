/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for string put functions
*/

#include <criterion/criterion.h>
#include "pf.h"
#include "str.h"

Test(sp_tests, spchar_tests)
{
    char *str = NULL;
    size_t len = 0;

    len = spchar(str, 'a');
    cr_assert_eq(len, 1, "spchar(NULL, 'a') != 1, got %zu", len);
    str = snew(len, ' ');
    (void) spchar(str, 'a');
    cr_assert_eq(str[0], 'a', "spchar(str, 'a')[0] != 'a'");
    free(str);
}

Test(sp_tests, spstr_tests)
{
    char *str = NULL;
    size_t len = 0;

    len = spstr(str, "Hello World!");
    cr_assert_eq(len, 12, "spstr(NULL, \"Hello World!\") != 12, got %zu", len);
    str = snew(len, ' ');
    (void) spstr(str, "Hello World!");
    cr_assert_str_eq(str, "Hello World!", "spstr(str, \"Hello World!\") != \"Hello World!\", got %s", str);
    free(str);
}
