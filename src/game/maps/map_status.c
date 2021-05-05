/*
** EPITECH PROJECT, 2021
** chose map
** File description:
** map_status.c
*/

#include "../../../include/func_name.h"

void destroy_enemies(rpg_t *rpg)
{
    rpg->game->in_game->nmi_list = *(rpg->game->in_game->nmi);
    for (; rpg->game->in_game->nmi_list != NULL;
    rpg->game->in_game->nmi_list = rpg->game->in_game->nmi_list->next) {
        sfSprite_destroy(rpg->game->in_game->nmi_list->yellow_man);
        free(rpg->game->in_game->nmi_list->nmi_rect);
        free(rpg->game->in_game->nmi_list->offset_nmi);
        free(rpg->game->in_game->nmi_list);
    }
    *(rpg->game->in_game->nmi) = NULL;
}

void print_map(rpg_t *rpg, int on_map)
{
    int map_status = rpg->game->in_game->map->status;

    if (rpg->menu->status == ON_GAME &&
    !on_cine(rpg)) {
        player_run(rpg);
        move_left_map(rpg, on_map);
    }
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->game->in_game->map->maps[on_map], NULL);
    if (rpg->game->in_game->map->status != MAP_INSIDE_POLICE)
        move_enemies(rpg);
    if (map_status != rpg->game->in_game->map->status &&
    rpg->game->in_game->map->status != MAP_INSIDE_POLICE && map_status != MAP_INSIDE_POLICE)
        destroy_enemies(rpg);
    print_player_move(rpg);
}

void chose_map(rpg_t *rpg)
{
    print_map(rpg, rpg->game->in_game->map->status);
}