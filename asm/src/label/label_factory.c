/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** label_factory
*/

#include <stdlib.h>
#include "label.h"
#include "rules.h"

label_t *create_label(char *name, int index)
{
    label_t *label = NULL;

    if (!name || index < 0) {
        return NULL;
    }
    label = malloc(sizeof(label_t));
    ASSERT(label, NULL);
    label->index = index;
    label->name = name;
    return label;
}

void destroy_label(label_t *label)
{
    ASSERT(label,);
    free(label->name);
    free(label);
}
