/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** op_aff
*/

#include <unistd.h>
#include <stdlib.h>
#include "corewar.h"

int op_aff(vm_t *vm, process_t *proc)
{
    byte_t *op = NULL;
    byte_t reg = 0;
    int val = 0;

    ASSERT(vm && proc, ERROR);
    op = get_op(vm->mem, proc->pc);
    ASSERT(op, ERROR);
    reg = read_val(op + 2, 1);
    free(op);
    ASSERT_REG(reg);
    val = read_reg(proc, reg);
    val %= 256;
    write(1, &val, 1);
    return SUCCESS;
}
