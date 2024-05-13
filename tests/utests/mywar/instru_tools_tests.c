/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** Base tests for instru_tools.c funcs
*/

#include <criterion/criterion.h>
#include "instru.h"
#include "cbyte.h"

Test(instru_tools_tests, set_instru_from_mem_test)
{
    instru_t *instru = create_instru();
    byte_t data[5] = {ADD, 0x54, 0x02, 0x03, 0x04};

    cr_assert_not_null(instru);
    set_instru_from_mem(instru, data, 0);
    cr_assert_eq(instru->type, ADD);
    cr_assert_eq(instru->cbyte, data + 1);
    cr_assert_eq(instru->data, data + 2);
    free(instru);
}

Test(instru_tools_tests, set_instru_from_asm_test)
{
    instru_t *instru = create_instru();
    args_type_t types[3] = {T_DIR, T_IND, 0};
    int values[3] = {0xc49a, 0xb2, 0};
    int j = 0;
    byte_t expected[MAX_ARGS_NUMBER] = {2, 3, 0, 0};

    cr_assert_not_null(instru);
    set_instru_from_asm(instru, LD, types, values);
    cr_assert_eq(instru->type, LD);
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        if (i % 4 == 0 && i != 0) {
            j++;
        }
        cr_assert_eq(get_cbyte_val_at(instru->cbyte[j], i % 4),
            expected[i], "cbyte val at %d is %x", i,
            get_cbyte_val_at(instru->cbyte[j], i % 4));
    }
    cr_assert_eq(instru->data[0], 0x00, "data[0] = %x", instru->data[0]);
    cr_assert_eq(instru->data[1], 0x00, "data[1] = %x", instru->data[1]);
    cr_assert_eq(instru->data[2], 0xc4, "data[2] = %x", instru->data[2]);
    cr_assert_eq(instru->data[3], 0x9a, "data[3] = %x", instru->data[3]);
    cr_assert_eq(instru->data[4], 0x00, "data[4] = %x", instru->data[4]);
    cr_assert_eq(instru->data[5], 0xb2, "data[5] = %x", instru->data[5]);
    cr_assert_eq(instru->data[6], 0x00, "data[6] = %x", instru->data[6]);
    free(instru);
}
