/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar_info_tools
*/

#include <stdlib.h>
#include "corewar_info.h"
#include "pf.h"
#include "rules.h"

void reverse_corewar_champs(corewar_champs_t **champs)
{
    corewar_champs_t *prev = NULL;
    corewar_champs_t *curr = *champs;
    corewar_champs_t *tmp = NULL;

    while (curr) {
        tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    *champs = prev;
}

void set_new_champ(corewar_champs_t *new_champ, corewar_info_t *info)
{
    new_champ->next = info->champions;
    info->champions = new_champ;
    info->tmp_load_addr = -1;
    info->tmp_prog_num = -1;
}

int free_corewar_champs(corewar_champs_t *champ)
{
    corewar_champs_t *prev = NULL;

    for (; champ != NULL; champ = champ->next) {
        if (prev != NULL) {
            free(prev);
        }
        if (fclose(champ->stream) < 0) {
            fpf(2, "Error closing file: %s\n", champ->name);
            return ERROR;
        }
        prev = champ;
    }
    free(prev);
    return SUCCESS;
}

void init_corewar_champ(corewar_champs_t *new_champ)
{
    new_champ->prog_num = 0;
    new_champ->load_addr = 0;
    new_champ->name = NULL;
    new_champ->stream = NULL;
    new_champ->next = NULL;
}
