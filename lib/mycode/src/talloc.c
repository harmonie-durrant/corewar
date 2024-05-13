/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for allocation of primitives
*/

#include <stdlib.h>

/// @brief Allocate a char
/// @param ch Char to allocate
/// @return Allocated char
char *char_alloc(char ch)
{
    char *c = malloc(sizeof(char));

    if (!c) {
        return NULL;
    }
    *c = ch;
    return c;
}

/// @brief Allocate an int
/// @param nb Int to allocate
/// @return Allocated int
int *int_alloc(int nb)
{
    int *i = malloc(sizeof(int));

    if (!i) {
        return NULL;
    }
    *i = nb;
    return i;
}

/// @brief Allocate a float
/// @param nb Float to allocate
/// @return Allocated float
float *float_alloc(float nb)
{
    float *f = malloc(sizeof(float));

    if (!f) {
        return NULL;
    }
    *f = nb;
    return f;
}

/// @brief Allocate a double
/// @param nb Double to allocate
/// @return Allocated double
double *double_alloc(double nb)
{
    double *d = malloc(sizeof(double));

    if (!d) {
        return NULL;
    }
    *d = nb;
    return d;
}
