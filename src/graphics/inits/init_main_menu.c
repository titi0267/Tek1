/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** init_main_menu
*/

#include "../../../include/func_name.h"

void init_rect_adn(rpg_t *rpg)
{
    rpg->main_menu->rect_but.left = 0;
    rpg->main_menu->rect_but.width = 1920;
    rpg->main_menu->rect_but.height = 1080;
    rpg->main_menu->rect_but.top = 0;
    rpg->main_menu->line_rect = 0;
    rpg->main_menu->offset = 0;
}

int init_main_menu(rpg_t *rpg)
{
    rpg->main_menu->create_main_menu = sfTexture_createFromFile
    ("assets/menus/main/menu.png", NULL);
    rpg->main_menu->main_menu = sfSprite_create();
    sfSprite_setTexture(rpg->main_menu->main_menu,
    rpg->main_menu->create_main_menu, sfTrue);
    rpg->main_menu->create_background = sfTexture_createFromFile
    ("assets/menus/gif.jpg", NULL);
    rpg->main_menu->background = sfSprite_create();
    sfSprite_setTexture(rpg->main_menu->background,
    rpg->main_menu->create_background, sfTrue);
    init_menu_quit(rpg);
}