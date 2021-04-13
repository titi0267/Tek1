/*
** EPITECH PROJECT, 2021
** init buttons
** File description:
** init_btn_menu.c
*/

#include "../../../include/func_name.h"

void init_menu_newgame(rpg_t *rpg)
{
    rpg->main_menu->menu = malloc(sizeof(sfSprite *) * 7);

    sfTexture *new_gm_tex = sfTexture_createFromFile
    ("assets/menus/main/select1.png", NULL);
    rpg->main_menu->menu[NEW_GAME] = sfSprite_create();
    sfSprite_setTexture(rpg->main_menu->menu[NEW_GAME],
    new_gm_tex, sfTrue);
}

void init_menu_continue(rpg_t *rpg)
{
    sfTexture *continue_tex = sfTexture_createFromFile
    ("assets/menus/main/select2.png", NULL);

    init_menu_newgame(rpg);
    rpg->main_menu->menu[CONTINUE] = sfSprite_create();
    sfSprite_setTexture(rpg->main_menu->menu[CONTINUE],
    continue_tex, sfTrue);
}

void init_menu_tuto(rpg_t *rpg)
{
    sfTexture *tuto = sfTexture_createFromFile
    ("assets/menus/main/select3.png", NULL);

    init_menu_continue(rpg);
    rpg->main_menu->menu[TUTORIAL] = sfSprite_create();
    sfSprite_setTexture(rpg->main_menu->menu[TUTORIAL],
    tuto, sfTrue);
}

void init_menu_option(rpg_t *rpg)
{
    sfTexture *option = sfTexture_createFromFile
    ("assets/menus/main/select4.png", NULL);
    sfTexture *none = sfTexture_createFromFile
    ("assets/menus/main/select6.png", NULL);

    init_menu_tuto(rpg);
    rpg->main_menu->menu[NONE] = sfSprite_create();
    sfSprite_setTexture(rpg->main_menu->menu[NONE],
    none, sfTrue);
    rpg->main_menu->menu[OPTIONS] = sfSprite_create();
    sfSprite_setTexture(rpg->main_menu->menu[OPTIONS],
    option, sfTrue);
}

void init_menu_quit(rpg_t *rpg)
{
    sfTexture *quit_tex = sfTexture_createFromFile
    ("assets/menus/main/select5.png", NULL);
    sfVector2f btn_pos = {1242, 291.5};

    init_menu_option(rpg);
    rpg->main_menu->menu[QUIT] = sfSprite_create();
    sfSprite_setTexture(rpg->main_menu->menu[QUIT],
    quit_tex, sfTrue);
    for (int i = 0; i != 6; i++) {
        sfSprite_setPosition(rpg->main_menu->menu[i], btn_pos);
    }
}