/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for chars
*/

#include <criterion/criterion.h>
#include "char.h"

Test(char_anum_tests, is_num_tests)
{
    cr_assert_eq(is_num('0'), true, "Expected true for '0', got false");
    cr_assert_eq(is_num('5'), true, "Expected true for '5', got false");
    cr_assert_eq(is_num('9'), true, "Expected true for '9', got false");
    cr_assert_eq(is_num('a'), false, "Expected false for 'a', got true");
    cr_assert_eq(is_num('Z'), false, "Expected false for 'Z', got true");
    cr_assert_eq(is_num(' '), false, "Expected false for ' ', got true");
    cr_assert_eq(is_num(0), false, "Expected false for 0, got true");
}

Test(char_anum_tests, is_upper_tests)
{
    cr_assert_eq(is_upper('A'), true, "Expected true for 'A', got false");
    cr_assert_eq(is_upper('Z'), true, "Expected true for 'Z', got false");
    cr_assert_eq(is_upper('a'), false, "Expected false for 'a', got true");
    cr_assert_eq(is_upper('z'), false, "Expected false for 'z', got true");
    cr_assert_eq(is_upper(' '), false, "Expected false for ' ', got true");
    cr_assert_eq(is_upper(0), false, "Expected false for 0, got true");
}

Test(char_anum_tests, is_lower_tests)
{
    cr_assert_eq(is_lower('a'), true, "Expected true for 'a', got false");
    cr_assert_eq(is_lower('z'), true, "Expected true for 'z', got false");
    cr_assert_eq(is_lower('A'), false, "Expected false for 'A', got true");
    cr_assert_eq(is_lower('Z'), false, "Expected false for 'Z', got true");
    cr_assert_eq(is_lower(' '), false, "Expected false for ' ', got true");
    cr_assert_eq(is_lower(0), false, "Expected false for 0, got true");
}

Test(char_anum_tests, is_alpha_tests)
{
    cr_assert_eq(is_alpha('a'), true, "Expected true for 'a', got false");
    cr_assert_eq(is_alpha('z'), true, "Expected true for 'z', got false");
    cr_assert_eq(is_alpha('A'), true, "Expected true for 'A', got false");
    cr_assert_eq(is_alpha('Z'), true, "Expected true for 'Z', got false");
    cr_assert_eq(is_alpha(' '), false, "Expected false for ' ', got true");
    cr_assert_eq(is_alpha(0), false, "Expected false for 0, got true");
}

Test(char_anum_tests, is_alphanum_tests)
{
    cr_assert_eq(is_alphanum('a'), true, "Expected true for 'a', got false");
    cr_assert_eq(is_alphanum('z'), true, "Expected true for 'z', got false");
    cr_assert_eq(is_alphanum('A'), true, "Expected true for 'A', got false");
    cr_assert_eq(is_alphanum('Z'), true, "Expected true for 'Z', got false");
    cr_assert_eq(is_alphanum('0'), true, "Expected true for '0', got false");
    cr_assert_eq(is_alphanum('5'), true, "Expected true for '5', got false");
    cr_assert_eq(is_alphanum('9'), true, "Expected true for '9', got false");
    cr_assert_eq(is_alphanum(' '), false, "Expected false for ' ', got true");
    cr_assert_eq(is_alphanum(0), false, "Expected false for 0, got true");
}
