/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for Str Print Format function
*/

#include <stddef.h>
#include "talloc.h"
#include "read.h"

/// @brief Allocate a char from a string
/// @param data String to read from
/// @return Allocated char
void *sgf_char(const char *data)
{
    char *c = NULL;

    if (!data) {
        return NULL;
    }
    c = char_alloc(*data);
    return c;
}

/// @brief Allocate an int from a string
/// @param data String to read from
/// @return Allocated int
void *sgf_int(const char *data)
{
    int *i = NULL;

    if (!data) {
        return NULL;
    }
    i = int_alloc(stoi(data));
    return i;
}

/// @brief Allocate a float from a string
/// @param data String to read from
/// @return Allocated float
void *sgf_float(const char *data)
{
    float *f = NULL;

    if (!data) {
        return NULL;
    }
    f = float_alloc(stof(data));
    return f;
}

/// @brief Allocate a double from a string
/// @param data String to read from
/// @return Allocated double
void *sgf_double(const char *data)
{
    double *d = NULL;

    if (!data) {
        return NULL;
    }
    d = double_alloc(stod(data));
    return d;
}
