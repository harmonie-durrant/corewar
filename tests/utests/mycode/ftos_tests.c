/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for ftos
*/

#include <criterion/criterion.h>
#include "str.h"

Test(ftos_tests, ftos)
{
    cr_assert_eq(ftos(-1), NULL);
}