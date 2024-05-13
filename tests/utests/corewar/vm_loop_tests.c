/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** process_factory_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "process.h"
#include "vm.h"

Test(vm_loop_tests, simple_dead_process, .init = cr_redirect_stderr)
{
    vm_t *vm = NULL;
    process_t *proc = NULL;

    vm = create_vm();
    cr_assert_not_null(vm);
    proc = create_process();
    cr_assert_not_null(proc);
    proc->pc = 0;
    proc->wait = 10;
    vm->cycle = 999999;
    vm->nbr_dump_cycle = -1;
    vm->procs = create_list_node(proc);
    cr_assert_not_null(vm->procs);
    loop_vm(vm);
    destroy_vm(vm);
}
