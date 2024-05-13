/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** Source file for the instruction struct
*/

#include <stdlib.h>
#include "cbyte.h"
#include "rules.h"

byte_t get_cbyte_val_at(byte_t b, int pos)
{
    if (pos < 0 || pos > 3) {
        return 0;
    } else {
        return (b >> (6 - (pos * 2))) & 3;
    }
}

static void fill_cbyte(byte_t *cbyte, const args_type_t *types)
{
    for (int i = 0; types[i]; i++) {
        switch (types[i]) {
            case T_REG: *cbyte |= 1 << (6 - (i * 2)); break;
            case T_DIR: *cbyte |= 2 << (6 - (i * 2)); break;
            case T_IND: *cbyte |= 3 << (6 - (i * 2)); break;
            case T_LAB: *cbyte |= 3 << (6 - (i * 2)); break;
            default: break;
        }
        if ((i + 1) % 4 == 0) {
            cbyte++;
            types += 4;
            i = -1;
        }
    }
}

size_t get_cbyte_size(void)
{
    size_t size = 0;

    size = MAX_ARGS_NUMBER % 4;
    if (size == 0) {
        size = 1;
    }
    return size;
}

byte_t *make_cbyte(const args_type_t *types)
{
    byte_t *cbyte = NULL;
    size_t size = 0;

    size = get_cbyte_size();
    cbyte = malloc(sizeof(byte_t) * size);
    ASSERT(cbyte, NULL);
    for (size_t i = 0; i < size; i++) {
        cbyte[i] = 0;
    }
    fill_cbyte(cbyte, types);
    return cbyte;
}
