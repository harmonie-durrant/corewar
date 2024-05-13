/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** parse_instructions_tools
*/

#include <stdlib.h>
#include <stdio.h>
#include "asm.h"
#include "str.h"
#include "gf.h"
#include "label.h"
#include "rules.h"

void free_data(void **data)
{
    ASSERT(data,);
    for (int i = 0; data[i]; i++) {
        free(data[i]);
    }
    free(data);
}

void **get_line_data(char *line)
{
    char *format = NULL;
    void **data = NULL;
    int arg_len = 0;
    int start = 0;

    start = get_line_data_start(line);
    ASSERT(start != -1, NULL);
    clean_line(line + start);
    arg_len = scount(line + start, (char[]){SEPARATOR_CHAR, '\0'});
    format = get_sgf_format(arg_len + 1);
    ASSERT(format, NULL);
    data = sgf(format, line + start);
    free(format);
    free(line);
    return data;
}

int parse_instru_line(char *line, instru_t *instru,
list_t **lists, int pos)
{
    instru_args_t args = {0};
    void **data = NULL;
    int status = 0;
    instru_type_t type = 0;

    type = get_instru_type(line);
    ASSERT(type != ERR, ERROR);
    data = get_line_data(line);
    ASSERT(data, ERROR);
    status = set_args(data, &args, lists, pos);
    free_data(data);
    ASSERT_ERR(status, ERROR);
    status = set_instru_from_asm(instru, type, args.types, args.values);
    ASSERT_ERR(status, ERROR);
    return SUCCESS;
}

static int add_instru(char *line, list_t **instructions,
list_t **lists, int pos)
{
    instru_t *instru = NULL;
    int status = 0;

    ASSERT(line, ERROR);
    if (line_is_empty(line)) {
        free(line);
        return 1;
    }
    if ((instru = create_instru()) == NULL) {
        free(line);
        return ERROR;
    }
    status = parse_instru_line(line, instru, lists, pos);
    ASSERT_ERR(status, ERROR);
    if (append_to_list(instructions, instru) == ERROR) {
        destroy_instru(instru);
        return ERROR;
    }
    return SUCCESS;
}

int parse_instructions(FILE *stream, list_t **instructions,
list_t **labels, list_t **sizes)
{
    char *line = NULL;
    int pos = 0;
    list_t *lists[] = {NULL, NULL};
    int status = 0;

    ASSERT(stream && instructions && labels && sizes, ERROR);
    lists[0] = *labels;
    lists[1] = *sizes;
    while ((line = get_next_line(stream))) {
        status = add_instru(line, instructions, lists, pos);
        if (status == ERROR) {
            destroy_list(labels, (list_callback_t)&destroy_label);
            destroy_list(instructions, &free);
            destroy_list(sizes, &free);
            return ERROR;
        }
        if (status == SUCCESS)
            pos++;
    }
    return SUCCESS;
}
