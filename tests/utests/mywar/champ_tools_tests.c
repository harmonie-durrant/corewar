/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** Base tests for champ_tools.c funcs
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include "champ.h"
#include "instru.h"
#include "cbyte.h"
#include "rules.h"

Test(champ_tools_tests, simple_test)
{
    FILE *mem = fopen("../../tests/champions/abel.cor", "r");
    champ_t *champ = create_champ();

    cr_assert(mem != NULL);
    cr_assert(champ != NULL);
    cr_assert(set_champ_from_mem(champ, mem) == SUCCESS);
    cr_assert(champ->header.magic == COREWAR_EXEC_MAGIC, "magic: %d", champ->header.magic);
    cr_assert(champ->header.prog_size == 22, "prog_size: %d", champ->header.prog_size);
}