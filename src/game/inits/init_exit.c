/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** init_exit
*/

#include "../../../include/func_name.h"

void init_exit(rpg_t *rpg)
{
    sfTexture *exit = sfTexture_createFromFile
    ("assets/menu_in_game/exit.png", NULL);
    sfTexture *no_mouse_on = sfTexture_createFromFile
    ("assets/menu_in_game/exit_menu4.png", NULL);

    rpg->game->in_game->ig_menus->exit = sfSprite_create();
    sfSprite_setTexture(rpg->game->in_game->ig_menus->exit,
    exit, sfTrue);
    sfSprite_setTexture(rpg->game->in_game->ig_menus->pause_menu[MENU_PAUSE],
    no_mouse_on, sfTrue);
}

void init_pause(rpg_t *rpg)
{
    sfTexture *option = sfTexture_createFromFile
    ("assets/menu_in_game/exit_menu2.png", NULL);
    sfTexture *resume = sfTexture_createFromFile
    ("assets/menu_in_game/exit_menu1.png", NULL);
    sfTexture *quit = sfTexture_createFromFile
    ("assets/menu_in_game/exit_menu3.png", NULL);
    sfVector2f pos = {761.23, 389.809};

    rpg->game->in_game->ig_menus->pause_menu
    = malloc(sizeof(sfSprite *) * 6);
    for (int i = RESUME_PAUSE; i != NO_BUTTON_PAUSE; i++)
        rpg->game->in_game->ig_menus->pause_menu[i] = sfSprite_create();
    init_exit(rpg);
    sfSprite_setTexture(rpg->game->in_game->ig_menus->pause_menu[RESUME_PAUSE],
    resume, sfTrue);
    sfSprite_setTexture(rpg->game->in_game->ig_menus->pause_menu[OPTION_PAUSE],
    option, sfTrue);
    sfSprite_setTexture(rpg->game->in_game->ig_menus->pause_menu[QUIT_PAUSE],
    quit, sfTrue);
    for (int i = RESUME_PAUSE; i != NO_BUTTON_PAUSE; i++)
        sfSprite_setPosition(rpg->game->in_game->ig_menus->pause_menu[i], pos);
}