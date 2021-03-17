/*
** EPITECH PROJECT, 2021
** tower infos by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** tower_infos.c
*/

#include "../../../../include/defender.h"

void ice_def(game_t *game)
{
    if (game->tower->wich_defense == ice_tower) {
        game->defense_bis->damage = 10;
        game->defense_bis->shoot_speed = 2;
        game->defense_bis->range = 5;
    }
}

void archer_def(game_t *game)
{
    if (game->tower->wich_defense == arrow_tower) {
        game->defense_bis->damage = 20;
        game->defense_bis->shoot_speed = 2.5;
        game->defense_bis->range = 5;
    }
}

void wiz_def(game_t *game)
{
    if (game->tower->wich_defense == wiz_tower) {
        game->defense_bis->damage = 15;
        game->defense_bis->shoot_speed = 1.5;
        game->defense_bis->range = 5;
    }

}
