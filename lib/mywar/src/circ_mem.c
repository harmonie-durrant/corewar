/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** Source file for the circular memory
*/

#include <stdlib.h>
#include "byte.h"
#include "op.h"
#include "rules.h"

static void mcpy(byte_t *dest, byte_t *src, size_t len)
{
    ASSERT(dest && src && len,);
    for (size_t i = 0; i < len; i++) {
        dest[i] = src[i];
    }
}

byte_t *mget(byte_t *mem, size_t midx, size_t len)
{
    byte_t *data = NULL;

    ASSERT(mem && len, NULL);
    data = malloc(sizeof(byte_t) * len);
    ASSERT(data, NULL);
    if (midx + len > MEM_SIZE) {
        mcpy(data, mem + midx, MEM_SIZE - midx);
        mcpy(data + (MEM_SIZE - midx), mem, len - (MEM_SIZE - midx));
    } else {
        mcpy(data, mem + midx, len);
    }
    return data;
}

int mput(byte_t *mem, size_t midx, byte_t *data, size_t len)
{
    ASSERT(mem && data && len, ERROR);
    if (midx + len > MEM_SIZE) {
        mcpy(mem + midx, data, MEM_SIZE - midx);
        mcpy(mem, data + (MEM_SIZE - midx), len - (MEM_SIZE - midx));
    } else {
        mcpy(mem + midx, data, len);
    }
    return SUCCESS;
}
