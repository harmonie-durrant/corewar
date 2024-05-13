/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base len functions
*/

#ifndef LEN_H
    #define LEN_H
    #include <stddef.h>

size_t uilen(unsigned int nb);
size_t ilen(int nb);
size_t flen(float nb);
size_t dlen(double nb);
size_t slen(const char *str);

#endif /* !LEN_H */
