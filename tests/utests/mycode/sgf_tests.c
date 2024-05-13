/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for type allocation
*/

#include <criterion/criterion.h>
#include "gf.h"

Test(sgf_tests, sgf_char_tests)
{
    void **results = NULL;
    char *format = "%c %c";
    char *str = "a b";

    results = sgf(format, str);
    cr_assert(results != NULL, "sgf(\"%s\", \"%s\") == NULL", str, format);
    cr_assert_eq(*(char *)results[0], 'a', "sgf(\"%s\", \"%s\")[0] != 'a', got %c", str, format, *(char *)results[0]);
    cr_assert_eq(*(char *)results[1], 'b', "sgf(\"%s\", \"%s\")[1] != 'b', got %c", str, format, *(char *)results[1]);
    free(results[0]);
    free(results[1]);
    free(results);
}

Test(sgf_tests, sgf_int_tests)
{
    void **results = NULL;
    char *format = "%i %i";
    char *str = "123 456";

    results = sgf(format, str);
    cr_assert(results != NULL, "sgf(\"%s\", \"%s\") == NULL", str, format);
    cr_assert_eq(*(int *)results[0], 123, "sgf(\"%s\", \"%s\")[0] != 123, got %i", str, format, *(int *)results[0]);
    cr_assert_eq(*(int *)results[1], 456, "sgf(\"%s\", \"%s\")[1] != 456, got %i", str, format, *(int *)results[1]);
    free(results[0]);
    free(results[1]);
    free(results);
}

Test(sgf_tests, sgf_double_tests)
{
    void **results = NULL;
    char *format = "%d %d";
    char *str = "1.23 4.56";

    results = sgf(format, str);
    cr_assert(results != NULL, "sgf(\"%s\", \"%s\") == NULL", str, format);
    cr_assert_eq(*(double *)results[0], 1.23, "sgf(\"%s\", \"%s\")[0] != 1.23, got %f", str, format, *(double *)results[0]);
    cr_assert_eq(*(double *)results[1], 4.56, "sgf(\"%s\", \"%s\")[1] != 4.56, got %f", str, format, *(double *)results[1]);
    free(results[0]);
    free(results[1]);
    free(results);
}

Test(sgf_tests, sgf_string_tests)
{
    void **results = NULL;
    char *format = "%s %s";
    char *str = "Hello World";

    results = sgf(format, str);
    cr_assert(results != NULL, "sgf(\"%s\", \"%s\") == NULL", str, format);
    cr_assert_str_eq((char *)results[0], "Hello", "sgf(\"%s\", \"%s\")[0] != \"Hello\", got %s", str, format, (char *)results[0]);
    cr_assert_str_eq((char *)results[1], "World", "sgf(\"%s\", \"%s\")[1] != \"World\", got %s", str, format, (char *)results[1]);
    free(results[0]);
    free(results[1]);
    free(results);
}

Test(sgf_tests, sgf_complex_tests)
{
    void **results = NULL;
    char *format = "[%i; %i] is %s. %s have %d %s. ID = %c\n";
    char *str = "[123; 456] is Hello. World have 1.23 seconds. ID = X";

    results = sgf(format, str);
    cr_assert(results != NULL, "sgf(\"%s\", \"%s\") == NULL", str, format);
    cr_assert_eq(*(int *)results[0], 123, "sgf(\"%s\", \"%s\")[0] != 123, got %i", str, format, *(int *)results[0]);
    cr_assert_eq(*(int *)results[1], 456, "sgf(\"%s\", \"%s\")[1] != 456, got %i", str, format, *(int *)results[1]);
    cr_assert_str_eq((char *)results[2], "Hello", "sgf(\"%s\", \"%s\")[2] != \"Hello\", got %s", str, format, (char *)results[2]);
    cr_assert_str_eq((char *)results[3], "World", "sgf(\"%s\", \"%s\")[3] != \"World\", got %s", str, format, (char *)results[3]);
    cr_assert_eq(*(double *)results[4], 1.23, "sgf(\"%s\", \"%s\")[4] != 1.23, got %f", str, format, *(double *)results[4]);
    cr_assert_str_eq((char *)results[5], "seconds", "sgf(\"%s\", \"%s\")[5] != \"seconds\", got %s", str, format, (char *)results[5]);
    cr_assert_eq(*(char *)results[6], 'X', "sgf(\"%s\", \"%s\")[6] != 'X', got %c", str, format, *(char *)results[6]);
    free(results[0]);
    free(results[1]);
    free(results[2]);
    free(results[3]);
    free(results[4]);
    free(results[5]);
    free(results[6]);
    free(results);
}