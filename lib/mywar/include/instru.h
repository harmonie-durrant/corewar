/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** Header for the instruction struct
*/

#ifndef INSTRU_H
    #define INSTRU_H
    #define HAS_CBYTE(x) (x != LIVE && x != ZJMP && x != FORK && x != LFORK)
    #include <stddef.h>
    #include <stdbool.h>
    #include "byte.h"
    #include "op.h"

typedef enum instru_type_e {
    MTY = 0x00,
    LIVE = 0x01,
    LD = 0x02,
    ST = 0x03,
    ADD = 0x04,
    SUB = 0x05,
    AND = 0x06,
    OR = 0x07,
    XOR = 0x08,
    ZJMP = 0x09,
    LDI = 0x0a,
    STI = 0x0b,
    FORK = 0x0c,
    LLD = 0x0d,
    LLDI = 0x0e,
    LFORK = 0x0f,
    AFF = 0x10,
    ERR = 0x11
} instru_type_t;

typedef struct instru_s {
    instru_type_t type;
    byte_t *cbyte;
    byte_t *data;
    size_t len;
} instru_t;

typedef struct instru_args_s {
    args_type_t types[MAX_ARGS_NUMBER];
    int values[MAX_ARGS_NUMBER];
} instru_args_t;

typedef struct idx_handler_s {
    instru_type_t type;
    int use_idx[MAX_ARGS_NUMBER];
} idx_handler_t;

void init_instru(instru_t *instru);
instru_t *create_instru(void);
void destroy_instru(instru_t *instru);
int set_instru_from_mem(instru_t *instru, byte_t *mem, size_t midx);
int set_instru_from_asm(
    instru_t *instru, instru_type_t type,
    const args_type_t *types, const int *values);

size_t get_arg_size(instru_type_t itype,
    const args_type_t type, int index);
size_t get_mem_size(instru_type_t itype, byte_t *cbyte);
bool args_are_valid(instru_type_t type, const args_type_t *types);
bool mem_is_valid(const byte_t *cbyte, instru_type_t type);
size_t get_data_size(instru_type_t itype, const args_type_t *types);
byte_t *make_instru_data(instru_type_t itype,
    const args_type_t *types, const int *values);

#endif /* !INSTRU_H */
