/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Demo content
*/

#pragma GCC diagnostic ignored "-Wunused-parameter"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "content.h"
#include "demo.h"
#include "corewar_info.h"
#include "corewar.h"
#include "mywar.h"
#include "champ.h"
#include "vm.h"
#include "pf.h"
#include "op.h"
#include "rules.h"
#include "champ_mem.h"

void demo_content_destroyer(void *content)
{
    //printf("Demo content destroyer called\n");
}

void demo_content_eventer(void *content, sfEvent event)
{
    //printf("Demo content eventer called\n");
}

void demo_content_on_enter(void *content)
{
    //printf("Demo content on enter called\n");
}

void demo_content_on_leave(void *content)
{
    //printf("Demo content on leave called\n");
}

void demo_content_on_press(void *content, sfMouseButtonEvent event)
{
    //printf("Content click press on %d\n", event.button);
}

void demo_content_on_release(void *content, sfMouseButtonEvent event)
{
    //printf("Content click release on %d\n", event.button);
}

void demo_content_on_select(void *content)
{
    //printf("Demo content on select called\n");
}

void demo_content_on_deselect(void *content)
{
    //printf("Demo content on deselect called\n");
}

void demo_content_on_hover(void *content, sfVector2i *mouse)
{
    //write(1,".",1);
    //printf("Content hover at %d, %d\n", mouse->x, mouse->y);
}

void demo_content_on_key_press(void *content, sfKeyEvent event)
{
    //printf("Content key press of %d\n", event.code);
}

void demo_content_on_key_release(void *content, sfKeyEvent event)
{
    //printf("Content key release of %d\n", event.code);
}

void demo_content_on_start(void *content)
{
    //printf("Demo content on start called\n");
}

void demo_content_on_pause(void *content)
{
    //printf("Demo content on pause called\n");
}

void demo_content_on_resume(void *content)
{
    //printf("Demo content on resume called\n");
}

void demo_content_on_stop(void *content)
{
    //printf("Demo content on stop called\n");
}

void demo_content_saver(void *content, const char *path)
{
    //printf("Saved in %s\n", path);
}

void demo_content_loader(void *content, const char *path)
{
    //printf("loaded from %s\n", path);
}

void demo_content_looper(void *content, float dt)
{
    static int state = 0;

    if (state == -1) {
        return;
    }
    if (vm_container_update(content, dt) != -1)
        return;
    state = -1;
}

vm_t *bonusstart_corewar(corewar_info_t *info)
{
    corewar_champs_t *champ_info = NULL;
    vm_t *vm = NULL;
    int nchamps = 0;

    champ_info = info->champions;
    nchamps = count_champs(info->champions);
    vm = create_vm();
    vm->nbr_dump_cycle = info->dump;
    vm->champs = malloc(sizeof(champ_t) * nchamps);
    ASSERT(vm->champs, NULL);
    add_champions(champ_info, vm);
    set_vm_champs(vm, vm->champs, nchamps);
    return vm;
}

vm_t *bonuscorewar(int ac, char **av)
{
    corewar_info_t info = {0, 0, 0, 0, NULL};

    info = parse_arguments(ac, av);
    ASSERT((info.tmp_prog_num != -3), SUCCESS);
    ASSERT((info.tmp_prog_num != -2), NULL);
    ASSERT(info.champions, NULL);
    reverse_corewar_champs(&(info.champions));
    return bonusstart_corewar(&info);
}

vm_t *bonusmain(int ac, char **av)
{
    int arg_check = 0;

    arg_check = check_args(ac, av);
    ASSERT(arg_check != ERROR && arg_check != SUCCESS, NULL);
    return bonuscorewar(ac, av);
}

void initialize_content(content_t *content, program_t *prog, int ac, char **av)
{
    content->content = vm_container_create(prog, bonusmain(ac, av));
    content->maker = NULL;
    content->destroyer = NULL;
    content->drawer = NULL;
    content->looper = NULL;
    content->eventer = NULL;
    content->on_enter = NULL;
    content->on_leave = NULL;
    content->on_press = NULL;
    content->on_release = NULL;
    content->on_select = NULL;
    content->on_deselect = NULL;
    content->on_hover = NULL;
    content->on_key_press = NULL;
    content->on_key_release = NULL;
    content->on_start = NULL;
    content->on_pause = NULL;
    content->on_resume = NULL;
    content->on_stop = NULL;
    content->saver = NULL;
    content->loader = NULL;
}

content_t *demo_content_maker(program_t *prog, int ac, char **av)
{
    content_t *content = malloc(sizeof(content_t));

    if (!content)
        return NULL;
    initialize_content(content, prog, ac, av);
    if (!content->content)
        return NULL;
    content->destroyer = demo_content_destroyer;
    content->eventer = demo_content_eventer;
    content->on_enter = demo_content_on_enter;
    content->on_leave = demo_content_on_leave;
    content->on_press = demo_content_on_press;
    content->on_release = demo_content_on_release;
    content->on_select = demo_content_on_select;
    content->on_deselect = demo_content_on_deselect;
    content->on_hover = demo_content_on_hover;
    content->on_key_press = demo_content_on_key_press;
    content->on_key_release = demo_content_on_key_release;
    content->on_start = demo_content_on_start;
    content->on_pause = demo_content_on_pause;
    content->on_resume = demo_content_on_resume;
    content->on_stop = demo_content_on_stop;
    content->saver = demo_content_saver;
    content->loader = demo_content_loader;
    content->looper = demo_content_looper;
    return content;
}