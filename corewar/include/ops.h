/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** ops
*/

#ifndef OPS_H_
    #define OPS_H_
    #include "corewar.h"

int op_live(vm_t *vm, process_t *proc);
int op_ld(vm_t *vm, process_t *proc);
int op_st(vm_t *vm, process_t *proc);
int op_add(vm_t *vm, process_t *proc);
int op_sub(vm_t *vm, process_t *proc);
int op_and(vm_t *vm, process_t *proc);
int op_or(vm_t *vm, process_t *proc);
int op_xor(vm_t *vm, process_t *proc);
int op_zjmp(vm_t *vm, process_t *proc);
int op_ldi(vm_t *vm, process_t *proc);
int op_sti(vm_t *vm, process_t *proc);
int op_fork(vm_t *vm, process_t *proc);
int op_lld(vm_t *vm, process_t *proc);
int op_lldi(vm_t *vm, process_t *proc);
int op_lfork(vm_t *vm, process_t *proc);
int op_aff(vm_t *vm, process_t *proc);

#endif /* !OPS_H_ */
