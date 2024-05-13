/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for testing strings
*/

#include <stddef.h>
#include <stdbool.h>
#include "char.h"

/// @brief Check if a string is only made of letters
/// @param str String to check
/// @return true if the string is only made of letters, false otherwise
bool salpha(char const *str)
{
    for (size_t i = 0; str[i]; i++) {
        if (!is_alpha(str[i])) {
            return false;
        }
    }
    return true;
}

/// @brief Check if a string is only made of digits
/// @param str String to check
/// @return true if the string is only made of digits, false otherwise
bool snum(char const *str)
{
    for (size_t i = 0; str[i]; i++) {
        if (!is_num(str[i])) {
            return false;
        }
    }
    return true;
}

/// @brief Check if a string is only made of letters and digits
/// @param str String to check
/// @return true if the string is only made of letters and digits, false
/// otherwise
bool salnum(char const *str)
{
    for (size_t i = 0; str[i]; i++) {
        if (!is_alphanum(str[i])) {
            return false;
        }
    }
    return true;
}
