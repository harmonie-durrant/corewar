/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for chars
*/

#include <criterion/criterion.h>
#include "base.h"

Test(foo_to_sort_tests, make_dec_tests)
{
    cr_assert(make_dec(0) == 0, "Expected 0 for 0, got %f", make_dec(0));
    cr_assert(make_dec(1) == 0.1, "Expected 0.1 for 1, got %f", make_dec(1));
    cr_assert(make_dec(123) == 0.123, "Expected 0.01 for 10, got %f", make_dec(123));
}