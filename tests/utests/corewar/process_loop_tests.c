/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** process_factory_test
*/

#include <criterion/criterion.h>
#include "byte.h"
#include "instru.h"
#include "vm.h"

Test(process_loop_tests, simple_read_op)
{
    process_t *proc = NULL;
    vm_t *vm = NULL;

    vm = create_vm();
    cr_assert_not_null(vm);
    vm->mem[0] = LIVE;
    proc = create_process();
    cr_assert_not_null(proc);
    proc->pc = 0;
    proc->wait = -1;
    loop_process(vm, proc);
    cr_assert_eq(proc->wait, 10);
    destroy_process(&proc);
}
