/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** Source file for the instruction struct
*/

#include <stdbool.h>
#include <stddef.h>
#include "cbyte.h"
#include "instru.h"
#include "rules.h"
#include "base.h"

bool args_are_valid(instru_type_t type, const args_type_t *types)
{
    op_t op = op_tab[type - 1];
    int i = 0;

    ASSERT(types, false);
    ASSERT(IS_BETWEEN(type, LIVE, AFF), false);
    op = op_tab[type - 1];
    for (; i < op.nbr_args; i++) {
        ASSERT(types[i], false);
        if (op.type[i] & types[i]) {
            continue;
        }
        return false;
    }
    return true;
}

bool mem_is_valid(const byte_t *cbyte, instru_type_t type)
{
    int i = 0;
    int j = 0;
    byte_t tmp = 0;

    ASSERT(cbyte, false);
    ASSERT(IS_BETWEEN(type, LIVE, AFF), false);
    ASSERT(HAS_CBYTE(type), true);
    for (; i < MAX_ARGS_NUMBER; i++, j++) {
        tmp = get_cbyte_val_at(*cbyte, j);
        if (j % 4 == 3) {
            cbyte++;
            j = -1;
        }
        if (i < op_tab[type - 1].nbr_args) {
            ASSERT(tmp && (tmp & op_tab[type - 1].type[i]), false);
        } else {
            ASSERT(!tmp, false);
        }
    }
    return true;
}
