/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for string changes
*/

#include <stdlib.h>
#include "str.h"
#include "len.h"
#include "pf.h"

/// @brief Swap all occurences of a char in a string
/// @param str The string to modify
/// @param c1 char to replace
/// @param c2 char to replace with
void sswapc(char *str, char c1, char c2)
{
    if (!str) {
        return;
    }
    while (*str) {
        if (*str == c1) {
            *str = c2;
        }
        str++;
    }
}

/// @brief Swap all occurences of a string in a string
/// @param str The string to modify
/// @param s1 string to replace
/// @param s2 string to replace with
void sswaps(char *str, const char *s1, const char *s2)
{
    char *tmp = NULL;
    size_t len1 = 0, len2 = 0, next = 0, left = 0;

    if (!str || !s1 || !s2)
        return;
    next = sfind(str, s1);
    if (next == 0)
        return;
    tmp = str + next - 1;
    len1 = slen(s1); len2 = slen(s2);
    while (next != 0) {
        if (len1 != len2) {
            left = slen(tmp + len1);
            scpy(tmp + len2, tmp + len1);
            *(tmp + len2 + left) = '\0';
        }
        scpy(tmp, s2);
        next = sfind(tmp + len2, s1);
        tmp += len2 + next - 1;
    }
}

/// @brief split a string into a table of string
/// @param str string to split
/// @param delim delimiter
/// @return table of string
char **sslice(char *str, const char *delim)
{
    char **tab = NULL;
    char *tmp = str;
    size_t len = 0, i = 0;
    const char sep[2] = {-1, '\0'};

    if (!str || !delim)
        return NULL;
    len = scount(str, delim);
    tab = malloc(sizeof(char *) * (len + 2));
    if (!tab)
        return NULL;
    sswaps(str, delim, sep);
    sswapc(str, sep[0], '\0');
    while (i < len + 1) {
        tab[i] = tmp;
        tmp += slen(tmp) + 1;
        i++;
    }
    tab[i] = NULL;
    return tab;
}
