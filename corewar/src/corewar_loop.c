/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include <stdlib.h>
#include <stdio.h>
#include "corewar_info.h"
#include "corewar.h"
#include "mywar.h"
#include "champ.h"
#include "vm.h"
#include "pf.h"
#include "op.h"
#include "rules.h"
#include "champ_mem.h"

int add_champ_to_vm(vm_t *vm, corewar_champs_t *info)
{
    int i = 0;
    champ_t *champ = NULL;
    process_t *proc = NULL;

    champ = create_champ();
    ASSERT_ERR(set_champ_from_mem(champ, info->stream), ERROR);
    proc = create_process();
    ASSERT(proc, ERROR);
    proc->champid = info->prog_num + 1;
    proc->regs[0][REG_SIZE - 1] = info->prog_num + 1;
    proc->pc = info->load_addr;
    ASSERT_ERR(append_to_list(&vm->procs, proc), ERROR);
    for (i = 0; i < vm->champ_count; i++);
    vm->champs[i] = *champ;
    vm->champ_count++;
    free(champ);
    return SUCCESS;
}

int count_champs(corewar_champs_t *champ_info)
{
    corewar_champs_t *champ = NULL;
    int counter = 0;

    champ = champ_info;
    while (champ != NULL) {
        counter++;
        champ = champ->next;
    }
    return counter;
}

void add_champions(corewar_champs_t *champ_info, vm_t *vm)
{
    corewar_champs_t *curr = champ_info;

    for (int i = 0; curr; i++) {
        add_champ_to_vm(vm, curr);
        mput(vm->mem, curr->load_addr, vm->champs[i].code
        , vm->champs[i].header.prog_size);
        bput(vm->champ_mem, curr->load_addr, i + 1
        , vm->champs[i].header.prog_size);
        curr = curr->next;
    }
}

static int loop_corewar(vm_t *vm)
{
    while (vm->champ_alive_count > 1) {
        switch (loop_vm(vm)) {
            case SUCCESS: continue;
            case ERROR: return ERROR;
            case -1: break;
            default: return ERROR;
        }
        break;
    }
    ASSERT(vm->last_live != -1, ERROR);
    opf("The player %i(%s)has won.\n",
        vm->last_live, vm->champs[vm->last_live - 1].header.prog_name);
    return SUCCESS;
}

int start_corewar(corewar_info_t *info)
{
    corewar_champs_t *champ_info = NULL;
    vm_t *vm = NULL;
    int nchamps = 0;

    champ_info = info->champions;
    nchamps = count_champs(info->champions);
    vm = create_vm();
    vm->nbr_dump_cycle = info->dump;
    vm->champs = malloc(sizeof(champ_t) * nchamps);
    ASSERT(vm->champs, ERROR);
    add_champions(champ_info, vm);
    set_vm_champs(vm, vm->champs, nchamps);
    ASSERT_ERR(loop_corewar(vm), ERROR);
    destroy_vm(vm);
    return SUCCESS;
}
