/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for string functions
*/

#include <criterion/criterion.h>
#include "str.h"

Test(str_tests, salpha_tests)
{
    cr_assert_eq(salpha("Hello"), true);
    cr_assert_eq(salpha("Hello World"), false);
    cr_assert_eq(salpha("Hello 42!"), false);
}

Test(str_tests, snum_tests)
{
    cr_assert_eq(snum("Hello 42!"), false);
    cr_assert_eq(snum("42"), true);
    cr_assert_eq(snum("42Hello"), false);
}

Test(str_tests, salnum_tests)
{
    cr_assert_eq(salnum("Hello 42!"), false);
    cr_assert_eq(salnum("42"), true);
    cr_assert_eq(salnum("42Hello"), true);
    cr_assert_eq(salnum("Hello"), true);
    cr_assert_eq(salnum("Hello World"), false);
    cr_assert_eq(salnum("Hello 42!"), false);
}
