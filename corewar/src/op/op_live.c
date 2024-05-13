/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** Live operation
*/

#include <stdlib.h>
#include "corewar.h"
#include "rules.h"
#include "base.h"
#include "champ.h"

int op_live(vm_t *vm, process_t *proc)
{
    byte_t *op = NULL;
    int value = 0;

    ASSERT(vm && proc, ERROR);
    op = get_op(vm->mem, proc->pc);
    ASSERT(op, ERROR);
    value = read_val(op + 1, DIR_SIZE);
    free(op);
    ASSERT(IS_BETWEEN(value, 1, vm->champ_count), ERROR);
    ASSERT(vm->champs_alive[value - 1] != -1, ERROR);
    vm->last_live = value;
    proc->live = 1;
    return value;
}
