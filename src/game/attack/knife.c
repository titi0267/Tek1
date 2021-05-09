/*
** EPITECH PROJECT, 2021
** knife
** File description:
** knife
*/

#include "../../../include/func_name.h"

void draw_knife(rpg_t *rpg)
{
    if (rpg->game->in_game->map->last_pos == RIGHT)
        sfSprite_setPosition(rpg->game->in_game->objects->knife,
        put_in_vector2f(980, 502));
    if (rpg->game->in_game->map->last_pos == LEFT) {
        sfSprite_setRotation(rpg->game->in_game->objects->knife, 180);
        sfSprite_setPosition(rpg->game->in_game->objects->knife,
        put_in_vector2f(940, 582));
    }
    if (rpg->game->in_game->map->last_pos == UP) {
        sfSprite_setRotation(rpg->game->in_game->objects->knife, 270);
        sfSprite_setPosition(rpg->game->in_game->objects->knife,
        put_in_vector2f(920, 492));
    }
    if (rpg->game->in_game->map->last_pos == DOWN) {
        sfSprite_setRotation(rpg->game->in_game->objects->knife, 90);
        sfSprite_setPosition(rpg->game->in_game->objects->knife,
        put_in_vector2f(1000, 572));
    }
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->game->in_game->objects->knife, NULL);
    sfSprite_setRotation(rpg->game->in_game->objects->knife, 0);
}

static void attack_cut2(rpg_t *rpg, enemy_t *nmi_list)
{
    if (rpg->game->in_game->map->last_pos == UP &&
    ((nmi_list->nmi_pos.x > 930 && nmi_list->nmi_pos.x < 990) &&
    (nmi_list->nmi_pos.y < 485 && nmi_list->nmi_pos.y > 385))) {
        nmi_list->life -=
        rpg->game->in_game->stats->player_stats[P_DAMAGE]->total_value;
        nmi_list->blooding = 1;
    }
    if (rpg->game->in_game->map->last_pos == DOWN &&
    ((nmi_list->nmi_pos.x > 930 && nmi_list->nmi_pos.x < 990) &&
    (nmi_list->nmi_pos.y > 593 && nmi_list->nmi_pos.y < 693))) {
        nmi_list->life -=
        rpg->game->in_game->stats->player_stats[P_DAMAGE]->total_value;
        nmi_list->blooding = 1;
    }
}

void attack_cut(rpg_t *rpg, enemy_t *nmi_list)
{
    if (rpg->game->in_game->map->last_pos == RIGHT &&
    ((nmi_list->nmi_pos.x < 1100 && nmi_list->nmi_pos.x > 990) &&
    (nmi_list->nmi_pos.y > 485 && nmi_list->nmi_pos.y < 593))) {
        nmi_list->life -=
        rpg->game->in_game->stats->player_stats[P_DAMAGE]->total_value;
        nmi_list->blooding = 1;
    }
    if (rpg->game->in_game->map->last_pos == LEFT &&
    ((nmi_list->nmi_pos.x > 830 && nmi_list->nmi_pos.x < 930) &&
    (nmi_list->nmi_pos.y > 485 && nmi_list->nmi_pos.y < 593))) {
        nmi_list->life -=
        rpg->game->in_game->stats->player_stats[P_DAMAGE]->total_value;
        nmi_list->blooding = 1;
    }
    attack_cut2(rpg, nmi_list);
}