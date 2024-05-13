/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** process_factory_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"
#include "corewar_info.h"
#include "pf.h"

Test(flag_handler_tests, parse_arguments_no_files, .init = cr_redirect_stderr)
{
    char *av[] = {"./corewar", "-dump", "10", NULL};

    cr_assert_eq(parse_arguments(3, av).tmp_prog_num, -2);
}

Test(flag_handler_tests, parse_arguments_no_dump, .init = cr_redirect_stderr)
{
    char *av[] = {"./corewar", "-n", "5", "../tests/champions/42.cor", NULL};

    cr_assert_eq(parse_arguments(4, av).tmp_prog_num, -1);
}

Test(flag_handler_tests, parse_arguments_valid, .init = cr_redirect_stderr)
{
    char *av[] = {"./corewar", "../tests/champions/42.cor", "../tests/champions/abel.cor", NULL};

    cr_assert_eq(parse_arguments(3, av).tmp_prog_num, -1);
}

Test(flag_handler_tests, parse_arguments_no_file, .init = cr_redirect_stderr)
{
    char *av[] = {"./corewar", "-n", "5", NULL};

    cr_assert_eq(parse_arguments(3, av).tmp_prog_num, -2);
}

Test(flag_handler_tests, parse_arguments_same_num, .init = cr_redirect_stderr)
{
    char *av[] = {"./corewar", "-n", "5", "../tests/champions/42.cor", "-n", "5", "../tests/champions/42.cor", NULL};

    cr_assert_eq(parse_arguments(7, av).tmp_prog_num, -2);
}

Test(flag_handler_tests, parse_arguments_multiple_dump, .init = cr_redirect_stderr)
{
    char *av[] = {"./corewar", "-dump", "10", "-dump", "20", NULL};

    cr_assert_eq(parse_arguments(5, av).tmp_prog_num, -2);
}