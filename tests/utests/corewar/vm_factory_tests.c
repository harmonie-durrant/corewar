/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** process_factory_test
*/

#include <criterion/criterion.h>
#include "vm.h"

Test(vm_factory, create_vm)
{
    vm_t *vm = NULL;

    vm = create_vm();
    cr_assert_not_null(vm);
    destroy_vm(vm);
}

Test(vm_factory, destroy_vm)
{
    vm_t *vm = NULL;

    vm = create_vm();
    cr_assert_not_null(vm);
    destroy_vm(vm);
}
