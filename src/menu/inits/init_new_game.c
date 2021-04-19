/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** init_new_game
*/

#include "../../../include/func_name.h"

sfVector2f put_in_vector2f(float x, float y)
{
    sfVector2f pos = {x, y};

    return (pos);
}

void set_square_position(rpg_t *rpg)
{
    sfVector2f pos_bg = {0, -30};
    sfVector2f *pos_characters = malloc(sizeof(sfVector2f) * 5);

    sfSprite_setPosition(rpg->menu->main_menu->new_game->background, pos_bg);
    pos_characters[MAXOU] = put_in_vector2f((float)396, (float)362);
    pos_characters[TIMO] = put_in_vector2f((float)689, (float)362);
    pos_characters[LUDO] = put_in_vector2f((float)982, (float)362);
    pos_characters[SYLVIE] = put_in_vector2f((float)1275, (float)362);
    for (int i = MAXOU; i < NO_CHARACTERS; i++) {
        sfSprite_setPosition(rpg->menu->main_menu->new_game->select[i],
        pos_characters[i]);
    }
    rpg->menu->main_menu->new_game->pos_characters = pos_characters;
}

void init_new_game(rpg_t *rpg)
{
    rpg->menu->main_menu->new_game->select = malloc(sizeof(sfSprite *) * 5);
    rpg->menu->main_menu->new_game->select_txt = malloc(sizeof(sfTexture *) *5);
    rpg->menu->main_menu->new_game->background = sfSprite_create();
    rpg->menu->main_menu->new_game->background_txt = sfTexture_createFromFile
    ("assets/menus/new_game/charactere_choice.png", NULL);
    sfSprite_setTexture(rpg->menu->main_menu->new_game->background,
    rpg->menu->main_menu->new_game->background_txt, sfTrue);
    for (int i = MAXOU; i < NO_CHARACTERS; i++) {
        rpg->menu->main_menu->new_game->select[i] = sfSprite_create();
        rpg->menu->main_menu->new_game->select_txt[i] =
        sfTexture_createFromFile
        ("assets/menus/new_game/select_perso.png", NULL);
        sfSprite_setTexture(rpg->menu->main_menu->new_game->select[i],
        rpg->menu->main_menu->new_game->select_txt[i], sfTrue);
    }
    set_square_position(rpg);
}

void init_characters_textures(rpg_t *rpg)
{
    rpg->menu->main_menu->new_game->characters_txt[MAXOU] =
    sfTexture_createFromFile("assets/menus/new_game/maxou_sprite.png", NULL);
    rpg->menu->main_menu->new_game->characters_txt[TIMO] =
    sfTexture_createFromFile("assets/menus/new_game/timo_sprite.png", NULL);
    rpg->menu->main_menu->new_game->characters_txt[LUDO] =
    sfTexture_createFromFile("assets/menus/new_game/ludo_sprite.png", NULL);
    rpg->menu->main_menu->new_game->characters_txt[SYLVIE] =
    sfTexture_createFromFile("assets/menus/new_game/sylvie_sprite.png", NULL);
}

void init_characters_sprites(rpg_t *rpg)
{
    sfIntRect rect = {259, 347};

    rpg->menu->main_menu->new_game->rect_characters = rect;
    rpg->menu->main_menu->new_game->characters = malloc(sizeof(sfSprite *) * 5);
    rpg->menu->main_menu->new_game->characters_txt =
    malloc(sizeof(sfTexture *) * 5);
    init_characters_textures(rpg);
    for (int i = MAXOU; i < NO_CHARACTERS; i++) {
        rpg->menu->main_menu->new_game->characters[i] = sfSprite_create();
        sfSprite_setTexture(rpg->menu->main_menu->new_game->characters[i],
        rpg->menu->main_menu->new_game->characters_txt[i], sfTrue);
        sfSprite_setPosition(rpg->menu->main_menu->new_game->characters[i],
        rpg->menu->main_menu->new_game->pos_characters[i]);
        sfSprite_setTextureRect(rpg->menu->main_menu->new_game->characters[i],
        rect);
    }
}