/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for string put format function
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "pf.h"
#include "str.h"

Test(vquicks, vquicks_test)
{
    char* str = NULL;
    va_list ap;
    va_list ap_cp;

    str = vquicks(NULL, ap, ap_cp);
    cr_assert_eq(str, NULL, "Unexpected NULL result");
}

Test(quicks, quicks_test)
{
    char* str = NULL;

    str = quicks(NULL);
    cr_assert_eq(str, NULL, "Unexpected NULL result");
}

Test(quicks, quicks_test2)
{
    char* str = NULL;

    str = quicks("Hello World");
    cr_assert_str_eq(str, "Hello World", "Unexpected result");
}
