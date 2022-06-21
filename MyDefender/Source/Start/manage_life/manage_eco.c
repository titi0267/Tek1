/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** manage_eco
*/

#include "../../../include/defender.h"

void init_eco(core_t *core)
{
    lib_t *lib = malloc(sizeof(lib_t));

    sfFont *Font = sfFont_createFromFile("Ressources/FONT/Early GameBoy.ttf");
    int i = core->game->money;
    char *scr = my_int_str(i, lib);
    sfColor color = sfBlack;
    sfVector2f pos_score = {400, 0};
    sfVector2f scale_score = {1.5, 1.5};

    sfText_setFont(core->game->money_txt, Font);
    sfText_setString(core->game->money_txt, scr);
    sfText_setColor(core->game->money_txt, color);
    sfText_setPosition(core->game->money_txt, pos_score);
    sfText_setScale(core->game->money_txt, scale_score);
    sfRenderWindow_drawText(core->wnd->window, core->game->money_txt, NULL);
    free(scr);
    free(lib);
}