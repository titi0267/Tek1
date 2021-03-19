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

void calc_vector(game_t *game, menu_t *menu)
{
    sfVector2f place;
    float auto_place;

    for (int i = 0; game->tower->good_pos[i].x != -1; i++) {
        place.x = ((game->tower->mouse_pos.x) - (game->tower->good_pos[i].x ));
        place.y = ((game->tower->mouse_pos.y) - (game->tower->good_pos[i].y));
        auto_place = sqrt(pow(place.x, 2) + pow(place.y, 2));
        if (auto_place < 150 && game->tower->area[i] == FALSE) {
            if (game->tower->tower_release == TRUE &&
                menu->button->enable_click == TRUE) {
                game->tower->area[i] = TRUE;
                game->tower->transmit_pos.x = game->tower->good_pos[i].x;
                game->tower->transmit_pos.y = game->tower->good_pos[i].y;
                game->valid = TRUE;
            }
        }
    }
}

void fill_pos_def(game_t *game)
{
    game->tower->good_pos = malloc(sizeof(sfVector2f *) * 10);

    game->tower->good_pos[0].x = 910;
    game->tower->good_pos[0].y = 150;
    game->tower->good_pos[1].x = 910;
    game->tower->good_pos[1].y = 490;
    game->tower->good_pos[2].x = 910;
    game->tower->good_pos[2].y = 760;
    game->tower->good_pos[3].x = 600;
    game->tower->good_pos[3].y = 490;
    game->tower->good_pos[4].x = 600;
    game->tower->good_pos[4].y = 720;
    game->tower->good_pos[5].x = 380;
    game->tower->good_pos[5].y = 920;
    game->tower->good_pos[6].x = 380;
    game->tower->good_pos[6].y = 550;
    game->tower->good_pos[7].x = 380;
    game->tower->good_pos[7].y = 350;
    game->tower->good_pos[8].x = 220;
    game->tower->good_pos[8].y = 720;
    game->tower->good_pos[9].x = -1;
    game->tower->good_pos[9].y = -1;
}