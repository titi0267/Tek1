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
    rpg->game->in_game->bullet_list->nbr++;
    rpg->game->in_game->bullet_list->next = *(rpg->game->in_game->bullet);
    *(rpg->game->in_game->bullet) = rpg->game->in_game->bullet_list;
    return (0);
}

void pop_bullet(rpg_t *rpg, bullets_t *bullet_list)
{
    if (bullet_list == *(rpg->game->in_game->bullet)) {
        *(rpg->game->in_game->bullet) = (*rpg->game->in_game->bullet)->next;
        sfSprite_destroy(rpg->game->in_game->bullet_list->bullet);
        free(bullet_list);
        return;
    }
    bullet_list->next = bullet_list->next->next;
    sfSprite_destroy(rpg->game->in_game->bullet_list->bullet);
    free(rpg->game->in_game->bullet_list);
}

void bullet_direction(rpg_t *rpg, bullets_t *bullet_list)
{
    if (bullet_list->bullet_dir == UP) {
        if (bullet_list->bullet_pos.y <= 50)
            pop_bullet(rpg, bullet_list);
        move_bullet_up(rpg, bullet_list);
    }
    if (bullet_list->bullet_dir == DOWN) {
        if (bullet_list->bullet_pos.y >= 1080)
            pop_bullet(rpg, bullet_list);
        move_bullet_down(rpg, bullet_list);
    }
    if (bullet_list->bullet_dir == LEFT) {
        if (bullet_list->bullet_pos.y <= 0)
            pop_bullet(rpg, bullet_list);
        move_bullet_left(rpg, bullet_list);
    }
    if (bullet_list->bullet_dir == RIGHT) {
        if (bullet_list->bullet_pos.y >= 1920)
            pop_bullet(rpg, bullet_list);
        move_bullet_right(rpg, bullet_list);
    }
}

void draw_bullet(rpg_t *rpg)
{
    rpg->game->in_game->bullet_list = *(rpg->game->in_game->bullet);

    for (; rpg->game->in_game->bullet_list != NULL;
    rpg->game->in_game->bullet_list = rpg->game->in_game->bullet_list->next) {
        bullet_direction(rpg, rpg->game->in_game->bullet_list);
        sfSprite_setPosition(rpg->game->in_game->bullet_list->bullet,
        rpg->game->in_game->bullet_list->bullet_pos);
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->bullet_list->bullet, NULL);
    }
}