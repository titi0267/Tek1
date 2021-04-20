/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** init_main_menu
*/

#include "../../../include/func_name.h"

void init_rect_adn(rpg_t *rpg)
{
    rpg->menu->bgd_adn->rect_but.left = 0;
    rpg->menu->bgd_adn->rect_but.width = 1920;
    rpg->menu->bgd_adn->rect_but.height = 1080;
    rpg->menu->bgd_adn->rect_but.top = 0;
    rpg->menu->bgd_adn->line_rect = 0;
    rpg->menu->bgd_adn->offset = 0;
}

void init_main_menu(rpg_t *rpg)
{
    rpg->menu->main_menu->menu_spt->create_main_menu = sfTexture_createFromFile
    ("assets/menus/main/menu.png", NULL);
    rpg->menu->main_menu->menu_spt->main_menu = sfSprite_create();
    sfSprite_setTexture(rpg->menu->main_menu->menu_spt->main_menu,
    rpg->menu->main_menu->menu_spt->create_main_menu, sfTrue);
    rpg->menu->bgd_adn->create_background = sfTexture_createFromFile
    ("assets/menus/gif.jpg", NULL);
    rpg->menu->bgd_adn->background = sfSprite_create();
    sfSprite_setTexture(rpg->menu->bgd_adn->background,
    rpg->menu->bgd_adn->create_background, sfTrue);
    init_menu_quit(rpg);
}