/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** size_tools
*/

#include "rules.h"
#include "asm.h"
#include "cbyte.h"

static int get_size_to_line(list_t *sizes, int line)
{
    list_t *curr = sizes;
    int size = 0;

    for (int i = 0; i < line; i++) {
        size += *(int *)curr->data;
        curr = curr->next;
    }
    return size;
}

int set_lines_offset(list_t *sizes, int *delim, int *offset)
{
    int mul = 1;
    int start = 0;
    int end = 0;
    int start_size = 0;
    int end_size = 0;

    ASSERT(sizes && delim && offset, ERROR);
    if (delim[0] > delim[1]) {
        mul = -1;
        start = delim[1];
        end = delim[0];
    } else {
        start = delim[0];
        end = delim[1];
    }
    start_size = get_size_to_line(sizes, start);
    end_size = get_size_to_line(sizes, end);
    *offset = (end_size - start_size) * mul;
    return SUCCESS;
}
