/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** champ_mem_tests
*/

#include <criterion/criterion.h>
#include "champ_mem.h"

Test(bput, simple)
{
    byte_t mem[MEM_SIZE] = {0};

    bput(mem, 0, 1, 2);
    cr_assert_eq(mem[0], 1);
    cr_assert_eq(mem[1], 1);
    cr_assert_eq(mem[2], 0);
}

Test(bput, advanced)
{
    byte_t mem[MEM_SIZE] = {0};

    bput(mem, 0, 3, 27);
    bput(mem, 7, 1, 15);
    for (int i = 0; i < 7; i++)
        cr_assert_eq(mem[i], 3);
    for (int i = 7; i < 22; i++)
        cr_assert_eq(mem[i], 1);
    for (int i = 22; i < 27; i++)
        cr_assert_eq(mem[i], 3);
    cr_assert_eq(mem[27], 0);
}

Test(bput, circular)
{
    byte_t mem[MEM_SIZE] = {0};

    bput(mem, MEM_SIZE / 2, 1, (MEM_SIZE / 2) + 100);
    for (int i = 0; i < 100; i++)
        cr_assert_eq(mem[i], 1);
    for (int i = 100; i < MEM_SIZE / 2; i++)
        cr_assert_eq(mem[i], 0);
    for (int i = MEM_SIZE / 2; i < MEM_SIZE; i++)
        cr_assert_eq(mem[i], 1);
}
