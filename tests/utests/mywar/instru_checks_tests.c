/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** Base tests for cbyte_factory.c funcs
*/
 
#include <criterion/criterion.h>
#include "instru.h"

Test(instru_checks_tests, valid_args_test)
{
    const args_type_t types[4] = {T_REG, T_REG, T_REG, 0};

    cr_assert_eq(args_are_valid(ADD, types), 1);
    cr_assert_eq(args_are_valid(LIVE, types), 0);
}

Test(instru_checks_tests, valid_mem_test)
{
    const byte_t cbyte[4] = {0x54, 0x00, 0x00, 0x00};

    cr_assert_eq(mem_is_valid(cbyte, ADD), 1);
    cr_assert_eq(mem_is_valid(cbyte, LLD), 0);
}
