/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** fork & lfork
*/

#include <stdlib.h>
#include "corewar.h"

int op_fork(vm_t *vm, process_t *proc)
{
    process_t *new_proc = NULL;
    byte_t *op = NULL;
    int value = 0;

    ASSERT(vm && proc, ERROR);
    op = get_op(vm->mem, proc->pc);
    ASSERT(op, ERROR);
    value = read_val(op + 1, IND_SIZE);
    free(op);
    proc = duplicate_process(proc, value % IDX_MOD);
    ASSERT(proc, ERROR);
    if (append_to_list(&(vm->procs), proc) == ERROR) {
        destroy_process(&new_proc);
        return ERROR;
    }
    return SUCCESS;
}

int op_lfork(vm_t *vm, process_t *proc)
{
    process_t *new_proc = NULL;
    byte_t *op = NULL;
    int value = 0;

    ASSERT(vm && proc, ERROR);
    op = get_op(vm->mem, proc->pc);
    ASSERT(op, ERROR);
    value = read_val(op + 1, IND_SIZE);
    free(op);
    proc = duplicate_process(proc, value);
    ASSERT(proc, ERROR);
    if (append_to_list(&(vm->procs), proc) == ERROR) {
        destroy_process(&new_proc);
        return ERROR;
    }
    return SUCCESS;
}
