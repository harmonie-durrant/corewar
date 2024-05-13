/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base functions
*/

#ifndef BASE_H
    #define BASE_H
    #include <stddef.h>
    #define IS_BETWEEN(x, min, max) ((x) >= (min) && (x) <= (max))

double make_dec(unsigned int nb);
double dpow(double nb, int pow);
size_t spow(size_t nb, size_t pow);
int check_files(int ac, char **av, char *extension);
int check_file(char *filename);

#endif /* !BASE_H */
