/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** champ_mem_tools
*/

#include "corewar.h"

void bput(byte_t *mem, size_t midx, byte_t val, size_t len)
{
    size_t i = 0;
    ASSERT(mem,);

    if (midx + len <= MEM_SIZE) {
        for (i = 0; i < len; i++) {
            mem[midx + i] = val;
        }
    } else {
        for (i = 0; i < MEM_SIZE - midx; i++) {
            mem[midx + i] = val;
        }
        for (i = 0; i < len - (MEM_SIZE - midx); i++) {
            mem[i] = val;
        }
    }
}
