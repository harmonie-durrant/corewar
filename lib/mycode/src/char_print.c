/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for char testing
*/

#include <stdbool.h>

/// @brief Check if char is printable
/// @param c Char to check
/// @return True if char is a printable, false otherwise
bool is_print(char c)
{
    return (c >= ' ' && c <= '~');
}

/// @brief Check if char is a blank
/// @param c Char to check
/// @return True if char is a blank, false otherwise
bool is_blank(char c)
{
    return (c == ' ' || c == '\t');
}

/// @brief Check if char is a space
/// @param c Char to check
/// @return True if char is a space, false otherwise
bool is_space(char c)
{
    return (is_blank(c) || c == '\n');
}
