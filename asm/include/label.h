/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** label
*/

#ifndef LABEL_H_
    #define LABEL_H_
    #include <stdio.h>
    #include "list.h"
    #include "instru.h"

typedef struct label_s {
    char *name;
    int index;
} label_t;

label_t *create_label(char *name, int index);
void destroy_label(label_t *label);
int add_label(list_t **labels, char *name, int index);
int get_label_pos(list_t **lists, const char *name, int *pos);
int scan_labels(FILE *stream, list_t **labels);

#endif /* !LABEL_H_ */
