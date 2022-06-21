/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** init_options
*/

#include "../../../include/func_name.h"

void init_controls(rpg_t *rpg)
{
    rpg->menu->stg->key_bnd->control[UP]->text[0] = 'z';
    rpg->menu->stg->key_bnd->control[DOWN]->text[0] = 's';
    rpg->menu->stg->key_bnd->control[LEFT]->text[0] = 'q';
    rpg->menu->stg->key_bnd->control[RIGHT]->text[0] = 'd';
    rpg->menu->stg->key_bnd->control[RUN]->text[0] = 'r';
    rpg->menu->stg->key_bnd->control[INVENTORY]->text[0] = 'e';
    rpg->menu->stg->key_bnd->control[CELLPHONE]->text[0] = 't';
    rpg->menu->stg->key_bnd->control[CAR]->text[0] = 'c';
    rpg->menu->stg->key_bnd->control[QUADCOPTER]->text[0] = 'x';
    for (int i = 0; i <= QUADCOPTER; i++)
        rpg->menu->stg->key_bnd->control[i]->text[1] = '\0';
    rpg->menu->stg->key_bnd->box_clicked = -1;
    init_text(rpg);
}

static void init_menu_option2(rpg_t *rpg)
{
    sfTexture *game_options = sfTexture_createFromFile
    ("assets/menus/options/select_menu3.png", NULL);
    sfTexture *main_menu = sfTexture_createFromFile
    ("assets/menus/options/select_menu4.png", NULL);
    sfTexture *none = sfTexture_createFromFile
    ("assets/menus/options/select_menu5.png", NULL);

    rpg->menu->stg->opt[GAME_OPTIONS] = sfSprite_create();
    sfSprite_setTexture(rpg->menu->stg->opt[GAME_OPTIONS],
    game_options, sfTrue);
    rpg->menu->stg->opt[MAIN_MENU] = sfSprite_create();
    sfSprite_setTexture(rpg->menu->stg->opt[MAIN_MENU],
    main_menu, sfTrue);
    rpg->menu->stg->opt[NO] = sfSprite_create();
    sfSprite_setTexture(rpg->menu->stg->opt[NO],
    none, sfTrue);
}

static void init_menu_option1(rpg_t *rpg)
{
    sfTexture *graph = sfTexture_createFromFile
    ("assets/menus/options/select_menu1.png", NULL);
    sfTexture *sound = sfTexture_createFromFile
    ("assets/menus/options/select_menu2.png", NULL);
    sfVector2f btn_pos = {255, 360.5};

    rpg->menu->stg->opt[GRAPH] = sfSprite_create();
    sfSprite_setTexture(rpg->menu->stg->opt[GRAPH],
    graph, sfTrue);
    rpg->menu->stg->opt[SOUND] = sfSprite_create();
    sfSprite_setTexture(rpg->menu->stg->opt[SOUND],
    sound, sfTrue);
    for (int i = 3; i != 8; i++) {
        sfSprite_setPosition(rpg->menu->stg->opt[i], btn_pos);
    }
}

static void init_option2(rpg_t *rpg)
{
    sfTexture *game_options = sfTexture_createFromFile
    ("assets/menus/options/menus3.png", NULL);

    init_menu_option2(rpg);
    init_menu_option1(rpg);
    rpg->menu->stg->opt[GAME_OPTIONS_F] = sfSprite_create();
    sfSprite_setTexture(rpg->menu->stg->opt[GAME_OPTIONS_F],
    game_options, sfTrue);
}

void init_option1(rpg_t *rpg)
{
    sfTexture *graph = sfTexture_createFromFile
    ("assets/menus/options/menus1.png", NULL);
    sfTexture *sound = sfTexture_createFromFile
    ("assets/menus/options/menus2.png", NULL);
    sfVector2f mns_pos = {0, -30};

    rpg->menu->stg->opt = malloc(sizeof(sfSprite *) * 9);
    init_option2(rpg);
    rpg->menu->stg->opt[GRAPH_F] = sfSprite_create();
    sfSprite_setTexture(rpg->menu->stg->opt[GRAPH_F],
    graph, sfTrue);
    rpg->menu->stg->opt[SOUND_F] = sfSprite_create();
    sfSprite_setTexture(rpg->menu->stg->opt[SOUND_F],
    sound, sfTrue);
    for (int i = 0; i != 3; i++) {
        sfSprite_setPosition(rpg->menu->stg->opt[i], mns_pos);
    }
}