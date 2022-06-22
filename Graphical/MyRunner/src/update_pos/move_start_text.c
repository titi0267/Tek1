/*
** EPITECH PROJECT, 2021
** move text by Timothy CONIEL
** File description:
** move_text.c
*/

#include "../../include/my.h"


void update_count(gather_t *gather)
{
    lib_t lib;
    static float nbr = 0;

    gather->menu.counter = my_int_str(gather->menu.countdown, &lib);
    sfText_setString(gather->menu.count, gather->menu.counter);
    sfRenderWindow_drawText(gather->windo.window, gather->menu.count, NULL);
    if (nbr > 1) {
        gather->menu.countdown--;
        nbr = 0;
    }
    nbr += gather->time.delta_time;
    free(gather->menu.counter);
}

void update_textpos_max(menu_t *menu)
{
    if (menu->text_pos.x < 0 || menu->text_pos.x > 420) {
        menu->random++;
        if (menu->random % 2 == 0)
            menu->delay = 2001;
        else
            menu->delay = 1;
        menu->random_move1 *= -1;
        menu->random_move2 = 1;
    }
    if (menu->text_pos.y < -15 || menu->text_pos.y > 670) {
        menu->random++;
        if (menu->random % 2 == 0)
            menu->delay = 2001;
        else
            menu->delay = 1;
        menu->random_move1 = 1;
        menu->random_move2 = 1;
    }
}

void update_textpos_min(menu_t *menu)
{
    if (menu->text_pos.y > 670 || menu->text_pos.y < -15) {
        menu->random++;
        if (menu->random % 2 == 0)
            menu->delay = 1;
        else
            menu->delay = 2001;
        menu->random_move2 = 1;
        menu->random_move1 = 1;
    }
    if (menu->text_pos.x > 420 || menu->text_pos.x < 0) {
        menu->random++;
        if (menu->random % 2 == 0)
            menu->delay = 1;
        else
            menu->delay = 2001;
        menu->random_move2 = 1;
        menu->random_move1 *= -1;
    }
}

void update_press(gather_t *gather)
{
    if (gather->menu.game_starting != 1) {
        sfText_setString(gather->menu.press, "Press space to start !\n");
        sfRenderWindow_drawText(gather->windo.window, gather->menu.press, NULL);
        if (gather->menu.delay < 2000) {
            gather->menu.text_pos.x -= gather->menu.random_move1;
            gather->menu.text_pos.y -= gather->menu.random_move2;
            gather->menu.delay++;
            update_textpos_max(&gather->menu);
        }
        if (gather->menu.delay > 2000) {
            gather->menu.text_pos.x += gather->menu.random_move1;
            gather->menu.text_pos.y += gather->menu.random_move2;
            gather->menu.delay++;
            update_textpos_min(&gather->menu);
        }
        sfText_setPosition(gather->menu.press, gather->menu.text_pos);
    }
}
