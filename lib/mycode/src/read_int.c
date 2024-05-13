/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for reading from strings
*/

#include <stdio.h>
#include "base.h"
#include "char.h"

/// @brief Reaad a unsigned int from a string
/// @param str String to read from
/// @return Unsigned int from the string
unsigned int stoui(const char *str)
{
    unsigned int nb = 0;

    if (!str) {
        return 0;
    }
    while (is_num(*str)) {
        nb *= 10;
        nb += *str - '0';
        str++;
    }
    return nb;
}

/// @brief Read an int from a string
/// @param str String to read from
/// @return Int from the string
int stoi(const char *str)
{
    if (!str) {
        return 0;
    }
    if (*str == '-') {
        return - ((int) stoui(str + 1));
    }
    return (int) stoui(str);
}
