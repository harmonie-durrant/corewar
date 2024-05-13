/*
** EPITECH PROJECT, 2023
** my_list
** File description:
** handle_list
*/

#include <stdlib.h>
#include "list.h"
#include "str.h"
#include "rules.h"

list_t *get_list_start(list_t *head)
{
    list_t *curr = NULL;

    ASSERT(head, NULL);
    curr = head;
    while (curr->prev) {
        curr = curr->prev;
    }
    return curr;
}

list_t *get_list_end(list_t *head)
{
    list_t *curr = NULL;

    ASSERT(head, NULL);
    curr = head;
    while (curr->next) {
        curr = curr->next;
    }
    return curr;
}

void callback_list(list_t *head, list_callback_t callback)
{
    list_t *curr = NULL;

    ASSERT(head && callback,);
    curr = get_list_start(head);
    while (curr) {
        callback(curr->data);
        curr = curr->next;
    }
}

static void handle_zero_index(list_t **head, void **data)
{
    list_t *tmp = NULL;

    *data = (*head)->data;
    if ((*head)->next) {
        (*head)->next->prev = (*head)->prev;
    }
    if ((*head)->prev) {
        (*head)->prev->next = (*head)->next;
    }
    tmp = *head;
    *head = (*head)->next ? (*head)->next : (*head)->prev;
    free(tmp);
}

void *pop_list(list_t **head, int index)
{
    list_t *curr = NULL;
    void *data = NULL;
    int direction = index < 0 ? -1 : 1;

    ASSERT(head && *head, NULL);
    if (index == 0) {
        handle_zero_index(head, &data);
        return data;
    }
    curr = *head;
    for (int i = 0; curr && i != index; i += direction)
        curr = direction < 0 ? curr->prev : curr->next;
    ASSERT(curr, NULL);
    data = curr->data;
    if (curr->next)
        curr->next->prev = curr->prev;
    if (curr->prev)
        curr->prev->next = curr->next;
    free(curr);
    return data;
}
