/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base string print format functions
*/

#ifndef PF_H
    #define PF_H
    #include <stdarg.h>
    #include <stddef.h>

size_t spchar(char *trgt, char c);
size_t spstr(char *trgt, const char *str);
size_t spuint(char *trgt, unsigned int nb);
size_t spint(char *trgt, int nb);
size_t spfloat(char *trgt, float nb);
size_t spdouble(char *trgt, double nb);

size_t spf(char *trgt, const char *format, ...);
size_t vspf(char *trgt, const char *format, va_list ap);
void fpf(int fd, const char *format, ...);
void opf(const char *format, ...);
void epf(const char *format, ...);
char *vquicks(const char *format, va_list ap, va_list ap_cp);
char *quicks(const char *format, ...);
#endif /* !PF_H */
