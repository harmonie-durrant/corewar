/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** Source file for the champion struct
*/

#include "byte.h"
#include "op.h"
#include "rules.h"

void init_header(header_t *header)
{
    ASSERT(header,);
    header->magic = COREWAR_EXEC_MAGIC;
    header->magic = SWAP32(header->magic);
    for (int i = 0; i < PROG_NAME_LENGTH + 1; i++) {
        header->prog_name[i] = ' ';
    }
    header->prog_size = 0;
    for (int i = 0; i < COMMENT_LENGTH + 1; i++) {
        header->comment[i] = ' ';
    }
}
