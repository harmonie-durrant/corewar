/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** main header for the mywar library
*/

#ifndef CBYTE_H
    #define CBYTE_H
    #include <stddef.h>
    #include "byte.h"
    #include "op.h"

byte_t get_cbyte_val_at(byte_t b, int pos);
size_t get_cbyte_size(void);
byte_t *make_cbyte(const args_type_t *types);

#endif /* !CBYTE_H */
