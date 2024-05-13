/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for type length
*/

#include <criterion/criterion.h>
#include "str.h"

Test(smake_tests, snew_tests)
{
    char *str = snew(10, ' ');

    cr_assert_str_eq(str, "          ", "snew(10) != \"          \", str = %s", str);
    free(str);
}

Test(smake_tests, sfree_tests)
{
    char *str = snew(10, ' ');

    sfree(&str);
    cr_assert_eq(str, NULL, "sfree(str) != NULL");
}

Test(smake_tests, sdup_tests)
{
    char *str = "Hello World!";
    char *str2 = sdup(str);

    cr_assert_str_eq(str, str2, "sdup(\"Hello World!\") != \"Hello World!\", str2 = %s", str2);
    free(str2);
}

Test(smake_tests, sdupn_tests)
{
    char *str = "Hello World!";
    char *str2 = sdupn(str, 5);

    cr_assert_neq(str, NULL, "str2 == NULL");
    cr_assert_str_eq(str2, "Hello", "sdupn(\"Hello World!\", 5) != \"Hello\", str2 = %s", str2);
    free(str2);
}

Test(smake_tests, smerge_tests)
{
    char *str = "Hello ";
    char *str2 = "World!";
    char *str3 = "Hello World!";
    char *result = NULL;

    result = smerge(str, str2);
    cr_assert_str_eq(result, str3, "smerge(\"Hello \", \"World!\") != \"Hello World!\", result = %s", result);
    free(result);
}