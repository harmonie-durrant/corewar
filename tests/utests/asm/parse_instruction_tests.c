/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** parse_instruction_tests
*/

#include <criterion/criterion.h>
#include "asm.h"
#include "rules.h"
#include "str.h"

Test(parse_instru_type, live)
{
    char *instruction = "    live %:label";

    cr_assert_eq(get_instru_type(instruction), LIVE);
}

Test(parse_instru_type, ld)
{
    char *instruction = "    ld %0, r3";

    cr_assert_eq(get_instru_type(instruction), LD);
}

Test(parse_instru_type, zjmp)
{
    char *instruction = "    zjmp	%:attack";

    cr_assert_eq(get_instru_type(instruction), ZJMP);
}

Test(parse_instru_type, error)
{
    char *instruction = "   hello	%12";

    cr_assert_eq(get_instru_type(instruction), ERR);
}

Test(parse_instru_line, overflow)
{
    char *line = sdup(" ld 5, 8, 65536");
    int pos = 0;
    list_t *labels = NULL;
    list_t *sizes = NULL;
    instru_t *instru = create_instru();
    list_t *lists[] = {labels, sizes};

    cr_assert_eq(parse_instru_line(line, instru, lists, pos), ERROR);
    destroy_instru(instru);
}

Test(parse_instru_line, valid1)
{
    char *line = sdup(" fork %98");
    int pos = 0;
    list_t *labels = NULL;
    list_t *sizes = NULL;
    instru_t *instru = create_instru();
    list_t *lists[] = {labels, sizes};

    cr_assert_eq(parse_instru_line(line, instru, lists, pos), SUCCESS);
    cr_assert_eq(instru->type, FORK);
    cr_assert_eq(instru->data[0], 0x00);
    cr_assert_eq(instru->data[1], 0x62);
    destroy_instru(instru);
}

Test(parse_instru_line, valid2)
{
    char *line = sdup(" zjmp 556");
    int pos = 0;
    list_t *labels = NULL;
    list_t *sizes = NULL;
    list_t *lists[] = {labels, sizes};
    instru_t *instru = create_instru();

    cr_assert_eq(parse_instru_line(line, instru, lists, pos), SUCCESS);
    cr_assert_eq(instru->type, ZJMP);
    cr_assert_eq(instru->data[0], 0x02);
    cr_assert_eq(instru->data[1], 0x2c);
    destroy_instru(instru);
}

Test(parse_instru_line, valid3)
{
    char *line = sdup(" ld 12");
    int pos = 0;
    list_t *labels = NULL;
    list_t *sizes = NULL;
    list_t *lists[] = {labels, sizes};
    instru_t *instru = create_instru();

    cr_assert_eq(parse_instru_line(line, instru, lists, pos), SUCCESS);
    cr_assert_eq(instru->type, LD);
    cr_assert_eq(instru->data[0], 0x00);
    cr_assert_eq(instru->data[1], 0x0c);
    destroy_instru(instru);
}
