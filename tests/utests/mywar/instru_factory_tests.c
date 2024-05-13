/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** Base tests for instru_factory functions
*/

#include <criterion/criterion.h>
#include "instru.h"

Test(instru_tests, init_instru)
{
    instru_t instru;

    init_instru(&instru);
    cr_assert_eq(instru.type, 0);
    cr_assert_eq(instru.cbyte, NULL);
    cr_assert_eq(instru.data, NULL);
}

Test(instru_tests, create_instru)
{
    instru_t *instru = create_instru();

    cr_assert_not_null(instru);
    cr_assert_eq(instru->type, 0);
    cr_assert_eq(instru->cbyte, NULL);
    cr_assert_eq(instru->data, NULL);
    destroy_instru(instru);
}

Test(instru_tests, destroy_instru)
{
    instru_t *instru = create_instru();

    cr_assert_not_null(instru);
    destroy_instru(instru);
}
