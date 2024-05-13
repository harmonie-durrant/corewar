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

char *vquicks(const char *format, va_list ap, va_list ap_cp)
{
    char *str = NULL;

    if (!format) {
        return NULL;
    }
    str = snew(vspf(NULL, format, ap), ' ');
    if (!str) {
        return NULL;
    }
    (void) vspf(str, format, ap_cp);
    return str;
}

char *quicks(const char *format, ...)
{
    va_list ap;
    va_list ap_cp;
    char *str = NULL;

    if (!format) {
        return NULL;
    }
    va_start(ap, format);
    va_copy(ap_cp, ap);
    va_start(ap_cp, format);
    str = vquicks(format, ap, ap_cp);
    va_end(ap);
    va_end(ap_cp);
    return str;
}
