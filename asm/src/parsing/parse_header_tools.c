/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** parse_header_tools
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "asm.h"
#include "gf.h"
#include "str.h"
#include "op.h"
#include "charset.h"
#include "rules.h"

static int set_delim(const char *ref, const char *line, int *delim)
{
    size_t ref_itt = 0;
    size_t start = 0;
    size_t end = 0;

    for (; line[start] && ccharset(line[start], " \t"); start++);
    for (; line[start] && line[start] != ' '; start++, ref_itt++) {
        if (line[start] != ref[ref_itt])
            return ERROR;
    }
    for (; line[start] && line[start] != '"'; start++);
    ASSERT(line[start], ERROR);
    delim[0] = start + 1;
    end = sfindc(line + delim[0], '"');
    if (end == 0) {
        return ERROR;
    }
    delim[1] = delim[0] + end - 2;
    return SUCCESS;
}

static int parse_name(FILE *stream, header_t *header)
{
    const char *ref = NAME_CMD_STRING;
    int delim[2] = {0};
    char *line = NULL;

    line = get_next_line(stream);
    ASSERT(line, ERROR);
    if (set_delim(ref, line, delim) == ERROR
        || delim[1] - delim[0] > PROG_NAME_LENGTH) {
            free(line);
        return ERROR;
    }
    scpy(header->prog_name, line + delim[0]);
    header->prog_name[delim[1] - delim[0] + 1] = '\0';
    free(line);
    return SUCCESS;
}

static int parse_comment(FILE *stream, header_t *header)
{
    const char *ref = COMMENT_CMD_STRING;
    int delim[2] = {0};
    char *line = NULL;

    line = get_next_line(stream);
    ASSERT(line, ERROR);
    if (set_delim(ref, line, delim) == ERROR
        || delim[1] - delim[0] > COMMENT_LENGTH) {
            free(line);
        return ERROR;
    }
    scpy(header->comment, line + delim[0]);
    header->comment[delim[1] - delim[0] + 1] = '\0';
    free(line);
    return SUCCESS;
}

static void clean_header(header_t *header)
{
    size_t i = 0;

    for (; header->prog_name[i]; i++);
    for (i++; i < PROG_NAME_LENGTH + 1; i++) {
        header->prog_name[i] = 0;
    }
    for (i = 0; header->comment[i]; i++);
    for (i++; i < COMMENT_LENGTH + 1; i++) {
        header->comment[i] = 0;
    }
}

int parse_header(FILE *stream, header_t *header)
{
    ASSERT(stream && header, ERROR);
    ASSERT_ERR(parse_name(stream, header), ERROR);
    ASSERT_ERR(parse_comment(stream, header), ERROR);
    clean_header(header);
    return 0;
}
