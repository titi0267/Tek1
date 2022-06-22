/*
** EPITECH PROJECT, 2021
** reset next by Timothy CONIEL
** File description:
** reset_next.c
*/
#include "../../../include/my.h"

void init_text(menu_t *menu)
{
    menu->game_starting = 0;
    menu->random_move1 = 1;
    menu->random_move2 = 1;
    menu->delay = 0;
    menu->random = 0;
    menu->font_size = 80;
    menu->text_pos.y = 250;
    menu->text_pos.x = 100;
    menu->count_pos.x = 600;
    menu->count_pos.y = 200;
    menu->countdown = 3;
    menu->start_count = 0;
    menu->stop_game = 0;
    menu->change_button = 0;
    menu->restart = 0;
}

void re_init(gather_t *gather, map_t *buff)
{
    reset_static(&gather->enemy, &gather->bird);
    init_text(&gather->menu);
    init_button(&gather->menu);
    bird_init(&gather->bird);
    init_enemy(&gather->enemy, buff, &gather->bird);
    init_bottom(&gather->back);
    init_background(&gather->back);
    reset_score(&gather->score);
}
