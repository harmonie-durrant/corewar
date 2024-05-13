/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base macros for rules
*/

#ifndef RULES_H
    #define RULES_H

    // MSG
    #define SUCCESS 0
    #define ERROR 84

    // TEST
    #define ASSERT(x, err) if (!(x)) return err
    #define ASSERT_ERR(x, err) if ((x) == ERROR) return err

    // CONST
    #define MAX_DEC 1e+4
    #define DEC_DIG 4
    #define MIN_DEC 1e-4
    #define RND_LIM 0.5
    #define IMAX 2147483647

    // ATTRIBUTES
    #define UNUSED __attribute__((unused))

#endif /* !RULES_H */
