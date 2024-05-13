/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** op_add & op_sub
*/

#include <stdlib.h>
#include "corewar.h"
#include "rules.h"

int op_add(vm_t *vm, process_t *proc)
{
    byte_t *op = NULL;
    int reg1 = 0;
    int reg2 = 0;
    int val1 = 0;
    int val2 = 0;

    ASSERT(vm && proc, ERROR);
    op = get_op(vm->mem, proc->pc);
    ASSERT(op, ERROR);
    reg1 = read_val(op + 2, 1);
    ASSERT_REG(reg1);
    reg2 = read_val(op + 3, 1);
    ASSERT_REG(reg2);
    val1 = read_reg(proc, reg1);
    val2 = read_reg(proc, reg2);
    write_reg(proc, read_val(op + 4, 1), val1 + val2);
    proc->carry = val1 + val2 == 0 ? 1 : 0;
    free(op);
    return SUCCESS;
}

int op_sub(vm_t *vm, process_t *proc)
{
    byte_t *op = NULL;
    int reg1 = 0;
    int reg2 = 0;
    int val1 = 0;
    int val2 = 0;

    ASSERT(vm && proc, ERROR);
    op = get_op(vm->mem, proc->pc);
    ASSERT(op, ERROR);
    reg1 = read_val(op + 2, 1);
    ASSERT_REG(reg1);
    reg2 = read_val(op + 3, 1);
    ASSERT_REG(reg2);
    val1 = read_reg(proc, reg1);
    val2 = read_reg(proc, reg2);
    write_reg(proc, read_val(op + 4, 1), val1 - val2);
    proc->carry = val1 - val2 == 0 ? 1 : 0;
    free(op);
    return SUCCESS;
}
