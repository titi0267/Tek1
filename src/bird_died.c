/*
** EPITECH PROJECT, 2021
** bird died by Timothy CONIEL
** File description:
** bird_died.c
*/
#include "../include/my.h"

void bird_fall_speed(player_t *bird)
{
    if (bird->position.y <= 200 && bird->position.y > 0) {
        bird->fall_dead = 13;
        bird->angle_down = 2;
        bird->stop = 1;
    }
    if (bird->position.y < 400 && bird->position.y > 200) {
        bird->fall_dead = 8;
        bird->angle_down = 3;
        bird->stop = 1;
    }
    if (bird->position.y < 550 && bird->position.y >= 400) {
        bird->fall_dead = 6;
        bird->angle_down = 4;
        bird->stop = 1;
    }
    if (bird->position.y >= 550 && bird->position.y <= 720) {
        bird->fall_dead = 3;
        bird->angle_down = 5;
        bird->stop = 1;
    }
}

void bird_fall_death(player_t *bird, window_t *windo)
{
    float angle_bottom = bird->rotation;

    if (bird->position.y < 0)
        bird->position.y = 0;
    if (bird->stop == 0)
        bird_fall_speed(bird);
    if (bird->position.y < 720) {
        bird->position.y += bird->fall_dead;
        if (bird->angle <= 85)
            bird->angle += bird->angle_down;
    }
    if (bird->position.y >= 720 && bird->stop == 0) {
        sfSprite_setRotation(bird->my_bird, angle_bottom);
        bird->stop = 1;
    } else
        sfSprite_setRotation(bird->my_bird, bird->angle);
    sfSprite_setPosition(bird->my_bird, bird->position);
    sfRenderWindow_drawSprite(windo->window, bird->my_bird, NULL);
}

void game_over(menu_t *menu)
{
    menu->gm_ovr = sfSprite_create();
    menu->game_ovr = sfTexture_createFromFile("png/game_over.png", NULL);
    sfVector2f scale = {5, 5};

    menu->pos_death.x = 400;
    menu->pos_death.y = 200;
    sfSprite_setTexture(menu->gm_ovr, menu->game_ovr, sfFalse);
    sfSprite_setScale(menu->gm_ovr, scale);
    sfSprite_setPosition(menu->gm_ovr, menu->pos_death);
}

void update_gm_over(gather_t *gather)
{
    static float nbr = 0;
    static int button_black = 0;

    if (gather->menu.change_button == 0) {
        sfRenderWindow_drawSprite(gather->windo.window, gather->menu.gm_ovr, NULL);
        sfRenderWindow_drawSprite(gather->windo.window, gather->menu.button, NULL);
    } else {
        if (nbr > 0.1) {
            if (gather->menu.black_scale.x <= 5 && gather->menu.black_scale.y <= 5) {
                gather->menu.black_scale.x += 0.2f;
                gather->menu.black_scale.y += 0.2f;
                gather->menu.pos_black.x -= 6.125f;
                gather->menu.pos_black.y -= 3.5;
            }
            sfSprite_setPosition(gather->menu.black_but, gather->menu.pos_black);
            sfSprite_setScale(gather->menu.black_but, gather->menu.black_scale);
            button_black = 1;
            nbr = 0;
        }
        if (button_black == 1) {
            sfRenderWindow_drawSprite(gather->windo.window, gather->menu.black_but, NULL);
            sfRenderWindow_drawSprite(gather->windo.window, gather->menu.load, NULL);
        }
        nbr += gather->time.delta_time;
    }
}

void restart(gather_t *gather, map_t *buff)
{
    if (gather->menu.black_scale.x >= 5 || gather->menu.black_scale.y >= 5)
        gather->menu.restart = 1;
    if (gather->menu.restart == 1)
        re_init(gather, buff);
}