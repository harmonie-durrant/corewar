/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** St & sti operation
*/

#include <stdlib.h>
#include "corewar.h"
#include "cbyte.h"
#include "rules.h"
#include "base.h"
#include "mywar.h"
#include "champ_mem.h"

static int internal_op_st(vm_t *vm, process_t *proc, byte_t *op, int *value)
{
    if (T_REG & get_cbyte_val_at(op[1], 1)) {
        value[1] = read_val(op + 3, 1);
        ASSERT_REG(value[1]);
        write_reg(proc, value[1], read_reg(proc, value[0]));
    } else {
        value[1] = read_val(op + 3, IND_SIZE);
        value[1] = (proc->pc + value[1] % IDX_MOD);
        mput(vm->mem, value[1], proc->regs[value[0] - 1], REG_SIZE);
        bput(vm->champ_mem, value[1], proc->champid, REG_SIZE);
    }
    return SUCCESS;
}

int op_st(vm_t *vm, process_t *proc)
{
    byte_t *op = NULL;
    int value[2] = {0};

    ASSERT(vm && proc, ERROR);
    op = get_op(vm->mem, proc->pc);
    ASSERT(op, ERROR);
    value[0] = read_val(op + 2, 1);
    ASSERT_REG(value[0]);
    ASSERT_ERR(internal_op_st(vm, proc, op, value), ERROR);
    free(op);
    return SUCCESS;
}

static int internal_op_sti(process_t *proc, byte_t *op, int *value)
{
    size_t size = 1;

    if (T_REG & get_cbyte_val_at(op[size++], 1)) {
        value[1] = read_val(op + ++size, 1);
        ASSERT_REG(value[1]);
        value[1] = read_reg(proc, value[1]);
    } else {
        value[1] = read_val(op + 3, IND_SIZE);
        size += IND_SIZE + 1;
    }
    if (T_REG & get_cbyte_val_at(op[1], 2)) {
        value[2] = read_val(op + size, 1);
        ASSERT_REG(value[2]);
        value[2] = read_reg(proc, value[2]);
    } else {
        value[2] = read_val(op + size, IND_SIZE);
    }
    return SUCCESS;
}

int op_sti(vm_t *vm, process_t *proc)
{
    byte_t *op = NULL;
    int value[3] = {0};

    ASSERT(vm && proc, ERROR);
    op = get_op(vm->mem, proc->pc);
    ASSERT(op, ERROR);
    value[0] = read_val(op + 2, 1);
    ASSERT_REG(value[0]);
    ASSERT_ERR(internal_op_sti(proc, op, value), ERROR);
    mput(vm->mem, (proc->pc + (value[1] + value[2]) % IDX_MOD),
        proc->regs[value[0] - 1], REG_SIZE);
    bput(vm->champ_mem, (proc->pc + (value[1] + value[2]) % IDX_MOD),
        proc->champid, REG_SIZE);
    free(op);
    return SUCCESS;
}
