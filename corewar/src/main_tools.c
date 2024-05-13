/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** main_tools
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "corewar_info.h"
#include "corewar.h"
#include "pf.h"
#include "str.h"
#include "len.h"
#include "rules.h"

void print_help(void)
{
    fpf(1, "USAGE\n"
    "./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address]"
    " prog_name] ...\n"
    "DESCRIPTION\n"
    "-dump nbr_cycle dumps the memory after the nbr_cycle execution"
    " (if the round isn't already over) with the following format:"
    " 32 bytes/line in hexadecimal (A0BCDEFE1DD3...)"
    "-n prog_number sets the next program's number."
    " By default, the first free number in the parameter order"
    "-a load_address sets the next program's loading address."
    " When no address is specified, optimize the addresses so that"
    " the processes are as far away from each other as possible. The"
    " addresses are MEM_SIZE modulo.\n");

}

int check_args(int ac, char **av)
{
    if (ac < 2 || av == NULL) {
        fpf(2, "Invalid number of arguments, use -h for more info.\n");
        return ERROR;
    }
    if (ac == 2 && sexact(av[1], "-h")) {
        print_help();
        return SUCCESS;
    }
    return 1;
}

int get_n_champs(int argc, char **argv)
{
    int n = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            i++;
        } else {
            n++;
        }
    }
    if (n == 1) {
        return n + 1;
    }
    return n;
}

int check_missing_script(corewar_info_t info)
{
    if (info.tmp_load_addr != -1 || info.tmp_prog_num != -1) {
        fpf(2, "Error: Missing script for player %i with start address %i.\n",
        info.tmp_prog_num, info.tmp_load_addr);
        return ERROR;
    }
    return SUCCESS;
}
