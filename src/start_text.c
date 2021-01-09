/*
** EPITECH PROJECT, 2021
** Start by Timothy CONIEL
** File description:
** start.c
*/
#include "../include/my.h"

void start_text(menu_t *menu)
{
    menu->press = sfText_create();
    menu->count = sfText_create();
    menu->font = sfFont_createFromFile("png/score.ttf");
    init_text(menu);
    sfText_setFont(menu->press, menu->font);
    sfText_setFont(menu->count, menu->font);
    sfText_setCharacterSize(menu->press, menu->font_size);
    sfText_setCharacterSize(menu->count, 150);
    sfText_setColor(menu->press, sfBlack);
    sfText_setColor(menu->count, sfBlack);
    sfText_setPosition(menu->press, menu->text_pos);
    sfText_setPosition(menu->count, menu->count_pos);
}

void update_count(gather_t *gather)
{
    lib_t lib;
    static float nbr = 0;

    gather->menu.counter = my_revstr(my_int_str(gather->menu.countdown, &lib), &lib);
    sfText_setString(gather->menu.count, gather->menu.counter);
    sfRenderWindow_drawText(gather->windo.window, gather->menu.count, NULL);
    if (nbr > 1) {
        gather->menu.countdown--;
        nbr = 0;
    }
    nbr += gather->time.delta_time;
    free(gather->menu.counter);
}

void update_textpos_max(gather_t *gather)
{
    if (gather->menu.text_pos.x < 0 || gather->menu.text_pos.x > 420) {
        gather->menu.random++;
        if (gather->menu.random % 2 == 0)
            gather->menu.delay = 2001;
        else
            gather->menu.delay = 1;
        gather->menu.random_move1 *= -1;
        gather->menu.random_move2 = 1;
    }
    if (gather->menu.text_pos.y < -15 || gather->menu.text_pos.y > 670) {
        gather->menu.random++;
        if (gather->menu.random % 2 == 0)
            gather->menu.delay = 2001;
        else
            gather->menu.delay = 1;
        gather->menu.random_move1 = 1;
        gather->menu.random_move2 = 1;
    }
}

void update_textpos_min(gather_t *gather)
{
    if (gather->menu.text_pos.y > 670 || gather->menu.text_pos.y < -15) {
        gather->menu.random++;
        if (gather->menu.random % 2 == 0)
            gather->menu.delay = 1;
        else
            gather->menu.delay = 2001;
        gather->menu.random_move2 = 1;
        gather->menu.random_move1 = 1;
    }
    if (gather->menu.text_pos.x > 420 || gather->menu.text_pos.x < 0) {
        gather->menu.random++;
        if (gather->menu.random % 2 == 0)
            gather->menu.delay = 1;
        else
            gather->menu.delay = 2001;
        gather->menu.random_move2 = 1;
        gather->menu.random_move1 *= -1;
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
            update_textpos_max(gather);
        }
        if (gather->menu.delay > 2000) {
            gather->menu.text_pos.x += gather->menu.random_move1;
            gather->menu.text_pos.y += gather->menu.random_move2;
            gather->menu.delay++;
            update_textpos_min(gather);
        }
        sfText_setPosition(gather->menu.press, gather->menu.text_pos);
    }
}
