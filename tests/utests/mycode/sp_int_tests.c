/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for string put functions
*/

#include <criterion/criterion.h>
#include "pf.h"
#include "str.h"

Test(sp_tests, spint_tests)
{
    char *str = NULL;
    size_t len = 0;

    len = spint(str, 42);
    cr_assert_eq(len, 2, "spint(NULL, 42) != 2, got %zu", len);
    str = snew(len, ' ');
    (void) spint(str, 42);
    cr_assert_str_eq(str, "42", "spint(str, 42) != \"42\", got \"%s\"", str);
    free(str);
}
