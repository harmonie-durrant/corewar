/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** File for the vm loop
*/

#include <stdlib.h>
#include "list.h"
#include "instru.h"
#include "process.h"
#include "vm.h"
#include "talloc.h"
#include "rules.h"
#include "base.h"
#include "champ.h"
#include "pf.h"

static int set_champ_live_state(vm_t *vm, list_t **idx_list)
{
    int idx = 0;
    list_t *tmp = NULL;

    tmp = *idx_list;
    for (; tmp; tmp = tmp->next) {
        idx = *(int *)tmp->data;
        if (idx < 1 || idx > vm->champ_count) {
            return ERROR;
        }
        if (vm->champs_alive[idx - 1] == -1) {
            continue;
        }
        vm->champs_alive[idx - 1] = 1;
    }
    destroy_list(idx_list, free);
    return SUCCESS;
}

static void reset_vm_cycle(vm_t *vm)
{
    vm->total_cycle += vm->cycle;
    vm->cycle = 0;
    for (int i = 0; i < vm->champ_count; i++) {
        if (vm->champs_alive[i] == 0) {
            vm->champs_alive[i] = -1;
            vm->champ_alive_count--;
        }
        if (vm->champs_alive[i] > 0) {
            vm->champs_alive[i] = 0;
        }
    }
}

void handle_loop_one_proc(vm_t *vm, list_t **tmp, list_t **live_nb)
{
    ASSERT(tmp && *tmp && (*tmp)->data,);
    loop_one_proc(vm, *tmp, live_nb);
}

int loop_vm(vm_t *vm)
{
    list_t *tmp = NULL;
    list_t *live_nb = NULL;

    ASSERT(vm && vm->procs && vm->champ_alive_count > 1, ERROR);
    for (tmp = vm->procs; tmp; tmp = tmp->next) {
        handle_loop_one_proc(vm, &tmp, &live_nb);
        ASSERT(tmp, -1);
    }
    ASSERT_ERR(set_champ_live_state(vm, &live_nb), ERROR);
    if (++(vm->cycle) >= vm->cycle_to_die) {
        reset_vm_cycle(vm);
    }
    if ((vm->cycle + vm->total_cycle) >= vm->nbr_dump_cycle
        && vm->nbr_dump_cycle != -1) {
        dump_vm(vm);
        return -1;
    }
    return SUCCESS;
}
