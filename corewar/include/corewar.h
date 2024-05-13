/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** main header for the corewar binary
*/

#ifndef COREWAR_H
    #define COREWAR_H

    #include "vm.h"
    #include "rules.h"
    #include "base.h"
    #include "corewar_info.h"
    #define REG_VALID(reg) IS_BETWEEN(reg, 1, REG_NUMBER)
    #define ASSERT_REG(reg) ASSERT(REG_VALID(reg), ERROR)

// MAIN TOOLS
int check_args(int ac, char **av);
int flag_handler(vm_t *vm, int ac, char **av);
int get_n_champs(int argc, char **argv);

// ERROR HANDLING
int check_file(char *filename);
void print_help(void);

// COREWAR
int corewar(int ac, char **av);
int start_corewar(corewar_info_t *info);
int add_champ_to_vm(vm_t *vm, corewar_champs_t *info);
int count_champs(corewar_champs_t *champ_info);
void add_champions(corewar_champs_t *champ_info, vm_t *vm);

byte_t *get_op(byte_t *mem, size_t midx);
int read_val(byte_t *mem, byte_t size);
int read_ind(byte_t *mem, byte_t size);
#endif /* !COREWAR_H */
