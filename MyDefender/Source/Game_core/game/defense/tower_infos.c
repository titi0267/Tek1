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
        game->defense_bis->damage = 1;
        game->defense_bis->shoot_speed = 2;
        game->defense_bis->range = 250;
        game->defense_bis->slow_enemy = 0.5;
    }
}

void archer_def(game_t *game)
{
    if (game->tower->wich_defense == arrow_tower) {
        game->defense_bis->damage = 25;
        game->defense_bis->shoot_speed = 2.5;
        game->defense_bis->range = 200;
    }
}

void wiz_def(game_t *game)
{
    if (game->tower->wich_defense == wiz_tower) {
        game->defense_bis->damage = 15;
        game->defense_bis->shoot_speed = 1.5;
        game->defense_bis->range = 150;
    }
}

void eco_def(game_t *game)
{
    if (game->tower->wich_defense == eco_center) {
        game->defense_bis->damage = 0;
        game->defense_bis->shoot_speed = 0;
        game->defense_bis->range = 0;
        game->tower->eco_placed = TRUE;
    }

}

void create_rect_def(tower_t *tower)
{
    tower->archer_rect.left = 0;
    tower->archer_rect.top = 0;
    tower->archer_rect.width = 55;
    tower->archer_rect.height = 81;
    tower->ice_rect.left = 0;
    tower->ice_rect.top = 0;
    tower->ice_rect.width = 51;
    tower->ice_rect.height = 81;
    tower->wiz_rect.left = -10;
    tower->wiz_rect.top = 15;
    tower->wiz_rect.width = 50;
    tower->wiz_rect.height = 81;
    tower->eco_rect.left = 0;
    tower->eco_rect.top = 0;
    tower->eco_rect.height = 51;
    tower->eco_rect.width = 54;
}