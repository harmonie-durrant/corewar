/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar_info
*/

#ifndef COREWAR_INFO_H_
    #define COREWAR_INFO_H_

    #include <stdio.h>

    typedef struct corewar_champs_s {
        int prog_num;
        int load_addr;
        FILE *stream;
        char *name;
        struct corewar_champs_s *next;
    } corewar_champs_t;

    typedef struct corewar_info_s {
        int dump;
        int seen_dump;
        int tmp_prog_num;
        int tmp_load_addr;
        corewar_champs_t *champions;
    } corewar_info_t;

corewar_info_t parse_arguments(int argc, char *argv[]);
int handle_flag(int *i, char *argv[], int argc, corewar_info_t *info);
void init_corewar_champ(corewar_champs_t *new_champ);

int check_pnum(corewar_info_t *info);
int check_laddr(corewar_info_t *info);
int check_missing_script(corewar_info_t info);

int set_pnum(int *i, char *argv[], int argc, corewar_info_t *info);
int set_dump(int *i, char *argv[], int argc, corewar_info_t *info);
int set_laddr(int *i, char *argv[], int argc, corewar_info_t *info);

void set_new_champ(corewar_champs_t *new_champ, corewar_info_t *info);
int free_corewar_champs(corewar_champs_t *champ);
void init_corewar_champ(corewar_champs_t *new_champ);
void reverse_corewar_champs(corewar_champs_t **champs);

#endif /* !COREWAR_INFO_H_ */
