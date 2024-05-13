/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** label_tests
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include "label.h"
#include "str.h"
#include "rules.h"
#include "talloc.h"
#include "list.h"

static int init_sizes(list_t **sizes, size_t line_nb)
{
    ASSERT(sizes, ERROR);
    for (size_t i = 0; i < line_nb; i++) {
        ASSERT_ERR(append_to_list(sizes, int_alloc(1)), ERROR);
    }
    return SUCCESS;
}

Test(label, create_label)
{
    label_t *label = NULL;

    label = create_label(sdup("hello"), 5);
    cr_assert_not_null(label);
    cr_assert_str_eq(label->name, "hello");
    cr_assert_eq(label->index, 5);
    destroy_label(label);
}

Test(label, add_label)
{
    list_t *labels = NULL;
    label_t *curr_label = NULL;

    cr_assert_eq(add_label(&labels, sdup("hello"), 5), 0);
    curr_label = labels->data;
    cr_assert_str_eq(curr_label->name, "hello");
    cr_assert_eq(curr_label->index, 5);
    destroy_list(&labels, (list_callback_t)&destroy_label);
}

Test(label, get_label_pos)
{
    list_t *labels = NULL;
    list_t *sizes = NULL;
    list_t *lists[] = {NULL, NULL};
    int index = 10;

    cr_assert_eq(init_sizes(&sizes, 20), SUCCESS);
    add_label(&labels, sdup("hello"), 5);
    add_label(&labels, sdup("world"), 10);
    lists[0] = labels;
    lists[1] = sizes;
    cr_assert_eq(get_label_pos(lists, "world", &index), 0);
    cr_assert_eq(index, 0);
    cr_assert_eq(get_label_pos(lists, "hello", &index), 0);
    cr_assert_eq(index, 5);
    destroy_list(&labels, (list_callback_t)&destroy_label);
}

Test(scan_labels, pdd_asm_index_from_start)
{
    char *path = "../tests/champions/src/pdd.s";
    FILE *file = fopen(path, "r");
    list_t *labels = NULL;
    list_t *sizes = NULL;
    list_t *lists[] = {NULL, NULL};
    int index = 0;

    cr_assert_eq(init_sizes(&sizes, 20), SUCCESS);
    cr_assert_not_null(file);
    cr_assert_eq(scan_labels(file, &labels), 0);
    cr_assert_not_null(labels);
    lists[0] = labels;
    lists[1] = sizes;
    cr_assert_eq(get_label_pos(lists, "begin", &index), 0);
    cr_assert_eq(index, 2, "begin index is %d\n", index);
    index = 0;
    cr_assert_eq(get_label_pos(lists, "live", &index), 0);
    cr_assert_eq(index, 9, "live index is %d\n", index);
    index = 0;
    cr_assert_eq(get_label_pos(lists, "attack", &index), 0);
    cr_assert_eq(index, 12, "attack index is %d\n", index);
    destroy_list(&labels, (list_callback_t)&destroy_label);
}

Test(scan_labels, pdd_asm_multiple_starts)
{
    char *path = "../tests/champions/src/pdd.s";
    FILE *file = fopen(path, "r");
    list_t *labels = NULL;
    list_t *sizes = NULL;
    list_t *lists[] = {NULL, NULL};
    int index = 2;

    cr_assert_eq(init_sizes(&sizes, 30), SUCCESS);
    cr_assert_not_null(file);
    cr_assert_eq(scan_labels(file, &labels), 0);
    cr_assert_not_null(labels);
    lists[0] = labels;
    lists[1] = sizes;
    cr_assert_eq(get_label_pos(lists, "begin", &index), 0);
    cr_assert_eq(index, 0, "begin index is %d\n", index);
    index = 11;
    cr_assert_eq(get_label_pos(lists, "live", &index), 0);
    cr_assert_eq(index, -2, "live index is %d\n", index);
    index = 18;
    cr_assert_eq(get_label_pos(lists, "attack", &index), 0);
    cr_assert_eq(index, -6, "attack index is %d\n", index);
    destroy_list(&labels, (list_callback_t)&destroy_label);
}
