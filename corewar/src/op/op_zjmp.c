/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** op_zjmp
*/

#include <stdlib.h>
#include "corewar.h"

int op_zjmp(vm_t *vm, process_t *proc)
{
    byte_t *op = NULL;
    int val = 0;

    ASSERT(vm && proc, ERROR);
    ASSERT(proc->carry == 1, ERROR);
    op = get_op(vm->mem, proc->pc);
    ASSERT(op, ERROR);
    val = read_ind(op + 1, IND_SIZE);
    free(op);
    proc->pc += val % IDX_MOD;
    return SUCCESS;
}
