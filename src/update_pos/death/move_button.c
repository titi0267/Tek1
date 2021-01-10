/*
** EPITECH PROJECT, 2021
** move button by Timothy CONIEL
** File description:
** move_button.c
*/
#include "../../../include/my.h"

void move_black(gather_t *gather)
{
    if (gather->menu.black_scale.x <= 5 && gather->menu.black_scale.y <= 5) {
        gather->menu.black_scale.x += 0.2f;
        gather->menu.black_scale.y += 0.2f;
        gather->menu.pos_black.x -= 6.125f;
        gather->menu.pos_black.y -= 3.5;
    }
    sfSprite_setPosition(gather->menu.black_but, gather->menu.pos_black);
    sfSprite_setScale(gather->menu.black_but, gather->menu.black_scale);
}

void draw_load(gather_t *gather)
{
    sfRenderWindow_drawSprite(gather->windo.window,
                                gather->menu.black_but, NULL);
    sfRenderWindow_drawSprite(gather->windo.window, gather->menu.load, NULL);
}

void draw_button(gather_t *gather)
{
    sfRenderWindow_drawSprite(gather->windo.window, gather->menu.button, NULL);
}

void update_gm_over(gather_t *gather)
{
    static float nbr = 0;

    if (gather->menu.change_button == 0) {
        if (gather->score.win == 1)
            draw_button(gather);
        else {
            draw_button(gather);
            sfRenderWindow_drawSprite(gather->windo.window, gather->menu.gm_ovr,
                                        NULL);
        }
    } else {
        if (nbr > 0.1) {
            move_black(gather);
            gather->menu.button_black = 1;
            nbr = 0;
        }
        if (gather->menu.button_black == 1)
            draw_load(gather);
        nbr += gather->time.delta_time;
    }
}
