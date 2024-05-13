/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** flag_handler
*/

#include <stdlib.h>
#include "corewar_info.h"
#include "corewar.h"
#include "process.h"
#include "vm.h"
#include "read.h"
#include "str.h"
#include "pf.h"
#include "rules.h"
#include "champ.h"

int set_dump(int *i, char *argv[], int argc, corewar_info_t *info)
{
    if (sequal(argv[*i], "-dump")) {
        if (info->seen_dump == 1) {
            return ERROR;
        }
        if (*i + 1 < argc && snum(argv[*i + 1])) {
            info->seen_dump = 1;
            info->dump = stoi(argv[*i + 1]);
            *i = *i + 1;
        } else {
            fpf(2, "Missing value for -dump flag.\n");
            return ERROR;
        }
        return 1;
    }
    fpf(2, "%s\n", argv[*i]);
    return SUCCESS;
}

int set_pnum(int *i, char *argv[], int argc, corewar_info_t *info)
{
    if (sequal(argv[*i], "-n")) {
        if (*i + 2 < argc && snum(argv[*i + 1])) {
            info->tmp_prog_num = stoi(argv[*i + 1]);
            *i = *i + 1;
        } else {
            fpf(2, "Missing values for -n flag.\n");
            return ERROR;
        }
        ASSERT(check_pnum(info) != ERROR, ERROR);
        return 1;
    }
    return SUCCESS;
}

int set_laddr(int *i, char *argv[], int argc, corewar_info_t *info)
{
    if (sequal(argv[*i], "-a")) {
        if (*i + 1 < argc && snum(argv[*i + 1])) {
            info->tmp_load_addr = stoi(argv[*i + 1]);
            info->tmp_load_addr %= MEM_SIZE;
            *i = *i + 1;
        } else {
            fpf(2, "Missing value for -a flag.\n");
            return ERROR;
        }
        ASSERT(check_laddr(info) != ERROR, ERROR);
        return 1;
    }
    return SUCCESS;
}

int handle_flag(int *i, char *argv[], int argc, corewar_info_t *info)
{
    int g_flag = 0;

    g_flag = set_dump(i, argv, argc, info);
    ASSERT_ERR(g_flag, ERROR);
    if (g_flag != 1) {
        g_flag = set_pnum(i, argv, argc, info);
    }
    ASSERT_ERR(g_flag, ERROR);
    if (g_flag != 1) {
        g_flag = set_laddr(i, argv, argc, info);
    }
    ASSERT_ERR(g_flag, ERROR);
    if (g_flag == 0) {
        ASSERT(sequal(argv[*i], "-h"), ERROR);
        print_help();
        return 1;
    }
    return SUCCESS;
}
