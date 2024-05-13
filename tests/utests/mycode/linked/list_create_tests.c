/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** list_create_test
*/

#include <criterion/criterion.h>
#include "list.h"
#include "str.h"

Test(create_list_node, create_list_node_test)
{
    char *str = sdup("Hello World!");
    list_t *node = create_list_node(str);

    cr_assert_str_eq(node->data, "Hello World!");
    cr_assert_null(node->next);
    cr_assert_null(node->prev);
    free(node);
    free(str);
}

Test(destroy_list, node_only)
{
    list_t *head = NULL;
    char *str = sdup("Hello World!");

    head = create_list_node(str);
    destroy_list(&head, free);
    cr_assert_null(head);
}

Test(append_to_list, append)
{
    list_t *head = NULL;

    append_to_list(&head, sdup("Hello"));
    append_to_list(&head, sdup("World"));
    append_to_list(&head, sdup("42"));
    cr_assert_str_eq(head->data, "Hello");
    cr_assert_str_eq(head->next->data, "World");
    cr_assert_str_eq(head->next->next->data, "42");
    cr_assert_null(head->prev);
    cr_assert_null(head->next->next->next);
    destroy_list(&head, free);
}

Test(prepend_to_list, without_prev)
{
    list_t *head = NULL;

    prepend_to_list(&head, sdup("Hello"));
    prepend_to_list(&head, sdup("World"));
    prepend_to_list(&head, sdup("42"));
    cr_assert_str_eq(head->data, "42");
    cr_assert_str_eq(head->next->data, "World");
    cr_assert_str_eq(head->next->next->data, "Hello");
    cr_assert_null(head->prev);
    cr_assert_null(head->next->next->next);
    destroy_list(&head, free);
}

Test(prepend_to_list, with_prev)
{
    list_t *head = NULL;

    append_to_list(&head, sdup("Hello"));
    append_to_list(&head, sdup("World"));
    append_to_list(&head, sdup("42"));
    cr_assert_not_null(head);
    head = head->next;
    prepend_to_list(&head, sdup("Hi"));
    cr_assert_str_eq(head->data, "World");
    cr_assert_not_null(head->next);
    cr_assert_str_eq(head->next->data, "42");
    cr_assert_not_null(head->prev);
    cr_assert_str_eq(head->prev->data, "Hello");
    cr_assert_not_null(head->prev->prev);
    cr_assert_str_eq(head->prev->prev->data, "Hi");
    cr_assert_null(head->next->next);
    cr_assert_null(head->prev->prev->prev);
    destroy_list(&head, free);
}
