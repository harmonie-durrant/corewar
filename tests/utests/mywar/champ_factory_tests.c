/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** Base tests for champ.c funcs
*/

#include <criterion/criterion.h>
#include "champ.h"
#include "op.h"

Test(champ_tests, init_champ)
{
    champ_t champ;

    init_champ(&champ);
    cr_assert_eq(SWAP32(champ.header.magic), COREWAR_EXEC_MAGIC);
    cr_assert_eq(champ.header.prog_size, 0);
    cr_assert_eq(champ.header.prog_name[0], ' ');
    cr_assert_eq(champ.header.comment[0], ' ');
    cr_assert_eq(champ.code, NULL);
}

Test(champ_tests, create_champ)
{
    champ_t *champ = create_champ();
    cr_assert_not_null(champ);
    cr_assert_eq(SWAP32(champ->header.magic), COREWAR_EXEC_MAGIC);
    cr_assert_eq(champ->header.prog_size, 0);
    cr_assert_eq(champ->header.prog_name[0], ' ');
    cr_assert_eq(champ->header.comment[0], ' ');
    cr_assert_eq(champ->code, NULL);
    destroy_champ(champ);
}

Test(champ_tests, destroy_champ)
{
    champ_t *champ = create_champ();

    cr_assert_not_null(champ);
    destroy_champ(champ);
}
