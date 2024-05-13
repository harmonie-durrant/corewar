/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** label_scanner
*/

#include <stdlib.h>
#include <stdbool.h>
#include "op.h"
#include "label.h"
#include "str.h"
#include "charset.h"
#include "rules.h"
#include "asm.h"

static char *get_label(const char *line)
{
    int end = 0;
    char *name = NULL;

    end = sfindc(line, LABEL_CHAR);
    if (end == 0) {
        return NULL;
    }
    name = sdupn(line, end - 1);
    ASSERT(name, NULL);
    if (scharset(name, LABEL_CHARS)) {
        return name;
    }
    free(name);
    return NULL;
}

static void free_buf(char **buf)
{
    ASSERT(buf && *buf,);
    free(*buf);
    *buf = NULL;
}

static int handle_adding(char **buffers, list_t **labels,
list_t **queue, int *index)
{
    char *buf = buffers[0];
    char *label_buf = buffers[1];
    char *tmp = NULL;

    if (label_buf && append_to_list(queue, label_buf) == ERROR) {
        free(label_buf);
        destroy_list(queue, free);
        return ERROR;
    }
    if (line_is_empty(buf)) {
        return 1;
    }
    while ((tmp = pop_list(queue, 0))) {
        ASSERT_ERR(add_label(labels, tmp, *index), ERROR);
    }
    return SUCCESS;
}

static void handle_status(list_t *queue, int *status)
{
    if (queue) {
        *status = ERROR;
        destroy_list(&queue, free);
    }
}

int scan_labels(FILE *stream, list_t **labels)
{
    int i = 0, status = SUCCESS;
    char *buf = NULL, *label = NULL;
    list_t *queue = NULL;

    ASSERT(stream && labels, ERROR);
    ASSERT_ERR(set_start(stream), ERROR);
    while ((buf = get_next_line(stream))) {
        label = get_label(buf);
        status = handle_adding((char*[]){buf, label}, labels, &queue, &i);
        free_buf(&buf);
        if (status == ERROR)
            break;
        if (status != 1)
            i++;
    }
    handle_status(queue, &status);
    fseek(stream, 0, SEEK_SET);
    return status;
}
