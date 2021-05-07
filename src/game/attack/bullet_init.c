/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** bullet_init
*/

#include "../../../include/func_name.h"

int init_bullet(rpg_t *rpg)
{
    sfTexture *bullet = sfTexture_createFromFile
    ("assets/inventory/bullet_in_gm.png", NULL);
    static int i = 0;

    rpg->game->in_game->bullet_list = *(rpg->game->in_game->bullet);
    if ((rpg->game->in_game->bullet_list = malloc(sizeof
    (*rpg->game->in_game->bullet_list))) == NULL)
        return (MALLOC_ERROR);
    rpg->game->in_game->bullet_list->bullet = sfSprite_create();
    sfSprite_setTexture(rpg->game->in_game->bullet_list->bullet,
    bullet, sfTrue);
    rpg->game->in_game->bullet_list->bullet_pos = put_in_vector2f(950, 532);
    sfSprite_setPosition(rpg->game->in_game->bullet_list->bullet,
    rpg->game->in_game->bullet_list->bullet_pos);
    rpg->game->in_game->bullet_list->bullet_dir =
    rpg->game->in_game->map->last_pos;
    rpg->game->in_game->bullet_list->nbr = i;
    //printf("bullet %i\n", )
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
    while(bullet_list->nbr != del_nbr) {
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
        //free(bullet_list);
    }
}

void bullet_direction(rpg_t *rpg, bullets_t *bullet_list)
{
    if (bullet_list->bullet_dir == UP) {
        if (bullet_list->bullet_pos.y <= 200)
            pop_bullet(rpg, bullet_list);
        move_bullet_up(rpg, bullet_list);
    }
    if (bullet_list->bullet_dir == DOWN) {
        if (bullet_list->bullet_pos.y >= 800)
            pop_bullet(rpg, bullet_list);
        move_bullet_down(rpg, bullet_list);
    }
    if (bullet_list->bullet_dir == LEFT) {
        if (bullet_list->bullet_pos.x <= 200)
            pop_bullet(rpg, bullet_list);
        move_bullet_left(rpg, bullet_list);
    }
    if (bullet_list->bullet_dir == RIGHT) {
        if (bullet_list->bullet_pos.x >= 1600)
            pop_bullet(rpg, bullet_list);
        move_bullet_right(rpg, bullet_list);
    }
}

void draw_bullet(rpg_t *rpg)
{
    rpg->game->in_game->bullet_list = *(rpg->game->in_game->bullet);

    for (; rpg->game->in_game->bullet_list != NULL;
    rpg->game->in_game->bullet_list = rpg->game->in_game->bullet_list->next) {
        sfSprite_setPosition(rpg->game->in_game->bullet_list->bullet,
        rpg->game->in_game->bullet_list->bullet_pos);
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->bullet_list->bullet, NULL);
        bullet_direction(rpg, rpg->game->in_game->bullet_list);
    }
}