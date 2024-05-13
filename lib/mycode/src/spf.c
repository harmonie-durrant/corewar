/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for Str Print Format function
*/

#include "pf.h"

static size_t spf_flags(char *trgt, const char *format, va_list ap)
{
    switch (*format) {
        case 'c': return spchar(trgt, va_arg(ap, int));
        case 's': return spstr(trgt, va_arg(ap, char *));
        case 'i': return spint(trgt, va_arg(ap, int));
        case 'f': return spfloat(trgt, va_arg(ap, double));
        case 'd': return spdouble(trgt, va_arg(ap, double));
        default: return 0;
    }
}

static size_t spf_step(char *trgt, const char *format, va_list ap, size_t *i)
{
    size_t len = 0;

    if (format[*i] == '%') {
        (*i)++;
        len = spf_flags(trgt, format + *i, ap);
    } else {
        if (trgt) {
            *trgt = format[*i];
        }
        len = 1;
    }
    (*i)++;
    return len;
}

/// @brief Prints a formatted string to a target string directly from a va_list
/// @param trgt the target string
/// @param format the format string
/// @param ap the va_list
/// @return the length of the formatted string
size_t vspf(char *trgt, const char *format, va_list ap)
{
    size_t i = 0;
    size_t j = 0;
    char *str = NULL;

    if (!format) {
        return 0;
    }
    while (format[i]) {
        str = trgt ? trgt + j : NULL;
        j += spf_step(str, format, ap, &i);
    }
    if (trgt) {
        trgt[j] = '\0';
    }
    return j;
}

/// @brief Prints a formatted string to a target string
/// @param trgt the target string
/// @param format the format string
/// @param  the arguments
/// @return the length of the formatted string
size_t spf(char *trgt, const char *format, ...)
{
    va_list ap;
    size_t j = 0;

    if (!format) {
        return 0;
    }
    va_start(ap, format);
    j = vspf(trgt, format, ap);
    va_end(ap);
    return j;
}
