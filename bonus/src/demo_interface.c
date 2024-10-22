/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** Creates the base panels for paint
*/

#pragma GCC diagnostic ignored "-Wunused-parameter"

#include <stdlib.h>
#include "demo.h"
#include "ui_panels/empty.h"
#include "ui_panels/button.h"
#include "ui_panels/input.h"
#include "ui_panels/text.h"
#include "ui_panels/flex.h"
#include "tools.h"
#include "ui_panels/buttallfoos.h"
#include "ui_panels/draggable.h"
#include "theme.h"
#include "ui_panels/options.h"
#include "ui_panels/slider.h"
#include "pf.h"

panel_t *minimap(void)
{
    rectransform_t *mrect = rtrans_create_centered(
        (sfVector2f){- ELEMMARGIN * 2.0 - MAPSIZE / 2.0,
        ELEMMARGIN * 2.0 + MAPSIZE / 2.0}, (sfVector2f){MAPSIZE, MAPSIZE});
    mrect->xanchor = ANCHOR_END;
    mrect->yanchor = ANCHOR_START;
    panel_t *main = panel_empty_create(mrect, ITEM_BG);
    return main;
}

static void interface_text_rect_set(panel_t *panel, float scale)
{
    sfText_setScale(panel->text, (sfVector2f){scale, scale});
}

static panel_t *vmflex(program_t *p)
{
    panel_t *fmain = make_flex((sfVector2i){86, 48},
        (sfVector2f){ITEMSIZEX + ITEMMARGIN, ITEMSIZEY + ITEMMARGIN});
    panel_t **childs = malloc(sizeof(panel_t) * 64 * 64 + 1);
    panel_t *panel = NULL;

    fmain->rect->pos.y = -60;
    for (int i = 0; i < 64 * 64; i++) {
        childs[i] = make_ibutt("OO", NULL, NULL, p->font2);
        panel = childs[i];
        interface_text_rect_set(panel, 0.6);
        sfText_setColor(panel->text, sfColor_fromRGBA(255, 215, 50, 100));
    }
    childs[64 * 64] = NULL;
    fmain->childs = childs;
    fmain->childs_count = 64 * 64;
    init_rshape(&(fmain->shape), MENU);
    return fmain;
}

void update_timescale(void *in, float value)
{
    vm_container_t *vmc = (vm_container_t *)in;
    vmc->timescale = value * TIME_SCALE_MAX;
    char *str = quicks("%i", (int) (CYCLE_PER_SEC * vmc->timescale));
    sfText_setString(vmc->timescaleText, str);
    free(str);
    sfFloatRect trect = sfText_getLocalBounds(vmc->timescaleText);
    sfText_setOrigin(vmc->timescaleText, (sfVector2f){
        trect.left + trect.width / 2.0f, trect.top + trect.height / 2.0f});
}

panel_t *time_control(program_t *p)
{
    panel_t *fmain = make_flex((sfVector2i){1, 2},
        (sfVector2f){2 * (ELEMX + ELEMMARGIN * 2), ELEMY + ELEMMARGIN});
    fmain->rect->xanchor = ANCHOR_START;
    fmain->rect->yanchor = ANCHOR_START;
    panel_add_childs(fmain, 2,
        make_label_pair(p->font, "cycles / sec", make_label(p->font, "0", 12), 12),
        make_label_pair(p->font, "time scale", make_slider(NULL, update_timescale, 0, p->params.scale), 12));
    init_rshape(&(fmain->shape), MENU);
    return fmain;
}

panel_t *vm_stats(program_t *p)
{
    panel_t *fmain = make_flex((sfVector2i){1, 3},
        (sfVector2f){2 * (ELEMX + ELEMMARGIN * 2), ELEMY});
    fmain->rect->xanchor = ANCHOR_START;
    fmain->rect->yanchor = ANCHOR_START;
    panel_add_childs(fmain, 3,
        make_label_pair(p->font, "cycles to die", make_label(p->font, "0 / 1536", 12), 12),
        make_label_pair(p->font, "total cycles", make_label(p->font, "0", 12), 12),
        make_label_pair(p->font, "call to live", make_label(p->font, "0 / 40", 12), 12));
    init_rshape(&(fmain->shape), MENU);
    return fmain;
}

panel_t *champ_info1(program_t *p)
{
    panel_t *fmain = make_flex((sfVector2i){1, 2},
        (sfVector2f){2 * (ELEMX + ELEMMARGIN * 2), ELEMY + ELEMMARGIN});
    fmain->rect->xanchor = ANCHOR_START;
    fmain->rect->yanchor = ANCHOR_START;
    panel_add_childs(fmain, 2,
        make_label_pair(p->font, "", make_label(p->font, "", 16), 16),
        make_label_pair(p->font, "", make_label(p->font, "", 16), 16));
    init_rshape(&(fmain->shape), MENU);
    return fmain;
}

panel_t *champ_info2(program_t *p)
{
    panel_t *fmain = make_flex((sfVector2i){1, 2},
        (sfVector2f){2 * (ELEMX + ELEMMARGIN * 2), ELEMY + ELEMMARGIN});
    fmain->rect->xanchor = ANCHOR_START;
    fmain->rect->yanchor = ANCHOR_START;
    panel_add_childs(fmain, 2,
        make_label_pair(p->font, "", make_label(p->font, "", 16), 16),
        make_label_pair(p->font, "", make_label(p->font, "", 16), 16));
    init_rshape(&(fmain->shape), MENU);
    return fmain;
}

panel_t *vm_options(program_t *p)
{
    panel_t *fmain = make_flex((sfVector2i){4, 1},
        (sfVector2f){2 * (ELEMX + ELEMMARGIN * 2) + ELEMMARGIN, ELEMY + ELEMMARGIN});
    fmain->rect->xanchor = ANCHOR_START;
    fmain->rect->yanchor = ANCHOR_START;
    panel_add_childs(fmain, 4, champ_info1(p), champ_info2(p), vm_stats(p), time_control(p));
    return fmain;
}

panel_t *vm_viewer(program_t *p)
{
    rectransform_t *mrect = rtrans_create_centered(
        (sfVector2f){0, - 65}, (sfVector2f){1900, 3 * (ELEMY + ELEMMARGIN)});
    mrect->xanchor = ANCHOR_MIDDLE;
    mrect->yanchor = ANCHOR_END;
    panel_t *main = panel_empty_create(mrect, sfColor_fromRGBA(0, 0, 0, 0));
    panel_add_childs(main, 1, vm_options(p));
    return main;
}

panel_t *game_interface(program_t *p)
{
    rectransform_t *mrect = rtrans_create_resize();
    panel_t *main = panel_none_create(mrect);
    panel_add_childs(main, 2, vm_viewer(p), vmflex(p));
    return main;
}
