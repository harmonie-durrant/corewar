/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** parse_instru_type_tools
*/

#include <stdlib.h>
#include "asm.h"
#include "str.h"
#include "charset.h"
#include "op.h"
#include "rules.h"

instru_type_t get_instru_type(const char *line)
{
    size_t start = 0, end = 0;
    char *name = NULL;

    ASSERT(line, ERR);
    for (; !ccharset(line[start], " \t"); start++);
    for (; ccharset(line[start], " \t"); start++);
    end = start;
    for (; !ccharset(line[end], " \t"); end++);
    name = sdupn(line + start, end - start);
    ASSERT(name, ERR);
    for (size_t i = 0; i < 16; i++) {
        if (sexact(op_tab[i].mnemonique, name)) {
            free(name);
            return i + 1;
        }
    }
    free(name);
    return ERR;
}
