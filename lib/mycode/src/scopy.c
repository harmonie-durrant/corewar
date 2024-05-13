/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for copying strings
*/

#include <stdlib.h>

/// @brief Copy a string
/// @param trgt string to copy to
/// @param src string to copy from
void scpy(char *trgt, const char *src)
{
    size_t i = 0;

    if (!trgt || !src) {
        return;
    }
    while (src[i] && trgt[i]) {
        trgt[i] = src[i];
        i++;
    }
}

/// @brief Copy a string
/// @param trgt string to copy to
/// @param src string to copy from
/// @param n number of char to copy
void scpyn(char *trgt, const char *src, size_t n)
{
    size_t i = 0;

    if (!trgt || !src) {
        return;
    }
    while (n - i && src[i] && trgt[i]) {
        trgt[i] = src[i];
        i++;
    }
}
