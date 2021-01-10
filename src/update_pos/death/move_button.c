/*
** EPITECH PROJECT, 2021
** move button by Timothy CONIEL
** File description:
** move_button.c
*/
#include "../../../include/my.h"

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
