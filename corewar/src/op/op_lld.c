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

static size_t rlload(vm_t *vm, byte_t *op, int *value, args_type_t arg)
{
    byte_t *loaded = NULL;

    if (arg & T_DIR) {
        *value = read_val(op, DIR_SIZE);
        return DIR_SIZE;
    } else {
        *value += read_val(op, IND_SIZE);
        loaded = mget(vm->mem, *value, REG_SIZE);
        ASSERT(loaded, 0);
        *value = read_val(loaded, REG_SIZE);
        free(loaded);
        return IND_SIZE;
    }
}

static int internal_op_lld(vm_t *vm, process_t *proc, byte_t *op, int *value)
{
    size_t size = 2;

    value[0] = proc->pc;
    size += rlload(vm, op + size, value, get_cbyte_val_at(op[1], 0));
    ASSERT(size > 2, ERROR);
    value[1] = read_val(op + size, 1);
    ASSERT_REG(value[1]);
    value[1] = read_reg(proc, value[1]);
    write_reg(proc, value[1], value[0]);
    return value[1] == 0;
}

int op_lld(vm_t *vm, process_t *proc)
{
    byte_t *op = NULL;
    int value[2] = {0};

    ASSERT(vm && proc, ERROR);
    op = get_op(vm->mem, proc->pc);
    ASSERT(op, ERROR);
    proc->carry = internal_op_lld(vm, proc, op, value);
    free(op);
    return SUCCESS;
}
