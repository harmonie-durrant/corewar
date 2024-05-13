/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** Base tests for cbyte_factory.c funcs
*/

#include <criterion/criterion.h>
#include "cbyte.h"

Test(cbyte_tests, make_cbyte_test)
{
    args_type_t types[MAX_ARGS_NUMBER] = {T_REG, T_DIR, T_IND, T_LAB};
    byte_t *cbyte = make_cbyte(types);
    byte_t expected[MAX_ARGS_NUMBER] = {1, 2, 3, 3};
    int j = 0;

    cr_assert_not_null(cbyte);
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        if (i % 4 == 0 && i != 0) {
            j++;
        }
        cr_assert_eq(get_cbyte_val_at(cbyte[j], i % 4), expected[i]);
    }
}