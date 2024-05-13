/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** Tools for the champion struct
*/

#include <stdlib.h>
#include "byte.h"
#include "cbyte.h"
#include "rules.h"
#include "instru.h"
#include "list.h"

static void write_cbyte_in_code(byte_t *code, byte_t *cbyte, size_t *i)
{
    size_t cblen = 0;

    cblen = get_cbyte_size();
    for (size_t j = 0; j < cblen; j++) {
        code[(*i)++] = cbyte[j];
    }
}

static void write_instru_in_code(byte_t *code, instru_t *instru, size_t *i)
{
    ASSERT(instru->type != MTY && instru->type != ERR,);
    code[(*i)++] = instru->type;
    if (HAS_CBYTE(instru->type) && instru->cbyte) {
        write_cbyte_in_code(code, instru->cbyte, i);
    }
    for (size_t j = 0; j < instru->len; j++) {
        code[(*i)++] = instru->data[j];
    }
}

size_t get_code_size(list_t *tmp)
{
    size_t size = 0;

    ASSERT(tmp, 0);
    for (; tmp; tmp = tmp->next) {
        size += ((instru_t *)tmp->data)->len;
        if (HAS_CBYTE(((instru_t *)tmp->data)->type)) {
            size += get_cbyte_size();
        }
        size++;
    }
    return size;
}

byte_t *get_champ_code(list_t *instrus)
{
    size_t len = 0;
    byte_t *code = NULL;
    list_t *tmp = NULL;
    size_t i = 0;

    ASSERT(instrus, NULL);
    len = get_code_size(instrus);
    code = malloc(sizeof(byte_t) * len);
    ASSERT(code, NULL);
    for (tmp = instrus; tmp; tmp = tmp->next) {
        write_instru_in_code(code, tmp->data, &i);
    }
    return code;
}
