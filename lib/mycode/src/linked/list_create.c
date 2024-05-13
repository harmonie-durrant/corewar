/*
** EPITECH PROJECT, 2023
** my_list
** File description:
** create_list
*/

#include <stdlib.h>
#include "list.h"
#include "str.h"
#include "rules.h"

list_t *create_list_node(void *data)
{
    list_t *node = NULL;

    node = malloc(sizeof(list_t));
    ASSERT(node, NULL);
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void destroy_list(list_t **head, list_callback_t destroy)
{
    list_t *curr = NULL;
    list_t *tmp = NULL;

    ASSERT(head && *head,);
    curr = get_list_start(*head);
    ASSERT(curr,);
    while (curr) {
        tmp = curr;
        if (destroy) {
            destroy(tmp->data);
        }
        curr = curr->next;
        free(tmp);
    }
    *head = NULL;
}

int append_to_list(list_t **head, void *data)
{
    list_t *curr = NULL;
    list_t *node = NULL;

    ASSERT(head, ERROR);
    node = create_list_node(data);
    ASSERT(node, ERROR);
    if (!*head) {
        *head = node;
        return SUCCESS;
    }
    curr = get_list_end(*head);
    curr->next = node;
    node->prev = curr;
    return SUCCESS;
}

int prepend_to_list(list_t **head, void *data)
{
    list_t *curr = NULL;
    list_t *node = NULL;

    ASSERT(head, ERROR);
    node = create_list_node(data);
    ASSERT(node, ERROR);
    if (!*head) {
        *head = node;
        return SUCCESS;
    }
    curr = get_list_start(*head);
    curr->prev = node;
    node->next = curr;
    if (curr == *head) {
        *head = node;
    }
    return SUCCESS;
}

int insert_to_list(list_t **head, void *data)
{
    list_t *node = NULL;

    ASSERT(head, ERROR);
    node = create_list_node(data);
    ASSERT(node, ERROR);
    if (!*head) {
        *head = node;
        return SUCCESS;
    }
    node->next = *head;
    node->prev = (*head)->prev;
    (*head)->prev = node;
    *head = node;
    return SUCCESS;
}
