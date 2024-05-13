/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function for Str Print Format function
*/

#include <stdlib.h>
#include <unistd.h>
#include "len.h"
#include "pf.h"
#include "str.h"

void vfpf(int fd, const char *format, va_list ap, va_list ap_cp)
{
    char *str = NULL;

    if (!format) {
        return;
    }
    str = vquicks(format, ap, ap_cp);
    if (!str) {
        return;
    }
    write(fd, str, slen(str));
    sfree(&str);
}

/// @brief Prints a formatted string to a file descriptor
/// @param fd the file descriptor
/// @param format the format string
/// @param  the arguments
void fpf(int fd, const char *format, ...)
{
    va_list ap;
    va_list ap_cp;

    if (!format) {
        return;
    }
    va_start(ap, format);
    va_copy(ap_cp, ap);
    va_start(ap_cp, format);
    vfpf(fd, format, ap, ap_cp);
    va_end(ap);
    va_end(ap_cp);
}

/// @brief Prints a formatted string to stdout
/// @param format the format string
/// @param  the arguments
void opf(const char *format, ...)
{
    va_list ap;
    va_list ap_cp;

    if (!format) {
        return;
    }
    va_start(ap, format);
    va_copy(ap_cp, ap);
    va_start(ap_cp, format);
    vfpf(1, format, ap, ap_cp);
    va_end(ap);
    va_end(ap_cp);
}

/// @brief Prints a formatted string to stderr
/// @param format the format string
/// @param  the arguments
void epf(const char *format, ...)
{
    va_list ap;
    va_list ap_cp;

    if (!format) {
        return;
    }
    va_start(ap, format);
    va_copy(ap_cp, ap);
    va_start(ap_cp, format);
    vfpf(2, format, ap, ap_cp);
    va_end(ap);
    va_end(ap_cp);
}
