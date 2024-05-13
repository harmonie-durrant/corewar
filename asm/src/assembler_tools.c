/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** assembler_tools
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "op.h"
#include "str.h"
#include "len.h"
#include "charset.h"
#include "rules.h"

char *get_next_line(FILE *stream)
{
    char *line = NULL;
    int status = 0;
    size_t size = 0;

    ASSERT(stream, NULL);
    status = getline(&line, &size, stream);
    while (status != EOF
        && (!line || sfindc(line, COMMENT_CHAR) || slen(line) <= 1)) {
        free(line);
        line = NULL;
        status = getline(&line, &size, stream);
    }
    if (status == EOF) {
        if (line)
            free(line);
        return NULL;
    }
    line[status - 1] = '\0';
    return line;
}

char *get_sgf_format(size_t size)
{
    size_t i = 0;
    size_t sep_itt = 0;
    char *format = NULL;
    char sep[] = {'%', 's', SEPARATOR_CHAR, '\0'};

    ASSERT(size, NULL);
    format = snew(size * 3, '\0');
    ASSERT(format, NULL);
    while (i < size * 3 - 1) {
        format[i] = sep[sep_itt % 3];
        i++;
        sep_itt++;
    }
    format[(size * 3) - 1] = '\0';
    return format;
}

int get_line_data_start(const char *line)
{
    int i = 0;
    bool instru_flag = false;

    ASSERT(line, -1);
    for (;line[i] && !ccharset(line[i], " \t"); i++);
    while (line[i]) {
        if (!ccharset(line[i], " \t") && !instru_flag) {
            instru_flag = true;
        }
        if (instru_flag && ccharset(line[i], " \t")) {
            break;
        }
        i++;
    }
    for (;line[i] && ccharset(line[i], " \t"); i++);
    ASSERT(line[i], -1);
    return i;
}

void clean_line(char *line)
{
    int i = 0;
    int pos = 0;
    char *tmp = NULL;

    ASSERT(line,);
    while ((pos = sfindc(line, ' '))) {
        tmp = line + (pos - 1);
        for (i = 0; tmp[i + 1] != '\0'; i++) {
            tmp[i] = tmp[i + 1];
        }
        tmp[i] = '\0';
    }
    while ((pos = sfindc(line, '\t'))) {
        tmp = line + (pos - 1);
        for (i = 0; tmp[i + 1] != '\0'; i++) {
            tmp[i] = tmp[i + 1];
        }
        tmp[i] = '\0';
    }
}

char *get_new_filename(const char *filename)
{
    char *new_name = NULL;
    char *new_filename = NULL;
    size_t start = 0, end = 0;

    ASSERT(filename, NULL);
    for (size_t i = 0; filename[i] && filename[i] != '.'; i++) {
        if (filename[i] == '/') {
            start = i + 1;
        }
    }
    ASSERT(filename[start], NULL);
    for (end = start; filename[end] && filename[end] != '.'; end++);
    ASSERT(filename[end], NULL);
    if (end - start <= 0)
        return NULL;
    new_name = sdupn(filename + start, end - start);
    ASSERT(new_name, NULL);
    new_filename = smerge(new_name, ".cor");
    free(new_name);
    return new_filename;
}
