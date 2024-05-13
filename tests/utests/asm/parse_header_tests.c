/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** parse_header_tests
*/

#include <criterion/criterion.h>
#include "asm.h"
#include "rules.h"

Test(parse_header, no_tab)
{
    char *path = "../tests/champions/src/abel2.s";
    header_t header = {0};
    FILE *stream = fopen(path, "r");

    init_header(&header);
    cr_assert_not_null(stream);
    cr_assert_eq(parse_header(stream, &header), SUCCESS);
    cr_assert_str_eq(header.prog_name, "Abel2");
    cr_assert_str_eq(header.comment, "L'autre Abel");
    fclose(stream);
}

Test(parse_header, bill)
{
    char *path = "../tests/champions/src/bill.s";
    header_t header = {0};
    FILE *stream = fopen(path, "r");

    init_header(&header);
    cr_assert_not_null(stream);
    cr_assert_eq(parse_header(stream, &header), SUCCESS);
    cr_assert_str_eq(header.prog_name, "Bill");
    cr_assert_str_eq(header.comment, "Equilibre");
    fclose(stream);
}

Test(parse_header, tyron)
{
    char *path = "../tests/champions/src/tyron.s";
    header_t header = {0};
    FILE *stream = fopen(path, "r");

    init_header(&header);
    cr_assert_not_null(stream);
    cr_assert_eq(parse_header(stream, &header), SUCCESS);
    cr_assert_str_eq(header.prog_name, "Tyron");
    cr_assert_str_eq(header.comment, "Just a basic pompes, traction program");
    fclose(stream);
}

Test(parse_header, pdd)
{
    char *path = "../tests/champions/src/pdd.s";
    header_t header = {0};
    FILE *stream = fopen(path, "r");

    init_header(&header);
    cr_assert_not_null(stream);
    cr_assert_eq(parse_header(stream, &header), SUCCESS);
    cr_assert_str_eq(header.prog_name, "pdd");
    cr_assert_str_eq(header.comment, "pdd");
    fclose(stream);
}

Test(parse_header, no_header)
{
    char *path = "../tests/champions/src/abel_no_header.s";
    header_t header = {0};
    FILE *stream = fopen(path, "r");

    init_header(&header);
    cr_assert_not_null(stream);
    cr_assert_eq(parse_header(stream, &header), ERROR);
    fclose(stream);
}
