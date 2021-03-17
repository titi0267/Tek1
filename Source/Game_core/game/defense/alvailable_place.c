/*
** EPITECH PROJECT, 2021
** alvailable place by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** alvailable_place.c
*/

#include "../../../../include/defender.h"

void fill_pos_def(game_t *game)
{
    game->tower->good_pos = malloc(sizeof(sfIntRect) * 10);

    game->tower->good_pos[0].top = 100;
    game->tower->good_pos[0].left = 800;
    game->tower->good_pos[0].width = 100;
    game->tower->good_pos[0].height = 100;
    game->tower->good_pos[1].top = 300;
    game->tower->good_pos[1].left = 550;
    game->tower->good_pos[1].width = 100;
    game->tower->good_pos[1].height = 100;
    game->tower->good_pos[2].top = -1;
    game->tower->good_pos[2].left = -1;
    game->tower->good_pos[2].width = -1;
    game->tower->good_pos[2].height = -1;
    /*game->tower->good_pos[3].top = ;
    game->tower->good_pos[3].left = ;
    game->tower->good_pos[3].width = ;
    game->tower->good_pos[3].height = ;
    game->tower->good_pos[4].top = ;
    game->tower->good_pos[4].left = ;
    game->tower->good_pos[4].width = ;
    game->tower->good_pos[4].height = ;
    game->tower->good_pos[5].top = ;
    game->tower->good_pos[5].left = ;
    game->tower->good_pos[5].width = ;
    game->tower->good_pos[5].height = ;
    game->tower->good_pos[6].top = ;
    game->tower->good_pos[6].left = ;
    game->tower->good_pos[6].width = ;
    game->tower->good_pos[6].height = ;
    game->tower->good_pos[7].top = ;
    game->tower->good_pos[7].left = ;
    game->tower->good_pos[7].width = ;
    game->tower->good_pos[7].height = ;
    game->tower->good_pos[8].top = ;
    game->tower->good_pos[8].left = ;
    game->tower->good_pos[8].width = ;
    game->tower->good_pos[8].height = ;*/
}