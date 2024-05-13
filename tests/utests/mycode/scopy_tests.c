/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for type length
*/

#include <criterion/criterion.h>
#include "str.h"

Test(scopy_tests, scpy_tests)
{
    char str[60] = "Hello World!";
    char *str2 = "World!";
    char *str3 = "World!World!";

    scpy(str, str2);
    cr_assert_str_eq(str, str3, "scpy(\"Hello World!\", \"World!\") != \"World!World!\", str = %s", str);
}

Test(scopy_tests, scpyn_tests)
{
    char str[60] = "Hello World!";
    char *str2 = "World!";
    char *str3 = "Worlo World!";

    scpyn(str, str2, 3);
    cr_assert_str_eq(str, str3, "scpyn(\"Hello World!\", \"World!\", 6) != \"Worlo World!\", str = %s", str);
}