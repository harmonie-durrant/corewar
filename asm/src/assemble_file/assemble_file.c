/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** assemble_file
*/

#include <stdlib.h>
#include "byte.h"
#include "asm.h"
#include "rules.h"
#include "label.h"
#include "str.h"

static int parse_champ(FILE *stream, champ_t *champ)
{
    list_t *sizes = NULL;
    list_t *labels = NULL;
    list_t *instrus = NULL;

    ASSERT_ERR(scan_labels(stream, &labels), ERROR);
    ASSERT_ERR(parse_instructions_sizes(stream, &sizes), ERROR);
    if (parse_header(stream, &champ->header) == ERROR) {
        destroy_list(&labels, (list_callback_t)&destroy_label);
        return ERROR;
    }
    ASSERT_ERR(parse_instructions(stream, &instrus, &labels, &sizes), ERROR);
    destroy_list(&labels, (list_callback_t)&destroy_label);
    champ->code = get_champ_code(instrus);
    champ->header.prog_size = SWAP32(get_code_size(instrus));
    destroy_list(&instrus, (list_callback_t)&destroy_instru);
    destroy_list(&sizes, &free);
    ASSERT(champ->code, ERROR);
    return SUCCESS;
}

static int write_champ(champ_t *champ, const char *asm_filename)
{
    FILE *stream = NULL;
    char *new_filename = NULL;
    size_t size = sizeof(header_t);

    new_filename = get_new_filename(asm_filename);
    ASSERT(new_filename, ERROR);
    stream = fopen(new_filename, "w");
    free(new_filename);
    ASSERT(stream, ERROR);
    if (fwrite(&champ->header, size, 1, stream) != 1) {
        fclose(stream);
        return ERROR;
    }
    size = SWAP32(champ->header.prog_size);
    if (fwrite(champ->code, size, 1, stream) != 1) {
        fclose(stream);
        return ERROR;
    }
    fclose(stream);
    return SUCCESS;
}

int assemble_file(char *filename)
{
    champ_t champ = {0};
    FILE *stream = NULL;
    int status = ERROR;

    init_champ(&champ);
    stream = fopen(filename, "r");
    ASSERT(stream, ERROR);
    status = parse_champ(stream, &champ);
    fclose(stream);
    if (status == ERROR) {
        return ERROR;
    }
    status = write_champ(&champ, filename);
    free(champ.code);
    return status;
}
