/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** Source file for the instruction struct
*/

#include <stdlib.h>
#include "op.h"
#include "instru.h"
#include "mywar.h"
#include "rules.h"
#include "cbyte.h"
#include "base.h"

static const idx_handler_t handlers[] = {
    {LIVE, {0, 0, 0, 0}},
    {LD, {0, 0, 0, 0}},
    {ST, {0, 0, 0, 0}},
    {ADD, {0, 0, 0, 0}},
    {SUB, {0, 0, 0, 0}},
    {AND, {0, 0, 0, 0}},
    {OR, {0, 0, 0, 0}},
    {XOR, {0, 0, 0, 0}},
    {ZJMP, {1, 0, 0, 0}},
    {LDI, {1, 1, 0, 0}},
    {STI, {0, 1, 1, 0}},
    {FORK, {1, 0, 0, 0}},
    {LLD, {0, 0, 0, 0}},
    {LLDI, {1, 1, 0, 0}},
    {LFORK, {1, 0, 0, 0}},
    {AFF, {0, 0, 0, 0}},
    {0, {0, 0, 0, 0}}
};

size_t get_arg_size(instru_type_t itype,
    const args_type_t type, int index)
{
    if (itype == LIVE && index == 0 && type == T_DIR) {
        return 4;
    }
    if (handlers[itype - 1].use_idx[index] && type != T_REG) {
        return IND_SIZE;
    }
    switch (type) {
        case T_REG: return 1;
        case T_DIR: return DIR_SIZE;
        case T_IND: return IND_SIZE;
        default: return 0;
    }
}

size_t get_mem_size(instru_type_t itype, byte_t *cbyte)
{
    size_t size = 1;
    int i = 0;

    ASSERT(cbyte, 0);
    ASSERT(IS_BETWEEN(itype, LIVE, AFF), 0);
    if (!HAS_CBYTE(itype)) {
        return get_arg_size(itype, op_tab[itype - 1].type[0], 0) + 1;
    }
    while (i < op_tab[itype - 1].nbr_args) {
        size += get_arg_size(itype, get_cbyte_val_at(*cbyte, i), i);
        i++;
    }
    return size + get_cbyte_size();
}

size_t get_data_size(instru_type_t itype, const args_type_t *types)
{
    size_t size = 0;
    int i = 0;

    ASSERT(types, 0);
    while (types[i]) {
        size += get_arg_size(itype, types[i], i);
        i++;
    }
    return size;
}

static int fill_instru_data(byte_t *data, instru_type_t itype,
    const args_type_t *types, const int *values)
{
    size_t arg_size = 0;
    int i = 0;

    while (types[i]) {
        arg_size = get_arg_size(itype, types[i], i);
        if (put_cor_nbr(data, values[i], arg_size, types[i] != T_REG) == 84) {
            return ERROR;
        }
        data += arg_size;
        i++;
    }
    return SUCCESS;
}

byte_t *make_instru_data(instru_type_t itype,
    const args_type_t *types, const int *values)
{
    byte_t *data = NULL;
    size_t size = 0;

    size = get_data_size(itype, types) + 1;
    data = malloc(sizeof(byte_t) * size);
    ASSERT(data, NULL);
    if (fill_instru_data(data, itype, types, values) == 84) {
        free(data);
        return NULL;
    }
    return data;
}
