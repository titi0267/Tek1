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
    for (int d = UP; d <=  LEFT; d++) {
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

    //if (rpg->game->in_game->map->status != MAP_INSIDE_POLICE) {
        while (1) {
            x = rand() % 5000;
            y = rand() % 5000;
            color = sfImage_getPixel(rpg->game->in_game->map->collisions
            [rpg->game->in_game->map->status], (unsigned int)x,
            (unsigned int)y);
            if (check_color(rpg, color) != COLLISION)
                break;
        }
        x = (x) + rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status].x;
        y = (y) + rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status].y;
        add_nmi(rpg, x, y);
   // }
}

void move_enemies_on_map(rpg_t *rpg, int direction)
{
    rpg->game->in_game->nmi_list = *(rpg->game->in_game->nmi);

    for (int i = 0; rpg->game->in_game->nmi_list != NULL; rpg->game->in_game->nmi_list
    = rpg->game->in_game->nmi_list->next, i++) {
        if (direction == LEFT)
            rpg->game->in_game->nmi_list->nmi_pos.x += rpg->game->in_game->map->speed
            [rpg->game->in_game->objects->speed_status];
        if (direction == RIGHT)
            rpg->game->in_game->nmi_list->nmi_pos.x -= rpg->game->in_game->map->speed
            [rpg->game->in_game->objects->speed_status];
        if (direction == DOWN)
            rpg->game->in_game->nmi_list->nmi_pos.y -= rpg->game->in_game->map->speed
            [rpg->game->in_game->objects->speed_status];
        if (direction == UP)
            rpg->game->in_game->nmi_list->nmi_pos.y += rpg->game->in_game->map->speed
            [rpg->game->in_game->objects->speed_status];
        sfSprite_setPosition(rpg->game->in_game->nmi_list->yellow_man, rpg->game->in_game->nmi_list->nmi_pos);
    }
}

void rect_move_enemy(rpg_t *rpg, int direction, enemy_t *nmi_list)
{
    if (rpg->game->in_game->nmi_list->clock_rect > 0.4) {
        nmi_list->nmi_rect[direction].left =
        (nmi_list->offset_nmi[direction] *
        nmi_list->nmi_rect[direction].width);
        rpg->game->in_game->nmi_list->clock_rect = 0;
        nmi_list->offset_nmi[direction]++;
    }
    if (nmi_list->offset_nmi[direction] > 2)
        nmi_list->offset_nmi[direction] = 0;
    rpg->game->in_game->nmi_list->clock_rect += rpg->basic->cnf->clk->time_loop;
}

void detect_player(rpg_t *rpg)
{
    sfVector2f pos;

    pos = vect_diff(rpg->game->in_game->nmi_list->nmi_pos, put_in_vector2f(
    930,
    486));
    if (pos.x < 0)
        pos.x *= -1;
    if (pos.y < 0)
        pos.y *= -1;
    if (pos.x < 300 && pos.y < 300)
        printf("In range ! (%f, %f)\n", pos.x, pos.y);
}

void move_enemies(rpg_t *rpg)
{
    static float nbr = 0;

    rpg->game->in_game->nmi_list = *(rpg->game->in_game->nmi);
    nbr += rpg->basic->cnf->clk->time_loop;
    if (nbr >= 20) {
        spawn_enemies(rpg);
        nbr = 0;
        printf("Spawned\n");
    }
    for (int i = 0; rpg->game->in_game->nmi_list != NULL; rpg->game->in_game->nmi_list
    = rpg->game->in_game->nmi_list->next, i++) {
        rect_move_enemy(rpg, DOWN, rpg->game->in_game->nmi_list);
        sfSprite_setTextureRect(rpg->game->in_game->nmi_list->yellow_man,
        rpg->game->in_game->nmi_list->nmi_rect[DOWN]);
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->nmi_list->yellow_man, NULL);
        detect_player(rpg);
    }
}