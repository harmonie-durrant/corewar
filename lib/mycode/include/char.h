/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base char functions
*/

#ifndef CHAR_H
    #define CHAR_H
    #include <stdbool.h>

bool is_num(char c);
bool is_upper(char c);
bool is_lower(char c);
bool is_alpha(char c);
bool is_alphanum(char c);

bool is_print(char c);
bool is_blank(char c);
bool is_space(char c);

#endif /* !CHAR_H */
