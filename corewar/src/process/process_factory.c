/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** process_factory
*/

#include <stdlib.h>
#include "process.h"
#include "rules.h"

process_t *create_process(void)
{
    process_t *proc = NULL;

    proc = malloc(sizeof(process_t));
    ASSERT(proc, NULL);
    for (int i = 0; i < REG_NUMBER; i++) {
        for (int j = 0; j < REG_SIZE; j++) {
            proc->regs[i][j] = 0;
        }
    }
    proc->champid = 0;
    proc->carry = 0;
    proc->live = 0;
    proc->wait = -1;
    proc->pc = 0;
    return proc;
}

process_t *duplicate_process(process_t *process, int pc_offset)
{
    process_t *new = NULL;

    ASSERT(process, NULL);
    new = create_process();
    ASSERT(new, NULL);
    new->carry = process->carry;
    new->champid = process->champid;
    new->pc = (process->pc + pc_offset) % MEM_SIZE;
    new->wait = -1;
    new->live = 0;
    for (int i = 0; i < REG_NUMBER; i++) {
        for (int j = 0; j < REG_SIZE; j++) {
            new->regs[i][j] = process->regs[i][j];
        }
    }
    return new;
}

void destroy_process(process_t **process)
{
    ASSERT(process && *process,);
    free(*process);
    *process = NULL;
}
