/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** flag_checker
*/

#include "corewar_info.h"
#include "pf.h"
#include "rules.h"

int check_pnum(corewar_info_t *info)
{
    corewar_champs_t *champs = NULL;

    champs = info->champions;
    for (; champs != NULL; champs = champs->next) {
        if (champs->prog_num == info->tmp_prog_num) {
            fpf(2, "Error: Program number already in use.\n");
            return ERROR;
        }
    }
    return SUCCESS;
}

int check_laddr(corewar_info_t *info)
{
    corewar_champs_t *champs = NULL;

    champs = info->champions;
    for (; champs != NULL; champs = champs->next) {
        if (champs->load_addr == info->tmp_load_addr) {
            fpf(2, "Error: Load address already in use.\n");
            return ERROR;
        }
    }
    return SUCCESS;
}
