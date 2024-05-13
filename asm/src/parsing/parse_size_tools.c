/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** parse_size_tools
*/

#include <stdlib.h>
#include "asm.h"
#include "rules.h"
#include "talloc.h"
#include "str.h"
#include "charset.h"
#include "cbyte.h"

int set_start(FILE *stream)
{
    char *line = NULL;

    line = get_next_line(stream);
    ASSERT(line, ERROR);
    free(line);
    line = get_next_line(stream);
    ASSERT(line, ERROR);
    free(line);
    return SUCCESS;
}

static int set_arg(char *data, args_type_t *type)
{
    ASSERT(data && type, ERROR);
    if (data[0] == 'r' && snum(data + 1)) {
        *type = T_REG;
        return SUCCESS;
    }
    if (data[0] == DIRECT_CHAR && snum(data + 1)) {
        *type = T_DIR;
        return SUCCESS;
    }
    if (data[0] == '%' && data[1] == LABEL_CHAR
        && scharset(data + 2, LABEL_CHARS)) {
        *type = T_DIR;
        return SUCCESS;
    }
    if (snum(data)) {
        *type = T_IND;
        return SUCCESS;
    }
    return ERROR;
}

static void **get_data(char *line, instru_type_t *type, list_t **sizes)
{
    ASSERT(line && type && sizes, NULL);
    *type = get_instru_type(line);
    ASSERT(*type != ERR && *type != MTY, NULL);
    return get_line_data(line);
}

static int set_args_sizes(char *line, list_t **sizes)
{
    void **data = NULL;
    size_t size = 0;
    args_type_t types[MAX_ARGS_NUMBER] = {0};
    instru_type_t instru_type = 0;

    data = get_data(line, &instru_type, sizes);
    ASSERT(data, ERROR);
    for (size_t i = 0; i < MAX_ARGS_NUMBER && data[i]; i++) {
        if (set_arg(data[i], &(types[i])) == ERROR) {
            free_data(data);
            return ERROR;
        }
    }
    free_data(data);
    size = get_data_size(instru_type, types) + 1;
    size += HAS_CBYTE(instru_type) ? get_cbyte_size() : 0;
    ASSERT_ERR(append_to_list(sizes, int_alloc(size)), ERROR);
    return SUCCESS;
}

int parse_instructions_sizes(FILE *stream, list_t **sizes)
{
    char *line = NULL;

    ASSERT(stream && sizes, ERROR);
    ASSERT_ERR(set_start(stream), ERROR);
    for (size_t i = 0; (line = get_next_line(stream)); i++) {
        if (line_is_empty(line)) {
            free(line);
            continue;
        }
        if (set_args_sizes(line, sizes) == ERROR) {
            free(line);
            destroy_list(sizes, free);
            return ERROR;
        }
    }
    fseek(stream, 0, SEEK_SET);
    return SUCCESS;
}
