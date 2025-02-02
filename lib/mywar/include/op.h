/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** main header for the vm defines
*/

#ifndef _OP_H_
    #define _OP_H_
    #define MEM_SIZE (6 * 1024)
    #define IDX_MOD 512
    #define MAX_ARGS_NUMBER 4
    #define COMMENT_CHAR '#'
    #define LABEL_CHAR ':'
    #define DIRECT_CHAR '%'
    #define SEPARATOR_CHAR ','
    #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"
    #define NAME_CMD_STRING ".name"
    #define COMMENT_CMD_STRING ".comment"

    #define REG_NUMBER 16 /* r1 <--> rx */

/*
**
*/

typedef char args_type_t;

    #define T_REG 1 /* register */
    #define T_DIR 2 /* direct  (ld  #1,r1  put 1 into r1) */
    #define T_IND 4 /* indirect always relative */
                /* ( ld 1,r1 put what's in the
                 address (1+pc) into r1 (4 bytes )) */
    #define T_LAB 8 /* LABEL */

struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
};

typedef struct op_s op_t;

/*
** size (in bytes)
*/
    #define IND_SIZE 2
    #define DIR_SIZE 4
    #define REG_SIZE DIR_SIZE

/*
** op_tab
*/
extern op_t op_tab[];

/*
** header
*/
    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048

struct header_s {
    int magic;
    #define COREWAR_EXEC_MAGIC 0xea83f3 /* why not */
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
};

typedef struct header_s header_t;

/*
** live
*/
    #define CYCLE_TO_DIE 1536 /* number of cycle before beig declared dead */
    #define CYCLE_DELTA 5
    #define NBR_LIVE 40

#endif /* !_OP_H_ */
