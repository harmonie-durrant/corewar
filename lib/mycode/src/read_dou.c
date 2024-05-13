/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for reading from strings
*/

#include <stdio.h>
#include "base.h"
#include "char.h"

/// @brief Read an "unsigned" float from a string (will stop if start with '-')
/// @param str String to read from
/// @return Float from the string
float stouf(const char *str)
{
    float nb = 0.0f;
    size_t digits = 0;
    size_t point = 0;

    if (!str) {
        return 0;
    }
    while (is_num(*str)) {
        nb = nb * 10.0f + *str - '0';
        str++;
        digits++;
        if (*str == '.') {
            point = digits;
            str++;
        }
    }
    if (point == 0) {
        return nb;
    }
    return nb / (float) spow(10, digits - point);
}

/// @brief Read a float from a string
/// @param str String to read from
/// @return Float from the string
float stof(const char *str)
{
    if (!str) {
        return 0;
    }
    if (*str == '-') {
        return -stouf(str + 1);
    }
    return stouf(str);
}

/// @brief Read an "unsigned" double from a string (will stop if start with '-')
/// @param str String to read from
/// @return Double from the string
double stoud(const char *str)
{
    double nb = 0.0;
    size_t digits = 0;
    size_t point = 0;

    if (!str) {
        return 0;
    }
    while (is_num(*str)) {
        nb = nb * 10.0 + *str - '0';
        str++;
        digits++;
        if (*str == '.') {
            point = digits;
            str++;
        }
    }
    if (point == 0) {
        return nb;
    }
    return nb / (double) spow(10, digits - point);
}

/// @brief Read a double from a string
/// @param str String to read from
/// @return Double from the string
double stod(const char *str)
{
    if (!str) {
        return 0;
    }
    if (*str == '-') {
        return -stoud(str + 1);
    }
    return stoud(str);
}
