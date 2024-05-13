/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for string testing
*/

#include "char.h"

/// @brief Check if char is inside a given set of characters
/// @param c Char to check
/// @param charset String of characters to check
/// @return True if char is inside charset, false otherwise
bool ccharset(char c, const char *charset)
{
    if (!charset) {
        return false;
    }
    for (int i = 0; charset[i]; i++) {
        if (c == charset[i]) {
            return true;
        }
    }
    return false;
}

/// @brief Check if string is only made of a given set of characters
/// @param str String to check
/// @param charset String of characters to check
/// @return True if string is only made of characters from charset,
/// false otherwise
bool scharset(const char *str, const char *charset)
{
    if (!str || !charset) {
        return false;
    }
    for (int i = 0; str[i]; i++) {
        if (!ccharset(str[i], charset)) {
            return false;
        }
    }
    return true;
}
