/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for write
*/

#include <unistd.h>
#include "len.h"
#include "rules.h"

/// @brief Write a char to a string
/// @param trgt String to write to
/// @param c Char to write
/// @return Number of char written
size_t spchar(char *trgt, char c)
{
    if (!trgt) {
        return 1;
    }
    trgt[0] = c;
    trgt[1] = '\0';
    return 1;
}

/// @brief Write a string to a string
/// @param trgt String to write to
/// @param str String to write
/// @return Number of char written
size_t spstr(char *trgt, const char *str)
{
    size_t i = 0;

    if (!str) {
        return 0;
    }
    if (!trgt) {
        return slen(str);
    }
    while (str[i]) {
        trgt[i] = str[i];
        i++;
    }
    return i;
}
