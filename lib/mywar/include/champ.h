/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** Header for the champion structure
*/

#ifndef CHAMP_H
    #define CHAMP_H
    #include <stdio.h>
    #include "byte.h"
    #include "op.h"

typedef struct champ_s {
    header_t header;
    byte_t *code;
} champ_t;

void init_header(header_t *header);
void init_champ(champ_t *champ);
void destroy_champ(champ_t *champ);
champ_t *create_champ(void);

int set_champ_from_mem(champ_t *champ, FILE *mem);
#endif /* !CHAMP_H */
