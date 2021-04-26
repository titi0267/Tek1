/*
** EPITECH PROJECT, 2021
** init player rect
** File description:
** init_player_rect.c
*/

#include "../../../include/func_name.h"

void init_pleft_right_rect(rpg_t *rpg)
{
    rpg->menu->main_menu->new_game->char_in_game[LEFT].left = 100;
    rpg->menu->main_menu->new_game->char_in_game[LEFT].top = 326;
    rpg->menu->main_menu->new_game->char_in_game[LEFT].width = 60;
    rpg->menu->main_menu->new_game->char_in_game[LEFT].height = 108;
    rpg->menu->main_menu->new_game->char_in_game[RIGHT].left = 100;
    rpg->menu->main_menu->new_game->char_in_game[RIGHT].top = 580;
    rpg->menu->main_menu->new_game->char_in_game[RIGHT].width = 60;
    rpg->menu->main_menu->new_game->char_in_game[RIGHT].height = 108;
}

void set_player_rect(rpg_t *rpg)
{
    sfSprite_setTextureRect(rpg->game->in_game->objects->players
    [rpg->menu->main_menu->new_game->character_chosen],
    rpg->menu->main_menu->new_game->char_in_game[UP]);
    sfSprite_setTextureRect(rpg->game->in_game->objects->players
    [rpg->menu->main_menu->new_game->character_chosen],
    rpg->menu->main_menu->new_game->char_in_game[LEFT]);
    sfSprite_setTextureRect(rpg->game->in_game->objects->players
    [rpg->menu->main_menu->new_game->character_chosen],
    rpg->menu->main_menu->new_game->char_in_game[RIGHT]);
    sfSprite_setTextureRect(rpg->game->in_game->objects->players
    [rpg->menu->main_menu->new_game->character_chosen],
    rpg->menu->main_menu->new_game->char_in_game[DOWN]);
}

void create_player_rect(rpg_t *rpg)
{
    sfTexture *maxou = sfTexture_createFromFile
    ("assets/perso/policemen-maxime.png", NULL);
    sfTexture *sylvie = sfTexture_createFromFile
    ("assets/perso/sylvie-policemen.png", NULL);
    sfTexture *titi = sfTexture_createFromFile
    ("assets/perso/policemen-timo.png", NULL);
    sfTexture *ludo = sfTexture_createFromFile
    ("assets/perso/ludo-police.png", NULL);

    rpg->game->in_game->objects->players = malloc(sizeof(sfSprite *) * 5);
    for (int i = MAXOU; i <= SYLVIE; i++)
        rpg->game->in_game->objects->players[i] = sfSprite_create();
    sfSprite_setTexture(rpg->game->in_game->objects->players[MAXOU],
    maxou, sfTrue);
    sfSprite_setTexture(rpg->game->in_game->objects->players[TIMO],
    titi, sfTrue);
    sfSprite_setTexture(rpg->game->in_game->objects->players[LUDO],
    ludo, sfTrue);
    sfSprite_setTexture(rpg->game->in_game->objects->players[SYLVIE],
    sylvie, sfTrue);
}

int init_pdown_up_rect(rpg_t *rpg)
{
    rpg->menu->main_menu->new_game->character_chosen = rand() % 4;
    if ((rpg->menu->main_menu->new_game->char_in_game =
    malloc(sizeof(sfIntRect) * 5)) == NULL)
        return (MALLOC_ERROR);
    rpg->menu->main_menu->new_game->char_in_game[DOWN].left = 100;
    rpg->menu->main_menu->new_game->char_in_game[DOWN].top = 72;
    rpg->menu->main_menu->new_game->char_in_game[DOWN].width = 60;
    rpg->menu->main_menu->new_game->char_in_game[DOWN].height = 108;
    rpg->menu->main_menu->new_game->char_in_game[UP].left = 100;
    rpg->menu->main_menu->new_game->char_in_game[UP].top = 840;
    rpg->menu->main_menu->new_game->char_in_game[UP].width = 60;
    rpg->menu->main_menu->new_game->char_in_game[UP].height = 108;
    init_pleft_right_rect(rpg);
    create_player_rect(rpg);
    set_player_rect(rpg);
    return (0);
}

