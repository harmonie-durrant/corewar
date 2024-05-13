/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include <stdlib.h>
#include <stdio.h>
#include "corewar_info.h"
#include "corewar.h"
#include "mywar.h"
#include "champ.h"
#include "vm.h"
#include "pf.h"
#include "op.h"
#include "rules.h"

int corewar(int ac, char **av)
{
    corewar_info_t info = {0, 0, 0, 0, NULL};

    info = parse_arguments(ac, av);
    ASSERT((info.tmp_prog_num != -3), SUCCESS);
    ASSERT((info.tmp_prog_num != -2), ERROR);
    ASSERT(info.champions, ERROR);
    reverse_corewar_champs(&(info.champions));
    ASSERT(start_corewar(&info) == 0, ERROR);
    return free_corewar_champs(info.champions);
}
