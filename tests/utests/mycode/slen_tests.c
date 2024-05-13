/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for type length
*/

#include <criterion/criterion.h>
#include "len.h"

Test(slen_tests, slen_tests)
{
    cr_assert_eq(slen("123"), 3, "slen(\"123\") != 3, slen(\"123\") = %d", slen("123"));
    cr_assert_eq(slen(""), 1, "slen(\"\") != 1, slen(\"\") = %d", slen(""));
    cr_assert_eq(slen("98765"), 5, "slen(\"98765\") != 5, slen(\"98765\") = %d", slen("98765"));
}