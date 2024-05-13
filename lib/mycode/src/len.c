/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for lengths of primitive types
*/

#include <stddef.h>
#include "rules.h"

/// @brief Get length of an unsigned int
/// @param nb Number to get length of
/// @return Length of the number
size_t uilen(unsigned int nb)
{
    size_t len = 0;

    if (!nb) {
        return 1;
    }
    while (nb) {
        nb /= 10;
        len++;
    }
    return len;
}

/// @brief Get length of an int
/// @param nb Number to get length of
/// @return Length of the number
size_t ilen(int nb)
{
    if (nb < 0) {
        return uilen((unsigned int) -nb) + 1;
    }
    return uilen((unsigned int) nb);
}

/// @brief Get length of a float
/// @param nb Number to get length of
/// @return Length of the number
size_t flen(float nb)
{
    size_t len = 0;

    len = ilen((int) nb);
    return len + DEC_DIG + 1;
}

/// @brief Get length of a double
/// @param nb Number to get length of
/// @return Length of the number
size_t dlen(double nb)
{
    size_t len = 0;

    len = ilen((int) nb);
    if (nb < 0 && nb > -1) {
        len++;
    }
    return len + DEC_DIG + 1;
}
