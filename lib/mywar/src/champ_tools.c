/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** Source file for the champion struct
*/

#include <stdlib.h>
#include "byte.h"
#include "champ.h"
#include "rules.h"

static int set_header_from_mem(header_t *header, FILE *mem)
{
    ASSERT(header && mem, ERROR);
    ASSERT(fread(header, sizeof(header_t), 1, mem) == 1, ERROR);
    header->magic = SWAP32(header->magic);
    ASSERT(header->magic == COREWAR_EXEC_MAGIC, ERROR);
    header->prog_size = SWAP32(header->prog_size);
    return SUCCESS;
}

static int set_code_from_mem(byte_t **code, FILE *mem, size_t len)
{
    ASSERT(code && mem, ERROR);
    *code = malloc(len);
    ASSERT(*code, ERROR);
    if (fread(*code, sizeof(byte_t), len, mem) != len) {
        free(*code);
        return ERROR;
    }
    return SUCCESS;
}

int set_champ_from_mem(champ_t *champ, FILE *mem)
{
    size_t len = 0;

    ASSERT(champ && mem, ERROR);
    ASSERT_ERR(set_header_from_mem(&champ->header, mem), ERROR);
    len = champ->header.prog_size;
    ASSERT_ERR(set_code_from_mem(&champ->code, mem, len), ERROR);
    return SUCCESS;
}
