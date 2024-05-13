/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for type allocation
*/

#include <criterion/criterion.h>
#include "read.h"

Test(read_tests, stoui_tests)
{
    cr_assert_eq(stoui("123"), 123, "stoui(\"123\") != 123, stoui(\"123\") = %d", stoui("123"));
    cr_assert_eq(stoui("0"), 0, "stoui(\"0\") != 0, stoui(\"0\") = %d", stoui("0"));
    cr_assert_eq(stoui("98765"), 98765, "stoui(\"98765\") != 98765, stoui(\"98765\") = %d", stoui("98765"));
    cr_assert_eq(stoui("-1"), 0, "stoui(\"-1\") != 0, stoui(\"-1\") = %d", stoui("-1"));
    cr_assert_eq(stoui("a"), 0, "stoui(\"a\") != 0, stoui(\"a\") = %d", stoui("a"));
}

Test(read_tests, stoi_tests)
{
    cr_assert_eq(stoi("123"), 123, "stoi(\"123\") != 123, stoi(\"123\") = %d", stoi("123"));
    cr_assert_eq(stoi("0"), 0, "stoi(\"0\") != 0, stoi(\"0\") = %d", stoi("0"));
    cr_assert_eq(stoi("98765"), 98765, "stoi(\"98765\") != 98765, stoi(\"98765\") = %d", stoi("98765"));
    cr_assert_eq(stoi("-1"), -1, "stoi(\"-1\") != -1, stoi(\"-1\") = %d", stoi("-1"));
    cr_assert_eq(stoi("a"), 0, "stoi(\"a\") != 0, stoi(\"a\") = %d", stoi("a"));
}
