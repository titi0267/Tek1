/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** manage_kill
*/

#include "../../../include/defender.h"

int manage_kill(core_t *core)
{
    lib_t *lib = malloc(sizeof(lib_t));
    sfFont *Font = sfFont_createFromFile("Ressources/FONT/Early GameBoy.ttf");
    int i = core->wave->kill;
    char *scr = my_int_str(i, lib);
    sfColor color = sfBlack;
    sfVector2f pos_score = {80, 950};
    sfVector2f scale_score = {1.5, 1.5};

    sfText_setFont(core->game->life, Font);
    sfText_setString(core->game->life, scr);
    sfText_setColor(core->game->life, color);
    sfText_setPosition(core->game->life, pos_score);
    sfText_setScale(core->game->life, scale_score);
    sfRenderWindow_drawText(core->wnd->window, core->game->life, NULL);
    free(scr);
    free(lib);
    return (0);
}