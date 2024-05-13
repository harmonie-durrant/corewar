/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for type length
*/

#include <criterion/criterion.h>
#include <stdbool.h>
#include "str.h"

Test(ssearch_tests, sexact_tests)
{
    char *str = "Coucou Bananas";
    char *str2 = "Coucou";
    char *str3 = "Coucous";
    char *str4 = "Coucou";

    cr_assert_eq(sexact(str, str2), false);
    cr_assert_eq(sexact(str2, str3), false);
    cr_assert_eq(sexact(str3, str4), false);
    cr_assert_eq(sexact(str2, str4), true);
}

Test(ssearch_tests, sequal_tests)
{
    char *str = "Coucou Bananas";
    char *str2 = "Coucou";

    cr_assert_eq(sequal(str, str2), 1, "sequal(\"Coucou Bananas\", \"Coucou\") != 1, got %d", sequal(str, str2));
}

Test(ssearch_tests, sfind_tests)
{
    char *str = "Coucou Bananas";
    char *str2 = "Bananas";

    cr_assert_eq(sfind(str, str2), 7 + 1, "sfind(\"Coucou Bananas\", \"Bananas\") != 7 + 1, got %d", sfind(str, str2));
}

Test(ssearch_tests, sfindc_tests)
{
    char *str = "Coucou Bananas";

    cr_assert_eq(sfindc(str, 'B'), 7 + 1, "sfindc(\"Coucou Bananas\", 'B') != 7 + 1, got %d", sfindc(str, 'B'));
}

Test(ssearch_tests, scount_tests)
{
    char *str = "Coucou Bananas";

    cr_assert_eq(scount(str, "a"), 3, "scount(\"Coucou Bananas\", 'a') != 3, got %d", scount(str, "a"));
    cr_assert_eq(scount(str, "ou"), 2, "scount(\"Coucou Bananas\", 'ou') != 2, got %d", scount(str, "ou"));
    cr_assert_eq(scount(str, "Bananas"), 1, "scount(\"Coucou Bananas\", 'Bananas') != 1, got %d", scount(str, "Bananas"));
}