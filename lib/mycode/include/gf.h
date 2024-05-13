/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base string print format functions
*/

#ifndef GF_H
    #define GF_H
    #include <stddef.h>

void *sgf_char(const char *data);
void *sgf_int(const char *data);
void *sgf_float(const char *data);
void *sgf_double(const char *data);

void **sgf(const char *format, const char *data);

#endif /* !GF_H */
