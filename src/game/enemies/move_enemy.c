/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** move_enemy
*/

#include "../../../include/func_name.h"

void enemy_stop(rpg_t *rpg)
{
    if (rpg->game->in_game->nmi_list->last_pos != -1) {
        rpg->game->in_game->nmi_list->nmi_rect
        [rpg->game->in_game->nmi_list->last_pos].left = 58;
        sfSprite_setTextureRect(rpg->game->in_game->nmi_list->yellow_man,
        rpg->game->in_game->nmi_list->nmi_rect[rpg->game->in_game->nmi_list->last_pos]);
    }
    for (int d = UP; d <=  RIGHT; d++) {
        rpg->game->in_game->nmi_list->nmi_rect[d].left = 58;
        rpg->game->in_game->nmi_list->offset_nmi[d] = 0;
    }
}

int add_nmi(rpg_t *rpg, int x, int y)
{
    if ((rpg->game->in_game->nmi_list = malloc(sizeof
    (*rpg->game->in_game->nmi_list))) == NULL)
        return (MALLOC_ERROR);
    if (init_yellow_man(rpg) == 84)
        return (MALLOC_ERROR);
    rpg->game->in_game->nmi_list->nmi_pos =
    put_in_vector2f((float)x, (float)y);
    sfSprite_setPosition(rpg->game->in_game->nmi_list->yellow_man,
    rpg->game->in_game->nmi_list->nmi_pos);
    rpg->game->in_game->nmi_list->next = *rpg->game->in_game->nmi;
    *rpg->game->in_game->nmi = rpg->game->in_game->nmi_list;
    return (0);
}

void spawn_enemies(rpg_t *rpg)
{
    int x = 0;
    int y = 0;
    sfColor color;

    if (rpg->game->in_game->map->status != MAP_INSIDE_POLICE) {
            x = rand() % 5000;
            y = rand() % 5000;
        /*while (1) {
            x = rand() % 5000;
            y = rand() % 5000;
            printf("x = %i & y = %i\n", x, y);
            /*color = sfImage_getPixel(rpg->game->in_game->map->collisions
            [rpg->game->in_game->map->status], (unsigned int)((x * -1)
            + rpg->game->in_game->map->col_real[rpg->game->in_game->map->status].x),
            (unsigned int)(y * -1) + rpg->game->in_game->map->col_real
            [rpg->game->in_game->map->status].y);
            if (check_color(rpg, color) != COLLISION)
                break;
        }*/
        printf("SORTI : x = %i & y = %i\n", x, y);
        printf("Player : x = %f & y = %f\n", rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status].x, rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status].y);
        add_nmi(rpg, x, y);
    }
}

void move_enemies(rpg_t *rpg)
{
    rpg->game->in_game->nmi_list = *(rpg->game->in_game->nmi);
    static float nbr = 0;

    nbr += rpg->basic->cnf->clk->time_loop;
    if (nbr >= 10) {
        spawn_enemies(rpg);
        nbr = 0;
    }
    for (int i = 0; rpg->game->in_game->nmi_list != NULL; rpg->game->in_game->nmi_list
    = rpg->game->in_game->nmi_list->next, i++) {
        //if (range > 300) enemy_stop(rpg);
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->nmi_list->yellow_man, NULL);
        //printf("spawn enemy nbr = %i", i);
    }
    //if (player passe en x = ? & y = ? sur map nbr ?) add new enemy a list
    //
}