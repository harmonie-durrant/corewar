/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for string search
*/

#include <stdbool.h>
#include "len.h"

/// @brief Check if two strings are exactly the same
/// they must be the same length
/// @param str1 First string to compare
/// @param str2 Second string to compare
/// @return True if strings are the exact same, false otherwise
bool sexact(const char *str1, const char *str2)
{
    size_t i = 0;

    if (!str1 && !str2) {
        return true;
    }
    if (!str1 || !str2) {
        return false;
    }
    while (str1[i] && str2[i]) {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return str1[i] == str2[i];
}

/// @brief Check if two strings are equal until the end of one of them
/// @param str1 First string to compare
/// @param str2 Second string to compare
/// @return True if strings are equal, false otherwise
bool sequal(const char *str1, const char *str2)
{
    size_t i = 0;

    if (!str1 && !str2) {
        return true;
    }
    if (!str1 || !str2) {
        return false;
    }
    while (str1[i] && str2[i]) {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return true;
}

/// @brief Find a string in another string
/// @param str String to search in
/// @param to_find String to search for
/// @return Index + 1 of the first char of the string to find, 0 if not found
size_t sfind(const char *str, const char *to_find)
{
    size_t i = 0;

    if (!str || !to_find) {
        return 0;
    }
    while (str[i]) {
        if (sequal(str + i, to_find)) {
            return i + 1;
        }
        i++;
    }
    return 0;
}

/// @brief Find a char in a string
/// @param str String to search in
/// @param c Char to search for
/// @return Index + 1 of the char, 0 if not found
size_t sfindc(const char *str, char c)
{
    const char tmp[2] = {c, '\0'};

    return sfind(str, tmp);
}

/// @brief Count the number of occurences of a string in another string
/// @param str String to search in
/// @param to_find String to search for
/// @return Number of occurences
size_t scount(const char *str, const char *to_find)
{
    size_t count = 0;
    const char *tmp = NULL;
    size_t len = 0;
    size_t next = 0;

    if (!str || !to_find) {
        return 0;
    }
    next = sfind(str, to_find);
    if (next == 0) {
        return 0;
    }
    tmp = str + next;
    len = slen(to_find);
    while (next != 0) {
        count++;
        next = sfind(tmp + len, to_find);
        tmp += next + len;
    }
    return count;
}
