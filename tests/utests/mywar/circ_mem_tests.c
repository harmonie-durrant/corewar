/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** Source file for the circular memory
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <string.h>
#include "byte.h"
#include "op.h"
#include "rules.h"
#include "mywar.h"

Test(circ_mem_tests, simple_mget_test)
{
    byte_t *mem = malloc(sizeof(byte_t) * MEM_SIZE);
    byte_t *data = NULL;

    cr_assert_not_null(mem);
    memset(mem, 0, MEM_SIZE);
    mem[0] = 1;
    mem[1] = 2;
    mem[2] = 3;
    data = mget(mem, 0, 3);
    cr_assert_not_null(data);
    cr_assert_eq(data[0], 1, "data[0] = %d", data[0]);
    cr_assert_eq(data[1], 2, "data[1] = %d", data[1]);
    cr_assert_eq(data[2], 3, "data[2] = %d", data[2]);
    free(data);
    free(mem);
}

Test(circ_mem_tests, simple_mput_test)
{
    byte_t *mem = malloc(sizeof(byte_t) * MEM_SIZE);
    byte_t *data = malloc(sizeof(byte_t) * 3);

    cr_assert_not_null(mem);
    cr_assert_not_null(data);
    memset(mem, 0, MEM_SIZE);
    memset(data, 0, 3);
    data[0] = 1;
    data[1] = 2;
    data[2] = 3;
    mput(mem, 0, data, 3);
    cr_assert_eq(mem[0], 1);
    cr_assert_eq(mem[1], 2);
    cr_assert_eq(mem[2], 3);
    free(data);
    free(mem);
}