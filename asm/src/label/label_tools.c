/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** label_tools
*/

#include <stdlib.h>
#include "str.h"
#include "label.h"
#include "rules.h"
#include "asm.h"
#include "charset.h"

bool line_is_empty(char *line)
{
    size_t i = 0;

    ASSERT(line, false);
    for (; line[i] && ccharset(line[i], " \t"); i++);
    for (; line[i] && line[i] != LABEL_CHAR; i++) {
        if (!ccharset(line[i], LABEL_CHARS)) {
            return false;
        }
    }
    for (i++; line[i] && ccharset(line[i], " \t"); i++);
    return line[i] == '\0';
}

int add_label(list_t **labels, char *name, int index)
{
    label_t *new = NULL;

    ASSERT(labels && name, ERROR);
    new = create_label(name, index);
    ASSERT(new, ERROR);
    if (prepend_to_list(labels, new) == ERROR) {
        destroy_label(new);
        return ERROR;
    }
    return SUCCESS;
}

int get_label_pos(list_t **lists, const char *name, int *pos)
{
    list_t *sizes = NULL;
    int new_pos = 0;
    list_t *curr = NULL;
    label_t *curr_label = NULL;

    ASSERT(lists && name && pos, ERROR);
    curr = lists[0];
    sizes = lists[1];
    curr_label = curr->data;
    while (curr && !sequal(curr_label->name, name)) {
        curr = curr->next;
        if (curr) {
            curr_label = curr->data;
        }
    }
    ASSERT(curr, ERROR);
    new_pos = curr_label->index - *pos;
    return set_lines_offset(sizes, (int[]){*pos, *pos + new_pos}, pos);
}
