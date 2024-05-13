/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** Source file for the instruction struct
*/

#include <stdlib.h>
#include <stdio.h>
#include "instru.h"
#include "cbyte.h"
#include "rules.h"

int set_instru_from_mem(instru_t *instru, byte_t *mem, size_t midx)
{
    size_t cblen = 0;

    ASSERT(instru && mem, ERROR);
    instru->type = mem[midx++];
    if (HAS_CBYTE(instru->type)) {
        cblen = get_cbyte_size();
        instru->cbyte = mem + midx;
    }
    instru->data = mem + midx + cblen;
    return SUCCESS;
}

int set_instru_from_asm(
    instru_t *instru, instru_type_t type,
    const args_type_t *types, const int *values)
{
    ASSERT(instru && type && types && values, ERROR);
    instru->type = type;
    if (HAS_CBYTE(type)) {
        instru->cbyte = make_cbyte(types);
        ASSERT(instru->cbyte, ERROR);
    }
    instru->data = make_instru_data(type, types, values);
    if (!instru->data) {
        if (HAS_CBYTE(type)) {
            free(instru->cbyte);
            instru->cbyte = NULL;
        }
        return ERROR;
    }
    instru->len = get_data_size(type, types);
    return SUCCESS;
}

size_t get_instru_size(instru_t *instru)
{
    size_t size = 1;

    ASSERT(instru, 0);
    if (HAS_CBYTE(instru->type)) {
        size += get_cbyte_size();
    }
    return size + instru->len;
}
