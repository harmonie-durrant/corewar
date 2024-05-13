/*
** EPITECH PROJECT, 2023
** B-CPE-200-TLS-2-1-corewar-lucien.pineau
** File description:
** main src file for the corewar binary
*/

#include <stdio.h>
#include "corewar.h"
#include "str.h"
#include "pf.h"
#include "rules.h"

int main(int ac, char **av)
{
    int arg_check = 0;

    arg_check = check_args(ac, av);
    ASSERT(arg_check != ERROR && arg_check != SUCCESS, arg_check);
    ASSERT_ERR(corewar(ac, av), ERROR);
    return 0;
}
