/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for charset.c funcs
*/

#include <criterion/criterion.h>
#include "charset.h"

Test(ccharset, true_test)
{
    cr_assert(ccharset('1', "0123456789"));
    cr_assert(ccharset('a', "abcdefghijklmnopqrstuvwxyz"));
}

Test(ccharset, false_test)
{
    cr_assert_not(ccharset('a', "0123456789"));
    cr_assert_not(ccharset('1', "abcdefghijklmnopqrstuvwxyz"));
}

Test(scharset, true_test)
{
    char *s1 = "the stressed chef serves fresh desserts.";
    char *s2 = "she treasures the delicate scent of her secret valgrind.";

    cr_assert(scharset("Helloworld!", "Helowrd!"));
    cr_assert(scharset(s1, s2));
}

Test(scharset, false_test)
{
    cr_assert_not(scharset("Hello world!", "Helowrd"));
    cr_assert_not(scharset("Hello there. General Kenobi!", "Hlowrd! .GnKbi"));
}
