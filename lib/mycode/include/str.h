/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Prototype for string functions
*/

#ifndef STR_H
    #define STR_H
    #include <stddef.h>
    #include <stdbool.h>

char *snew(size_t len, char c);
int sfree(char **str);

char *sdup(const char *str);
char *sdupn(const char *str, size_t n);
char *smerge(const char *s1, const char *s2);

void scpy(char *trgt, const char *src);
void scpyn(char *trgt, const char *src, size_t n);

bool sequal(const char *str1, const char *str2);
bool sexact(const char *str1, const char *str2);

size_t sfind(const char *str, const char *to_find);
size_t sfindc(const char *str, char c);
size_t scount(const char *str, const char *to_find);

void sswapc(char *str, char c1, char c2);
void sswaps(char *str, const char *s1, const char *s2);

char **sslice(char *str, const char *delim);

char *ftos(int fd);

bool salpha(char const *str);
bool snum(char const *str);
bool salnum(char const *str);

#endif /* !STR_H */
