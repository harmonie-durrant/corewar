/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** assembler_tools
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "asm.h"
#include "op.h"
#include "str.h"

Test(get_next_line, empty_file, .init = cr_redirect_stderr)
{
    FILE *stream = fopen("../tests/champions/src/empty.s", "r");
    char *line = get_next_line(stream);

    cr_assert_null(line);
    fclose(stream);
}

Test(get_next_line, empty_line, .init = cr_redirect_stderr)
{
    FILE *stream = fopen("../tests/champions/src/comment.s", "r");
    char *line = NULL;

    cr_assert_not_null(stream);
    line = get_next_line(stream);
    cr_assert_str_eq(line, "\t.name \"com\"");
    free(line);
    line = get_next_line(stream);
    cr_assert_str_eq(line, "\t.comment \"com\"");
    free(line);
    line = get_next_line(stream);
    cr_assert_str_eq(line, "\tsti\tr1, %:live, %1");
    free(line);
    line = get_next_line(stream);
    cr_assert_str_eq(line, "\tfork	%:live");
    free(line);
    fclose(stream);
}

Test(get_sgf_format, sgf_format, .init = cr_redirect_stderr)
{
    char *format = NULL;

    format = get_sgf_format(1);
    cr_assert_str_eq(format, "%s");
    free(format);
    format = get_sgf_format(5);
    cr_assert_str_eq(format, "%s,%s,%s,%s,%s");
    free(format);
}

Test(get_line_data_start, start, .init = cr_redirect_stderr)
{
    char *line1 = "	sti	r1, %:live, %1";
    char *line2 = "	zjmp	%:attack";
    char *line3 = "hi:	live %123";
    char *line4 = "";
    char *line5 = NULL;
    char *line6 = "lesChaussettesDeLarchiduchesseSontEllesSeches";

    cr_assert_eq(get_line_data_start(line1), 5);
    cr_assert_eq(get_line_data_start(line2), 6);
    cr_assert_eq(get_line_data_start(line3), 9);
    cr_assert_eq(get_line_data_start(line4), -1);
    cr_assert_eq(get_line_data_start(line5), -1);
    cr_assert_eq(get_line_data_start(line6), -1);
}

Test(clean_line, clean)
{
    char line[] = "	sti	r1, %:live, %1";

    cr_assert_not_null(line);
    clean_line(line);
    cr_assert_str_eq(line, "stir1,%:live,%1");
}

Test(get_new_filename, valid1)
{
    char *filename = "random_file.s";
    char *ref = "random_file.cor";
    char *new_filename = NULL;

    new_filename = get_new_filename(filename);
    cr_assert_not_null(new_filename);
    cr_assert_str_eq(new_filename, ref);
    free(new_filename);
}

Test(get_new_filename, valid2)
{
    char *filename = "path/to/the/champ.s";
    char *ref = "champ.cor";
    char *new_filename = NULL;

    new_filename = get_new_filename(filename);
    cr_assert_not_null(new_filename);
    cr_assert_str_eq(new_filename, ref);
    free(new_filename);
}

Test(get_new_filename, null)
{
    char *filename = NULL;
    char *new_filename = NULL;

    new_filename = get_new_filename(filename);
    cr_assert_null(new_filename);
}

Test(get_new_filename, no_extention)
{
    char *filename = "no_extention";
    char *new_filename = NULL;

    new_filename = get_new_filename(filename);
    cr_assert_null(new_filename);
}

Test(get_new_filename, only_extention)
{
    char *filename = ".s";
    char *new_filename = NULL;

    new_filename = get_new_filename(filename);
    cr_assert_null(new_filename);
}
