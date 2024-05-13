/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for making strings
*/

#include <stdlib.h>
#include "len.h"
#include "str.h"

/// @brief Make a new string
/// @param len Length of the string
/// @return New string
char *snew(size_t len, char c)
{
    char *str = NULL;

    str = malloc(len + 1);
    if (!str) {
        return NULL;
    }
    for (size_t i = 0; i < len; i++) {
        str[i] = c;
    }
    str[len] = '\0';
    return str;
}

/// @brief Free a string
/// @param str String to free
/// @return 0 on success, 84 on error
int sfree(char **str)
{
    if (!str || !*str) {
        return 84;
    }
    free(*str);
    *str = NULL;
    return 0;
}

/// @brief Duplicate a string
/// @param str String to duplicate
/// @return New string
char *sdup(const char *str)
{
    size_t i = 0;
    char *dup = NULL;

    dup = malloc(slen(str) + 1);
    if (!dup) {
        return NULL;
    }
    while (str[i]) {
        dup[i] = str[i];
        i++;
    }
    dup[i] = '\0';
    return dup;
}

/// @brief Duplicate a string
/// @param str String to duplicate
/// @param n Number of char to duplicate
/// @return New string
char *sdupn(const char *str, size_t n)
{
    size_t i = 0;
    char *dup = NULL;

    dup = malloc(n + 1);
    if (!dup) {
        return NULL;
    }
    while (n - i && str[i]) {
        dup[i] = str[i];
        i++;
    }
    dup[n] = '\0';
    return dup;
}

/// @brief Merge two strings
/// @param s1 First string
/// @param s2 Second string
/// @return New string
char *smerge(const char *s1, const char *s2)
{
    char *str = NULL;
    size_t len1 = 0;
    size_t len2 = 0;

    if (!s1 && !s2) {
        return NULL;
    }
    if (!s1 || !s2) {
        return sdup(s1 ? s1 : s2);
    }
    len1 = slen(s1);
    len2 = slen(s2);
    str = snew(len1 + len2, ' ');
    if (!str) {
        return NULL;
    }
    scpy(str, s1);
    scpy(str + len1, s2);
    str[len1 + len2] = '\0';
    return str;
}
