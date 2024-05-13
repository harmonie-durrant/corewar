/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for type length
*/

#include <criterion/criterion.h>
#include "len.h"
#include "rules.h"

Test(len_tests, uilen_tests)
{
    cr_assert_eq(uilen(123), 3, "uilen(123) != 3, uilen(123) = %d", uilen(123));
    cr_assert_eq(uilen(0), 1, "uilen(0) != 1, uilen(0) = %d", uilen(0));
    cr_assert_eq(uilen(98765), 5, "uilen(98765) != 5, uilen(98765) = %d", uilen(98765));
}

Test(len_tests, ilen_tests)
{
    cr_assert_eq(ilen(-123), 4, "ilen(-123) != 4, ilen(-123) = %d", ilen(-123));
    cr_assert_eq(ilen(0), 1, "ilen(0) != 1, ilen(0) = %d", ilen(0));
    cr_assert_eq(ilen(98765), 5, "ilen(98765) != 5, ilen(98765) = %d", ilen(98765));
    cr_assert_eq(ilen(-1), 2, "ilen(-1) != 2, ilen(-1) = %d", ilen(-1));
}

Test(len_tests, flen_tests)
{
    cr_assert_eq(flen(-1.23), 3 + DEC_DIG, "flen(-1.23) != 5, flen(-1.23) = %d", flen(-1.23));
    cr_assert_eq(flen(0), 2 + DEC_DIG, "flen(0) != 1, flen(0) = %d", flen(0));
    cr_assert_eq(flen(98.765), 3 + DEC_DIG, "flen(98.765) != 6, flen(98.765) = %d", flen(98.765));
    cr_assert_eq(flen(-1), 3 + DEC_DIG, "flen(-1) != 2, flen(-1) = %d", flen(-1));
}

Test(len_tests, dlen_tests)
{
    cr_assert_eq(dlen(-1.23), 3 + DEC_DIG, "flen(-1.23) != 7, flen(-1.23) = %d", dlen(-1.23));
    cr_assert_eq(dlen(0), 2 + DEC_DIG, "flen(0) != 6, flen(0) = %d", dlen(0));
    cr_assert_eq(dlen(98.765), 3 + DEC_DIG, "flen(98.765) != 7, flen(98.765) = %d", dlen(98.765));
    cr_assert_eq(dlen(-0.005), 3 + DEC_DIG, "flen(-0.005) != 7, flen(-0.005) = %d", dlen(-0.005));
    cr_assert_eq(dlen(-1), 3 + DEC_DIG, "flen(-1) != 7, flen(-1) = %d", dlen(-1));
    cr_assert_eq(dlen(-1.05), 3 + DEC_DIG, "flen(-0.05) != 7, flen(-1.05) = %d", dlen(-0.05));
    cr_assert_eq(dlen(-12.05), 4 + DEC_DIG, "flen(-0.05) != 8, flen(-12.05) = %d", dlen(-0.05));
    cr_assert_eq(dlen(-0.05), 3 + DEC_DIG, "flen(-0.05) != 7, flen(-0.05) = %d", dlen(-0.05));
}