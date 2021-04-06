/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** window
*/

#include "../include/rpg.h"

int time_clock(rpg_t *rpg)
{
    rpg->basics->time_loop =
    sfClock_restart(rpg->basics->clock).microseconds / 1000000.0;
    rpg->basics->time_total += rpg->basics->time_loop;
}

int create_window(rpg_t *rpg)
{
    sfVideoMode video_mode = {1920, 1080, 32};
    //sfVector2i position_window = {0, 0};

    rpg->basics->my_window = sfRenderWindow_create(video_mode,
    "Grand Theft Covid", sfClose, NULL);
    //sfRenderWindow_setPosition(rpg->basics->my_window, position_window);
    //sfRenderWindow_setFramerateLimit(rpg->basics->my_window, 60);
    while (sfRenderWindow_isOpen(rpg->basics->my_window)) {
        sfRenderWindow_display(rpg->basics->my_window);
        //time_clock(rpg);
        //parsing(rpg);
    }
}