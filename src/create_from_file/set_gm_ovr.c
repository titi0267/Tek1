/*
** EPITECH PROJECT, 2021
** set game over by Timothy CONIEL
** File description:
** set_gm_ovr.c
*/
#include "../../include/my.h"


void create_button(menu_t *menu)
{
    menu->button = sfSprite_create();
    menu->button_tex = sfTexture_createFromFile("ressource/img/off_button.png",
                                                NULL);
    init_button(menu);
    sfSprite_setTexture(menu->button, menu->button_tex, sfFalse);
    sfSprite_setScale(menu->button, menu->scale);
}

void create_load(menu_t *menu)
{
    menu->load = sfSprite_create();
    menu->loading = sfTexture_createFromFile("ressource/img/loading.png", NULL);
    sfVector2f scale = {1, 1};
    sfVector2f position = {200, 100};

    sfSprite_setTexture(menu->load, menu->loading, sfFalse);
    sfSprite_setScale(menu->load, scale);
    sfSprite_setPosition(menu->load, position);
}

void create_button_black(menu_t *menu)
{
    menu->black_but = sfSprite_create();
    menu->black_tex = sfTexture_createFromFile("ressource/img/on_button.png",
                                                NULL);
    init_button(menu);
    sfSprite_setTexture(menu->black_but, menu->black_tex, sfFalse);
    sfSprite_setScale(menu->black_but, menu->scale);
    sfSprite_setPosition(menu->black_but, menu->pos_black);
}

void game_over(menu_t *menu)
{
    menu->gm_ovr = sfSprite_create();
    menu->game_ovr = sfTexture_createFromFile("ressource/img/game_over.png",
                                                NULL);
    sfVector2f scale = {5, 5};

    menu->pos_death.x = 400;
    menu->pos_death.y = 200;
    sfSprite_setTexture(menu->gm_ovr, menu->game_ovr, sfFalse);
    sfSprite_setScale(menu->gm_ovr, scale);
    sfSprite_setPosition(menu->gm_ovr, menu->pos_death);
}
