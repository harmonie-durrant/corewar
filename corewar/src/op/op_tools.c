/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** process_factory
*/

#include "corewar.h"
#include "process.h"
#include "mywar.h"
#include "instru.h"
#include "rules.h"
#include "cbyte.h"
#include "base.h"

int read_ind(byte_t *mem, byte_t size)
{
    int16_t result = 0;
    int i = 0;

    if (size > 4) {
        return 0;
    }
    for (; i < size; i++) {
        result = result << 8;
        result |= mem[i];
    }
    return result;
}

int read_val(byte_t *mem, byte_t size)
{
    int result = 0;
    int i = 0;

    if (size > 4) {
        return 0;
    }
    for (; i < size; i++) {
        result = result << 8;
        result |= mem[i];
    }
    return result;
}

void write_reg(process_t *process, int reg, int value)
{
    ASSERT(REG_VALID(reg),);
    for (int i = REG_SIZE - 1; i >= 0; i--) {
        process->regs[reg - 1][i] = (byte_t) value & 0xFF;
        value = value >> 8;
    }
}

int read_reg(process_t *process, int reg)
{
    int result = 0;

    ASSERT(REG_VALID(reg), 0);
    result = read_val(process->regs[reg - 1], REG_SIZE);
    return result;
}

byte_t *get_op(byte_t *mem, size_t midx)
{
    size_t cbidx = 0;

    ASSERT(mem && midx < MEM_SIZE, NULL);
    ASSERT(mem[midx] && mem[midx] <= AFF, NULL);
    if (HAS_CBYTE(mem[midx])) {
        cbidx = (midx + 1) % MEM_SIZE;
        ASSERT(mem[cbidx], NULL);
    }
    ASSERT(mem_is_valid(mem + cbidx, mem[midx]), NULL);
    return mget(mem, midx, get_mem_size(mem[midx], mem + cbidx));
}
