/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** vm_factory
*/

#include <stdlib.h>
#include <stddef.h>
#include "champ.h"
#include "list.h"
#include "vm.h"
#include "process.h"
#include "rules.h"
#include "pf.h"

static int init_vm(vm_t *vm)
{
    ASSERT(vm, ERROR);
    vm->champs = NULL;
    vm->champs_alive = NULL;
    vm->champ_count = 0;
    vm->live_count = 0;
    vm->procs = NULL;
    vm->nbr_dump_cycle = 0;
    vm->cycle_to_die = CYCLE_TO_DIE;
    vm->cycle = 0;
    vm->total_cycle = 0;
    vm->champ_alive_count = 0;
    vm->last_live = -1;
    for (int i = 0; i < MEM_SIZE; i++) {
        vm->mem[i] = 0;
        vm->champ_mem[i] = 0;
    }
    return SUCCESS;
}

vm_t *create_vm(void)
{
    vm_t *vm = NULL;

    vm = malloc(sizeof(vm_t));
    ASSERT(vm, NULL);
    if (init_vm(vm) == ERROR) {
        free(vm);
        return NULL;
    }
    return vm;
}

int set_vm_champs(vm_t *vm, champ_t *champs, int nb_champs)
{
    int i = 0;

    if (vm == NULL || champs == NULL || nb_champs <= 0) {
        return ERROR;
    }
    vm->champs = champs;
    vm->champs_alive = malloc(sizeof(byte_t) * nb_champs);
    ASSERT(vm->champs_alive, ERROR);
    for (; i < nb_champs; i++) {
        vm->champs_alive[i] = 0;
    }
    vm->champ_alive_count = nb_champs;
    return SUCCESS;
}

void destroy_vm(vm_t *vm)
{
    ASSERT(vm,);
    if (vm->champs) {
        for (int i = 0; i < vm->champ_count; i++) {
            destroy_champ(vm->champs + i);
        }
        free(vm->champs);
    }
    if (vm->champs_alive) {
        free(vm->champs_alive);
    }
    free(vm);
}

void dump_vm(vm_t *vm)
{
    int i = 0;
    char hexa[3] = "00\0";
    const char hexachars[] = "0123456789ABCDEF";

    ASSERT(vm,);
    for (; i < MEM_SIZE; i++) {
        if (i % 32 == 0 && i != 0) {
            opf("\n");
        }
        hexa[0] = hexachars[vm->mem[i] / 16];
        hexa[1] = hexachars[vm->mem[i] % 16];
        opf("%s", hexa);
    }
    opf("\n");
}
