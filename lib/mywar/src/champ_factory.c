/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** Source file for the champion struct
*/

#include <stdlib.h>
#include "champ.h"
#include "rules.h"

void init_champ(champ_t *champ)
{
    ASSERT(champ,);
    init_header(&champ->header);
    champ->code = NULL;
}

champ_t *create_champ(void)
{
    champ_t *champ = NULL;

    champ = malloc(sizeof(champ_t));
    ASSERT(champ, NULL);
    init_champ(champ);
    return champ;
}

void destroy_champ(champ_t *champ)
{
    ASSERT(champ,);
    free(champ->code);
}
