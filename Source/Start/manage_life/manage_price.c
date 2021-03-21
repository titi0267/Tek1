/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** manage_price
*/

#include "../../../include/defender.h"

void manage_price_four(core_t *core)
{
    lib_t *lib = malloc(sizeof(lib_t));
    sfFont *Font = sfFont_createFromFile("Ressources/FONT/Early GameBoy.ttf");
    int i = core->shop->price1;
    char *scr = my_int_str(i, lib);
    sfColor color = sfBlack;
    sfVector2f pos_score = {1540, 250};
    sfVector2f scale_score = {1, 1};

    sfText_setFont(core->game->life, Font);
    sfText_setString(core->game->life, scr);
    sfText_setColor(core->game->life, color);
    sfText_setPosition(core->game->life, pos_score);
    sfText_setScale(core->game->life, scale_score);
    sfRenderWindow_drawText(core->wnd->window, core->game->life, NULL);
    free(scr);
    free(lib);
}

void manage_price_three(core_t *core)
{
    lib_t *lib = malloc(sizeof(lib_t));
    sfFont *Font = sfFont_createFromFile("Ressources/FONT/Early GameBoy.ttf");
    int i = core->shop->price2;
    char *scr = my_int_str(i, lib);
    sfColor color = sfBlack;
    sfVector2f pos_score = {1540, 460};
    sfVector2f scale_score = {1, 1};

    sfText_setFont(core->game->life, Font);
    sfText_setString(core->game->life, scr);
    sfText_setColor(core->game->life, color);
    sfText_setPosition(core->game->life, pos_score);
    sfText_setScale(core->game->life, scale_score);
    sfRenderWindow_drawText(core->wnd->window, core->game->life, NULL);
    free(scr);
    free(lib);
}

void manage_price_two(core_t *core)
{
    lib_t *lib = malloc(sizeof(lib_t));
    sfFont *Font = sfFont_createFromFile("Ressources/FONT/Early GameBoy.ttf");
    int i = core->shop->price3;
    char *scr = my_int_str(i, lib);
    sfColor color = sfBlack;
    sfVector2f pos_score = {1540, 670};
    sfVector2f scale_score = {1, 1};

    sfText_setFont(core->game->life, Font);
    sfText_setString(core->game->life, scr);
    sfText_setColor(core->game->life, color);
    sfText_setPosition(core->game->life, pos_score);
    sfText_setScale(core->game->life, scale_score);
    sfRenderWindow_drawText(core->wnd->window, core->game->life, NULL);
    free(scr);
    free(lib);
}

void manage_price_one(core_t *core)
{
    lib_t *lib = malloc(sizeof(lib_t));
    sfFont *Font = sfFont_createFromFile("Ressources/FONT/Early GameBoy.ttf");
    int i = core->shop->price4;
    char *scr = my_int_str(i, lib);
    sfColor color = sfBlack;
    sfVector2f pos_score = {1540, 810};
    sfVector2f scale_score = {1, 1};

    sfText_setFont(core->game->life, Font);
    sfText_setString(core->game->life, scr);
    sfText_setColor(core->game->life, color);
    sfText_setPosition(core->game->life, pos_score);
    sfText_setScale(core->game->life, scale_score);
    sfRenderWindow_drawText(core->wnd->window, core->game->life, NULL);
    free(scr);
    free(lib);
}

void manage_price_all(core_t *core)
{
    manage_price_one(core);
    manage_price_two(core);
    manage_price_three(core);
    manage_price_four(core);
}