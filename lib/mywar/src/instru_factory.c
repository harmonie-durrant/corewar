/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** Source file for the instruction struct
*/

#include <stdlib.h>
#include "instru.h"
#include "rules.h"

void init_instru(instru_t *instru)
{
    ASSERT(instru,);
    instru->type = 0;
    instru->cbyte = NULL;
    instru->data = NULL;
}

instru_t *create_instru(void)
{
    instru_t *instru = NULL;

    instru = malloc(sizeof(instru_t));
    ASSERT(instru, NULL);
    init_instru(instru);
    return instru;
}

void destroy_instru(instru_t *instru)
{
    ASSERT(instru,);
    if (instru->cbyte)
        free(instru->cbyte);
    if (instru->data)
        free(instru->data);
    free(instru);
}
