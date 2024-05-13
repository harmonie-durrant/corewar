/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for type allocation
*/

#include <criterion/criterion.h>
#include "gf.h"

Test(sgf_type_tests, sgf_char_tests)
{
    char *c = NULL;

    c = sgf_char("a");
    cr_assert(c != NULL, "sgf_char(\"a\") == NULL");
    cr_assert_eq(*c, 'a', "sgf_char(\"a\") != 'a', got %c", *c);
    free(c);
}

Test(sgf_type_tests, sgf_int_tests)
{
    int *i = NULL;

    i = sgf_int("123");
    cr_assert(i != NULL, "sgf_int(\"123\") == NULL");
    cr_assert_eq(*i, 123, "sgf_int(\"123\") != 123, got %i", *i);
    free(i);
}

Test(sgf_type_tests, sgf_float_tests)
{
    float *f = NULL;

    f = sgf_float("-1.23");
    cr_assert(f != NULL, "sgf_float(\"-1.23\") == NULL");
    cr_assert_eq(*f, -1.23f, "sgf_float(\"-1.23\") != -1.23, got %f", *f);
    free(f);
}

Test(sgf_type_tests, sgf_double_tests)
{
    double *d = NULL;

    d = sgf_double("-1.23");
    cr_assert(d != NULL, "sgf_double(\"-1.23\") == NULL");
    cr_assert_eq(*d, -1.23, "sgf_double(\"-1.23\") != -1.23, got %f", *d);
    free(d);
}
