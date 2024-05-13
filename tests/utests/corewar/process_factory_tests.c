/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** process_factory_test
*/

#include <criterion/criterion.h>
#include "process.h"

Test(process_factory_tests, create_process)
{
    process_t *proc = NULL;

    proc = create_process();
    cr_assert_not_null(proc);
    destroy_process(&proc);
}

Test(process_factory_tests, duplicate_process)
{
    process_t *proc = NULL;
    process_t *proc2 = NULL;

    proc = create_process();
    proc->champid = 16;
    proc2 = duplicate_process(proc, 22);
    cr_assert_not_null(proc2);
    cr_assert_eq(proc2->champid, proc->champid);
    destroy_process(&proc2);
    destroy_process(&proc);
}
