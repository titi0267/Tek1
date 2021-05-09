/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** new_enemy
*/

#include "../../../include/func_name.h"

void begin_nmi_spawn(rpg_t *rpg)
{
    for (int i = 0; i < 6; i++)
        spawn_enemies(rpg);
}

int add_nmi(rpg_t *rpg, int x, int y)
{
    static int i = 0;
    sfColor color;

    if ((rpg->game->in_game->nmi_list = malloc(sizeof
    (*rpg->game->in_game->nmi_list))) == NULL)
        return (MALLOC_ERROR);
    if (init_yellow_man(rpg) == 84)
        return (MALLOC_ERROR);
    rpg->game->in_game->nmi_list->nmi_pos =
    put_in_vector2f((float)x, (float)y);
    sfSprite_setPosition(rpg->game->in_game->nmi_list->yellow_man,
    rpg->game->in_game->nmi_list->nmi_pos);
    if (rpg->game->in_game->game_status >= GM_NOTIF7)
        rpg->game->in_game->nmi_list->life = 150;
    else
        rpg->game->in_game->nmi_list->life = 100;
    rpg->game->in_game->nmi_list->nbr = i;
    rpg->game->in_game->nmi_list->blooding = 0;
    rpg->game->in_game->nmi_list->blood = 0;
    sfSprite_setColor(rpg->game->in_game->nmi_list->yellow_man, sfWhite);
    if (rpg->game->in_game->objects->color_a == 1) {
        color.r = 128;
        color.g = 128;
        color.b = 128;
        color.a = 80;
        sfSprite_setColor(rpg->game->in_game->nmi_list->yellow_man, color);
    }
    i++;
    rpg->game->in_game->nmi_list->next = *rpg->game->in_game->nmi;
    *rpg->game->in_game->nmi = rpg->game->in_game->nmi_list;
    return (0);
}

int spawn_enemy_next(rpg_t *rpg, int x, int y)
{
    sfColor color;

    y += 85;
    for (int z = x; x != (z + 60); x++) {
        color = sfImage_getPixel(rpg->game->in_game->map->collisions
        [rpg->game->in_game->map->status], (unsigned int)x,
        (unsigned int)y);
        if (check_color(rpg, color) == COLLISION)
            break;
        if (x >= z + 59) {
            if (check_color(rpg, color) == BEHIND)
                rpg->game->in_game->objects->color_a = 1;
            else
                rpg->game->in_game->objects->color_a = 0;
            return (1);
        }
    }
    return (0);
}

int spawn_enemies(rpg_t *rpg)
{
    int x = 0;
    int y = 0;

    while (1) {
        x = rand() % 4900;
        y = rand() % 4900;
        if (spawn_enemy_next(rpg, x, y) == 1)
            break;
    }
    x += rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status].x;
    y += rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status].y;
    return (add_nmi(rpg, x, y));
}
