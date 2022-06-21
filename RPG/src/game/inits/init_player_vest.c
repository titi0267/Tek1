/*
** EPITECH PROJECT, 2021
** init_player_vest.c
** File description:
** init_player_vest.c
*/

#include "../../../include/func_name.h"

static void set_player_rect_vest(rpg_t *rpg)
{
    sfSprite_setTextureRect(rpg->game->in_game->objects->player_vest
    [rpg->menu->main_menu->new_game->character_chosen],
    rpg->menu->main_menu->new_game->char_in_game[UP]);
    sfSprite_setTextureRect(rpg->game->in_game->objects->player_vest
    [rpg->menu->main_menu->new_game->character_chosen],
    rpg->menu->main_menu->new_game->char_in_game[LEFT]);
    sfSprite_setTextureRect(rpg->game->in_game->objects->player_vest
    [rpg->menu->main_menu->new_game->character_chosen],
    rpg->menu->main_menu->new_game->char_in_game[RIGHT]);
    sfSprite_setTextureRect(rpg->game->in_game->objects->player_vest
    [rpg->menu->main_menu->new_game->character_chosen],
    rpg->menu->main_menu->new_game->char_in_game[DOWN]);
}

static int vest_player_tex(rpg_t *rpg)
{
    if ((rpg->game->in_game->objects->player_vest_tex =
    malloc(sizeof(sfTexture *) * 5)) == NULL)
        return (MALLOC_ERROR);
    rpg->game->in_game->objects->player_vest_tex[MAXOU] =
    sfTexture_createFromFile
    ("assets/perso/bpvest/policemengilet-maxime.png", NULL);
    rpg->game->in_game->objects->player_vest_tex[SYLVIE] =
    sfTexture_createFromFile
    ("assets/perso/bpvest/sylvie-policemengilet.png", NULL);
    rpg->game->in_game->objects->player_vest_tex[TIMO] =
    sfTexture_createFromFile
    ("assets/perso/bpvest/policemengilet-timopsd.png", NULL);
    rpg->game->in_game->objects->player_vest_tex[LUDO] =
    sfTexture_createFromFile
    ("assets/perso/bpvest/policemengilet-ludo.png", NULL);
    return (0);
}

int create_player_vest(rpg_t *rpg)
{
    if (vest_player_tex(rpg) == MALLOC_ERROR ||
    (rpg->game->in_game->objects->player_vest = malloc(sizeof(sfSprite *) * 5))
    == NULL)
        return (MALLOC_ERROR);
    for (int i = MAXOU; i <= SYLVIE; i++) {
        rpg->game->in_game->objects->player_vest[i] = sfSprite_create();
        sfSprite_setTexture(rpg->game->in_game->objects->player_vest[i],
        rpg->game->in_game->objects->player_vest_tex[i], sfTrue);
    }
    set_player_rect_vest(rpg);
    return (0);
}
