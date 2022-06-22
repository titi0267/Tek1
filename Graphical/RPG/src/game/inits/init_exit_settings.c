/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** init_exit_settings
*/

#include "../../../include/func_name.h"

static void init_settings_option2(rpg_t *rpg)
{
    sfTexture *game_options = sfTexture_createFromFile
    ("assets/menu_in_game/select_menu/select_menu3.png", NULL);
    sfTexture *back = sfTexture_createFromFile
    ("assets/menu_in_game/select_menu/select_menu4.png", NULL);
    sfTexture *none = sfTexture_createFromFile
    ("assets/menu_in_game/select_menu/select_menu5.png", NULL);

    rpg->menu->stg->opt_exit[GAME_OPTIONS] = sfSprite_create();
    sfSprite_setTexture(rpg->menu->stg->opt_exit[GAME_OPTIONS],
    game_options, sfTrue);
    rpg->menu->stg->opt_exit[MAIN_MENU] = sfSprite_create();
    sfSprite_setTexture(rpg->menu->stg->opt_exit[MAIN_MENU],
    back, sfTrue);
    rpg->menu->stg->opt_exit[NO] = sfSprite_create();
    sfSprite_setTexture(rpg->menu->stg->opt_exit[NO],
    none, sfTrue);
}

void init_exit_option1(rpg_t *rpg)
{
    sfTexture *graph = sfTexture_createFromFile
    ("assets/menu_in_game/select_menu/select_menu1.png", NULL);
    sfTexture *sound = sfTexture_createFromFile
    ("assets/menu_in_game/select_menu/select_menu2.png", NULL);
    sfVector2f btn_pos = {255, 360.5};

    rpg->menu->stg->opt_exit = malloc(sizeof(sfSprite *) * 8);
    rpg->menu->stg->opt_exit[GRAPH] = sfSprite_create();
    sfSprite_setTexture(rpg->menu->stg->opt_exit[GRAPH],
    graph, sfTrue);
    rpg->menu->stg->opt_exit[SOUND] = sfSprite_create();
    sfSprite_setTexture(rpg->menu->stg->opt_exit[SOUND],
    sound, sfTrue);
    init_settings_option2(rpg);
    for (int i = 3; i != 8; i++) {
        sfSprite_setPosition(rpg->menu->stg->opt_exit[i], btn_pos);
    }
}