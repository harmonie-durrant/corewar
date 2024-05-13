/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for string put format function
*/

#include <criterion/criterion.h>
#include "pf.h"

Test(spf_tests, spf_char_tests)
{
    char *str = NULL;
    size_t len = 0;

    len = spf(str, "%c", 'a');
    cr_assert_eq(len, 1, "spf(NULL, \"%%c\", 'a') != 1, got %zu", len);
    str = malloc(sizeof(char) * len + 1);
    (void) spf(str, "%c", 'a');
    cr_assert_eq(str[0], 'a', "spf(str, \"%%c\", 'a')[0] != 'a', got %c", str[0]);
    free(str);
}

Test(spf_tests, spf_int_tests)
{
    char *str = NULL;
    size_t len = 0;

    len = spf(str, "%i", 42);
    cr_assert_eq(len, 2, "spf(NULL, \"%%i\", 42) != 2, got %zu", len);
    str = malloc(sizeof(char) * len + 1);
    (void) spf(str, "%i", 42);
    cr_assert_str_eq(str, "42", "spf(str, \"%%i\", 42) != \"42\", got %s", str);
    free(str);
}

Test(spf_tests, spf_float_tests)
{
    char *str = NULL;
    size_t len = 0;

    len = spf(str, "%f", 42.42);
    cr_assert_eq(len, 7, "spf(NULL, \"%%f\", 42.42) != 7, got %zu", len);
    str = malloc(sizeof(char) * len + 1);
    (void) spf(str, "%f", 42.42);
    cr_assert_str_eq(str, "42.4200", "spf(str, \"%%f\", 42.42) != \"42.4200\", got %s", str);
    free(str);
}

Test(spf_tests, spf_double_tests)
{
    char *str = NULL;
    size_t len = 0;

    len = spf(str, "%d", 1.23);
    cr_assert_eq(len, 6, "spf(NULL, \"%%d\", 1.23) != 6, got %zu", len);
    str = malloc(sizeof(char) * len + 1);
    (void) spf(str, "%d", 1.23);
    cr_assert_str_eq(str, "1.2300", "spf(str, \"%%d\", 1.23) != \"1.2300\", got %s", str);
    free(str);
}

Test(spf_tests, spf_string_tests)
{
    char *str = NULL;
    size_t len = 0;

    len = spf(str, "%s", "Hello World!");
    cr_assert_eq(len, 12, "spf(NULL, \"%%s\", \"Hello World!\") != 12, got %zu", len);
    str = malloc(sizeof(char) * len + 1);
    (void) spf(str, "%s", "Hello World!");
    cr_assert_str_eq(str, "Hello World!", "spf(str, \"%%s\", \"Hello World!\") != \"Hello World!\", got %s", str);
    free(str);
}

Test(spf_tests, spf_complex_tests)
{
    char *str = NULL;
    size_t len = 0;
    char *format = "[%i; %i] is %s. %s have %d %s. ID = %c\n";
    char *expected = "[123; 456] is Hello. World have 1.2300 seconds. ID = X\n";

    len = spf(str, format, 123, 456, "Hello", "World", 1.23, "seconds", 'X');
    cr_assert_eq(len, 55, "spf(NULL, format, 123, 456, \"Hello\", \"World\", 1.23, \"seconds\", 'X') != 51, got %zu", len);
    str = malloc(sizeof(char) * len + 1);
    (void) spf(str, format, 123, 456, "Hello", "World", 1.23, "seconds", 'X');
    cr_assert_str_eq(str, expected, "spf(str, format, 123, 456, \"Hello\", \"World\", 1.23, \"seconds\", 'X') != expected, got %s", str);
    free(str);
}