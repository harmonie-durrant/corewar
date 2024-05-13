/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** and or & xor op
*/

#include <stdlib.h>
#include "corewar.h"
#include "instru.h"
#include "cbyte.h"
#include "mywar.h"

static int set_vals(vm_t *vm, process_t *proc, int *vals, int *types)
{
    byte_t *buf = NULL;

    for (size_t i = 0; i < 2; i++) {
        if (types[i] & T_IND) {
            buf = mget(vm->mem, proc->pc + vals[i], REG_SIZE);
            ASSERT(buf, ERROR);
            vals[i] = read_val(buf, REG_SIZE);
            free(buf);
        }
        if (types[i] & T_REG) {
            ASSERT_REG(vals[i]);
            vals[i] = read_reg(proc, vals[i]);
        }
    }
    return SUCCESS;
}

static int set_args(byte_t *op, int *vals, int *types, int *reg)
{
    size_t size = 0;
    byte_t *op_ptr = op;

    types[0] = get_cbyte_val_at(op[1], 0);
    size = get_arg_size(op[0], types[0], 0);
    vals[0] = read_val(op_ptr, size);
    op_ptr += size;
    types[1] = get_cbyte_val_at(op[1], 1);
    size = get_arg_size(op[0], types[1], 1);
    vals[1] = read_val(op_ptr, size);
    op_ptr += size;
    *reg = read_val(op_ptr, 1);
    free(op);
    ASSERT_REG(*reg);
    return SUCCESS;
}

int op_and(vm_t *vm, process_t *proc)
{
    byte_t *op = NULL;
    int values[2] = {0};
    int types[2] = {0};
    int reg = 0;

    ASSERT(vm && proc, ERROR);
    op = get_op(vm->mem, proc->pc);
    ASSERT(op, ERROR);
    ASSERT_ERR(set_args(op, values, types, &reg), ERROR);
    ASSERT_ERR(set_vals(vm, proc, values, types), ERROR);
    write_reg(proc, reg, values[0] & values[1]);
    proc->carry = (values[0] & values[1]) == 0;
    return SUCCESS;
}

int op_or(vm_t *vm, process_t *proc)
{
    byte_t *op = NULL;
    int values[2] = {0};
    int types[2] = {0};
    int reg = 0;

    ASSERT(vm && proc, ERROR);
    op = get_op(vm->mem, proc->pc);
    ASSERT(op, ERROR);
    ASSERT_ERR(set_args(op, values, types, &reg), ERROR);
    ASSERT_ERR(set_vals(vm, proc, values, types), ERROR);
    write_reg(proc, reg, values[0] | values[1]);
    proc->carry = (values[0] | values[1]) == 0;
    return SUCCESS;
}

int op_xor(vm_t *vm, process_t *proc)
{
    byte_t *op = NULL;
    int values[2] = {0};
    int types[2] = {0};
    int reg = 0;

    ASSERT(vm && proc, ERROR);
    op = get_op(vm->mem, proc->pc);
    ASSERT(op, ERROR);
    ASSERT_ERR(set_args(op, values, types, &reg), ERROR);
    ASSERT_ERR(set_vals(vm, proc, values, types), ERROR);
    write_reg(proc, reg, values[0] ^ values[1]);
    proc->carry = (values[0] ^ values[1]) == 0;
    return SUCCESS;
}
