/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for write binary in big endian
*/

#include <criterion/criterion.h>
#include "mywar.h"
#include "op.h"

Test(put_cor_nbr, test_put_cor_nbr)
{
    int nbr = 0xc49a;
    size_t buffer_size = DIR_SIZE;
    byte_t *buffer = malloc(buffer_size);

    put_cor_nbr(buffer, nbr, buffer_size, true);
    for (size_t i = 0; i < buffer_size; i++)
        cr_expect_eq(buffer[i], 0xc49a >> (8 * (buffer_size - i - 1))
            & 0xFF, "buffer[%ld] = %d", i, buffer[i]);
    free(buffer);
}
