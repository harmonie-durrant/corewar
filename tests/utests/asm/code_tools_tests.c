/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** Test for the generation of the champion's code
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include "asm.h"
#include "list.h"

Test(code_tools_tests, get_champ_code_simple_test)
{
    instru_t *instru = NULL;
    list_t *instrus = NULL;
    byte_t *code = NULL;

    instru = create_instru();
    set_instru_from_asm(instru, LIVE,
        (const args_type_t[]){T_DIR}, (const int []){0xb2c49a});
    (void) append_to_list(&instrus, instru);
    code = get_champ_code(instrus);
    cr_assert_eq(code[0], 0x01, "code[0] = %x\n", code[0]);
    cr_assert_eq(code[1], 0x00, "code[1] = %x\n", code[1]);
    cr_assert_eq(code[2], 0xb2, "code[2] = %x\n", code[2]);
    cr_assert_eq(code[3], 0xc4, "code[3] = %x\n", code[3]);
    cr_assert_eq(code[4], 0x9a, "code[4] = %x\n", code[4]);
    free(code);
}

Test(code_tools_tests, get_champ_code_complex_test)
{
    instru_t *instru1 = NULL;
    instru_t *instru2 = NULL;
    list_t *instrus = NULL;
    byte_t *code = NULL;

    instru1 = create_instru();
    set_instru_from_asm(instru1, LIVE,
        (const args_type_t[]){T_DIR}, (const int []){0x00b2c49a});
    (void) append_to_list(&instrus, instru1);
    instru2 = create_instru();
    set_instru_from_asm(instru2, LD,
        (const args_type_t[]){T_DIR, T_REG}, (const int []){0x00b2c49a, 0x90});
    (void) append_to_list(&instrus, instru2);
    code = get_champ_code(instrus);
    cr_assert_eq(code[0], 0x01, "code[0] = %x\n", code[0]);
    cr_assert_eq(code[1], 0x00, "code[1] = %x\n", code[1]);
    cr_assert_eq(code[2], 0xb2, "code[2] = %x\n", code[2]);
    cr_assert_eq(code[3], 0xc4, "code[3] = %x\n", code[3]);
    cr_assert_eq(code[4], 0x9a, "code[4] = %x\n", code[4]);
    cr_assert_eq(code[5], 0x02, "code[5] = %x\n", code[5]);
    free(code);
}