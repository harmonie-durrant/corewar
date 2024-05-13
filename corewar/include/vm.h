/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** vm
*/

#ifndef VM_H_
    #define VM_H_
    #include "process.h"
    #include "byte.h"
    #include "op.h"
    #include "list.h"

    typedef struct champ_s champ_t;

    typedef struct vm_s {
        champ_t *champs;
        int8_t *champs_alive;
        byte_t champ_count;
        byte_t mem[MEM_SIZE];
        byte_t champ_mem[MEM_SIZE];
        list_t *procs;
        int live_count;
        int nbr_dump_cycle;
        int cycle_to_die;
        int cycle;
        int total_cycle;
        int champ_alive_count;
        int last_live;
    } vm_t;

    typedef int (*op_func_t)(vm_t *, process_t *);
vm_t *create_vm(void);
void destroy_vm(vm_t *vm);
void dump_vm(vm_t *vm);

int loop_vm(vm_t *vm);
int loop_process(vm_t *vm, process_t *process);
int loop_one_proc(vm_t *vm, list_t *tmp, list_t **live_nb);
int set_vm_champs(vm_t *vm, champ_t *champs, int nb_champs);

#endif /* !VM_H_ */
