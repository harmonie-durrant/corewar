/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** File for the process' loop
*/

#include <stdlib.h>
#include "instru.h"
#include "process.h"
#include "vm.h"
#include "rules.h"
#include "base.h"
#include "ops.h"
#include "pf.h"
#include "list.h"
#include "talloc.h"
#include "base.h"
#include "champ.h"

static const op_func_t funcs[16] = {
    &op_live,
    &op_ld,
    &op_st,
    &op_add,
    &op_sub,
    &op_and,
    &op_or,
    &op_xor,
    &op_zjmp,
    &op_ldi,
    &op_sti,
    &op_fork,
    &op_lld,
    &op_lldi,
    &op_lfork,
    &op_aff
};

void read_op(byte_t *mem, process_t *process)
{
    ASSERT(mem && process,);
    ASSERT(IS_BETWEEN(mem[process->pc], LIVE, AFF),);
    process->wait = op_tab[mem[process->pc] - 1].nbr_cycles;
}

int exec_op(vm_t *vm, process_t *process)
{
    int ret = 0;
    instru_type_t itype = 0;
    byte_t *cb = NULL;

    ASSERT(vm && process, ERROR);
    process->wait = -1;
    itype = vm->mem[process->pc];
    ASSERT(IS_BETWEEN(itype, LIVE, AFF), ERROR);
    ret = funcs[itype - 1](vm, process);
    if (ret == ERROR && itype != ZJMP) {
        process->wait = 0;
    }
    if (itype == ZJMP && ret == 0) {
        return ret;
    }
    cb = &vm->mem[(process->pc + 1) % MEM_SIZE];
    process->pc = (process->pc + get_mem_size(itype, cb)) % MEM_SIZE;
    return ret;
}

int loop_process(vm_t *vm, process_t *process)
{
    ASSERT(process, ERROR);
    switch (process->wait) {
        case -1:
            read_op(vm->mem, process);
            ASSERT(process->wait != -1, ERROR);
            break;
        case 0: return exec_op(vm, process); break;
        default: process->wait--; break;
    }
    return SUCCESS;
}

int loop_one_proc(vm_t *vm, list_t *tmp, list_t **live_nb)
{
    int ret = 0;
    int *new_ret = NULL;

    ASSERT(vm && tmp && live_nb, ERROR);
    ret = loop_process(vm, tmp->data);
    ASSERT_ERR(ret, ERROR);
    ASSERT(ret, SUCCESS);
    opf("The player %i(%s)is alive.\n",
        ret, vm->champs[ret - 1].header.prog_name);
    new_ret = int_alloc(ret);
    ASSERT(new_ret, ERROR);
    if (prepend_to_list(live_nb, new_ret) == ERROR) {
        free(new_ret);
        return ERROR;
    }
    if (++(vm->live_count) >= NBR_LIVE) {
        vm->live_count = 0;
        vm->cycle_to_die -= CYCLE_DELTA;
    }
    return SUCCESS;
}
