/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** bullet_init
*/

#include "../../../include/func_name.h"

static void dispawn_bullet(rpg_t *rpg, bullets_t *bullet_list)
{
    if (rpg->game->in_game->map->last_pos == DOWN)
        bullet_list->finish_line = 300;
    if (rpg->game->in_game->map->last_pos == UP)
        bullet_list->finish_line = 300;
    if (rpg->game->in_game->map->last_pos == LEFT)
        bullet_list->finish_line = 300;
    if (rpg->game->in_game->map->last_pos == RIGHT)
        bullet_list->finish_line = 300;
}

void set_bullet_value(rpg_t *rpg, bullets_t *bullet_list)
{
    sfTexture *bullet = sfTexture_createFromFile
    ("assets/inventory/bullet_in_gm.png", NULL);
    sfTexture *bullet_blue = sfTexture_createFromFile
    ("assets/inventory/bullet_taz.png", NULL);

    bullet_list->bullet = sfSprite_create();
    if (rpg->game->in_game->inventory->area_contains[WEAPON] == TAZER)
        sfSprite_setTexture(bullet_list->bullet, bullet_blue, sfTrue);
    else
        sfSprite_setTexture(bullet_list->bullet, bullet, sfTrue);
    bullet_list->bullet_pos = put_in_vector2f(950, 532);
    sfSprite_setPosition(bullet_list->bullet,
    bullet_list->bullet_pos);
    bullet_list->bullet_dir =
    rpg->game->in_game->map->last_pos;
}

int init_bullet(rpg_t *rpg)
{
    static int i = 0;

    rpg->game->in_game->bullet_list = *(rpg->game->in_game->bullet);
    if ((rpg->game->in_game->bullet_list = malloc(sizeof
    (*rpg->game->in_game->bullet_list))) == NULL)
        return (MALLOC_ERROR);
    set_bullet_value(rpg, rpg->game->in_game->bullet_list);
    rpg->game->in_game->bullet_list->nbr = i;
    dispawn_bullet(rpg, rpg->game->in_game->bullet_list);
    rpg->game->in_game->bullet_list->next = *(rpg->game->in_game->bullet);
    *(rpg->game->in_game->bullet) = rpg->game->in_game->bullet_list;
    i++;
    return (0);
}

void pop_bullet(rpg_t *rpg, bullets_t *bullet_list)
{
    int del_nbr = bullet_list->nbr;
    bullets_t *bullet_prev = NULL;
    bullet_list = *rpg->game->in_game->bullet;

    if (*rpg->game->in_game->bullet == NULL)
        return;
    while (bullet_list->nbr != del_nbr) {
        if (bullet_list->next == NULL)
            return;
        else {
            bullet_prev = bullet_list;
            bullet_list = bullet_list->next;
        }
    }
    if (bullet_list == *rpg->game->in_game->bullet)
        *(rpg->game->in_game->bullet) = (*rpg->game->in_game->bullet)->next;
    else {
        bullet_prev->next = bullet_list->next;
        bullet_list->next = NULL;
    }
}

void bullet_direction(rpg_t *rpg, bullets_t *bullet_list)
{
    if (bullet_list->bullet_dir == UP) {
        if (rpg->game->in_game->bullet_list->finish_line <= 0)
            pop_bullet(rpg, bullet_list);
        move_bullet_up(rpg, bullet_list);
    }
    if (bullet_list->bullet_dir == DOWN) {
        if (rpg->game->in_game->bullet_list->finish_line <= 0)
            pop_bullet(rpg, bullet_list);
        move_bullet_down(rpg, bullet_list);
    }
    if (bullet_list->bullet_dir == LEFT) {
        if (rpg->game->in_game->bullet_list->finish_line <= 0)
            pop_bullet(rpg, bullet_list);
        move_bullet_left(rpg, bullet_list);
    }
    if (bullet_list->bullet_dir == RIGHT) {
        if (rpg->game->in_game->bullet_list->finish_line <= 0)
            pop_bullet(rpg, bullet_list);
        move_bullet_right(rpg, bullet_list);
    }
}