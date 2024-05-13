/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Write binary in big endian
*/

#include <stdlib.h> // malloc
#include <stdbool.h>
#include "byte.h" // byte_t
#include "rules.h"
#include "base.h"

/// @brief Check if the buffer is valid
/// @param buffer Buffer to write in
/// @param byte_size Size of the number in byte
/// @return
static int check_cor_handle(int nbr, size_t byte_size, bool is_signed)
{
    int64_t max_val = 1;

    ASSERT(IS_BETWEEN(byte_size, 1, 8), ERROR);
    for (size_t i = 0; i < byte_size; i++) {
        max_val *= 256;
    }
    nbr = nbr < 0 ? -nbr : nbr;
    max_val = is_signed ? max_val / 2 : max_val;
    ASSERT(nbr < max_val, ERROR);
    return SUCCESS;
}

/// @brief Write binary (hexa) in big endian
/// @param buffer Buffer to write in
/// @param nbr Number to write
/// @param byte_size Size of the number in byte
/// @return
int put_cor_nbr(byte_t *buffer, int nbr, size_t byte_size, bool is_signed)
{
    ASSERT_ERR(check_cor_handle(nbr, byte_size, is_signed), ERROR);
    for (size_t i = 0; i < byte_size; i++) {
        buffer[i] = nbr >> (8 * (byte_size - i - 1)) & 0xFF;
    }
    return SUCCESS;
}
