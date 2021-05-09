/*
** EPITECH PROJECT, 2021
** init player rect
** File description:
** init_player_rect.c
*/

#include "../../../include/func_name.h"

static void init_pleft_right_rect(rpg_t *rpg)
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

static int create_player_bis(rpg_t *rpg)
{
    if ((rpg->game->in_game->objects->player_tex = malloc(sizeof(sfTexture *)
    * 5)) == NULL)
        return (MALLOC_ERROR);
    rpg->game->in_game->objects->player_tex[MAXOU] = sfTexture_createFromFile
    ("assets/perso/policemen-maxime.png", NULL);
    rpg->game->in_game->objects->player_tex[SYLVIE] = sfTexture_createFromFile
    ("assets/perso/sylvie-policemen.png", NULL);
    rpg->game->in_game->objects->player_tex[TIMO] = sfTexture_createFromFile
    ("assets/perso/policemen-timo.png", NULL);
    rpg->game->in_game->objects->player_tex[LUDO] = sfTexture_createFromFile
    ("assets/perso/ludo-police.png", NULL);
    return (0);
}

static int create_player_rect(rpg_t *rpg)
{
    if (create_player_bis(rpg) == 84 ||
    (rpg->game->in_game->objects->players = malloc(sizeof(sfSprite *) * 5))
    == NULL || (rpg->game->in_game->map->speed = malloc(sizeof(int) * 4))
    == NULL)
        return (MALLOC_ERROR);
    for (int i = MAXOU; i <= SYLVIE; i++) {
        rpg->game->in_game->objects->players[i] = sfSprite_create();
        sfSprite_setTexture(rpg->game->in_game->objects->players[i],
        rpg->game->in_game->objects->player_tex[i], sfTrue);
    }
    rpg->game->in_game->map->speed[WALK_SPEED] = 3;
    rpg->game->in_game->map->speed[RUN_SPEED] = 4;
    rpg->game->in_game->map->speed[CAR_SPEED] = 5;
    return (0);
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
    if (create_player_rect(rpg) == MALLOC_ERROR)
        return (MALLOC_ERROR);
    set_player_rect(rpg);
    return (0);
}
