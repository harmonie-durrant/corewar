/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** process
*/

#ifndef PROCESS_H_
    #define PROCESS_H_
    #include <stddef.h>
    #include "byte.h"
    #include "op.h"

    typedef struct process_s {
        int champid;
        byte_t regs[REG_NUMBER][REG_SIZE];
        size_t pc;
        int carry;
        int live;
        int wait;
    } process_t;

process_t *create_process(void);
void destroy_process(process_t **process);
process_t *duplicate_process(process_t *process, int pc_offset);

void write_reg(process_t *process, int reg, int value);
int read_reg(process_t *process, int reg);

#endif /* !PROCESS_H_ */
