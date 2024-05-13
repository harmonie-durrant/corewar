/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base function not sorted yet
*/

#include <stddef.h>

/// @brief Turn a number into a decimal
/// @param nb Number to turn into a decimal
/// @return Decimal from the number
double make_dec(unsigned int nb)
{
    double dec = (double) nb;

    while ((int) dec) {
        dec /= 10;
    }
    return dec;
}

double dpow(double nb, int pow)
{
    double res = 1;

    if (pow < 0) {
        return 0;
    }
    if (pow == 0) {
        return 1;
    }
    if (pow == 1) {
        return nb;
    }
    for (int i = 0; i < pow; i++) {
        res *= nb;
    }
    return res;
}

size_t spow(size_t nb, size_t pow)
{
    size_t res = 1;

    if (pow == 0) {
        return 1;
    }
    if (pow == 1) {
        return nb;
    }
    for (size_t i = 0; i < pow; i++) {
        res *= nb;
    }
    return res;
}
