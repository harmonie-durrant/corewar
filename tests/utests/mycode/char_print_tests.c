/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for chars
*/

#include <criterion/criterion.h>
#include "char.h"

Test(char_print_tests, is_printable_tests)
{
    cr_assert_eq(is_print(' '), true, "Expected true for ' ', got false");
    cr_assert_eq(is_print('a'), true, "Expected true for 'a', got false");
    cr_assert_eq(is_print('Z'), true, "Expected true for 'Z', got false");
    cr_assert_eq(is_print('0'), true, "Expected true for '0', got false");
    cr_assert_eq(is_print('!'), true, "Expected true for '!', got false");
    cr_assert_eq(is_print('~'), true, "Expected true for '~', got false");
    cr_assert_eq(is_print('\t'), false, "Expected false for '\t', got true");
}

Test(char_print_tests, is_blank_tests)
{
    cr_assert_eq(is_blank(' '), true, "Expected true for ' ', got false");
    cr_assert_eq(is_blank('\t'), true, "Expected true for '\t', got false");
    cr_assert_eq(is_blank('a'), false, "Expected false for 'a', got true");
    cr_assert_eq(is_blank('Z'), false, "Expected false for 'Z', got true");
    cr_assert_eq(is_blank('0'), false, "Expected false for '0', got true");
    cr_assert_eq(is_blank('!'), false, "Expected false for '!', got true");
    cr_assert_eq(is_blank('~'), false, "Expected false for '~', got true");
}

Test(char_print_tests, is_space_tests)
{
    cr_assert_eq(is_space(' '), true, "Expected true for ' ', got false");
    cr_assert_eq(is_space('\t'), true, "Expected true for '\t', got false");
    cr_assert_eq(is_space('\n'), true, "Expected true for '\n', got false");
    cr_assert_eq(is_space('a'), false, "Expected false for 'a', got true");
    cr_assert_eq(is_space('Z'), false, "Expected false for 'Z', got true");
    cr_assert_eq(is_space('0'), false, "Expected false for '0', got true");
    cr_assert_eq(is_space('!'), false, "Expected false for '!', got true");
}