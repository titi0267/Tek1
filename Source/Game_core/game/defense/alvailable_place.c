/*
** EPITECH PROJECT, 2021
** alvailable place by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** alvailable_place.c
*/

#include "../../../../include/defender.h"
#include <math.h>
#include <stdio.h>

void fill_alrd_build(game_t *game)
{
    game->tower->area = malloc(sizeof(int) * 10);

    for (int i = 0; i < 9; i++)
        game->tower->area[i] = FALSE;
    game->tower->area[9] = -1;
}

void calc_vector_bis(game_t *game, menu_t *menu, int i)
{
    if (game->tower->tower_release == TRUE &&
        menu->button->enable_click == TRUE) {
        game->tower->area[i] = TRUE;
        game->tower->transmit_pos.x = game->tower->good_pos[i].x;
        game->tower->transmit_pos.y = game->tower->good_pos[i].y;
        game->valid = TRUE;
    }
}

void calc_vector(game_t *game, menu_t *menu)
{
    sfVector2f place;
    float auto_place;

    for (int i = 0; game->tower->good_pos[i].x != -1; i++) {
        place.x = ((game->tower->mouse_pos.x) - (game->tower->good_pos[i].x ));
        place.y = ((game->tower->mouse_pos.y) - (game->tower->good_pos[i].y));
        auto_place = sqrt(pow(place.x, 2) + pow(place.y, 2));
        if (auto_place < 150 && game->tower->area[i] == FALSE) {
            calc_vector_bis(game, menu, i);
        }
    }
}

void fill_pos_def_bis(game_t *game)
{
    game->tower->good_pos[4].y = 660;
    game->tower->good_pos[5].x = 400;
    game->tower->good_pos[5].y = 880;
    game->tower->good_pos[6].x = 400;
    game->tower->good_pos[6].y = 530;
    game->tower->good_pos[7].x = 400;
    game->tower->good_pos[7].y = 330;
    game->tower->good_pos[8].x = 250;
    game->tower->good_pos[8].y = 660;
    game->tower->good_pos[9].x = -1;
    game->tower->good_pos[9].y = -1;
}

void fill_pos_def(game_t *game)
{
    game->tower->good_pos = malloc(sizeof(sfVector2f *) * 10);

    game->tower->good_pos[0].x = 940;
    game->tower->good_pos[0].y = 120;
    game->tower->good_pos[1].x = 940;
    game->tower->good_pos[1].y = 450;
    game->tower->good_pos[2].x = 940;
    game->tower->good_pos[2].y = 720;
    game->tower->good_pos[3].x = 650;
    game->tower->good_pos[3].y = 460;
    game->tower->good_pos[4].x = 650;
    fill_pos_def_bis(game);
}