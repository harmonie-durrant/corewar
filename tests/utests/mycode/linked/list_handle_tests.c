/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** list_handle_test
*/

#include <criterion/criterion.h>
#include "list.h"
#include "str.h"

Test(get_list_start, get_start)
{
    list_t *head = NULL;
    list_t *node = NULL;

    append_to_list(&head, sdup("Hello"));
    append_to_list(&head, sdup("World"));
    append_to_list(&head, sdup("42"));
    node = head->next->next;
    cr_assert_str_eq(node->data, "42");
    node = get_list_start(head);
    cr_assert_not_null(node);
    cr_assert_str_eq(node->data, "Hello");
    destroy_list(&head, free);
}

Test(get_list_end, get_end)
{
    list_t *head = NULL;
    list_t *node = NULL;

    append_to_list(&head, sdup("Hello"));
    append_to_list(&head, sdup("World"));
    append_to_list(&head, sdup("42"));
    node = get_list_end(head);
    cr_assert_not_null(node);
    cr_assert_str_eq(node->data, "42");
    destroy_list(&head, free);
}

Test(pop_list, positive_index)
{
    list_t *head = NULL;
    char *data = NULL;

    append_to_list(&head, sdup("Hello"));
    append_to_list(&head, sdup("World"));
    append_to_list(&head, sdup("42"));
    head = head->next;
    data = pop_list(&head, 1);
    cr_assert_str_eq(data, "42");
    cr_assert_not_null(head);
    cr_assert_str_eq(head->data, "World");
    cr_assert_not_null(head->prev);
    cr_assert_str_eq(head->prev->data, "Hello");
    cr_assert_null(head->next);
    cr_assert_null(head->prev->prev);
    destroy_list(&head, free);
}

Test(pop_list, negative_index)
{
    list_t *head = NULL;
    char *data = NULL;

    append_to_list(&head, sdup("Hello"));
    append_to_list(&head, sdup("World"));
    append_to_list(&head, sdup("42"));
    head = head->next;
    data = pop_list(&head, -1);
    cr_assert_str_eq(data, "Hello");
    cr_assert_not_null(head);
    cr_assert_str_eq(head->data, "World");
    cr_assert_not_null(head->next);
    cr_assert_str_eq(head->next->data, "42");
    cr_assert_null(head->prev);
    cr_assert_null(head->next->next);
    destroy_list(&head, free);
}

Test(pop_list, zero_index)
{
    list_t *head = NULL;
    char *data = NULL;

    append_to_list(&head, sdup("Hello"));
    append_to_list(&head, sdup("World"));
    append_to_list(&head, sdup("42"));
    head = head->next;
    data = pop_list(&head, 0);
    cr_assert_not_null(data);
    cr_assert_str_eq(data, "World");
    cr_assert_not_null(head);
    cr_assert_str_eq(head->data, "42");
    cr_assert_not_null(head->prev);
    cr_assert_str_eq(head->prev->data, "Hello");
    cr_assert_null(head->next);
    cr_assert_null(head->prev->prev);
    destroy_list(&head, free);
}
