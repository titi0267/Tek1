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
    //sfSprite_destroy(core->wnd->sandwich1);
    sfSprite_destroy(core->menu->bgd_spt);
    sfTexture_destroy(core->menu->bgd_tex);
    free(core->wnd);
    free(core->time);
    free(core);
}