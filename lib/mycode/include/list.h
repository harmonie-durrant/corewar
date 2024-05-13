/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** list
*/

#ifndef LIST_H_
    #define LIST_H_

    typedef struct list_s {
        void *data;
        struct list_s *prev;
        struct list_s *next;
    } list_t;

    typedef void (*list_callback_t)(void *);

list_t *create_list_node(void *data);
void destroy_list(list_t **head, list_callback_t destroy);
int append_to_list(list_t **head, void *data);
int prepend_to_list(list_t **head, void *data);
int insert_to_list(list_t **head, void *data);

list_t *get_list_start(list_t *head);
list_t *get_list_end(list_t *head);
void callback_list(list_t *head, list_callback_t callback);
void *pop_list(list_t **head, int index);

#endif /* !LIST_H_ */
