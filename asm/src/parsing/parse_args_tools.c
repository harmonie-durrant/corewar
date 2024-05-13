/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** parse_args_tools
*/

#include "asm.h"
#include "str.h"
#include "charset.h"
#include "label.h"
#include "read.h"
#include "rules.h"

static int set_label(void **data, int pos, list_t **lists)
{
    char *str = data[0];
    int *arg = data[1];

    ASSERT(str && arg && lists, ERROR);
    if (!(str[0] == '%' && str[1] == LABEL_CHAR
        && scharset(str + 2, LABEL_CHARS))) {
        return ERROR;
    }
    if (get_label_pos(lists, str + 2, &pos) == SUCCESS) {
        *arg = pos;
        return SUCCESS;
    }
    return ERROR;
}

static int set_arg(char *data, int *arg, args_type_t *type)
{
    ASSERT(data && arg && type, ERROR);
    if (data[0] == 'r' && snum(data + 1)) {
        *arg = stoi(data + 1);
        *type = T_REG;
        return SUCCESS;
    }
    if (data[0] == DIRECT_CHAR && snum(data + 1)) {
        *arg = stoi(data + 1);
        *type = T_DIR;
        return SUCCESS;
    }
    if (snum(data)) {
        *arg = stoi(data);
        *type = T_IND;
        return SUCCESS;
    }
    return ERROR;
}

int set_args(void **data, instru_args_t *args, list_t **lists, int pos)
{
    char *tmp = NULL;
    void *label_data[2] = {0};

    ASSERT(data && args, ERROR);
    for (size_t i = 0; data[i]; i++) {
        tmp = data[i];
        label_data[0] = tmp;
        label_data[1] = &(args->values[i]);
        if (set_label(label_data, pos, lists) == SUCCESS) {
            args->types[i] = T_DIR;
            continue;
        }
        if (set_arg(tmp, &(args->values[i]), &(args->types[i])) == SUCCESS) {
            continue;
        }
        return ERROR;
    }
    return SUCCESS;
}
