/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for char testing
*/

#include <stdbool.h>

/// @brief Check if char is a number
/// @param c Char to check
/// @return True if char is a number, false otherwise
bool is_num(char c)
{
    return (c >= '0' && c <= '9');
}

/// @brief Check if char is an uppercase letter
/// @param c Char to check
/// @return True if char is an uppercase letter, false otherwise
bool is_upper(char c)
{
    return (c >= 'A' && c <= 'Z');
}

/// @brief Check if char is a lowercase letter
/// @param c Char to check
/// @return True if char is a lowercase letter, false otherwise
bool is_lower(char c)
{
    return (c >= 'a' && c <= 'z');
}

/// @brief Check if char is a letter
/// @param c Char to check
/// @return True if char is a letter, false otherwise
bool is_alpha(char c)
{
    return (is_upper(c) || is_lower(c));
}

/// @brief Check if char is a letter or a number
/// @param c Char to check
/// @return True if char is a letter or a number, false otherwise
bool is_alphanum(char c)
{
    return (is_alpha(c) || is_num(c));
}
