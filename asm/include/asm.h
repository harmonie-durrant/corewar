/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** main header for the asm binary
*/

#ifndef ASM_H_
    #define ASM_H_
    #include <stdio.h>
    #include "op.h"
    #include "champ.h"
    #include "instru.h"
    #include "list.h"
    #define FILE_EXT ".s"

// MAIN TOOLS
int check_args(int ac, char **av);

// ASSEMBLER
int assembler(int ac, char **av);
int assemble_file(char *filename);
size_t get_code_size(list_t *tmp);
byte_t *get_champ_code(list_t *instrus);
int create_cor(char *name_ref, champ_t *champ);
char *name_to_cor(char *s_filename);
int write_content(FILE *stream, champ_t *champ);

// ASSEMBLER TOOLS
char *get_next_line(FILE *stream);
char *get_sgf_format(int size);
int get_line_data_start(const char *line);
void clean_line(char *line);
char *get_new_filename(const char *filename);
int set_start(FILE *stream);
void **get_line_data(char *line);
void free_data(void **data);
int set_lines_offset(list_t *sizes, int *delim, int *offset);
bool line_is_empty(char *line);

// PARSING
int parse_header(FILE *stream, header_t *header);
int parse_instructions(FILE *stream, list_t **instructions,
list_t **labels, list_t **sizes);
int set_args(void **args_str, instru_args_t *args, list_t **lists, int pos);
int parse_line_data(const char *line, instru_args_t *args,
list_t *labels, int pos);
int parse_instru_line(char *line, instru_t *instru,
list_t **lists, int pos);
instru_type_t get_instru_type(const char *line);
int parse_instructions_sizes(FILE *stream, list_t **sizes);

#endif /* !ASM_H_ */
