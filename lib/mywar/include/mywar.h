/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** main header for the mywar library
*/

#ifndef MY_WAR_H
    #define MY_WAR_H
    #include <stdbool.h>
    #include "byte.h"

int put_cor_nbr(
    byte_t *buffer, unsigned int nbr, size_t byte_size, bool is_signed);
byte_t *mget(byte_t *mem, size_t midx, size_t len);
int mput(byte_t *mem, size_t midx, byte_t *data, size_t len);

#endif /* !MY_WAR_H */
