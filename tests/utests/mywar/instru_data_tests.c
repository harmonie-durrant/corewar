/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** Base tests for hexa data
*/

#include <criterion/criterion.h>
#include "instru.h"

Test(make_instru_data_tests, valid_data)
{
    args_type_t types[3] = {T_DIR, T_IND, 0};
    int values[3] = {0xc49a, 0xb2, 0};
    byte_t *data = make_instru_data(ST, types, values);

    cr_assert_not_null(data);
    cr_assert_eq(data[0], 0x00, "data[0] = %x", data[0]);
    cr_assert_eq(data[1], 0x00, "data[1] = %x", data[1]);
    cr_assert_eq(data[2], 0xc4, "data[2] = %x", data[2]);
    cr_assert_eq(data[3], 0x9a, "data[3] = %x", data[3]);
    cr_assert_eq(data[4], 0x00, "data[4] = %x", data[4]);
    cr_assert_eq(data[5], 0xb2, "data[5] = %x", data[5]);
    cr_assert_eq(data[6], 0x00, "data[6] = %x", data[6]);
    free(data);
}

Test(make_instru_data_tests, invalid_data)
{
    args_type_t types[2] = {T_IND, 0};
    int values[2] = {0xf1b2c49a, 0};
    byte_t *data = make_instru_data(LIVE, types, values);

    cr_assert_null(data);
}

Test(instru_data_tests, memsize_test)
{
    byte_t cb = 0x54;
    int size = get_mem_size(ADD, &cb);

    cr_assert_eq(size, 5, "size = %d", size);
    cb = 0x94;
    size = get_mem_size(LFORK, &cb);
    cr_assert_eq(size, 3, "size = %d", size);
    cb = 0x64;
    size = get_mem_size(ZJMP, &cb);
    cr_assert_eq(size, 3, "size = %d", size);
    cb = 0x74;
    size = get_mem_size(LDI, &cb);
    cr_assert_eq(size, 6, "size = %d", size);
}