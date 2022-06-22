/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** move_enemy
*/

#include "../../../include/func_name.h"

static void move_enemies_map_next(rpg_t *rpg, int direction)
{
    if (direction == LEFT)
        rpg->game->in_game->nmi_list->nmi_pos.x +=
        rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status];
    if (direction == RIGHT)
        rpg->game->in_game->nmi_list->nmi_pos.x -=
        rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status];
    if (direction == DOWN)
        rpg->game->in_game->nmi_list->nmi_pos.y -=
        rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status];
    if (direction == UP)
        rpg->game->in_game->nmi_list->nmi_pos.y +=
        rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status];
}

void move_enemies_on_map(rpg_t *rpg, int direction)
{
    rpg->game->in_game->nmi_list = *(rpg->game->in_game->nmi);
    for (; rpg->game->in_game->nmi_list != NULL;
    rpg->game->in_game->nmi_list = rpg->game->in_game->nmi_list->next) {
        move_enemies_map_next(rpg, direction);
        sfSprite_setPosition(rpg->game->in_game->nmi_list->yellow_man,
        rpg->game->in_game->nmi_list->nmi_pos);
    }
}

int move_enemies(rpg_t *rpg)
{
    static float nbr = 0;

    rpg->game->in_game->nmi_list = *(rpg->game->in_game->nmi);
    nbr += rpg->basic->cnf->clk->time_loop;
    if (nbr >= 10) {
        if (spawn_enemies(rpg) == MALLOC_ERROR)
            return (MALLOC_ERROR);
        nbr = 0;
    }
    for (; rpg->game->in_game->nmi_list != NULL;
    rpg->game->in_game->nmi_list = rpg->game->in_game->nmi_list->next) {
        detect_player(rpg);
        sfSprite_setPosition(rpg->game->in_game->nmi_list->yellow_man,
        rpg->game->in_game->nmi_list->nmi_pos);
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->nmi_list->yellow_man, NULL);
    }
    return (0);
}