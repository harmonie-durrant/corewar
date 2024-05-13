/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for type allocation
*/

#include <criterion/criterion.h>
#include "talloc.h"

Test(talloc_tests, char_alloc_tests)
{
    char *str = NULL;

    str = char_alloc('a');
    cr_assert_neq(str, NULL, "Expected non-NULL, got NULL");
    cr_assert_eq(str[0], 'a', "Expected 'a', got %c", str[0]);
    free(str);
    str = char_alloc('Z');
    cr_assert_neq(str, NULL, "Expected non-NULL, got NULL");
    cr_assert_eq(str[0], 'Z', "Expected 'Z', got %c", str[0]);
    free(str);
}

Test(talloc_tests, int_alloc_tests)
{
    int *nbr = NULL;

    nbr = int_alloc(0);
    cr_assert_neq(nbr, NULL, "Expected non-NULL, got NULL");
    cr_assert_eq(*nbr, 0, "Expected 0, got %d", *nbr);
    free(nbr);
    nbr = int_alloc(123);
    cr_assert_neq(nbr, NULL, "Expected non-NULL, got NULL");
    cr_assert_eq(*nbr, 123, "Expected 123, got %d", *nbr);
    free(nbr);
    nbr = int_alloc(-123);
    cr_assert_neq(nbr, NULL, "Expected non-NULL, got NULL");
    cr_assert_eq(*nbr, -123, "Expected -123, got %d", *nbr);
    free(nbr);
}

Test(talloc_tests, float_alloc_tests)
{
    float *nbr = NULL;

    nbr = float_alloc(0);
    cr_assert_neq(nbr, NULL, "Expected non-NULL, got NULL");
    cr_assert_eq(*nbr, 0, "Expected 0, got %f", *nbr);
    free(nbr);
    nbr = float_alloc(123.456f);
    cr_assert_neq(nbr, NULL, "Expected non-NULL, got NULL");
    cr_assert_eq(*nbr, 123.456f, "Expected 123.456, got %f", *nbr);
    free(nbr);
    nbr = float_alloc(-123.456f);
    cr_assert_neq(nbr, NULL, "Expected non-NULL, got NULL");
    cr_assert_eq(*nbr, -123.456f, "Expected -123.456, got %f", *nbr);
    free(nbr);
}

Test(talloc_tests, double_alloc_tests)
{
    double *nbr = NULL;

    nbr = double_alloc(0);
    cr_assert_neq(nbr, NULL, "Expected non-NULL, got NULL");
    cr_assert_eq(*nbr, 0, "Expected 0, got %f", *nbr);
    free(nbr);
    nbr = double_alloc(123.456);
    cr_assert_neq(nbr, NULL, "Expected non-NULL, got NULL");
    cr_assert_eq(*nbr, 123.456, "Expected 123.456, got %f", *nbr);
    free(nbr);
    nbr = double_alloc(-123.456);
    cr_assert_neq(nbr, NULL, "Expected non-NULL, got NULL");
    cr_assert_eq(*nbr, -123.456, "Expected -123.456, got %f", *nbr);
    free(nbr);
}