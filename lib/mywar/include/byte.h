/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** main header for byte related functions
*/

#ifndef BYTE_H
    #define BYTE_H
    #define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) \
| (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))
    #include <stdint.h>

typedef uint8_t byte_t;

#endif /* !BYTE_H */
