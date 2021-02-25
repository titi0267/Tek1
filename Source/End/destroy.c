/*
** EPITECH PROJECT, 2021
** destroy elements by Timothy CONIEL & Tristan HOURTOUILLE
** File description:
** destroy.c
*/

#include "../../include/defender.h"

void destroy1(core_t *core)
{
    sfRenderWindow_destroy(core->wnd->window);
    sfSprite_destroy(core->menu->bgd_spt);
    sfSprite_destroy(core->menu->button->play_spt);
    sfSprite_destroy(core->menu->button->leave_spt);
    sfSprite_destroy(core->menu->button->hover_leave_spt);
    sfSprite_destroy(core->menu->button->setting_spt);
    sfSprite_destroy(core->menu->button->hover_setting_spt);
    sfTexture_destroy(core->menu->bgd_tex);
    sfTexture_destroy(core->menu->button->hover_setting_tex);
    sfTexture_destroy(core->menu->button->setting_tex);
    sfTexture_destroy(core->menu->button->leave_tex);
    sfTexture_destroy(core->menu->button->hover_leave_tex);
    sfTexture_destroy(core->menu->button->play_tex);
    sfClock_destroy(core->time->clock);
    free(core->wnd);
    free(core->menu->button);
    free(core->time);
    free(core);
}