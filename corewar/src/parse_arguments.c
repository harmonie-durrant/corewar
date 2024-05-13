/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** parse_arguments
*/

#include <stdlib.h>
#include "corewar_info.h"
#include "corewar.h"
#include "pf.h"
#include "rules.h"

void set_vars(corewar_champs_t *new_champ, corewar_info_t *info,
int n_champs, int *num_champions)
{
    if (info->tmp_prog_num == -1) {
        new_champ->prog_num = *num_champions;
    } else {
        new_champ->prog_num = info->tmp_prog_num;
    }
    if (info->tmp_load_addr == -1) {
        new_champ->load_addr = *num_champions * MEM_SIZE / (n_champs + 1);
    } else {
        new_champ->load_addr = info->tmp_load_addr;
    }
    *num_champions = *num_champions + 1;
}

int create_info(corewar_info_t *info, int n_champs, char *file,
int *num_champions)
{
    corewar_champs_t *new_champ = NULL;

    new_champ = malloc(sizeof(corewar_champs_t));
    ASSERT(new_champ, ERROR);
    init_corewar_champ(new_champ);
    set_vars(new_champ, info, n_champs, num_champions);
    if (check_pnum(info) == ERROR || check_laddr(info) == ERROR) {
        free(new_champ);
        return ERROR;
    }
    new_champ->name = file;
    new_champ->stream = fopen(file, "rb");
    if (new_champ->stream == NULL) {
        fpf(2, "Error opening file: %s\n", file);
        free(new_champ);
        return ERROR;
    }
    set_new_champ(new_champ, info);
    return SUCCESS;
}

static int parse_arguments_loop(int argc, char *argv[], corewar_info_t *info)
{
    int n_champs = 0;
    int err = 0;
    int num_champions = 0;

    n_champs = get_n_champs(argc, argv);
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            err = handle_flag(&i, argv, argc, info);
        } else {
            err = create_info(info, n_champs, argv[i], &num_champions);
        }
        ASSERT(err == 0, err);
    }
    return 0;
}

corewar_info_t parse_arguments(int argc, char *argv[])
{
    corewar_info_t info = {-1, 0, 0, 0, NULL};
    corewar_info_t fail_info = ((corewar_info_t){0, 0, -2, 0, NULL});
    corewar_info_t skip_info = ((corewar_info_t){0, 0, -3, 0, NULL});

    switch (parse_arguments_loop(argc, argv, &info)) {
        case 1: return skip_info;
        case 84: return fail_info;
    }
    ASSERT_ERR(check_missing_script(info), fail_info);
    ASSERT(info.champions == NULL, info);
    fpf(2, "No program names provided.\n");
    return fail_info;
}
