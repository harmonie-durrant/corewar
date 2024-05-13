/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** Test file for op_tools
*/

#include <criterion/criterion.h>
#include "process.h"
#include "instru.h"
#include "corewar.h"

Test(op_tools_tests, reg_test1)
{
    process_t *process = create_process();

    write_reg(process, 1, 42);
    cr_assert_eq(read_reg(process, 1), 42);
}

Test(op_tools_tests, reg_test2)
{
    process_t *process = create_process();

    write_reg(process, 1, 0);
    cr_assert_eq(read_reg(process, 1), 0);
}

Test(op_tools_tests, reg_test3)
{
    process_t *process = create_process();

    write_reg(process, 1, 0x12345678);
    cr_assert_eq(read_reg(process, 1), 0x12345678);
}

Test(op_tools_tests, get_op_test)
{
    byte_t mem[5] = {ADD, 0x54, 0x01, 0x02, 0x03};
    byte_t *gen = get_op(mem, 0);

    cr_assert_not_null(gen);
    for (int i = 0; i < 5; i++) {
        cr_assert_eq(gen[i], mem[i]);
    }
}