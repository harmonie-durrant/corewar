/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for string lengths
*/

#include <stddef.h>

/// @brief Get the length of a string
/// @param str String to get length of
/// @return Length of the string
size_t slen(const char *str)
{
    size_t len = 0;

    if (!str) {
        return 0;
    }
    if (str[0] == '\0') {
        return 1;
    }
    while (str[len++]);
    return len - 1;
}
