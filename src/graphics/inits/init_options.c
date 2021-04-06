/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** init_options
*/

#include "../../../include/rpg.h"

void init_menu_option2(rpg_t *rpg)
{
    sfTexture *game_options = sfTexture_createFromFile
    ("assets/menus/options/select_menu3.png", NULL);
    sfTexture *main_menu = sfTexture_createFromFile
    ("assets/menus/options/select_menu4.png", NULL);
    sfTexture *none = sfTexture_createFromFile
    ("assets/menus/options/select_menu5.png", NULL);

    rpg->main_menu->options[GAME_OPTIONS] = sfSprite_create();
    sfSprite_setTexture(rpg->main_menu->options[GAME_OPTIONS],
    game_options, sfTrue);
    rpg->main_menu->options[MAIN_MENU] = sfSprite_create();
    sfSprite_setTexture(rpg->main_menu->options[MAIN_MENU],
    main_menu, sfTrue);
    rpg->main_menu->options[NO] = sfSprite_create();
    sfSprite_setTexture(rpg->main_menu->options[NO],
    none, sfTrue);
}

void init_menu_option1(rpg_t *rpg)
{
    sfTexture *graph = sfTexture_createFromFile
    ("assets/menus/options/select_menu1.png", NULL);
    sfTexture *sound = sfTexture_createFromFile
    ("assets/menus/options/select_menu2.png", NULL);
    sfVector2f btn_pos = {255, 360.5};

    rpg->main_menu->options[GRAPH] = sfSprite_create();
    sfSprite_setTexture(rpg->main_menu->options[GRAPH],
    graph, sfTrue);
    rpg->main_menu->options[SOUND] = sfSprite_create();
    sfSprite_setTexture(rpg->main_menu->options[SOUND],
    sound, sfTrue);
    for (int i = 3; i != 8; i++) {
        sfSprite_setPosition(rpg->main_menu->options[i], btn_pos);
    }
}

void init_option2(rpg_t *rpg)
{
    sfTexture *game_options = sfTexture_createFromFile
    ("assets/menus/options/menus3.png", NULL);

    init_menu_option2(rpg);
    init_menu_option1(rpg);
    rpg->main_menu->options[GAME_OPTIONS_F] = sfSprite_create();
    sfSprite_setTexture(rpg->main_menu->options[GAME_OPTIONS_F],
    game_options, sfTrue);
}

void init_option1(rpg_t *rpg)
{
    sfTexture *graph = sfTexture_createFromFile
    ("assets/menus/options/menus1.png", NULL);
    sfTexture *sound = sfTexture_createFromFile
    ("assets/menus/options/menus2.png", NULL);
    sfVector2f mns_pos = {0, -30};

    rpg->main_menu->options = malloc(sizeof(sfSprite *) * 9);
    init_option2(rpg);
    rpg->main_menu->options[GRAPH_F] = sfSprite_create();
    sfSprite_setTexture(rpg->main_menu->options[GRAPH_F],
    graph, sfTrue);
    rpg->main_menu->options[SOUND_F] = sfSprite_create();
    sfSprite_setTexture(rpg->main_menu->options[SOUND_F],
    sound, sfTrue);
    for (int i = 0; i != 2; i++) {
        sfSprite_setPosition(rpg->main_menu->options[i], mns_pos);
    }
}