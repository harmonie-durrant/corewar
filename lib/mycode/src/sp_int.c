/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for write
*/

#include <unistd.h>
#include "len.h"
#include "rules.h"

/// @brief Write an unsigned int to a string
/// @param trgt String to write to
/// @param nb Unsigned Int to write
/// @return Number of char written
size_t spuint(char *trgt, unsigned int nb)
{
    size_t len = 0;
    size_t i = 0;

    len = uilen(nb);
    if (!trgt) {
        return len;
    }
    len--;
    if (nb == 0) {
        trgt[0] = '0';
        return 1;
    }
    while (nb) {
        trgt[len] = nb % 10 + '0';
        nb /= 10;
        len--;
        i++;
    }
    return i;
}

/// @brief Write an int to a string
/// @param trgt String to write to
/// @param nb Int to write
/// @return Number of char written
size_t spint(char *trgt, int nb)
{
    if (!trgt) {
        return ilen(nb);
    }
    if (nb < 0) {
        trgt[0] = '-';
        return spuint(trgt + 1, -nb) + 1;
    }
    return spuint(trgt, nb);
}
