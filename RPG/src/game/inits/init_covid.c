/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** init_covid.c
*/

#include "../../../include/func_name.h"

void init_covid(rpg_t *rpg)
{
    sfTexture *vaccine_txt = sfTexture_createFromFile
    ("assets/inventory/vaccine.png", NULL);

    rpg->game->in_game->inventory->vaccine = sfSprite_create();
    sfSprite_setTexture(rpg->game->in_game->inventory->vaccine, vaccine_txt,
    sfTrue);
    sfSprite_setPosition(rpg->game->in_game->inventory->vaccine,
    put_in_vector2f(370.5, 547.2));
}

void init_bullet_proof(rpg_t *rpg)
{
    sfTexture *b_proof_txt = sfTexture_createFromFile
    ("assets/inventory/bullet_proof.png", NULL);

    rpg->game->in_game->inventory->weapon[BPVEST] = sfSprite_create();
    sfSprite_setTexture(rpg->game->in_game->inventory->weapon[BPVEST],
    b_proof_txt, sfTrue);
    sfSprite_setPosition(rpg->game->in_game->inventory->weapon[BPVEST],
    put_in_vector2f(rpg->game->in_game->map->pos_map[MAP_WARREN].x
    + 2362, rpg->game->in_game->map->pos_map[MAP_WARREN].y + 2462));

}

static void positions_items(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->game->in_game->inventory->weapon[GUN],
    put_in_vector2f(rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].x
    + 1752, rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].y + 3384));
    sfSprite_setPosition(rpg->game->in_game->inventory->weapon[BPVEST],
    put_in_vector2f(rpg->game->in_game->map->pos_map[MAP_WARREN].x
    + 2362, rpg->game->in_game->map->pos_map[MAP_WARREN].y + 2462));
}

void init_stuff(rpg_t *rpg)
{
    rpg->game->in_game->stuff->stuff_status = malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++)
        rpg->game->in_game->stuff->stuff_status[i] = FALSE;
    sfSprite_setPosition(rpg->game->in_game->inventory->weapon[SMG],
    put_in_vector2f(rpg->game->in_game->map->pos_map[MAP_OUTSIDE_DISCO].x
    + 1670, rpg->game->in_game->map->pos_map[MAP_OUTSIDE_DISCO].y + 2810));
    sfSprite_setPosition(rpg->game->in_game->inventory->weapon[TAZER],
    put_in_vector2f(rpg->game->in_game->map->pos_map[MAP_OUTSIDE_CDC].x
    + 1689, rpg->game->in_game->map->pos_map[MAP_OUTSIDE_CDC].y + 2665));
    sfSprite_setPosition(rpg->game->in_game->inventory->weapon[KNIFE],
    put_in_vector2f(rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE].x
    + 2044, rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE].y + 2006));
    positions_items(rpg);
}